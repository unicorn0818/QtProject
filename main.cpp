#include <QApplication>
#include "mainwindow.h"
#include <QFile>
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
    QApplication *a=new QApplication(argc, argv);
    MainWindow * w=new MainWindow;
    w->setWindowState(Qt::WindowFullScreen);
    QTranslator translator;
    bool ok=translator.load(":./qt_zh_CN.qm");
    a->installTranslator(&translator);
    CommonHelper::setStyle(":./style.qss");
    QObject::connect(w,SIGNAL(close_m()),a,SLOT(quit()));
    w->setWindowTitle("S6300 V2.1.7");
    w->show();
    return a->exec();
}
