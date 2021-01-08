#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initUI();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initUI()
{
    // 隐藏标签
    ui->tabWidget->tabBar()->hide();
    ui->tabWidget_2->tabBar()->hide();
    model_a = new QStandardItemModel(this);
    model_b = new QStandardItemModel(this);
    model_b_2 = new QStandardItemModel(this);
    QStringList label;
    label<<"交易门店"<<"支付宝套餐"<<"支付宝代金券"<<"支付宝付款";
    model_a->setHorizontalHeaderLabels(label);
    label.clear();
    label<<"操作员"<<"商家实收";
    model_b->setHorizontalHeaderLabels(label);
    model_b_2->setHorizontalHeaderLabels(label);
    ui->tableView_a->setModel(model_a);
    ui->tableView_a->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView_b->setModel(model_b);
    ui->tableView_b->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView_b_2->setModel(model_b_2);
    ui->tableView_b_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->textBrowser->setTextColor(Qt::red);
}
//获取文件的后缀名
QString MainWindow::getFileSuffix(QString file_path)
{
    return file_path.mid(file_path.lastIndexOf(".")+1);
}

void MainWindow::loadTable(int type, QString file_path)
{
    //汇总表xlsx
    if(type == 0)
    {
        table_name_a = file_path;
        QXlsx::Document xlsx(file_path);
        QXlsx::CellRange range;
        range = xlsx.dimension();
        int rowCount = range.rowCount();
        int col=range.columnCount();
        int page_range = (rowCount%15)==0?(rowCount/15):rowCount/15+1;
        ui->go_index_a->setRange(1,page_range);
        ui->all_index_a->setText(QString::number(page_range));
        xlsx_vector.clear();
        int coupon_col = 0,combo_col = 0,trading_col = 0,alipay_col = 0;
        for(int i=1;i<col;i++)
        {
            if(xlsx.cellAt(2,i)->value().toString()=="支付宝代金券")
                coupon_col = i;
            if(xlsx.cellAt(2,i)->value().toString()=="支付宝套餐")
                combo_col = i;
            if(xlsx.cellAt(2,i)->value().toString()=="交易门店")
                trading_col = i;
            if(xlsx.cellAt(2,i)->value().toString()=="支付宝付款")
                alipay_col = i;
        }
        int num = 0,flag = 0;
        for(int i=3;i<rowCount;i++)
        {
            for(int j=2;j<col;j++)
            {
                if(j==trading_col)
                {
                    all_value.clear();
                    //先判断一下xlsx_vector里面是不是已经存在了这个门店
                    //如果存在了，就把它累加上去
                    for(int k = 0;k<xlsx_vector.count();k++)
                    {
                        if(xlsx_vector.at(k).at(2)==xlsx.cellAt(i,j)->value().toString())
                        {
                            QStringList list;
                            list<<QString::number(xlsx_vector.at(k).at(0).toDouble()+xlsx.cellAt(i,combo_col)->value().toDouble())\
                               <<QString::number(xlsx_vector.at(k).at(1).toDouble()+xlsx.cellAt(i,coupon_col)->value().toDouble())\
                              <<xlsx.cellAt(i,j)->value().toString()\
                             <<QString::number(xlsx_vector.at(k).at(3).toDouble()+xlsx.cellAt(i,alipay_col)->value().toDouble());
                            xlsx_vector.replace(k,list);
                            flag = 1;
                        }
                    }
                    if(flag==0)
                    {
                        all_value<<xlsx.cellAt(i,combo_col)->value().toString()\
                                <<xlsx.cellAt(i,coupon_col)->value().toString()\
                               <<xlsx.cellAt(i,j)->value().toString()\
                              <<xlsx.cellAt(i,alipay_col)->value().toString();
                        xlsx_vector.append(all_value);
                    }else
                        flag = 0;
                    if(num<15)
                    {
                        model_a->setItem(i-3,0,new QStandardItem(xlsx.cellAt(i,j)->value().toString()));
                        model_a->setItem(i-3,1,new QStandardItem(xlsx.cellAt(i,combo_col)->value().toString()));
                        model_a->setItem(i-3,2,new QStandardItem(xlsx.cellAt(i,coupon_col)->value().toString()));
                        model_a->setItem(i-3,3,new QStandardItem(xlsx.cellAt(i,alipay_col)->value().toString()));
                        num++;
                    }
                }
            }
        }
        ui->textBrowser->append(QTime::currentTime().toString("hh:mm:ss")+":汇总表:"+file_path+"导入成功!");
    }//套餐实收表xls
    else if(type == 1)
    {
        table_name_b = file_path;
        QAxObject excel("Excel.Application");
        if(excel.isNull())
        {
            QMessageBox::information(this,"提示","无office组件.");
            return;
        }
        excel.setProperty("Visible", false); //隐藏打开的excel文件界面
        //获取工作簿(excel文件)集合
        QAxObject *workbooks = excel.querySubObject("WorkBooks");
        //计算各阶段消耗的时间
        QElapsedTimer timer;
        timer.start();
        //打开文件
        QAxObject *workbook = workbooks->querySubObject("Open(QString, QVariant)", file_path);
        //打开文件消耗的时间
        qDebug()<<"open cost:"<<timer.elapsed()<<"ms";
        timer.restart();
        cell.clear();
        QAxObject *active_book = excel.querySubObject("ActiveWorkBook");//获取活动工作簿
        QAxObject *worksheets = active_book->querySubObject("WorkSheets");//获取所有的工作表
        int sheet_count = worksheets->property("Count").toInt();
        qDebug()<<"sheet_count"<<sheet_count;
        //访问第一个工作表
        QAxObject * worksheet = workbook->querySubObject("WorkSheets(int)", 1);
        QAxObject * usedrange = worksheet->querySubObject("UsedRange");
        QAxObject * rows = usedrange->querySubObject("Rows");
        QAxObject * colums = usedrange->querySubObject("Columns");
        int all_row = rows->property("Count").toInt(); //行数
        int all_colum = colums->property("Count").toInt(); //行数
        qDebug()<<"rows"<<all_row<<"colums"<<all_colum;
        cell = usedrange->dynamicCall("Value");
        qDebug()<<"read data cost:"<<timer.elapsed()<<"ms";timer.restart();
        QString opt_tmp;
        for(int i = 4;i<all_row-2;i++)
        {
            opt_tmp = cell.toList().at(i).toList().at(9).toString();
            if(earned_rates.keys().contains(opt_tmp))
            {
                earned_rates[opt_tmp] += cell.toList().at(i).toList().at(12).toDouble();
            }
            else
                earned_rates.insert(cell.toList().at(i).toList().at(9).toString(),\
                                    cell.toList().at(i).toList().at(12).toDouble());
        }
        int times = 0;
        if(earned_rates.count()>=15)
            times = 15;
        else
            times = earned_rates.count();
        for(int i=0;i<times;i++)
        {
            model_b->setItem(i,0,new QStandardItem(earned_rates.keys().at(i)));
            model_b->setItem(i,1,new QStandardItem(QString::number(earned_rates.values().at(i))));
        }
        int page_range = ((earned_rates.count())%15)==0?((earned_rates.count())/15):earned_rates.count()/15+1;
        ui->all_index_b->setText(QString::number(page_range));
        ui->go_index_b->setRange(0,page_range);
        ui->textBrowser->append(QTime::currentTime().toString("hh:mm:ss")+":代金实收表:"+file_path+"导入成功!");
        //保存工作簿
        workbooks->dynamicCall("Close()");
        excel.dynamicCall("Quit()");
    }else if(type==2){
        table_name_b_2 = file_path;
        QAxObject excel("Excel.Application");
        if(excel.isNull())
        {
            QMessageBox::information(this,"提示","无office组件.");
            return;
        }
        excel.setProperty("Visible", false); //隐藏打开的excel文件界面
        //获取工作簿(excel文件)集合
        QAxObject *workbooks = excel.querySubObject("WorkBooks");
        //计算各阶段消耗的时间
        QElapsedTimer timer;
        timer.start();
        //打开文件
        QAxObject *workbook = workbooks->querySubObject("Open(QString, QVariant)", file_path);
        timer.restart();
        cell.clear();
        QAxObject *active_book = excel.querySubObject("ActiveWorkBook");//获取活动工作簿
        QAxObject *worksheets = active_book->querySubObject("WorkSheets");//获取所有的工作表
        int sheet_count = worksheets->property("Count").toInt();
        qDebug()<<"sheet_count"<<sheet_count;
        //访问第一个工作表
        QAxObject * worksheet = workbook->querySubObject("WorkSheets(int)", 1);
        QAxObject * usedrange = worksheet->querySubObject("UsedRange");
        QAxObject * rows = usedrange->querySubObject("Rows");
        QAxObject * colums = usedrange->querySubObject("Columns");
        int all_row = rows->property("Count").toInt(); //行数
        int all_colum = colums->property("Count").toInt(); //行数
        qDebug()<<"rows"<<all_row<<"colums"<<all_colum;
        cell = usedrange->dynamicCall("Value");
        QString opt_tmp;
        for(int i = 4;i<all_row-2;i++)
        {
            opt_tmp = cell.toList().at(i).toList().at(22).toString();
            if(earned_rates_2.keys().contains(opt_tmp))
            {
                earned_rates_2[opt_tmp] += cell.toList().at(i).toList().at(9).toDouble();
            }
            else
                earned_rates_2.insert(cell.toList().at(i).toList().at(22).toString(),\
                                    cell.toList().at(i).toList().at(9).toDouble());
        }
        int times = 0;
        if(earned_rates_2.count()>=15)
            times = 15;
        else
            times = earned_rates_2.count();
        for(int i=0;i<times;i++)
        {
            model_b_2->setItem(i,0,new QStandardItem(earned_rates_2.keys().at(i)));
            model_b_2->setItem(i,1,new QStandardItem(QString::number(earned_rates_2.values().at(i))));
        }
        int page_range = ((earned_rates_2.count())%15)==0?((earned_rates_2.count())/15):earned_rates_2.count()/15+1;
        ui->all_index_b_2->setText(QString::number(page_range));
        ui->go_index_b_2->setRange(0,page_range);
        ui->textBrowser->append(QTime::currentTime().toString("hh:mm:ss")+":付款实收表:"+file_path+"导入成功!");
        //保存工作簿
        workbooks->dynamicCall("Close()");
        excel.dynamicCall("Quit()");
    }
}

void MainWindow::on_resolution_ratio_clicked()
{
    if(ui->resolution_ratio->text()=="全屏")
    {
        this->setWindowState(Qt::WindowFullScreen);
        ui->resolution_ratio->setText("窗口化");
    }else{
        this->setWindowState(Qt::WindowNoState);
        ui->resolution_ratio->setText("全屏");
    }
}

void MainWindow::on_quit_system_clicked()
{
    if(QMessageBox::Yes==QMessageBox::information(this,"提示","确定退出吗？",QMessageBox::Yes|QMessageBox::No))
        qApp->quit();
}

void MainWindow::on_load_file_clicked()
{
    QSettings *setting = new QSettings("./config.ini", QSettings::IniFormat);
    QString file_name = QFileDialog::getOpenFileName(NULL,"选择文件",setting->value("openpath").toString(),"*.*");
    if(file_name.isEmpty())
        return;
    if("xlsx"==getFileSuffix(file_name)&&ui->comboBox->currentText()=="汇总表")
        loadTable(0,file_name);
    else if("xls"==getFileSuffix(file_name)&&ui->comboBox->currentText()=="套餐实收表")
        loadTable(1,file_name);
    else if("xls"==getFileSuffix(file_name)&&ui->comboBox->currentText()=="付款实收表")
        loadTable(2,file_name);
    else
        QMessageBox::information(this,"提示","文件格式错误!");
    setting->setValue("openpath",file_name);
}

void MainWindow::on_file_path_clicked()
{
    if(ui->comboBox->currentText()=="汇总表"&&!table_name_a.isEmpty())
        ui->textBrowser->append(QTime::currentTime().toString("hh:mm:ss")+":当前导入汇总表的路径为:"+table_name_a);
    else if(!table_name_b.isEmpty())
        ui->textBrowser->append(QTime::currentTime().toString("hh:mm:ss")+":当前导入实收表的路径为:"+table_name_b);
    else
        return ;
}

void MainWindow::on_clear_info_clicked()
{
    ui->textBrowser->clear();
}

void MainWindow::on_go_to_a_clicked()
{
    on_go_index_a_editingFinished();
}

void MainWindow::on_go_index_a_editingFinished()
{
    if(xlsx_vector.length()<1)
        return ;
    int go_index = ui->go_index_a->text().toInt();
    ui->now_index_a->setText(QString::number(go_index));
    for(int i=0;i<15;i++)
    {
        if((go_index-1)*15+i<xlsx_vector.length())
        {
            model_a->item(i,0)->setText(xlsx_vector.at((go_index-1)*15+i).at(2));
            model_a->item(i,1)->setText(xlsx_vector.at((go_index-1)*15+i).at(0));
            model_a->item(i,2)->setText(xlsx_vector.at((go_index-1)*15+i).at(1));
            model_a->item(i,3)->setText(xlsx_vector.at((go_index-1)*15+i).at(3));
        }
        else
        {
            model_a->item(i,0)->setText("");
            model_a->item(i,1)->setText("");
            model_a->item(i,2)->setText("");
            model_a->item(i,3)->setText("");
        }
    }
}

void MainWindow::on_last_a_clicked()
{
    ui->go_index_a->setValue(ui->go_index_a->value()-1);
    on_go_index_a_editingFinished();
}

void MainWindow::on_next_a_clicked()
{
    ui->go_index_a->setValue(ui->go_index_a->value()+1);
    on_go_index_a_editingFinished();
}

void MainWindow::on_go_to_b_clicked()
{
    on_go_index_b_editingFinished();
}

void MainWindow::on_go_index_b_editingFinished()
{
    if(earned_rates.count()<1)
        return ;
    int go_index = ui->go_index_b->text().toInt();
    ui->now_index_b->setText(QString::number(go_index));
    for(int i=0;i<15;i++)
    {

        if((go_index-1)*15+i<earned_rates.count())
        {
            model_b->item(i,0)->setText(earned_rates.keys().at((go_index-1)*15+i));
            model_b->item(i,1)->setText(QString::number(earned_rates.values().at((go_index-1)*15+i)));
        }
        else
        {
            model_b->item(i,0)->setText("");
            model_b->item(i,1)->setText("");
        }
    }
}

void MainWindow::on_last_b_clicked()
{
    ui->go_index_b->setValue(ui->go_index_b->value()-1);
    on_go_index_b_editingFinished();
}

void MainWindow::on_next_b_clicked()
{
    ui->go_index_b->setValue(ui->go_index_b->value()+1);
    on_go_index_b_editingFinished();
}
//比对数据
void MainWindow::on_check_data_clicked()
{
    if(table_name_a.isEmpty())
        return ;
    ui->textBrowser->append(QTime::currentTime().toString("hh:mm:ss")+":开始比对");
    if(ui->comboBox->currentText()=="套餐实收表")
    {
        ui->tabWidget_2->setCurrentIndex(0);
        int true_count = 0,false_count = 0;
        for(int i=0;i<earned_rates.count();i++)
        {
            QString check_str = earned_rates.keys().at(i);
            QString value = QString::number(earned_rates.values().at(i));
            check_str = check_str.remove("店");
            //广州
            if(check_str=="合一国际")
                check_str="合一广场";
            else if(check_str=="天河北佳兆业")
                check_str="广州佳兆业";
            else if(check_str=="荔湾悦汇城")
                check_str="广州悦汇城";
            else if(check_str=="祈福缤纷")
                check_str="广州祈福新村";
            //深圳
            else if(check_str=="卓悦INTOWN")
                check_str="深圳卓越世纪";
            else if(check_str=="万科里")
                check_str="深圳龙城万科";
            else if(check_str=="西丽云城万科里")
                check_str="深圳云城万科";
            else if(check_str=="龙华九方")
                check_str="深圳龙华天虹";
            else if(check_str=="京基百纳时代")
                check_str="深圳KKONE";
            else if(check_str=="宝安壹方城")
                check_str="深圳壹方城";
            else if(check_str=="香格里分")
                check_str="深圳观澜香格里";
            for(int j =0 ;j<xlsx_vector.count();j++)
            {
                if(xlsx_vector.at(j).at(2).contains(check_str))
                {
                    if((xlsx_vector.at(j).at(1).toDouble()+xlsx_vector.at(j).at(0).toDouble()!=value.toDouble()))
                    {
                        ui->textBrowser->append("实收项与汇总项不匹配!");
                        ui->textBrowser->append("汇总表门店信息:"+xlsx_vector.at(j).at(2)+"代金券+支付宝套餐:"+QString::number(xlsx_vector.at(j).at(1).toDouble()+xlsx_vector.at(j).at(0).toDouble()));
                        ui->textBrowser->append("实收项门店信息:"+check_str+"实收款:"+value);
                        false_count++;
                    }else{
//                        ui->textBrowser->append("实收项与汇总项匹配!");
//                        ui->textBrowser->append("汇总表门店信息:"+xlsx_vector.at(j).at(2)+"代金券+支付宝套餐:"+QString::number(xlsx_vector.at(j).at(1).toDouble()+xlsx_vector.at(j).at(0).toDouble()));
//                        ui->textBrowser->append("实收项门店信息:"+check_str+"实收款:"+value);
                        true_count++;
                    }
                }
            }
        }       
        ui->textBrowser->append(QTime::currentTime().toString("hh:mm:ss")+":正确数:"+QString::number(true_count)+"错误数:"+QString::number(false_count));
    }else if(ui->comboBox->currentText()=="付款实收表"){
        ui->tabWidget_2->setCurrentIndex(1);
        int true_count = 0,false_count = 0;
        for(int i=0;i<earned_rates_2.count();i++)
        {
            QString check_str = earned_rates_2.keys().at(i);
            QString value = QString::number(earned_rates_2.values().at(i));
            check_str = check_str.remove("店");
            //广州
            if(check_str=="广州中铁诺德")
                check_str="广州番禺诺德";
            else if(check_str=="广州祈福缤纷")
                check_str="广州祈福新村";
            else if(check_str=="荔湾悦汇城")
                check_str="广州悦汇城";
            else if(check_str=="天河北佳兆业")
                check_str="广州佳兆业";
            //东莞
            else if(check_str=="东莞国际购物中心")
                check_str="东莞虎门购物中心";
            //深圳
            else if(check_str=="卓悦INTOWN")
                check_str="深圳卓越世纪";
            else if(check_str=="万科里")
                check_str="深圳龙城万科";
            else if(check_str=="西丽云城万科里")
                check_str="深圳云城万科";
            else if(check_str=="龙华九方")
                check_str="深圳龙华天虹";
            else if(check_str=="京基百纳时代")
                check_str="深圳KKONE";
            else if(check_str=="宝安壹方城")
                check_str="深圳壹方城";
            else if(check_str=="香格里分")
                check_str="深圳观澜香格里";
            //上海
            else if(check_str=="上海五角场店万达")
                check_str="上海五角场";
            else if(check_str=="打浦桥日月光")
                check_str="上海日月光";
            for(int j =0 ;j<xlsx_vector.count();j++)
            {
                if(xlsx_vector.at(j).at(2).contains(check_str))
                {
                    if((xlsx_vector.at(j).at(3).toDouble()!=value.toDouble()))
                    {
                        ui->textBrowser->append("实收项与汇总项不匹配!");
                        ui->textBrowser->append("汇总表门店信息:"+xlsx_vector.at(j).at(2)+"支付宝付款:"+QString::number(xlsx_vector.at(j).at(3).toDouble()));
                        ui->textBrowser->append("实收项门店信息:"+check_str+"实收款:"+value);
                        false_count++;
                    }else{
//                        ui->textBrowser->append("实收项与汇总项匹配!");
//                        ui->textBrowser->append("汇总表门店信息:"+xlsx_vector.at(j).at(2)+"支付宝付款:"+QString::number(xlsx_vector.at(j).at(3).toDouble()));
//                        ui->textBrowser->append("实收项门店信息:"+check_str+"实收款:"+value);
                        true_count++;
                    }
                }
            }
        }
        ui->textBrowser->append(QTime::currentTime().toString("hh:mm:ss")+":正确数:"+QString::number(true_count)+"错误数:"+QString::number(false_count));
    }
}

void MainWindow::on_output_info_clicked()
{
    QString file_path = QFileDialog::getSaveFileName(NULL,"导出路径",QDateTime::currentDateTime().toString("yyyy_MM_dd_HH_mm_ss")+"_输出日志","*.txt");
    if(!file_path.isEmpty())
    {
        QFile file(file_path+".txt");
        file.open(QIODevice::WriteOnly);
        QTextStream stream(&file);
        stream<<ui->textBrowser->toPlainText();
        file.close();
    }
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    if(index==1)
    {
        ui->tabWidget_2->setCurrentIndex(0);
    }else if(index ==2)
    {
        ui->tabWidget_2->setCurrentIndex(1);
    }
}

void MainWindow::on_go_to_b_2_clicked()
{
    on_go_index_b_2_editingFinished();
}

void MainWindow::on_go_index_b_2_editingFinished()
{
    if(earned_rates_2.count()<1)
        return ;
    int go_index = ui->go_index_b_2->text().toInt();
    ui->now_index_b_2->setText(QString::number(go_index));
    for(int i=0;i<15;i++)
    {

        if((go_index-1)*15+i<earned_rates_2.count())
        {
            model_b_2->item(i,0)->setText(earned_rates_2.keys().at((go_index-1)*15+i));
            model_b_2->item(i,1)->setText(QString::number(earned_rates_2.values().at((go_index-1)*15+i)));
        }
        else
        {
            model_b_2->item(i,0)->setText("");
            model_b_2->item(i,1)->setText("");
        }
    }
}

void MainWindow::on_last_b_2_clicked()
{
    ui->go_index_b_2->setValue(ui->go_index_b_2->value()-1);
    on_go_index_b_2_editingFinished();
}

void MainWindow::on_next_b_2_clicked()
{
    ui->go_index_b_2->setValue(ui->go_index_b_2->value()+1);
    on_go_index_b_2_editingFinished();
}

