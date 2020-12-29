#include "config_set.h"
#include "ui_config_set.h"
int Config_set::out_time_value=10;
Config_set::Config_set(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Config_set)
{
    ui->setupUi(this);
    foreach (const QSerialPortInfo &qspinfo, QSerialPortInfo::availablePorts())
    {
           ui->com_name->addItem(qspinfo.portName());
           com_list<<qspinfo;
    }
    ui->com_name->addItem("刷新");
    //ui->com_name->setStyleSheet("font: 14pt '宋体';");
    QVector<QString> items;
    items<<"57600"<<"38400"<<"9600";
    ui->baud->setRange(0,2);
    ui->baud->set_items(items);
    ui->baud->setValue(1);
    items.clear();
    ui->check_byte->setRange(0,2);
    items<<"偶校验"<<"奇校验"<<"无校验";
    ui->check_byte->set_items(items);
    ui->check_byte->setValue(2);
    items.clear();
    items<<"2位"<<"1.5位"<<"1位";
    ui->stop_byte->setRange(0,2);
    ui->stop_byte->set_items(items);
    ui->stop_byte->setValue(2);
    items.clear();
    xl609=L_XL803;
    m_meter[meter1]=NULL;
    m_meter[meter2]=NULL;
    m_meter[meter3]=NULL;
    m_local=NULL;
    //QRegExp rx("^1150|([0,1](([1][0-4])|([0]\\d))\\d(\\.\\d{1,3})?)|\\d{1,3}(\\.\\d{1,3})?$");
    //^(-?\d+)(\.\d+)?$
    QRegExp rx("^(\\d|([a,b,c,d,e,f,A,B,C,D,E,F]))(\\d|([a,b,c,d,e,f,A,B,C,D,E,F]))$");
    ui->mac->setValidator(new QRegExpValidator(rx, this));
    ui->mac_2->setValidator(new QRegExpValidator(rx, this));
    ui->mac_3->setValidator(new QRegExpValidator(rx, this));
    ui->mac_4->setValidator(new QRegExpValidator(rx, this));
    ui->mac_5->setValidator(new QRegExpValidator(rx, this));
    ui->mac_6->setValidator(new QRegExpValidator(rx, this));
    ui->label_3->setStyleSheet("QLabel{border-image:url(:./png/logo.png);}");
    connect(xl609,SIGNAL(send_to_config(QByteArray,QByteArray)),this,SLOT(recv_mesg(QByteArray,QByteArray)));
    connect(ui->buttonGroup,SIGNAL(buttonClicked(int)),this,SLOT(set_all_enable(int)));
    i2_ratio=1;
    i3_ratio=1;
    i4_ratio=1;
    i1_ratio=1;
    i_num=1;
    ui->desc->set_items(P_NET->get_desc());
    ui->serial->click();
    set_enable(false);
    ui->connect_dis->setChecked(true);
    ui->connect_dis->setText("断开");
    init=true;
}

Config_set::~Config_set()
{
    delete ui;
}

QSerialPortInfo Config_set::get_com()
{
    int index=ui->com_name->currentIndex();
    if(index<0||index>com_list.count())
    {
        return com_list[0];
    }else
    {
        return com_list[index];
    }
}
QSerialPort::BaudRate Config_set::get_bound()
{
    switch (ui->baud->value()) {
    case 0:
        return QSerialPort::Baud57600;
    case 1:
        return QSerialPort::Baud38400;
    case 2:
        return QSerialPort::Baud9600;
    default:
        break;
    }
}
QSerialPort::Parity Config_set::get_parity()
{
    switch (ui->check_byte->value()) {
    case 0:
        return QSerialPort::EvenParity;
    case 1:
        return QSerialPort::OddParity;
    case 2:
        return QSerialPort::NoParity;
    default:
        break;
    }
}
QSerialPort::StopBits Config_set::get_stop_byte()
{
    switch (ui->stop_byte->value()) {
    case 0:
        return QSerialPort::TwoStop;
    case 1:
        return QSerialPort::OneAndHalfStop;
    case 2:
        return QSerialPort::OneStop;
    default:
        break;
    }
}


void Config_set::on_check_byte_valueChanged(const QString &arg1)
{

}

void Config_set::on_stop_byte_valueChanged(const QString &arg1)
{

}
XL803::METER_PARA * Config_set::get_m_meter(quint8 meter_type)
{
    return m_meter[meter_type]>0?m_meter[meter_type]:0;
}
XL803::LOCAL_PARA *Config_set::get_m_local()
{
    return m_local;
}
/*
void Config_set::send_to_read_meter_const(quint8 flag)
{
    xl609->read_meter_const(flag,XL803::Config_set);
}



void Config_set::send_to_read_local_const()
{

    xl609->read_local_const(XL803::Config_set);
}
*/

void Config_set::recv_mesg(QByteArray last, QByteArray now)
{
//    if((quint8)last[5]!=0x85&&(quint8)last[5]!=0x82)
//        return;
    if((quint8)last[5]==0x84)
    {
        QByteArray now_data(now);
        now_data.remove(0,7);
        now_data.remove(now_data.length()-2,2);
        if(m_local==NULL)
        {
            m_local=new XL803::LOCAL_PARA;
        }
        memcpy(m_local,now_data,sizeof(XL803::LOCAL_PARA));
    }else if((quint8)last[5]==0x82)
    {
        QByteArray now_data(now);
        now_data.remove(0,6);
        quint8 flag=*((quint8 *)now_data.data());
        now_data.remove(0,1);
        now_data.remove(now_data.length()-2,2);
        if(m_meter[flag]==NULL)
        {
            m_meter[flag]=new XL803::METER_PARA;
        }
        memcpy(m_meter[flag],now_data,sizeof(XL803::METER_PARA));
        if(flag==2)
        {
            emit set_constp();
        }
    }else if((quint8)last[5]==0x47)
    {
        QByteArray now_data(now);
        now_data.remove(0,6);
        float i[5]={0};
        memcpy(i,now_data,sizeof(float)*5);
        now_data.remove(now_data.length()-2,2);
        i2_ratio=i[0];
        i3_ratio=i[1];
        i4_ratio=i[2];
        i1_ratio=i[3];
        if(now_data.length()>sizeof(float)*4)
        {
            i_num=i[4];
        }
    }else if((quint8)last[5]==0x81||(quint8)last[5]==0x83)
    {
        QMessageBox::information(this," ","写入成功");
    }
}

void Config_set::on_connect_dis_clicked()
{
    emit clear_list();
    if(!ui->connect_dis->text().compare("断开"))
    {
        ui->connect_dis->setText("连接");
        emit disconect_com();
        set_enable(true);
    }else
    {
        ui->connect_dis->setText("断开");
        emit connect_com();
        set_enable(false);
    }
}
void Config_set::btn_reset()
{
    ui->connect_dis->setText("连接");
    ui->connect_dis->setChecked(false);
    set_enable(true);
}
void Config_set::btn_net_reset()
{
    ui->net_connect->setText("连接");
    ui->net_connect->setChecked(false);
    set_net_enable(true);
}
int Config_set::get_com_count()
{
    return com_list.count();
}


float Config_set::get_i1()
{
    return i1_ratio;
}
float Config_set::get_i2()
{
    return i2_ratio;
}
float Config_set::get_i3()
{
    return i3_ratio;
}
float Config_set::get_i4()
{
    return i4_ratio;
}
void Config_set::set_connect_state()
{
     ui->connect_dis->setText("断开");
     set_enable(true);
}
void Config_set::set_enable(bool flag)
{
    ui->com_name->setEnabled(flag);
    ui->check_byte->setEnabled(flag);
    ui->baud->setEnabled(flag);
    ui->stop_byte->setEnabled(flag);
}
void Config_set::information()
{
    QMessageBox::information(this," ","未连接到串口!");
}
bool Config_set::is_serial()
{
    return ui->serial->isChecked();
}

void Config_set::on_net_connect_clicked()
{
    emit clear_list();
    if(ui->net_connect->text().compare("断开")==0)
    {
        ui->net_connect->setText("连接");
        emit net_disconnect();
       set_net_enable(true);
    }else
    {
        emit net_connect();
        unsigned char  dest[6];
        QByteArray data;
        xl609->StringToHex(ui->mac->text(),data);
        dest[0]=(unsigned char)data.at(0);
        xl609->StringToHex(ui->mac_2->text(),data);
        dest[1]=(unsigned char)data.at(0);
        xl609->StringToHex(ui->mac_3->text(),data);
        dest[2]=(unsigned char)data.at(0);
        xl609->StringToHex(ui->mac_4->text(),data);
        dest[3]=(unsigned char)data.at(0);
        xl609->StringToHex(ui->mac_5->text(),data);
        dest[4]=(unsigned char)data.at(0);
        xl609->StringToHex(ui->mac_6->text(),data);
        dest[5]=(unsigned char)data.at(0);
        unsigned char  src[6]={0x22,0x33,0x44,0x55,0x66,0x77};
        //P_NET->update_mesg_mac();
        //qDebug()<<P_NET->get_name().at(ui->desc->value()).toLatin1();
        P_NET->SetDev_ex(P_NET->get_name().at(ui->desc->value()).toLatin1().data(),src,dest,1);
        P_NET->start_read();
        ui->net_connect->setText("断开");
        set_net_enable(false);
    }
}
void Config_set::set_net_enable(bool flag)
{
    ui->desc->setEnabled(flag);
    ui->mac->setEnabled(flag);
    ui->mac_2->setEnabled(flag);
    ui->mac_3->setEnabled(flag);
    ui->mac_4->setEnabled(flag);
    ui->mac_5->setEnabled(flag);
    ui->mac_6->setEnabled(flag);
//    ui->out_time->setEnabled(flag);
//    ui->cpu_version->setEnabled(flag);
//    ui->set_mac->setEnabled(flag);
//    ui->reset_cpu->setEnabled(flag);
}
void Config_set::set_all_enable(int index)
{
    if(ui->serial->isChecked())
    {
        if(ui->connect_dis->text().compare("断开")==0)
            return;
        set_enable(true);
        if(ui->net_connect->text().compare("断开")==0)
            ui->net_connect->click();
        ui->net_connect->setEnabled(false);
        ui->connect_dis->setEnabled(true);
        set_net_enable(false);
    }else
    {
        if(ui->net_connect->text().compare("断开")==0)
            return;
        set_net_enable(true);
        if(ui->connect_dis->text().compare("断开")==0)
            ui->connect_dis->click();
        ui->connect_dis->setEnabled(false);
        ui->net_connect->setEnabled(true);
        set_enable(false);
    }
}

void Config_set::on_mac_textChanged(const QString &arg1)
{
    if(arg1.length()==2)
    {
        ui->mac_2->setFocus();
        ui->mac_2->selectAll();
    }
}

void Config_set::on_mac_2_textChanged(const QString &arg1)
{
    if(arg1.length()==2)
    {
        ui->mac_3->setFocus();
        ui->mac_3->selectAll();
    }
}

void Config_set::on_mac_3_textChanged(const QString &arg1)
{
    if(arg1.length()==2)
    {
        ui->mac_4->setFocus();
        ui->mac_4->selectAll();
    }
}

void Config_set::on_mac_4_textChanged(const QString &arg1)
{
    if(arg1.length()==2)
    {
        ui->mac_5->setFocus();
        ui->mac_5->selectAll();
    }
}

void Config_set::on_mac_5_textChanged(const QString &arg1)
{
    if(arg1.length()==2)
    {
        ui->mac_6->setFocus();
        ui->mac_6->selectAll();
    }
}



void Config_set::on_com_name_currentIndexChanged(const QString &arg1)
{
    if(init==false)
        return;
    if(arg1.compare("刷新")==0)
    {
        com_list.clear();
        ui->com_name->clear();
        foreach (const QSerialPortInfo &qspinfo, QSerialPortInfo::availablePorts())
        {
            ui->com_name->addItem(qspinfo.portName());
            com_list<<qspinfo;
        }
        if(ui->com_name->count()>0)
            ui->com_name->setCurrentIndex(0);
        ui->com_name->addItem("刷新");
    }
}

void Config_set::on_pushButton_clicked()
{
    out_time_value=ui->spinBox->value();
}

void Config_set::on_btn_close_clicked()
{
    if(QMessageBox::warning(this, "警告", "是否确定退出程序！",\
      QMessageBox::Yes | QMessageBox::No, QMessageBox::No)==QMessageBox::Yes)
    {
        emit close_me();
    }
}

void Config_set::on_reset_window_clicked()
{
    emit set_window();
}

void Config_set::on_read_gear_clicked()
{
    xl609->read_all_set(XL803::Config_set);
}

void Config_set::on_init_cpu_clicked()
{
    xl609->reset_cpu(XL803::Config_set);
}
