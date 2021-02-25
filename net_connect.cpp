#include "net_connect.h"
net_connect *net_connect::net=NULL;

read_net::read_net(QObject *parent)
{
    recv_buff=(char * )malloc(0xFFFF+8);
    lenth=0;
    timer=new QTimer();
    //connect(timer, SIGNAL(timeout()), this, SLOT(read_data()));
    read_flag=true;
}
void read_net::read_data()
{
    QByteArray now_data;
    QByteArray send_data;
    int all_size=0;
    while (read_flag) {
        QByteArray data;
        lenth=0;
        EthRecv(recv_buff,&lenth);
        data.clear();
        data.resize(lenth);
        memcpy(data.data(),recv_buff,lenth);
        //emit ready_read(recv_buff,lenth);
        if(lenth>0)
        {
            now_data.append(data);
            if(now_data.length()>3)
            {
                all_size=(quint8)now_data[1]+(quint8)now_data[2]*256;
                if(now_data.length()>=all_size)
                {
                    send_data=now_data.mid(0,all_size);
                    now_data.remove(0,all_size);
                    if((quint8)send_data.at(5)==0x05)
                    {
                        emit send_error(send_data);
                    }else
                    {
                        emit ready_read(send_data,all_size);
                    }
                }else
                {
                    continue;
                }
            }else
            {
                continue;
            }
        }
    }
}
void read_net::start_read()
{
    read_flag=true;
    read_data();
}
void read_net::stop_read()
{
    read_flag=false;
}
net_connect::net_connect(QObject *parent, int num)
{
//    QLibrary my_lib("Comm801Dll.dll");
//    InitMemBuff=(XL803::InitMemBuffTYPE)my_lib.resolve("InitMemBuff");
//    GetallDevName=(XL803::GetallDevNameTYPE)my_lib.resolve("GetallDevName");
//    GetallDevName_ex=(XL803::GetallDevNameTYPE_ex)my_lib.resolve("GetallDevName_ex");
//    EthSend=(XL803::ETHSENDTYPE)my_lib.resolve("EthSend");
//    EthRecv=(XL803::ETHRECVTYPE)my_lib.resolve("EthRecv");
//    SetDev=(XL803::SetDevTYPE)my_lib.resolve("SetDev");
//    SetDev_ex=(XL803::SetDevTYPE_ex)my_lib.resolve("SetDev_ex");
//    if(my_lib.isLoaded()==false)
//    {
//        QMessageBox::information(NULL,"提示","网络模块加载失败！");
//    }
    recv_memory.setKey("share_memory");
    update_mesg(num);
    InitMemBuff();
    m_thread=new QThread();
    p_read=new read_net();
    send_flag=false;
    last_flag=false;
    is_formula=false;
    p_read->moveToThread(m_thread);
    m_send_timer=new QTimer(0);
    m_send_timer->setTimerType(Qt::PreciseTimer);
    m_out_timer=new QTimer(0);
    m_out_timer->moveToThread(this->thread());
    m_out_timer->setSingleShot(true);
    m_formula_timer=new QTimer(0);
    m_formula_timer->setSingleShot(true);
    connect(m_formula_timer,SIGNAL(timeout()),this,SLOT(formula_send()));
    //connect(m_send_timer,SIGNAL(timeout()),this,SLOT(send_data()));
    connect(m_out_timer,SIGNAL(timeout()),this,SLOT(timer_out()));
    connect(p_read,SIGNAL(ready_read(QByteArray,int)),this,SLOT(portrecv(QByteArray,int)),Qt::QueuedConnection);
    connect(p_read,SIGNAL(send_error(QByteArray)),this,SLOT(recv_err(QByteArray)),Qt::QueuedConnection);
    //connect(p_read,SIGNAL(ready_send()),this,SLOT(send_data()),Qt::QueuedConnection);
    connect(this,SIGNAL(start_thread_read()),p_read,SLOT(start_read()),Qt::QueuedConnection);
    connect(this,SIGNAL(stop_thread_read()),p_read,SLOT(stop_read()),Qt::QueuedConnection);
    last_send=0;
    send_buff=(char *)malloc(BYTE_LEN);
}
void net_connect::timer_out()
{
    if(last_flag)
    {
        out.device()->seek(last_pos);
        send_data();
    }
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
void net_connect::send_byte(QString path)
{
    file.setFileName(path);
    if(!file.isOpen())
    {
        file.open(QIODevice::ReadOnly);
    }else
    {
        out.device()->seek(0);
    }
    out.setDevice(&file);
    sample=0;
    out>>sample;
    qDebug()<<sample;
    int n=0;
    quint32 len=0;
    last_pos=out.device()->pos();
    out>>len;
    qDebug()<<"len"<<len;
    char * send_data=(char *)malloc(len);
    memset(send_data,0,len);
    out.readRawData(send_data,len);
    send_flag=false;
    last_flag=true;
    quint32 index=*((quint32 *)(send_data+10));
    emit send_index(index);
    int m_len=len;
     EthSend(send_data,len);
     last_index=0;
//    while(m_len>0)
//    {
//        if(m_len>50000)
//        {
//        qDebug()<< EthSend(send_data+n,50000);
//        }else
//        {
//        qDebug()<< EthSend(send_data+n,m_len);
//        }
//        n+=50000;
//        m_len-=n;
//    }
  //  qDebug()<<"timer"<<((len-20)/8)/(sample/50)*20;
  // m_send_timer->start(((len-20)/8)/(sample/50)*20);
 //  m_send_timer->start(1);
//    QStringList strLst;
//    for(int i = 0; i < len; i ++)
//    {
//        strLst.append(QString("%1").arg(quint8(send_data[i]),2,16,QLatin1Char('0')));
//    }
//    qDebug()<<strLst;
    free(send_data);
    m_out_timer->start(Config_set::out_time_value*1000);
}
void net_connect::send_data()
{
    if(!file.isOpen())
    {
        //m_send_timer->stop();
        return;
    }
    if(out.atEnd()||send_flag)
    {
        emit send_over();
        file.close();
        send_flag=false;
        last_flag=false;
        //m_send_timer->stop();
        return;
    }
    last_pos=out.device()->pos();
    quint32 len=0;
    out>>len;
    char * send_data=(char *)malloc(len);
    memset(send_data,0,len);
    //qDebug()<<"len"<<len;
    out.readRawData(send_data,len);
    quint32 index=*((quint32 *)(send_data+10));
    emit send_index(index);
    last_index=index;
    last_len=len+4;
    int m_len=len;
    int n=0;
//    while(m_len>0)
//    {
//        if(m_len>40000)
//        {
//        qDebug()<< EthSend(send_data+n,40000);
//        }else
//        {
//        qDebug()<< EthSend(send_data+n,m_len);
//        }
//        n+=40000;
//        m_len-=n;
//    }
    EthSend(send_data,len);
    free(send_data);
    m_out_timer->start(Config_set::out_time_value*1000);
}
void net_connect::recv_stop()
{
    send_flag=true;
    last_flag=false;
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
    if((quint8)b[5]==0xBB)
    {
        qDebug() << QTime::currentTime().toString("hh:mm:ss.zzz") << " read:" << HexToStr(b);
                    //qDebug()<<"read_index"<<*((qint32*)(b.data()+6));
        m_out_timer->stop();
        if(is_formula)
        {
            formula_send();
        }else
        {
            qDebug()<<"last_index:"<<last_index<<"read_index"<<*((qint32*)(b.data()+6));
            if(last_index!=(*((qint32*)(b.data()+6))))
            {
                   QMessageBox::information(NULL," ",QString("last:%1 read:%2").arg(last_index).arg(*((qint32*)(b.data()+6))));
            }
            send_data();
        }
    }else if((quint8)b[5]==0xBC)
    {
        qint32 index=*((qint32*)(b.data()+5));
        qDebug()<<"index:"<<index;
//        last_pos-=((index-1)-last_index)*last_len;
//        qDebug()<<"last_pos"<<last_pos;
//        if(last_pos<0)
//        {
//            qDebug()<<"pos error!";
//            return;
//        }
//        out.device()->seek(last_pos);
        if(is_formula)
        {
            formula_send();
        }else
        {
            send_data();
        }
    }else if((quint8)b[5]==0x7C)
    {
         qDebug() << QTime::currentTime().toString("hh:mm:ss.zzz") << " read:" << HexToStr(b);
    }else if((quint8)b[5]==0xFB)
    {
        emit portReaded(b,b,XL803::Power_test);
         qDebug() << QTime::currentTime().toString("hh:mm:ss.zzz") << " read:" << HexToStr(b);
    }else if((quint8)b[5]==0xBA)
    {
        emit portReaded(b,b,XL803::REOUT_WAVE);
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
            m_writeList.removeFirst();
    }

   // mutex.unlock();
}
void net_connect::start_read()
{
    m_thread->start();
    emit start_thread_read();
}
void net_connect::stop_read()
{
    emit stop_thread_read();
    m_thread->exit();
}
net_connect::~net_connect()
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
void net_connect::formula_send()
{
    recv_memory.attach();
    recv_memory.lock();
    memset(send_buff,0,BYTE_LEN);
    int* read_index=(int *)recv_memory.data();
    int * read_len=(int *)recv_memory.data()+2;
    if((*read_index)==(BYTE_LEN*100))
        *read_index=0;
    char * stop_flag=((char*)((int *)recv_memory.data()+4));
    char * read_ptr=stop_flag+1+*read_index;
    qint32 index=*((qint32*)(read_ptr+10));
    if((quint8)*stop_flag==(quint8)0xAA)
    {
        last_send=0;
        recv_memory.unlock();
        is_formula=false;
        return;
    }
    if(index<=last_send&&index!=0)
    {
        recv_memory.unlock();
        m_formula_timer->start(5);
        return;
    }
    is_formula=true;
    *read_len+=BYTE_LEN;
    memcpy(send_buff,read_ptr,BYTE_LEN);
    EthSend(send_buff,BYTE_LEN);
    emit send_index(index);

    *read_index+=BYTE_LEN;
    last_send=index;
    recv_memory.unlock();
    recv_memory.detach();
}
