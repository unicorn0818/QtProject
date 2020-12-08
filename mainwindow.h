#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPortInfo>
#include <QSerialPort>
#include <QThread>
#include <QDebug>
#include "xl803.h"
#include "serialex.h"
#include "key_board_dlg.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void set_enable(bool flag);
    void disconect_com();
    void connect_com();
    void disconect_net();
    void connect_net();
    void link(bool sel);
    QSerialPortInfo get_com();
    void clear_list();
signals:
    void linkDevSeri(bool);
    void close_com();
    void send_close();
private slots:
    void on_connect_bt_clicked();

    void on_start_bt_clicked();

    void on_stop_bt_clicked();

    void test_connect();

    void test_net_connect();

    void error_mesg(QByteArray data);
    void recv_time_out();
    void getConnected();
    void recv_mesg(const QByteArray last, const QByteArray now);

    void on_p_1_clicked();

    void on_p_5_clicked();

    void on_p_10_clicked();

    void on_p_20_clicked();

    void on_p_50_clicked();

    void on_p_80_clicked();

    void on_p_100_clicked();

    void on_p_120_clicked();

    void on_key_borad_clicked();

    void on_a1A_clicked();

    void on_s1A_clicked();

    void on_a01A_clicked();

    void on_s01A_clicked();

    void on_a001A_clicked();

    void on_s001A_clicked();

    void on_a0001A_clicked();

    void on_s0001A_clicked();

    void on_quit_bt_clicked();

    void on_smallbt_clicked();

    void on_output_mode_currentTextChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    void changeEvent(QEvent*);
    //输出类型
    QString output_mode;
    //额定值
    float rated_value;
    //输出电流
    double output_ele;
    //频率
    float freq;
    //创建串口对象
    QSerialPort serial;
    //串口列表
    QList<QSerialPortInfo> com_list;
    QThread *m_pSeriThread;		//串口通信用线程
    QThread *m_pNetThread;      //网口通信用线程
    SerialEx *m_pDevSeri;		//与下位机连接用的串口
    SerialEx *m_pPCSeri;		//与上位机连接用的串口
    //定时器
    QTimer * timer;
    QTimer * net_timer;
    XL803::XL803Proto * xl609;
};
#endif // MAINWINDOW_H
