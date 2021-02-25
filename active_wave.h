#ifndef ACTIVE_WAVE_H
#define ACTIVE_WAVE_H

#include <QWidget>

#include "xl803.h"
#include "m_checkbox.h"

class ActiveDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    ActiveDelegate(QObject * parent=0);
    //createEditor是双击item后创建什么控件
    QWidget * createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    //setEditorData是显示控件后 设置里面的值，提供index 自己从model内提取数据
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    //setmodeldata是确定 （按下回车后）设置model的值，
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;

    ~ActiveDelegate();
signals:
    void editd(QModelIndex index,QString value) const;
};


class ViewDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    ViewDelegate(QObject * parent=0);
    //createEditor是双击item后创建什么控件
    QWidget * createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    //setEditorData是显示控件后 设置里面的值，提供index 自己从model内提取数据
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    //setmodeldata是确定 （按下回车后）设置model的值，
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;

    ~ViewDelegate();
signals:
    void editd(QModelIndex index,double value) const;
};

namespace Ui {
class active_wave;
}

class active_wave : public QWidget
{
    Q_OBJECT

public:
    explicit active_wave(QWidget *parent = 0);
    ~active_wave();
private slots:
    void add_item(int index);
    void on_save_formula_clicked();

    void on_open_formula_clicked();

    void on_save_wave_clicked();

    void on_open_wave_clicked();

    void on_priview_wave_clicked();

    void on_out_now_wave_clicked();

    void on_start_out_clicked();

    void on_stop_out_clicked();

    void on_all_start_clicked();

    void on_all_stop_clicked();

    void recv_mesg(QByteArray send,QByteArray read);

    void on_formula_valueChanged(int arg1);

    void show_rula(int );

    void update_value(QModelIndex index,QString value);

    void update_value(QModelIndex index,double value);


    void show_line();

    void set_line_data(int u_all=0,int num=6);

    void on_priview_all_wave_clicked();

    void on_out_all_wave_clicked();

    void cancel_down();

    void showListWidgetMenuSlot(QPoint pos);

    void copy_one(bool);

    void copy_all(bool);

    void past(bool);

    void remove_one(bool);

    void remove_all(bool);

    int get_set_flag();
private:
    struct rule_value{
        QString rule;
        QString time;
    };
    struct line_data{
        QVector<double> x;
        QVector<double> y;
    };
    QCPGraph * line;
    QMenu *m_contextMenu;
    QAction * m_copy_one;
    QAction * m_copy_all;
    QAction * m_remove;
    QAction * m_past;
    int copy_flag;
    int copy_row;
    int copy_phase;
    void  show_wave(QByteArray  data);
    m_checkbox *get_box(int index=-1);
    void set_enable(bool flag);
    quint8 check_byte;
    XL803::XL803Proto * xl609;
    Ui::active_wave *ui;
    QByteArray wave_data;
    QByteArray wave_data_2;
    QByteArray wave_data_3;
    QByteArray wave_data_4;
    QByteArray wave_data_5;
    QByteArray wave_data_6;
    QByteArray down_wave;
    QByteArray one_wave;
    bool pri_flag;
    bool read_formula;
    bool start_down;
    short all_byte;
    short now_byte;
    QProgressDialog * dialog;
    float max_time_lenth;
    QStandardItemModel * model;
    QStandardItemModel * value_model;
    QMap<int,rule_value> ua_rule_map;
    QMap<int,rule_value> ub_rule_map;
    QMap<int,rule_value> uc_rule_map;
    QMap<int,rule_value> ia_rule_map;
    QMap<int,rule_value> ib_rule_map;
    QMap<int,rule_value> ic_rule_map;
    line_data ua_data;
    line_data ub_data;
    line_data uc_data;
    line_data ia_data;
    line_data ib_data;
    line_data ic_data;
    float ua_max;
    float ub_max;
    float uc_max;
    float ia_max;
    float ib_max;
    float ic_max;
    float ua_rms;
    float ub_rms;
    float uc_rms;
    float ia_rms;
    float ib_rms;
    float ic_rms;
    int ua_sample;
    int ub_sample;
    int uc_sample;
    int ia_sample;
    int ib_sample;
    int ic_sample;
    int down_num;
    int down_flag;
    bool data_creator_flag;
    bool cancel_flag;
    QVector<int *> sample_vector;
    QVector<float *> max_vector;
    QVector<float *> rms_vector;
    QVector<line_data *> line_vector;
    QVector<QByteArray *> wave_vector;
    QVector<QMap<int,rule_value> *> map;
};
#include "mainwindow.h"
#endif // ACTIVE_WAVE_H
