#include "mainwindow.h"
#include "ui_mainwindow.h"

bool MainWindow::connect_flag=false;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    p_state_list=new Statu_list();
    p_base_out=new m_base_out();
    p_config_set=new Config_set();
    p_list_out=new List_out();
    p_active_wave=new active_wave();
    ui->tabWidget->addTab(p_list_out,tr("调压输出"));
    ui->tabWidget->addTab(p_base_out,tr("基波输出设置"));
    ui->tabWidget->addTab(p_active_wave,tr("动态波形输出"));
    ui->tabWidget->addTab(p_state_list,tr("状态序列"));
    ui->tabWidget->addTab(p_config_set,tr("通讯设置"));
    ui->tabWidget->tabBar()->setStyleSheet("font: 14pt '宋体';");
    board=new QPushButton(this);
    board->setText("键盘");
    m_pSeriThread = new QThread(this);
    m_pDevSeri = new SerialEx(0);
    m_pNetThread= new QThread(this);
    qRegisterMetaType<XL803::PAGE>("XL803::PAGE");

    m_pDevSeri->moveToThread(m_pSeriThread);
    connect(L_XL803,SIGNAL(sendToPort(const QByteArray &,quint32,XL803::PAGE)),\
            m_pDevSeri,SLOT(portWrite(const QByteArray &,quint32,XL803::PAGE)));
    connect(m_pDevSeri,SIGNAL(portReaded(const QByteArray &,const QByteArray &,XL803::PAGE)),\
            L_XL803,SLOT(readFromPort(const QByteArray &,const QByteArray &,XL803::PAGE)));
    connect(m_pDevSeri,SIGNAL(send_error(QByteArray)),this,SLOT(error_mesg(QByteArray)));
    connect(m_pDevSeri,SIGNAL(recv_time_out()),this,SLOT(recv_time_out()));
    connect(P_NET,SIGNAL(recv_time_out()),this,SLOT(recv_time_out()));
    connect(p_config_set,SIGNAL(close_me()),this,SLOT(m_close()));
    connect(this,SIGNAL(linkDevSeri(bool)),m_pDevSeri,SLOT(linkToCom(bool)));
    connect(this,SIGNAL(close_com()),m_pDevSeri,SLOT(m_close()));
    connect(p_config_set,SIGNAL(net_connect()),this,SLOT(connect_net()));
    connect(p_config_set,SIGNAL(net_disconnect()),this,SLOT(disconnect_net()));
    connect(board,SIGNAL(clicked(bool)),this,SLOT(show_keyboard(bool)));
    connect(p_config_set,SIGNAL(connect_com()),this,SLOT(con_com()));
    connect(p_config_set,SIGNAL(clear_list()),this,SLOT(clear_list()));
    connect(p_config_set,SIGNAL(disconect_com()),this,SLOT(dis_com()));
    connect(p_config_set,SIGNAL(set_window()),this,SLOT(m_set_window()));
    connect(L_XL803,SIGNAL(send_to_main(QByteArray,QByteArray)),this,SLOT(recv_mesg(QByteArray,QByteArray)));
    connect(p_list_out,SIGNAL(show_tab_bar(bool)),this,SLOT(show_tab_bar(bool)));
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
        link(true);
    }
    board->setFocusPolicy(Qt::NoFocus);
//    float value=0;
//    for(int i=0;i<4;i++)
//    {
//        qDebug()<<*((qint8*)&value);
//    }
}
void MainWindow::recv_time_out()
{
    QMessageBox::information(this,"提示","响应超时，请检查通讯设置!");
}
void MainWindow::reset_com()
{
    // link(true);
}
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
    delete ui;
}
void MainWindow::con_com()
{
    connect(L_XL803,SIGNAL(sendToPort(const QByteArray &,quint32,XL803::PAGE)),\
            m_pDevSeri,SLOT(portWrite(const QByteArray &,quint32,XL803::PAGE)),Qt::QueuedConnection);
    connect(m_pDevSeri,SIGNAL(portReaded(const QByteArray &,const QByteArray &,XL803::PAGE)),\
            L_XL803,SLOT(readFromPort(const QByteArray &,const QByteArray &,XL803::PAGE)),Qt::QueuedConnection);
    connect(m_pDevSeri,SIGNAL(send_error(QByteArray)),this,SLOT(error_mesg(QByteArray)));
    connect(m_pDevSeri,SIGNAL(recv_time_out()),this,SLOT(recv_time_out()));
    link(true);
}
void MainWindow::dis_com()
{
    disconnect(L_XL803,SIGNAL(sendToPort(const QByteArray &,quint32,XL803::PAGE)),\
            m_pDevSeri,SLOT(portWrite(const QByteArray &,quint32,XL803::PAGE)));
    disconnect(m_pDevSeri,SIGNAL(portReaded(const QByteArray &,const QByteArray &,XL803::PAGE)),\
            L_XL803,SLOT(readFromPort(const QByteArray &,const QByteArray &,XL803::PAGE)));
    disconnect(m_pDevSeri,SIGNAL(send_error(QByteArray)),this,SLOT(error_mesg(QByteArray)));
    //disconnect(m_pDevSeri,SIGNAL(recv_time_out()),this,SLOT(recv_time_out()));
    MainWindow::connect_flag=false;
    timer->stop();
    emit close_com();
}
void  MainWindow::recv_mesg(const QByteArray last, const QByteArray now)
{
    if((quint8)last[5]==0x14)
    {
        disconnect(m_pDevSeri,SIGNAL(recv_time_out()),this,SLOT(recv_time_out()));
        disconnect(P_NET,SIGNAL(recv_time_out()),this,SLOT(recv_time_out()));
        timer->stop();
        net_timer->stop();
        MainWindow::connect_flag=true;
        L_XL803->read_all_set(XL803::List_out);
        if(ui->tabWidget->currentIndex()==4)
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
    //return;
    m_pDevSeri->clear_list();
//    QMessageBox *box = new QMessageBox(QMessageBox::Information,tr("提示"),tr("连接超时，串口无响应!"),0,this);
//    QTimer::singleShot(1500,box,SLOT(accept()));
//    box->exec();
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
    //k->move(0,0);
    k->show();
    this->activateWindow();
}
void MainWindow::resizeEvent(QResizeEvent * event)
{
    QSize size=event->size();
    int now_size=size.width()/7;
    ui->tabWidget->tabBar()->setStyleSheet(QString("QTabBar::tab{width:%1;font: 14pt '宋体';}").arg(now_size));
    board->move(size.width()-board->width(),size.height()-board->height());
    board->update();
}

void MainWindow::connect_net()
{
    P_NET->clear_list();
    connect(L_XL803,SIGNAL(sendToPort(const QByteArray &,quint32,XL803::PAGE)),\
            P_NET,SLOT(portWrite(QByteArray,quint32,XL803::PAGE)),Qt::QueuedConnection);
    connect(P_NET,SIGNAL(portReaded(QByteArray,QByteArray,XL803::PAGE)),\
            L_XL803,SLOT(readFromPort(const QByteArray &,const QByteArray &,XL803::PAGE)),Qt::QueuedConnection);
    connect(P_NET,SIGNAL(send_error(QByteArray)),this,SLOT(error_mesg(QByteArray)));
    connect(P_NET,SIGNAL(recv_time_out()),this,SLOT(recv_time_out()));
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
    //disconnect(P_NET,SIGNAL(recv_time_out()),this,SLOT(recv_time_out()));
    MainWindow::connect_flag=false;
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
            QMessageBox::information(this,"警告","电源异常!");
            return;
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
            err.append(QString("错误标识：%1,停止输出").arg(err_type));
            break;
    }
    QMessageBox::information(this,"警告",err);
}
void MainWindow::show_tab_bar(bool flag)
{
    ui->tabWidget->tabBar()->setEnabled(flag);
}
void MainWindow::m_close()
{
    emit close_m();
}
void MainWindow::m_set_window()
{
    setWindowState(Qt::WindowNoState);
}
void MainWindow::changeEvent(QEvent* event)
{
    if(event->type()!=QEvent::WindowStateChange) return;
    if(this->windowState()==Qt::WindowMaximized)
    {
        setWindowState(Qt::WindowFullScreen);
    }
}
