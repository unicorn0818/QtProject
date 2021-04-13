#include "analysissql.h"
bool analysisSQL::linkFlag=false;
bool analysisSQL::selectFlag=false;
analysisSQL::analysisSQL(QObject *parent) : QObject(parent)
{
}
//链接数据库
bool analysisSQL::Link(QString Username, QString Password, int Port, QString IP, QString Database)
{
    db = QSqlDatabase::addDatabase("QOCI");
    db.setPort(Port);
    db.setHostName(IP);
    db.setDatabaseName(Database);
    db.setUserName(Username);
    db.setPassword(Password);

    //如果数据库打开失败
    if(!db.open()) {
        //记录失败信息到日志中
        //如果数据库链接超时会导致界面阻塞，未解决(可尝试多线程)
        QString string("数据链接失败"+db.lastError().text()+" | "+QTime::currentTime().toString("hh:mm:ss"));
        const char *str = string.toStdString().c_str();
        qWarning(str);
        return false;
    }
    else
    {
        analysisSQL::linkFlag=true;
        return true;
    }
}
//断开链接
bool analysisSQL::DisLink()
{
//    QSqlDatabase db;
    //如果数据库打开了，则关闭
    if(db.isOpen())
    {
        db.close();
        QString str = "断开数据库成功 | "+QTime::currentTime().toString("hh:mm:ss");
        qDebug(str.toStdString().c_str());
    }
    return true;
}
//到表中查询是否存在 有这个barcode
bool analysisSQL::selectBarCode(QString bar_code)
{
    QSqlQuery query;
    query.exec(QString("select * from MT_DETECT_OUT_EQUIP where bar_code = '%1'").arg(bar_code));
    if(!query.next())
        return false;
    else
        return true;
}

void analysisSQL::jointA_1()
{
    QSqlQuery query;
    query.exec("select DETECT_TASK_NO ,TASK_PRIO, DETECT_MODE,SYS_NO, ARRIVE_BATCH_NO, \
               EQUIP_CATEG ,MODEL_CODE ,ERP_BATCH_NO ,SCHEMA_ID ,REDETECT_SCHEMA, REDETECT_FLAG ,\
              REDETECT_QTY, EQUIP_QTY, PILE_QTY ,EXEC_RESP_NAME, APPR_NAME, IS_AUTO_SEAL ,TASK_STATUS ,\
              WRITE_DATE, HANDLE_FLAG ,HANDLE_DATE ,EQUIP_CODE_NEW, PARAM_TYPE from MT_DETECT_TASK where SYS_NO \
                = '200311'");
    QStringList tmp;
    while (query.next()) {
        tmp.clear();
        for(int i=0;i<23;i++)
        {
           tmp<<query.record().value(i).toString();
        }
        emit A_1Data(tmp);
    }
}

bool analysisSQL::insertA_1(QVector<QStringList> row_data)
{
     QSqlQuery query;
     QString str,tmp;
     for(int i=0;i<row_data.count();i++)
     {
        for(int j=0;j<row_data.at(i).count();j++)
        {
            str="'"+row_data.at(i).at(j)+"',";
            tmp.append(str);
        }
        tmp.remove(tmp.lastIndexOf(","),1);
        QString sql = QString("insert into MT_DETECT_OUT_EQUIP_Test(DETECT_TASK_NO,BAR_CODE,WRITE_DATE,HANDLE_FLAG,HANDLE_DATE,LOAD_FLAG,ERR_ITEM,\
                              RATIO_ERR,ANGLE_ERR,RATIO_AMEND_ERR,ANGLE_AMEND_ERR,PARA_INDEX,RC_RATIO_CODE,SYS_NO,DETECT_EQUIP_NO,DETECT_UNIT_NO,POSITION_NO,\
                              DETECT_ITEM_POINT,IS_VALID,PF,CONC_CODE,PHASE_CODE,LIFTING_FLAG,ERR_TYPE) values(%1)").arg(tmp);
        if(!query.exec(sql))
        {
           qDebug()<<"error"<<db.lastError();
           return false;
        }
        tmp.clear();
     }
     return true;
}
