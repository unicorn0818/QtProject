#include "configdialog.h"
#include "ui_configdialog.h"

configDialog::configDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::configDialog)
{
    ui->setupUi(this);
    initConfig();
}

configDialog::~configDialog()
{
    delete ui;
}

void configDialog::initConfig()
{
    //读取配置信息并显示
    QSettings *config = new QSettings("./SysConfig.ini", QSettings::IniFormat);
    QString IP = config->value("ip").toString();
    QString PASSWORD = config->value("password").toString();
    QString USERNAME = config->value("username").toString();
    QString PORT = config->value("port").toString();
    QString DATABASENAME = config->value("database").toString();
    QString FILENAME = config->value("filename").toString();
    //恢复关闭软件前保存的信息
    ui->FileNameLE->setText(FILENAME);
    ui->DataBaseNameLE->setText(DATABASENAME);
    ui->PortLE->setText(PORT);
    ui->UserNameLE->setText(USERNAME);
    ui->HostNameLE->setText(IP);
    ui->PassWordLE->setText(PASSWORD);
    ui->DisLinkDBBT->setEnabled(false);
}

void configDialog::setConMode(bool flag)
{
   ui->DisLinkDBBT->setEnabled(flag);
   ui->LinkDBBT->setEnabled(!flag);
}

void configDialog::on_LinkDBBT_clicked()
{
    //保存信息
    QSettings *config = new QSettings("./SysConfig.ini", QSettings::IniFormat);
    config->setValue("ip", ui->HostNameLE->text());
    config->setValue("database",ui->DataBaseNameLE->text());
    config->setValue("port",ui->PortLE->text());
    config->setValue("username",ui->UserNameLE->text());
    config->setValue("password",ui->PassWordLE->text());
    QStringList info_list;
    info_list<<ui->UserNameLE->text()<<ui->PassWordLE->text()<<ui->PortLE->text()<<ui->HostNameLE->text()<<ui->DataBaseNameLE->text();
    emit conOracle(info_list);
}

void configDialog::on_DisLinkDBBT_clicked()
{
    emit disConOracle();
}

void configDialog::on_OpenFileBT_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,"文件选择","./myxml","*.xml");
    //如果文件不为空
    if(!filename.isEmpty())
    {
        //将文件名显示在LE上并保存到配置文件中
        ui->FileNameLE->setText(filename);
        QSettings *config = new QSettings("./SysConfig.ini", QSettings::IniFormat);
        config->setValue("filename",ui->FileNameLE->text());
        emit loadXml(filename);
    }
}
