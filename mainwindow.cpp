#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //setWindowState(Qt::WindowFullScreen);
    //resize(800,600);
    ui->label_2->hide();
    ui->connect_mode->hide();
    ui->label_4->hide();
    ui->connect_net->hide();
    //设置输出电流最大值为10A
    ui->output_ele->setMaximum(12);
    //串口
    m_pSeriThread = new QThread(this);
    m_pDevSeri = new SerialEx(0);
    m_pNetThread= new QThread(this);
    qRegisterMetaType<XL803::PAGE>("XL803::PAGE");
    m_pDevSeri->moveToThread(m_pSeriThread);
    m_pSeriThread->start();
    //创建定时器对象
    timer=new QTimer;
    net_timer=new QTimer;
    //连接超时
    connect(net_timer, SIGNAL(timeout()), this, SLOT(test_net_connect()));
    connect(timer, SIGNAL(timeout()), this, SLOT(test_connect()));
    connect(m_pDevSeri,SIGNAL(recv_time_out()),this,SLOT(recv_time_out()));
    //连接成功
    connect(m_pDevSeri,SIGNAL(portConnected()),this,SLOT(getConnected()));
    //查找可用串口信息
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        ui->connect_serial->addItem(info.portName());
        // 把端口信息存在QList中
        com_list<<info;
    }
    //连接串口
    connect(this,SIGNAL(linkDevSeri(bool)),m_pDevSeri,SLOT(linkToCom(bool)));
    //断开串口
    connect(this,SIGNAL(close_com()),m_pDevSeri,SLOT(m_close()));
    connect(L_XL803,SIGNAL(send_to_main(QByteArray,QByteArray)),this,SLOT(recv_mesg(QByteArray,QByteArray)));
    xl609 = L_XL803;
    ui->output_hz->setValidator(new QDoubleValidator(0,2000,1));
    ui->rated_value->setValidator(new QDoubleValidator(0,10,1));
    ui->connect_bt->click();
    if(ui->output_mode->currentText()=="交流电流")
        ui->output_hz->setEnabled(true);
    else
        ui->output_hz->setEnabled(false);

}
void MainWindow::changeEvent(QEvent* event)
{
    if(event->type()!=QEvent::WindowStateChange) return;
    if(this->windowState()==Qt::WindowMaximized)
    {
        setWindowState(Qt::WindowFullScreen);
    }
}
MainWindow::~MainWindow()
{
    m_pSeriThread->quit();
    m_pNetThread->quit();
    delete ui;
}
void  MainWindow::recv_mesg(const QByteArray last, const QByteArray now)
{
    if((quint8)last[5]==0x14)
    {
        timer->stop();
    }
}
void MainWindow::getConnected()
{
    //QMessageBox::information(this,"提示","连接成功!");
}
void MainWindow::recv_time_out()
{
    QMessageBox::information(this,"提示","响应超时，请检查通讯设置!");
}
//通信连接
void MainWindow::on_connect_bt_clicked()
{
    clear_list();
    //如果已经连接，断开；如果未连接，那么连接
    if(!ui->connect_bt->text().compare("断开"))
    {
        ui->connect_bt->setText("连接");
        if(!ui->connect_mode->currentText().compare("串口连接"))
             disconect_com();
        else
             disconect_net();
        //可以进行通讯设置
        set_enable(true);
    }else
    {
        ui->connect_bt->setText("断开");

        if(!ui->connect_mode->currentText().compare("串口连接"))
            //连接串口
            connect_com();
        else
            connect_net();
        //无法设置
        set_enable(false);
    }
}
//启动输出
void MainWindow::on_start_bt_clicked()
{
    //输出类型
    output_mode = ui->output_mode->currentText();
    //输出电流
    output_ele = ui->output_ele->value();
    //频率
    freq = ui->output_hz->currentText().toFloat();
    if(freq>2000)
    {
        QMessageBox::information(this,"提示","最大频率为2000HZ");
        return;
    }
    QMap<XL803::MARKERB,qint32> para;
    QMap<XL803::MARKERB,qint32> para_start;
    para.insert(XL803::MARKERB_UA,xl609->float_to_quint((float)output_ele));
    para.insert(XL803::MARKERB_UAP,0);
    para.insert(XL803::MARKERB_FA,xl609->float_to_quint(freq));
    para.insert(XL803::MARKERB_DUA,0x55);
    if(output_mode=="直流电流")
    {
        para.insert(XL803::MARKERB_WT_UA,0x03);
        qDebug()<<"直流"<<output_ele<<" "<<freq;
    }
    else
    {
        if(ui->waveSet->currentText()=="正弦波")
            para.insert(XL803::MARKERB_WT_UA,0x00);
        else
            para.insert(XL803::MARKERB_WT_UA,0x01);
        qDebug()<<"交流"<<output_ele<<" "<<freq;
    }
    para.insert(XL803::DCBias1,0);

    para_start.insert(XL803::MARKERB_SUA,0x01);

    xl609->COM_HightWrite(para,XL803::MAIN);
    xl609->COM_StartUp(para_start,XL803::MAIN);

}
//停止输出
void MainWindow::on_stop_bt_clicked()
{
    QMap<XL803::MARKERB,qint32> para_stop;
    para_stop.insert(XL803::MARKERB_EUA,0x01);
    xl609->COM_Stop(para_stop,XL803::MAIN);
}
//通讯设置
void MainWindow::set_enable(bool flag)
{
    ui->connect_serial->setEnabled(flag);
    ui->connect_mode->setEnabled(flag);
    ui->connect_net->setEnabled(flag);
}
void MainWindow::connect_com()
{
    //关联写、读、报错
    connect(L_XL803,SIGNAL(sendToPort(const QByteArray &,quint32,XL803::PAGE)),\
            m_pDevSeri,SLOT(portWrite(const QByteArray &,quint32,XL803::PAGE)),Qt::QueuedConnection);
    connect(m_pDevSeri,SIGNAL(portReaded(const QByteArray &,const QByteArray &,XL803::PAGE)),\
            L_XL803,SLOT(readFromPort(const QByteArray &,const QByteArray &,XL803::PAGE)),Qt::QueuedConnection);
    connect(m_pDevSeri,SIGNAL(send_error(QByteArray)),this,SLOT(error_mesg(QByteArray)));

    link(true);
}

void MainWindow::disconect_net()
{

}
//连接串口
void MainWindow::link(bool sel)
{
    if(ui->connect_serial->currentText().isEmpty())
    {
        QMessageBox::information(NULL," ","检测不到串口!");
        ui->connect_bt->setText("连接");
        set_enable(true);

        return;
    }
    m_pDevSeri->setPort(get_com());
    m_pDevSeri->setBaudRate(QSerialPort::Baud57600,QSerialPort::AllDirections);
    m_pDevSeri->setDataBits(QSerialPort::Data8);//数据位
    m_pDevSeri->setParity(QSerialPort::NoParity);
    m_pDevSeri->setStopBits(QSerialPort::OneStop);
    emit linkDevSeri(sel);
    timer->start(5*1000);
    L_XL803->test_connet(XL803::MAIN);

}
//获取串口
QSerialPortInfo MainWindow::get_com()
{
    int index=ui->connect_serial->currentIndex();
    if((index<0||index>com_list.count())&&(ui->connect_serial->count()>1))
    {
        return com_list[0];
    }else
    {
        return com_list[index];
    }
}
void MainWindow::test_connect()
{
    timer->stop();
    m_pDevSeri->clear_list();
    //QMessageBox::information(this," ","连接超时，串口无响应!");
    ui->connect_bt->setText("连接");
    ui->connect_bt->setChecked(false);
    set_enable(true);
    //MainWindow::connect_flag=false;
    disconect_com();
    emit close_com();
}
//超时
void MainWindow::test_net_connect()
{

}
void MainWindow::disconect_com()
{
    disconnect(L_XL803,SIGNAL(sendToPort(const QByteArray &,quint32,XL803::PAGE)),\
            m_pDevSeri,SLOT(portWrite(const QByteArray &,quint32,XL803::PAGE)));
    disconnect(m_pDevSeri,SIGNAL(portReaded(const QByteArray &,const QByteArray &,XL803::PAGE)),\
            L_XL803,SLOT(readFromPort(const QByteArray &,const QByteArray &,XL803::PAGE)));
    disconnect(m_pDevSeri,SIGNAL(send_error(QByteArray)),this,SLOT(error_mesg(QByteArray)));
//    MainWindow::connect_flag=false;
    timer->stop();
    emit close_com();
}
void MainWindow::connect_net()
{

}
void MainWindow::error_mesg(QByteArray data)
{
    QString err;
    data.remove(0,6);
    quint8 pipe=*((quint8 *)data.data());
    data.remove(0,1);
    quint32 err_type=*((quint32 *)(data.data()));
    switch(pipe)
    {
        case 17:
            err="A相电压";
            break;
        case 18:
            err="B相电压";
            break;
        case 19:
            err="C相电压";
            break;
        case 122:
            err="D相电压";
            break;
        case 123:
            err="A1相电压";
            break;
        case 124:
            err="B1相电压";
            break;
        case 125:
            err="C1相电压";
            break;
        case 126:
            err="D1相电压";
            break;
        case 20:
            err="A相电流";
            break;
        case 21:
            err="B相电流";
            break;
        case 22:
            err="C相电流";
            break;
        case 127:
            err="D相电流";
            break;
        case 128:
            err="A1相电流";
            break;
        case 129:
            err="B1相电流";
            break;
        case 130:
            err="C1相电流";
            break;
        case 131:
            err="D1相电流";
            break;
        case 23:
            if(err_type==1)
            {
                QMessageBox::information(this,"警告","电源异常!");
                return;
            }
        default:
            err=QString("错误号%1").arg(pipe);
            break;
     }
    switch (err_type)
    {
        case 1:
            err.append("过载!");
            break;
        case 2:
            err.append("开路/短路!");
            break;
        case 3:
            err.append("震荡");
            break;
        case 4:
            err.append("波形溢出（超出范围）!");
            break;
        case 5:
            err.append("过热!");
            break;
        case 6:
            err.append("设备故障!");
            break;
        case 7:
            err.append("电源异常!");
            break;
        default:
            err.append(QString("错误类型:%1").arg(err_type));
            break;
    }
    QMessageBox::information(this,"警告",err);
}
void MainWindow::clear_list()
{
    m_pDevSeri->clear_list();
}
void MainWindow::on_p_1_clicked()
{
    double ele_value = ui->rated_value->currentText().remove("A").toDouble();
    ele_value = ele_value*0.01;
    output_ele = ele_value;
    qDebug()<<output_ele;
    ui->output_ele->setValue(output_ele);
}
void MainWindow::on_p_5_clicked()
{
    double ele_value = ui->rated_value->currentText().remove("A").toDouble();
    ele_value = ele_value*0.05;
    output_ele = ele_value;
    qDebug()<<output_ele;
    ui->output_ele->setValue(output_ele);
}

void MainWindow::on_p_10_clicked()
{
    double ele_value = ui->rated_value->currentText().remove("A").toDouble();
    ele_value = ele_value*0.1;
    output_ele = ele_value;
    qDebug()<<output_ele;
    ui->output_ele->setValue(output_ele);
}

void MainWindow::on_p_20_clicked()
{
    double ele_value = ui->rated_value->currentText().remove("A").toDouble();
    ele_value = ele_value*0.2;
    output_ele = ele_value;
    qDebug()<<output_ele;
    ui->output_ele->setValue(output_ele);
}

void MainWindow::on_p_50_clicked()
{
    double ele_value = ui->rated_value->currentText().remove("A").toDouble();
    ele_value = ele_value*0.5;
    output_ele = ele_value;
    qDebug()<<output_ele;
    ui->output_ele->setValue(output_ele);
}

void MainWindow::on_p_80_clicked()
{
    double ele_value = ui->rated_value->currentText().remove("A").toDouble();
    ele_value = ele_value*0.8;
    output_ele = ele_value;
    qDebug()<<output_ele;
    ui->output_ele->setValue(output_ele);
}

void MainWindow::on_p_100_clicked()
{
    double ele_value = ui->rated_value->currentText().remove("A").toDouble();
    ele_value = ele_value*1;
    output_ele = ele_value;
    qDebug()<<output_ele;
    ui->output_ele->setValue(output_ele);
}

void MainWindow::on_p_120_clicked()
{
    double ele_value = ui->rated_value->currentText().remove("A").toDouble();
    ele_value = ele_value*1.2;
    output_ele = ele_value;
    qDebug()<<output_ele;
    ui->output_ele->setValue(output_ele);
}

void MainWindow::on_key_borad_clicked()
{
//    int state=0;
//    if(ui->output_ele->hasFocus())
//       state = 1;
//    Key_board_dlg *k=Key_board_dlg::get_key_board(this);
//    k->setFocusPolicy(Qt::NoFocus);
//    QWidget *current_focus_w = this->focusWidget();
//    k->show();
//    this->activateWindow();
//    if(state==1)
//        ui->output_ele->setFocus();
    Key_board_dlg *k=Key_board_dlg::get_key_board(this);
    k->setFocusPolicy(Qt::NoFocus);
    QWidget *current_focus_w = this->focusWidget();
    //k->move();
    k->show();
    this->activateWindow();

}

void MainWindow::on_a1A_clicked()
{
    output_ele = ui->output_ele->value();
    output_ele += 1;
    ui->output_ele->setValue(output_ele);
}


void MainWindow::on_s1A_clicked()
{
    output_ele = ui->output_ele->value();
    output_ele -= 1;
    qDebug()<<"output_ele"<<output_ele;
    ui->output_ele->setValue(output_ele);
}

void MainWindow::on_a01A_clicked()
{
    output_ele = ui->output_ele->value();
    output_ele += 0.1;
    ui->output_ele->setValue(output_ele);
}

void MainWindow::on_s01A_clicked()
{
    output_ele = ui->output_ele->value();
    output_ele -= 0.1;
    ui->output_ele->setValue(output_ele);
}

void MainWindow::on_a001A_clicked()
{
    output_ele = ui->output_ele->value();
    output_ele += 0.01;
    ui->output_ele->setValue(output_ele);
}

void MainWindow::on_s001A_clicked()
{
    output_ele = ui->output_ele->value();
    output_ele -= 0.01;
    ui->output_ele->setValue(output_ele);
}

void MainWindow::on_a0001A_clicked()
{
    output_ele = ui->output_ele->value();
    output_ele += 0.001;
    ui->output_ele->setValue(output_ele);
}

void MainWindow::on_s0001A_clicked()
{
    output_ele = ui->output_ele->value();
    output_ele -= 0.001;
    ui->output_ele->setValue(output_ele);
}

void MainWindow::on_quit_bt_clicked()
{
    emit send_close();
}

void MainWindow::on_smallbt_clicked()
{
    if(ui->smallbt->text()=="窗口化")
    {
        setWindowState(Qt::WindowNoState);
        ui->smallbt->setText("全屏");
    }
    else
    {
        setWindowState(Qt::WindowFullScreen);
        ui->smallbt->setText("窗口化");
    }
}



void MainWindow::on_output_mode_currentTextChanged(const QString &arg1)
{
    if(arg1=="交流电流")
    {
        ui->output_hz->setEnabled(true);
        ui->output_ele->setRange(0.0000,12.0000);
    }
    else
    {
       ui->output_hz->setEnabled(false);
       ui->output_ele->setRange(-12.0000,12.0000);
    }
}
