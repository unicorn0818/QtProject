#ifndef ANALYSISXML_H
#define ANALYSISXML_H

#include <QObject>
#include <QDomDocument>
#include <QFile>
#include <QMap>
#include <QList>
#include <QHash>
#include <QUuid>
#include <QStringList>
#include <QObject>
#include <QDebug>
#include <QDateTime>
#include <QSettings>
#include <QTextCodec>
#include <QDir>
#include <QXmlStreamWriter>
#include <QSqlDatabase>
#include <QMessageBox>
#include <analysissql.h>
class analysisXml : public QObject
{
    Q_OBJECT
public:
    analysisXml();
    //加载xml文件
    void loadXml(QString);
    QMap<QString, QString> Tabletest(QDomNode &domNode);
    QList<QMap<QString, QString> > dealChildData(QDomNode &domNode);
    void jointTable(QMap<QString, QString> text, QVector<QMap<QString,QList<QMap<QString,QString>>>> data);
signals:
    void selectBarCode(QString);
    void tableData(QStringList);
    void finishLoad();

};

#endif // ANALYSISXML_H
