#include "lnktargetcheck.h"
#include <QCheckBox>
#include <QDir>
#include <QFileInfo>
#include <QProcess>
#include <QStandardPaths>
#include <QSerialPortInfo>
#include <QMessageBox>
#include <QFileDialog>
#include <QSettings>
#include <QtWidgets/QApplication>

LnkTargetCheck::LnkTargetCheck(QObject *parent)
	: QObject(parent)
{

}

LnkTargetCheck::~LnkTargetCheck()
{

}
bool LnkTargetCheck::setLnk()
{
	//首先
	QString targetFileName = QFileInfo(QApplication::applicationFilePath()).fileName();
	if(linkChech(QStandardPaths::writableLocation(QStandardPaths::DesktopLocation),targetFileName))
	{
		QMessageBox::information(0,tr("提示"),tr("桌面快捷方式添加成功！"));
	}else
	{
		QMessageBox::warning(0,tr("警告"),tr("桌面快捷方式添加失败！"));
	}
	if(linkChech(QStandardPaths::writableLocation(QStandardPaths::ApplicationsLocation).append(QString("\\%1").arg(tr("启动"))),targetFileName))
	{
		QMessageBox::information(0,tr("提示"),tr("开机启动项添加成功！"));
	}else
	{
		QMessageBox::warning(0,tr("警告"),tr("开机启动项添加失败！"));
	}
	return true;
}
bool LnkTargetCheck::checkStartLink()
{
	QString linkName;		//原来链接名
	//查找有指向当前目录的快捷方式
	QDir linkDir(QStandardPaths::writableLocation(QStandardPaths::DesktopLocation));
	QStringList fileLst = linkDir.entryList(QStringList() << QString("*.lnk"),QDir::Files,QDir::Name);
	foreach(QString s,fileLst)
	{
		QFileInfo linkTarget = QFileInfo(QFile::symLinkTarget(QFileInfo(linkDir,s).absoluteFilePath()));
		if(linkTarget.absolutePath() == QCoreApplication::applicationDirPath())
		{//有快捷方式的目标文件就在当前这个 目录里。
			linkName = linkTarget.fileName();
			break;
		}
	}

	//不再询问列表
	QSettings m_setting("../DCStandMeter.ini",QSettings::IniFormat);
	m_setting.beginGroup(staticMetaObject.className());

	QStringList strLst;
	strLst = m_setting.value("questLst").toStringList();
	m_setting.endGroup();

	QString appName = QFileInfo(QApplication::applicationFilePath()).fileName();
	if(!linkName.isEmpty() && !strLst.contains(appName) && appName != linkName)
	{//现有的链接不是指向该文件
		QString str = tr("原快捷方式为“%1”，是否更改为“%2”？").arg(linkName).arg(appName);
		QMessageBox messBox(QMessageBox::Question,tr("快捷方式"),str,QMessageBox::Yes | QMessageBox::No);
		messBox.setCheckBox(new QCheckBox(tr("不再询问"),&messBox));

		if(QMessageBox::Yes == messBox.exec())
		{
			setLnk();
			if(messBox.checkBox() && messBox.checkBox()->isChecked())
			{
				QSettings m_setting("../DCStandMeter.ini",QSettings::IniFormat);
				m_setting.beginGroup(staticMetaObject.className());

				QStringList strLst;
				strLst = m_setting.value("questLst").toStringList();
				strLst.append(appName);
				m_setting.setValue("questLst",strLst);

				m_setting.endGroup();
			}
		}
	}
	return true;
}
bool LnkTargetCheck::linkChech(const QString &linkDirPath,const QString &targetFileName)
{
	QString linkName = QString("%1.lnk").arg(targetFileName.split(" ").first());		//默认名称
	//查找有指向当前目录的快捷方式
	QDir linkDir(linkDirPath);		//启动目录
	QStringList fileLst = linkDir.entryList(QStringList() << QString("*.lnk"),QDir::Files,QDir::Name);
	foreach(QString s,fileLst)
	{
		if(QFileInfo(QFile::symLinkTarget(QFileInfo(linkDir,s).absoluteFilePath())).absolutePath() == QCoreApplication::applicationDirPath())
		{//有快捷方式的目标文件就在当前这个 目录里。
			linkName = s;
			break;
		}
	}
	
	bool ret = QFile::link(QFileInfo(QDir(QCoreApplication::applicationDirPath()),targetFileName).absoluteFilePath(),QFileInfo(linkDir,linkName).absoluteFilePath());
	if(ret)
	{
		if(QProcess::startDetached("FbwfMgr"))
		{//用的系统保护是FbwfMgr的话
			QStringList strLst;
			strLst << "/commit" << "c:" << QFileInfo(linkDir,linkName).absoluteFilePath().mid(2).replace("/","\\");
			QProcess::execute("FbwfMgr",strLst);
			return true;
		}else if(QProcess::startDetached("ewfmgr"))
		{
			QStringList strLst;
            strLst << QFileInfo(linkDir,linkName).absoluteFilePath().replace("/","\\") << " -commit";
			QProcess::execute("ewfmgr",strLst);
			return true;
		}
	}
	return ret;
}
