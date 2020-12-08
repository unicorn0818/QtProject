#include "mainwin.h"
#include "ui_mainwin.h"
extern void ClearTxt();
MainWin::MainWin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWin)
{
    ui->setupUi(this);
    //加载oracle数据库
    loadDll();
    //初始化变量
    Row = 0;
    Row1 = 0;
    Row2 = 0;
    table2.clear();
    insertlist.clear();
    optsql = new analysisSQL();
    optxml = new analysisXML();
    //多线程上传web
    submitreport = new SubmitReport;
    QThread *tread = new QThread();
    submitreport->moveToThread(tread);
    tread->start();
    //初始化ui界面
    initUi();
    //初始化连接函数
    initCon();
}
MainWin::~MainWin()
{
    delete ui;
}
void MainWin::isfinished()
{
    QString str1 = "上传MDS成功 | "+QTime::currentTime().toString("hh:mm:ss");
    qDebug(str1.toStdString().c_str());
    QMessageBox::information(this,"提示","插入完成！",QMessageBox::Ok);
}
void MainWin::insert_next()
{
    insertlist.clear();
    for(int i=0;i<get_list1.count();i++)
    {
        insertlist.append(get_list1.at(i));
    }
    //qDebug()<<"insertlist"<<insertlist;
    emit insert_Data(insertlist,2);
}
//接受插入数据
void MainWin::get_State(int flag)
{
    if(flag == 1)
       QMessageBox::information(this,"提示","上传失败",QMessageBox::Ok);
    else
        QMessageBox::information(this,"提示","上传成功",QMessageBox::Ok);

}
//表中字段
void MainWin:: addName()
{
    if(ui->error_table->currentIndex()==0)
    {
        ui->error_Info1->clear();
        QStringList header;
        header<<"主键"<<"设备ID"<<"条形码"<<"设备名称"<<"检定单编号"<<"设备专业"<<"设备大类"<<"设备小类"<<"试验项ID"<<"试验项名称"<<"试验分组"<<"系统编号";
        header<<"检定线/台体编号"<<"检定单元编号"<<"表位编号"<<"检定/校准日期"<<"检定点的序号"<<"数据来源"<<"数据类型"<<"温度"<<"相对湿度"<<"指标项1"<<"指标项2";
        header<<"指标项3"<<"指标项4"<<"指标项5"<<"指标项6"<<"指标项7"<<"指标项8"<<"指标项9"<<"指标项10"<<"指标项11"<<"指标项12"<<"指标项13"<<"检定结论";
        header<<"写入时间"<<"处理标记"<<"处理时间";
        ui->error_Info1->setHorizontalHeaderLabels(header);
    }
    else
    {
        ui->error_Info2->clear();
        QStringList header;
        header<<"主键"<<"设备ID"<<"条形码"<<"设备名称"<<"检定单编号";
        header<<"设备专业"<<"设备大类"<<"设备小类"<<"试验项ID"<<"试验项名称";
        header<<"试验分组"<<"系统编号"<<"检定线/台体编号"<<"检定单元编号"<<"表位编号";
        header<<"检定/校准日期"<<"检定点的序号"<<"数据来源"<<"数据类型"<<"温度";
        header<<"相对湿度"<<"指标项1"<<"检定结论"<<"写入时间"<<"处理标记"<<"处理时间";
        ui->error_Info2->setHorizontalHeaderLabels(header);
    }
}
//链接数据库
void MainWin::on_LinkDBBT_clicked()
{
    //保存信息
    QSettings *config = new QSettings("./SysConfig.ini", QSettings::IniFormat);
    config->setValue("DETECT_EQUIP_NO",ui->DETECT_EQUIP_NO->text());
    config->setValue("DETECT_UNIT_NO",ui->DETECT_UNIT_NO->text());
    config->setValue("ip", ui->HostNameLE->text());
    config->setValue("database",ui->DataBaseNameLE->text());
    config->setValue("port",ui->PortLE->text());
    config->setValue("username",ui->UserNameLE->text());
    config->setValue("password",ui->PassWordLE->text());
    //链接数据库
    bool ret = optsql->Link(ui->UserNameLE->text(),ui->PassWordLE->text(),ui->PortLE->text().toInt(),ui->HostNameLE->text(),ui->DataBaseNameLE->text());
    //如果返回值为真，则链接成功
    if(ret)
    {
        QMessageBox::information(this,"提示","链接成功",QMessageBox::Ok);
        QString str1 = "数据库链接成功 | "+QTime::currentTime().toString("hh:mm:ss");
        qDebug(str1.toStdString().c_str());
        ui->DisLinkDBBT->setEnabled(true);
        ui->LinkDBBT->setEnabled(false);
    }
    else
    {
        QMessageBox::information(this,"提示","链接失败",QMessageBox::Ok);
    }

}
//断开数据库
void MainWin::on_DisLinkDBBT_clicked()
{
    bool ret = optsql->DisLink();
    if(ret)
    {
        QMessageBox::information(this,"提示","断开成功",QMessageBox::Ok);
        ui->DisLinkDBBT->setEnabled(false);
        ui->LinkDBBT->setEnabled(true);
    }
}
//打开xml文件
void MainWin::on_OpenFileBT_clicked()
{
    if(ui->LinkDBBT->isEnabled())
    {
        QString string("数据库未链接，导入xml文件失败 | "+QTime::currentTime().toString("hh:mm:ss"));
        qWarning(string.toStdString().c_str());
        QMessageBox::information(this,"提示","请先链接数据库",QMessageBox::Ok);
        return ;
    }
    QString filename = QFileDialog::getOpenFileName(this,"文件选择","./myxml","*.xml");
    //如果文件不为空
    if(!filename.isEmpty())
    {
        QString str1 = "正在导入xml文件 | "+QTime::currentTime().toString("hh:mm:ss");
        qDebug(str1.toStdString().c_str());
        //解析进度条
        progressDlg=new QProgressDialog("正在解析...", "取消",0,100,this);
        progressDlg->setWindowModality(Qt::WindowModal);
        progressDlg->setWindowTitle("提示...");
        //将文件名显示在LE上并保存到配置文件中
        ui->FileNameLE->setText(filename);
        QSettings *config = new QSettings("./SysConfig.ini", QSettings::IniFormat);
        config->setValue("filename",ui->FileNameLE->text());
        //将界面上用户填入的信息发送（检定线，检定单元）
        emit gui_info(ui->DETECT_EQUIP_NO->text(),
                      ui->DETECT_UNIT_NO->text());
        //开始解析
        emit loadxml_signal(filename);
    }
    else
    {
        QString string("选择的xml文件错误 | "+QTime::currentTime().toString("hh:mm:ss"));
        const char *str = string.toStdString().c_str();
        qWarning(str);
        return ;
    }
}
//获取从数据库中查询的数据并显示在基本信息表上
void MainWin::get_show_list(QStringList list)
{
    for(int i=0;i<list.count();i++)
    {
        ui->BaseInfo->setRowCount(Row+1);
        ui->BaseInfo->setItem(Row,i,new QTableWidgetItem(list.at(i)));
    }
    Row++;
}
//显示error1信息
void MainWin::get_show_list1(QStringList list)
{
    list_error1 = list;
    if(ui->error_table->currentIndex()==0)
    {
        int flag = 0;
        for(int i=0;i<ui->listWidget->count();i++)
        {
           if(ui->listWidget->item(i)->text()==list_error1.at(2))
           {
               flag = 1;
           }
        }
        if(flag==0)
        {
           ui->listWidget->addItem(list_error1.at(2));
        }

        flag = 0;
    }
    get_list.append(list_error1);
}
//显示error2信息
void MainWin::get_show_list2(QStringList list)
{

    list_error2 = list;
    if(ui->error_table->currentIndex()==1)
    {
        int flag = 0;
        for(int i=0;i<ui->listWidget->count();i++)
        {
           if(ui->listWidget->item(i)->text()==list_error2.at(2))
           {
               flag = 1;
           }
        }
        if(flag==0)
        {
           ui->listWidget->addItem(list_error2.at(2));
        }

        flag = 0;
    }
    get_list1.append(list_error2);
}
//上传MDS(插入到数据库的数据表中)
void MainWin::on_UpLoadBT_clicked()
{
    if(QMessageBox::Yes==QMessageBox::information(this,"提示",
                                                      "确定上传吗",
                                                      QMessageBox::Yes|QMessageBox::No)
                                                    &&!ui->LinkDBBT->isEnabled()&&ui->listWidget->count()>1)
        {
             for(int i=0;i<get_list.count();i++)
             {
                 insertlist.append(get_list.at(i));
             }
             emit insert_Data(insertlist,1);
        }
        else{
            QString string("数据库未链接或xml文件未解析,上传失败 | "+QTime::currentTime().toString("hh:mm:ss"));
            const char *str = string.toStdString().c_str();
            qWarning(str);
            return ;
        }
}
//清空表
void MainWin::on_ClearBT_clicked()
{
    if(QMessageBox::Yes==QMessageBox::information(this,"提示","确定清空吗",QMessageBox::Yes|QMessageBox::No))
    {
        addName();
    }
}

void MainWin::on_listWidget_itemClicked(QListWidgetItem *item)
{
    if(item->text()=="条形码")
        return ;
    if(ui->error_table->currentIndex()==0)
    {
        addName();
        Row1 = 0;
        //如：获得列表的数量为6，遍历
        for(int i=0;i<get_list.count();i++)
        {
            //此StringList是不是属于点击的条形码
            if(get_list.at(i).at(2)==item->text())
            {
                // 将条形码打印
                for(int j=0;j<get_list.at(i).count();j++)
                {
                    ui->error_Info1->setRowCount(Row1+1);
                    ui->error_Info1->setItem(Row1,j,new QTableWidgetItem(get_list.at(i).at(j)));
                }
                Row1++;
            }
        }
    }
    else
    {
        addName();
        Row2 = 0;
        //如：获得列表的数量为6，遍历
        for(int i=0;i<get_list1.count();i++)
        {
            //此StringList是不是属于点击的条形码
            if(get_list1.at(i).at(2)==item->text())
            {
                // 将条形码打印
                for(int j=0;j<get_list1.at(i).count();j++)
                {
                    ui->error_Info2->setRowCount(Row2+1);
                    ui->error_Info2->setItem(Row2,j,new QTableWidgetItem(get_list1.at(i).at(j)));
                }
                Row2++;
            }
        }
    }
}
//点击topbar
void MainWin::on_error_table_tabBarClicked(int index)
{
    ui->listWidget->clear();
    ui->listWidget->addItem("条形码");
    if(index==0)
    {
        int flag = 0;
        for(int j=0;j<get_list.count();j++)
        {
            for(int i=0;i<ui->listWidget->count();i++)
            {
                if(ui->listWidget->item(i)->text()==get_list.at(j).at(2))
                    flag = 1;
            }
            if(flag == 0)
                ui->listWidget->addItem(get_list.at(j).at(2));
            flag = 0;
        }
    }
    else if(index==1)
    {
        int flag = 0;
        for(int i=0;i<get_list1.count();i++)
        {
            for(int j=0;j<ui->listWidget->count();j++)
            {
                if(ui->listWidget->item(j)->text()==get_list1.at(i).at(2))
                    flag = 1;
            }
            if(flag == 0)
                ui->listWidget->addItem(get_list1.at(i).at(2));
             flag = 0;
        }
    }
}
//获取实时进度
void MainWin::get_current_precent(qreal precent)
{
   progressDlg->setValue(precent);
}
//点击日志功能时，更新日志内容
void MainWin::on_ALLTW_tabBarClicked(int index)
{
    if(index==3)
    {
        QFile file("./debuglog.txt");
        if(file.isOpen())
            file.close();
        file.open(QIODevice::ReadOnly);
        QByteArray array = file.read(file.size());
        QString mes = QString::fromLocal8Bit(array);
        ui->ShowLog->setText(mes);
        file.close();
    }
}
//导出日志文件
void MainWin::on_DownLoadLog_clicked()
{
    QFile file("./debuglog.txt");
    file.open(QIODevice::ReadOnly);
    QByteArray array = file.read(file.size());
    file.close();
    QFile file1("./report.txt");
    file1.open(QIODevice::WriteOnly);
    file1.write(array);
    QMessageBox::information(this,"提示","日志已导出到./report.txt中！！！",QMessageBox::Ok);
    file.close();
    file1.close();
}
//清空日志内容
void MainWin::on_ClearLog_clicked()
{
    if(QMessageBox::Yes==QMessageBox::information(this,"提示","确定清空日志内容吗",QMessageBox::Yes|QMessageBox::No))
    {
        ClearTxt();
        ui->ALLTW->tabBarClicked(3);
    }
    else
        return ;
}
//更新web
//1@检验任务单编号@检定设备编号
void MainWin::on_UpdateWebBT_clicked()
{
    if(ui->UpdateWeb->rowCount()<1)
    {
       QMessageBox::information(this,"提示","请求失败：表为空",QMessageBox::Ok);
       qWarning("更新失败：表为空");
       return ;
    }
    if(QMessageBox::Yes==QMessageBox::information(this,"提示","确定更新Web吗",QMessageBox::Yes|QMessageBox::No))
    {
        qDebug("准备更新Web...");
        QStringList v_Web_t;
        for(int i=0;i<ui->UpdateWeb->rowCount()-1;i++)
        {
           QString tWeb;
           ui->UpdateWeb->item(i,2)->setText("处理中");
           tWeb.append(QString::number(i)).append('@')
                   .append(ui->UpdateWeb->item(i, 0)->text()).append('@')
                   .append(ui->UpdateWeb->item(i, 1)->text());
           v_Web_t.append(tWeb);
        }
        if(v_Web_t.size())
        {
            emit qtsoap_send(v_Web_t);
        }
    }
}
//清空web表中的内容
void MainWin::on_ClearTable_clicked()
{
    if(QMessageBox::Yes==QMessageBox::information(this,"提示","确定清空吗",QMessageBox::Yes|QMessageBox::No))
    {
       ui->UpdateWeb->clear();
       QStringList list;
       list<<"检验任务单编号"<<"检定设备编号"<<"状态"<<"错误信息"<<"上传接口"<<"时间";
       ui->UpdateWeb->setHorizontalHeaderLabels(list);
    }
}
//获取WebUrl
void MainWin::on_WebUrlLE_textChanged(const QString &arg1)
{
    WebUrl = arg1;
}
//获取来自web的响应
void MainWin::getWebInfo(bool flag, QString info)
{
    ui->UpdateWeb->setRowCount(ui->UpdateWeb->rowCount()+1);
    if(flag==1)
        ui->UpdateWeb->setItem(ui->UpdateWeb->rowCount()-1,2,new QTableWidgetItem("成功"));
    else
    {
        ui->UpdateWeb->setItem(ui->UpdateWeb->rowCount()-1,2,new QTableWidgetItem("失败"));
        ui->UpdateWeb->setItem(ui->UpdateWeb->rowCount()-1,3,new QTableWidgetItem(info));
    }
    ui->UpdateWeb->setItem(ui->UpdateWeb->rowCount()-1,4,new QTableWidgetItem(ui->WebUrlLE->text()));
    ui->UpdateWeb->setItem(ui->UpdateWeb->rowCount()-1,5,new QTableWidgetItem(QTime::currentTime().toString("hh:mm:ss")));
}
//加载oracle动态库
void MainWin::loadDll()
{
    QLibrary *hello_lib = NULL;
    hello_lib = new QLibrary("F:\\app\\27191\\product\\11.2.0\\dbhome_2\\BIN\\oci.dll");
    hello_lib->load();
    if (!hello_lib->isLoaded())
    {
        qDebug("load Oracle failed!");
        return ;
    }
}
//初始化界面
void MainWin::initUi()
{
    //设置图标
    QIcon icon1(":/1.png");
    ui->ALLTW->setTabIcon(0,icon1);
    QIcon icon2(":/2.png");
    ui->ALLTW->setTabIcon(1,icon2);
    QIcon icon3(":/3.png");
    ui->ALLTW->setTabIcon(2,icon3);
    QIcon icon4(":/4.png");
    ui->ALLTW->setTabIcon(3,icon4);
    QIcon icon5(":/5.png");
    ui->ALLTW->setTabIcon(4,icon5);
    ui->ALLTW->setIconSize(QSize(50,50));

    //读取配置信息并显示
    QSettings *config = new QSettings("./SysConfig.ini", QSettings::IniFormat);
    QString IP = config->value("ip").toString();
    QString PASSWORD = config->value("password").toString();
    QString USERNAME = config->value("username").toString();
    QString PORT = config->value("port").toString();
    QString DATABASENAME = config->value("database").toString();
    QString FILENAME = config->value("filename").toString();
    QString DETECT_EQUIP_NO = config->value("DETECT_EQUIP_NO").toString();
    QString DETECT_UNIT_NO = config->value("DETECT_UNIT_NO").toString();
    QString WebUrl = config->value("WebUrl").toString();
    //恢复关闭软件前保存的信息
    ui->FileNameLE->setText(FILENAME);
    ui->DataBaseNameLE->setText(DATABASENAME);
    ui->PortLE->setText(PORT);
    ui->UserNameLE->setText(USERNAME);
    ui->HostNameLE->setText(IP);
    ui->PassWordLE->setText(PASSWORD);
    ui->DisLinkDBBT->setEnabled(false);
    ui->DETECT_EQUIP_NO->setText(DETECT_EQUIP_NO);
    ui->DETECT_UNIT_NO->setText(DETECT_UNIT_NO);
    ui->WebUrlLE->setText(WebUrl);
}
//初始化连接函数
void MainWin::initCon()
{
    //接受web的响应
    connect(submitreport,SIGNAL(sendToMainWin(bool,QString)),this,SLOT(getWebInfo(bool,QString)));
    //解析xml
    connect(this,SIGNAL(loadxml_signal(QString)),optxml,SLOT(load_DealXML(QString)));
    //发送bar_code到数据库中查询
    connect(optxml,SIGNAL(signals_Bar_Code(QString)),  optsql, SLOT(ExectSQL_MDS(QString)));
    connect(optsql,SIGNAL(show_list(QStringList)),this, SLOT(get_show_list(QStringList)));
    connect(optsql,SIGNAL(show_list(QStringList)),optxml, SLOT(get_show_list(QStringList)));
    connect(optxml,SIGNAL(error_info1(QStringList)),this,SLOT(get_show_list1(QStringList)));
    connect(optxml,SIGNAL(error_info2(QStringList)),this,SLOT(get_show_list2(QStringList)));
    //把界面上用户输入的信息发送给optxml
    connect(this,SIGNAL(gui_info(QString,QString)),optxml,SLOT(send_gui_info(QString,QString)));
    connect(this,SIGNAL(insert_Data(QVector<QStringList>,int)),optsql,SLOT(get_insert_Data(QVector<QStringList>,int)));
    connect(optsql,SIGNAL(Insert_State(int)),this,SLOT(get_State(int)));
    connect(optxml,SIGNAL(current_pre(qreal)),this,SLOT(get_current_precent(qreal)));
    connect(optsql,SIGNAL(next_insert()),this,SLOT(insert_next()));
    connect(optsql,SIGNAL(finished()),this,SLOT(isfinished()));
    //发送信号到多线程中开始上传web
    connect(this,SIGNAL(qtsoap_send(QStringList)),submitreport,SLOT(slot_qtsoap_send(QStringList)));
    //数据库插入完成后将信息发送到更新web界面
    connect(optsql,SIGNAL(addWebInfo(QString,QString)),this,SLOT(upDateWebInfo(QString,QString)));
}
//更新web界面的上传信息
void MainWin::upDateWebInfo(QString info1, QString info2)
{
    int count = ui->UpdateWeb->rowCount();
    ui->UpdateWeb->setRowCount(count+1);
    ui->UpdateWeb->setItem(count-1,0,new QTableWidgetItem(info1));
    ui->UpdateWeb->setItem(count-1,1,new QTableWidgetItem(info2));
    ui->UpdateWeb->setItem(count-1,2,new QTableWidgetItem("未上传"));
    ui->UpdateWeb->setItem(count-1,3,new QTableWidgetItem(""));
    ui->UpdateWeb->setItem(count-1,4,new QTableWidgetItem("veriSendDetectRsltInfo"));
    ui->UpdateWeb->setItem(count-1,5,new QTableWidgetItem(QTime::currentTime().toString("hh:mm:ss")));
}
//发送soap请求
//void MainWin::slot_qtsoap_send(QStringList list)
//{
//    //http://10.158.249.196:7001/InterfaceWS/InterfaceBusinessrvices/DetectService
//    //解析域名
//    QString Host = WebUrl.split('/').at(2);
//    QString port = Host.split(':').at(1);
//    Host = Host.split(':').at(0);

//    for(int i = 0;i<list.count();i++)
//    {
//        //解析url
//        QStringList t_list = list.at(i).split('@');
//        QString nIndex = t_list.at(0);
//        QString DETECT_TASK_NO = t_list.at(1);
//        QString EQUIP_NO = t_list.at(2);

//        // 设置主机
//        m_pHttp->setHost(Host,port.toInt());
//        // 设置动作
//        m_pHttp->setAction("veriSendDetectRsltInfo");

//        QtSoapMessage mes;
//        //设置方法
//        mes.setMethod("veriSendDetectRsltInfo", WebUrl);
//        //添加参数
//        mes.addMethodArgument("DETECT_TASK_NO",NULL,DETECT_TASK_NO.toLatin1().data());
//        mes.addMethodArgument("EQUIP_NO",NULL,EQUIP_NO.toLatin1().data());
//        // 提交请求
//        m_pHttp->submitRequest(mes,"10.158.249.196:7001");
//    }

//}
////获取返回的信息
//void MainWin::onResponse(const QtSoapMessage &back)
//{
//    QString ret = back.toXmlString();
//}
