#if _MSC_VER >= 1600    // VC2010
#pragma  execution_character_set("UTF-8")
#endif

#include "analysisxml.h"


analysisXML::analysisXML()
{
    qRegisterMetaType<QVector<QString> >("myvector");

    Equip_no = "20161117";
    NotAgainLocal = false;
    C3_index = C7_index = C1_index=C2_index=C4_index=C5_index=C16_index=C25_index=C34_index = 0;
}

void analysisXML::E_1_2_get()
{

}

void analysisXML::setIndexNull()
{
    C3_index = C7_index = C1_index=C2_index=C4_index=C5_index=C16_index=C25_index=C34_index = 0;
}

//基本误差
bool analysisXML::joint_E_1_2(QString code)
{
    //qDebug()<<"m_xmlTabelDate.value(code).find("").value().count()"<<m_xmlTabelDate.value(code).find("基本误差").value().count();
    for(int i=0;i<m_xmlTabelDate.value(code).find("基本误差").value().count();i++)
    {
        QString READ_ID = QUuid::createUuid().toString().remove("{").remove("}").remove("-");//主键:uuid码
        QString EQUIP_ID = list.at(1);//设备id：在e.1.1查到的
        QString BAR_CODE = code;//条形码：由xml文件提供
        QString EQUIP_NAME = list.at(3);//设备名称：在e.1.1查到的
        QString DETECT_TASK_NO = list.at(4);//检定单编号
        QString PROF_CATEG = list.at(6);//设备专业
        QString EQUIP_CATEG= list.at(7);//设备大类
        QString EQUIP_TYPE = list.at(8);//设备小类
                                                                 //试验项id：不知道
                                                                 QString ITEM_ID;
        //基本误差
        QString ITEM_NAME = "基本误差";//试验项名称
        QString TEST_GROUP = "基本误差";//试验分组
                                                                 //系统编号：不知道
                                                                 QString SYS_NO;
        //从界面中导入
        //检定线/台体编号[必传，标准装置的条码号]
        QString DETECT_EQUIP_NO = m_DETECT_EQUIP_NO;
        //检定单元编号[必传，标准器的条码号]
        QString DETECT_UNIT_NO = m_DETECT_UNIT_NO;
                                                                 //表位编号：不知道
                                                                 QString POSITION_NO;

        //剩下的都是在导入的xml中获得的
        //检定/校准日期
        QString DETECT_DATE = m_TableText.value(code).value("检定日期");
        //检定点的序号，每个检定项可以检定多个点[必传，各试验项数据展示的序列号，我们将order by 该字段展示到报告里。]
        QString DETECT_ITEM_POINT = QString::number(i);
        //数据来源01系统录入，02自动上传
        QString DATA_SOURCE = "02";
        //数据类型01报告数据，02原始数据
        QString DATA_TYPE = "01";
        //温度
        QString ENVIRON_TEMPER = m_xmlTabelDate.value(code).find("其它信息").value().at(5).value("值");
        //湿度
        QString RELATIVE_HUM = m_xmlTabelDate.value(code).find("其它信息").value().at(6).value("值");
                                                                 //接线方式
                                                                 QString DATA_ITEM1;
        //电压（码值类型transmitVoltage）
        QString DATA_ITEM2 = m_xmlTabelDate.value(code).find("基本误差").value().at(i).value("电压");
        //电流（码值类型transmitCurrent）
        QString DATA_ITEM3 = m_xmlTabelDate.value(code).find("基本误差").value().at(i).value("电流");
        //相别（填写值必需是 三相合元件、A相、B相、C相）
        QString DATA_ITEM4 = m_xmlTabelDate.value(code).find("基本误差").value().at(i).value("元件");
        //功率因数 （例：1.0、0.5L、0.8C）
        QString DATA_ITEM5 = m_xmlTabelDate.value(code).find("基本误差").value().at(i).value("COS");
        //误差值，以逗号区分误差值传入该字段下（例：-0.0015，-0.0008）
        QString DATA_ITEM6 = m_xmlTabelDate.value(code).find("基本误差").value().at(i).value("误差0")+","+m_xmlTabelDate.value(code).find("基本误差").value().at(i).value("误差1");
        //误差平均值
        QString DATA_ITEM7 = m_xmlTabelDate.value(code).find("基本误差").value().at(i).value("均值");
        //化整值（%）（例：+0.035）
        QString DATA_ITEM8  = m_xmlTabelDate.value(code).find("基本误差").value().at(i).value("均值化整");
        //S值（%）（例：0.0025、/）要求数值或空
        QString DATA_ITEM9 = "/";
        //有无功 01：有功 02：无功
        QString DATA_ITEM10;
        if(m_xmlTabelDate.value(code).find("基本误差").value().at(i).value("有无功")=="有功")
            DATA_ITEM10 = "01";
        else
        DATA_ITEM10 = "02";
        //量程（码值类型 单相：singlePhaseRange，
        //三相：threePhaseRange）
        QString DATA_ITEM11 = "03";
        //输入量（码值类型 单相：singlePhaseInput，
        //三相：threePhaseInput）
        QString DATA_ITEM12 = "07";
        //频率
        QString DATA_ITEM13 = m_xmlTabelDate.value(code).find("启动测试").value().at(0).value("频率");
        //鉴定结论，结论（例：01：合格:02：不合格）
        QString CHK_CONC_CODE;
        if(m_xmlTabelDate.value(code).find("基本误差").value().at(i).value("结论")=="合格")
            CHK_CONC_CODE = "01";
        else
            CHK_CONC_CODE = "02";

        //写入时间
        QString WRITE_DATE = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:s");
                                                                    QString HANDLE_FLAG;
        //处理时间
        QString HANDLE_DATE = WRITE_DATE;

        QStringList list;
        list<<READ_ID<<EQUIP_ID<<BAR_CODE<<EQUIP_NAME<<DETECT_TASK_NO<<PROF_CATEG<<EQUIP_CATEG<<EQUIP_TYPE<<ITEM_ID<<ITEM_NAME<<TEST_GROUP<<SYS_NO;
        list<<DETECT_EQUIP_NO<<DETECT_UNIT_NO<<POSITION_NO<<DETECT_DATE<<DETECT_ITEM_POINT<<DATA_SOURCE<<DATA_TYPE<<ENVIRON_TEMPER<<RELATIVE_HUM;
        list<<DATA_ITEM1<<DATA_ITEM2<<DATA_ITEM3<<DATA_ITEM4<<DATA_ITEM5<<DATA_ITEM6<<DATA_ITEM7<<DATA_ITEM8<<DATA_ITEM9<<DATA_ITEM10<<DATA_ITEM11;
        list<<DATA_ITEM12<<DATA_ITEM13<<CHK_CONC_CODE<<WRITE_DATE<<HANDLE_FLAG<<HANDLE_DATE;
        emit error_info1(list);
    }
    return true;
}
//起动测试
bool analysisXML::joint_E_1_3(QString code)
{
    for(int i=0;i<m_xmlTabelDate.value(code).find("启动测试").value().count();i++)
    {
        QString READ_ID = QUuid::createUuid().toString().remove("{").remove("}").remove("-");//主键:uuid码
        QString EQUIP_ID = list.at(1);             //  设备id
        QString BAR_CODE = code;                   // 条形码
        QString EQUIP_NAME = list.at(3);           // 设备名称（码值类型equipName）
        QString DETECT_TASK_NO = list.at(4);       // 检定任务单编号
        QString PROF_CATEG = list.at(6);           // 设备专业（码值类型measSpecialtySort）
        QString EQUIP_CATEG= list.at(7);           //设备大类（码值类型measStdEquipSort）
        QString EQUIP_TYPE= list.at(8);            // 设备小类（码值类型measStdEquipType）
        QString ITEM_ID;                           // 试验项
        QString ITEM_NAME = "起动试验";             // 试验项名称
        QString TEST_GROUP = "起动试验";            // 试验分组（起动试验、停止试验、工频耐压、最大变差、直观检查）
        QString SYS_NO;                            //  系统编号
        //检定线/台体编号[必传，标准装置的条码号]
        QString DETECT_EQUIP_NO = m_DETECT_EQUIP_NO;
        //检定单元编号[必传，标准器的条码号]
        QString DETECT_UNIT_NO = m_DETECT_UNIT_NO;
        QString POSITION_NO;                       //  表位编号
        QString DETECT_DATE = m_TableText.value(code).value("检定日期");                       //  检定/校准日期
        QString DETECT_ITEM_POINT = QString::number(i);                  // 检定点的序号，每个检定项可以检定多个点[必传，各试验项数据展示的序列号，我们将order by 该字段展示到报告里。]
        QString DATA_SOURCE = "01";                     //    01系统录入，02自动上传
        QString DATA_TYPE = "02";                         //  01报告数据，02原始数据
        //温度
        QString ENVIRON_TEMPER = m_xmlTabelDate.value(code).find("其它信息").value().at(5).value("值");
        //湿度
        QString RELATIVE_HUM = m_xmlTabelDate.value(code).find("其它信息").value().at(6).value("值");
        QString DATA_ITEM1;                        //  起动试验/停止试验/工频耐压试验/最大变差/直观检查 结果值（例：>100MΩ）
        QString CHK_CONC_CODE;                      // 结论（例:01：合格:02：不合格）
        if(m_xmlTabelDate.value(code).find("启动测试").value().at(i).value("结论")=="合格")
            CHK_CONC_CODE = "01";
        else
            CHK_CONC_CODE = "02";
        //写入时间
        QString WRITE_DATE = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:s");
        QString HANDLE_FLAG;
        //处理时间
        QString HANDLE_DATE = WRITE_DATE;
        QStringList list;
        list<<READ_ID<<EQUIP_ID<<BAR_CODE<<EQUIP_NAME<<DETECT_TASK_NO<<PROF_CATEG<<EQUIP_CATEG;
        list<<EQUIP_TYPE<<ITEM_ID<<ITEM_NAME<<TEST_GROUP<<SYS_NO<<DETECT_EQUIP_NO<<DETECT_UNIT_NO;
        list<<POSITION_NO<<DETECT_DATE<<DETECT_ITEM_POINT<<DATA_SOURCE<<DATA_TYPE<<ENVIRON_TEMPER;
        list<<RELATIVE_HUM<<DATA_ITEM1<<CHK_CONC_CODE<<WRITE_DATE<<HANDLE_FLAG<<HANDLE_DATE;
        emit error_info2(list);
    }
        return true;

}
void analysisXML::get_show_list(QStringList list)
{
    //qDebug()<<"here";
    this->list = list;
    //joint_E_1_2(list.at(2));

}
//解析导入的xml文件
void analysisXML::load_DealXML(QString xmlPath)
{
    QFile file(xmlPath);
    if (!file.open(QFile::ReadWrite | QFile::Text))
    {
        QString str = "xml文件打开失败 | "+ QTime::currentTime().toString("hh:mm:ss");
        qWarning(str.toStdString().c_str());
        return;
    }

    //清空容器
    m_xmlTabelDate.clear();
    m_TableText.clear();

    QDomDocument doc;
    doc.setContent(&file, false);

    QDomElement root = doc.documentElement();
    if( root.nodeName() == QObject::tr("上传数据"))
    {
        QDomNodeList xml_list = root.childNodes();
        //遍历xml文件中的每一个表检测节点
        for (int i=0; i<xml_list.length(); i++)
        {
            QDomNode domNode = xml_list.item(i);
            QString bar_code = "";
            QMap<QString, QString> _TableText;//临时的表信号
            if(domNode.nodeName() == QObject::tr("表检测"))
            {
                _TableText = Tabletest(domNode);
            }
            QDomNode firchild = domNode.firstChild();

            QMap<QString, QList<QMap<QString, QString> > >_TableData;//表信息

            if(firchild.nodeName() == QObject::tr("其它信息"))
            {
                _TableData.insert("其它信息", DealChildData(firchild, bar_code));
            }

            m_TableText.insert(bar_code, _TableText);

            QDomNode nexttab = firchild.nextSibling();//找出误差
            while(!nexttab.isNull())
            {
                QString str;
                _TableData.insert(nexttab.nodeName(),DealChildData(nexttab, str));

                nexttab = nexttab.nextSibling();
            }
            m_xmlTabelDate.insert(bar_code,_TableData);

            //把实时地解析进度发送回主界面并在日志中显示
            precent = ((qreal)(i+1)/(qreal)xml_list.length())*100;
            QString str = QString("当前解析进度:%1 | "+ QTime::currentTime().toString("hh:mm:ss")).arg(precent);
            qDebug(str.toStdString().c_str());
            emit current_pre(precent);
        }
        QString str = "解析xml文件成功 | "+ QTime::currentTime().toString("hh:mm:ss");
        qDebug(str.toStdString().c_str());
    } else
    {
        //emit InstallReportMsg(tr("所有设备"), tr("用户操作"),tr("Error: 错误的数据表,请选择正确的表，本次数据读取失败!"), "红色");
        QString str = "解析xml文件失败 | "+ QTime::currentTime().toString("hh:mm:ss");
        qWarning(str.toStdString().c_str());
    }
    file.close();

//    //下发所有查找到的bar_code到数据库中查询， 并显示
    QMap<QString, QMap<QString, QString>>::const_iterator it = m_TableText.begin();
    while(it != m_TableText.end())
    {
//        qDebug()<<"it.key()"<<it.key();
        //发送到mds查询
        this->signals_Bar_Code(it.key());
        //拼接表E_1_2并显示
        //标准误差/基本误差
        joint_E_1_2(it.key());
        //拼接表E_1_3并显示
        //起动试验/停止试验/工频耐压/最大变差/直观检查/绝缘电阻
        joint_E_1_3(it.key());
        ++it;
    }
    NotAgainLocal = true;
}

void analysisXML::slotLocalConfig(QString LineNubm, QString DetectPerson, QString AuditPerson,
                                  QString StdCertNo, QString StdCertNoPeriod, QString CertNo
                                  , QString CertNoPeriod, QString ExpirAtionDate)
{
    //检定线台编号, 检定人员, 审核人员,标准器证书编号,标准器证书编号有效期,
    //计量装置证书编号,计量装置证书编号有效期,检定合格证的有效日期
    Equip_no = LineNubm;
    DETECT_PERSON = DetectPerson;
    AUDIT_PERSON = AuditPerson;
    STD_CERT_NO = StdCertNo;
    STD_CERT_NO_PERIOD = StdCertNoPeriod;
    CERT_NO = CertNo;
    CERT_NO_PERIOD = CertNoPeriod;
    EXPIRATION_DATE = ExpirAtionDate;

}
//获取界面上用户填写的的信息
void analysisXML::send_gui_info(QString m_DETECT_EQUIP_NO, QString m_DETECT_UNIT_NO)
{
    //检定线/台体编号[必传，标准装置的条码号]
    this->m_DETECT_EQUIP_NO = m_DETECT_EQUIP_NO;
    //检定单元编号[必传，标准器的条码号]
    this->m_DETECT_UNIT_NO = m_DETECT_UNIT_NO;
}
void analysisXML::slots_CreateXMLFile(QStringList txml)
{//xml内容对应界面上的每一项

    for(int i = 0; i<txml.count(); i++)
    {
        QStringList xml = txml.at(i).split('@');

        QDir dir;
        if(!dir.exists("./tmpSampleNoData"))
            dir.mkdir("./tmpSampleNoData");

        QFile file(tr("./tmpSampleNoData/%1.xml").arg(xml.at(1)));

        if(file.open(QIODevice::WriteOnly|QIODevice::Text))
        {
            QXmlStreamWriter xmlWriter(&file);
            //自动生成格式
            xmlWriter.setAutoFormatting(true);
            //设置自动缩进大小
            xmlWriter.setAutoFormattingIndent(2);

            xmlWriter.writeStartDocument();

            xmlWriter.writeStartElement("samples");

            xmlWriter.writeStartElement("sample");
            //原始信息
            WriteSample(xml, xmlWriter);

            xmlWriter.writeStartElement("projects");

            QList<QMap<QString, QString>> tList;

            //外观检查
            this->WriteProject(sINTUIT_MET_CONC_ProjectNo, "外观检查", "外观检查", xml, xmlWriter);

            tList= this->FineTableName(xml.at(0), "基本误差");
            if(tList.size())
                this->WriteProject(sBASICERR_ProjectNo, "基本误差", "基本误差", xml, xmlWriter);

            tList= this->FineTableName(xml.at(0), "测量重复性");
            if(tList.size())
                this->WriteProject(sMEASURE_REPEAT_MET_CONC_ProjectNo, "测量重复性试验", "测量重复性", xml, xmlWriter);

            tList= this->FineTableName(xml.at(0), "潜动测试");
            if(tList.size())
                this->WriteProject(sCREEP_MET_CONC_ProjectNo, "潜动试验", "潜动测试", xml, xmlWriter);

            tList= this->FineTableName(xml.at(0), "启动测试");
            if(tList.size())
                this->WriteProject(sSTARTING_METCONC_ProjectNo, "起动试验", "启动测试", xml, xmlWriter);

            //影响量要比较7项
            this->WriteProjectINFLUENCEQTY(sINFLUENCE_QTY_MET_CONC_ProjectNo, "影响量试验", "电压影响", xml, xmlWriter);


            xmlWriter.writeEndElement();//project

            xmlWriter.writeEndElement();//sample

            xmlWriter.writeEndElement();//projects


            xmlWriter.writeEndDocument();//samples


            file.close();

            emit InstallReportMsg(tr("所有设备"), tr("用户操作"),tr("[%1][%2]生成xml成功，请检无误方可上传MIS!").arg(xml.at(0)).arg(xml.at(1)), "");

        }

    }
    //这里发送一个创建xml成功的信号

    emit signals_CreateXmlOk();
}

//重新加载

void analysisXML::slots_AgainLocalXML()
{
    //下发所有查找到的bar_code到数据库中查询， 并显示
    QMap<QString, QMap<QString, QString>>::const_iterator it = m_TableText.begin();
    while(it != m_TableText.end())
    {
        JointMIS(it.key());//处理mis,并上传
        ++it;
    }

}


void analysisXML::WriteSample(QStringList &xml, QXmlStreamWriter &xmlWriter)
{

    //            checkResult="总结论（0：不合格，1：合格）
    //            conclusion="结论（0：不合格，1：合格）
    //            result="项目结论（0：合格，1：不合格）


    int i = 1;
    xmlWriter.writeAttribute("sampleNo",xml.at(i++));
    xmlWriter.writeAttribute("checkResult",(xml.at(i++) == "合格") ? "1" : "0");
    xmlWriter.writeAttribute("checkDate",xml.at(i++));
    xmlWriter.writeAttribute("testMan",xml.at(i++));
    xmlWriter.writeAttribute("checkMan",xml.at(i++));

    xmlWriter.writeAttribute("checkTemp",xml.at(i++));
    xmlWriter.writeAttribute("checkWet",xml.at(i++));
    xmlWriter.writeAttribute("checkVolt",xml.at(i++));
    xmlWriter.writeAttribute("checkCurr",xml.at(i++));
    xmlWriter.writeAttribute("checkRate",xml.at(i++));

    xmlWriter.writeAttribute("checkClass",xml.at(i++));
    xmlWriter.writeAttribute("factory",xml.at(i++));
    xmlWriter.writeAttribute("metConst",xml.at(i++));
    xmlWriter.writeAttribute("metVarConst",xml.at(i++));
    xmlWriter.writeAttribute("metClass",xml.at(i++));

    xmlWriter.writeAttribute("metVarClass",xml.at(i++));
    xmlWriter.writeAttribute("metPhase",xml.at(i++));
    xmlWriter.writeAttribute("redSeal",xml.at(i++));
    xmlWriter.writeAttribute("pf",xml.at(i++));
    xmlWriter.writeAttribute("firstCurr",xml.at(i++));

    xmlWriter.writeAttribute("secondCurr",xml.at(i++));
    xmlWriter.writeAttribute("ratedLoad",xml.at(i++));
    xmlWriter.writeAttribute("securityFactor",xml.at(i++));

}

void analysisXML::WriteProject(QString projectNo, QString projectName, QString findName, QStringList &xml, QXmlStreamWriter &xmlWriter)
{

    //    checkResult="总结论（0：不合格，1：合格）
    //    conclusion="结论（0：不合格，1：合格）
    //    result="项目结论（0：合格，1：不合格）

    //注意 项目结论和总结论是相反的
    xmlWriter.writeStartElement("project");//创建项目
    //项目编号
    xmlWriter.writeAttribute("projectNo", projectNo);

    xmlWriter.writeAttribute("projectName", projectName);

    QString tResult = (this->FineTableTextData(xml.at(0), "结论") == "合格")? "0": "1";
    xmlWriter.writeAttribute("testResult","");
    //结论
    xmlWriter.writeAttribute("result",tResult);

    //试验时间
    xmlWriter.writeAttribute("startTime",this->FineTableTextData(xml.at(0), "检定日期"));

    //找出同批次号
    QList<QMap<QString, QString>> tList;
    tList= this->FineTableName(xml.at(0), "其它信息");
    QString strSampleID = "";

    if(tList.size())
    {
        for(int i = 0; i<tList.count(); i++)
        {
            QMap<QString, QString> tMap = tList.at(i);
            if(tMap.value("标识") == "ARRIVE_BATCH_ NO")
            {
                strSampleID = tMap.value("值");
                break;//找到就直接中止本次查找
            }
        }
    }

    //找出项目中所有数据
    tList= this->FineTableName(xml.at(0), findName);
    if(tList.size())
    {
        for(int i = 0; i<tList.count(); i++)
        {
            //创建一条测试项目
            xmlWriter.writeStartElement("testData");
            //            checkResult="总结论（0：不合格，1：合格）
            //            conclusion="结论（0：不合格，1：合格）
            //            result="项目结论（0：合格，1：不合格）
            QMap<QString, QString> tMap = tList.at(i);
            QString Result = tMap.value("结论");

            Result = (Result == "合格") ? "1": "0";

            QString BOTH_WAY_POWER_FLAG = tMap.value("正反向") + tMap.value("有无功");//功率方向

            if(BOTH_WAY_POWER_FLAG == "正向有功")
                BOTH_WAY_POWER_FLAG = "0";
            else if(BOTH_WAY_POWER_FLAG == "反向有功")
                BOTH_WAY_POWER_FLAG = "1";
            else if(BOTH_WAY_POWER_FLAG == "正向无功")
                BOTH_WAY_POWER_FLAG = "2";
            else if(BOTH_WAY_POWER_FLAG == "反向无功")
                BOTH_WAY_POWER_FLAG = "3";
            else
                BOTH_WAY_POWER_FLAG = "0";

            xmlWriter.writeAttribute("testPhase",BOTH_WAY_POWER_FLAG);

            xmlWriter.writeAttribute("testNum","0");

            QString testGroup = tMap.value("元件");
            if(testGroup == "合元件")
                testGroup = "L";
            else if(testGroup == "A元件")
                testGroup = "A";
            else if(testGroup == "B元件")
                testGroup = "B";
            else if(testGroup == "C元件")
                testGroup = "C";


            xmlWriter.writeAttribute("testGroup",testGroup);
            //频率
            QString freq = tMap.value("频率");

            if(freq.size()>2)
            {
                freq = freq.left(freq.size()-2);
                xmlWriter.writeAttribute("freq",freq);
            }
            QString volt = tMap.value("电压");
            if(volt.isEmpty())
                volt = this->FineTableTextData(xml.at(0), "电压");
            QString curr = tMap.value("电流");
            if(curr.isEmpty())
                curr = this->FineTableTextData(xml.at(0), "电流");

            xmlWriter.writeAttribute("volt",volt);
            xmlWriter.writeAttribute("curr",curr);
            xmlWriter.writeAttribute("conclusion", Result);

            QString testTime = tMap.value("时间");
            if(testTime.size()>1)
            {
                testTime = testTime.left(testTime.size()-1);
                xmlWriter.writeAttribute("testTime", testTime);
            }
            xmlWriter.writeAttribute("strSampleID",strSampleID);
            //参考均值
            xmlWriter.writeAttribute("aveErr",tMap.value("均值"));
            //因数
            xmlWriter.writeAttribute("PF",tMap.value("COS"));
            xmlWriter.writeAttribute("intErr",tMap.value("均值化整"));
            //下面处理误差
            QList<QString> sValues = tMap.values();//找出值
            QList<QString> sKey = tMap.keys();//找出key
            for(int i = 0; i<sKey.count(); i++)
            {//key对应值数据
                if(sKey.at(i).contains("误差"))
                {
                    xmlWriter.writeTextElement("error",sValues.at(i));
                }
            }

            xmlWriter.writeEndElement();//testdata
        }
    }else//这里给一个默认值， 这是必须要的
    {
        xmlWriter.writeStartElement("testData");
        //
        xmlWriter.writeAttribute("testNum","0");
        xmlWriter.writeAttribute("testPhase","");
        xmlWriter.writeAttribute("testGroup","");
        xmlWriter.writeAttribute("freq","");
        xmlWriter.writeAttribute("volt",this->FineTableTextData(xml.at(0), "电压"));
        xmlWriter.writeAttribute("curr",this->FineTableTextData(xml.at(0), "电流"));
        xmlWriter.writeAttribute("conclusion", (tResult == "0")? "1":"0");
        xmlWriter.writeAttribute("testTime", "");
        xmlWriter.writeAttribute("strSampleID",strSampleID);
        //因数
        xmlWriter.writeAttribute("PF","");
        xmlWriter.writeEndElement();//testdata
    }
    xmlWriter.writeEndElement();//project
}

void analysisXML::WriteProjectINFLUENCEQTY(QString projectNo, QString projectName, QString /*findName*/, QStringList &xml, QXmlStreamWriter &xmlWriter)
{

    //            checkResult="总结论（0：不合格，1：合格）
    //            conclusion="结论（0：不合格，1：合格）
    //            result="项目结论（0：合格，1：不合格）

    QList<QMap<QString, QString>> tList;
    tList= this->FineTableName(xml.at(0), "电压影响");
    QString conclusion;
    conclusion = "合格";//合格

    if(tList.size())
    {
        for(int i = 0; i<tList.count(); i++)
        {
            QMap<QString, QString> tMap = tList.at(i);
            QString Result = tMap.value("结论");
            if(Result == "不合格")
            {
                conclusion = Result;
                break;
            }
        }
    }
    if(conclusion == "合格")
    {
        tList= this->FineTableName(xml.at(0), "频率影响");
        if(tList.size())
        {
            for(int i = 0; i<tList.count(); i++)
            {
                QMap<QString, QString> tMap = tList.at(i);
                QString Result = tMap.value("结论");
                if(Result == "不合格")
                {
                    conclusion = Result;
                    break;
                }
            }
        }
    }
    if(conclusion == "合格")
    {
        tList= this->FineTableName(xml.at(0), "谐波影响");
        if(tList.size())
        {
            for(int i = 0; i<tList.count(); i++)
            {
                QMap<QString, QString> tMap = tList.at(i);
                QString Result = tMap.value("结论");
                if(Result == "不合格")
                {
                    conclusion = Result;
                    break;
                }
            }
        }
    }
    if(conclusion == "合格")
    {
        tList= this->FineTableName(xml.at(0), "逆相序影响");
        if(tList.size())
        {
            for(int i = 0; i<tList.count(); i++)
            {
                QMap<QString, QString> tMap = tList.at(i);
                QString Result = tMap.value("结论");
                if(Result == "不合格")
                {
                    conclusion = Result;
                    break;
                }
            }
        }
    }
    if(conclusion == "合格")
    {
        tList= this->FineTableName(xml.at(0), "电压不平衡影响");
        if(tList.size())
        {
            for(int i = 0; i<tList.count(); i++)
            {
                QMap<QString, QString> tMap = tList.at(i);
                QString Result = tMap.value("结论");
                if(Result == "不合格")
                {
                    conclusion = Result;
                    break;
                }
            }
        }
    }
    if(conclusion == "合格")
    {
        tList= this->FineTableName(xml.at(0), "采样点影响");
        if(tList.size())
        {
            for(int i = 0; i<tList.count(); i++)
            {
                QMap<QString, QString> tMap = tList.at(i);
                QString Result = tMap.value("结论");
                if(Result == "不合格")
                {
                    conclusion = Result;
                    break;
                }
            }
        }
    }
    if(conclusion == "合格")
    {
        tList= this->FineTableName(xml.at(0), "丢帧影响");
        if(tList.size())
        {
            for(int i = 0; i<tList.count(); i++)
            {
                QMap<QString, QString> tMap = tList.at(i);
                QString Result = tMap.value("结论");
                if(Result == "不合格")
                {
                    conclusion = Result;
                    break;
                }
            }
        }
    }


    xmlWriter.writeStartElement("project");//创建项目
    //项目编号
    xmlWriter.writeAttribute("projectNo", projectNo);

    xmlWriter.writeAttribute("projectName", projectName);

    QString tResult = (conclusion == "合格")? "0": "1";
    xmlWriter.writeAttribute("testResult","");
    //结论
    xmlWriter.writeAttribute("result",tResult);

    //试验时间
    xmlWriter.writeAttribute("startTime",this->FineTableTextData(xml.at(0), "检定日期"));

    //找出同批次号
    tList= this->FineTableName(xml.at(0), "其它信息");
    QString strSampleID = "";

    if(tList.size())
    {
        for(int i = 0; i<tList.count(); i++)
        {
            QMap<QString, QString> tMap = tList.at(i);
            if(tMap.value("标识") == "ARRIVE_BATCH_ NO")
            {
                strSampleID = tMap.value("值");
                break;//找到就直接中止本次查找
            }
        }
    }
    xmlWriter.writeStartElement("testData");
    //

    tResult = (conclusion == "合格")? "1": "0";

    xmlWriter.writeAttribute("testNum","0");
    xmlWriter.writeAttribute("testPhase","");
    xmlWriter.writeAttribute("testGroup","");
    xmlWriter.writeAttribute("freq","");
    xmlWriter.writeAttribute("volt",this->FineTableTextData(xml.at(0), "电压"));
    xmlWriter.writeAttribute("curr",this->FineTableTextData(xml.at(0), "电流"));
    xmlWriter.writeAttribute("conclusion", tResult);
    xmlWriter.writeAttribute("testTime", "");
    xmlWriter.writeAttribute("strSampleID",strSampleID);
    //因数
    xmlWriter.writeAttribute("PF","");
    xmlWriter.writeEndElement();//testdata

    xmlWriter.writeEndElement();//project

}

QMap<QString, QString> analysisXML::Tabletest(QDomNode &domNode)
{
    QMap<QString, QString> tMap;//表检测
    QDomElement delTab = domNode.toElement();
    if(!delTab.isNull())
    {
        //找出该节点所有数据
        QDomNamedNodeMap item = delTab.attributes();

        for(int i = 0;i<item.count(); i++)
        {
            tMap[item.item(i).nodeName()] = item.item(i).nodeValue();
        }
    }
    return tMap;
}

QList<QMap<QString, QString> > analysisXML::DealChildData(QDomNode &domNode, QString &bar_code)
{
    QList< QMap<QString, QString> >tList;
    QDomNode tab = domNode.firstChild();
    if(tab.nodeName() ==  "信息" || tab.nodeName() == "点")
    {
        while(!tab.isNull())
        {
            QDomElement domtab = tab.toElement();
            if(!domtab.isNull())
            {
                QMap<QString, QString>tMap;

                QDomNamedNodeMap item = domtab.attributes();

                for(int i = 0;i<item.count(); i++)
                    tMap[item.item(i).nodeName()] = item.item(i).nodeValue();
                if(tMap.value("标识") == "BAR_CODE")
                    bar_code=tMap.value("值");
                tList.append(tMap);
            }
            tab = tab.nextSibling();
        }
    }

    return tList;
}

QList<QMap<QString, QString>> analysisXML::FineTableName(const QString bar_code, const QString TableName)
{
    if(m_xmlTabelDate.contains(bar_code))//是否存在该条形码， 如果没有则返回空值
    {
        //找出该条形码的所有数据
        QMap<QString, QMap<QString, QList<QMap<QString, QString>>>>::const_iterator it  = m_xmlTabelDate.find(bar_code);
        //找出所在的表
        QMap<QString, QList<QMap<QString, QString>>>::const_iterator itName = (*it).find(TableName);
        if(!itName.key().isEmpty())
            return itName.value();
    }

    return QList<QMap<QString, QString>>();
}

QString analysisXML::FineTableTextData(const QString bar_code, const QString key)
{
    QMap<QString, QMap<QString, QString>>::const_iterator it = m_TableText.find(bar_code);

    if(it.value().contains(key))//如果表中有该条数据， 那么取出他的值
    {
        QMap<QString, QString>::const_iterator i = (*it).find(key);
        return i.value();
    }
    return QString();
}


//上传数据到mis界面上显示
void analysisXML::JointMIS(QString tBar_code)
{
    QString bar_code = tBar_code;//条形码与样品一样
    QString sampleNo = tBar_code;//样品编号
    QString checkResult = this->FineTableTextData(tBar_code, "结论");//总结论
    QString checkDate = this->FineTableTextData(tBar_code, "检定日期");//检验日期YYYY-MM-DD
    QString testMan = this->DETECT_PERSON;//检验员
    QString checkMan = this->AUDIT_PERSON;//校核员
    QString checkTemp;//温度
    QString checkWet;//湿度

    QList<QMap<QString, QString>> tList= this->FineTableName(bar_code, "其它信息");

    QString checkVolt = this->FineTableTextData(tBar_code, "电压");//电压
    QString checkCurr = this->FineTableTextData(tBar_code, "电流");//电流
    QString checkRate = "50";//频率
    QString checkClass;//等级
    QString factory;//生产厂家
    QString metConst;//有功常数
    QString metVarConst;//无功常数
    QString metClass;//有功等级
    QString metVarClass;//无功等级
    QString metPhase;//相线
    QString redSeal;//铅封号
    QString pf;//功率因数
    QString firstCurr;//额定一次电流
    QString secondCurr;//额定二次电流
    QString ratedLoad ;//额定负荷
    QString securityFactor ;//仪表保安系数

    for(int i = 0; i<tList.count(); i++)
    {
        QMap<QString, QString> tMap = tList.at(i);
        if(tMap.value("标识") == "fTemperature")
        {
            checkTemp = tMap.value("值");//温度
            checkTemp= checkTemp.left(checkTemp.size()-1);
        }else if(tMap.value("标识") == "fHumidity")
        {
            checkWet = tMap.value("值");//湿度
            checkWet= checkWet.left(checkWet.size()-1);
        }else if(tMap.value("标识") == "cClassGrade")
            checkClass = tMap.value("值");
        else if(tMap.value("标识") == "接线模式")
            metPhase = tMap.value("值");
        else if(tMap.value("标识") == "cManufactory")
            factory = tMap.value("值");
    }

    QStringList tlist;
    tlist<<bar_code<<sampleNo<<checkResult<<checkDate<<testMan<<checkMan<<checkTemp
        <<checkWet<<checkVolt<<checkCurr<<checkRate<<checkClass<<factory<<metConst
       <<metVarConst<<metClass<<metVarClass<<metPhase<<redSeal<<pf<<firstCurr<<
         secondCurr<<ratedLoad<<securityFactor;

    emit signals_DealSampleList(tlist);
}
