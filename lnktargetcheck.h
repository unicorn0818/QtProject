#ifndef LNKTARGETCHECK_H
#define LNKTARGETCHECK_H
#pragma  execution_character_set("UTF-8")
#include <QObject>

class LnkTargetCheck : public QObject
{
	Q_OBJECT

public:
	LnkTargetCheck(QObject *parent);
	~LnkTargetCheck();

	//检查开机启动快捷方式是否不是本程序 （比本程序 低的版本），如果是，则提示。
	static bool checkStartLink();
	//设置桌面及开机启动方式
	static bool setLnk();
private:
	//检测指定快捷方式目录中是否有需要 更新或添加快捷启动项
	static bool linkChech(const QString &linkDirPath,const QString &targetFileName);
	
};

#endif // LNKTARGETCHECK_H
