#include "power_test.h"
#include "ui_power_test.h"

power_test::power_test(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::power_test)
{
    ui->setupUi(this);
    connect(L_XL803,SIGNAL(send_to_power_test(QByteArray,QByteArray)),this,SLOT(recv_mesg(QByteArray,QByteArray)));
    QString btn_style="QPushButton{font-size: 20px;}";
    QString dsp_style="QDoubleSpinBox{font-size: 20px;}";
    QString sp_style="QSpinBox{font-size: 20px;}";
    QString lb_style="QLabel{font-size: 20px;}";
    QString edit_style="QLineEdit{font-size: 20px;}";
    ui->start_test->setStyleSheet(btn_style);
    ui->u_test->setStyleSheet(btn_style);
    ui->r_test->setStyleSheet(btn_style);
    ui->read_u_r->setStyleSheet(btn_style);
    ui->label->setStyleSheet(lb_style);
    ui->label_3->setStyleSheet(lb_style);
    ui->label_4->setStyleSheet(lb_style);
    ui->label_5->setStyleSheet(lb_style);
    ui->label_6->setStyleSheet(lb_style);
    ui->label_7->setStyleSheet(lb_style);
    ui->label_8->setStyleSheet(lb_style);
    ui->label_9->setStyleSheet(lb_style);
    ui->label_10->setStyleSheet(lb_style);
    ui->label_11->setStyleSheet(lb_style);
    ui->u_start_value->setStyleSheet(dsp_style);
    ui->i_out->setStyleSheet(dsp_style);
    ui->u_range->setStyleSheet(dsp_style);
    ui->i_range->setStyleSheet(dsp_style);
    ui->u_value->setStyleSheet(dsp_style);
    ui->r_value->setStyleSheet(dsp_style);
    ui->power_size->setStyleSheet(dsp_style);
    ui->out_time->setStyleSheet(dsp_style);
    ui->u_end->setStyleSheet(dsp_style);
    ui->test_time->setStyleSheet(edit_style);
    ui->now_i->setStyleSheet(dsp_style);
    ui->temp->setStyleSheet(dsp_style);
    connect(&m_read_timer,SIGNAL(timeout()),this,SLOT(read_time()));
    connect(&m_count_timer,SIGNAL(timeout()),this,SLOT(count_time()));
}

power_test::~power_test()
{
    delete ui;
}
void power_test::recv_mesg(QByteArray send,QByteArray read)
{
    if((quint8)read[5]==0xFB)
    {
        m_read_timer.stop();
        m_count_timer.stop();
        QMessageBox::information(this,"提示","放电测试结束！");
        time_flag=true;
        end_time=QTime::currentTime();
        //L_XL803->read_power_u_r(XL803::Power_test);
        if(ui->start_test->text().compare("开始放电测试"))
        {
            ui->start_test->setChecked(false);
            ui->start_test->setText("开始放电测试");
        }
    }else if((quint8)send[5]==0xF9&&(quint8)read[5]==0xF9)
    {
        read.remove(0,6);
        float u_value=0;
        float r_value=0;
        float temp=0;
        float now_i=0;
        memcpy(&u_value,read.data(),sizeof(float));
        ui->u_value->setValue(u_value);
        read.remove(0,4);
        memcpy(&r_value,read.data(),sizeof(float));
        ui->r_value->setValue(r_value);
        read.remove(0,4);
        memcpy(&temp,read.data(),sizeof(float));
        ui->temp->setValue(temp);
        read.remove(0,4);
        memcpy(&now_i,read.data(),sizeof(float));
        ui->now_i->setValue(now_i);
        if(ui->start_test->text().compare("开始放电测试")||time_flag)
        {
            time_flag=false;
            int time=qAbs(start_time.secsTo(end_time));
            double now_time=time/3600.0;
            ui->power_size->setValue(((now_time*(ui->u_range->value()/(ui->u_start_value->value()-ui->u_value->value())))\
            /(ui->i_range->value()/ui->i_out->value()))*100);
        }
    }else if((quint8)send[5]==0xFA)
    {
        //m_read_timer.start(1000*60*ui->read_time->value());
        m_count_timer.start(1000);
        all_time=0;
        start_time=QTime::currentTime();
    }
}

void power_test::on_u_test_clicked()
{
    L_XL803->test_power_u(XL803::Power_test);
}

void power_test::on_r_test_clicked()
{
    L_XL803->test_power_r(XL803::Power_test);
}
void power_test::on_read_u_r_clicked()
{
//    if(ui->u_check->isChecked())
//        L_XL803->test_power_u(XL803::Power_test);
//    if(ui->r_check->isChecked())
//        L_XL803->test_power_r(XL803::Power_test);
    L_XL803->read_power_u_r(XL803::Power_test);
}

void power_test::on_start_test_clicked()
{
    if(ui->start_test->text().compare("开始放电测试")==0)
    {
        L_XL803->start_power_out_ele(ui->i_out->value(),ui->out_time->value()*60,ui->u_end->value(),XL803::Power_test);
        ui->start_test->setText("结束测试");
        ui->u_start_value->setValue(ui->u_value->value());
        time_flag=false;
    }else
    {
        //m_read_timer.stop();
        m_count_timer.stop();
        L_XL803->stop_power_out_ele(XL803::Power_test);
        ui->start_test->setText("开始放电测试");
    }
}
void power_test::count_time()
{
    all_time++;
    int h=all_time/3600;
    int m=all_time%3600/60;
    int s=all_time%3600%60;
    QString mm;
    QString ss;
    mm.clear();
    ss.clear();
    if(m<10)
        mm="0";
    mm+=QString::number(m);
    if(s<10)
        ss="0";
    ss+=QString::number(s);
    ui->test_time->setText(QString("%1:%2:%3").arg(QString::number(h)).arg(mm).arg(ss));
}
void power_test::read_time()
{
    L_XL803->read_power_u_r(XL803::Power_test);
}
