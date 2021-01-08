#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QtXlsx>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QAxObject>
#include <QSettings>
#include <QTextStream>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_resolution_ratio_clicked();

    void on_quit_system_clicked();

    void on_load_file_clicked();

    void on_file_path_clicked();

    void on_clear_info_clicked();

    void on_go_to_a_clicked();

    void on_go_index_a_editingFinished();

    void on_last_a_clicked();

    void on_next_a_clicked();

    void on_go_to_b_clicked();

    void on_go_index_b_editingFinished();

    void on_last_b_clicked();

    void on_next_b_clicked();

    void on_check_data_clicked();

    void on_output_info_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_go_to_b_2_clicked();

    void on_go_index_b_2_editingFinished();

    void on_last_b_2_clicked();

    void on_next_b_2_clicked();

private:
    Ui::MainWindow *ui;
    QStringList all_value;
    QVector<QStringList> xlsx_vector;
    void initUI();
    QString getFileSuffix(QString);
    void loadTable(int type,QString file_path);
    QString table_name_a,table_name_b,table_name_b_2;
    QStandardItemModel * model_a,* model_b,* model_b_2;
    QVariant cell;
    QMap<QString,double> earned_rates,earned_rates_2;
};
#endif // MAINWINDOW_H
