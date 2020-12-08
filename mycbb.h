#ifndef MYCBB_H
#define MYCBB_H

#include <QWidget>
#include <QDebug>
#include <QStringList>
namespace Ui {
class MyCBB;
}

class MyCBB : public QWidget
{
    Q_OBJECT

public:
    explicit MyCBB(QWidget *parent = 0);
    ~MyCBB();
    void setIcon(QIcon);
    void setLabelText(QString);

    void setIconSize(QSize size);
    void setScaledContents(bool value);
    void clickBox();
signals:
    void append_list(QString);
    void remove_list(QString);
    void set_enable_false();
private slots:
    void on_checkBox_clicked(bool checked);

    void on_checkBox_stateChanged(int arg1);

private:
    Ui::MyCBB *ui;
};

#endif // MYCBB_H
