#ifndef REOUT_WAVE_H
#define REOUT_WAVE_H

#include <QWidget>

#include "xl803.h"
#include "map_control.h"
#include "./XL-Comtrade/comtrade.h"
#define all_channel 8
namespace Ui {
class reout_wave;
}

class reout_wave : public QWidget
{
    Q_OBJECT

public:
    explicit reout_wave(QWidget *parent = 0);
    ~reout_wave();

private slots:
    void on_start_out_clicked();

    void on_stop_out_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_mid_wave_clicked();

    void on_read_falush_lenth_clicked();

    void on_write_wave_date_clicked();

    void recv_mesg(QByteArray,QByteArray);

    double set_line_data(QCPGraph *, unsigned int pipe, int start_point=0,int point=0);

    void on_ib_pipe_valueChanged(int arg1);

    void on_ua_pipe_valueChanged(int arg1);

    void on_ub_pipe_valueChanged(int arg1);

    void on_uc_pipe_valueChanged(int arg1);

    void on_ia_pipe_valueChanged(int arg1);

    void on_ic_pipe_valueChanged(int arg1);

    void m_reset();

    void m_move();
    void m_sq();
    void m_all_up();
    void m_all_down();
    void m_sq_x();
    void m_x_up();
    void m_x_down();
    void m_sq_y();
    void m_y_up();
    void m_y_down();
    void on_map_control_clicked();

    void u_press(QMouseEvent*);
    void i_press(QMouseEvent*);
    void mousePress(QMouseEvent* mevent);
    void mouseMove(QMouseEvent*);
    void mouseRelease(QMouseEvent*);

    void m_replot();
    void on_all_clicked();
    void cancel_down();

private:
    void set_signal();
    void reset_ticker();
    double get_max(double * data, double start, double end);
    Ui::reout_wave *ui;
    XL803::XL803Proto * xl609;
    int pipe_count;
    double max_freq;
    double start_time;
    double end_time;
    double wave_point_count;
    QCPGraph * l_ua;
    QCPGraph * l_ub;
    QCPGraph * l_uc;
    QCPGraph * l_ia;
    QCPGraph * l_ib;
    QCPGraph * l_ic;
    QCPGraph * l_u;
    QCPGraph * l_i;
    map_control * p_control;
    quint8 check_byte;
    int all_byte;
    QByteArray wave_data;
    QByteArray one_wave;
    int now_byte;
    bool start_down;
    int type;
    double wave_send_count;
    QProgressDialog * dialog;
    QRubberBand * u_rubber;
    QRubberBand * i_rubber;
    QPoint rubberOrigin;
    bool u_flag;
    bool i_flag;
};

#endif
