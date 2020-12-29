#ifndef LIST_OUT_H
#define LIST_OUT_H

#include <QDialog>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QItemDelegate>
#include <QAxObject>
#include <QtXlsx>
#include <QDateTime>
#include <QTime>

#include "map_control.h"
#include "xl803.h"
#include <xlsxdocument.h>
#include <xlsxcellrange.h>
#include <xlsxcellreference.h>


#define DAC_CHNUM 17
#define LEVELNUM 15
#pragma pack(4)
typedef struct
{
    char version[20];	//版本号，只读
    char msg[500];	//说明信息
    double levelLimit[DAC_CHNUM][LEVELNUM];	//最大值限制，交流有效值，直流要自己换算,上层软件是和驱动配置一个表格显示的，为了程序编写方便定义为64位的
    quint64 levelDriveSet[DAC_CHNUM][LEVELNUM];		//levelnum最后一档的是频率所在,不要用，驱动信号配置
    float uMax;
    float iMax;
    quint32 levelLimitType;	//档位限值的类型，设置的是交流还是直流
    quint32  PowerBoardType;		//功放板类型，0交直流功放，1，803系列功放
    qint32 negDcAdj;			//直流负端校准
    qint32 GJMask;			//告警屏蔽，=1，屏蔽所有告警，=0，允许告警
    qint32 switchDlay;		//换挡前输出停止时间
    float defaultV;		//默认电压值
    float defaultI;		//默认电流值
    qint32 ztLevelSet;		//暂态所在档位设置
    qint32 silicon;			//u版本信息
    quint64 pwrDrvSet;	//暂态大电流电源切换配置
    qint32 phaseAdjEn;		//相位调整值是否有效，0x55有效
    float	phaseAdj[DAC_CHNUM];	//相位调整值
    qint32 tempAdjEn;			//温度调整是否有效，0x55有效
    float tempAdj[DAC_CHNUM][LEVELNUM];	//电流温度系数
    qint32 useDDS;			//0x55=使用dds，其它值使用sclk0
    quint32 AD5545MAXFREQ;			//sport口最快频率
    qint32 secChIndependent;		//0x55=付路输出独立，其它值付路输出不独立
    quint64 pwrOrderCtrlSet1;	//上电顺序控制1
    quint64 pwrOrderCtrlSet2;	//上电顺序控制2
    qint32 TriOutDlyNum;			//触发延迟补偿值，因为每块板子的中断响应可能稍有不同，因此最好是进行实际测试并调整
    float dcMeLeveSet[DAC_CHNUM][LEVELNUM];	//直流测量档位设置值17.1.10
    quint32 menuSet;		//菜单设置,每一个位代表该菜单是否启用，1启用，0该项不启用
    quint64 dcModeDriveSet[DAC_CHNUM];	//直流模式的继电器驱动，有些功放直流输出时可能需要切换一些继电器，可以通过这个配置
    quint32 harmoNum;	//谐波次数配置
    quint32 waveTypeSet;	//波形类型设置
    quint32	zeroDriftRemoveForAC;	//交流输出时消除直流零位偏移=0不处理，=1消除零位
    float highCurrentLimit;		//大电流限值，超出这个限值的电流只能短时输出
    float highCurrentLimitTime;	//电流输出时间，单位秒
    quint32 highCurrentCtrlPhs;	//大电流控制的相，1受控，0，不受控，bit0：Ua,bit1:Ia....,在TaskDAC里面处理超时关闭
    quint32	levelChangeMode;		//换档模式设置，0，直接换档，1换档前先停止输出，换档后再启动，避免冲击
    quint32 	waveMirrorSet;		//动态波形、录波回放输出波形反向设置，BIT0：Ua,=1反向，=0，不变。
    float PowerUpSwitchDelayTime;		//上电时电源继电器切换间隔时间，如果时间小于等于0ms，那么就只上电一次
} PowerSet;
class UDataDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    UDataDelegate(QObject * parent=0);
    //createEditor是双击item后创建什么控件
    QWidget * createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    //setEditorData是显示控件后 设置里面的值，提供index 自己从model内提取数据
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    //setmodeldata是确定 （按下回车后）设置model的值，
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;

    ~UDataDelegate();
signals:
    void editd(QModelIndex index,double value) const;
};
class UchDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    UchDelegate(QObject * parent=0);
    //createEditor是双击item后创建什么控件
    QWidget * createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    //setEditorData是显示控件后 设置里面的值，提供index 自己从model内提取数据
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    //setmodeldata是确定 （按下回车后）设置model的值，
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;

    ~UchDelegate();
signals:
    void editd(QModelIndex index,double value) const;
};

class TimeDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    TimeDelegate(QObject * parent=0);
    //createEditor是双击item后创建什么控件
    QWidget * createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    //setEditorData是显示控件后 设置里面的值，提供index 自己从model内提取数据
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    //setmodeldata是确定 （按下回车后）设置model的值，
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;

    ~TimeDelegate();
    QString last_text;
signals:
    void editd(QModelIndex index,QString text) const;
};
namespace Ui {
class List_out;
#define MAX_U_SIZE 500
}

class List_out : public QDialog
{
    Q_OBJECT

public:
    explicit List_out(QWidget *parent = 0);
    ~List_out();
signals:
    void show_tab_bar(bool);
private slots:
    void on_u_view_clicked(QModelIndex index);

    void on_in_file_clicked();

    void on_go_index_valueChanged(int arg1);

    void recv_mesg(QByteArray last,QByteArray now);
    void on_go_index_editingFinished();

    void on_start_freq_clicked();

    void on_start_out_clicked();

    void on_stop_out_clicked();

    void change_u_time();

    void on_down_data_clicked();

    void cancel_down();

     void on_last_clicked();

     void on_next_clicked();

     void on_u_all_clicked();

     void on_start_change_u_clicked();

     void on_u_change_view_clicked(const QModelIndex &index);

     void on_go_to_clicked();

     void on_last_3_clicked();

     void on_freq_view_clicked(const QModelIndex &index);

     void on_remove_start_valueChanged(int arg1);

     void set_time(QModelIndex index,QString text);

     void set_freq(QModelIndex index, double text);


     void on_creat_line_data_clicked();


     void on_change_set_clicked();

     void on_pushButton_clicked();
     void m_reset();

     void m_move();
     void m_sq();
     void m_all_up();
     void m_all_down();
     void m_sq_x();
     void m_x_up();
     void m_x_down();
     void m_sq_y();
     void m_y_up();
     void m_y_down();

     void u_press(QMouseEvent*);
     void i_press(QMouseEvent*);
     void mousePress(QMouseEvent* mevent);
     void mouseMove(QMouseEvent*);
     void mouseRelease(QMouseEvent*);
     void showListWidgetMenuSlot(QPoint pos);
     void on_add_data_clicked();

     void send_start_freq();

     void on_read_gear_clicked();

     void gear_Change(int index);

private:
    void set_signal();
    void set_freq_data();
    void set_u_enable(bool flag);
    void open_by_execl(QString file_name);
    void open_by_file(QString file_name);
    void open_by_xlsx(QString file_name);
    void set_u_data();
    void reset_ticker();
    map_control * p_control;
    void  init_u_data(bool flag=false);
    bool edit_flag;
    QMenu *m_contextMenu;
    QAction * m_move_item;
    QAction * m_reset_item;
    QAction * m_sq_item;
    QAction * m_sq_x_item;
    QAction * m_sq_y_item;
    QAction * m_all_up_item;
    QAction * m_all_down_item;
    QAction * m_x_up_item;
    QAction * m_x_down_item;
    QAction * m_y_down_item;
    QAction * m_y_up_item;
    QCPGraph * line;
    QCPGraph * l_ua;
    QCPGraph * l_ub;
    QCPGraph * l_uc;
    QCPGraph * l_ud;

    QCPGraph * l_freq;
    QCPGraph * l_value;
    QVector<double>x_l,y_l;
    QVector<float>freq_time,value_time;
    QActionGroup * group;
    QVector<double>freq_x,freq_y;
    QStandardItemModel * u_model;
    QStandardItemModel * freq_model;
    QStandardItemModel * u_change_model;
    double max_freq;
    double min_freq;
    int type;
    double freq_map_x;
    double freq_map_y_min;
    double freq_map_y_max;
    double freq_ticker_step;
    double value_map_x;
    double value_map_y_min;
    double value_map_y_max;
    double value_ticker_step;
    QVariant cell;
    Ui::List_out *ui;
    QMap<int,int> index_map;
    struct freq_value{
        QDateTime time;
        float freq;
    };
    QVector<freq_value> freq_vector;
    QRubberBand * u_rubber;
    QRubberBand * i_rubber;
    QPoint rubberOrigin;
    bool freq_flag;
    bool value_flag;
    bool step_flag;
    bool end_flag;
    bool count_flag;
    bool down_flag;
    bool flush_over;
    bool u_start;
    int data_index;
    int byte_index;
    int u_end;
    float old_ua;
    float old_ub;
    float old_uc;
    float old_ud;
    QByteArray freq_data;
    XL803::XL803Proto * xl609;
    QProgressDialog * dialog;
    QTimer * u_timer;
    QTimer * u_init_timer;
    bool freq_is_start;
    PowerSet * m_set;
    QVector<double> max_value;
};
#include "mainwindow.h"
#endif // LIST_OUT_H
