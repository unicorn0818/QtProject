#ifndef CONFIGDIALOG_H
#define CONFIGDIALOG_H

#include <QDialog>
#include <QSettings>
#include <QMessageBox>
#include <QFileDialog>
namespace Ui {
class configDialog;
}

class configDialog : public QDialog
{
    Q_OBJECT

public:
    explicit configDialog(QWidget *parent = nullptr);
    ~configDialog();

    void initConfig();
    void setConMode(bool);

signals:
    void loadXml(QString);
    void conOracle(QStringList);
    void disConOracle();
private slots:
    void on_LinkDBBT_clicked();

    void on_DisLinkDBBT_clicked();

    void on_OpenFileBT_clicked();

private:
    Ui::configDialog *ui;
};

#endif // CONFIGDIALOG_H
