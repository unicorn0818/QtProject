#ifndef WAVE_REOUT_H
#define WAVE_REOUT_H

#include <QWidget>
#include <QDir>
#include <QDebug>
#include <QMessageBox>
#include <QThread>
#include <QDateTime>
#include <QProgressDialog>
#include "xl803.h"
#include "./XL-Comtrade/comtrade.h"

using namespace std;
namespace Ui {
class Wave_reout;
}
/**
 * @brief The file_control class
 * 数据文件处理类
 */
class file_control:public QObject
{
    Q_OBJECT
public:
    explicit file_control(QObject *parent = 0);
    ~file_control();
signals:
    void send_mesg(int ,int);
    void send_vector(QVector<double>,QVector<double>,double,float);
public slots:
    void file(QString , double, int );
    void comtrade_convert(QString,double sample);
    void out_file(QString ,QVector<int>,QVector<int>,int);
    void show_map(int ,int ,QString,int);

};
/**
 * @brief The formula_control class
 * 公式输出类
 */
class formula_control:public QObject
{
    Q_OBJECT
public:
    explicit formula_control(QObject *parent = 0);
    ~formula_control();
    QSharedMemory send_memory;
    long all_lenth;
    bool start_flag;
signals:
    void data_ready();
public slots:
    void formula_data(double , QVector<int> , QVector<QString>);
    QString get_max_formula(QString formula);
    int get_str_len(int,QString);
};
typedef union
{
    quint8 byte_8[4];
    quint16 byte_16[2];
    quint32 byte_32;
}byte_data;
typedef struct
{
    quint8 * byte_8[4];
}big_byte_data;
/**
 * @brief The Wave_reout class
 * 长录波界面
 */
class Wave_reout : public QWidget
{
    Q_OBJECT

public:
    explicit Wave_reout(QWidget *parent = 0);
    ~Wave_reout();
signals:
    void send_path(QString,double,int);
    //录波路径的处理
    void comtrade_path(QString,double );
    void send_out_path(QString ,QVector<int>,QVector<int>,int );
    void send_out(QString);
    void priview_map(int ,int,QString,int);
    void send_stop();
    void start_formula(double , QVector<int>,QVector<QString>);
    void stop_formula();
    void start_read();
    void disConnect(int,bool);
private slots:
    void m_priview(QVector<double>,QVector<double>,double,float);

    void on_update_list_clicked();

    void on_change_file_clicked();

    void on_checkBox_7_clicked();

    void show_dialog(int ,int);

    void on_a_clicked();

    void on_b_clicked();

    void on_c_clicked();

    void on_d_clicked();

    void on_wave_start_file_clicked();

    void on_new_file_clicked(const QModelIndex &index);

    void on_wave_start_clicked();

    void recv(QByteArray,QByteArray);
    //void on_wave_mesg_clicked();

    void on_new_wave_mesg_clicked();

    //void on_wave_out_mesg_clicked();

    void on_priview_clicked();

    void recv_over();
    void on_no_stop_clicked();

    void recv_index(int);

    void on_stop_wave_clicked();

    void on_data_control_clicked();


    void on_all_clicked();

    void on_start_formula_clicked();

    void on_stop_formula_clicked();

    void start_send();

    void on_checkBox_8_clicked();

    void on_checkBox_clicked();

    void on_checkBox_2_clicked();

    void on_checkBox_3_clicked();

    void on_wave_reout_clicked();

    void on_remove1_clicked();

    void on_remove2_clicked();

    void read_formula_file();

    void on_formula_list_activated(int index);

private:
    void updata_old_file();
    void updata_new_file();
    void updata_out_file();
    void set_pipe_range(int value);
    void show_map();
    bool is_big;
    QProgressDialog * dialog;
    QTimer timer;
    Ui::Wave_reout *ui;
    file_control m_file;
    formula_control m_formula;
    QThread file_thread;
    QThread formula_thread;
    QCPGraph * line;
    QSharedMemory stop_memory;
    QVector<int> index_vector;
    QVector<int> pipe_vector;
    QVector<QString> old_path_name;
    QVector<QString> new_path_name;
    QVector<QString> out_path_name;
    QString now_out_path;
    QStringList file_formula_list;
    int out_count;
};
#include "mainwindow.h"

#endif // WAVE_REOUT_H
