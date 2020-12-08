#ifndef DIALOG_CSV_H
#define DIALOG_CSV_H

#include <QDialog>

namespace Ui {
class Dialog_CSV;
}

class Dialog_CSV : public QDialog
{
   Q_OBJECT
signals:
    void sendFileName(QString,int);
    void sendFileSample(double);
public:
    explicit Dialog_CSV(QWidget *parent = 0);
    ~Dialog_CSV();
    void setType(int);
    void setLineEdit(QString);
    static bool revPhase;
private slots:
    void on_btOk_clicked();

    void on_btCancel_clicked();

private:
    Ui::Dialog_CSV *ui;
    int type;
};

#endif // DIALOG_CSV_H
