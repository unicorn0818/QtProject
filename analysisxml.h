#ifndef ANALYSISXML_H
#define ANALYSISXML_H

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


class analysisXML : public QObject
{
    Q_OBJECT
public:
    analysisXML();
        void E_1_2_get();
    void setIndexNull();
    //拼接E_1_2信息
    bool joint_E_1_2(QString);
    //拼接E_1_3信息
    bool joint_E_1_3(QString);
private://解析xml
    QMap<QString, QString> Tabletest(QDomNode &domNode);//表检测
    QList<QMap<QString, QString> > DealChildData(QDomNode &domNode, QString &bar_code);//其它信息
private://通过条形码找出该表要的值
    QString FineTableTextData(const QString bar_code, const QString key);
    QList<QMap<QString, QString> > FineTableName(const QString, const QString);
    //处过条形码加表的名字找出信息
private:
    //这里是mds查询到的一些必要信息为上传表个别地方所用到
    //参数：  条形码, 设备类型, 系统编号 , 检定线台编号 检定任务编号
    QHash<QString, QStringList>m_joint_C1_Hash;
private://key == bar_code
    QMap<QString, QMap<QString, QList<QMap<QString, QString>>>> m_xmlTabelDate;
    QMap<QString, QMap<QString, QString>>m_TableText;//表的信息
private://拼接信息
    void joint_C1(QString);
    void joint_C2(QString);
    void joint_C3(QString);
    void joint_C4(QString);
    void joint_C5(QString);
    void joint_C7(QString);
    void joint_C16(QString);
    void joint_C25(QString);
    void joint_C34(QString);

    //加载xml表的所有数据显示到mis上面去
    void JointMIS(QString tBar_code);
Q_SIGNALS://上报拼接好的表信息到界面中显示
    void signals_C1(QStringList);
    void signals_C2(QStringList);
    void signals_C3(QStringList);
    void signals_C4(QStringList);
    void signals_C5(QStringList);
    void signals_C7(QStringList);
    void signals_C16(QStringList);
    void signals_C25(QStringList);
   void signals_C34(QStringList);
   void error_info1(QStringList);
   void error_info2(QStringList);
    //下发数据到mis界面中显示出来
    void signals_DealSampleList(QStringList);
Q_SIGNALS://上报一些消息， 包括错误等等
    void InstallReportMsg(QString, QString, QString, QString);
    //发送实时解析进度
    void current_pre(qreal);
Q_SIGNALS:
    void signals_Bar_Code(QString bar_code);//这个信号发送到数据库中查询
    void signals_WebList(QStringList);//上传查询到的数据显示到web中
    void signals_CreateXmlOk();//创建xml成功
private Q_SLOTS:
    void load_DealXML(QString);//处理传进xml表的地址及处理出所有数据
    void slotLocalConfig(QString, QString, QString, QString, QString, QString, QString, QString);
    void send_gui_info(QString,QString);
private Q_SLOTS:
    //生成xml到本地并
    void slots_CreateXMLFile(QStringList);
    //重新加载ff
    void slots_AgainLocalXML();
    void get_show_list(QStringList list);
private:
    void WriteSample(QStringList &xml, QXmlStreamWriter &xmlWriter);
    void WriteProject(QString projectNo, QString projectName, QString findName, QStringList &xml, QXmlStreamWriter &xmlWriter);
    void WriteProjectINFLUENCEQTY(QString projectNo, QString projectName, QString findName, QStringList &xml, QXmlStreamWriter &xmlWriter);
private:
    qreal precent;
    volatile bool NotAgainLocal;//是否重新加载 真为重新加载
    int C1_index, C2_index, C3_index,C4_index, C5_index, C16_index, C25_index, C34_index, C7_index;
    QString Equip_no, DETECT_PERSON,AUDIT_PERSON, STD_CERT_NO,
    STD_CERT_NO_PERIOD, CERT_NO, CERT_NO_PERIOD, EXPIRATION_DATE;//检定人员,审核人员

   QString sINTUIT_MET_CONC_ProjectNo;//外观检查
   QString sBASICERR_ProjectNo;//基本误差
   QString sSTARTING_METCONC_ProjectNo;//启动
   QString sCREEP_MET_CONC_ProjectNo;//潜动
   QString sMEASURE_REPEAT_MET_CONC_ProjectNo;//重复性
   QString sINFLUENCE_QTY_MET_CONC_ProjectNo;//影响量
    QStringList list;
    //以下的参数手动在配置表中改
    //    STD_CERT_NO=标准器证书编号
    //    STD_CERT_NO_PERIOD=标准器证书编号有效期
    //    CERT_NO=计量装置证书编号
    //    CERT_NO_PERIOD=计量装置证书编号有效期
   //    EXPIRATION_DATE=检定合格证的有效日期
    //检定线/台体编号[必传，标准装置的条码号]
    QString m_DETECT_EQUIP_NO;
    //检定单元编号[必传，标准器的条码号]
    QString m_DETECT_UNIT_NO;
};

#endif // ANALYSISXML_H
