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
#include "list_out.h"
#include "active_wave.h"
#include "statu_list.h"
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
    ~MainWindow();
signals:
    void linkDevSeri(bool sel);
    void linkPCSeri(bool sel);
    void close_com();
    void close_m();
public slots:
    void con_com();
    void m_close();
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
private slots:
    void show_keyboard(bool);
    void show_tab_bar(bool);
    void m_set_window();
    void reset_com();
private:
    void changeEvent(QEvent *event);
    Ui::MainWindow *ui;
    Statu_list * p_state_list;
    m_base_out * p_base_out;
    Config_set * p_config_set;
    List_out *p_list_out;
    active_wave * p_active_wave;
    QPushButton * board;
    QThread *m_pSeriThread;		//串口通信用线程
    QThread *m_pNetThread;      //网口通信用线程
    SerialEx *m_pDevSeri;		//与下位机连接用的串口
    SerialEx *m_pPCSeri;		//与上位机连接用的串口
    void link(bool sel);
    QTimer * timer;
    QTimer * net_timer;
};

#endif // MAINWINDOW_H
