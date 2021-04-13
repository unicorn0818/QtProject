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
    MainWindow w;
    CommonHelper::setStyle(":/style.qss");
    w.show();

    return a.exec();
}
