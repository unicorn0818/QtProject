#include "map_control.h"
#include "ui_map_control.h"

map_control::map_control(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::map_control)
{
    ui->setupUi(this);
    setWindowFlags( Qt::WindowStaysOnTopHint | Qt::Tool |Qt::WindowDoesNotAcceptFocus);
}

map_control::~map_control()
{
    delete ui;
}

void map_control::on_move_clicked()
{
    emit m_move();
}

void map_control::on_reset_clicked()
{
    emit m_reset();
}

void map_control::on_sq_clicked()
{
    emit m_sq();
}

void map_control::on_all_up_clicked()
{
    emit m_all_up();
}

void map_control::on_all_down_clicked()
{
    emit m_all_down();
}

void map_control::on_sq_x_clicked()
{
    emit m_sq_x();
}

void map_control::on_x_up_clicked()
{
    emit m_x_up();
}

void map_control::on_x_down_clicked()
{
    emit m_x_down();
}

void map_control::on_sq_y_clicked()
{
    emit m_sq_y();
}

void map_control::on_y_up_clicked()
{
    emit m_y_up();
}

void map_control::on_y_down_clicked()
{
    emit m_y_down();
}

