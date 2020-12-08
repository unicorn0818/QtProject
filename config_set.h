#ifndef CONFIG_SET_H
#define CONFIG_SET_H

#include <QWidget>
#include <QSerialPortInfo>
#include <QSerialPort>
#include "LnkTargetCheck.h"
#include "xl803.h"
#include "ue_protocol.h"
namespace Ui {
class Config_set;
}

class Config_set : public QWidget
{
    Q_OBJECT

public:
    explicit Config_set(QWidget *parent = 0);
    ~Config_set();

    QSerialPortInfo get_com();
    QSerialPort::BaudRate get_bound();
    QSerialPort::Parity get_parity();
    QSerialPort::StopBits get_stop_byte();
    XL803::METER_PARA *get_m_meter(quint8 meter_type);
    XL803::LOCAL_PARA *get_m_local();
    static int out_time_value;
    static bool flag;
    static bool serFlag;
    void initSecUi();
    void set_connect_state();
    void set_enable(bool flag);
    void send_to_read_meter_const(quint8 flag);
    void send_to_write_meter_const(quint8 flag);
    void send_to_read_local_const();
    void send_to_write_local_const();
    void set_meter();
    void set_local();
    void set_i_ratio();
    void information();
    void initConfig();
    bool is_serial();
    float get_i1();
    float get_i2();
    float get_i3();
    float get_i4();
    void hideUi();


    QString ByteArrayToHexStr(QByteArray data);
public slots:
    int get_com_count();
    void btn_reset();
    void btn_net_reset();
    void set_connect();
    void m_connect();
    void sloReadyRead();
private slots:
    void on_check_byte_valueChanged(const QString &arg1);

    void on_stop_byte_valueChanged(const QString &arg1);
    void recv_mesg(QByteArray last,QByteArray now);
    void on_connect_dis_clicked();

    void on_net_connect_clicked();
    void set_all_enable(int index);

    void on_mac_2_textChanged(const QString &arg1);

    void on_mac_3_textChanged(const QString &arg1);

    void on_mac_4_textChanged(const QString &arg1);

    void on_mac_5_textChanged(const QString &arg1);

    void on_mac_textChanged(const QString &arg1);

    void on_com_name_currentIndexChanged(const QString &arg1);

    void on_pushButton_clicked();

    void on_close_btn_clicked();

    void on_reset_btn_clicked();

    void on_byte_out_valueChanged(int arg1);


    void on_setStart_clicked();


    void on_connect_dis_2_clicked();

    void receiveInfo();

    void recvBack(bool status, int flag);
signals:
    void disconect_com();
    void connect_com();
    void clear_list();
    void set_constp();
    void net_connect();
    void net_disconnect();
    void close_me();
    void m_reset(int);
    void m_reset_1();
    void send_to_TRJ(QStringList,int);
private:
    void set_net_enable(bool flag);
    Ui::Config_set *ui;
    QTimer *timer;
    QThread *m_Thread;
    int spec;
    QSerialPort *m_serialPort;
    int com_count;
    bool init;//初始化标志位
    QList<QSerialPortInfo> com_list;
    QStringList com_list_2;
    XL803::METER_PARA * m_meter[3];
    XL803::LOCAL_PARA * m_local;
    XL803::XL803Proto * xl609;
    float i2_ratio;//小信号通道1
    float i3_ratio;//小信号通道2
    float i4_ratio;//小信号通道3
    float i1_ratio;//电流变比
    float i_num;//电流并联数
    enum meter
    {
        meter1,
        meter2,
        meter3
    };

};
#include "mainwindow.h"
#endif // CONFIG_SET_H
