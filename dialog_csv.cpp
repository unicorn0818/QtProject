#include "dialog_csv.h"
#include "ui_dialog_csv.h"
bool Dialog_CSV::revPhase = false;
Dialog_CSV::Dialog_CSV(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_CSV)
{
    ui->setupUi(this);
    //this->setWindowModality(Qt::ApplicationModal);
}

Dialog_CSV::~Dialog_CSV()
{
    delete ui;
}

void Dialog_CSV::setType(int type)
{
    this->type = type;
    if(type==1)
    {
        ui->sample->hide();
        ui->label_2->hide();
    }
}

void Dialog_CSV::setLineEdit(QString str)
{
    ui->lineEdit->setText(str);
}

void Dialog_CSV::on_btOk_clicked()
{
//    if(ui->radioButton->isChecked())
//        revPhase = true;
    QString fileDbName = ui->lineEdit->text();
    double initSample = ui->sample->value();
    if(!fileDbName.isEmpty())
    {
        if(type == 0)
            emit sendFileSample(initSample);
        emit sendFileName(fileDbName,this->type); 
        this->close();
    }
    else
        this->close();
}

void Dialog_CSV::on_btCancel_clicked()
{
    this->close();
}
