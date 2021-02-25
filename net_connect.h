#ifndef NET_CONNECT_H
#define NET_CONNECT_H
#include <QObject>
#include <QTimer>
#include <QNetworkInterface>

#include "ue_protocol.h"
#include "xl803.h"
class read_net:public QObject
{
    Q_OBJECT
public:
    read_net(QObject *parent=0);
signals:
    void ready_read(QByteArray data,int lenth);
    void send_error(QByteArray data);
    void ready_send();
public slots:
    void read_data();
    void start_read();
    void stop_read();
private:
    char* recv_buff;
    unsigned int lenth;
    QMutex mutex;
    QTimer * timer;
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
   ~net_connect();
   QVector <QString> get_name();
   QVector <QString> get_desc();
//   XL803::ETHSENDTYPE EthSend;
//   XL803::ETHRECVTYPE EthRecv;
//   XL803::InitMemBuffTYPE InitMemBuff;
//   XL803::GetallDevNameTYPE GetallDevName;
//   XL803::GetallDevNameTYPE_ex GetallDevName_ex;
//   XL803::SetDevTYPE SetDev;
//   XL803::SetDevTYPE_ex SetDev_ex;
   QThread * m_thread;
   read_net * p_read;
   QSharedMemory recv_memory;
public slots:
   void portWrite(const QByteArray &,quint32,XL803::PAGE);
   void portrecv(QByteArray, int);
   void recv_err(QByteArray);
   void update_mesg_mac();
   void clear_list();
   void timer_out();
   void send_byte(QString);
   void send_data();
   void recv_stop();

   void formula_send();
signals:
   void portReaded(const QByteArray &,const QByteArray &,XL803::PAGE);
   void read_start();
   void send_error(QByteArray data);
   void recv_time_out();
   void send_over();
   void send_index(int );
   void start_thread_read();
   void stop_thread_read();
private:
    net_connect(QObject *parent,int num=10);
    QMutex mutex;
    QTimer *m_out_timer;
    QTimer *m_send_timer;
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
    QFile file;
    QDataStream out;
    bool send_flag;
    bool last_flag;
    bool is_formula;
    qint64 last_pos;
    qint32 last_index;
    qint32 last_len;
    double sample;
    qint32 last_send;
    char * send_buff;
    QTimer *m_formula_timer;
};
#include "config_set.h"
#define P_NET net_connect::get_connect(this)
#endif // NET_CONNECT_H
