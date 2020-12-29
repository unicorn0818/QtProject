#include "net_connect.h"
net_connect *net_connect::net=NULL;

read_net::read_net(QObject *parent)
{
    recv_buff=(char * )malloc(0xFFFF+8);
    lenth=0;
    timer=new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(read_data()));
}
void read_net::read_data()
{
    QByteArray data;
    lenth=0;
    P_NET->EthRecv(recv_buff,&lenth);
    data.clear();
    data.resize(lenth);
    memcpy(data.data(),recv_buff,lenth);
    if(lenth>0)
    {
        if((quint8)data.at(5)==0x05)
        {
            emit send_error(data);
        }else
        {
            emit ready_read(data,lenth);
        }
    }
}
void read_net::start_read(int i)
{
    timer->start(i);
}
net_connect::net_connect(QObject *parent, int num)
{
    QLibrary my_lib("./Comm801Dll.dll");
    InitMemBuff=(XL803::InitMemBuffTYPE)my_lib.resolve("InitMemBuff");
    GetallDevName=(XL803::GetallDevNameTYPE)my_lib.resolve("GetallDevName");
    GetallDevName_ex=(XL803::GetallDevNameTYPE_ex)my_lib.resolve("GetallDevName_ex");
    EthSend=(XL803::ETHSENDTYPE)my_lib.resolve("EthSend");
    EthRecv=(XL803::ETHRECVTYPE)my_lib.resolve("EthRecv");
    SetDev=(XL803::SetDevTYPE)my_lib.resolve("SetDev");
    SetDev_ex=(XL803::SetDevTYPE_ex)my_lib.resolve("SetDev_ex");
    if(my_lib.isLoaded()==false)
    {
        QMessageBox::information(NULL,"提示","网络模块加载失败！");
    }
    update_mesg(num);
    InitMemBuff();
    m_thread=new QThread(this);
    p_read=new read_net(this);
    p_read->moveToThread(m_thread);
    m_out_timer=new QTimer(0);
    m_out_timer->moveToThread(this->thread());
    m_out_timer->setSingleShot(true);
    connect(m_out_timer,SIGNAL(timeout()),this,SLOT(timer_out()));
    connect(p_read,SIGNAL(ready_read(QByteArray,int)),this,SLOT(portrecv(QByteArray,int)));
    connect(p_read,SIGNAL(send_error(QByteArray)),this,SLOT(recv_err(QByteArray)));
}
void net_connect::timer_out()
{
    emit recv_time_out();
}
net_connect *net_connect::get_connect(QObject *parent,int num)
{
    if(net==NULL)
    {
        net=new net_connect(parent,num);
    }
    return net;
}

void net_connect::update_mesg(int num)
{
    char** m_name;
    char** m_desc;
    unsigned char uDevNum = num;//本机可能拥有的最大网卡设备数；

    m_name = (char **) malloc ( uDevNum * sizeof(char *) );
    m_desc = (char **) malloc ( uDevNum * sizeof(char *) );
    for(int j = 0; j < uDevNum; j++)
    {
        m_name[j] = (char *) malloc ( 64 * sizeof(char) );
        m_desc[j] = (char *) malloc ( 64 * sizeof(char) );
    }
    GetallDevName(m_name,m_desc,uDevNum);
    QString item;
    for(int j = 0; j < uDevNum; j++)
    {
        item=QString(m_name[j]);
        if(item.length()>0)
        {
            name<<item;
        }
        item=QString(m_desc[j]);
        if(item.length()>0)
        {
            desc<<item;
        }
    }
}


void net_connect::update_mesg_mac()
{
    QList<QNetworkInterface> interfaceList = QNetworkInterface::allInterfaces();

    foreach(QNetworkInterface interfaceItem, interfaceList)
    {
        if(interfaceItem.flags().testFlag(QNetworkInterface::IsUp)
                &&interfaceItem.flags().testFlag(QNetworkInterface::IsRunning)
                &&!interfaceItem.flags().testFlag(QNetworkInterface::IsLoopBack))
        {
            QList<QNetworkAddressEntry> addressEntryList=interfaceItem.addressEntries();
            foreach(QNetworkAddressEntry addressEntryItem, addressEntryList)
            {
                if(addressEntryItem.ip().protocol()==QAbstractSocket::IPv4Protocol)
                {
                    qDebug()<<"------------------------------------------------------------";
                    qDebug()<<"Adapter Name:"<<interfaceItem.name();
                    qDebug()<<"Adapter Address:"<<interfaceItem.hardwareAddress();
                }
            }
        }
    }

}
QVector <QString> net_connect::get_name()
{
    return name;
}
QVector <QString> net_connect::get_desc()
{
    return desc;
}
void net_connect::portWrite(const QByteArray & b, quint32 waitTimes, XL803::PAGE page)
{
    WriteListType t;
    t.bb = b;
    t.waitTs = waitTimes;
    t.page= page;
   // mutex.lock();
    m_writeList.append(t);
   // mutex.unlock();
    //qDebug() << QTime::currentTime().toString("hh:mm:ss.zzz") << " write:" << HexToStr(b);
    if(m_writeList.count() == 1)
    {//只有一个时就自己发
        t=m_writeList.first();
        EthSend(t.bb.data(),t.bb.length());
        m_out_timer->start(Config_set::out_time_value*1000);
        qDebug() << QTime::currentTime().toString("hh:mm:ss.zzz") << " write:" << HexToStr(m_writeList.first().bb);
        if(t.waitTs == 0)
            m_writeList.removeFirst();
    }
}
void net_connect::portrecv(QByteArray b,int lenth)
{
    //mutex.lock();
    WriteListType data;
    if((quint8)b[5]==0x7C)
    {
        emit portReaded(b,b,XL803::List_out);
        qDebug() << QTime::currentTime().toString("hh:mm:ss.zzz") << " read:" << HexToStr(b);
    }else
    {
        if(!m_writeList.isEmpty())
        {
            data=m_writeList.takeFirst();
            emit portReaded(b,data.bb,data.page);
            qDebug() << QTime::currentTime().toString("hh:mm:ss.zzz") << " read:" << HexToStr(b);
            m_out_timer->stop();
        }
    }
    if(!m_writeList.isEmpty())
    {//还有在排队的
        WriteListType &wt = m_writeList.first();
        EthSend(wt.bb.data(),wt.bb.length());
        m_out_timer->start(Config_set::out_time_value*1000);
        qDebug() << QTime::currentTime().toString("hh:mm:ss.zzz") << " write:" << HexToStr(wt.bb);
        if(wt.waitTs == 0)
        {
            qDebug()<<"111111111111111";
            m_writeList.removeFirst();
        }
    }
   // mutex.unlock();
}
void net_connect::start_read()
{
    m_thread->start();
    p_read->start_read(20);
}
void net_connect::stop_read()
{
    m_thread->exit();
}
void net_connect::recv_err(QByteArray err)
{
    emit send_error(err);
}
void net_connect::clear_list()
{
    m_writeList.clear();
}
