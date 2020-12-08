#ifndef HRENTER_OUT_H
#define HRENTER_OUT_H

#include <QWidget>
#include <QTableWidgetItem>

#include "xl803.h"
#include "customplothasroll.h"
namespace Ui {
class Hrenter_out;
}
//原为6通道后改为16通道，待重构
class Hrenter_out : public QWidget
{
    Q_OBJECT

public:
    explicit Hrenter_out(QWidget *parent = 0);
    ~Hrenter_out();

private slots:
    void on_hrenter_data_cellChanged(int row, int column);


    void on_pipe_type_currentIndexChanged(int index);

    void on_wave_type_valueChanged(int arg1);

    void on_base_value_valueChanged(double arg1);

    void on_ratio_valueChanged(double arg1);

    void on_freq_valueChanged(double arg1);

    void on_base_start_clicked();

    void on_base_stop_clicked();

    void on_write_hrenter_data_clicked();

    void on_hrenter_all_start_clicked();

    void on_base_all_start_clicked();

    void on_all_stop_clicked();

    void on_hrenter_start_clicked();

    void on_hrenter_stop_clicked();

    void on_clear_hrenter_data_clicked();

    void recv_mesg(QByteArray,QByteArray);

    void on_preview_hrenter_clicked();

    void on_base_phase_valueChanged(double arg1);

    void on_all_clicked();

private:
    struct base
    {
        float value;
        float phase;
        int wave_type;
        float ratio;
        float freq;
    };
    void show_hr_data(int type, base *pipe);
    void show_base_data(base *pipe);
    void set_rms(int type, base *pipe);
    void set_thd(int type);
    void init_value();
    void set_ua_out(QMap<XL803::MARKERB, qint32> *data);
    void set_ub_out(QMap<XL803::MARKERB, qint32> *data);
    void set_uc_out(QMap<XL803::MARKERB, qint32> *data);
    void set_ud_out(QMap<XL803::MARKERB, qint32> *data);
    void set_ia_out(QMap<XL803::MARKERB, qint32> *data);
    void set_ib_out(QMap<XL803::MARKERB, qint32> *data);
    void set_ic_out(QMap<XL803::MARKERB, qint32> *data);
    void set_id_out(QMap<XL803::MARKERB, qint32> *data);

    void set_ua1_out(QMap<XL803::MARKERB, qint32> *data);
    void set_ub1_out(QMap<XL803::MARKERB, qint32> *data);
    void set_uc1_out(QMap<XL803::MARKERB, qint32> *data);
    void set_ud1_out(QMap<XL803::MARKERB, qint32> *data);
    void set_ia1_out(QMap<XL803::MARKERB, qint32> *data);
    void set_ib1_out(QMap<XL803::MARKERB, qint32> *data);
    void set_ic1_out(QMap<XL803::MARKERB, qint32> *data);
    void set_id1_out(QMap<XL803::MARKERB, qint32> *data);
    void check_flag(int );
    void write_hrenter_out();
    void write_base(bool flag);
    QVector<QString> start_flag;
    Ui::Hrenter_out *ui;
    XL803::PhaseOneHrDef m_hrData[XL803::SOUR_PHASE_NUM_MAX][XL803::HIGHT_HAR_TIMES];
    XL803::XL803Proto * xl609;
    QCPBars * bar;
    QCPGraph * line;
    QVector <int> list_flag;
    QVector <base *> base_vector;
    QVector <XL803::CH_MAP> enum_index;
    enum
    {
        ua,
        ia,
        ub,
        ib,
        uc,
        ic,
        ud,
        id,
        ua1,
        ia1,
        ub1,
        ib1,
        uc1,
        ic1,
        ud1,
        id1,
    };
    void hide_other();
    bool init;
};

#endif // HRENTER_OUT_H
