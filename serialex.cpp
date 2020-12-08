#include "serialex.h"
#include "qdebug.h"
#include <QTime>

//还是要再加上考虑线程同步执行，待解决。
//最完美的做法是同时引出一个同步执行的曹，并且连接时使用阻塞式连接，调用该曹时忘记写读完成再结束

SerialEx::SerialEx(QObject *parent)
	: QSerialPort(parent)
{
	m_pReadTimer = 0;
	m_pReadSendTimer = 0;
    all_size=0;
	m_LstEmpty = true;
}

SerialEx::~SerialEx()
{
	if(m_pReadTimer)
		delete m_pReadTimer;
	if(m_pReadSendTimer)
		delete m_pReadSendTimer;
}
//连接串口
void SerialEx::linkToCom(bool sel)
{
	if(sel)
	{
		if(!m_pReadTimer)
		{
			m_pReadTimer = new QTimer(0);
			m_pReadTimer->moveToThread(this->thread());
			m_pReadTimer->setInterval(30);
			m_pReadTimer->setSingleShot(true);			//单次
			connect(m_pReadTimer,SIGNAL(timeout()),this,SLOT(readTimerOut()));

			m_pReadSendTimer = new QTimer(0);
			m_pReadSendTimer->moveToThread(this->thread());
			m_pReadSendTimer->setSingleShot(true);		//单次
			connect(m_pReadSendTimer,SIGNAL(timeout()),this,SLOT(readSendTimerOut()));

			connect(this,SIGNAL(readyRead()),SLOT(onReadyRead()));

            m_out_timer=new QTimer(0);
            m_out_timer->moveToThread(this->thread());
            m_out_timer->setSingleShot(true);
            connect(m_out_timer,SIGNAL(timeout()),this,SLOT(timer_out()));
		}
		if(isOpen())
            close();

		if(!open(QIODevice::ReadWrite))
		{
            // qDebug()<< errorString();
			return ;
		}else
		{
            setRequestToSend(true);             //设置 RTS 为高电平
            setDataTerminalReady(true);         //设置 DTR 为高电平
		}
		emit portConnected();
	}else
	{
		if(isOpen())
			close();
	}
}
void SerialEx::timer_out()
{
    emit recv_time_out();
}
void SerialEx::portWrite(const QByteArray &b, quint32 waitTimes, XL803::PAGE page)
{
	if(isOpen())
	{
		WriteListType t;
		t.bb = b;
		t.waitTs = waitTimes;
        t.page= page;
		m_writeList.append(t);
		m_LstEmpty = false;
        //qDebug() << QTime::currentTime().toString("hh:mm:ss.zzz") << " write:" << HexToStr(b);
        if(m_writeList.count() == 1)
		{//只有一个时就自己发
			WriteListType &wt = m_writeList.first();
            writeData(wt.bb.data(),wt.bb.length());
            //qDebug()<<"定时器已启动";
            m_out_timer->start(5*1000);
            qDebug() << QTime::currentTime().toString("hh:mm:ss.zzz") << " write:" << HexToStr(wt.bb);
			if(wt.waitTs == 0)
				m_writeList.removeFirst();
			else
			{
				m_pReadSendTimer->start(wt.waitTs);
			}
        }
	}
}
void SerialEx::portWrite(const QByteArray &b, XL803::PAGE page)
{
    portWrite(b,0,page);
}
void SerialEx::readTimerOut()
{
    int flag=0;
    int size=bytesAvailable();
    int send_flag=0;
    if(all_size==0)
    {
        if(size>3)
        {
            lenth=read(3);
            all_size=(quint8)lenth[1]+(quint8)lenth[2]*256;
            if(all_size>size)
            {
                return;
            }else
            {
                flag=1;
            }
        }else
        {
            return;
        }
    }
    if(size<all_size-3&&flag==0)
    {
        return;
    }
    lenth.resize(all_size);
    memset(lenth.data()+3,0,all_size-3);
    memcpy(lenth.data()+3,read(all_size-3).data(),all_size-3);
    if((quint8)lenth[5]==0xBA)
    {
        emit portReaded(lenth,lenth,XL803::REOUT_WAVE);
    }else if((quint8)lenth[5]==0xFB)
    {
        emit portReaded(lenth,lenth,XL803::Power_test);
    }else if((quint8)lenth[5]!=0x05)
    {
        if(!m_writeList.isEmpty())
        {
            data=m_writeList.takeFirst();
            m_out_timer->stop();
            emit portReaded(lenth,data.bb,data.page);
            send_flag=1;
        }
    }else
    {
        emit send_error(lenth);
    }
    qDebug() << QTime::currentTime().toString("hh:mm:ss.zzz") << " read:" << HexToStr(lenth);
    all_size=0;
    lenth.clear();

    if(!m_writeList.isEmpty()&&send_flag==1)
    {//还有在排队的
        WriteListType &wt = m_writeList.first();
        write(wt.bb);
        qDebug() << QTime::currentTime().toString("hh:mm:ss.zzz") << " write:" << HexToStr(wt.bb);
        if(wt.waitTs == 0)
            m_writeList.removeFirst();
        else
        {
            m_pReadSendTimer->start(wt.waitTs);
        }
    }else
    {
        m_LstEmpty = true;
    }
    all_size=0;
    lenth.clear();
    if(bytesAvailable()>0)
    {
        readTimerOut();
    }
}
void SerialEx::readSendTimerOut()
{
	//暂时不考虑重发机制
	//readTimerOut();
}
void SerialEx::onReadyRead()
{
    if(m_pReadTimer->isActive())
        m_pReadTimer->stop();

    m_pReadTimer->start();
}
void SerialEx::clear_list()
{
    m_writeList.clear();
}
void SerialEx::m_close()
{
    close();
}
