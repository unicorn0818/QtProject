#ifndef XL803PROTO_H
#define XL803PROTO_H

#include <QObject>
#include <QMap>
#include <QStringList>
#include <QVariant>
#include <QMessageBox>

#include "customplothasroll.h"

#define MAX_803_DEV 8
#define DAC_CHNUM 16	//信号板输出的通道数，609信号板有16路输出共有8相。
#define OUT_PULSENUM 2	//输出脉冲数
#define IN_PULSENUM 3	//输入脉冲数
namespace XL803
{
	enum MARKERB
	{
		MARKERB_UA			=1,		//A相电压幅值
		MARKERB_UAP			=2,		//A相电压相位
		MARKERB_UB			=3,		//B相电压幅值
		MARKERB_UBP			=4,		//B相电压相位
		MARKERB_UC			=5,		//C相电压幅值
		MARKERB_UCP			=6,		//C相电压相位
        MARKERB_UD			=101,		//D相电压幅值
        MARKERB_UDP			=102,		//D相电压相位
        MARKERB_UA1			=103,		//A1相电压幅值
        MARKERB_UAP1		=104,		//A1相电压相位
        MARKERB_UB1			=105,		//B1相电压幅值
        MARKERB_UBP1		=106,		//B1相电压相位
        MARKERB_UC1			=107,		//C1相电压幅值
        MARKERB_UCP1		=108,		//C1相电压相位
        MARKERB_UD1			=109,		//D1相电压幅值
        MARKERB_UDP1		=110,		//D1相电压相位

		MARKERB_IA			=7,		//A相电流幅值
		MARKERB_IAP			=8,		//A相电流相位
		MARKERB_IB			=9,		//B相电流幅值
		MARKERB_IBP			=10,		//B相电流相位
		MARKERB_IC			=11,		//C相电流幅值
		MARKERB_ICP			=12,		//C相电流相位
        MARKERB_ID			=111,		//C相电流幅值
        MARKERB_IDP			=112,		//C相电流相位
        MARKERB_IA1			=113,		//A1相电流幅值
        MARKERB_IAP1		=114,		//A1相电流相位
        MARKERB_IB1			=115,		//B1相电流幅值
        MARKERB_IBP1		=116,		//B1相电流相位
        MARKERB_IC1			=117,		//C1相电流幅值
        MARKERB_ICP1		=118,		//C1相电流相位
        MARKERB_ID1			=119,		//D1相电流幅值
        MARKERB_IDP1		=120,		//D1相电流相位

		MARKERB_VDC			=13,
        MARKERB_FA			=14,
        MARKERB_FB			=15,
        MARKERB_FC			=16,
        MARKERB_FD          =121,
		MARKERB_AUA			=17,			//UA告警信息
		MARKERB_AUB			=18,			//UB告警信息
		MARKERB_AUC			=19,			//UC告警信息
		MARKERB_AIA			=20,			//IA告警信息
		MARKERB_AIB			=21,			//IB告警信息
		MARKERB_AIC			=22,			//IC告警信息

		MARKERB_SUA			=24,			//UA启动
		MARKERB_SUB			=25,
		MARKERB_SUC			=26,
        MARKERB_SUD         =132,
		MARKERB_SIA			=27,
		MARKERB_SIB			=28,
		MARKERB_SIC			=29,
        MARKERB_SID			=30,

        MARKERB_SUA1        =133,			//UA启动
        MARKERB_SUB1		=134,
        MARKERB_SUC1		=135,
        MARKERB_SUD1        =136,
        MARKERB_SIA1		=137,
        MARKERB_SIB1		=138,
        MARKERB_SIC1		=139,
        MARKERB_SID1		=140,

		MARKERB_EUA			=31,			//A相电压停止
		MARKERB_EUB			=32,			//B相电压停止
		MARKERB_EUC			=33,			//C相电压停止
        MARKERB_EUD         =141,
		MARKERB_EIA			=34,			//A相电流停止
		MARKERB_EIB			=35,			//B相电流停止
		MARKERB_EIC			=36,			//C相电流停止
        MARKERB_EID			=37,

        MARKERB_EUA1		=142,			//A相电压停止
        MARKERB_EUB1		=143,			//B相电压停止
        MARKERB_EUC1		=144,			//C相电压停止
        MARKERB_EUD1        =145,
        MARKERB_EIA1		=177,			//A相电流停止
        MARKERB_EIB1		=178,			//B相电流停止
        MARKERB_EIC1		=179,			//C相电流停止
        MARKERB_EID1		=180,

		MARKERB_DUA			=38,			//A相电压档位
		MARKERB_DUB			=39,			//B相电压档位
		MARKERB_DUC			=40,			//C相电压档位
        MARKERB_DUD         =146,           //D相电流档位
		MARKERB_DIA			=41,			//A相电流档位
		MARKERB_DIB			=42,			//B相电流档位
		MARKERB_DIC			=43,			//C相电流档位
        MARKERB_DID			=44,			//D相电流档位

        MARKERB_DUA1		=147,			//A1相电压档位
        MARKERB_DUB1		=148,			//B1相电压档位
        MARKERB_DUC1		=149,			//C1相电压档位
        MARKERB_DUD1        =150,           //D1相电流档位
        MARKERB_DIA1		=151,			//A1相电流档位
        MARKERB_DIB1		=152,			//B1相电流档位
        MARKERB_DIC1		=153,			//C1相电流档位
        MARKERB_DID1		=154,			//D1相电流档位

		MARKERB_WT_UA		=72,		//波形类型
		MARKERB_WT_IA		=73,
		MARKERB_WT_UB		=74,
		MARKERB_WT_IB		=75,
		MARKERB_WT_UC		=76,
		MARKERB_WT_IC		=77,
		MARKERB_WT_UD		=78,
		MARKERB_WT_ID		=79,
		MARKERB_WT_UA2		=80,		//波形类型
		MARKERB_WT_IA2		=81,
		MARKERB_WT_UB2		=82,
		MARKERB_WT_IB2		=83,
		MARKERB_WT_UC2		=173,
		MARKERB_WT_IC2		=174,
		MARKERB_WT_UD2		=175,
		MARKERB_WT_ID2		=176,

		MARKERB_WAVE_UA		=60,
		MARKERB_WAVE_IA		=61,
		MARKERB_WAVE_UB		=62,
		MARKERB_WAVE_IB		=63,
		MARKERB_WAVE_UC		=64,
		MARKERB_WAVE_IC		=65,
		MARKERB_WAVE_UD		=66,
		MARKERB_WAVE_ID		=67,
		MARKERB_WAVE_UA2	=68,
		MARKERB_WAVE_IA2	=69,
		MARKERB_WAVE_UB2	=70,
		MARKERB_WAVE_IB2	=71,
		MARKERB_WAVE_UC2	=169,
		MARKERB_WAVE_IC2	=170,
		MARKERB_WAVE_UD2	=171,
		MARKERB_WAVE_ID2	=172,
        DCBias1             =85,        //直流偏移(ua)百分比
        DCBias2             =86,        //ia
        DCBias3             =87,        //ub
        DCBias4             =88,        //ib
        DCBias5             =89,        //uc
        DCBias6             =90,        //ic
        DCBias7             =91,        //ud
        DCBias8             =92,        //id
        DCBias9             =93,        //ua1
        DCBias10             =94,       //ia1
        DCBias11             =95,       //ub1
        DCBias12             =96,       //ib1
        DCBias13             =97,       //uc1
        DCBias14             =98,       //ic1
        DCBias15             =99,       //ud1
        DCBias16             =100,      //id1
        TRIGE_TYPE          =84,
	};
    enum PAGE
    {
        MAIN,
        BASE_OUT,
        List_out,
        Config_set,
        STATE_LIST,
        ACTIVE_WAVE,
    };
    //网口部分
    typedef int (*ETHSENDTYPE)(char * , unsigned int);
    typedef int (*ETHRECVTYPE)(char * , unsigned int*);
    typedef int (*InitMemBuffTYPE)(void);
    typedef void (*GetallDevNameTYPE)(char **,char **, unsigned char &);
    typedef int (*SetDevTYPE)(char *, int );
    typedef void (*GetallDevNameTYPE_ex)(char *name,char *desc, int &nameSize,int &descSize);
    typedef int (*SetDevTYPE_ex)(char* , unsigned char [], unsigned char [],int);

	enum CH_MAP
	{//程序不要有顺序依赖
		OCM_UA,
		OCM_IA,
		OCM_UB,
		OCM_IB,
		OCM_UC,
		OCM_IC,
		OCM_UD,
		OCM_ID,
		OCM_UA2,
		OCM_IA2,
		OCM_UB2,
		OCM_IB2,
		OCM_UC2,
		OCM_IC2,
		OCM_UD2,
		OCM_ID2,
	};
	enum PHASE_ENUM
	{//统一的相定义标识，后面有新增的全部用该标识。sizeof(PHASE_ENUM) = 4;
		SP_NO = 0,
		SP_UA = (1 << OCM_UA),
		SP_IA = (1 << OCM_IA),
		SP_UB = (1 << OCM_UB),
		SP_IB = (1 << OCM_IB),
		SP_UC = (1 << OCM_UC),
		SP_IC = (1 << OCM_IC),
		SP_UD = (1 << OCM_UD),
		SP_ID = (1 << OCM_ID),
		SP_UA2 = (1 << OCM_UA2),
		SP_IA2 = (1 << OCM_IA2),
		SP_UB2 = (1 << OCM_UB2),
		SP_IB2 = (1 << OCM_IB2),
		SP_UC2 = (1 << OCM_UC2),
		SP_IC2 = (1 << OCM_IC2),
		SP_UD2 = (1 << OCM_UD2),
		SP_ID2 = (1 << OCM_ID2),

		SP_UIA = SP_UA | SP_IA,
		SP_UIB = SP_UB | SP_IB,
		SP_UIC = SP_UC | SP_IC,
		SP_UID = SP_UD | SP_ID,

        SP_UAC = SP_UA | SP_UC,
        SP_IAC = SP_IA | SP_IC,
        SP_UIAC = SP_UIA | SP_UIC,

		SP_UIA2 = SP_UA2 | SP_IA2,
		SP_UIB2 = SP_UB2 | SP_IB2,
		SP_UIC2 = SP_UC2 | SP_IC2,
		SP_UID2 = SP_UD2 | SP_ID2,

		SP_UABC = SP_UA | SP_UB | SP_UC,
		SP_UABCD = SP_UABC | SP_UD,

		SP_IABC = SP_IA | SP_IB | SP_IC,
		SP_IABCD = SP_IABC | SP_ID,

		SP_UIABC = SP_UABC | SP_IABC,
		SP_UIABCD = SP_UABCD | SP_IABCD,

		SP_UABC2 = SP_UA2 | SP_UB2 | SP_UC2,
		SP_UABCD2 = SP_UABC2 | SP_UD2,

		SP_IABC2 = SP_IA2 | SP_IB2 | SP_IC2,
		SP_IABCD2 = SP_IABC2 | SP_ID2,

		SP_UIABC2 = SP_UABC2 | SP_IABC2,
		SP_UIABCD2 = SP_UABCD2 | SP_IABCD2,

		SP_UABC12 = SP_UABC | SP_UABC2,
		SP_IABC12 = SP_IABC | SP_IABC2,

		SP_UABCD12 = SP_UABCD | SP_UABCD2,
		SP_IABCD12 = SP_IABCD | SP_IABCD2,

        SP_UIABCD12 = SP_UIABCD|SP_UIABCD2,
	};
    enum flag_enum
    {
        HIGH_WRITE_FLAG                  =1<<0,
        HIGH_READ_FLAG                   =1<<1,
        START_OUTPUT_FLAG                =1<<2,
        STOP_OUTPUT_FLAG                 =1<<3,
        HIGHT_HAR_WTITE_FLAG			 =1<<4,
        HIGHT_HAR_STARTUP_FLAG           =1<<5,
        HIGHT_HAR_STOP_FLAG              =1<<6,
        DCME_ERROR_STATE_FLAG            =1<<7,
        BASE_START_FLAG                  =HIGH_WRITE_FLAG | START_OUTPUT_FLAG,
    };
	typedef struct
	{//用一个U32来表示相的配置,16相
		quint32 UA:1;
		quint32 IA:1;
		quint32 UB:1;
		quint32 IB:1;
		quint32 UC:1;
		quint32 IC:1;
		quint32 UD:1;
		quint32 ID:1;
		quint32 UA2:1;
		quint32 IA2:1;
		quint32 UB2:1;
		quint32 IB2:1;
		quint32 UC2:1;
		quint32 IC2:1;
		quint32 UD2:1;
		quint32 ID2:1;
	}PHASE_U32;
	enum HAR_TIMES
	{
		HAR_T_DEF = 21,
		HAR_T_EXP = 128,
		HAR_T_EXP2 = 512,
	};
    typedef struct
    {
        PAGE sender;
        int index;
    }SENDER_MESG;
	typedef struct
	{
		float U;
		float I;
		float I1;
		float I2;
		float I3;
		float P;
		float Q;
		float S;
		float engy;
		quint32 cnt;
		float err1;
		float err2;
		float err3;
		float err4;
		quint32 pulse1;
		quint32 pulse2;
		quint32 pulse3;
		quint32 pulse4;
		quint32 autoU;
		quint32 autoI1;
		quint32 autoI2;
		quint32 autoI3;
	}DC_METER_V;

	typedef struct
	{
		quint32 standConst;
		quint32 meter1Const;
		quint32 meter2Const;
		quint32 meter3Const;
		quint32 meter4Const;
		quint32 meterTimes;
		quint32 avgT;
		quint32 swU;
		quint32 swI1;
		quint32 swI2;
		quint32 swI3;
		quint32 ichSel;
	}DC_METER_SET;

    typedef struct
    {
        float x;
        float y;
    }M_point;

	typedef struct
	{
		float UA;//单位V
		float UaAngle;//单位度
		float UB;//单位V
		float UbAngle;//单位度
		float UC;//单位V	
		float UcAngle;//单位度
		float IA;//单位A
		float IaAngle;//单位度
		float IB;//单位A
		float IbAngle;//单位度
		float IC;//单位A
		float IcAngle;//单位度
		float FAB;//单位Hz
		float FC;//单位Hz
	}AC_TYPE,*pAC_TYPE,**ppAC_TYPE;

	typedef struct
	{
		quint8 ua;
		quint8 ub;
		quint8 uc;
		quint8 ud;
		quint8 ia;
		quint8 ib;
		quint8 ic;
		quint8 id;
		quint8 ua2;
		quint8 ub2;
		quint8 uc2;
		quint8 ud2;
		quint8 ia2;
		quint8 ib2;
		quint8 ic2;
		quint8 id2;
	}AC_GEAR,*pAC_GEAR;

	typedef struct
	{
		float radio;			//含有率
		float phase;			//相位
	}PhaseOneHrDef,*pPhaseOneHrDef;

	enum
	{
		SOUR_PHASE_NUM = 6,
		SOUR_PHASE_NUM_MAX =16,
		HARMONIC_TIMES = 22,			//谐波次数22
		HIGHT_HAR_TIMES = 129,			//谐波次数129
		HIGHT2_HAR_TIMES = 513,			//谐波次数513
	};

    typedef struct
    {
        float power[DAC_CHNUM/2];	//每相功率	8
        float var[DAC_CHNUM/2];	//无功功率	8
        float Pall,Qall;			//总功率	2
        float pEnergy[DAC_CHNUM/2];	//分相电能	8
        float qEnergy[DAC_CHNUM/2];	//无功电能	8
        float pEnergyTotal;			//总电能累计	1
        float qEnergyTotal;			//总电能累计   1
        quint32 powerPulsNum[OUT_PULSENUM];	//电能脉冲累计数	2
        quint32 varPulsNum[OUT_PULSENUM];		//无功脉冲累计数	2
        float sErr[IN_PULSENUM];			//标准偏差值		3
        float energyErr[IN_PULSENUM];		//电能误差，如果脉冲输入口模式设置为时钟误差校验，则这个是电能表的时钟误差。
        float inputPower[IN_PULSENUM];	//脉冲输入的功率
        float inputEnergy[IN_PULSENUM];	//输入脉冲电能累计
        float inputPulseNum[IN_PULSENUM];	//输入脉冲数
    }POWER;

	typedef struct
	{
		float uaBaseWave;//基波分量,表示为百分比.如100表示100%
		QMap<quint16,float> uaTimesWave;//指向谐振波含有率的缓存，每个成员表示为百分比.如100表示100%

		float ubBaseWave;
		QMap<quint16,float> ubTimesWave;

		float ucBaseWave;
		QMap<quint16,float> ucTimesWave;

		float iaBaseWave;
		QMap<quint16,float> iaTimesWave;

		float ibBaseWave;
		QMap<quint16,float> ibTimesWave;

		float icBaseWave;
		QMap<quint16,float> icTimesWave;	

		float uaPhBaseWave;//基波相位
		QMap<quint16,float> uaPhTimesWave;//谐振波相位

		float ubPhBaseWave;
		QMap<quint16,float> ubPhTimesWave;

		float ucPhBaseWave;
		QMap<quint16,float> ucPhTimesWave;

		float iaPhBaseWave;
		QMap<quint16,float> iaPhTimesWave;

		float ibPhBaseWave;
		QMap<quint16,float> ibPhTimesWave;

		float icPhBaseWave;
		QMap<quint16,float> icPhTimesWave;
	}HARMONIC_DATA,*pHARMONIC_DATA;
	
	enum WAVE_TYPE_DEF
{
	WTD_SINE = 0,			//正弦波
	WTD_SQUARE = 1,			//方波
	WTD_TRIANGLE = 2,		//三角波
	WTD_DIRECT = 3,			//直流
	WTD_TRANSIENT = 4,		//暂态
	WTD_PLAYBACK = 5,		//录波回放
};
    typedef struct
    {
        quint32 constp;		//电能表有功脉冲常数
        quint32 constq;		//电能表无功脉冲常数
        quint32 checkNum;		//校验圈数
        quint32 checkType;		//脉冲输入校验类型: 		0:有功,-1:无功,1：谐波正向有功，2：谐波反向有功，3基波有功
        quint32 sAvergeNum; 		//S值计算次数 默认12
        quint32 sCalcuType;		//S值计算算法0：平均值法 （默认）
    }METER_PARA;
    typedef struct
    {
        long powerConstP;	//本机有功脉冲常数 默认36000000
        long powerConstQ;	//本机无功脉冲常数 默认36000000
        long pulsOutType;	//脉冲输出类型：-1:无功 0:有功，1谐波正向有功，2谐波反向有功，3基波有功
    }LOCAL_PARA;
    typedef struct
    {
        quint32 Constp;//电能表有功脉冲常数
        quint32 Constq;//电能表无功脉冲常数
        quint32 PowerConstP;//本机有功脉冲常数 固定36000000
        quint32 PowerConstQ;//本机无功脉冲常数 固定36000000
        quint32 CheckNum;//校验圈数
        quint32 CheckType;//校验类型: 0:无功 1:有功
        quint32 SAvergeNum; //S值计算次数 默认12
        quint32 CalType;//S值计算算法0：平均值法 （默认）
    }YM_PARR_TYPE;

    typedef struct
    {
        quint32 Index; //文件号
        char    Name[32]; //文件名  和写入的控制文件名称一致
    }FILE_LIST_TYPE;

    typedef struct
    {
        float Hz;//单位Hz
        float UA;//单位V
        float UB;//单位V
        float UC;//单位V
        float IA;//单位A
        float IB;//单位A
        float IC;//单位A
        float UaAngle;//单位度
        float UbAngle;//单位度
        float UcAngle;//单位度
        float IaAngle;//单位度
        float IbAngle;//单位度
        float IcAngle;//单位度
        quint32 UaHarmonicN;// UaHarmonicN=[2,99]
        float   UaHarmonicValue;// 谐波含量,不是谐波含有率 V
        quint32 UbHarmonicN;// UbHarmonicN=[2,99]
        float   UbHarmonicValue;// 谐波含量,不是谐波含有率 V
        quint32 UcHarmonicN;// UcHarmonicN=[2,99]
        float   UcHarmonicValue;// 谐波含量,不是谐波含有率 V
        quint32 IaHarmonicN;// IaHarmonicN=[2,99]
        float   IaHarmonicValue;// 谐波含量,不是谐波含有率 V
        quint32 IbHarmonicN;// IbHarmonicN=[2,99]
        float   IbHarmonicValue;// 谐波含量,不是谐波含有率 V
        quint32 IcHarmonicN;// IcHarmonicN=[2,99]
        float   IcHarmonicValue;// 谐波含量,不是谐波含有率 V
    }FILE_VALUE_TYPE;

    typedef struct
    {
        char Label[32];// 标签
        char  Help[32];// 帮助信息
        float Time;//单位 mS
        quint32 Key;//  按”Key”快捷键，跳到当前段
        quint32 EndKey;/*当 EndKey = 0时，代表无法提前退出。
                            程序一直运行到Time为的时间到，当EndKey=“A”,”B”,”C”,”D”,”ESC”中的任何一个键时。提前强制退出 */
        quint32  Go;//直接跳转到到的段
        FILE_VALUE_TYPE Value;//控制的输出值
    }FILE_SECTION_TYPE;

    typedef struct
    {
        char    Name[32]; //文件名  和写入的控制文件名称一致
        char  Ver[32];// 版本
        quint32 TotalSetion;// 总段数
        quint32 Control;// RS = 0 /IO=1/Panel=2;
    }FILE_CONTROL_TYPE;

    typedef struct
    {
        quint32    Num;//电能脉冲的累积个数
        float    Err; //计算的电能误差
        float    P;//有功功率值
        float    Q;//无功功率值
        float    Ep;//有功电能
        float    Eq; //无功电能
        float   SErr;//标准偏差值误差
    }YM_DATA_TYPE;

	class XL803Proto : public QObject
	{
		Q_OBJECT
	private:
		enum LINK_TYPE
		{
			LINK_NO,
			LINK_BY_COM,		//串口连接
			LINK_BY_PCAP,		//原始以太网连接
			LINK_BY_UDP,		//UDP连接
		};
		enum COMMAND_TYPE
		{
			NO_COMMAND					=0x00,		//不修改，用在重发时不设置
			HIGH_PRICISION_READ			=0x91,		//高精度读
			HIGH_PRICISION_WRITE		=0x92,		//高精度写
			STARTUP_OUTPUT				=0x03,		//源启动
			STOP_OUTPUT					=0x04,		//源停止
			HARMONIC_READ				=0x16,		//读谐波
			HARMONIC_WTITE				=0x17,		//写谐波
			HARMONIC_STARTUP			=0x18,		//谐波启动
			HARMONIC_STOP				=0x19,		//谐波停止
			HIGHT_HAR_READ				=0x26,		//超级谐波读
			HIGHT_HAR_WTITE				=0x27,		//超级写谐波
            HIGHT_HAR_STARTUP			=0x28,		//超级谐波启动
            HIGHT_HAR_STOP				=0x29,		//超级谐波停止
			RIGHT_RESPON				=0x10,		//正确应答
			ERROR_RESPON				=0x80,		//错误应答
			ERROR_EVENT					=0x05,		//告警事件


            READ_CONTROL_FILE_LIST      =0x61,      //读取控制文件列表
            WRITE_CONTROL_FILE          =0x62,      //写入控制文件
            READ_CONTROL_FILE           =0x63,      //读取控制文件
            CHANGE_CONTROL_MODEL        =0x64,      //切换控制模式
            WRITE_KEY                   =0x65,      //写入控制值
            READ_NOW_FILE_NUMBER        =0X67,      //读取当前文件号
            SET_NOW_FILE_NUMBER         =0X68,      //设置当前文件号
            REMOVE_CONTROL_FILE         =0X69,      //格式化控制文件

			HARMONIC_WTITE_EXP				=0x27,		//写谐波
			HARMONIC_STARTUP_EXP			=0x28,		//谐波启动
			HARMONIC_STOP_EXP				=0x29,		//谐波停止
			HARMONIC_WTITE_EXP2				=0x37,		//写谐波
			HARMONIC_STARTUP_EXP2			=0x38,		//谐波启动
			HARMONIC_STOP_EXP2				=0x39,		//谐波停止

            ONE_HARMONIC_WTITE              =0x40,      //单相谐波写 129次

            DCME_ERROR_STATE				=0x85,		//直流标准表，读取误差
            CHECK_STATE                     =0x87,      //检测电能有效状态
            CLEAR_STATE                     =0x8C,      //清除电能有效状态
            READ_METER_CONST				=0x82,      //读取电能表常数
            SET_LOCAL_CONST                 =0x83,      //设置本机电能表参数
            READ_LOCAL_CONST                =0x84,      //读取本机电能表参数
            SET_METER_CONST                 =0x81,      //电能校验
            ENERGY_CHECK_READ               =0x55,      //读
            ENERGY_CHECK_WRITE              =0xAA,      //写
            SYNC_START                      =0x09,      //
            STEP_ADD                        =0x97,      //幅度增量控制

            SET_CHECK_NUM                   =0x8A,      //设置校验圈数
            CLEAR_ENERGY                    =0x88,      //电能清零
            SET_ENERGY_PIPE                 =0x45,      //设置电流通道
            SET_METET_RATIO                 =0x46,      //设置变比
            GET_METET_RATIO                 =0x47,      //设置变比
            SET_COMPENSATION_FACTOR         =0x48,      //设置补偿系数

            SET_PLUS_TYPE                   =0x89,      //设置脉冲口模式
            TEST_CONNECT                    =0x14,

            DOWN_SIMPDATA_START			=0xB0,		//开始波形数据下载
            DOWN_SIMPDATA				=0xB1,		//波形数据下载
            DOWN_SIMPDATA_STOP			=0xB2,		//波形数据下载结束
            DMA_OUT_FREQ				=0xB3,		//DMA输出频率
            DOWN_DATA_OUTPOUT_START		=0xB4,		//自定义波形启动
            DOWN_DATA_OUTPOUT_STOP		=0xB5,		//自定义波形停止
            DOWN_DATA_SAVE				=0xB6,		//保存波形到Flash

            WAVE_REOUT_START            =0xB8,      //录波回放的启动
            READ_REOUT_MAX_LENTH        =0xB9,      //读取录波波形缓存长度
            WAVE_REOUT_READ             =0xBa,      //录波回放波形准备完成

            ADJUST_START                =0xA0,      //开始校准
            READ_ADJUST_NUM             =0xA1,      //读校准系数
            WRITE_ADJUST_NUM            =0xA2,      //写校准系数
            ADJUST_END                  =0xA3,      //结束校准
            INIT_STD_NUM_LIST           =0xA4,      //初始化校准系数表
            READ_ADJUST_OLD_VALUE       =0xA5,      //读校准原始值
            READ_ADJUST_STD_VALUE       =0xA6,      //读校准标准值
            READ_STD_NUM_VALUE          =0xA7,      //读标准系数值
            UNENABLE_STD_NUM            =0xA8,      //禁用标准系数
            ENABLE_STD_NUM              =0xA9,      //启用标准系数

            WRITE_FREQ_CONTROL_DATA     =0x7A,      //写入频率控制数据
            START_FREQ_CONTROL          =0x7B,      //启动频率控制
            FREQ_CONTROL_OUT_END        =0x7C,      //频率控制输出结束

            WRITE_OUT_LIST              =0x71,      //写入输出序列
            READ_OUT_LIST               =0x72,      //读取输出序列
            WRITE_END_LIST              =0x73,      //写入结束 另一版本0x73 0x79
            START_STOP_OUT_LIST         =0x74,      //启动停止输出序列
            CLEAR_OUT_LIST              =0x78,      //启动停止输出序列

            CONSTRAINT_WAVE_SET         =0xF0,      //强制波形拟合

             READ_ALL_SET                =0xC0,      //读取配置

            INIT_CPU                    =0xF5,
		};
		enum LABEL_ENUM
		{
			START_CHAR		=0x68,		//起始字符
			STOP_CHAR		=0x16,		//结束字符
			DEVICE_NUM		=0x00,		//设备地址
			HOST_NUM		=0x80,		//主机地址
		};
		enum INDEX_ENUM
		{
			IND_START		= 0,
			IND_LEN			= 1,
			IND_START2		= 3,
			IND_ADDR		= 4,
			IND_CODE		= 5,
			IND_DATA		= 6,
		};
		enum
		{
			MIN_FRAME_SIZE	=	8,		//最小帧长度
			PCAP_PACK_MAX_LEN = 1400,
		};

		#pragma pack(1)		
		typedef struct
		{
			quint8 descMac[6];
			quint8 sourMac[6];
			quint16 netType;
			quint16 packCount;		//帧数量
			quint16 packInd;		//帧索引
			quint32 dataLen;		//数据域长度
			quint8 data[PCAP_PACK_MAX_LEN];
		}PcapPackType,*pPcapPackType;
		#pragma pack()

		typedef struct
		{
			quint16 UaRadio[HIGHT_HAR_TIMES];
			quint16 UbRadio[HIGHT_HAR_TIMES];
			quint16 UcRadio[HIGHT_HAR_TIMES];
			quint16 IaRadio[HIGHT_HAR_TIMES];
			quint16 IbRadio[HIGHT_HAR_TIMES];
			quint16 IcRadio[HIGHT_HAR_TIMES];
			quint16 UaPhase[HIGHT_HAR_TIMES];
			quint16 UbPhase[HIGHT_HAR_TIMES];
			quint16 UcPhase[HIGHT_HAR_TIMES];
			quint16 IaPhase[HIGHT_HAR_TIMES];
			quint16 IbPhase[HIGHT_HAR_TIMES];
			quint16 IcPhase[HIGHT_HAR_TIMES];
		}ProtoHrHightWriteDef,*pProtoHrHightWriteDef;
        typedef struct
        {
            float Radio[HIGHT_HAR_TIMES];
            float Phase[HIGHT_HAR_TIMES];
        }ProtoHrHightWriteDefOne,*pProtoHrHightWriteDefOne;
	private://单例
		XL803Proto(QObject *parent = 0);
		~XL803Proto();

	public:
		static XL803Proto* getXl803(quint8 ind = 0,QObject *parent = 0);

		bool waitPack(COMMAND_TYPE right = RIGHT_RESPON,COMMAND_TYPE error = ERROR_RESPON,quint32 waitMs = 2000,quint8 reSendTimes = 3);
		//测试通信连接端是否正确，靠发命令测试
		bool testLink();

		void setGear(QList<double> &vol,QList<double> &cur,bool volAutoGear = true,bool curAutoGear = true);
		//当前档位
		quint32 currGear(CH_MAP ch);

		void setLimit(double volMax,double curMax);
	public slots:
        void readFromPort(const QByteArray &rb, const QByteArray &wB, XL803::PAGE page);
	signals:
        void send_to_main(const QByteArray &last,const QByteArray &now);
        void send_to_base_out(const QByteArray &last,const QByteArray &now);
        void send_to_config(const QByteArray &last,const QByteArray &now);
        void send_to_list_out(const QByteArray &last,const QByteArray &now);
        void send_to_state_out(const QByteArray &last,const QByteArray &now);
        void send_to_active_wave(const QByteArray &last,const QByteArray &now);

        void sendToPort(const QByteArray &bb,quint32 waitTimes ,XL803::PAGE page);
        void send_file_list(const QByteArray );
        void send_file(const QByteArray );
        void send_update_mesg(const QByteArray);
        void write_to_memter(const QByteArray &bb);
		//附录B数据变化信号
		void HighValueChanged(QMap<MARKERB,qint32> &v);
	public://与协议文本对应，用于单路同步等待应答 
        int last_contorl;//0基波1动态波2状态序列
        bool COM_HightWrite(const QMap<MARKERB,qint32> &para,PAGE page);
        bool COM_HightRead(QMap<MARKERB,qint32> &para,PAGE page);
        bool COM_HightRead(QVector<MARKERB> &keys,QVector<qint32> &value,PAGE page);
        bool COM_StartUp(const QMap<MARKERB,qint32> &para,PAGE page);
        bool COM_Stop(const QMap<MARKERB,qint32> &para,PAGE page);
        bool COM_WriteHarmonic(HAR_TIMES max,const HARMONIC_DATA &para,PAGE page);
        //单相写谐波
        bool write_one_harmonic(quint8 pipe, PhaseOneHrDef data[], PAGE page);
		//写谐波,data[6][hrCount]数组,hrCount 必需小于maxTimes，SOUR_PHASE_NUM的顺序与OUT_CH_MAP一致
        bool COM_WriteHarmonic(PhaseOneHrDef data[SOUR_PHASE_NUM][HIGHT_HAR_TIMES],PAGE page);
		//谐波启动
        bool COM_HarmonicStartup(PHASE_ENUM phase,quint32 ,PAGE page);
		//谐波停止
        bool COM_HarmonicStop(PHASE_ENUM phase,PAGE page);

        //同步启动
        bool COM_sync_start(const AC_TYPE &ac,PHASE_ENUM phase,PAGE page);
        bool test_connet(PAGE page);
        //电能校验
        bool COM_energy_check(int flag,PAGE page);
        bool COM_energy_check_state(int flag,PAGE page);
        void set_config(YM_PARR_TYPE *parr,PAGE page);
        bool COM_step_output(quint8 a, float b,PAGE page);
        bool check_state(quint8 type,PAGE page);//检测可读
        bool clear_state(quint8 type1, quint8 type2, quint8 type3, PAGE page);//清除可读
        //609电能校验
        bool clear_energy(quint8 flag,PAGE page); //清空电能累计值
        bool set_energy_pipe(quint8 flag,PAGE page);//设置电流通道
        bool set_compensation_factor(float pipe[],PAGE page);//设置补偿系数
        bool read_meter_const(quint8 flag,PAGE page);//读取表常数
        bool set_meter_const(const QByteArray re, quint8 type, PAGE page);//设置表常数
        bool read_local_const(PAGE page);
        bool set_local_const(const QByteArray re, PAGE page);
        //609脉冲检验
        bool set_plus_type(quint8 pipe[],PAGE page);
        bool read_plus(PAGE page);
        bool set_meter_ratio(float ratio[],PAGE page);
        bool read_meter_ratio(PAGE page);
        //电表校验
        void  read_addr(PAGE page);
        void  read_meter(int type);
        //序列控制
        bool read_control_file_list(PAGE page);
        bool read_control_file(quint8,PAGE page);
        bool read_now_file_number(PAGE page);
        bool write_control_file(const QByteArray re,PAGE page);
        bool write_key(quint16 key,PAGE page);
        bool change_control_model(quint8 type,PAGE page);
        bool set_now_file_number(quint8 file_number,PAGE page);
        bool remove_control_file(quint8 file_number,PAGE page);
        bool set_check_num(quint32 num,PAGE page);
        bool clear_out_list(PAGE page);

        //波形控制部分
        bool start_down_simpdata(quint32 data_count,quint32 byte_freq,quint32 lenth,quint8 pipe,quint8 type,PAGE page);
        bool down_simpdata(quint16 index,QByteArray data,quint8 check_num,PAGE page);
        bool stop_down_simpdata(PAGE page);
        bool get_dma_freq(PAGE page);
        bool output_simpdata_start(quint8 mode,QByteArray data,PAGE page);
        bool output_simpdata_stop(QByteArray data, PAGE page);
        //录波部分
        bool start_reout_wave(quint8 count, QByteArray data, PAGE page);
        bool read_max_reout_wave_lenth(PAGE page);
        //校准部分
        bool start_adjust(PAGE page);
        bool read_adjust_num(quint8 pipe, quint8 lv, quint8 type, PAGE page);
        bool write_adjust_num(quint8 pipe, quint8 lv, quint8 type, QByteArray data, PAGE page);
        bool stop_adjust(PAGE page);
        bool init_std_num_list(PAGE page);
        bool read_adjust_old_value(quint8 pipe, quint8 lv, quint8 type, PAGE page);
        bool read_adjust_std_value(quint8 pipe,quint8 lv,quint8 type,PAGE page);
        bool read_std_num_value(quint8 pipe, quint8 lv, quint8 type, PAGE page);
        bool unenable_std_num(PAGE page);
        bool enable_std_num(PAGE page);
        //频率控制
        bool write_freq_control_data(long lenth,long index,QByteArray data,PAGE page);
        bool start_freq_control(PAGE page);
        //状态序列
        bool write_out_list(unsigned int lenth, QByteArray arry, PAGE page);
        bool read_out_list(int index, PAGE page);
        bool write_end_list(PAGE page);
        bool start_stop_out_list(QByteArray arry, PAGE page);

        bool read_all_set(PAGE page);
        //强制波形拟合
        bool constraint_set_wave(PAGE page);

        bool reset_cpu(PAGE page);
    public:////用于扩展协议文本，方便调用
        bool EX_startACOutPut(const AC_TYPE &ac,PHASE_ENUM phase,PAGE page);
        bool EX_stopACOutPut(PHASE_ENUM phase,PAGE page);
        bool EX_writeHrOutput(const AC_TYPE &ac, PhaseOneHrDef data[SOUR_PHASE_NUM][HIGHT_HAR_TIMES], PHASE_ENUM phase ,PAGE page);
    public://与协议文本对应，用于解sendPack析应答
        bool unpackHightRead(const QByteArray &rb,QMap<MARKERB,qint32> &para);
        bool unpackHightRead(QVector<MARKERB> &keys,QVector<qint32> &value);
	private:
        bool sendPack(COMMAND_TYPE code, quint32 waitMs , PAGE page);
		quint8 checkSum(quint8 *frame,quint16 frameSize);
		quint32 volGearSel(double value);
		quint32 curGearSel(double value);

		quint8 gearSel(const QList<double> &lst,double value);

		double getMin(double v1,double v2,bool &li)
		{
			if(v1 > v2)
			{
				li = true;
				return v2;
			}
			return v1;
		}
		void acToLimit(AC_TYPE &ac);
		bool readFile(bool emitErr = true,quint32 waitMs = 5000);
		bool checkPack(COMMAND_TYPE right,bool emitErr = false);
		bool checkEnd();
	public://铺助函数

        char ConvertHexChar(char ch);
        void StringToHex(QString str, QByteArray &senddata);
        quint8 getCalculatorValue(char *f,double &value);
        quint32 float_to_quint(float data);
        float quint_to_float(quint32 data);
        QString float_to_str(double data,int len=4);
        void  set_map(CustomPlotHasRoll *map);
        //插值，dataIn输入数据，inSize输入数据点数，simpIn输入数据采样率，simpOut需要输出的采样率，outSize输出的采样数据点数，maxValue采样点最大值。
        quint8 SIE_reGetData(float *dataIn,quint32 inSize,quint32 simpIn,float *dataOut,quint32 &outSize,quint32 simpOut,float &maxValue);
        //贝塞尔插值算法
        void createCurve(QVector<M_point> &originPoint,int originCount,QVector<M_point> &curvePoint);
        //正弦插值
        void sin_insert(QVector<M_point> in_point, QVector<M_point> &out_point, int point_num, double len=0.02);
        float bezier3funcX(float uu,QVector<M_point> &controlP);
        float bezier3funcY(float uu,QVector<M_point> &controlP);
        inline static void phaseSet(PHASE_ENUM &x,PHASE_ENUM y)
		{
			x = PHASE_ENUM(x | y);
		}
		inline static void phaseClr(PHASE_ENUM &x,PHASE_ENUM y)
		{
			x = PHASE_ENUM(x &(~y));
		}
		inline static bool phaseIsSet(PHASE_ENUM &x,PHASE_ENUM y)
		{
			return (x & y);
		}
		inline static void phaseSetB(PHASE_ENUM &x,CH_MAP b)
		{
			x = PHASE_ENUM(x | (1 << b));
		}
		inline static void phaseClrB(PHASE_ENUM &x,CH_MAP b)
		{
			x = PHASE_ENUM(x & ~(1 << b));
		}
		inline static bool phaseIsSetB(PHASE_ENUM x,CH_MAP b)
		{
			return (x & (1 << b));
		}
		inline static PHASE_ENUM phaseAnd(PHASE_ENUM x,PHASE_ENUM y)
		{
			return PHASE_ENUM(x & y);
		}
		//构造相
		inline static PHASE_ENUM phaseGet(bool ua = false,bool ub = false,bool uc = false,bool ia = false,bool ib = false,bool ic = false)
		{
			PHASE_ENUM phase = SP_NO;
			if(ua)
				phaseSet(phase,SP_UA);
			if(ub)
				phaseSet(phase,SP_UB);
			if(uc)
				phaseSet(phase,SP_UC);
			if(ia)
				phaseSet(phase,SP_IA);
			if(ib)
				phaseSet(phase,SP_IB);
			if(ic)
				phaseSet(phase,SP_IC);
			return phase;
		}
		//根据all取反
		inline static PHASE_ENUM phaseNo(PHASE_ENUM phase,PHASE_ENUM all = SP_UIABC)
		{
			return PHASE_ENUM(phase ^ all);
		}
		inline static PHASE_U32 EnumToU32(PHASE_ENUM ph)
		{
			return *(PHASE_U32*)&ph;
		}
		inline static PHASE_ENUM U32ToEnum(PHASE_U32 ph)
		{
			return *(PHASE_ENUM*)&ph;
		}

		inline static qint32 HighFloat(float f)
		{
			return (qint32&)f;
		}
		inline static quint16 netHostChangeS(quint16 netshort)
		{
			quint16 retValue;

			*((quint8*)&retValue) = *(((quint8*)&netshort)+1);
			*(((quint8*)&retValue)+1) = *((quint8*)&netshort);
			return retValue;
		}
		QString HexToStr(quint8 *buf,quint32 size)
		{
			QString str;
			QStringList strLst;
			for(int i = 0; i < size; i ++)
			{
				strLst.append(QString("%1").arg(buf[i],2,16,QLatin1Char('0')));
			}
			return strLst.join(" ");
		}
		MARKERB waveMarkB(CH_MAP ph);
        AC_TYPE get_ac();
        void set_ac(float u, float i, int line, int order);
        void set_ac(const AC_TYPE &ac);
	private:
		quint32 sendBufSize;
		quint32 recvBufSize;
		quint8 *recvBuf;
		quint8 *sendBuf;
		quint32 sendIndex;
		quint32 recvIndex;

		static XL803Proto* m_pXl803[MAX_803_DEV];
		LINK_TYPE m_linkType;

		void *adhandle;
		pPcapPackType m_pcapPack;
	private:
		quint8 *mr_start;
		quint16 *mr_len;
		quint8 *mr_start2;
		quint8 *mr_addr;
		quint8 *mr_code;
		quint8 *mr_data;
		quint8 *mr_crc;
		quint8 *mr_end;
		quint16 mr_dSize;		//数据域大小

		quint8 *ms_start;
		quint16 *ms_len;
		quint8 *ms_start2;
		quint8 *ms_addr;
		quint8 *ms_code;
		quint8 *ms_data;
		quint8 *ms_crc;
		quint8 *ms_end;
		quint16 ms_dSize;		//数据域大小

        quint8 * meter_addr;
        AC_TYPE m_ac;
        PHASE_ENUM m_able;
		QList<double> m_volGears;
		QList<double> m_curGears;
		bool m_volAutoGear;
		bool m_curAutoGear;

		AC_GEAR m_currGear;

		double m_volMax;
		double m_curMax;
        float  step_value;
        YM_PARR_TYPE * m_parr[8];
        YM_DATA_TYPE * m_data[8];
        quint8 energy_flag;

signals:
		void dataSend(QString d);
		void dataRecv(QString d);
		void isError(QString str);
        void energy_state(quint8);
        void set_err_data(QByteArray);
        void send_meter_data(QByteArray);
        void start_ac(XL803::PHASE_ENUM able);
        void stopAc(XL803::PHASE_ENUM able);
        void send_ac(const XL803::AC_TYPE &ac);
        void step_signal();
        void send_step_value(float);
	};
}
#define L_XL803 XL803::XL803Proto::getXl803(0,this)
#define L_XL803s(a)  XL803::XL803Proto::getXl803(a,this)

#endif // XL803PROTO_H
