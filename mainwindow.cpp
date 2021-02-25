#include "mainwindow.h"
#include "ui_mainwindow.h"

bool MainWindow::connect_flag=false;
bool MainWindow::net_flag=false;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //添加各个界面
    //创建对象指针，将对象指针添加到tabWidget中
    p_config_set=new Config_set();
    p_base_out=new m_base_out();
    p_hrenter=new Hrenter_out();
    p_any_wave=new Any_wave();
    p_active_wave=new active_wave();
    //p_adjust_energy=new adjust_energy();
    p_reout_wave    =new reout_wave();
    p_wave_reout =new Wave_reout();
   // p_power_test=new power_test();
    //p_test_bll=new test_bll();
    ui->tabWidget->addTab(p_base_out,tr("基波输出"));
    ui->tabWidget->addTab(p_hrenter,tr("谐波输出"));
    //ui->tabWidget->addTab(p_power_test,tr("电池测试"));
    //ui->tabWidget->addTab(p_any_wave,tr("任意波形"));
    ui->tabWidget->addTab(p_active_wave,tr("动态波"));
    ui->tabWidget->addTab(p_reout_wave,tr("录波回放"));
    ui->tabWidget->addTab(p_wave_reout,tr("长录波回放"));
    //ui->tabWidget->addTab(p_adjust_energy,tr("校准"));
    ui->tabWidget->addTab(p_config_set,tr("通讯设置"));
    //ui->tabWidget->addTab(p_test_bll,tr("test"));

    ui->tabWidget->tabBar()->setStyleSheet("font: 14pt '宋体';");
    board=new QPushButton(this);
    board->setText("键盘");
    m_net_flag=false;
    m_pSeriThread = new QThread(this);
    m_pDevSeri = new SerialEx(0);
    m_pNetThread= new QThread(this);
    qRegisterMetaType<XL803::PAGE>("XL803::PAGE");
    m_pDevSeri->moveToThread(m_pSeriThread);
    connect(p_wave_reout,SIGNAL(send_out(QString)),P_NET,SLOT(send_byte(QString)),Qt::QueuedConnection);
    connect(p_wave_reout,SIGNAL(start_read()),P_NET,SLOT(formula_send()),Qt::QueuedConnection);

    connect(P_NET,SIGNAL(send_over()),p_wave_reout,SLOT(recv_over()),Qt::QueuedConnection);
    connect(p_wave_reout,SIGNAL(send_stop()),P_NET,SLOT(recv_stop()),Qt::QueuedConnection);
    connect(P_NET,SIGNAL(send_index(int)),p_wave_reout,SLOT(recv_index(int)),Qt::QueuedConnection);

    connect(L_XL803,SIGNAL(sendToPort(const QByteArray &,quint32,XL803::PAGE)),\
            m_pDevSeri,SLOT(portWrite(const QByteArray &,quint32,XL803::PAGE)));
    connect(m_pDevSeri,SIGNAL(portReaded(const QByteArray &,const QByteArray &,XL803::PAGE)),\
            L_XL803,SLOT(readFromPort(const QByteArray &,const QByteArray &,XL803::PAGE)));
    connect(m_pDevSeri,SIGNAL(send_error(QByteArray)),this,SLOT(error_mesg(QByteArray)));

    connect(m_pDevSeri,SIGNAL(recv_time_out()),this,SLOT(recv_time_out()));
    connect(P_NET,SIGNAL(recv_time_out()),this,SLOT(recv_time_out()));

    connect(this,SIGNAL(linkDevSeri(bool)),m_pDevSeri,SLOT(linkToCom(bool)));
    connect(this,SIGNAL(close_com()),m_pDevSeri,SLOT(m_close()));

    connect(p_config_set,SIGNAL(net_connect()),this,SLOT(connect_net()));
    connect(p_config_set,SIGNAL(net_disconnect()),this,SLOT(disconnect_net()));
    connect(board,SIGNAL(clicked(bool)),this,SLOT(show_keyboard(bool)));
    //  config_set界面发来信号，触发 con_com()槽函数，连接串口
    connect(p_config_set,SIGNAL(connect_com()),this,SLOT(con_com()));
    connect(p_config_set,SIGNAL(clear_list()),this,SLOT(clear_list()));
    connect(p_config_set,SIGNAL(disconect_com()),this,SLOT(dis_com()));
    //  config_set界面发来信号，触发 m_close（）槽函数,关闭程序
    connect(p_config_set,SIGNAL(close_me()),this,SLOT(m_close()));

    connect(L_XL803,SIGNAL(send_to_main(QByteArray,QByteArray)),this,SLOT(recv_mesg(QByteArray,QByteArray)));
    connect(p_config_set,SIGNAL(m_reset()),this,SLOT(reset_size()));
    m_pSeriThread->start();
    timer=new QTimer;
    net_timer=new QTimer;
    connect(net_timer, SIGNAL(timeout()), this, SLOT(test_net_connect()));
    connect(timer, SIGNAL(timeout()), this, SLOT(test_connect()));

    if(p_config_set->get_com_count()<=0)
    {
        QMessageBox::information(NULL," ","检测不到串口!");
        p_config_set->btn_reset();
    }else
    {
        //link(true);
    }
    p_config_set->m_connect();
    board->setFocusPolicy(Qt::NoFocus);

}
void MainWindow::recv_time_out()
{
    QMessageBox::information(this,"提示","响应超时，请检查通讯设置!");
}
//连接串口
void MainWindow::link(bool sel)
{
    if(p_config_set->get_com_count()<=0)
    {
        QMessageBox::information(NULL," ","检测不到串口!");
        p_config_set->btn_reset();
        return;
    }
    m_pDevSeri->setPort(p_config_set->get_com());
    m_pDevSeri->setBaudRate(p_config_set->get_bound(),QSerialPort::AllDirections);
    m_pDevSeri->setDataBits(QSerialPort::Data8);//数据位
    m_pDevSeri->setParity(p_config_set->get_parity());
    m_pDevSeri->setStopBits(p_config_set->get_stop_byte());
    emit linkDevSeri(sel);
    timer->start(Config_set::out_time_value*1000);
    L_XL803->test_connet(XL803::MAIN);
}
MainWindow::~MainWindow()
{
    m_pSeriThread->quit();
    m_pNetThread->quit();
    delete ui;
}
//连接串口
void MainWindow::con_com()
{
    connect(L_XL803,SIGNAL(sendToPort(const QByteArray &,quint32,XL803::PAGE)),\
            m_pDevSeri,SLOT(portWrite(const QByteArray &,quint32,XL803::PAGE)),Qt::QueuedConnection);
    connect(m_pDevSeri,SIGNAL(portReaded(const QByteArray &,const QByteArray &,XL803::PAGE)),\
            L_XL803,SLOT(readFromPort(const QByteArray &,const QByteArray &,XL803::PAGE)),Qt::QueuedConnection);
    connect(m_pDevSeri,SIGNAL(send_error(QByteArray)),this,SLOT(error_mesg(QByteArray)));
    link(true);
}
void MainWindow::dis_com()
{
    disconnect(L_XL803,SIGNAL(sendToPort(const QByteArray &,quint32,XL803::PAGE)),\
            m_pDevSeri,SLOT(portWrite(const QByteArray &,quint32,XL803::PAGE)));
    disconnect(m_pDevSeri,SIGNAL(portReaded(const QByteArray &,const QByteArray &,XL803::PAGE)),\
            L_XL803,SLOT(readFromPort(const QByteArray &,const QByteArray &,XL803::PAGE)));
    disconnect(m_pDevSeri,SIGNAL(send_error(QByteArray)),this,SLOT(error_mesg(QByteArray)));
    MainWindow::connect_flag=false;
    timer->stop();
    emit close_com();
}
void  MainWindow::recv_mesg(const QByteArray last, const QByteArray now)
{
    if((quint8)last[5]==0x14)
    {
        timer->stop();
        if(m_net_flag)
            MainWindow::net_flag=true;
        MainWindow::connect_flag=true;
        net_timer->stop();
        L_XL803->get_dma_freq(XL803::ANY_WAVE);
        L_XL803->get_dma_freq(XL803::ACTIVE_WAVE);
        L_XL803->read_max_reout_wave_lenth(XL803::REOUT_WAVE);
        if(ui->tabWidget->currentIndex()==5)
        {
            QMessageBox *box = new QMessageBox(QMessageBox::Information,tr("提示"),tr("连接成功！"),0,this);
            QTimer::singleShot(1500,box,SLOT(accept()));
            box->exec();
        }
    }
}
void MainWindow::test_connect()
{
    timer->stop();
    m_pDevSeri->clear_list();
//    QMessageBox::information(this," ","连接超时，串口无响应!");
    p_config_set->btn_reset();
    MainWindow::connect_flag=false;
    dis_com();
    emit close_com();
}
void MainWindow::test_net_connect()
{
    net_timer->stop();
    //return;
    P_NET->clear_list();
//    QMessageBox *box = new QMessageBox(QMessageBox::Information,tr("提示"),tr("连接超时，网口无响应!"),0,this);
//    QTimer::singleShot(1500,box,SLOT(accept()));
//    box->exec();
    p_config_set->btn_net_reset();
    MainWindow::connect_flag=false;
    MainWindow::net_flag=false;
    m_net_flag=false;
    disconnect_net();
}
void MainWindow::clear_list()
{
    m_pDevSeri->clear_list();
}

void MainWindow::show_keyboard(bool)
{
    Key_board_dlg *k=Key_board_dlg::get_key_board(this);
    k->setFocusPolicy(Qt::NoFocus);
    QWidget *current_focus_w = this->focusWidget();
    //k->move();
    k->show();
    this->activateWindow();
}
void MainWindow::resizeEvent(QResizeEvent * event)
{
    QSize size=event->size();
    float now_size=size.width()/7.5;
    ui->tabWidget->tabBar()->setStyleSheet(QString("QTabBar::tab{width:%1;font: 14pt '宋体';}").arg(now_size));
    board->move(size.width()-board->width(),size.height()-board->height());
    board->update();
}

void MainWindow::connect_net()
{
    m_net_flag=true;
    P_NET->clear_list();
    connect(L_XL803,SIGNAL(sendToPort(const QByteArray &,quint32,XL803::PAGE)),\
            P_NET,SLOT(portWrite(QByteArray,quint32,XL803::PAGE)),Qt::QueuedConnection);
    connect(P_NET,SIGNAL(portReaded(QByteArray,QByteArray,XL803::PAGE)),\
            L_XL803,SLOT(readFromPort(const QByteArray &,const QByteArray &,XL803::PAGE)),Qt::QueuedConnection);
    connect(P_NET,SIGNAL(send_error(QByteArray)),this,SLOT(error_mesg(QByteArray)));
    L_XL803->test_connet(XL803::MAIN);
    net_timer->start(Config_set::out_time_value*1000);
}
void MainWindow::disconnect_net()
{
    disconnect(L_XL803,SIGNAL(sendToPort(const QByteArray &,quint32,XL803::PAGE)),\
            P_NET,SLOT(portWrite(const QByteArray &,quint32,XL803::PAGE)));
    disconnect(P_NET,SIGNAL(portReaded(const QByteArray &,const QByteArray &,XL803::PAGE)),\
            L_XL803,SLOT(readFromPort(const QByteArray &,const QByteArray &,XL803::PAGE)));
    disconnect(P_NET,SIGNAL(send_error(QByteArray)),this,SLOT(error_mesg(QByteArray)));
    MainWindow::connect_flag=false;
    MainWindow::net_flag=false;
    m_net_flag=false;
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
void MainWindow::m_close()
{
    //  发送 close_m信号到main.cpp
    emit close_m();
}
void MainWindow::changeEvent(QEvent* event)
{
    if(event->type()!=QEvent::WindowStateChange) return;
    if(this->windowState()==Qt::WindowMaximized)
    {
        setWindowState(Qt::WindowFullScreen);
    }
}
void MainWindow::reset_size()
{
    setWindowState(Qt::WindowNoState);
}
