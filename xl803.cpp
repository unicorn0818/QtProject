#include "xl803.h"
#include <qdebug.h>

using namespace XL803;

#define ONE_FRAME_POINT_MAX_SIZE	2500		//一帧数据最点数，每点代表2字节

#ifdef _DEBUG
//#define XL803_DEBUG
//#define XL803_FUNC_IN_DEBUG
#endif

#ifdef XL803_FUNC_IN_DEBUG
//函数进入节点调试宏
#define XL803_funcIn() qDebug()<<(__FUNCSIG__ "\r\n")
#else
#define XL803_funcIn()
#endif

const int OP_NUM = 22;//运算符数量
const char opr[] = {'+', '-', '~', '*', '/', '^', '!', '(', ')','s', 'c', 't',   'o',   'a',  'g', 'q', 'l', 'L', 'S',   'C',   'T', 'O'};
//分别用来代替				   -（负号）					    sin  cos  tan/tg cot/ctg abs sign  sqrt  ln  log sinh/sh cosh/sh tanh coth

struct OpStack//符号栈
{
    char op[3][STACK_MAX];
    int top;
}op_stack;

struct NumStack//数字栈
{
    double num[3][STACK_MAX];
    int top;
}num_stack;

int oplevel(char c);//判断运算符优先级
bool is_op(char c);//判断是否符号
bool is_num(char c);//判断是否数

int fac(int t);//阶乘
double sign(double f);//符号函数
void big_add(char n1[], char n2[]);//大整数加
void big_minus(char n1[], char n2[]);//大整数减

void push_num(double f, int type);//数字栈压栈
double pop_num(int type);//数字栈弹栈
void push_op(char c, int type);//符号栈压栈
char pop_op(int type);//符号栈弹栈
XL803Proto* XL803Proto::m_pXl803[] = {0};

XL803Proto::XL803Proto(QObject *parent)
	: QObject(parent)
{
	recvBufSize = 0xFFFF;
	sendBufSize = 0xFFFF;
	recvBuf = new quint8[recvBufSize];
	sendBuf = new quint8[sendBufSize];
    meter_addr = new quint8[7];
	sendIndex = 0;
	recvIndex = 0;
    step_value = 0;
	mr_start = &recvBuf[IND_START];
	mr_len = (quint16*)&recvBuf[IND_LEN];
	mr_start2 = &recvBuf[IND_START2];
	mr_addr = &recvBuf[IND_ADDR];
	mr_code = &recvBuf[IND_CODE];
	mr_data = &recvBuf[IND_DATA];

	ms_start = &sendBuf[IND_START];
	ms_len = (quint16*)&sendBuf[IND_LEN];
	ms_start2 = &sendBuf[IND_START2];
	ms_addr = &sendBuf[IND_ADDR];
	ms_code = &sendBuf[IND_CODE];
	ms_data = &sendBuf[IND_DATA];

	m_volGears << 57.7 << 100 << 220 << 380 << 600 << 1000;
	m_curGears << 0.2 << 1.0 << 5.0 << 10.0;

	m_volAutoGear = true;
	m_curAutoGear = true;

	m_volMax = 1000;
	m_curMax = 10;
    last_control=0;
	m_linkType = LINK_NO;
	m_pcapPack = 0;
    energy_flag=0;
    m_able=SP_NO;
    for(int i=0;i<8;i++)
    {
        m_data[i]=new YM_DATA_TYPE;
        m_parr[i]=new YM_PARR_TYPE;
        memset(m_data[i],0,sizeof(YM_DATA_TYPE));
    }
    sufexp[3][EXP_MAX_LEN]={0};//suffix expression 后缀表达式
    buffer[3][EXP_MAX_LEN]={0};//buffer
}
XL803Proto::~XL803Proto()
{
	delete []recvBuf;
	delete []sendBuf;
}
XL803Proto* XL803Proto::getXl803(quint8 ind,QObject *parent)
{
	if(ind >= MAX_803_DEV)
		return 0;
	if(!m_pXl803[ind])
		m_pXl803[ind] = new XL803Proto(parent);
	return m_pXl803[ind];
}

void XL803Proto::setGear(QList<double> &vol,QList<double> &cur,bool volAutoGear,bool curAutoGear)
{
	m_volGears = vol;
	m_curGears = cur;
	m_volAutoGear = volAutoGear;
	m_curAutoGear = curAutoGear;
}

quint32 XL803Proto::currGear(CH_MAP ch)
{
	quint32 gear = 0;
	switch(ch)
	{
	case OCM_UA:
		gear = m_currGear.ua;
		break;
	case OCM_UB:
		gear = m_currGear.ub;
		break;
	case OCM_UC:
		gear = m_currGear.uc;
		break;
	case OCM_IA:
		gear = m_currGear.ia;
		break;
	case OCM_IB:
		gear = m_currGear.ib;
		break;
	case OCM_IC:
		gear = m_currGear.ic;
		break;
	}
	return gear;
}
void XL803Proto::setLimit(double volMax,double curMax)
{
	m_volMax = volMax;
	m_curMax = curMax;
}
void XL803Proto::readFromPort(const QByteArray &rb,const QByteArray &wB,XL803::PAGE page)
{
    switch (page) {
    case MAIN:
        emit send_to_main(wB,rb);
        break;
    case BASE_OUT:
        emit send_to_base_out(wB,rb);
        break;
    case Config_set:
        emit send_to_config(wB,rb);
        break;
    case HRENTER_OUT:
        emit send_to_hrenter(wB,rb);
        break;
    case ANY_WAVE:
        emit send_to_any_wave(wB,rb);
        break;
    case ACTIVE_WAVE:
        emit send_to_active_wave(wB,rb);
        break;
    case ADJUST_ENERGY:
        emit send_to_adjust_energy(wB,rb);
        break;
    case REOUT_WAVE:
        emit send_to_reout_wave(wB,rb);
        break;
    case Wave_reout:
        emit send_to_wave_reout(wB,rb);
        break;
    case Power_test:
        emit send_to_power_test(wB,rb);
        break;
//    case PAGE::test_bll:
//        emit send_to_bll_test(wB,rb);
//        break;
    case wave_reout_ZJ:
        emit send_to_Ele_Load_Sim(wB,rb);
        break;
    default:
        break;
    }
}

//void XL803Proto::readFrommeter(const QByteArray &rb,const QByteArray &wB)
//{
//    const char *tempWb = wB.data();
//    const char *tempRb = rb.data();
//    if(((quint8)tempWb[12]== 0x13) && ((quint8)tempRb[8] == 0x93))//读地址
//    {
//        for(int i=0;i<6;i++)
//        {
//            meter_addr[i]=((quint8)tempRb[10+i])-0x33;
//        }
//    }else if(((quint8)tempWb[9]== 0x11) && ((quint8)tempRb[8] == 0x91))//读电量，无后续帧
//    {
//        QByteArray data=rb.mid(10,(quint8)tempRb[9]);
//        emit send_meter_data(data);
//    }else if(((quint8)tempWb[9]== 0x11) && ((quint8)tempRb[8] == 0xB1))//读电量，有后续帧
//    {

//    }else if(((quint8)tempWb[9]== 0x11) && ((quint8)tempRb[8] == 0xD1))//读电量，错误应答
//    {

//    }

//}
bool XL803Proto::sendPack(COMMAND_TYPE code,quint32 waitMs,PAGE page)
{
	XL803_funcIn();
    sendIndex = ms_dSize + 8;
    //帧头0x68
	*ms_start = START_CHAR;
    //长度=数据域+8;
	*ms_len = sendIndex;
    //启始字符0x68
	*ms_start2 = START_CHAR;
    //地址域
	*ms_addr = DEVICE_NUM;
    //命令域 如：0x03 源启动
	*ms_code = code;

	ms_crc = &sendBuf[(*ms_len) - 2];
	ms_end = &sendBuf[(*ms_len) - 1];
    //校验和
	*ms_crc = checkSum(ms_addr,ms_crc - ms_addr);
    //结束字符0x16
	*ms_end = STOP_CHAR;

	sendBuf[sendIndex] = 0;

    quint32 size = sendIndex;

    emit sendToPort(QByteArray((char*)sendBuf,size),waitMs,page);
	return true;
}
bool XL803Proto::readFile(bool emitErr,quint32 waitMs)
{
	return false;
}
bool XL803Proto::checkPack(COMMAND_TYPE right,bool emitErr)
{
	mr_crc = &recvBuf[(*mr_len) - 2];
	mr_end = &recvBuf[(*mr_len) - 1];

	if(recvIndex < MIN_FRAME_SIZE ||
		recvIndex < *mr_len)
	{//长度不够
		if(emitErr)
			emit isError(tr("通信应答错误!"));
		return false;
	}
	if(*mr_start != START_CHAR ||
		*mr_start2 != START_CHAR ||
		*mr_end != STOP_CHAR)
	{
		if(emitErr)
			emit isError(tr("通信应答帧格式错误!"));
		return false;
	}
	if(*mr_crc != checkSum(mr_addr,mr_crc - mr_addr))
	{
		if(emitErr)
			emit isError(tr("通信应答校验码错误!"));
		return false;
	}
	if(*mr_addr != HOST_NUM)
	{
		if(emitErr)
			emit isError(tr("通信应答地址错误!"));
		return false;
	}
	return true;
}
bool XL803Proto::checkEnd()
{//检测帧长度是否足够
	if(recvIndex < MIN_FRAME_SIZE ||
		recvIndex < *mr_len)
	{//长度不够
		return false;
	}
	return true;
}
bool XL803Proto::waitPack(COMMAND_TYPE right,COMMAND_TYPE error,quint32 waitMs,quint8 reSendTimes)
{
	XL803_funcIn();

	return true;
}

bool XL803Proto::COM_HightWrite(const QMap<MARKERB,qint32> &para,PAGE page)
{
	XL803_funcIn();
	ms_dSize = 0;
	QList<MARKERB> keys = para.keys();
	foreach(MARKERB mar,keys)
	{
		ms_data[ms_dSize++] = mar;
        (quint32&)ms_data[ms_dSize] = para.value(mar);
		ms_dSize += sizeof(quint32);

		switch(mar)
		{//
		case MARKERB_DUA:
			m_currGear.ua = para.value(mar);
			break;
		case MARKERB_DUB:
			m_currGear.ub = para.value(mar);
			break;
		case MARKERB_DUC:
			m_currGear.uc = para.value(mar);
			break;
		case MARKERB_DIA:
			m_currGear.ia = para.value(mar);
			break;
		case MARKERB_DIB:
			m_currGear.ib = para.value(mar);
			break;
		case MARKERB_DIC:
			m_currGear.ic = para.value(mar);
			break;
		}
	}
    if(sendPack(HIGH_PRICISION_WRITE,1000,page) && waitPack())
		return true;

	return false;
}
bool XL803Proto::COM_HightRead(QMap<MARKERB,qint32> &para,PAGE page)
{
	XL803_funcIn();
	ms_dSize = 0;
	QList<MARKERB> keys = para.keys();
	foreach(MARKERB mar,keys)
	{
		ms_data[ms_dSize++] = mar;
        (quint32&)ms_data[ms_dSize] = para.value(mar);
		ms_dSize += sizeof(quint32);
	}
    if(sendPack(HIGH_PRICISION_READ,1000,page) && waitPack(HIGH_PRICISION_READ))
	{
		//unpackHightRead(para);
		return true;
	}
	return false;
}
bool XL803Proto::COM_HightRead(QVector<MARKERB> &keys,QVector<qint32> &value,PAGE page)
{
	XL803_funcIn();
	ms_dSize = 0;
	foreach(MARKERB mar,keys)
	{
		ms_data[ms_dSize++] = mar;
        (quint32&)ms_data[ms_dSize] = 0;
        ms_dSize += sizeof(quint32);
	}
    if(sendPack(HIGH_PRICISION_READ,1000,page) && waitPack(HIGH_PRICISION_READ))
	{
		unpackHightRead(keys,value);
		return true;
	}
	return false;
}
bool XL803Proto::COM_StartUp(const QMap<MARKERB,qint32> &para,PAGE page)
{
	XL803_funcIn();
	ms_dSize = 0;
	QList<MARKERB> keys = para.keys();
	foreach(MARKERB mar,keys)
	{
		ms_data[ms_dSize++] = mar;
        (quint16&)ms_data[ms_dSize] = para.value(mar);
		ms_dSize += sizeof(quint16);
	}
    if(sendPack(STARTUP_OUTPUT,1000,page) && waitPack())
		return true;
	return false;
}
bool XL803Proto::COM_Stop(const QMap<MARKERB,qint32> &para,PAGE page)
{
	XL803_funcIn();
	ms_dSize = 0;
	QList<MARKERB> keys = para.keys();
	foreach(MARKERB mar,keys)
	{
		ms_data[ms_dSize++] = mar;
        (quint16&)ms_data[ms_dSize] = para.value(mar);
		ms_dSize += sizeof(quint16);
	}
    qDebug()<<"STOP_OUTPUT!";
    if(sendPack(STOP_OUTPUT,1000,page) && waitPack())
		return true;
	return false;
}
bool XL803Proto::COM_WriteHarmonic(HAR_TIMES max,const HARMONIC_DATA &para,PAGE page)
{
	XL803_funcIn();
	memset(sendBuf,0,sendBufSize);		//先都清零，再根据需要填值。

	COMMAND_TYPE com = HARMONIC_WTITE;

	if(max == HAR_T_DEF)
		com = HARMONIC_WTITE;
	else if(max == HAR_T_EXP)
		com = HIGHT_HAR_WTITE;
	else if(max == HAR_T_EXP2)
		com = HARMONIC_WTITE_EXP2;
	else
		return false;

	quint16 i;
	quint16 *oneValue = (quint16*)ms_data;	
	quint16 waveCount = max;

	quint16 maxTimes = max + 1;

	oneValue[maxTimes * 0] = (quint16)(para.uaBaseWave / 100.0 * 0x6666);
	oneValue[maxTimes * 1] = (quint16)(para.ubBaseWave / 100.0 * 0x6666);
	oneValue[maxTimes * 2] = (quint16)(para.ucBaseWave / 100.0 * 0x6666);
	oneValue[maxTimes * 3] = (quint16)(para.iaBaseWave / 100.0 * 0x6666);
	oneValue[maxTimes * 4] = (quint16)(para.ibBaseWave / 100.0 * 0x6666);
	oneValue[maxTimes * 5] = (quint16)(para.icBaseWave / 100.0 * 0x6666);

	oneValue[maxTimes * 6] = (quint16)(para.uaPhBaseWave * 100);
	oneValue[maxTimes * 7] = (quint16)(para.ubPhBaseWave * 100);
	oneValue[maxTimes * 8] = (quint16)(para.ucPhBaseWave * 100);
	oneValue[maxTimes * 9] = (quint16)(para.iaPhBaseWave * 100);
	oneValue[maxTimes * 10] = (quint16)(para.ibPhBaseWave * 100);
	oneValue[maxTimes * 11] = (quint16)(para.icPhBaseWave * 100);
	for(i = 1; i < waveCount; i ++)
	{
		int t = i + 1;
		if(!para.uaTimesWave.values(t).isEmpty())
			oneValue[i + maxTimes * 0] = (quint16)(para.uaTimesWave.value(t) / 100.0 * oneValue[maxTimes * 0]);

		if(!para.ubTimesWave.values(t).isEmpty())
			oneValue[i + maxTimes * 1] = (quint16)(para.ubTimesWave.value(t) / 100.0 * oneValue[maxTimes * 1]);

		if(!para.ucTimesWave.values(t).isEmpty())
			oneValue[i + maxTimes * 2] = (quint16)(para.ucTimesWave.value(t) / 100.0 * oneValue[maxTimes * 2]);

		if(!para.iaTimesWave.values(t).isEmpty())
			oneValue[i + maxTimes * 3] = (quint16)(para.iaTimesWave.value(t) / 100.0 * oneValue[maxTimes * 3]);

		if(!para.ibTimesWave.values(t).isEmpty())
			oneValue[i + maxTimes * 4] = (quint16)(para.ibTimesWave.value(t) / 100.0 * oneValue[maxTimes * 4]);

		if(!para.icTimesWave.values(t).isEmpty())
			oneValue[i + maxTimes * 5] = (quint16)(para.icTimesWave.value(t) / 100.0 * oneValue[maxTimes * 5]);

		if(!para.uaPhTimesWave.values(t).isEmpty())
			oneValue[i + maxTimes * 6] = (quint16)(para.uaPhTimesWave.value(t) * 100);

		if(!para.ubPhTimesWave.values(t).isEmpty())
			oneValue[i + maxTimes * 7] = (quint16)(para.ubPhTimesWave.value(t) * 100);

		if(!para.ucPhTimesWave.values(t).isEmpty())
			oneValue[i + maxTimes * 8] = (quint16)(para.ucPhTimesWave.value(t) * 100);

		if(!para.iaPhTimesWave.values(t).isEmpty())
			oneValue[i + maxTimes * 9] = (quint16)(para.iaPhTimesWave.value(t) * 100);

		if(!para.ibPhTimesWave.values(t).isEmpty())
			oneValue[i + maxTimes * 10] = (quint16)(para.ibPhTimesWave.value(t) * 100);

		if(!para.icPhTimesWave.values(t).isEmpty())
			oneValue[i + maxTimes * 11] = (quint16)(para.icPhTimesWave.value(t) * 100);
	}
	ms_dSize = maxTimes * 12 * 2;

    if(sendPack(com,1000,page) && waitPack())
		return true;
	return false;
}

bool XL803Proto::write_one_harmonic(quint8 pipe, const PhaseOneHrDef data[HIGHT_HAR_TIMES],PAGE page)
{
    XL803_funcIn();
    int hrCount = HIGHT_HAR_TIMES;
    QByteArray arry;
    arry.append(pipe);
    for(int i = 0; i < hrCount; i ++)
    {
        arry.append(*((qint8 *)&(data[i].radio)));
        arry.append(*((qint8 *)&(data[i].radio)+1));
        arry.append(*((qint8 *)&(data[i].radio)+2));
        arry.append(*((qint8 *)&(data[i].radio)+3));
    }
    for(int i = 0; i < hrCount; i ++)
    {
        arry.append(*((qint8 *)&(data[i].phase)));
        arry.append(*((qint8 *)&(data[i].phase)+1));
        arry.append(*((qint8 *)&(data[i].phase)+2));
        arry.append(*((qint8 *)&(data[i].phase)+3));
    }
    ms_dSize = arry.length()+1;
    memcpy(ms_data,arry.data(),arry.length());
    if(sendPack(HARMONIC_WRITE_ONE,1000,page) && waitPack())
        return true;
    return false;
}
//写谐波,data[6][hrCount]数组,hrCount 必需小于maxTimes，SOUR_PHASE_NUM的顺序与OUT_CH_MAP一致
bool XL803Proto::COM_WriteHarmonic(PhaseOneHrDef data[SOUR_PHASE_NUM][HIGHT_HAR_TIMES],PAGE page)
{
	XL803_funcIn();
    int hrCount = HIGHT_HAR_TIMES;
	quint16 i;
	pProtoHrHightWriteDef pD = (pProtoHrHightWriteDef)ms_data;

	memset(pD,0,sizeof(ProtoHrHightWriteDef));
	for(int i = 0; i < hrCount; i ++)
	{
		pD->UaRadio[i] = quint16(data[OCM_UA][i].radio / 100.0 * 0x6666);
		pD->UbRadio[i] = quint16(data[OCM_UB][i].radio / 100.0 * 0x6666);
		pD->UcRadio[i] = quint16(data[OCM_UC][i].radio / 100.0 * 0x6666);
		pD->IaRadio[i] = quint16(data[OCM_IA][i].radio / 100.0 * 0x6666);
		pD->IbRadio[i] = quint16(data[OCM_IB][i].radio / 100.0 * 0x6666);
		pD->IcRadio[i] = quint16(data[OCM_IC][i].radio / 100.0 * 0x6666);

		pD->UaPhase[i] = data[OCM_UA][i].phase * 100.0;
		pD->UbPhase[i] = data[OCM_UB][i].phase * 100.0;
		pD->UcPhase[i] = data[OCM_UC][i].phase * 100.0;
		pD->IaPhase[i] = data[OCM_IA][i].phase * 100.0;
		pD->IbPhase[i] = data[OCM_IB][i].phase * 100.0;
		pD->IcPhase[i] = data[OCM_IC][i].phase * 100.0;
	}

	ms_dSize = sizeof(ProtoHrHightWriteDef);

    if(sendPack(HIGHT_HAR_WTITE,1000,page) && waitPack())
		return true;
	return false;
}

//谐波启动
bool XL803Proto::COM_HarmonicStartup(PHASE_ENUM phase, quint32, PAGE page)
{
	XL803_funcIn();
    m_able=phase;
	float harmonicWB = 1.25;
	ms_dSize = 0;

	ms_data[ms_dSize++] = phaseIsSet(phase,SP_UA)?0x55:0;
    ms_data[ms_dSize++] = phaseIsSet(phase,SP_IA)?0x55:0;
	ms_data[ms_dSize++] = phaseIsSet(phase,SP_UB)?0x55:0;
    ms_data[ms_dSize++] = phaseIsSet(phase,SP_IB)?0x55:0;
	ms_data[ms_dSize++] = phaseIsSet(phase,SP_UC)?0x55:0;
    ms_data[ms_dSize++] = phaseIsSet(phase,SP_IC)?0x55:0;
    ms_data[ms_dSize++] = phaseIsSet(phase,SP_UD)?0x55:0;
    ms_data[ms_dSize++] = phaseIsSet(phase,SP_ID)?0x55:0;
    ms_data[ms_dSize++] = phaseIsSet(phase,SP_UA2)?0x55:0;
    ms_data[ms_dSize++] = phaseIsSet(phase,SP_IA2)?0x55:0;
    ms_data[ms_dSize++] = phaseIsSet(phase,SP_UB2)?0x55:0;
    ms_data[ms_dSize++] = phaseIsSet(phase,SP_IB2)?0x55:0;
    ms_data[ms_dSize++] = phaseIsSet(phase,SP_UC2)?0x55:0;
    ms_data[ms_dSize++] = phaseIsSet(phase,SP_IC2)?0x55:0;
    ms_data[ms_dSize++] = phaseIsSet(phase,SP_UD2)?0x55:0;
    ms_data[ms_dSize++] = phaseIsSet(phase,SP_ID2)?0x55:0;

    if(sendPack(HIGHT_HAR_STARTUP,1000,page) && waitPack(RIGHT_RESPON,ERROR_RESPON,2000))
		return true;

	return false;
}

//谐波停止
bool XL803Proto::COM_HarmonicStop(PHASE_ENUM phase,PAGE page)
{
	XL803_funcIn();
    m_able=phase;
	ms_dSize = 0;
	ms_data[ms_dSize++] = phaseIsSet(phase,SP_UA)?0xAA:0;
	ms_data[ms_dSize++] = phaseIsSet(phase,SP_UB)?0xAA:0;
	ms_data[ms_dSize++] = phaseIsSet(phase,SP_UC)?0xAA:0;

	ms_data[ms_dSize++] = phaseIsSet(phase,SP_IA)?0xAA:0;
	ms_data[ms_dSize++] = phaseIsSet(phase,SP_IB)?0xAA:0;
	ms_data[ms_dSize++] = phaseIsSet(phase,SP_IC)?0xAA:0;

    if(sendPack(HIGHT_HAR_STOP,1000,page) && waitPack())
		return true;

	return false;
}


bool XL803Proto::EX_startACOutPut(const AC_TYPE &ac,PHASE_ENUM phase,PAGE page)
{
	XL803_funcIn();
	bool retValue = false;
	//acToLimit(ac);
    m_able=phase;
	QMap<MARKERB,qint32> para;
    set_ac(ac);
	qint32 gear;
	if(phaseIsSet(phase,SP_UA))
	{
        para.insert(MARKERB_UA,(quint32&)ac.UA);
        para.insert(MARKERB_UAP,(quint32&)ac.UaAngle);
        para.insert(MARKERB_FA,(quint32&)ac.FAB);
		para.insert(MARKERB_DUA,volGearSel(ac.UA));		
	}
	if(phaseIsSet(phase,SP_UB))
	{
        para.insert(MARKERB_UB,(quint32&)ac.UB);
        para.insert(MARKERB_UBP,(quint32&)ac.UbAngle);
        para.insert(MARKERB_FA,(quint32&)ac.FAB);
		para.insert(MARKERB_DUB,volGearSel(ac.UB));
	}
	if(phaseIsSet(phase,SP_UC))
	{
        para.insert(MARKERB_UC,(quint32&)ac.UC);
        para.insert(MARKERB_UCP,(quint32&)ac.UcAngle);
        para.insert(MARKERB_FB,(quint32&)ac.FC);
		para.insert(MARKERB_DUC,volGearSel(ac.UC));
	}
	if(phaseIsSet(phase,SP_IA))
	{
        para.insert(MARKERB_IA,(quint32&)ac.IA);
        para.insert(MARKERB_IAP,(quint32&)ac.IaAngle);
        para.insert(MARKERB_FA,(quint32&)ac.FAB);
		para.insert(MARKERB_DIA,curGearSel(ac.IA));
	}
	if(phaseIsSet(phase,SP_IB))
	{
        para.insert(MARKERB_IB,(quint32&)ac.IB);
        para.insert(MARKERB_IBP,(quint32&)ac.IbAngle);
        para.insert(MARKERB_FA,(quint32&)ac.FAB);
		para.insert(MARKERB_DIB,curGearSel(ac.IB));
	}
	if(phaseIsSet(phase,SP_IC))
	{
        para.insert(MARKERB_IC,(quint32&)ac.IC);
        para.insert(MARKERB_ICP,(quint32&)ac.IcAngle);
        para.insert(MARKERB_FB,(quint32&)ac.FC);
		para.insert(MARKERB_DIC,curGearSel(ac.IC));
	}
    if(!COM_HightWrite(para,page))
		return false;

	quint32 v;
	v = 1;
	para.clear();

	if(phaseIsSet(phase,SP_UA))
	{
		para.insert(MARKERB_SUA,v);
	}
	if(phaseIsSet(phase,SP_UB))
	{
		para.insert(MARKERB_SUB,v);
	}
	if(phaseIsSet(phase,SP_UC))
	{
		para.insert(MARKERB_SUC,v);
	}
	if(phaseIsSet(phase,SP_IA))
	{
		para.insert(MARKERB_SIA,v);
	}
	if(phaseIsSet(phase,SP_IB))
	{
		para.insert(MARKERB_SIB,v);
	}
	if(phaseIsSet(phase,SP_IC))
	{
		para.insert(MARKERB_SIC,v);
	}
    if(!COM_StartUp(para,page))
		return false;
	return true;
}

void XL803Proto::acToLimit(AC_TYPE &ac)
{
	bool isL = false;
	ac.UA = getMin(ac.UA,m_volMax,isL);
	ac.UB = getMin(ac.UB,m_volMax,isL);
	ac.UC = getMin(ac.UC,m_volMax,isL);

	ac.IA = getMin(ac.IA,m_curMax,isL);
	ac.IB = getMin(ac.IB,m_curMax,isL);
	ac.IC = getMin(ac.IC,m_curMax,isL);
	if(isL)
		emit isError(tr("超过最大输出限值:%1V，%2A").arg(m_volMax).arg(m_curMax));
}
bool XL803Proto::EX_stopACOutPut(PHASE_ENUM phase,PAGE page)
{
	XL803_funcIn();
    m_able=phase;
    quint32 v;
	v = 1;

	QMap<MARKERB,qint32> para;

    if(phaseIsSet(phase,SP_UA))
	{
		para.insert(MARKERB_EUA,v);
	}
	if(phaseIsSet(phase,SP_UB))
	{
		para.insert(MARKERB_EUB,v);
	}
	if(phaseIsSet(phase,SP_UC))
	{
		para.insert(MARKERB_EUC,v);
	}
	if(phaseIsSet(phase,SP_IA))
	{
		para.insert(MARKERB_EIA,v);
	}
	if(phaseIsSet(phase,SP_IB))
	{
		para.insert(MARKERB_EIB,v);
	}
	if(phaseIsSet(phase,SP_IC))
	{
		para.insert(MARKERB_EIC,v);
	}
    return COM_Stop(para,page);
}

bool XL803Proto::EX_writeHrOutput(const AC_TYPE &ac,PhaseOneHrDef data[SOUR_PHASE_NUM][HIGHT_HAR_TIMES],PHASE_ENUM phase,PAGE page)
{
	XL803_funcIn();
    bool retValue = false;
    m_able=phase;
    QMap<MARKERB,qint32> para;
    qint32 gear;
    if(phaseIsSet(phase,SP_UA))
    {
        para.insert(MARKERB_UA,(quint32&)ac.UA);
        para.insert(MARKERB_UAP,(quint32&)ac.UaAngle);
        para.insert(MARKERB_FA,(quint32&)ac.FAB);
        para.insert(MARKERB_DUA,volGearSel(ac.UA));
    }
    if(phaseIsSet(phase,SP_UB))
    {
        para.insert(MARKERB_UB,(quint32&)ac.UB);
        para.insert(MARKERB_UBP,(quint32&)ac.UbAngle);
        para.insert(MARKERB_FA,(quint32&)ac.FAB);
        para.insert(MARKERB_DUB,volGearSel(ac.UB));
    }
    if(phaseIsSet(phase,SP_UC))
    {
        para.insert(MARKERB_UC,(quint32&)ac.UC);
        para.insert(MARKERB_UCP,(quint32&)ac.UcAngle);
        para.insert(MARKERB_FB,(quint32&)ac.FC);
        para.insert(MARKERB_DUC,volGearSel(ac.UC));
    }
    if(phaseIsSet(phase,SP_IA))
    {
        para.insert(MARKERB_IA,(quint32&)ac.IA);
        para.insert(MARKERB_IAP,(quint32&)ac.IaAngle);
        para.insert(MARKERB_FA,(quint32&)ac.FAB);
        para.insert(MARKERB_DIA,curGearSel(ac.IA));
    }
    if(phaseIsSet(phase,SP_IB))
    {
        para.insert(MARKERB_IB,(quint32&)ac.IB);
        para.insert(MARKERB_IBP,(quint32&)ac.IbAngle);
        para.insert(MARKERB_FA,(quint32&)ac.FAB);
        para.insert(MARKERB_DIB,curGearSel(ac.IB));
    }
    if(phaseIsSet(phase,SP_IC))
    {
        para.insert(MARKERB_IC,(quint32&)ac.IC);
        para.insert(MARKERB_ICP,(quint32&)ac.IcAngle);
        para.insert(MARKERB_FB,(quint32&)ac.FC);
        para.insert(MARKERB_DIC,curGearSel(ac.IC));
    }
    COM_HightWrite(para,page);
    if(COM_WriteHarmonic(data,page) && COM_HarmonicStartup(phase,1000,page))
		return true;
	return false;
}


quint8 XL803Proto::checkSum(quint8 *frame,quint16 frameSize)
{
	quint8 wckh=0;
	for(int n=0; n<frameSize; n++) 
		wckh += (quint8)(*(frame+n));
	return wckh;
}

bool XL803Proto::unpackHightRead(const QByteArray &rb,QMap<MARKERB,qint32> &para)
{
	quint16 i = 0;
	while(i < mr_dSize)
	{
		quint8 label = mr_data[i++];
		if(para.keys().contains((MARKERB)label))
		{
            para[(MARKERB)label] = *((quint32*)&mr_data[i]);

            i += sizeof(quint32);
		}
	}
	return true;
}
bool XL803Proto::unpackHightRead(QVector<MARKERB> &keys,QVector<qint32> &value)
{
	quint16 i = 0;
	while(i < mr_dSize)
	{
		MARKERB label = (MARKERB)mr_data[i++];
		int ind = keys.indexOf(label);
		if(ind >= 0)
		{
            value[ind] = *((quint32*)&mr_data[i]);

            i += sizeof(quint32);
		}
	}
	return true;
}
bool XL803Proto::testLink()
{
	return true;
}

quint32 XL803Proto::volGearSel(double value)
{
	quint32 gear;

	if(m_volAutoGear)
	{
		gear = 0x55;
	}else
	{
		gear = gearSel(m_volGears,value);
	}
	return gear;
}
quint32 XL803Proto::curGearSel(double value)
{
	quint32 gear;

	if(m_curAutoGear)
	{
		gear = 0x55;
	}else
	{
		gear = gearSel(m_curGears,value);
	}
	return gear;
}
quint8 XL803Proto::gearSel(const QList<double> &gearLst,double value)
{
	int i;
	for(i = 0; i < gearLst.count(); i ++)
	{
		if(value < gearLst[i] * 1.2)
			break;
	}
	if(i >= gearLst.count())
		i = gearLst.count() - 1;
	if(i < 0)
		i = 0;

	return i;
}
MARKERB XL803Proto::waveMarkB(CH_MAP ph)
{
	MARKERB wave;
	wave = MARKERB_WAVE_IA;
	switch(ph)
	{
	case OCM_UA:
		wave = MARKERB_WAVE_UA;
		break;
	case OCM_IA:
		wave = MARKERB_WAVE_IA;
		break;
	case OCM_UB:
		wave = MARKERB_WAVE_UB;
		break;
	case OCM_IB:
		wave = MARKERB_WAVE_IB;
		break;
	case OCM_UC:
		wave = MARKERB_WAVE_UC;
		break;
	case OCM_IC:
		wave = MARKERB_WAVE_IC;
		break;
	case OCM_UD:
		wave = MARKERB_WAVE_UD;
		break;
	case OCM_ID:
		wave = MARKERB_WAVE_ID;
		break;
	case OCM_UA2:
		wave = MARKERB_WAVE_UA2;
		break;
	case OCM_IA2:
		wave = MARKERB_WAVE_IA2;
		break;
	case OCM_UB2:
		wave = MARKERB_WAVE_UB2;
		break;
	case OCM_IB2:
		wave = MARKERB_WAVE_IB2;
		break;
	case OCM_UC2:
		wave = MARKERB_WAVE_UC2;
		break;
	case OCM_IC2:
		wave = MARKERB_WAVE_IC2;
		break;
	case OCM_UD2:
		wave = MARKERB_WAVE_UD2;
        break;
	case OCM_ID2:
		wave = MARKERB_WAVE_ID2;
		break;
	}
	return wave;
}
//bool XL803Proto::COM_energy_check(int flag,PAGE page)
//{
//    ms_dSize=0;
//    if(flag)
//    {
//        *ms_data=0x55;
//    }else
//    {
//        *ms_data=0xAA;
//    }
//    ms_dSize=sizeof(quint8);
//    quint8 * now_point=ms_data+1;
//    YM_PARR_TYPE * parr;
//    YM_DATA_TYPE * data;
//    quint32 x=0;
//    for(int i=0;i<8;i++)
//    {
//        parr=(YM_PARR_TYPE*)now_point+i;
//        memset(parr+ms_dSize,0,sizeof(YM_PARR_TYPE));
//        parr->Constp=m_parr[i]->Constp;
//        parr->Constq=m_parr[i]->Constq;
//        parr->PowerConstP=m_parr[i]->PowerConstP;
//        parr->PowerConstQ=m_parr[i]->PowerConstQ;
//        parr->CheckNum=m_parr[i]->CheckNum;
//        parr->CheckType=m_parr[i]->CheckType;
//        parr->SAvergeNum=m_parr[i]->SAvergeNum;
//        parr->CalType=m_parr[i]->CalType;
//        ms_dSize+=sizeof(YM_PARR_TYPE);
//    }
//    parr=(YM_PARR_TYPE*)ms_data+8;
//    int data_size=0;
//    for(int i=0;i<8;i++)
//    {
//        data=(YM_DATA_TYPE *)parr+i;
//        memset(data+data_size,0,sizeof(YM_DATA_TYPE));
//        data_size+=sizeof(YM_DATA_TYPE);
//        ms_dSize+=sizeof(YM_DATA_TYPE);
//    }

//    if(sendPack(ENERGY_CHECK,1000,page) && waitPack())
//        return true;
//    return false;
//}
//bool XL803Proto::COM_energy_check_state(int flag,PAGE page)
//{
//    ms_dSize=0;
//    if(flag)
//    {
//        if(sendPack(DCME_ERROR_STATE_1,1000,page) && waitPack())
//            return true;
//        return false;
//    }else
//    {
//        if(sendPack(DCME_ERROR_STATE,1000,page) && waitPack())
//            return true;
//        return false;
//    }

//}
void XL803Proto::set_config(YM_PARR_TYPE * parr,PAGE page)
{
    for(int i=0;i<8;i++)
    {
        m_parr[i]->Constp=parr->Constp;
        m_parr[i]->Constq=parr->Constq;
        m_parr[i]->PowerConstP=parr->PowerConstP;
        m_parr[i]->PowerConstQ=parr->PowerConstQ;
        m_parr[i]->CheckNum=parr->CheckNum;
        m_parr[i]->CheckType=parr->CheckType;
        m_parr[i]->SAvergeNum=parr->SAvergeNum;
        m_parr[i]->CalType=parr->CalType;
    }
}
void XL803Proto::set_ac(float u, float i,int line,int order)
{
    m_ac.IA=i;
    m_ac.IB=i;
    m_ac.IC=i;
    m_ac.UA=u;
    m_ac.UB=u;
    m_ac.UC=u;
    m_ac.FAB=50;
    m_ac.FC=50;
    if(line)
    {
        if(order)
        {
            m_ac.UaAngle=30;
            m_ac.UbAngle=0;
            m_ac.UcAngle=90;
            m_ac.IaAngle=0;
            m_ac.IbAngle=0;
            m_ac.IcAngle=240;
        }else
        {
            m_ac.UaAngle=30;
            m_ac.UbAngle=0;
            m_ac.UcAngle=90;
            m_ac.IaAngle=0;
            m_ac.IbAngle=0;
            m_ac.IcAngle=120;
        }
    }else
    {
        if(order)
        {
            m_ac.UaAngle=0;
            m_ac.UbAngle=120;
            m_ac.UcAngle=240;
            m_ac.IaAngle=0;
            m_ac.IbAngle=120;
            m_ac.IcAngle=240;
        }else
        {
            m_ac.UaAngle=0;
            m_ac.UbAngle=240;
            m_ac.UcAngle=120;
            m_ac.IaAngle=0;
            m_ac.IbAngle=240;
            m_ac.IcAngle=120;
        }
    }
}
void XL803Proto::set_ac(const AC_TYPE &ac)
{
    m_ac.FAB=ac.FAB;
    m_ac.FC=ac.FC;
    m_ac.IA=ac.IA;
    m_ac.IaAngle=ac.IaAngle;
    m_ac.IB=ac.IB;
    m_ac.IbAngle=ac.IbAngle;
    m_ac.IC=ac.IC;
    m_ac.IcAngle=ac.IcAngle;
    m_ac.UA=ac.UA;
    m_ac.UaAngle=ac.UaAngle;
    m_ac.UB=ac.UB;
    m_ac.UbAngle=ac.UbAngle;
    m_ac.UC=ac.UC;
    m_ac.UcAngle=ac.UcAngle;
}
AC_TYPE XL803Proto::get_ac()
{
    return m_ac;
}

bool XL803Proto::COM_step_output(quint8 a,float b,PAGE page)
{
    ms_dSize=0;
    *ms_data=a;
    float * data=&b;
    quint8 *now_point=ms_data+1;
    qint8 * byte_data=(qint8 *)data;
    for(int i=0;i<4;i++)
    {
        *now_point=*byte_data;
        now_point++;
        byte_data++;
    }
    ms_dSize+=sizeof(quint8);
    ms_dSize+=sizeof(float);
    if(sendPack(STEP_ADD,1000,page) && waitPack())
        return true;
    return false;
}
void XL803Proto::read_addr(PAGE page)
{
    for(int i=0;i<4;i++)
    {
        ms_data[i]=0xFE;
    }
    ms_data[4]=0x68;
    for(int i=1;i<7;i++)
    {
        ms_data[i+4]=0xAA;
    }
    ms_data[11]=0x68;
    ms_data[12]=0x13;
    ms_data[13]=0x00;
    ms_data[14]=checkSum(ms_data+4,10);
    ms_data[15]=0x16;
    emit write_to_memter(QByteArray((char*)ms_data,16));
}
void XL803Proto::read_meter(int type)
{
    for(int i=0;i<4;i++)
    {
        ms_data[i]=0xFE;
    }
    ms_data[4]=0x68;
    for(int i=1;i<7;i++)
    {
        ms_data[i+4]=meter_addr[i-1];
        //ms_data[i+4]=0x88;
    }
    ms_data[11]=0x68;
    ms_data[12]=0x11;
    ms_data[13]=0x04;
    switch (type) {
    case 0://U
        ms_data[17]=0x02+0x33;
        ms_data[16]=0x01+0x33;
        ms_data[15]=0xFF+0x33;
        ms_data[14]=0x00+0x33;
        break;
    case 1://I
        ms_data[17]=0x02+0x33;
        ms_data[16]=0x02+0x33;
        ms_data[15]=0xFF+0x33;
        ms_data[14]=0x00+0x33;
        break;
    case 2://PF
        ms_data[17]=0x02+0x33;
        ms_data[16]=0x06+0x33;
        ms_data[15]=0xFF+0x33;
        ms_data[14]=0x00+0x33;
        break;
    case 3://P
        ms_data[17]=0x02+0x33;
        ms_data[16]=0x03+0x33;
        ms_data[15]=0xFF+0x33;
        ms_data[14]=0x00+0x33;
        break;
    case 4://Q
        ms_data[17]=0x02+0x33;
        ms_data[16]=0x04+0x33;
        ms_data[15]=0xFF+0x33;
        ms_data[14]=0x00+0x33;
        break;
    case 5://S
        ms_data[17]=0x02+0x33;
        ms_data[16]=0x05+0x33;
        ms_data[15]=0xFF+0x33;
        ms_data[14]=0x00+0x33;
        break;
    case 6://相角
        ms_data[17]=0x02+0x33;
        ms_data[16]=0x07+0x33;
        ms_data[15]=0xFF+0x33;
        ms_data[14]=0x00+0x33;
        break;
    case 7://Freq
        ms_data[17]=0x02+0x33;
        ms_data[16]=0x80+0x33;
        ms_data[15]=0x00+0x33;
        ms_data[14]=0x02+0x33;
        break;
    default:
        break;
    }
    ms_data[18]=checkSum(ms_data+4,14);
    ms_data[19]=0x16;
    emit write_to_memter(QByteArray((char*)ms_data,20));
}
bool XL803Proto::read_control_file_list(PAGE page)
{
    ms_dSize = 0;
    if(sendPack(READ_CONTROL_FILE_LIST,1000,page) && waitPack())
        return true;

    return false;
}
bool XL803Proto::read_control_file(quint8 file_number,PAGE page)
{
    ms_dSize = 1;
    *ms_data=file_number;
    if(sendPack(READ_CONTROL_FILE,1000,page) && waitPack())
        return true;

    return false;
}
bool XL803Proto::read_now_file_number(PAGE page)
{
    ms_dSize = 0;
    if(sendPack(READ_NOW_FILE_NUMBER,1000,page) && waitPack())
        return true;

    return false;
}
bool XL803Proto::write_control_file(const QByteArray re,PAGE page)
{
    ms_dSize=re.length();
    memcpy(ms_data,re.data(),ms_dSize);
    if(sendPack(WRITE_CONTROL_FILE,1000,page) && waitPack())
        return true;

    return false;
}
bool XL803Proto::write_key(quint16 key,PAGE page)
{
    ms_dSize = 2;
    *((quint16*)ms_data)=key;
    if(sendPack(WRITE_KEY,1000,page) && waitPack())
        return true;

    return false;
}
bool XL803Proto::change_control_model(quint8 type,PAGE page)
{
    ms_dSize = 1;
    *ms_data=type;
    if(sendPack(CHANGE_CONTROL_MODEL,1000,page) && waitPack())
        return true;

    return false;
}
bool XL803Proto::set_now_file_number(quint8 file_number,PAGE page)
{
    ms_dSize = 1;
    *ms_data=file_number;
    if(sendPack(SET_NOW_FILE_NUMBER,1000,page) && waitPack())
        return true;

    return false;
}
bool XL803Proto::remove_control_file(quint8 file_number,PAGE page)
{
    ms_dSize = 1;
    *ms_data=file_number;
    if(sendPack(REMOVE_CONTROL_FILE,1000,page) && waitPack())
        return true;

    return false;
}
bool XL803Proto::set_check_num(quint32 num,PAGE page)
{
    ms_dSize=4;
    *(quint32 *)ms_data=num;
    if(sendPack(SET_CHECK_NUM,1000,page)&& waitPack())
        return true;
    return false;
}
bool XL803Proto::clear_energy(quint8 flag,PAGE page)
{
    ms_dSize=1;
    *ms_data=flag;
    if(sendPack(CLEAR_ENERGY,1000,page)&& waitPack())
        return true;
    return false;
}
bool XL803Proto::set_energy_pipe(quint8 flag,PAGE page)
{
    ms_dSize=1;
    *ms_data=flag;
    if(sendPack(SET_ENERGY_PIPE,1000,page)&& waitPack())
        return true;
    return false;
}
bool XL803Proto::set_compensation_factor(float pipe[],PAGE page)
{
    ms_dSize=3*sizeof(float);
    *((float *)ms_data)=pipe[0];
    *((float *)ms_data+1)=pipe[1];
    *((float *)ms_data+2)=pipe[2];
    if(sendPack(SET_COMPENSATION_FACTOR,1000,page)&& waitPack())
        return true;
    return false;
}
bool XL803Proto::set_plus_type(quint8 pipe[],PAGE page)
{
    ms_dSize=3*sizeof(quint8);
    *(ms_data)=pipe[0];
    *(ms_data+1)=pipe[1];
    *(ms_data+2)=pipe[2];
    if(sendPack(SET_PLUS_TYPE,1000,page)&& waitPack())
        return true;
    return false;
}
bool XL803Proto::read_plus(PAGE page)
{
    ms_dSize=1;
    *ms_data=0x00;
    if(sendPack(DCME_ERROR_STATE,1000,page)&& waitPack())
        return true;
    return false;
}
bool XL803Proto::test_connet(PAGE page)
{
    ms_dSize=0;
    if(sendPack(TEST_CONNECT,1000,page)&& waitPack())
        return true;
    return false;
}
bool XL803Proto::read_meter_const(quint8 flag,PAGE page)
{
    ms_dSize=1;
    *ms_data=flag;
    if(sendPack(READ_METER_CONST,1000,page)&& waitPack())
        return true;
    return false;
}
bool XL803Proto::set_meter_const(const QByteArray re,quint8 type,PAGE page)
{
    ms_dSize=sizeof(METER_PARA)+1;
    *ms_data=type;
    memcpy(ms_data+1,re.data(),sizeof(METER_PARA));
    if(sendPack(SET_METER_CONST,1000,page)&& waitPack())
        return true;
    return false;
}
qint32 XL803Proto::float_to_quint(float data)
{
    qint32 new_data=0;
    for(int i=0;i<4;i++)
    {
        *((quint8*)&new_data+i)=*((quint8*)&data+i);
    }
    return new_data;
}

bool XL803Proto::read_local_const(PAGE page)
{
    ms_dSize=1;
    *ms_data=0;
    if(sendPack(READ_LOCAL_CONST,1000,page)&& waitPack())
        return true;
    return false;
}
bool XL803Proto::set_local_const(const QByteArray re,  PAGE page)
{
    ms_dSize=sizeof(LOCAL_PARA)+1;
    *ms_data=0;
    memcpy(ms_data+1,re.data(),sizeof(METER_PARA));
    if(sendPack(SET_LOCAL_CONST,1000,page)&& waitPack())
        return true;
    return false;
}
bool XL803Proto::check_state(quint8 type,PAGE page)
{
    ms_dSize=1;
    *ms_data=type;
    if(sendPack(CHECK_STATE,1000,page)&& waitPack())
        return true;
    return false;
}
bool XL803Proto::clear_state(quint8 type1,quint8 type2,quint8 type3,PAGE page)
{
    ms_dSize=3;
    *ms_data=type1;
    *(ms_data+1)=type2;
    *(ms_data+2)=type3;
    if(sendPack(CLEAR_STATE,1000,page)&& waitPack())
        return true;
    return false;
}
bool XL803Proto::set_meter_ratio(float ratio[],PAGE page)
{
    ms_dSize=sizeof(float)*5;
    memcpy(ms_data,ratio,ms_dSize);
    if(sendPack(SET_METET_RATIO,1000,page)&& waitPack())
        return true;
    return false;
}
bool XL803Proto::read_meter_ratio(PAGE page)
{
    ms_dSize=0;
    if(sendPack(GET_METET_RATIO,1000,page)&& waitPack())
        return true;
    return false;
}
QString XL803Proto::float_to_str(double data, int len)
{
    QString str;
    str=QString("%1").arg(data);
    if(str.indexOf(".")<0)
    {
        return str;
    }else
    {
        return str.mid(0,str.indexOf(".")+len);
    }
}

//插值，dataIn输入数据，inSize输入数据点数，simpIn输入数据采样率，simpOut需要输出的采样率，outSize输出的采样数据点数，maxValue采样点最大值。
quint8 XL803Proto::SIE_reGetData(float *dataIn,quint32 inSize,quint32 simpIn,float *dataOut,quint32 &outSize,quint32 simpOut,float &maxValue)
{
    outSize = (((double)inSize/(double)simpIn) * simpOut + 0.5);			//输出采样点数个数。

    float tempData;
    float inIndexF;
    quint32 inIndexI;		//原始数据位置
    maxValue = 0;
    float tt = 0;

    for(quint32 i = 0; i < outSize; i++)
    {
        inIndexF = (double)simpIn /simpOut * i;
        inIndexI = (quint32)inIndexF;
        //拉格朗日插值，3点法
        //取前一点，跟后两点进行插值，时间单位分别为1，从而进行简化。
        float t = inIndexF - inIndexI;
        dataOut[i] = dataIn[inIndexI]*(t-1.0)*(t-2.0)/2.0 - dataIn[inIndexI + 1]*t*(t-2.0)+ dataIn[inIndexI + 2]*t*(t-1.0)/2.0;

        tt = dataOut[i];
        if(tt < 0)
            tt = - tt;

        if(maxValue < tt)
            maxValue = tt;
    }
    return 1;
}
void XL803Proto::createCurve(QVector<M_point> &originPoint,int originCount,QVector<M_point> &curvePoint){
    //控制点收缩系数 ，经调试0.6较好
    float scale = 0.6;
    QVector<M_point> midpoints(originCount+1);
    //生成中点
    for(int i = 0 ;i < originCount+1; i++){
        int nexti = (i + 1) ;
        if(nexti==originCount)
        {
            midpoints[i].x=originPoint[i].x;
            midpoints[i].y =originPoint[i].y;
        }else if(i==originCount)
        {
            midpoints[i].x=-originPoint[0].x;
            midpoints[i].y=-originPoint[0].y;
        }else
        {
            midpoints[i].x= (originPoint[i].x + originPoint[nexti].x)/2.0;
            midpoints[i].y = (originPoint[i].y + originPoint[nexti].y)/2.0;
        }
    }

    //平移中点
    M_point extrapoints[2 * (originCount)];
    for(int i = 0 ;i < originCount ; i++){
         int nexti = (i + 1) % originCount;
         int backi = (i + originCount - 1) % midpoints.count();
         M_point midinmid;
         midinmid.x = (midpoints[i].x + midpoints[backi].x)/2.0;
         midinmid.y = (midpoints[i].y + midpoints[backi].y)/2.0;
         double offsetx = originPoint[i].x - midinmid.x;
         double offsety = originPoint[i].y - midinmid.y;
         int extraindex = 2 * (i);
         extrapoints[extraindex].x = midpoints[backi].x + offsetx;
         extrapoints[extraindex].y = midpoints[backi].y + offsety;
         //朝 originPoint[i]方向收缩

         double addx = (extrapoints[extraindex].x - originPoint[i].x) * scale;
         double addy = (extrapoints[extraindex].y - originPoint[i].y) * scale;
         extrapoints[extraindex].x = originPoint[i].x + addx;
         extrapoints[extraindex].y = originPoint[i].y + addy;

         int extranexti = (extraindex + 1)%(2 * originCount);
         extrapoints[extranexti].x = midpoints[i].x + offsetx;
         extrapoints[extranexti].y = midpoints[i].y + offsety;
         //朝 originPoint[i]方向收缩
         addx = (extrapoints[extranexti].x - originPoint[i].x) * scale;
         addy = (extrapoints[extranexti].y - originPoint[i].y) * scale;
         extrapoints[extranexti].x = originPoint[i].x + addx;
         extrapoints[extranexti].y = originPoint[i].y + addy;

    }

    QVector<M_point>  controlPoint(4);
    //生成4控制点，产生贝塞尔曲线
    for(int i = 0 ;i < originCount-1 ; i++){
           controlPoint[0] = originPoint[i];
           int extraindex = 2 * i;
           controlPoint[1] = extrapoints[extraindex + 1];
           int extranexti = (extraindex + 2) % (2 * originCount);
           controlPoint[2] = extrapoints[extranexti];
           int nexti = (i + 1) % originCount;
           controlPoint[3] = originPoint[nexti];
           float u = 1;
           while(u >= 0){
               double px = bezier3funcX(u,controlPoint);
               double py = bezier3funcY(u,controlPoint);
               //u的步长决定曲线的疏密
               u -= 0.01;
               M_point tempP;
//               if(px<0)
//                   break;
//               if(px==0)
//               {
//                   tempP.x=0;
//                   tempP.y=0;
//                   curvePoint.push_back(tempP);
//                    break;
//               }
               tempP.x=px;
               tempP.y=py;
               //存入曲线点
               curvePoint.push_back(tempP);
           }
    }
}
//三次贝塞尔曲线
float XL803Proto::bezier3funcX(float uu,QVector<M_point> &controlP){
   float part0 = controlP[0].x * uu * uu * uu;
   float part1 = 3 * controlP[1].x * uu * uu * (1 - uu);
   float part2 = 3 * controlP[2].x * uu * (1 - uu) * (1 - uu);
   float part3 = controlP[3].x * (1 - uu) * (1 - uu) * (1 - uu);
   return part0 + part1 + part2 + part3;
}
float XL803Proto::bezier3funcY(float uu,QVector<M_point> &controlP){
   float part0 = controlP[0].y * uu * uu * uu;
   float part1 = 3 * controlP[1].y * uu * uu * (1 - uu);
   float part2 = 3 * controlP[2].y * uu * (1 - uu) * (1 - uu);
   float part3 = controlP[3].y * (1 - uu) * (1 - uu) * (1 - uu);
   return part0 + part1 + part2 + part3;
}

//正弦插值 in_point输入点 out_point输出点 point_num准备生成点的数量 len x轴范围 默认in_point包含x轴起始点与结束点

void XL803Proto::sin_insert(QVector<M_point> in_point,QVector<M_point> &out_point,int point_num,double len)
{
    M_point p_start;
    M_point p_end;
    M_point p_now;
    double step=len/point_num;
    double A=0;
    double t=0;
    double b=0;
    for(int i=0;i<in_point.count()-1;i++)
    {

        p_start=in_point.at(i);
        p_now=in_point.at(i);
        p_end=in_point.at(i+1);
        if(p_end.y>p_start.y)
        {
            A=(p_end.y-p_start.y)/2;
            t=(p_end.x-p_start.x)/2*3;
            b=p_end.y-A;
        }else
        {
            A=(p_start.y-p_end.y)/2;
            t=(p_end.x-p_start.x)/2;
            b=p_start.y-A;
        }
        for(int i=0;p_now.x<p_end.x;p_now.x+=step,t+=step)
        {
            p_now.y=A*sin(2*M_PI*(1/((p_end.x-p_start.x)*2))*t)+b;
            out_point<<p_now;
        }
    }
}

void  XL803Proto::set_map(CustomPlotHasRoll *map)
{
    map->xAxis->setBasePen(QPen(Qt::white, 1));
    map->yAxis->setBasePen(QPen(Qt::white, 1));
    map->xAxis->setTickPen(QPen(Qt::white, 1));
    map->yAxis->setTickPen(QPen(Qt::white, 1));
    map->xAxis->setSubTickPen(QPen(Qt::white, 1));
    map->yAxis->setSubTickPen(QPen(Qt::white, 1));
    map->xAxis->setTickLabelColor(Qt::white);
    map->yAxis->setTickLabelColor(Qt::white);
    map->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    map->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    map->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    map->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    map->xAxis->grid()->setSubGridVisible(true);
    map->yAxis->grid()->setSubGridVisible(true);
    map->xAxis->grid()->setZeroLinePen(Qt::NoPen);
    map->yAxis->grid()->setZeroLinePen(Qt::NoPen);
    map->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    map->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    QLinearGradient plotGradient;
    plotGradient.setStart(0, 0);
    plotGradient.setFinalStop(0, 350);
    plotGradient.setColorAt(0, QColor(80, 80, 80));
    plotGradient.setColorAt(1, QColor(50, 50, 50));
    map->setBackground(plotGradient);
    QLinearGradient axisRectGradient;
    axisRectGradient.setStart(0, 0);
    axisRectGradient.setFinalStop(0, 350);
    axisRectGradient.setColorAt(0, QColor(80, 80, 80));
    axisRectGradient.setColorAt(1, QColor(30, 30, 30));
    map->axisRect()->setBackground(axisRectGradient);
    map->rescaleAxes();
//    QSharedPointer<QCPAxisTickerFixed> ticker(new QCPAxisTickerFixed);
//    ticker->setTickStep(0.1);
//    ticker->setTickCount(10);
//    map->xAxis->setTicker(ticker);
    map->xAxis->setSubTickLength(1);
    map->xAxis->setRange(0,1);
    map->xAxis->setLabelColor(QColor(255,255,255));
    map->yAxis->setLabelColor(QColor(255,255,255));
}
bool XL803Proto::start_down_simpdata(quint32 data_count,quint32 byte_freq,quint32 lenth,quint8 pipe,quint8 type,PAGE page)
{
    ms_dSize=sizeof(quint32)*3+sizeof(quint8)*2;
    quint32 * data=(quint32 *)ms_data;
    *data=data_count;
    *++data=byte_freq;
    *++data=lenth;
    *(quint8*)(++data)=pipe;
    *((quint8*)(data)+1)=type;
    if(sendPack(DOWN_SIMPDATA_START,1000,page)&& waitPack())
        return true;
    return false;
}
bool XL803Proto::down_simpdata(quint16 index,QByteArray data,quint8 check_num,PAGE page)
{
    ms_dSize=sizeof(quint16)+sizeof(quint8)+data.length();
    *(quint16 *)ms_data=index;
    memcpy(ms_data+2,data.data(),data.length());
    *(ms_data+data.length()+2)=check_num;
    if(sendPack(DOWN_SIMPDATA,1000,page)&& waitPack())
        return true;
    return false;
}
bool XL803Proto::stop_down_simpdata(PAGE page)
{
    ms_dSize=0;
    if(sendPack(DOWN_SIMPDATA_STOP,1000,page)&& waitPack())
        return true;
    return false;
}
bool XL803Proto::get_dma_freq(PAGE page)
{
    ms_dSize=0;
    if(sendPack(DMA_OUT_FREQ,1000,page)&& waitPack())
        return true;
    return false;
}
bool XL803Proto::output_simpdata_start(quint8 mode,QByteArray data,PAGE page)
{
    ms_dSize=data.length()+sizeof(quint8);
    *ms_data=mode;
    memcpy(ms_data+1,data.data(),data.length());
    if(sendPack(DOWN_DATA_OUTPOUT_START	,1000,page)&& waitPack())
        return true;
    return false;
}
bool XL803Proto::output_simpdata_stop(QByteArray data,PAGE page)
{
    ms_dSize=data.length();
    memcpy(ms_data,data.data(),data.length());
    if(sendPack(DOWN_DATA_OUTPOUT_STOP,1000,page)&& waitPack())
        return true;
    return false;
}

qint8 XL803Proto::getCalculatorValue(char *f,int type)
{
    char exp[EXP_MAX_LEN];	//expression 表达式
    int len;//表达式长度
    int precision;//控制精度
    int biginteger;//控制是否大整数模式

    int index, index_suf;//指示表达式当前位置
    int i, j;//循环变量
    memset(sufexp[type],0,EXP_MAX_LEN);
    memset(buffer[type],0,EXP_MAX_LEN);
    sufexp[type][EXP_MAX_LEN-1]='\0';
    buffer[type][EXP_MAX_LEN-1]='\0';
    op_stack.top = -1;
    num_stack.top = -1;
    memset(op_stack.op[type],0,STACK_MAX);
    op_stack.op[type][STACK_MAX-1]='\0';
    memset(num_stack.num[type],0,STACK_MAX);
    num_stack.num[type][STACK_MAX-1]='\0';
    precision = 3;
    biginteger = 0;

    strcpy(buffer[type],f);

    if (!biginteger)
    {
        //*****************   预处理（清空格,解析替换,预判错）  ******  START  ********
        int delta_bracket = 0;//左括号数-右括号数
        for (i = 0; i < (int)strlen(buffer[type]); i++)//全部转为小写
            buffer[type][i] = tolower(buffer[type][i]);
        for (i = 0, j = 0; i <= (int)strlen(buffer[type]); i++)
        {
            if (buffer[type][i] == '+')//将正号消除
            {
                if (j == 0 || (is_op(exp[j-1]) && exp[j-1] != ')' && exp[j-1] != '!'))//前面为空，或者是非右括号的运算符，说明这个应该不是加，是正号
                    continue;
            }
            else if (buffer[type][i] == '-')//负号改为~
            {
                if (j == 0 || (is_op(exp[j-1]) && exp[j-1] != ')' && exp[j-1] != '!'))//前面为空，或者是非右括号的运算符，说明这个应该不是加，是正号
                {
                    exp[j++] = '~';
                    continue;
                }
            }
            else if (buffer[type][i] == '(')
            {
                delta_bracket++;
                if (j > 0)
                    if (is_num(exp[j-1]) || exp[j-1] == ')')//左括号左边的乘号可以省略
                        exp[j++] = '*';
            }
            else if (buffer[type][i] == ')')
            {
                delta_bracket--;
                if (delta_bracket < 0)//右括号数大于左括号，必错
                    break;
            }
            else if (buffer[type][i] >= 'a' && buffer[type][i] <= 'z')//说明是函数或者是常数
            {
                if (j > 0)
                    if (is_num(exp[j-1]))
                        exp[j++]='*';
                //常数或函数前的*可以省略
                if (buffer[type][i] == 'e') {exp[j++]='E'; continue;}//常数E
                char tmp[5];
                for (int k = 0; k < 4; k++)//提取
                    tmp[k] = buffer[type][i+k];
                tmp[4] = '\0';
                if (!strcmp(tmp, "sinh"))	{exp[j++]='S'; i += 3; continue;}
                if (!strcmp(tmp, "cosh"))	{exp[j++]='C'; i += 3; continue;}
                if (!strcmp(tmp, "tanh"))	{exp[j++]='T'; i += 3; continue;}
                if (!strcmp(tmp, "coth"))	{exp[j++]='O'; i += 3; continue;}
                if (!strcmp(tmp, "sign"))	{exp[j++]='g'; i += 3; continue;}
                if (!strcmp(tmp, "sqrt"))	{exp[j++]='q'; i += 3; continue;}
                tmp[3] = '\0';
                if (!strcmp(tmp, "sin"))	{exp[j++]='s'; i += 2; continue;}
                if (!strcmp(tmp, "cos"))	{exp[j++]='c'; i += 2; continue;}
                if (!strcmp(tmp, "tan"))	{exp[j++]='t'; i += 2; continue;}
                if (!strcmp(tmp, "cot"))	{exp[j++]='o'; i += 2; continue;}
                if (!strcmp(tmp, "ctg"))	{exp[j++]='o'; i += 2; continue;}
                if (!strcmp(tmp, "abs"))	{exp[j++]='a'; i += 2; continue;}
                if (!strcmp(tmp, "log"))	{exp[j++]='L'; i += 2; continue;}
                tmp[2] = '\0';
                if (!strcmp(tmp, "tg"))		{exp[j++]='t'; i += 1; continue;}
                if (!strcmp(tmp, "ln"))		{exp[j++]='l'; i += 1; continue;}
                if (!strcmp(tmp, "sh"))		{exp[j++]='S'; i += 1; continue;}
                if (!strcmp(tmp, "ch"))		{exp[j++]='C'; i += 1; continue;}
                if (!strcmp(tmp, "pi"))		{exp[j++]='P'; i += 1; continue;}//常数PI
                if (!strcmp(tmp, "ti"))		{exp[j++]='x'; i += 1; continue;}
                //是字母却未找到匹配
                fprintf(stderr, "\aUnsupported Function!");
                //system("pause");
                return -1;
            }

            if (buffer[type][i] != ' ')
                exp[j++] = buffer[type][i];
        }
        if (delta_bracket != 0)//括号不匹配
        {
            fprintf(stderr, "\aError: Bracket mismatched！");
            //system("pause");
            return -1;
        }
        //********************  预处理（清空格,解析替换,预判错） *********END*********
        len = strlen(exp);
        index = 0;	//指示中缀表达式当前位置
        index_suf = 0;//指示后缀表达式当前位置

        //*********************  中缀表达式转后缀表达式   ************START************
        while (index < len)
        {
            //提取数
            while ((index < len) && is_num(exp[index]))
            {
                sufexp[type][index_suf++] = exp[index++];
            }
            sufexp[type][index_suf++] = ' ';
            //处理符号
            while ((index < len) && is_op(exp[index]))
            {
                char c = exp[index++];
                if (c == ')')
                {
                    while (op_stack.op[type][op_stack.top] != '(')//所有（）间的元素出栈
                    {
                        sufexp[type][index_suf++] = pop_op(type);
                        sufexp[type][index_suf++] = ' ';
                    }
                    pop_op(type);//删除（
                }
                else
                {
                    while (op_stack.top >= 0 && oplevel(c) <= oplevel(op_stack.op[type][op_stack.top]))
                    {
                        //不停弹栈输出，直到栈顶元素优先级比c低或为(为止
                        if (op_stack.op[type][op_stack.top]== '(')	break;
                        sufexp[type][index_suf++] = pop_op(type);
                        sufexp[type][index_suf++] = ' ';
                    }
                    push_op(c,type);
                }
            }
        }
        //已经到了结尾，如果符号栈中还有没输出的，一并输出
        while (op_stack.top >= 0)
        {
            sufexp[type][index_suf++] = pop_op(type);
            sufexp[type][index_suf++] = ' ';
        }
        sufexp[type][--index_suf] = '\0';
        //puts(sufexp);
        //现在我们化成的后缀表达式相邻两个单元都由一个空格隔开
        //*********************   中缀表达式转后缀表达式   ************END************

        //*********************   后缀表达式计算值   ******************Start**********
    }
    return 1;
}
double XL803Proto::get_value(double time,int type)
{
    int index_suf = 0;//指示后缀表达式当前位置
    int index_buf=0;
    int len = strlen(sufexp[type]);
    double angle;//控制弧度与角度转换
    double value;
    struct NumStack now_num_stack;
    char now_sufexp[EXP_MAX_LEN]={0};//suffix expression 后缀表达式
    char now_buffer[EXP_MAX_LEN]={0};

    angle = 1.0;
    memcpy(now_sufexp,sufexp[type],EXP_MAX_LEN);
    memcpy(now_buffer,buffer[type],EXP_MAX_LEN);
    now_num_stack.top=num_stack.top;
    memcpy(now_num_stack.num[type],num_stack.num[type],STACK_MAX);
    while (index_suf < len)
    {
        //提取数
        index_buf = 0;//指示buffer当前位置
        while ((index_suf < len) && is_num(sufexp[type][index_suf]))
            buffer[type][index_buf++] = sufexp[type][index_suf++];
        if (buffer[type][index_buf-1] == 'P')
            push_num(PI,type);
        else if (buffer[type][index_buf-1] == 'E')
            push_num(E,type);
        else if (buffer[type][index_buf-1] == 'x')
            push_num(time,type);
        else
        {
            buffer[type][index_buf] = '\0';//将字符串转为double
            push_num(atof(buffer[type]),type);
        }
        index_suf++;//跳过空格
        //处理符号
        while ((index_suf < len) && is_op(sufexp[type][index_suf]))
        {
            char c = sufexp[type][index_suf];
            double f1, f2;//tmp
            int t;//tmp
            index_suf += 2;	//跳过空格
            switch (c)
            {
            case '+':
                push_num(pop_num(type)+pop_num(type),type);
                break;
            case '-':
                push_num(-pop_num(type)+pop_num(type),type);
                break;
            case '~':
                push_num(-pop_num(type),type);
                break;
            case '*':
                push_num(pop_num(type)*pop_num(type),type);
                break;
            case '/':
                f1 = pop_num(type);
                if (f1 == 0.0)
                {
                    return 0;
                }
                else
                    push_num(pop_num(type)/f1,type);
                break;
            case '^':
                f1 = pop_num(type);
                f2 = pop_num(type);
                if (f1 == 0.0 && f2 == 0.0)
                {
                    return 0;
                }
                else
                    push_num(pow(f2, f1),type);
                break;
            case '!':
                f1 = pop_num(type);
                t = (int)f1;
                if (f1 - t != 0.0 || f1 < 0)//f不是整数或者是负数
                {
                    return 0;
                }
                else
                    push_num((double)fac(t),type);
                break;
            case 's'://sin
                push_num(sin(pop_num(type)*angle),type);
                break;
            case 'c'://cos
                push_num(cos(pop_num(type)*angle),type);
                break;
            case 't'://tan
                f2 =pop_num(type);
                f1 = tan(f2*angle);
                if (f1 > INF)
                {
                    return 0;
                }
                else
                    push_num(f1,type);
                break;
            case 'o'://cot
                f1 = tan(pop_num(type)*angle);
                if (abs(f1) < LIM_ZERO)
                {
                    return 0;
                }
                else if (abs(f1) > INF)
                    push_num(0.0,type);
                else
                    push_num(1/f1,type);
                break;
            case 'a':
                push_num(abs(pop_num(type)),type);
                break;
            case 'g'://sign()符号函数
                push_num(sign(pop_num(type)),type);
                break;
            case 'q'://sqrt
                f1 = pop_num(type);
                if (f1 < 0)
                {
                    return 0;
                }
                push_num(sqrt(f1),type);
                break;
            case 'l'://ln
                f1 = pop_num(type);
                if (f1 <= 0)
                {
                    return 0;
                }
                push_num(log(f1),type);
                break;
            case 'L'://log10
                f1 = pop_num(type);
                if (f1 <= 0)
                {
                    return 0;
                }
                push_num(log10(f1),type);
                break;
            case 'S'://sinh
                push_num(sinh(pop_num(type)),type);
                break;
            case 'C'://cosh
                push_num(cosh(pop_num(type)),type);
                break;
            case 'T'://tanh
                push_num(tanh(pop_num(type)),type);
                break;
            case 'O'://coth
                f1 = pop_num(type);
                if (f1 < LIM_ZERO)
                {
                    return 0;
                }
                else
                    push_num(1/tanh(f1),type);
                break;
            default:
                return 0;
                break;
            }
        }
    }
    double ans = pop_num(type);
    if ((ans - floor(ans) < LIM_ZERO))
    {
        value =(int)floor(ans);
    }
    else if ((ceil(ans) - ans < LIM_ZERO))
    {
        value = (int)ceil(ans);
    }
    else
    {
        value = ans;
    }
    memcpy(sufexp[type],now_sufexp,EXP_MAX_LEN);
    memcpy(buffer[type],now_buffer,EXP_MAX_LEN);
    num_stack.top=now_num_stack.top;
    memcpy(num_stack.num[type],now_num_stack.num[type],STACK_MAX);
    return value;
}
//=============  数符号相关  ======  START  =========//
int oplevel(char c)//判断运算符优先级
{
    switch (c)
    {
        case '+':
        case '-':
            return 0;
        case '*':
        case '/':
            return 1;
        case '~':
            return 2;
        case '^':
            return 3;
        case 's':
        case 'c':
        case 't':
        case 'o':
        case 'a':
        case 'g':
        case 'q':
        case 'l':
        case 'L':
        case 'S':
        case 'C':
        case 'T':
        case 'O':
            return 4;
        case '!':
            return 5;
        case '(':
        case ')':
            return 10;
        default:
            //exit(1);
            return 100;
    }

}

bool is_op(char c)//判断是否符号
{
    for (int i = 0; i < OP_NUM; i++)
        if (c == opr[i])
            return true;
    return false;
}

bool is_num(char c)//判断是否数
{
    if (c >= '0' && c <= '9')
        return true;
    if (c == '.')
        return true;
    if (c == 'E')
        return true;
    if (c == 'P')
        return true;
    if (c == 'x')
        return true;
    return false;
}
//=============  数符号相关  =======  END  =========//

//=============  数学函数  =======  START  =========//
int fac(int t)//阶乘
{
    int i;
    int result = 1;
    if (t <= 1)	return 1;
    for (i = 2; i <= t; i++)
        result *= i;
    return result;
}

double sign(double f)//符号函数
{
    if (f > 0)
        return 1.0;
    else if (f == 0 )
        return 0.0;
    else
        return -1.0;
}

void big_add(char n1[], char n2[])
{
    char result[EXP_MAX_LEN/2+1];
    int i;
    int la = strlen(n1);
    int lb = strlen(n2);
    int l = max(la, lb);
    for (i = 0; i <= l; i++)
        result[i] = '0';
    for (i = 0; i < l; i++)
    {
        if (i < la && i < lb)
            result[i] += n1[la-i-1]-'0'+n2[lb-i-1]-'0';
        else if(i < la)
            result[i] += n1[la-i-1]-'0';
        else
            result[i] += n2[lb-i-1]-'0';

        if (result[i] > '9')
        {
            result[i] = result[i] - 10;
            result[i+1] = '1';
        }
    }
    if (result[l] > '0')	l++;
    putchar('=');
    for (i = l - 1; i >= 0; i--)
    {
        putchar(result[i]);
    }
    putchar('\n');
}

void big_minus(char n1[], char n2[])
{
    char result[EXP_MAX_LEN/2];
    char temp[EXP_MAX_LEN/2];
    int i;
    int la = strlen(n1);
    int lb = strlen(n2);
    int l;
    int prefix = 1;

    if (la > lb)
        l = la;
    else if (la < lb)
    {
        l = lb;
        prefix = -1;
    }
    else
    {
        l = la;
        prefix = strcmp(n1, n2);
    }
    for (i = 0; i <= l; i++)
        result[i] = '0';
    if (prefix < 0)
    {
        strcpy(temp, n1);
        strcpy(n1, n2);
        strcpy(n2, temp);
        i = la;
        la = lb;
        lb = i;
    }
    for (i = 0; i < l; i ++)
    {
        if (i < la && i < lb)
            result[i] += n1[la-i-1]-n2[lb-i-1];
        else
            result[i] += n1[la-i-1]-'0';

        if (result[i] < '0')
        {
            result[i] += 10;
            result[i+1] = '0' - 1;
        }
    }
    int flag = 1;

    putchar('=');
    if (prefix == 0)
    {
        putchar('0');
        return;
    }
    else if (prefix < 0)
    {
        putchar('-');
    }
    for (i = l - 1; i >= 0; i--)
    {
        if (result[i] == '0' && flag)
            continue;
        flag = 0;
        putchar(result[i]);

    }
    putchar('\n');
}

//=============  数学函数  ========  END  =========//

//=============  栈相关  =========  START  ========//
void push_num(double f,int type)//数字栈压栈
{
    if (num_stack.top + 1 < STACK_MAX)
        num_stack.num[type][++num_stack.top] = f;
    else
    {
        fprintf(stderr, "\aNumStack Overflow!");
        //system("pause");
        //exit(1);
    }
}

double pop_num(int type)
{
    double f;
    if (num_stack.top > -1)
        f = num_stack.num[type][num_stack.top--];
    else
    {
        fprintf(stderr, "\aNumstack Underflow!");
        //system("pause");
        //exit(1);
    }
    return f;
}

void push_op(char c,int type)
{
    if (op_stack.top + 1 < STACK_MAX)
        op_stack.op[type][++op_stack.top] = c;
    else
    {
        fprintf(stderr, "OpStack Overflow!");
        //system("pause");
        //exit(1);
    }
}

char pop_op(int type)
{
    char c;
    if (op_stack.top > -1)
        c = op_stack.op[type][op_stack.top--];
    else
    {
        fprintf(stderr, "Opstack Underflow!");
        //system("pause");
        //exit(1);
    }
    return c;
}
//=============  栈相关  ==========  END  ========//



bool XL803Proto::start_adjust(PAGE page)
{
    ms_dSize=0;
    if(sendPack(ADJUST_START,1000,page)&& waitPack())
        return true;
    return false;
}
bool XL803Proto::read_adjust_num(quint8 pipe,quint8 lv,quint8 type,PAGE page)
{
    ms_dSize=3;
    *ms_data=pipe;
    *(ms_data+1)=lv;
    *(ms_data+2)=type;
    if(sendPack(READ_ADJUST_NUM,1000,page)&& waitPack())
        return true;
    return false;
}
bool XL803Proto::write_adjust_num(quint8 pipe,quint8 lv,quint8 type,QByteArray data,PAGE page)
{
    ms_dSize=3+data.count()*4;
    *ms_data=pipe;
    *(ms_data+1)=lv;
    *(ms_data+2)=type;
    memcpy(ms_data+3,data.data(),data.length());
    if(sendPack(WRITE_ADJUST_NUM,1000,page)&& waitPack())
        return true;
    return false;
}
bool XL803Proto::stop_adjust(PAGE page)
{
    ms_dSize=0;
    if(sendPack(ADJUST_END,1000,page)&& waitPack())
        return true;
    return false;
}
bool XL803Proto::init_std_num_list(PAGE page)
{
    ms_dSize=0;
    if(sendPack(INIT_STD_NUM_LIST,1000,page)&& waitPack())
        return true;
    return false;
}
bool XL803Proto::read_adjust_old_value(quint8 pipe,quint8 lv,quint8 type,PAGE page)
{
    ms_dSize=3;
    *ms_data=pipe;
    *(ms_data+1)=lv;
    *(ms_data+2)=type;
    if(sendPack(READ_ADJUST_OLD_VALUE,1000,page)&& waitPack())
        return true;
    return false;
}
bool XL803Proto::read_adjust_std_value(quint8 pipe,quint8 lv,quint8 type,PAGE page)
{
    ms_dSize=3;
    *ms_data=pipe;
    *(ms_data+1)=lv;
    *(ms_data+2)=type;
    if(sendPack(READ_ADJUST_STD_VALUE,1000,page)&& waitPack())
        return true;
    return false;
}
bool XL803Proto::read_std_num_value(quint8 pipe,quint8 lv,quint8 type,PAGE page)
{
    ms_dSize=3;
    *ms_data=pipe;
    *(ms_data+1)=lv;
    *(ms_data+2)=type;
    if(sendPack(DMA_OUT_FREQ,1000,page)&& waitPack())
        return true;
    return false;
}
bool XL803Proto::unenable_std_num(PAGE page)
{
    ms_dSize=0;
    if(sendPack(UNENABLE_STD_NUM,1000,page)&& waitPack())
        return true;
    return false;
}
bool XL803Proto::enable_std_num(PAGE page)
{
    ms_dSize=0;
    if(sendPack(ENABLE_STD_NUM,1000,page)&& waitPack())
        return true;
    return false;
}
bool XL803Proto::start_reout_wave(quint8 count,QByteArray data, PAGE page)
{
    ms_dSize=data.count()+1;
    *ms_data=count;
    memcpy(ms_data+1,data.data(),data.length());
    if(sendPack(WAVE_REOUT_START,1000,page)&& waitPack())
        return true;
    return false;
}
bool XL803Proto::read_max_reout_wave_lenth(PAGE page)
{
    ms_dSize=1;
    *ms_data=0;
    if(sendPack(READ_REOUT_MAX_LENTH,1000,page)&& waitPack())
        return true;
    return false;
}
char XL803Proto::ConvertHexChar(char ch)
{
    if((ch >= '0') && (ch <= '9'))
        return ch-0x30;
    else if((ch >= 'A') && (ch <= 'F'))
        return ch-'A'+10;
    else if((ch >= 'a') && (ch <= 'f'))
        return ch-'a'+10;
    else return (-1);
}


void XL803Proto::StringToHex(QString str, QByteArray &senddata)
{
    int hexdata,lowhexdata;
    int hexdatalen = 0;
    int len = str.length();
    senddata.resize(len/2);
    char lstr,hstr;
    for(int i=0; i<len; )
    {
        //char lstr,
        hstr=str[i].toLatin1();
        if(hstr == ' ')
        {
            i++;
            continue;
        }
        i++;
        if(i >= len)
            break;
        lstr = str[i].toLatin1();
        hexdata = ConvertHexChar(hstr);
        lowhexdata = ConvertHexChar(lstr);
        if((hexdata == 16) || (lowhexdata == 16))
            break;
        else
            hexdata = hexdata*16+lowhexdata;
        i++;
        senddata[hexdatalen] = (char)hexdata;
        hexdatalen++;
    }
    senddata.resize(hexdatalen);
}
bool XL803Proto::constraint_set_wave(PAGE page)
{
    //数据域的大小
    ms_dSize=3;
    *ms_data=0;
    *(ms_data+1)=2;
    *(ms_data+2)=4;
    //sendPack（0xF0，1000，BASE_OUT）
    if(sendPack(CONSTRAINT_WAVE_SET,1000,page)&& waitPack())
        return true;
    return false;
}
bool XL803Proto::big_wave_reout(QByteArray arry, PAGE page)
{
    ms_dSize=arry.length();
    memcpy(ms_data,arry.data(),arry.length());
    if(sendPack(SATRT_BIG_WAVE_REOUT,1000,page)&& waitPack())
        return true;
    return false;
}
bool XL803Proto::test_power_u(PAGE page)
{
    ms_dSize=1;
    *ms_data=0;
    if(sendPack(TEST_POWER_U,1000,page)&& waitPack())
        return true;
    return false;
}
bool XL803Proto::test_power_r(PAGE page)
{
    ms_dSize=1;
    *ms_data=0;
    if(sendPack(TEST_POWER_R,1000,page)&& waitPack())
        return true;
    return false;
}
bool XL803Proto::read_power_u_r(PAGE page)
{
    ms_dSize=1;
    *ms_data=0;
    if(sendPack(READ_POWER_U_R,1000,page)&& waitPack())
        return true;
    return false;
}
bool XL803Proto::start_power_out_ele(float i,float time,float u,PAGE page)
{
    m_float value;
    value.f=i;
    ms_dSize=12;
    for(int i=0;i<4;i++)
    {
        ms_data[i]=value.ui8[i];
    }
    value.f=time;
    for(int i=0;i<4;i++)
    {
        ms_data[4+i]=value.ui8[i];
    }
    value.f=u;
    for(int i=0;i<4;i++)
    {
        ms_data[8+i]=value.ui8[i];
    }
    if(sendPack(START_POWER_OUT_ELE,1000,page)&& waitPack())
        return true;
    return false;
}
bool XL803Proto::stop_power_out_ele(PAGE page)
{
    ms_dSize=1;
    *ms_data=0;
    if(sendPack(STOP_POWER_OUT_ELE,1000,page)&& waitPack())
        return true;
    return false;
}
void XL803Proto::test_bll(QByteArray data)
{
//    emit sendToPort(data,1000,PAGE::test_bll);
}
