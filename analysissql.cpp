#include "analysissql.h"

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
        return true;
}
//断开链接
bool analysisSQL::DisLink()
{
    //如果数据库打开了，则关闭
    if(db.isOpen())
    {
        db.close();
        QString str = "断开数据库成功 | "+QTime::currentTime().toString("hh:mm:ss");
        qDebug(str.toStdString().c_str());
    }
    return true;
}
//通过code到mds中查询电能表基本信息并返回显示在表中
void analysisSQL::ExectSQL_MDS(QString str)
{
    if(!getIsOpenMds())//如果没有打开就不查询了
        return;
    QString strSQL;
    strSQL = QString("select * from  M_EQUIP_INFO where BAR_CODE ='%1'").arg(str);
    //查询表E_1_1
    if(!selectE_1_1(strSQL))
    {
        QString str ="查询M_EQUIP_INFO失败 | "+QTime::currentTime().toString("hh:mm:ss");
        qWarning(str.toStdString().c_str());
        return ;
    }
}
//将数据插入到数据库中
void analysisSQL::get_insert_Data(QVector<QStringList> insert_list,int type)
{
    QString sql,sql1,sql2,info;
    QStringList backList;
    int flag = 0;
    if(type==1)
    {
        QString str = "准备上传数据到M_DETECT_RSLT | "+QTime::currentTime().toString("hh:mm:ss");
        qDebug(str.toStdString().c_str());
        //qDebug()<<"insert table of first";
         sql = "";
         for(int i=0;i<insert_list.count();i++)
         {
             info = "";
            for(int j=0;j<insert_list.at(i).count();j++)
            {
                info+="'"+insert_list.at(i).at(j)+"',";
                backList.append("'"+insert_list.at(i).at(j)+"',");
            }
            sql1 = "insert into M_DETECT_RSLT(READ_ID,EQUIP_ID,BAR_CODE,EQUIP_NAME,DETECT_TASK_NO,"
                          "PROF_CATEG,EQUIP_CATEG,EQUIP_TYPE,ITEM_ID,ITEM_NAME,TEST_GROUP,SYS_NO,DETECT_EQUIP_NO,"
                          "DETECT_UNIT_NO,POSITION_NO,DETECT_DATE,DETECT_ITEM_POINT,DATA_SOURCE,DATA_TYPE,ENVIRON_TEMPER,"
                          "RELATIVE_HUM,DATA_ITEM1,DATA_ITEM2,DATA_ITEM3,DATA_ITEM4,DATA_ITEM5,DATA_ITEM6,DATA_ITEM7,DATA_ITEM8,"
                          "DATA_ITEM9,DATA_ITEM10,DATA_ITEM11,DATA_ITEM12,DATA_ITEM13,CHK_CONC_CODE,WRITE_DATE,HANDLE_FLAG,HANDLE_DATE) "
                          "values(%1)";
            sql1 = QString(sql1).arg(info);
            int ret = sql1.lastIndexOf(",");
            sql1.remove(ret,1);
            QSqlQuery query;
            if(!query.exec(sql1))
            {
                QString string("上传失败"+db.lastError().text()+" | "+QTime::currentTime().toString("hh:mm:ss"));
                const char *str = string.toStdString().c_str();
                qWarning(str);
                return ;
            }
            else
            {
                qDebug()<<"emit";
                emit addWebInfo(backList.at(4),backList.at(12));
            }

         }
         emit next_insert();

    }
    else if(type == 2)
    {
        QString str = "准备上传数据到M_DETECT_RSLT1 | "+QTime::currentTime().toString("hh:mm:ss");
        qDebug(str.toStdString().c_str());
        //qDebug()<<"insert table of second";
        sql = "";

        for(int i=0;i<insert_list.count();i++)
        {
            info = "";
           for(int j=0;j<insert_list.at(i).count();j++)
           {
               info+="'"+insert_list.at(i).at(j)+"',";
               backList.append("'"+insert_list.at(i).at(j)+"',");
           }
           sql1 = "insert into M_DETECT_RSLT(READ_ID,EQUIP_ID,BAR_CODE,EQUIP_NAME,DETECT_TASK_NO,"
                         "PROF_CATEG,EQUIP_CATEG,EQUIP_TYPE,ITEM_ID,ITEM_NAME,TEST_GROUP,SYS_NO,DETECT_EQUIP_NO,"
                         "DETECT_UNIT_NO,POSITION_NO,DETECT_DATE,DETECT_ITEM_POINT,DATA_SOURCE,DATA_TYPE,ENVIRON_TEMPER,"
                         "RELATIVE_HUM,DATA_ITEM1,CHK_CONC_CODE,WRITE_DATE,HANDLE_FLAG,HANDLE_DATE) "
                         "values(%1)";
           sql1 = QString(sql1).arg(info);
           int ret = sql1.lastIndexOf(",");
           sql1.remove(ret,1);
           QSqlQuery query(QSqlDatabase::database("TEST"));
           if(!query.exec(sql1))
           {
               QString string("上传失败"+db.lastError().text()+" | "+QTime::currentTime().toString("hh:mm:ss"));
               const char *str = string.toStdString().c_str();
               qWarning(str);
               return ;
           }
           else
           {
               emit addWebInfo(backList.at(4),backList.at(12));
           }
        }
        emit finished();
    }
}
//查询并获得数据
bool analysisSQL::selectE_1_1(QString str)
{
    QString str1 = "正在查询数据库中的基本信息表 | "+QTime::currentTime().toString("hh:mm:ss");
    qDebug(str1.toStdString().c_str());
    QSqlQuery query;
    if(!query.exec(str))
    {
        QString string("查询失败"+db.lastError().text()+" | "+QTime::currentTime().toString("hh:mm:ss"));
        const char *str = string.toStdString().c_str();
        qWarning(str);
        return false;
    }
    else
    {
        QStringList list;
        while(query.next())
        {
            list<<query.value("READ_ID").toString();//1
            list<<query.value("EQUIP_ID").toString();//2
            list<<query.value("BAR_CODE").toString();//3
            list<<query.value("EQUIP_NAME").toString();//4
            list<<query.value("DETECT_TASK_NO").toString();//5
            list<<query.value("SUBTAS_ID").toString();//6
            list<<query.value("PROF_CATEG").toString();//7
            list<<query.value("EQUIP_CATEG").toString();//8
            list<<query.value("EQUIP_TYPE").toString();//9
            list<<query.value("MANUFACTURER").toString();//10
            list<<query.value("MADE_NO").toString();//11
            list<<query.value("MODEL_CODE").toString();//12
            list<<query.value("PRE_LEVEL_CODE").toString();//13
            list<<query.value("TEST_SPEC").toString();//14
            list<<query.value("CERTIFICATE_NO").toString();//15
            list<<query.value("VOLTAGE_RANGE").toString();//16
            list<<query.value("CURRENT_RANGE").toString();//17
            list<<query.value("DATA_ITEM24").toString();//18
            list<<query.value("DATA_ITEM25").toString();//19
            list<<query.value("VERIFICATION_BASIS").toString();//20
        }
        QString str1 = "查询成功 | "+QTime::currentTime().toString("hh:mm:ss");
        qDebug(str1.toStdString().c_str());
        emit show_list(list);
        return true;
    }

}



