#include "config_set.h"
#include "ui_config_set.h"
int Config_set::out_time_value=12;
bool Config_set::flag = false;
bool Config_set::serFlag = false;
Config_set::Config_set(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Config_set)
{
    ui->setupUi(this);
    //初始化
    initConfig();
}

Config_set::~Config_set()
{
    delete ui;
}
void Config_set::initConfig()
{
    init=false;
    //com端口
    foreach (const QSerialPortInfo &qspinfo, QSerialPortInfo::availablePorts())
    {
      ui->com_name->addItem(qspinfo.portName());
      com_list<<qspinfo;
    }
    ui->com_name->addItem("刷新");
    //波特率
    QVector<QString> items;
    items<<"57600"<<"38400"<<"9600";
    ui->baud->setRange(0,2);
    ui->baud->set_items(items);
    items.clear();
    //校验位
    ui->check_byte->setRange(0,2);
    items<<"偶校验"<<"奇校验"<<"无校验";
    ui->check_byte->set_items(items);
    ui->check_byte->setValue(2);
    items.clear();
    //停止位
    items<<"2位"<<"1.5位"<<"1位";
    ui->stop_byte->setRange(0,2);
    ui->stop_byte->set_items(items);
    ui->stop_byte->setValue(2);
    items.clear();
    //实例化数据处理类
    xl609=L_XL803;
    //电能表脉冲结构体
    m_meter[meter1]=NULL;
    m_meter[meter2]=NULL;
    m_meter[meter3]=NULL;
    //本机脉冲结构体
    m_local=NULL;
    //显示星龙logo
    ui->label_5->setStyleSheet("QLabel{border-image:url(:./png/logo.png);}");
    //限制MAC地址的输入
    QRegExp rx("^(\\d|([a,b,c,d,e,f,A,B,C,D,E,F]))(\\d|([a,b,c,d,e,f,A,B,C,D,E,F]))$");
    ui->mac->setValidator(new QRegExpValidator(rx, this));
    ui->mac_2->setValidator(new QRegExpValidator(rx, this));
    ui->mac_3->setValidator(new QRegExpValidator(rx, this));
    ui->mac_4->setValidator(new QRegExpValidator(rx, this));
    ui->mac_5->setValidator(new QRegExpValidator(rx, this));
    ui->mac_6->setValidator(new QRegExpValidator(rx, this));
    //获取从下位机发送来的消息
    connect(xl609,SIGNAL(send_to_config(QByteArray,QByteArray)),this,SLOT(recv_mesg(QByteArray,QByteArray)));
    //点击按钮后作出相应的设置
    connect(ui->buttonGroup,SIGNAL(buttonClicked(int)),this,SLOT(set_all_enable(int)));
    //小信号通道的值
    i2_ratio=1;
    i3_ratio=1;
    i4_ratio=1;
    i1_ratio=1;
    i_num=1;
    //设置网卡
    ui->desc->set_items(P_NET->get_desc());
    //连接串口
    ui->serial->click();
    set_enable(false);
    ui->connect_dis->setChecked(true);
    ui->connect_dis->setText("断开");
    init=true;

    ui->label_4->hide();
    ui->cpu_version->hide();
    ui->set_mac->hide();
    ui->reset_cpu->hide();
    //保存配置信息
    QSettings Settings("XL","9201");
    Settings.value("connect_type",QVariant(0));
    Settings.value("path",QVariant("./"));
    ui->desc->set_text(Settings.value("desc",QVariant(ui->desc->text())).toString());
    ui->mac->setText(Settings.value("mac",QVariant(ui->mac->text())).toString());
    ui->mac_2->setText(Settings.value("mac2",QVariant(ui->mac_2->text())).toString());
    ui->mac_3->setText(Settings.value("mac3",QVariant(ui->mac_3->text())).toString());
    ui->mac_4->setText(Settings.value("mac4",QVariant(ui->mac_4->text())).toString());
    ui->mac_5->setText(Settings.value("mac5",QVariant(ui->mac_5->text())).toString());
    ui->mac_6->setText(Settings.value("mac6",QVariant(ui->mac_6->text())).toString());
    ui->com_name->setCurrentText(Settings.value("com_name",QVariant(ui->com_name->currentText())).toString());
    ui->baud->set_text(Settings.value("baud",QVariant(ui->baud->text())).toString());
    ui->check_byte->set_text(Settings.value("check_byte",QVariant(ui->check_byte->text())).toString());
    ui->stop_byte->set_text(Settings.value("stop_byte",QVariant(ui->stop_byte->text())).toString());
    //二次开发串口界面初始化
    initSecUi();
    //隐藏二次开发串口配置界面
    hideUi();
}
void Config_set::hideUi()
{
//    ui->label_8->hide();
//    ui->frame_6->hide();
}
QSerialPortInfo Config_set::get_com()
{
    int index=ui->com_name->currentIndex();
    if((index<0||index>com_list.count())&&(ui->com_name->count()>1))
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
        return QSerialPort::UnknownBaud;
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
        return QSerialPort::UnknownParity;
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
        return QSerialPort::UnknownStopBits;
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
    return m_meter[meter_type]!=NULL?m_meter[meter_type]:0;
}
XL803::LOCAL_PARA *Config_set::get_m_local()
{
    return m_local;
}

void Config_set::initSecUi()
{
    foreach (const QSerialPortInfo &qspinfo, QSerialPortInfo::availablePorts())
    {
        ui->com_name_2->addItem(qspinfo.portName());
        com_list_2<<qspinfo.portName();
    }
    //波特率
    QVector<QString> items;
    items<<"9600"<<"38400"<<"57600";
    ui->baud_2->setRange(0,2);
    ui->baud_2->set_items(items);
    items.clear();
    //校验位
    ui->check_byte_2->setRange(0,2);
    items<<"偶校验"<<"奇校验"<<"无校验";
    ui->check_byte_2->set_items(items);
    ui->check_byte_2->setValue(2);
    items.clear();
    //停止位
    items<<"2位"<<"1.5位"<<"1位";
    ui->stop_byte_2->setRange(0,2);
    ui->stop_byte_2->set_items(items);
    ui->stop_byte_2->setValue(2);
    items.clear();
    m_serialPort = new QSerialPort();//实例化串口类一个对象
    QSettings *setting = new QSettings("./config.ini", QSettings::IniFormat);
    QString str = setting->value("nowCom").toString();
    for(int i=0;i<ui->com_name_2->count();i++)
    {
        if(ui->com_name_2->itemText(i)==str)
        {
            ui->com_name_2->setCurrentIndex(i);
            ui->connect_dis_2->click();
        }
    }
       timer = new QTimer;
}
void Config_set::send_to_read_meter_const(quint8 flag)
{
    xl609->read_meter_const(flag,XL803::Config_set);
}
void Config_set::send_to_read_local_const()
{

    xl609->read_local_const(XL803::Config_set);
}
void Config_set::recv_mesg(QByteArray last, QByteArray now)
{
    //读取本机电能表参数
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
    }else if((quint8)last[5]==0x82)//读取电能表常数
    {
        QByteArray now_data(now);
        now_data.remove(0,6);
        //脉冲输入口
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
    }else if((quint8)last[5]==0x47)//读取小信号电压对应电流的变比
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
    }else if((quint8)last[5]==0x81||(quint8)last[5]==0x83)//设置电能表参数
    {
        QMessageBox::information(this," ","写入成功");
    }
}
//串口连接
void Config_set::on_connect_dis_clicked()
{
    emit clear_list();
    //如果已经连接，断开；如果未连接，那么连接
    if(!ui->connect_dis->text().compare("断开"))
    {
        ui->connect_dis->setText("连接");
        //断开串口
        emit disconect_com();
        //可以进行通讯设置
        set_enable(true);
    }else
    {
        //保存设置信息
        QSettings Settings("XL","9201");
        Settings.setValue("connect_type",QVariant(0));
        Settings.setValue("com_name",QVariant(ui->com_name->currentText()));
        Settings.setValue("baud",QVariant(ui->baud->text()));
        Settings.setValue("check_byte",QVariant(ui->check_byte->text()));
        Settings.setValue("stop_byte",QVariant(ui->stop_byte->text()));
        ui->connect_dis->setText("断开");
        //发送连接串口信号
        emit connect_com();
        //无法设置
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
//连接网口
void Config_set::on_net_connect_clicked()
{
    //清空缓存
    emit clear_list();
    if(ui->net_connect->text().compare("断开")==0)
    {
        ui->net_connect->setText("连接");
        emit net_disconnect();
        set_net_enable(true);
    }else
    {
        QSettings Settings("XL","9201");
        Settings.setValue("connect_type",QVariant(1));
        Settings.setValue("desc",QVariant(ui->desc->text()));
        Settings.setValue("mac",QVariant(ui->mac->text()));
        Settings.setValue("mac2",QVariant(ui->mac_2->text()));
        Settings.setValue("mac3",QVariant(ui->mac_3->text()));
        Settings.setValue("mac4",QVariant(ui->mac_4->text()));
        Settings.setValue("mac5",QVariant(ui->mac_5->text()));
        Settings.setValue("mac6",QVariant(ui->mac_6->text()));
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
        P_NET->start_read();
        SetDev_ex(P_NET->get_name().at(ui->desc->value()).toLatin1().data(),src,dest,-1);
        //qDebug()<<P_NET->get_name().at(ui->desc->value());
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
    ui->byte_out->setEnabled(flag);
    ui->cpu_version->setEnabled(flag);
    ui->set_mac->setEnabled(flag);
    ui->reset_cpu->setEnabled(flag);
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
//更新设置
void Config_set::on_pushButton_clicked()
{
    Config_set::out_time_value=ui->spinBox->value();
}
//关闭程序
void Config_set::on_close_btn_clicked()
{
    if(QMessageBox::warning(this, "警告", "是否确定退出程序！",\
      QMessageBox::Yes | QMessageBox::No, QMessageBox::No)==QMessageBox::Yes)
    {
        emit close_me();
    }
}
//全屏或窗口化
void Config_set::on_reset_btn_clicked()
{
    if(ui->reset_btn->text()=="全屏")
    {
        emit m_reset(0);
        ui->reset_btn->setText("窗口化");
    }
    else
     {
        emit m_reset(1);
        ui->reset_btn->setText("全屏");
    }
}
void Config_set::on_byte_out_valueChanged(int arg1)
{
    set_out_byte_out_time(arg1);
}

void Config_set::set_connect()
{

    L_XL803->test_connet(XL803::MAIN);
}

void Config_set::m_connect()
{
//    QSettings Settings("XL","9201");
//    if(Settings.value("connect_type").toInt()==0)
//    {
//        ui->serial->click();
//        if(ui->connect_dis->text().compare("断开")==0)
//            ui->connect_dis->click();
//        ui->connect_dis->click();
//    }else
//    {
//        ui->net->click();
//        if(ui->net_connect->text().compare("断开")==0)
//            ui->net_connect->click();
//        ui->net_connect->click();
//    }
    if(ui->connect_dis->text()=="断开")
        ui->connect_dis->click();
     if(ui->serial->isChecked())
         ui->serial->click();
     if(!ui->net->isChecked())
         ui->net->click();
     if(ui->net_connect->text()=="连接")
         ui->net_connect->click();
}
void Config_set::on_setStart_clicked()
{
    LnkTargetCheck::setLnk();
}
void Config_set::on_connect_dis_2_clicked()
{
    if(ui->connect_dis_2->text()=="连接")
    {
        if(m_serialPort->isOpen())//如果串口已经打开了 先给他关闭了
        {
            m_serialPort->close();
        }
        //qDebug()<<"com_list_2[ui->com_name_2->currentIndex()]"<<com_list_2[ui->com_name_2->currentIndex()];
        m_serialPort->setPortName(com_list_2[ui->com_name_2->currentIndex()]);

        if(!m_serialPort->open(QIODevice::ReadWrite))//用ReadWrite 的模式尝试打开串口
        {
            QMessageBox::information(this,"提示","打开失败!");
            return;
        }
        else
        {

            //QMessageBox::information(this,"提示","串口连接成功!");
            serFlag = true;
            QSettings *setting = new QSettings("./config.ini", QSettings::IniFormat);
            setting->setValue("nowCom",com_list_2[ui->com_name_2->currentIndex()]);
            ui->connect_dis_2->setText("断开");
        }
        //设置波特率
//        switch (ui->baud_2->value()) {
//        case 0:
             m_serialPort->setBaudRate(QSerialPort::Baud9600,QSerialPort::AllDirections);
             m_serialPort->setDataBits(QSerialPort::Data8);		//数据位为8位
             m_serialPort->setFlowControl(QSerialPort::NoFlowControl);//无流控制
             m_serialPort->setParity(QSerialPort::NoParity);	//无校验位
             m_serialPort->setStopBits(QSerialPort::OneStop); //一位停止位
//        case 1:
//             m_serialPort->setBaudRate(QSerialPort::Baud38400,QSerialPort::AllDirections);
//             m_serialPort->setDataBits(QSerialPort::Data8);
//             m_serialPort->setParity(QSerialPort::OddParity);
//             m_serialPort->setStopBits(QSerialPort::OneAndHalfStop);
//        case 2:
//             m_serialPort->setBaudRate(QSerialPort::Baud57600,QSerialPort::AllDirections);
//             m_serialPort->setDataBits(QSerialPort::Data8);
//             m_serialPort->setParity(QSerialPort::EvenParity);
//             m_serialPort->setStopBits(QSerialPort::TwoStop);
//        default:
//             m_serialPort->setBaudRate(QSerialPort::UnknownBaud,QSerialPort::AllDirections);
//             m_serialPort->setDataBits(QSerialPort::Data8);
//             m_serialPort->setParity(QSerialPort::UnknownParity);
//             m_serialPort->setStopBits(QSerialPort::UnknownStopBits);
//        }
//        qDebug()<<"ui->baud_2->value"<<ui->baud_2->value();
            //连接信号槽 当下位机发送数据QSerialPortInfo 会发送个 readyRead 信号,我们定义个槽void receiveInfo()解析数据
            connect(m_serialPort,SIGNAL(readyRead()),this,SLOT(receiveInfo()));
//            m_serialPort->write("68 08 00 68 00 14 14 16");
    }
    else
    {  
        m_serialPort->close();
        serFlag = false;
        ui->connect_dis_2->setText("连接");

    }
}
//接受信息
void Config_set::receiveInfo(){
   spec = 50;
   timer->stop();
   timer->setSingleShot(true);
   timer->start(spec);
   //因为串口读可能出现断帧等现象，所以加了一定定时用来组帧。//如果已启动，会自己restart;
   connect(timer,SIGNAL(timeout()),this,SLOT(sloReadyRead()),Qt::DirectConnection);

}
void Config_set::sloReadyRead()
{
    QString str = QString::fromLatin1(m_serialPort->readAll());
    QStringList content;
    content = str.split("\r\n");
    if(content.at(0)=="WAVESTART")
        emit send_to_TRJ(content,1);
    else if(content.at(0)=="WAVESTOP")
        emit send_to_TRJ(content,2);
}
//发送信息
void Config_set::recvBack(bool status,int flag)
{
    if(flag == 1&&status==true)
    {
        m_serialPort->write("WAVESTARTOK\r\n");
    }
    else if(flag == 1&&status==false)
    {
        m_serialPort->write("WAVESTARTERR\r\n");
    }
    else if(flag == 2&&status==true)
    {
        m_serialPort->write("WAVESTOPOK\r\n");
    }
    else if(flag == 2&&status==false)
    {
        m_serialPort->write("WAVESTOPERR\r\n");
    }
}
