#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCompleter>
#include "configdialog.h"
#include "analysissql.h"
#include "analysisxml.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QStringList handleCodeValue(QStringList);
private slots:
    void on_config_set_clicked();
    void myOracleCon(QStringList ora_info);
    void myOracleDisCon();
    void xmlLoad(QString file_name);
    void checkBarCode(QString bar_code);
    void getTableData(QStringList);
    void loadFinish();
    void on_listWidget_currentRowChanged(int currentRow);
    void getA_1Data(QStringList);
    void on_jointA_1_clicked();
    void on_update_ora_clicked();
    void on_bindInfo_clicked();
    void on_tabWidget_currentChanged(int index);

private:
    Ui::MainWindow *ui;
    bool loadFlag;
    QVector<QString> m_barCode_vector;
    QVector<QStringList> m_A_1Info_vector;
    QVector<QStringList> m_tableInfo_vector;
    configDialog *m_config_dialog;
    analysisSQL *m_analysis_sql;
    analysisXml *m_analysis_xml;

};
#endif // MAINWINDOW_H
