#include "test_bll.h"
#include "ui_test_bll.h"

test_bll::test_bll(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::test_bll)
{
    ui->setupUi(this);
    connect(L_XL803,SIGNAL(send_to_base_out(QByteArray,QByteArray)),this,SLOT(recv_mesg(QByteArray,QByteArray)));
}

test_bll::~test_bll()
{
    delete ui;
}
void test_bll::on_pushButton_clicked()
{

}
void test_bll::recv_mesg(QByteArray wb,QByteArray rb)
{
    qDebug()<<wb.data();
    qDebug()<<rb.data();
}
