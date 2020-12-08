#include "submitreport.h"

SubmitReport::SubmitReport(QObject *parent) : QObject(parent)
{
    m_pHttp = new QtSoapHttpTransport(this);
    connect(m_pHttp, SIGNAL(responseReady(const QtSoapMessage &)), this, SLOT(onResponse(const QtSoapMessage &)));
}

void SubmitReport::slot_qtsoap_send(QStringList list)
{
    qDebug("i am thread");
     //http://10.158.249.196:7001/InterfaceWS/InterfaceBusinessrvices/DetectService
//    for(int i = 0;i<list.count();i++)
//    {
//        QtSoapMessage message;
//        // 设置方法
//        message.setMethod("veriSendDetectRsltInfo", "http://10.158.249.196:7001/InterfaceWS/InterfaceBusinessrvices/DetectService");
//        // 设置动作
//        m_pHttp->setAction("http://10.158.249.196:7001/InterfaceWS/InterfaceBusinessrvices/DetectService/veriSendDetectRsltInfo");
//        // 设置主机
//        m_pHttp->setHost("http://10.158.249.196:7001",7001);
//        // 添加方法参数
//        message.addMethodArgument("DETECT_TASK_NO",NULL,"DETECT_TASK_NO.toLatin1().data()");
//        message.addMethodArgument("EQUIP_NO",NULL,"EQUIP_NO.toLatin1().data()");
//        QString strXML = message.toXmlString();
//        // 提交请求
//        m_pHttp->submitRequest(message, "10.158.249.196:7001");
//    }
}
void SubmitReport::onResponse(const QtSoapMessage & response)
{
    //  　数据同步接口 其他的接口只需要改为RESULT_FLAG和ERROR_INFO
    //    <DATA>
    //    <RESULT>成功标志</RESULT>
    //    <ERROR>错误信息</ERROR>
    //    </DATA>
    QString strXML = response.toXmlString();
    qDebug()<<"strXML"<<strXML;
    QDomDocument doc;
    doc.setContent(strXML);
    // 接在在线状态
    QDomNodeList nodeList = doc.elementsByTagName("RESULT");
    if (!nodeList.isEmpty())
    {
        QDomNode node = nodeList.at(0);
        QString strResult = node.toElement().text();
        if(strResult.toInt()==0)
        {
            qDebug("失败");
            QDomNodeList nodeList = doc.elementsByTagName("ERROR");
            if (!nodeList.isEmpty())
            {
                QDomNode node = nodeList.at(0);
                qDebug()<<node.toElement().text();
            }
            emit sendToMainWin(0,node.toElement().text());
        }
        else if(strResult.toInt()==1)
        {
            qDebug("成功");
            emit sendToMainWin(1,"");
        }
    }
    else{
        qDebug("soap error");
    }


//    QtSoapType type = response.returnValue();
//    if(type["RESULT"].value().toString()=="0")
//    {
//        qDebug()<<"web调用失败,失败信息:"<<type["ERROR"].value().toString();
//    }
//    else if(type["RESULT"].value().toString()=="1")
//    {
//        qDebug()<<"上传成功";
//    }
}
