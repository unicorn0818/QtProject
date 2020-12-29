#ifndef NET_CONNECT_H
#define NET_CONNECT_H
#include <QObject>
#include <QTimer>
#include <QNetworkInterface>

#include "xl803.h"
class read_net:public QObject
{
    Q_OBJECT
public:
    read_net(QObject *parent);
signals:
    void ready_read(QByteArray data,int lenth);
    void send_error(QByteArray data);
public slots:
    void read_data();
    void start_read(int i);
private:
    char* recv_buff;
    unsigned int lenth;
    QMutex mutex;
    QTimer * timer;
    QByteArray last_data;
    bool read_flag;
};
class net_connect:public QObject
{
    Q_OBJECT
    typedef struct
    {
        QByteArray bb;
        quint32 waitTs;
        XL803::PAGE page;
    }WriteListType;
public:
   static  net_connect *get_connect(QObject *parent,int num=10);
   //void update_mesg_mac();
   void update_mesg(int num);
   void start_read();
   void stop_read();
   QVector <QString> get_name();
   QVector <QString> get_desc();
   XL803::ETHSENDTYPE EthSend;
   XL803::ETHRECVTYPE EthRecv;
   XL803::InitMemBuffTYPE InitMemBuff;
   XL803::GetallDevNameTYPE GetallDevName;
   XL803::GetallDevNameTYPE_ex GetallDevName_ex;
   XL803::SetDevTYPE SetDev;
   XL803::SetDevTYPE_ex SetDev_ex;
   QThread * m_thread;
   read_net * p_read;
public slots:
   void portWrite(const QByteArray &,quint32,XL803::PAGE);
   void portrecv(QByteArray, int);
   void recv_err(QByteArray);
   void update_mesg_mac();
   void clear_list();
   void timer_out();
signals:
   void portReaded(const QByteArray &,const QByteArray &,XL803::PAGE);
   void read_start();
   void send_error(QByteArray data);
   void recv_time_out();
private:
    net_connect(QObject *parent,int num=10);
    QMutex mutex;
    QTimer *m_out_timer;
    QString HexToStr(QByteArray bb)
    {
        QString str;
        QStringList strLst;
        for(int i = 0; i < bb.count(); i ++)
        {
            strLst.append(QString("%1").arg(quint8(bb.at(i)),2,16,QLatin1Char('0')));
        }
        return strLst.join(" ");
    }
    static net_connect * net;
    QVector <QString> name;
    QVector <QString> desc;
    QList <WriteListType> m_writeList;
    char* recv_buff;
    unsigned int lenth;
};
#include "config_set.h"
#define P_NET net_connect::get_connect(this)
#endif // NET_CONNECT_H
