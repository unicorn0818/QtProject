#include "mycbb.h"
#include "ui_mycbb.h"

MyCBB::MyCBB(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyCBB)
{
    ui->setupUi(this);
    ui->label->setScaledContents(true);
}

MyCBB::~MyCBB()
{
    delete ui;
}

void MyCBB::setIcon(QIcon icon)
{
    ui->checkBox->setIcon(icon);
}
void MyCBB::setScaledContents(bool value)
{
    ui->label->setScaledContents(value);
}

void MyCBB::clickBox()
{
    ui->checkBox->click();
}
void MyCBB::setLabelText(QString text)
{
    ui->label->setText(text);
}
void MyCBB::setIconSize(QSize size)
{
    ui->checkBox->setIconSize(size);
}

void MyCBB::on_checkBox_clicked(bool checked)
{
    if(checked==1)
       emit append_list(ui->label->text());
    else
       emit remove_list(ui->label->text());
}

void MyCBB::on_checkBox_stateChanged(int arg1)
{
    emit set_enable_false();
}
