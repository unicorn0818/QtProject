#include "mainwin.h"
#include <QApplication>
#include <QFile>
#include <QApplication>
#include <QTextStream>
#include <QTextCodec>
//修改界面外观
class CommonHelper
{
public:
    static void setStyle(const QString &style) {
        QFile qss(style);
        qss.open(QFile::ReadOnly);
        qApp->setStyleSheet(qss.readAll());
        qss.close();
    }
};
//日志功能
void myMessageOutput(QtMsgType type,const QMessageLogContext &context, const QString &msg)
{
    QString txt;
          switch (type) {
          //调试信息提示
          case QtDebugMsg:
                  txt = QString("Debug: %1 from %2,%3").arg("正常输出:"+msg+" |").arg(context.file).arg(context.line);
                  break;

          //一般的warning提示
          case QtWarningMsg:
                  txt = QString("`: %1 from %2,%3").arg("警告:"+msg+" |").arg(context.file).arg(context.line);
          break;
          //严重错误提示
          case QtCriticalMsg:
                  txt = QString("Critical: %1 from %2,%3").arg("严重错误:"+msg+" |").arg(context.file).arg(context.line);
          break;
          //致命错误提示
          case QtFatalMsg:
                  txt = QString("Fatal: %1 from %2,%3").arg("致命错误:"+msg+" |").arg(context.file).arg(context.line);
                  abort();
          }
    QFile outFile("./debuglog.txt");
    outFile.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream ts(&outFile);
    ts << endl<< txt << endl;
    outFile.close();
}
//将日志文件的内容清空
void ClearTxt()
{
    QFile file("./debuglog.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream io(&file);
    file.close();

    file.open(QIODevice::Truncate);
    file.close();

    file.open(QIODevice::WriteOnly);
    io<<"";
    file.close();
}
int main(int argc, char *argv[])
{
    //安装消息处理程序
    qInstallMessageHandler(myMessageOutput);
    QApplication a(argc, argv);
    //清空日志
    ClearTxt();
    MainWin w;
    CommonHelper::setStyle(":/style.qss");
    w.setWindowTitle("MDSStandard V1.0");
    w.setWindowIcon(QIcon(":/6.png"));
    w.show();
    QString str1 = "系统启动 | "+QTime::currentTime().toString("hh:mm:ss");
    qDebug(str1.toStdString().c_str());
    return a.exec();
}
