#include "mainwindow.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    loadFlag = false;
    m_config_dialog = new configDialog();
    m_analysis_xml = new analysisXml();
    m_analysis_sql = new analysisSQL();
    m_config_dialog->setWindowModality(Qt::ApplicationModal);
    connect(m_config_dialog,SIGNAL(conOracle(QStringList)),this,SLOT(myOracleCon(QStringList)));
    connect(m_config_dialog,SIGNAL(disConOracle()),this,SLOT(myOracleDisCon()));
    connect(m_config_dialog,SIGNAL(loadXml(QString)),this,SLOT(xmlLoad(QString)));
    connect(m_analysis_xml,SIGNAL(selectBarCode(QString)),this,SLOT(checkBarCode(QString)));
    connect(m_analysis_xml,SIGNAL(tableData(QStringList)),this,SLOT(getTableData(QStringList)));
    connect(m_analysis_sql,SIGNAL(A_1Data(QStringList)),this,SLOT(getA_1Data(QStringList)));
    connect(m_analysis_xml,SIGNAL(finishLoad()),this,SLOT(loadFinish()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getA_1Data(QStringList list)
{
    m_A_1Info_vector<<list;
}

void MainWindow::loadFinish()
{
    loadFlag = true;
    m_config_dialog->hide();
    ui->listWidget->setCurrentRow(0);
    if(m_analysis_sql->getIsOpenMds())
    {
        m_analysis_sql->jointA_1();
        //构建模糊查询对象
        QStringList word_list;
        for(int i = 0;i<m_A_1Info_vector.count();i++)
        {
            if(word_list.contains(m_A_1Info_vector.at(i).at(3)))
            {

            }else{
                    word_list<<m_A_1Info_vector.at(i).at(0);
            }
        }
        QCompleter *MyInfor = new QCompleter(word_list);
        //设置Eidt的模糊查询对象
        ui->task_no->setCompleter(MyInfor);
    }
}

void MainWindow::getTableData(QStringList table_data)
{
    m_tableInfo_vector<<table_data;
}

void MainWindow::on_config_set_clicked()
{
    m_config_dialog->show();
}

void MainWindow::myOracleCon(QStringList ora_info)
{
    int ret = m_analysis_sql->Link(ora_info.at(0),ora_info.at(1),ora_info.at(2).toInt(),ora_info.at(3),ora_info.at(4));
    if(!ret)
        QMessageBox::warning(this,"警告","数据库连接失败!");
    else
    {
        m_config_dialog->setConMode(true);
        QMessageBox::information(this,"提示","数据库连接成功!");
    }
}

void MainWindow::myOracleDisCon()
{
    m_analysis_sql->DisLink();
    m_config_dialog->setConMode(false);
}

void MainWindow::xmlLoad(QString file_name)
{
    m_barCode_vector.clear();
    ui->listWidget->clear();
    m_tableInfo_vector.clear();
    loadFlag = false;
    m_analysis_xml->loadXml(file_name);
}

void MainWindow::checkBarCode(QString bar_code)
{
    m_barCode_vector.append(bar_code);
    ui->listWidget->addItem(bar_code);
}

void MainWindow::on_listWidget_currentRowChanged(int currentRow)
{
    int tmp_row = ui->tableWidget->rowCount();
    for(int i = 0;i<tmp_row;i++)
        ui->tableWidget->removeRow(0);
    tmp_row = ui->tableWidget_2->rowCount();
    for(int k = 0;k<tmp_row;k++)
        ui->tableWidget_2->removeRow(0);
    tmp_row = ui->tableWidget_3->rowCount();
    for(int x = 0;x<tmp_row;x++)
        ui->tableWidget_3->removeRow(0);
    QString cur_Barcode = ui->listWidget->currentItem()->text();
    for(int j=0;j<m_tableInfo_vector.count();j++)
    {
        if(m_tableInfo_vector.at(j).at(1)==cur_Barcode)
        {

            if(m_tableInfo_vector.at(j).last()=="电流互感器检定误差")
            {

                ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
                for(int i=0;i<ui->tableWidget->columnCount();i++)
                {
                    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,i,new QTableWidgetItem(m_tableInfo_vector.at(j).at(i)));
                }
            }else if(m_tableInfo_vector.at(j).last()=="叠加直流检定误差")
            {
                ui->tableWidget_2->setRowCount(ui->tableWidget_2->rowCount()+1);
                for(int i=0;i<ui->tableWidget_2->columnCount();i++)
                {
                    ui->tableWidget_2->setItem(ui->tableWidget_2->rowCount()-1,i,new QTableWidgetItem(m_tableInfo_vector.at(j).at(i)));
                }
            }else if(m_tableInfo_vector.at(j).last()=="正弦半波检定误差")
            {
                ui->tableWidget_3->setRowCount(ui->tableWidget_3->rowCount()+1);
                for(int i=0;i<ui->tableWidget_3->columnCount();i++)
                {
                    ui->tableWidget_3->setItem(ui->tableWidget_3->rowCount()-1,i,new QTableWidgetItem(m_tableInfo_vector.at(j).at(i)));
                }
            }
        }
    }
}

void MainWindow::on_jointA_1_clicked()
{
    int rowCount = ui->tableWidget_6->rowCount();
    for(int i=0;i<rowCount;i++)
        ui->tableWidget_6->removeRow(0);

    QString cur_show = ui->task_no->text();
    for(int i=0;i<m_A_1Info_vector.count();i++)
    {
        if(m_A_1Info_vector.at(i).at(0)==cur_show)
        {
            ui->tableWidget_6->setRowCount(ui->tableWidget_6->rowCount()+1);
            for(int j=0;j<ui->tableWidget_6->columnCount();j++)
            {
                ui->tableWidget_6->setItem(ui->tableWidget_6->rowCount()-1,j,new QTableWidgetItem(m_A_1Info_vector.at(i).at(j)));
            }
        }
    }
}
QStringList MainWindow::handleCodeValue(QStringList row_data)
{
    if(row_data.last()=="电流互感器检定误差")
        row_data.last()="01";
    else if(row_data.last()=="叠加直流检定误差")
        row_data.last()="02";
    else
        row_data.last()="03";

    if(row_data.at(5)=="标准负荷")
        row_data.replace(5,"01");
    else
        row_data.replace(5,"02");

    row_data.replace(6,row_data.at(6)+"%");

    if(row_data.at(12)=="1.25A/5A")
        row_data.replace(12,"001");
    else if(row_data.at(12)=="2.5A/5A")
        row_data.replace(12,"002");
    else if(row_data.at(12)=="10A/5A")
        row_data.replace(12,"003");
    else if(row_data.at(12)=="15A/5A")
        row_data.replace(12,"004");
    else if(row_data.at(12)=="20A/5A")
        row_data.replace(12,"005");
    else if(row_data.at(12)=="25A/5A")
        row_data.replace(12,"006");
    else if(row_data.at(12)=="30A/5A")
        row_data.replace(12,"007");
    else if(row_data.at(12)=="35A/5A")
        row_data.replace(12,"008");
    else if(row_data.at(12)=="37.5A/5A")
        row_data.replace(12,"009");
    else if(row_data.at(12)=="40A/5A")
        row_data.replace(12,"010");
    else if(row_data.at(12)=="50A/5A")
        row_data.replace(12,"011");
    else if(row_data.at(12)=="60A/5A")
        row_data.replace(12,"012");
    else if(row_data.at(12)=="75A/5A")
        row_data.replace(12,"013");
    else if(row_data.at(12)=="80A/5A")
        row_data.replace(12,"014");
    else if(row_data.at(12)=="100A/5A")
        row_data.replace(12,"015");
    else if(row_data.at(12)=="120A/5A")
        row_data.replace(12,"016");
    else if(row_data.at(12)=="125A/5A")
        row_data.replace(12,"017");
    else if(row_data.at(12)=="150A/5A")
        row_data.replace(12,"018");
    else if(row_data.at(12)=="160A/5A")
        row_data.replace(12,"019");
    else if(row_data.at(12)=="200A/5A")
        row_data.replace(12,"020");
    else if(row_data.at(12)=="250A/5A")
        row_data.replace(12,"021");
    else if(row_data.at(12)=="300A/5A")
        row_data.replace(12,"022");
    else if(row_data.at(12)=="315A/5A")
        row_data.replace(12,"023");
    else if(row_data.at(12)=="400A/5A")
        row_data.replace(12,"024");
    else if(row_data.at(12)=="500A/5A")
        row_data.replace(12,"025");
    else if(row_data.at(12)=="600A/5A")
        row_data.replace(12,"026");
    else if(row_data.at(12)=="750A/5A")
        row_data.replace(12,"027");
    else if(row_data.at(12)=="800A/5A")
        row_data.replace(12,"028");
    else if(row_data.at(12)=="1000A/5A")
        row_data.replace(12,"029");
    else if(row_data.at(12)=="1200A/5A")
        row_data.replace(12,"030");
    else if(row_data.at(12)=="1250A/5A")
        row_data.replace(12,"031");
    else if(row_data.at(12)=="1500A/5A")
        row_data.replace(12,"032");
    else if(row_data.at(12)=="1600A/5A")
        row_data.replace(12,"033");
    else if(row_data.at(12)=="2000A/5A")
        row_data.replace(12,"034");
    else if(row_data.at(12)=="2500A/5A")
        row_data.replace(12,"035");
    else if(row_data.at(12)=="3000A/5A")
        row_data.replace(12,"036");
    else if(row_data.at(12)=="4000A/5A")
        row_data.replace(12,"037");
    else if(row_data.at(12)=="5000A/5A")
        row_data.replace(12,"038");
    else if(row_data.at(12)=="6000A/5A")
        row_data.replace(12,"039");
    else if(row_data.at(12)=="8000A/5A")
        row_data.replace(12,"040");
    else if(row_data.at(12)=="10000A/5A")
        row_data.replace(12,"041");
    else if(row_data.at(12)=="1A/1A")
        row_data.replace(12,"042");
    else if(row_data.at(12)== "50A/1A")
        row_data.replace(12,"043");
    else if(row_data.at(12)== "100A/1A")
        row_data.replace(12,"044");
    else if(row_data.at(12)=="150A/1A")
        row_data.replace(12,"045");
    else if(row_data.at(12)=="200A/1A")
        row_data.replace(12,"046");
    else if(row_data.at(12)=="250A/1A")
        row_data.replace(12,"047");
    else if(row_data.at(12)=="300A/1A")
        row_data.replace(12,"048");
    else if(row_data.at(12)=="400A/1A")
        row_data.replace(12,"049");
    else if(row_data.at(12)=="500A/1A")
        row_data.replace(12,"050");
    else if(row_data.at(12)=="600A/1A")
        row_data.replace(12,"051");
    else if(row_data.at(12)=="750A/1A")
        row_data.replace(12,"052");
    else if(row_data.at(12)=="800A/1A")
        row_data.replace(12,"053");
    else if(row_data.at(12)=="1000A/1A")
        row_data.replace(12,"054");
    else if(row_data.at(12)=="1200A/1A")
        row_data.replace(12,"055");
    else if(row_data.at(12)=="1500A/1A")
        row_data.replace(12,"056");
    else if(row_data.at(12)=="1600A/1A")
        row_data.replace(12,"057");
    else if(row_data.at(12)=="2000A/1A")
        row_data.replace(12,"058");
    else if(row_data.at(12)=="2500A/1A")
        row_data.replace(12,"059");
    else if(row_data.at(12)=="4000A/1A")
        row_data.replace(12,"060");
    else if(row_data.at(12)=="4500A/1A")
        row_data.replace(12,"061");
    else if(row_data.at(12)=="5000A/1A")
        row_data.replace(12,"062");
    else if(row_data.at(12)=="8000A/1A")
        row_data.replace(12,"063");
    else if(row_data.at(12)=="10000A/1A")
        row_data.replace(12,"064");
    else if(row_data.at(12)=="1250A/1A")
        row_data.replace(12,"00065");
    else if(row_data.at(12)=="5A/5A")
        row_data.replace(12,"00068");
    else if(row_data.at(12)=="3000A/1A")
        row_data.replace(12,"00074");
    else if(row_data.at(12)=="6000A/1A")
        row_data.replace(12,"00076");
    else if(row_data.at(12)=="2400A/5A")
        row_data.replace(12,"00079");
    else if(row_data.at(12)=="10000A/100A")
        row_data.replace(12,"00088");
    else if(row_data.at(12)=="1800A/5A")
        row_data.replace(12,"00089");
    else if(row_data.at(12)=="12000A/5A")
        row_data.replace(12,"00092");
    else if(row_data.at(12)=="3500A/5A")
        row_data.replace(12,"000101");
    else if(row_data.at(12)=="450A/5A")
        row_data.replace(12,"000120");
    else if(row_data.at(12)=="75A/1A")
        row_data.replace(12,"000131");
    else if(row_data.at(12)=="15000A/5A")
        row_data.replace(12,"000134");
    else if(row_data.at(12)=="20000A/5A")
        row_data.replace(12,"000135");
    else if(row_data.at(12)=="30000A/5A")
        row_data.replace(12,"000140");
    else if(row_data.at(12)=="40000A/5A")
        row_data.replace(12,"000141");
    else if(row_data.at(12)=="60000A/5A")
        row_data.replace(12,"000142");
    else if(row_data.at(12)=="5A/1A")
        row_data.replace(12,"000145");
    else if(row_data.at(12)=="10A/1A")
        row_data.replace(12,"000146");
    else if(row_data.at(12)=="15A/1A")
        row_data.replace(12,"000147");
    else if(row_data.at(12)== "20A/1A")
        row_data.replace(12,"000148");
    else if(row_data.at(12)=="30A/1A")
        row_data.replace(12,"000150");
    else if(row_data.at(12)=="40A/1A")
        row_data.replace(12,"000151");
    else if(row_data.at(12)=="60A/1A")
        row_data.replace(12,"000152");
    else if(row_data.at(12)=="14000A/1A")
        row_data.replace(12,"000176");
    else if(row_data.at(12)=="28000A/1A")
        row_data.replace(12,"000178");
    else if(row_data.at(12)=="10500A/5A")
        row_data.replace(12,"000191");
    else if(row_data.at(12)=="180A/5A")
        row_data.replace(12,"000206");
    else if(row_data.at(12)=="18000A/5A")
        row_data.replace(12,"000207");
    else if(row_data.at(12)=="20000A/10A")
        row_data.replace(12,"000214");
    else if(row_data.at(12)=="3A/1A")
        row_data.replace(12,"000220");
    else if(row_data.at(12)=="4A/1A")
        row_data.replace(12,"000231");
    else if(row_data.at(12)=="6A/1A")
        row_data.replace(12,"000245");
    else if(row_data.at(12)=="8A/1A")
        row_data.replace(12,"000254");
    else if(row_data.at(12)=="210000A/5A")
        row_data.replace(12,"000283");
    else if(row_data.at(12)=="6250A/5A")
        row_data.replace(12,"000284");
    else if(row_data.at(12)=="7000A/5A")
        row_data.replace(12,"000285");
    else if(row_data.at(12)=="12500A/5A")
        row_data.replace(12,"000286");
    else if(row_data.at(12)=="45000A/5A")
        row_data.replace(12,"000287");
    else if(row_data.at(12)=="50000A/5A")
        row_data.replace(12,"000288");
    else if(row_data.at(12)=="200000A/5A")
        row_data.replace(12,"000289");
    else if(row_data.at(12)=="600A/4A")
        row_data.replace(12,"000290");
    else if(row_data.at(12)=="400A/4A")
        row_data.replace(12,"000291");
    else if(row_data.at(12)=="300A/4A")
        row_data.replace(12,"000292");
    else if(row_data.at(12)=="2000A/4A")
        row_data.replace(12,"000293");
    else if(row_data.at(12)=="34A/1A")
        row_data.replace(12,"000294");
    else if(row_data.at(12)=="350A/5A")
        row_data.replace(12,"999");
    if(row_data.at(19)=="0.8")
        row_data.replace(19,"09");
    else
        row_data.replace(19,"01");
    if(row_data.at(20)=="合格")
        row_data.replace(20,"01");
    else
        row_data.replace(20,"02");
    if(row_data.at(21)=="A相")
        row_data.replace(21,"01");
    else if(row_data.at(21)=="B相")
        row_data.replace(21,"02");
    else if(row_data.at(21)=="C相")
        row_data.replace(21,"03");
    else if(row_data.at(21)=="AB相")
        row_data.replace(21,"04");
    else if(row_data.at(21)=="AC相")
        row_data.replace(21,"05");
    else if(row_data.at(21)=="BC相")
        row_data.replace(21,"06");
    else if(row_data.at(21)=="AB+BC相")
        row_data.replace(21,"06");
    return  row_data;
}
void MainWindow::on_update_ora_clicked()
{
    QVector<QStringList> update_data;
    QStringList row_data;
    int cur_row = ui->listWidget->currentRow();
    //将导入的数据全部插入到数据库中去
    for(int x=0;x<ui->listWidget->count();x++)
    {
        ui->listWidget->setCurrentRow(x);
        for(int y=0;y<3;y++)
        {
            if(y==0)
            {
                 for(int i=0;i<ui->tableWidget->rowCount();i++)
                 {
                     for(int j=0;j<ui->tableWidget->columnCount();j++)
                     {
                         row_data<<ui->tableWidget->item(i,j)->text();
                     }
                     update_data<<handleCodeValue(row_data);
                     row_data.clear();
                 }

            }else if(y==1)
            {
                for(int i=0;i<ui->tableWidget_2->rowCount();i++)
                {
                    for(int j=0;j<ui->tableWidget_2->columnCount();j++)
                    {
                        row_data<<ui->tableWidget_2->item(i,j)->text();
                    }
                    update_data<<handleCodeValue(row_data);
                    row_data.clear();
                }

            }else if(y==2)
            {
                for(int i=0;i<ui->tableWidget_3->rowCount();i++)
                {
                    for(int j=0;j<ui->tableWidget_3->columnCount();j++)
                    {
                        row_data<<ui->tableWidget_3->item(i,j)->text();
                    }
                    update_data<<handleCodeValue(row_data);
                    row_data.clear();
                }
            }
        }
        if(!m_analysis_sql->insertA_1(update_data))
            QMessageBox::warning(this,"提示","插入失败!");
        else
            QMessageBox::information(this,"提示","插入成功!");
        update_data.clear();

    }

    ui->listWidget->setCurrentRow(cur_row);
}

void MainWindow::on_bindInfo_clicked()
{
    if(ui->tableWidget_6->rowCount()<1)
        return ;
    QString DETECT_TASK_NO = ui->tableWidget_6->item(ui->tableWidget_6->currentRow(),0)->text();
    QString WRITE_DATE = ui->tableWidget_6->item(ui->tableWidget_6->currentRow(),18)->text();
    QString HANDLE_FLAG = ui->tableWidget_6->item(ui->tableWidget_6->currentRow(),19)->text();
    QString HANDLE_DATE = ui->tableWidget_6->item(ui->tableWidget_6->currentRow(),20)->text();

    int count = ui->tableWidget->rowCount();
    for(int i=0;i<count;i++)
    {
        ui->tableWidget->item(i,0)->setText(DETECT_TASK_NO);
        ui->tableWidget->item(i,2)->setText(WRITE_DATE);
        ui->tableWidget->item(i,3)->setText(HANDLE_FLAG);
        ui->tableWidget->item(i,4)->setText(HANDLE_DATE);
    }
    count = ui->tableWidget_2->rowCount();
    for(int i=0;i<count;i++)
    {
        ui->tableWidget_2->item(i,0)->setText(DETECT_TASK_NO);
        ui->tableWidget_2->item(i,2)->setText(WRITE_DATE);
        ui->tableWidget_2->item(i,3)->setText(HANDLE_FLAG);
        ui->tableWidget_2->item(i,4)->setText(HANDLE_DATE);
    }
    count = ui->tableWidget_3->rowCount();
    for(int i=0;i<count;i++)
    {
        ui->tableWidget_3->item(i,0)->setText(DETECT_TASK_NO);
        ui->tableWidget_3->item(i,2)->setText(WRITE_DATE);
        ui->tableWidget_3->item(i,3)->setText(HANDLE_FLAG);
        ui->tableWidget_3->item(i,4)->setText(HANDLE_DATE);
    }
    for(int i=0;i<m_tableInfo_vector.count();i++)
    {
        if(ui->barCode->currentText()==m_tableInfo_vector.at(i).at(1))
        {
            QStringList tmp = m_tableInfo_vector.at(i);
            tmp.replace(0,DETECT_TASK_NO);
            tmp.replace(2,WRITE_DATE);
            tmp.replace(3,HANDLE_FLAG);
            tmp.replace(4,HANDLE_DATE);
            m_tableInfo_vector.replace(i,tmp);
        }
    }

}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    QStringList barCode_list;
    for(int i=0;i<m_barCode_vector.count();i++)
        barCode_list<<m_barCode_vector.at(i);
    ui->barCode->clear();
    ui->barCode->addItems(barCode_list);
}
