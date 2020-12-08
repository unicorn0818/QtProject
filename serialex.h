#ifndef SERIALEX_H
#define SERIALEX_H
#include <QSerialPort>
#include <QTimer>
#include "xl803.h"
class SerialEx : public QSerialPort
{
	Q_OBJECT
	typedef struct
	{
		QByteArray bb;
		quint32 waitTs;
        XL803::PAGE page;
	}WriteListType;
public:
    SerialEx(QObject *parent);
	~SerialEx();
signals:
    //已连接
	void portConnected();
    //读到数据
    void portReaded(const QByteArray &rb,const QByteArray &wB,XL803::PAGE);
    //发送错误
    void send_error(QByteArray data);
    //发送结束
    void send_end_out(QByteArray data,XL803::PAGE);
    //超时
    void recv_time_out();
	
private slots:
	void readTimerOut();
	void onReadyRead();
	void readSendTimerOut();
public slots://不许直接调用，必需用信号曹机制
    //连接串口
	void linkToCom(bool sel);
    //往端口写数据
    void portWrite(const QByteArray &b,quint32 waitTimes,XL803::PAGE);
    void portWrite(const QByteArray &b, XL803::PAGE page);

    void timer_out();
	void test(QByteArray &b)
	{
		b.append("fdsafd");
	}
    void clear_list();
    void m_close();
private:
	QList<WriteListType> m_writeList;
    WriteListType data;
	QTimer *m_pReadTimer;		//要在连接时移到对象所在的线程
    QTimer *m_out_timer;
	QTimer *m_pReadSendTimer;
   // QLibrary * my_lib;
	bool m_LstEmpty;

private:
    //十六进制转字符串
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
    int all_size;
    QByteArray lenth;
};
//#include "config_set.h"
#endif // SERIALEX_H
