#ifndef POWER_TEST_H
#define POWER_TEST_H

#include <QWidget>

#include "xl803.h"
namespace Ui {
class power_test;
}

class power_test : public QWidget
{
    Q_OBJECT

public:
    explicit power_test(QWidget *parent = 0);
    ~power_test();
public slots:
    void recv_mesg(QByteArray,QByteArray);
private slots:
    void on_u_test_clicked();

    void on_r_test_clicked();

    void on_read_u_r_clicked();

    void on_start_test_clicked();

    void read_time();

    void count_time();
private:
    Ui::power_test *ui;
    QTimer m_read_timer;
    QTimer m_count_timer;
    QTime  start_time;
    QTime  end_time;
    long all_time;
    bool time_flag;
};

#endif // POWER_TEST_H
