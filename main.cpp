#include "mainwindow.h"

#include <QApplication>
#include <QStyleFactory>
#include <QFile>
#include <QDebug>
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
    qDebug()<<QStyleFactory::keys();
    //a.setStyle(QStyleFactory::create("Fusion"));
    MainWindow w;
    CommonHelper::setStyle(":/new/prefix1/style.qss");
    w.show();
    QObject::connect(&w,SIGNAL(send_close()),&a,SLOT(quit()));
    return a.exec();
}
