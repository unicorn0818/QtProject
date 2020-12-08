#ifndef WAVE_REOUT_ZJ_H
#define WAVE_REOUT_ZJ_H

#include <QWidget>
#include <QDir>
#include <QDebug>
#include <QMessageBox>
#include <QThread>
#include <QDateTime>
#include <QProgressDialog>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSqlRecord>
#include "xl803.h"
#include "./XL-Comtrade/comtrade.h"
#include "dialog_csv.h"
#include "dialog.h"
#include "mycbb.h"

using namespace std;
namespace Ui {
class wave_reout_ZJ;
}

/**
 * @brief The file_control class
 * 数据文件处理类
 */
class file_control1:public QObject
{
    Q_OBJECT
public:
    explicit file_control1(QObject *parent = 0);
    ~file_control1();
    QVector<float> saveCSVData(QString filePath);
    double calEnergy(QVector<float> volTmp, QVector<float> eleTmp,int type);
    void setInsertMode(quint8 N);
    QVector<float> getVol(int ch_vol, QString file_name);
    QVector<float> overLay(QList<int> ch_list, QString file_name,bool revFlag);
    int get_pipe_count(QString filename);
    void writeToTmp(QVector<float> data_vol,QVector<float> data_ele,QString scr);
    int wave_point_count(QString file_name);
    int samplerate(QString file_name);
    void setNum(int NUM);
    static quint32 indexAll;
signals:
    void send_mesg(int ,int);
    void send_vector(QVector<double>,QVector<double>,double,float);
    void send_vector1(QVector<double>,QVector<double>,double,float);
    void finish(QString,double);
    void outFileName(QString);
    void add_sql(QString,int);
public slots:
    void file(QString , double, int ,int);
    void comtrade_convert(QString,double sample,QString);
    void comtrade_convert_CSV(QString,QString,QString,double sample,bool);
    void out_file(QString ,QVector<int>,QVector<int>,int,int);
    void show_map(int ,int ,QString,int);
    void getFileSample(double);
private:
    double initSample,initSample1,energy,sample;
    QStringList energyList;
    qint8 N;
    QVector<float> data,data1;
    int NUM;
};
/**
 * @brief The formula_control class
 * 公式输出类
 */
class formula_control1:public QObject
{
    Q_OBJECT
public:
    explicit formula_control1(QObject *parent = 0);
    ~formula_control1();
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
}byte_data1;
typedef struct
{
    quint8 * byte_8[4];
}big_byte_data1;
/**
 * @brief The wave_reout_ZJ class
 * 浙江用电负荷仿真页面
 */
class wave_reout_ZJ : public QWidget
{
    Q_OBJECT

public:
    explicit wave_reout_ZJ(QWidget *parent = 0);
    ~wave_reout_ZJ();
    void initUi();
    void initConnect();
    void initSql();
    void startOutPut();
    void setModel(QString dbName);
    int get_pipe_count(QString filename);
    int wave_point_count(QString file_name);
    int samplerate(QString file_name);
    bool Write_to_tmp(QVector<float> data_vol, QVector<float> data_ele, QString scr);
    QString get_table_name();
    QVector<float> GetVol(int ch_vol, QString file_name);
    QVector<float> OverLay(QList<int> ch_list, QString file_name);
    bool revFlag,revFlag_2;
signals:
    void comtrade_path_CSV(QString,QString,QString,double,bool);
    void comtrade_path(QString,double,QString);
    void priview_map(int ,int,QString,int);
    void send_stop();
    void send_out_path(QString ,QVector<int>,QVector<int>,int,int);
    void send_out(QString);
    void disConnect(int,bool);
    void sendBack(bool,int);
    void setNowNum(int);
private slots:
    void recvOrder(QStringList,int);
    void getFileName(QString CSVDbName,int);
    void addDb(QString,double);
    void m_priview(QVector<double> x, QVector<double> y, double time, float max);
    void m_priview1(QVector<double> x, QVector<double> y, double time, float max);
    void show_dialog(int index, int value);
    void recv(QByteArray wb, QByteArray rb);
    void recv_over();
    void recv_index(int value);
    void recv_fileName(QString file_name);
    void sql_add(QString file_path, int type);
    void ele_ch_bind(int ele_ch, QString equip_name);
    void vol_ch_bind(int vol_ch);
    void icon_bind(QString icon_path, int ele_ch);
    void cancel_click();
    void list_append(QString name);
    void list_remove(QString name);
    void set_false_enable();
    void on_btViewWave_2_clicked();
    void on_startOutput_2_clicked();
    void on_stopOutput_2_clicked();
    void on_btAdd_clicked();
    void on_btRemove_clicked();
    void on_btViewWave_clicked();
    void on_btAdd_2_clicked();
    void on_btRemove_2_clicked();
    void on_overlayWave_clicked();
    void on_scene_clicked(const QModelIndex &index);
    void on_tabWidget_currentChanged(int index);
    void on_configPipe_clicked();
    void on_startOutput_clicked();
    void on_stopOutput_clicked();
    void on_eleRev_clicked(bool checked);
    void on_eleRev_2_clicked(bool checked);
    void on_insertMode_currentIndexChanged(int index);
    void on_insertMode_2_currentIndexChanged(int index);
    void on_ua_max_editingFinished();

    void on_ia_max_editingFinished();


private:
    Ui::wave_reout_ZJ *ui;
    file_control1 m_file;
    QProgressDialog * dialog;
    QVector<int> index_vector;
    QVector<int> pipe_vector;
    QSqlTableModel *model;
    QThread file_thread;
    QString fileNameCSV;
    QString fileNameCom;
    QCPGraph * line;
    QCPGraph * line2;
    QCPItemText *label;
    QString outFileName;
    QStringList info_list,list,list1;
    QVector<QStringList> table_info_list;
    QVector<MyCBB *> v_hbox; 
    QVector<float> curMaxValue;
    bool is_big;
    double maxP,minP,energy1,initSample;
};
#include "mainwindow.h"
#endif // WAVE_REOUT_ZJ_H
