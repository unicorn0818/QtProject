#ifndef KEY_BOARD_DLG_H
#define KEY_BOARD_DLG_H
#define m_system 0
#include <QDialog>
#include <QDebug>
#include <QAbstractButton>
#include <QButtonGroup>
#include <QKeyEvent>
#include <QPoint>
#include <QWidget>
#include <windows.h>
namespace Ui {
class Key_board_dlg;
}

class Key_board_dlg : public QDialog
{
    Q_OBJECT

public:
    static Key_board_dlg *get_key_board(QWidget *parent = 0);
    ~Key_board_dlg();
private:
    explicit Key_board_dlg(QWidget *parent = 0);
private slots:
    void send_key1(int id);
    void send_key2(int id);

    void on_b_full_clicked();

    void on_btn_num_clicked();

    void on_btn_shi_clicked();

    void on_btn_cap_clicked();

private:
    Ui::Key_board_dlg *ui;
    void set_id();
    QButtonGroup * group_1;
    QButtonGroup * group_2;
    static Key_board_dlg *key_board;
};

#endif // KEY_BOARD_DLG_H
