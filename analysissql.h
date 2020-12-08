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
    //查询表E_1_1
    bool selectE_1_1(QString str);

signals:
    void show_list(QStringList);
    void Insert_State(int);
    void next_insert();
    void finished();
    void addWebInfo(QString,QString);
private slots:
    void ExectSQL_MDS(QString);
    void get_insert_Data(QVector<QStringList>,int);
private:
    QSqlDatabase db;
};

#endif // ANALYSISSQL_H
