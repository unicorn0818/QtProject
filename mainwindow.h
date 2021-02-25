#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#define protocol_verion 1

#include <QMainWindow>
#include <QThread>
#include <QDebug>
#include <QLabel>
#include <QResizeEvent>
#include <QPushButton>

#include "m_base_out.h"
#include "serialex.h"
#include "key_board_dlg.h"
#include "config_set.h"
#include "hrenter_out.h"
#include "any_wave.h"
#include "active_wave.h"
#include "adjust_energy.h"
#include "reout_wave.h"
#include "net_connect.h"
#include "wave_reout.h"
#include "power_test.h"
#include "test_bll.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    float ratio_value(int type, float value);
    static bool connect_flag;
    static bool net_flag; 
    ~MainWindow();
signals:
    void linkDevSeri(bool sel);
    void linkPCSeri(bool sel);
    void close_com();
    void close_m();
public slots:
    void m_close();
    void con_com();
    void dis_com();
    void test_connect();
    void test_net_connect();
    void recv_mesg(const QByteArray last, const QByteArray now);
    void clear_list();
    void resizeEvent(QResizeEvent * event);
    void connect_net();
    void disconnect_net();
    void error_mesg(QByteArray data);
    void recv_time_out();
    void reset_size();
private slots:
    void show_keyboard(bool);
private:
    void changeEvent(QEvent*);
    Ui::MainWindow *ui;
    Any_wave * p_any_wave;
    m_base_out * p_base_out;
    Config_set * p_config_set;
    Hrenter_out * p_hrenter;
    active_wave * p_active_wave;
    adjust_energy * p_adjust_energy;
    reout_wave * p_reout_wave;
    Wave_reout * p_wave_reout;
    power_test * p_power_test;
    test_bll * p_test_bll;
    QPushButton * board;
    QThread *m_pSeriThread;		//串口通信用线程
    QThread *m_pNetThread;      //网口通信用线程
    SerialEx *m_pDevSeri;		//与下位机连接用的串口
    SerialEx *m_pPCSeri;		//与上位机连接用的串口
    void link(bool sel);
    QTimer * timer;
    QTimer * net_timer;
    bool m_net_flag;
};

#endif // MAINWINDOW_H
