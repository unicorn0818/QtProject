#ifndef M_BASE_OUT_H
#define M_BASE_OUT_H

#include <QWidget>
#include <QButtonGroup>
#include <QDebug>
#include <QStandardItem>
#include <QStandardItemModel>

#include "customplothasroll.h"
#include "xl803.h"
#include "m_spinbox.h"


#include<QItemDelegate>
class BaseDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    BaseDelegate(QObject * parent=0);
    //createEditor是双击item后创建什么控件
    QWidget * createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    //setEditorData是显示控件后 设置里面的值，提供index 自己从model内提取数据
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    //setmodeldata是确定 （按下回车后）设置model的值，
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;

    ~BaseDelegate();
signals:
    void editd(QModelIndex index,double value) const;
};

namespace Ui {
class m_base_out;
}

class m_base_out : public QWidget
{
    Q_OBJECT

public:
    explicit m_base_out(QWidget *parent = 0);
    ~m_base_out();
private slots:

    void on_wave_type_valueChanged(int arg1);

    void on_value_valueChanged(double arg1);

    void on_phase_valueChanged(double arg1);

    void on_ratio_valueChanged(double arg1);

    void show_value(int id);
    void on_all_start_clicked();

    void on_start_clicked();

    void on_stop_clicked();

    void on_ua_start_clicked();

    void on_ia_start_clicked();

    void on_ub_start_clicked();

    void on_uc_start_clicked();

    void on_ib_start_clicked();

    void on_ic_start_clicked();

    void on_u_i_all_start_clicked();

    void update_value(QModelIndex index, double value);

    void on_tableView_clicked(const QModelIndex &index);

    void set_line_data(QCPGraph *line, int type, bool u_flag);

    void on_a_b_freq_valueChanged(double arg1);

    void on_c_freq_2_valueChanged(double arg1);

    void on_c_freq_valueChanged(double arg1);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_4_clicked();

    void show_model();

    void recv_mesg(QByteArray,QByteArray);

private:
    void init_value();
    Ui::m_base_out *ui;
    XL803::XL803Proto * xl609;
    void set_value(float value,int type);
    void set_ia_out(QMap<XL803::MARKERB, qint32> *data);
    void set_ua_out(QMap<XL803::MARKERB, qint32> *data);
    void set_ib_out(QMap<XL803::MARKERB, qint32> *data);
    void set_ub_out(QMap<XL803::MARKERB, qint32> *data);
    void set_ic_out(QMap<XL803::MARKERB, qint32> *data);
    void set_uc_out(QMap<XL803::MARKERB, qint32> *data);
    void set_ud_out(QMap<XL803::MARKERB, qint32> *data);
    void set_id_out(QMap<XL803::MARKERB, qint32> *data);
    struct out_value
    {
        int wave_type;
        float value;
        float phase;
        float ratio;
    };
    out_value * ua;
    out_value * ub;
    out_value * uc;
    out_value * ia;
    out_value * ib;
    out_value * ic;
    QVector <out_value *> group_value;
    M_spinbox wave_type;
    QButtonGroup * group;
    QStandardItemModel * model;
//    struct m_cloum
//    {
//        M_spinbox * wave_type;
//        QDoubleSpinBox * value;
//        QDoubleSpinBox * phase;
//        QDoubleSpinBox * ratio;
//        QDoubleSpinBox * freq;
//    };
//    m_cloum widget_table[6];
    QCPGraph * l_ua;
    QCPGraph * l_ia;
    QCPGraph * l_ub;
    QCPGraph * l_ib;
    QCPGraph * l_uc;
    QCPGraph * l_ic;
};

#endif // M_BASE_OUT_H
