#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
//    setFocusPolicy(Qt::NoFocus);
}

Dialog::~Dialog()
{
    delete ui;
}
//取消
void Dialog::on_cancel_bt_clicked()
{
    this->close();
    emit click_cancel();
}
void Dialog::setMaxValue(int pipe_count)
{
    this->pipe_count = pipe_count;
    ui->spinBox->setMinimum(1);
    ui->spinBox_2->setMinimum(1);
    ui->spinBox->setMaximum(pipe_count);
    ui->spinBox_2->setMaximum(pipe_count);
}

//绑定电压
void Dialog::on_bind_vol_clicked()
{
    int vol_ch = ui->spinBox->value();
    emit bind_vol_ch(vol_ch);
    this->show();
}
//绑定电流
void Dialog::on_bind_ele_clicked()
{
    if(ui->lineEdit->text().isEmpty())
    {
        QMessageBox::information(this,"提示","请先输入用电器",QMessageBox::Ok);
        return;
    }
    int ele_ch = ui->spinBox_2->value();
    QString equip_name = ui->lineEdit->text();
    emit bind_ele_ch(ele_ch,equip_name);
    this->show();
}
//绑定图标
void Dialog::on_bind_icon_clicked()
{
    int ele_ch = ui->spinBox_2->value();
    this->icon_path = QFileDialog::getOpenFileName(NULL,"打开录波文件","./image","*.*");
    emit bind_icon(icon_path,ele_ch);
    this->show();
}
