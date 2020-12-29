#ifndef STATU_LIST_H
#define STATU_LIST_H
#define HARMONUM	22
#define CHNUM	8
#include <QWidget>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QItemDelegate>
#include <QLineEdit>
#include <QComboBox>
#include <QFile>

#include "xl803.h"

class StateDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    StateDelegate(QObject * parent=0);
    //createEditor是双击item后创建什么控件
    QWidget * createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    //setEditorData是显示控件后 设置里面的值，提供index 自己从model内提取数据
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    //setmodeldata是确定 （按下回车后）设置model的值，
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    QString float_to_str(float,int) const;
    ~StateDelegate();
signals:
    void editd(QModelIndex index,QString value) const;
};

namespace Ui {
class Statu_list;
}

class Statu_list : public QWidget
{
    Q_OBJECT

public:
    explicit Statu_list(QWidget *parent = 0);
    ~Statu_list();
    QStandardItemModel * mesg_model;
private slots:
    void on_read_clicked();

    void on_write_clicked();

    void on_start_clicked();

    void on_stop_clicked();

    void on_all_start_clicked();

    void on_all_stop_clicked();

    void recv_mesg(QByteArray last,QByteArray now);

    void show_out_list();

    void update_vector(QModelIndex index,QString value);

    void on_all_write_clicked();

    void on_all_read_clicked();

    void on_in_file_clicked();

    void on_save_file_clicked();

    void on_priview_clicked();

    void on_list_state_now_clicked(const QModelIndex &index);

    void on_mid_clicked();

    void on_init_wave_clicked();

    void set_flag();

private:
    typedef struct
    {
        float	fundamental[CHNUM];		//基波有效值ua,ia,ub,ib
        float harmoVal[CHNUM][HARMONUM];//谐波含有率,谐波含有率按占基波的百分比设置，第0项是基波的含有率，也就是允许通过该比率更改基波值
        float	harmoPhase[CHNUM][HARMONUM];	//谐波相位，第0项是基波的相位
        float	Fa,Fb,Fc,Fd;			//基波频率，Fa决定Ua、Ia的频率，其它相的同理
    }POWERSET;
    //__attribute__((packed))
    typedef struct
    {
        long number;		//项序号，最多允许10项，0~9，
        float timeLastMs;		//输出持续时间，毫秒，<=0当前项连续输出，直到收到停止命令
    //能设置的最长时间为秒，或者连续输出
        POWERSET powerset;	//源输出设置值
        long active;		//>0激活，激活标志，只有激活的项才会起作用，没有激活的项直接略过,这样允许上位机编程更加灵活
        long next;			//下一项标志，0：结束后停止输出，1：结束后进行下一项输出，-1回到开始的第一项进行输出
    }POWERStatus;
    //__attribute__((packed))
    QVector<POWERStatus *> state_vector;
    XL803::XL803Proto * xl609;
    int now_index;
    Ui::Statu_list *ui;
    int start_a;
    int start_b;
    int start_c;
    int start_d;
    bool reset_wave;
    QTimer * timer;
    QList<int> all_down;
    int read_index;
    bool all_read;
    bool flag_no_stop;
    QCPGraph * l_ua;
    QCPGraph * l_ub;
    QCPGraph * l_uc;
    QCPGraph * l_ud;
    QMessageBox * mesg;
};

#endif // STATU_LIST_H
