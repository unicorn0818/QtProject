#ifndef MAP_CONTROL_H
#define MAP_CONTROL_H

#include <QDialog>

namespace Ui {
class map_control;
}

class map_control : public QDialog
{
    Q_OBJECT

public:
    explicit map_control(QWidget *parent = 0);
    ~map_control();
signals:
    void m_move();
    void m_reset();
    void m_sq();
    void m_all_up();
    void m_all_down();
    void m_sq_x();
    void m_x_up();
    void m_x_down();
    void m_sq_y();
    void m_y_up();
    void m_y_down();
    void m_replot();
private slots:
    void on_move_clicked();

    void on_reset_clicked();

    void on_sq_clicked();

    void on_all_up_clicked();

    void on_all_down_clicked();

    void on_sq_x_clicked();

    void on_x_up_clicked();

    void on_x_down_clicked();

    void on_sq_y_clicked();

    void on_y_up_clicked();

    void on_y_down_clicked();

private:
    Ui::map_control *ui;
};

#endif // MAP_CONTROL_H
