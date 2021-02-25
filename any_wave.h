#ifndef ANY_WAVE_H
#define ANY_WAVE_H

#include <QWidget>

#include "customplothasroll.h"

#include "m_checkbox.h"
#include "xl803.h"

namespace Ui {
class Any_wave;
}

class Any_wave : public QWidget
{
    Q_OBJECT

public:
    explicit Any_wave(QWidget *parent = 0);
    ~Any_wave();

private slots:
    void on_print_map_clicked();

    void on_point_data_cellChanged(int row, int column);

    void add_item(int index);

    void on_freq_valueChanged(double arg1);

    void mousePress(QMouseEvent* mevent);
    void on_back_point_clicked();

    void on_smooth_wave_clicked();

    void on_clear_clicked();

    void on_priview_clicked();

    void on_hrenter_data_cellChanged(int row, int column);

    void on_base_value_valueChanged(double arg1);

    void on_save_data_clicked();

    void on_down_wave_clicked();

    void on_ratio_textChanged(const QString &arg1);

    void recv_mesg(QByteArray last,QByteArray next);

    void on_save_clicked();

    void on_set_clicked();

    void on_start_wave_clicked();

    void on_stop_wave_clicked();

    void on_sampling_valueChanged(double arg1);

    void on_time_lenth_valueChanged(double arg1);

private:
    void set_rms();
    void set_thd();
    XL803::MARKERB get_pipe(quint8 & pipe);
    XL803::MARKERB get_wt();
    m_checkbox *get_box();
    void show_wave(QByteArray data);
    Ui::Any_wave *ui;
    QCPBars * bar;
    QCPGraph * line;
    QCPGraph * line2;
    QCPGraph * line3;
    int point_count;
    float max_value;
    QVector<QCPItemEllipse *> point;
    QVector<XL803::M_point> m_point;
    QVector<XL803::M_point> out_point;
    QByteArray wave_data;
    QByteArray one_wave;
    XL803::XL803Proto * xl609;
    bool show;
    bool init;
    bool clear_flag;
    bool cell_flag;
    float max_time_lenth;
    bool start_down;
    int  mouse_flag;
    quint8 check_byte;
    QProgressDialog * dialog;
};

#endif // ANY_WAVE_H
