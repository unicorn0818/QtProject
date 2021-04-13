#include "analysisxml.h"

analysisXml::analysisXml()
{

}

void analysisXml::loadXml(QString file_name)
{
    QFile file(file_name);
    if (!file.open(QFile::ReadWrite | QFile::Text))
        return;
    QDomDocument doc;
    doc.setContent(&file, false);

    QDomElement root = doc.documentElement();
    if(root.nodeName() == QObject::tr("上传数据"))
    {
        QDomNodeList xml_list = root.childNodes();
        for (int i=0; i<xml_list.length(); i++)
        {
            QDomNode domNode = xml_list.item(i);
            QMap<QString, QString> _TableText;
            if(domNode.nodeName() == QObject::tr("检测"))
            {
                _TableText = Tabletest(domNode);
//                //这里应该去查一下条形码存在不。
                QString bar_code = _TableText.value("条形码");
                emit selectBarCode(bar_code);
            }
            QDomNode nexttab = domNode.firstChild();
            QList<QMap<QString,QString>> _TableData;
            QMap<QString,QList<QMap<QString,QString>>> _TableDataItems;
            QVector<QMap<QString,QList<QMap<QString,QString>>>> m_dataVector;
            while(!nexttab.isNull())
            {
                _TableDataItems.clear();
                _TableData = dealChildData(nexttab);
                if(nexttab.nodeName() == QObject::tr("电流互感器检定误差"))
                {
                    _TableDataItems.insertMulti("电流互感器检定误差",_TableData);
                }else if(nexttab.nodeName() == QObject::tr("叠加直流检定误差"))
                {
                    _TableDataItems.insertMulti("叠加直流检定误差",_TableData);
                }else if(nexttab.nodeName() == QObject::tr("正弦半波检定误差"))
                {
                    _TableDataItems.insertMulti("正弦半波检定误差",_TableData);
                }
                if(!_TableDataItems.isEmpty())
                    m_dataVector<<_TableDataItems;
                nexttab = nexttab.nextSibling();
            }
            jointTable(_TableText,m_dataVector);
        }


    }else
        return;
    file.close();
    emit finishLoad();
}

void analysisXml::jointTable(QMap<QString, QString> text,QVector<QMap<QString,QList<QMap<QString,QString>>>> data)
{
     QStringList table_data;
     QString BAR_CODE = text.value("条形码");
     QString RC_RATIO_CODE = text.value("电流比");
     int count;QString str;
     for(int i = 0;i<data.count();i++)
     {
         for(int k = 0;k<3;k++)
         {
             if(k == 0)
             {
                 count = data.at(i).value("电流互感器检定误差").count();
                 str = "电流互感器检定误差";
             }else if(k == 1)
             {
                 count = data.at(i).value("叠加直流检定误差").count();
                 str = "叠加直流检定误差";
             }else if(k == 2)
             {
                 count = data.at(i).value("正弦半波检定误差").count();
                 str = "正弦半波检定误差";
             }

             for(int j=0;j<count;j++)
             {
                 table_data.clear();
                 QString LOAD_FLAG = data.at(i).value(str).at(j).value("负荷类型");
                 QString ERR_ITEM = data.at(i).value(str).at(j).value("额定电流百分值");
                 QString RATIO_ERR = data.at(i).value(str).at(j).value("比差");
                 QString ANGLE_ERR = data.at(i).value(str).at(j).value("角差");
                 QString RATIO_AMEND_ERR = data.at(i).value(str).at(j).value("比差修约值");
                 QString ANGLE_AMEND_ERR = data.at(i).value(str).at(j).value("角差修约值");
                 QString PF = data.at(i).value(str).at(j).value("功率因数");
                 QString CONC_CODE = data.at(i).value(str).at(j).value("结论");
                 QString PHASE_CODE = data.at(i).value(str).at(j).value("相别");
                 QString ERR_TYPE = str;
                 table_data<<""<<BAR_CODE<<""<<""<<""<<LOAD_FLAG<<ERR_ITEM<<RATIO_ERR<<ANGLE_ERR<<RATIO_AMEND_ERR\
                          <<ANGLE_AMEND_ERR<<""<<RC_RATIO_CODE<<"200311"<<""<<""<<""<<""<<""<<PF<<CONC_CODE<<PHASE_CODE<<""\
                         <<ERR_TYPE;
                 emit tableData(table_data);

             }
         }
     }
}

QList<QMap<QString,QString>> analysisXml::dealChildData(QDomNode &domNode)
{
    QDomNode tab = domNode.firstChild();
    QList<QMap<QString,QString>> info;

    if(tab.nodeName() == "点")
    {
        while(!tab.isNull())
        {
            QDomElement domtab = tab.toElement();
            QMap<QString,QString> tmp;
            if(!domtab.isNull())
            {
                QDomNamedNodeMap item = domtab.attributes();

                for(int i = 0;i<item.count(); i++)
                {
                      tmp.insertMulti(item.item(i).nodeName(),item.item(i).nodeValue());
                }
            }
            info.append(tmp);
            tab = tab.nextSibling();
        }
    }
    return info;
}

QMap<QString, QString> analysisXml::Tabletest(QDomNode &domNode)
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
