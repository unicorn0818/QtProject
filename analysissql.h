#ifndef ANALYSISSQL_H
#define ANALYSISSQL_H

#include <QObject>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QTime>
#include <QTimer>
#include <QMessageBox>
class analysisSQL : public QObject
{
    Q_OBJECT
public:
    explicit analysisSQL(QObject *parent = nullptr);
    //判断数据库是否链接
    inline bool getIsOpenMds()const { return db.isOpen();}
    //链接数据库
    bool Link(QString Username,QString Password,int Port,QString IP,QString Database);
    //断开链接
    bool DisLink();
    //查询Bar_code
    bool selectBarCode(QString);
    //拼接A_1表
    void jointA_1();
    //插入A_1表
    bool insertA_1(QVector<QStringList>);
    static bool linkFlag;
    static bool selectFlag;
signals:
    void A_1Data(QStringList);


private:
    QSqlDatabase db;
};

#endif // ANALYSISSQL_H
