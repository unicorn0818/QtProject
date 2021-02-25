#ifndef TEST_BLL_H
#define TEST_BLL_H

#include "xl803.h"

#include <QWidget>

namespace Ui {
class test_bll;
}

class test_bll : public QWidget
{
    Q_OBJECT

public:
    explicit test_bll(QWidget *parent = 0);
    ~test_bll();

private slots:
    void on_pushButton_clicked();
    void recv_mesg(QByteArray,QByteArray);
private:
    Ui::test_bll *ui;
};

#endif // TEST_BLL_H
