#ifndef CONFIG_SET_H
#define CONFIG_SET_H

#include <QWidget>
#include <QSerialPortInfo>
#include <QSerialPort>

#include "net_connect.h"
#include "xl803.h"
#include <pcap.h>
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
    bool is_serial();
    float get_i1();
    float get_i2();
    float get_i3();
    float get_i4();
    static int out_time_value;
public slots:
    int get_com_count();
    void btn_reset();
    void btn_net_reset();
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

    void on_btn_close_clicked();

    void on_reset_window_clicked();

    void on_read_gear_clicked();

    void on_init_cpu_clicked();

signals:
    void set_window();
    void close_me();
    void disconect_com();
    void connect_com();
    void clear_list();
    void set_constp();
    void net_connect();
    void net_disconnect();
private:
    void set_net_enable(bool flag);
    Ui::Config_set *ui;
    int com_count;
    QList<QSerialPortInfo> com_list;
    XL803::METER_PARA * m_meter[3];
    XL803::LOCAL_PARA * m_local;
    XL803::XL803Proto * xl609;
    float i2_ratio;
    float i3_ratio;
    float i4_ratio;
    float i1_ratio;
    float i_num;
    bool init;
    enum meter
    {
        meter1,
        meter2,
        meter3
    };
};
#include "mainwindow.h"
#endif // CONFIG_SET_H
