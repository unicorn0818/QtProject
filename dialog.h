#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QFileDialog>
#include <QMessageBox>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    void setMaxValue(int pipe_count);
signals:
    void bind_sql(int,int,QString,QString);
    void bind_vol_ch(int);
    void bind_ele_ch(int,QString);
    void bind_icon(QString,int);
    void click_cancel();
private slots:
    void on_cancel_bt_clicked();

    void on_bind_vol_clicked();

    void on_bind_ele_clicked();

    void on_bind_icon_clicked();



private:
    Ui::Dialog *ui;
    int pipe_count;
    QString icon_path;
};

#endif // DIALOG_H
