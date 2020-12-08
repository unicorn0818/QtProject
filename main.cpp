#include "mainwindow.h"
#include <QApplication>
#include <QFile>
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
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());
    MainWindow w;
    //关闭程序
    QObject::connect(&w,SIGNAL(close_m()),&a,SLOT(quit()));
    CommonHelper::setStyle(":./style.qss");
    w.show();
    return a.exec();
}
