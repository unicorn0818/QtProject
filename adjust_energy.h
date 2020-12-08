#ifndef ADJUST_ENERGY_H
#define ADJUST_ENERGY_H

#include <QWidget>

namespace Ui {
class adjust_energy;
}

class adjust_energy : public QWidget
{
    Q_OBJECT

public:
    explicit adjust_energy(QWidget *parent = 0);
    ~adjust_energy();

private slots:
    void on_enable_std_num_clicked();

    void on_check_adjust_clicked();

    void on_start_adjust_clicked();

    void on_read_old_num_clicked();

    void on_count_num_clicked();

    void on_stop_adjust_clicked();

    void on_init_num_clicked();

    void on_init_std_value_clicked();

    void on_write_num_clicked();

    void on_normal_clicked();

    void on_out_std_clicked();

    void on_stop_out_clicked();

private:
    Ui::adjust_energy *ui;
};

#endif // ADJUST_ENERGY_H
