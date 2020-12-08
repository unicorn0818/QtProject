#ifndef MAINWIN_H
#define MAINWIN_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QSettings>
#include <QListWidgetItem>
#include <QTableWidgetItem>
#include <QMessageBox>
#include <QProgressDialog>
#include <QProgressBar>
#include "qtsoap.h"
#include "analysissql.h"
#include "analysisxml.h"
#include "submitreport.h"
#include "qtsoap.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWin; }
QT_END_NAMESPACE

class MainWin : public QMainWindow
{
    Q_OBJECT

public:
    MainWin(QWidget *parent = nullptr);
    ~MainWin();

    void addName();

private slots:
    void get_State(int flag);

    void on_LinkDBBT_clicked();

    void on_DisLinkDBBT_clicked();

    void on_OpenFileBT_clicked();

    void on_UpLoadBT_clicked();

    void get_show_list(QStringList);

    void get_show_list1(QStringList list);

    void get_show_list2(QStringList list);

    void on_ClearBT_clicked();

    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_error_table_tabBarClicked(int index);

    void get_current_precent(qreal precent);
//    void on_StartWeb_clicked();

    void insert_next();

    void isfinished();

    void on_ALLTW_tabBarClicked(int index);

    void on_DownLoadLog_clicked();

    void on_ClearLog_clicked();

    void on_UpdateWebBT_clicked();

    void on_ClearTable_clicked();

    void on_WebUrlLE_textChanged(const QString &arg1);

    void getWebInfo(bool flag,QString info);

    void loadDll();

    void initUi();

    void initCon();

    void upDateWebInfo(QString,QString);

signals:
    void loadxml_signal(QString);

    void gui_info(QString,QString);

    void insert_Data(QVector<QStringList>,int);

    void qtsoap_send(QStringList);
private:
    Ui::MainWin *ui;
    analysisSQL *optsql;
    analysisXML *optxml;
    int Row,Row1,Row2;
    QStringList list_error1,list_error2,table2;
    QList<QStringList> get_list,get_list1;
    int clicked_flag1,clicked_flag2,clicked_flag3;
    QProgressDialog *progressDlg;
    QProgressBar mybar;
    QVector<QStringList> insertlist;
    QString WebUrl;
    QtSoapHttpTransport *m_pHttp;
    SubmitReport *submitreport;
};
#endif // MAINWIN_H
