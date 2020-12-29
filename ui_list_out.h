/********************************************************************************
** Form generated from reading UI file 'list_out.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIST_OUT_H
#define UI_LIST_OUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <customplothasroll.h>
#include "m_checkbox.h"

QT_BEGIN_NAMESPACE

class Ui_List_out
{
public:
    QGridLayout *gridLayout_5;
    QVBoxLayout *verticalLayout_3;
    QFrame *frame_5;
    QHBoxLayout *horizontalLayout_17;
    QHBoxLayout *horizontalLayout_16;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_4;
    QLabel *state_mesg;
    QHBoxLayout *horizontalLayout_14;
    QHBoxLayout *horizontalLayout_2;
    m_checkbox *ua_flag;
    m_checkbox *ub_flag;
    m_checkbox *uc_flag;
    m_checkbox *ud_flag;
    QHBoxLayout *horizontalLayout_8;
    m_checkbox *start_flag;
    m_checkbox *stop_flag;
    QTabWidget *tabWidget_2;
    QWidget *tab;
    QGridLayout *gridLayout_8;
    CustomPlotHasRoll *freq_map;
    QWidget *tab_2;
    QGridLayout *gridLayout_9;
    CustomPlotHasRoll *value_map;
    QHBoxLayout *horizontalLayout_5;
    QTabWidget *tabWidget;
    QWidget *tab_3;
    QGridLayout *gridLayout_6;
    QFrame *frame;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_8;
    QTableView *freq_view;
    QHBoxLayout *horizontalLayout_10;
    QHBoxLayout *horizontalLayout_12;
    QPushButton *last_3;
    QHBoxLayout *horizontalLayout_13;
    QLabel *now_index_3;
    QSpinBox *remove_start;
    QLabel *now_index_2;
    QSpinBox *remove_end;
    QLabel *all_index_2;
    QHBoxLayout *horizontalLayout_7;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *last;
    QPushButton *go_to;
    QSpinBox *go_index;
    QPushButton *next;
    QHBoxLayout *horizontalLayout_3;
    QLabel *now_index;
    QLabel *label_12;
    QLabel *all_index;
    QLabel *label_8;
    QPushButton *in_file;
    QPushButton *down_data;
    QPushButton *start_freq;
    QPushButton *creat_line_data;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_6;
    QLabel *file_name;
    QPushButton *add_data;
    QWidget *tab_4;
    QGridLayout *gridLayout_7;
    QFrame *frame_3;
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout_2;
    QTableView *u_change_view;
    QPushButton *start_change_u;
    QPushButton *pushButton;
    QFrame *line;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QVBoxLayout *verticalLayout_30;
    QLabel *label_32;
    QLineEdit *ua_value;
    QVBoxLayout *verticalLayout_31;
    QLabel *label_33;
    QLineEdit *ub_value;
    QVBoxLayout *verticalLayout_23;
    QLabel *label_22;
    QLineEdit *uc_value;
    QVBoxLayout *verticalLayout_24;
    QLabel *label_23;
    QLineEdit *ud_value;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QVBoxLayout *verticalLayout;
    QFrame *frame_4;
    QGridLayout *gridLayout_2;
    QCheckBox *freq_set;
    QLabel *label_7;
    QTableView *u_view;
    QCheckBox *zero_seq;
    QHBoxLayout *horizontalLayout_18;
    QHBoxLayout *horizontalLayout_9;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_9;
    QComboBox *gear;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_5;
    QLineEdit *max_value;
    QPushButton *read_gear;
    QFrame *frame_2;
    QGridLayout *gridLayout;
    QPushButton *stop_out;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QCheckBox *u_all;
    QCheckBox *ua;
    QCheckBox *ub;
    QCheckBox *uc;
    QCheckBox *ud;
    QPushButton *change_set;
    QPushButton *start_out;

    void setupUi(QDialog *List_out)
    {
        if (List_out->objectName().isEmpty())
            List_out->setObjectName(QStringLiteral("List_out"));
        List_out->resize(750, 500);
        gridLayout_5 = new QGridLayout(List_out);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        frame_5 = new QFrame(List_out);
        frame_5->setObjectName(QStringLiteral("frame_5"));
        frame_5->setFrameShape(QFrame::Box);
        frame_5->setFrameShadow(QFrame::Raised);
        frame_5->setLineWidth(2);
        horizontalLayout_17 = new QHBoxLayout(frame_5);
        horizontalLayout_17->setSpacing(2);
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        horizontalLayout_17->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        label_4 = new QLabel(frame_5);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_15->addWidget(label_4);

        state_mesg = new QLabel(frame_5);
        state_mesg->setObjectName(QStringLiteral("state_mesg"));
        state_mesg->setAlignment(Qt::AlignCenter);

        horizontalLayout_15->addWidget(state_mesg);

        horizontalLayout_15->setStretch(1, 1);

        horizontalLayout_16->addLayout(horizontalLayout_15);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        ua_flag = new m_checkbox(frame_5);
        ua_flag->setObjectName(QStringLiteral("ua_flag"));
        ua_flag->setEnabled(true);
        ua_flag->setFocusPolicy(Qt::NoFocus);
        ua_flag->setCheckable(false);

        horizontalLayout_2->addWidget(ua_flag);

        ub_flag = new m_checkbox(frame_5);
        ub_flag->setObjectName(QStringLiteral("ub_flag"));
        ub_flag->setEnabled(true);
        ub_flag->setFocusPolicy(Qt::NoFocus);
        ub_flag->setCheckable(false);

        horizontalLayout_2->addWidget(ub_flag);

        uc_flag = new m_checkbox(frame_5);
        uc_flag->setObjectName(QStringLiteral("uc_flag"));
        uc_flag->setEnabled(true);
        uc_flag->setFocusPolicy(Qt::NoFocus);
        uc_flag->setCheckable(false);

        horizontalLayout_2->addWidget(uc_flag);

        ud_flag = new m_checkbox(frame_5);
        ud_flag->setObjectName(QStringLiteral("ud_flag"));
        ud_flag->setEnabled(true);
        ud_flag->setFocusPolicy(Qt::NoFocus);
        ud_flag->setCheckable(false);

        horizontalLayout_2->addWidget(ud_flag);


        horizontalLayout_14->addLayout(horizontalLayout_2);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        start_flag = new m_checkbox(frame_5);
        start_flag->setObjectName(QStringLiteral("start_flag"));
        start_flag->setEnabled(true);
        start_flag->setFocusPolicy(Qt::NoFocus);
        start_flag->setCheckable(false);

        horizontalLayout_8->addWidget(start_flag);

        stop_flag = new m_checkbox(frame_5);
        stop_flag->setObjectName(QStringLiteral("stop_flag"));
        stop_flag->setEnabled(true);
        stop_flag->setFocusPolicy(Qt::NoFocus);
        stop_flag->setCheckable(false);

        horizontalLayout_8->addWidget(stop_flag);


        horizontalLayout_14->addLayout(horizontalLayout_8);


        horizontalLayout_16->addLayout(horizontalLayout_14);

        horizontalLayout_16->setStretch(0, 1);
        horizontalLayout_16->setStretch(1, 1);

        horizontalLayout_17->addLayout(horizontalLayout_16);


        verticalLayout_3->addWidget(frame_5);

        tabWidget_2 = new QTabWidget(List_out);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_8 = new QGridLayout(tab);
        gridLayout_8->setSpacing(0);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        gridLayout_8->setContentsMargins(0, 0, 0, 0);
        freq_map = new CustomPlotHasRoll(tab);
        freq_map->setObjectName(QStringLiteral("freq_map"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(freq_map->sizePolicy().hasHeightForWidth());
        freq_map->setSizePolicy(sizePolicy);
        freq_map->setMinimumSize(QSize(0, 0));

        gridLayout_8->addWidget(freq_map, 0, 0, 1, 1);

        tabWidget_2->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout_9 = new QGridLayout(tab_2);
        gridLayout_9->setSpacing(0);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        gridLayout_9->setContentsMargins(0, 0, 0, 0);
        value_map = new CustomPlotHasRoll(tab_2);
        value_map->setObjectName(QStringLiteral("value_map"));
        sizePolicy.setHeightForWidth(value_map->sizePolicy().hasHeightForWidth());
        value_map->setSizePolicy(sizePolicy);
        value_map->setMinimumSize(QSize(0, 0));

        gridLayout_9->addWidget(value_map, 0, 0, 1, 1);

        tabWidget_2->addTab(tab_2, QString());

        verticalLayout_3->addWidget(tabWidget_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(2);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        tabWidget = new QTabWidget(List_out);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        gridLayout_6 = new QGridLayout(tab_3);
        gridLayout_6->setSpacing(0);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(tab_3);
        frame->setObjectName(QStringLiteral("frame"));
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        frame->setLineWidth(2);
        gridLayout_3 = new QGridLayout(frame);
        gridLayout_3->setSpacing(2);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(2, 2, 2, 2);
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(1);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        freq_view = new QTableView(frame);
        freq_view->setObjectName(QStringLiteral("freq_view"));
        freq_view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        verticalLayout_8->addWidget(freq_view);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(0);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(1);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(1, -1, -1, 1);
        last_3 = new QPushButton(frame);
        last_3->setObjectName(QStringLiteral("last_3"));
        sizePolicy.setHeightForWidth(last_3->sizePolicy().hasHeightForWidth());
        last_3->setSizePolicy(sizePolicy);
        last_3->setMinimumSize(QSize(10, 10));
        last_3->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_12->addWidget(last_3);

        horizontalLayout_12->setStretch(0, 2);

        horizontalLayout_10->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(1);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        horizontalLayout_13->setContentsMargins(-1, -1, 0, -1);
        now_index_3 = new QLabel(frame);
        now_index_3->setObjectName(QStringLiteral("now_index_3"));

        horizontalLayout_13->addWidget(now_index_3);

        remove_start = new QSpinBox(frame);
        remove_start->setObjectName(QStringLiteral("remove_start"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(remove_start->sizePolicy().hasHeightForWidth());
        remove_start->setSizePolicy(sizePolicy1);
        remove_start->setWrapping(true);
        remove_start->setMinimum(1);
        remove_start->setMaximum(1);

        horizontalLayout_13->addWidget(remove_start);

        now_index_2 = new QLabel(frame);
        now_index_2->setObjectName(QStringLiteral("now_index_2"));

        horizontalLayout_13->addWidget(now_index_2);

        remove_end = new QSpinBox(frame);
        remove_end->setObjectName(QStringLiteral("remove_end"));
        sizePolicy1.setHeightForWidth(remove_end->sizePolicy().hasHeightForWidth());
        remove_end->setSizePolicy(sizePolicy1);
        remove_end->setWrapping(true);
        remove_end->setMinimum(1);
        remove_end->setMaximum(1);

        horizontalLayout_13->addWidget(remove_end);

        all_index_2 = new QLabel(frame);
        all_index_2->setObjectName(QStringLiteral("all_index_2"));

        horizontalLayout_13->addWidget(all_index_2);


        horizontalLayout_10->addLayout(horizontalLayout_13);


        verticalLayout_8->addLayout(horizontalLayout_10);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(1);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(1, -1, -1, 1);
        last = new QPushButton(frame);
        last->setObjectName(QStringLiteral("last"));
        sizePolicy.setHeightForWidth(last->sizePolicy().hasHeightForWidth());
        last->setSizePolicy(sizePolicy);
        last->setMinimumSize(QSize(10, 10));
        last->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_6->addWidget(last);

        go_to = new QPushButton(frame);
        go_to->setObjectName(QStringLiteral("go_to"));

        horizontalLayout_6->addWidget(go_to);

        go_index = new QSpinBox(frame);
        go_index->setObjectName(QStringLiteral("go_index"));
        sizePolicy1.setHeightForWidth(go_index->sizePolicy().hasHeightForWidth());
        go_index->setSizePolicy(sizePolicy1);
        go_index->setWrapping(true);
        go_index->setMinimum(1);
        go_index->setMaximum(1);

        horizontalLayout_6->addWidget(go_index);

        next = new QPushButton(frame);
        next->setObjectName(QStringLiteral("next"));
        sizePolicy.setHeightForWidth(next->sizePolicy().hasHeightForWidth());
        next->setSizePolicy(sizePolicy);
        next->setMinimumSize(QSize(10, 10));
        next->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_6->addWidget(next);

        horizontalLayout_6->setStretch(0, 2);
        horizontalLayout_6->setStretch(1, 1);
        horizontalLayout_6->setStretch(2, 2);
        horizontalLayout_6->setStretch(3, 2);

        horizontalLayout_7->addLayout(horizontalLayout_6);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(1);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, -1, 0, -1);
        now_index = new QLabel(frame);
        now_index->setObjectName(QStringLiteral("now_index"));

        horizontalLayout_3->addWidget(now_index);

        label_12 = new QLabel(frame);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_3->addWidget(label_12);

        all_index = new QLabel(frame);
        all_index->setObjectName(QStringLiteral("all_index"));

        horizontalLayout_3->addWidget(all_index);

        label_8 = new QLabel(frame);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_3->addWidget(label_8);


        horizontalLayout_7->addLayout(horizontalLayout_3);


        verticalLayout_8->addLayout(horizontalLayout_7);

        verticalLayout_8->setStretch(0, 1);

        gridLayout_3->addLayout(verticalLayout_8, 1, 0, 5, 1);

        in_file = new QPushButton(frame);
        in_file->setObjectName(QStringLiteral("in_file"));
        sizePolicy.setHeightForWidth(in_file->sizePolicy().hasHeightForWidth());
        in_file->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(in_file, 2, 1, 1, 1);

        down_data = new QPushButton(frame);
        down_data->setObjectName(QStringLiteral("down_data"));
        sizePolicy.setHeightForWidth(down_data->sizePolicy().hasHeightForWidth());
        down_data->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(down_data, 3, 1, 1, 1);

        start_freq = new QPushButton(frame);
        start_freq->setObjectName(QStringLiteral("start_freq"));
        start_freq->setEnabled(true);
        sizePolicy.setHeightForWidth(start_freq->sizePolicy().hasHeightForWidth());
        start_freq->setSizePolicy(sizePolicy);
        start_freq->setCheckable(false);

        gridLayout_3->addWidget(start_freq, 1, 1, 1, 1);

        creat_line_data = new QPushButton(frame);
        creat_line_data->setObjectName(QStringLiteral("creat_line_data"));
        sizePolicy.setHeightForWidth(creat_line_data->sizePolicy().hasHeightForWidth());
        creat_line_data->setSizePolicy(sizePolicy);
        creat_line_data->setCheckable(false);

        gridLayout_3->addWidget(creat_line_data, 5, 1, 1, 1);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(2);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_6 = new QLabel(frame);
        label_6->setObjectName(QStringLiteral("label_6"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy2);

        horizontalLayout_11->addWidget(label_6);

        file_name = new QLabel(frame);
        file_name->setObjectName(QStringLiteral("file_name"));
        file_name->setLayoutDirection(Qt::LeftToRight);
        file_name->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_11->addWidget(file_name);


        gridLayout_3->addLayout(horizontalLayout_11, 0, 0, 1, 1);

        add_data = new QPushButton(frame);
        add_data->setObjectName(QStringLiteral("add_data"));
        sizePolicy.setHeightForWidth(add_data->sizePolicy().hasHeightForWidth());
        add_data->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(add_data, 4, 1, 1, 1);

        gridLayout_3->setColumnStretch(0, 1);
        start_freq->raise();
        in_file->raise();
        down_data->raise();
        creat_line_data->raise();
        add_data->raise();

        gridLayout_6->addWidget(frame, 0, 0, 1, 1);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        gridLayout_7 = new QGridLayout(tab_4);
        gridLayout_7->setSpacing(0);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        frame_3 = new QFrame(tab_4);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        sizePolicy.setHeightForWidth(frame_3->sizePolicy().hasHeightForWidth());
        frame_3->setSizePolicy(sizePolicy);
        frame_3->setFrameShape(QFrame::Box);
        frame_3->setFrameShadow(QFrame::Raised);
        frame_3->setLineWidth(2);
        gridLayout_4 = new QGridLayout(frame_3);
        gridLayout_4->setSpacing(2);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(2, 2, 2, 2);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        u_change_view = new QTableView(frame_3);
        u_change_view->setObjectName(QStringLiteral("u_change_view"));

        verticalLayout_2->addWidget(u_change_view);


        gridLayout_4->addLayout(verticalLayout_2, 2, 0, 4, 1);

        start_change_u = new QPushButton(frame_3);
        start_change_u->setObjectName(QStringLiteral("start_change_u"));
        sizePolicy.setHeightForWidth(start_change_u->sizePolicy().hasHeightForWidth());
        start_change_u->setSizePolicy(sizePolicy);

        gridLayout_4->addWidget(start_change_u, 2, 1, 1, 1);

        pushButton = new QPushButton(frame_3);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);

        gridLayout_4->addWidget(pushButton, 3, 1, 1, 1);

        line = new QFrame(frame_3);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShadow(QFrame::Raised);
        line->setLineWidth(2);
        line->setFrameShape(QFrame::HLine);

        gridLayout_4->addWidget(line, 6, 0, 1, 2);

        verticalSpacer_2 = new QSpacerItem(20, 44, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_2, 5, 1, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(2);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, -1, -1, 0);
        label_2 = new QLabel(frame_3);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_4->addWidget(label_2);

        verticalLayout_30 = new QVBoxLayout();
        verticalLayout_30->setSpacing(2);
        verticalLayout_30->setObjectName(QStringLiteral("verticalLayout_30"));
        verticalLayout_30->setContentsMargins(-1, -1, -1, 2);
        label_32 = new QLabel(frame_3);
        label_32->setObjectName(QStringLiteral("label_32"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_32->sizePolicy().hasHeightForWidth());
        label_32->setSizePolicy(sizePolicy3);
        label_32->setAlignment(Qt::AlignCenter);

        verticalLayout_30->addWidget(label_32);

        ua_value = new QLineEdit(frame_3);
        ua_value->setObjectName(QStringLiteral("ua_value"));
        sizePolicy.setHeightForWidth(ua_value->sizePolicy().hasHeightForWidth());
        ua_value->setSizePolicy(sizePolicy);
        ua_value->setReadOnly(true);

        verticalLayout_30->addWidget(ua_value);


        horizontalLayout_4->addLayout(verticalLayout_30);

        verticalLayout_31 = new QVBoxLayout();
        verticalLayout_31->setSpacing(2);
        verticalLayout_31->setObjectName(QStringLiteral("verticalLayout_31"));
        verticalLayout_31->setContentsMargins(-1, -1, -1, 2);
        label_33 = new QLabel(frame_3);
        label_33->setObjectName(QStringLiteral("label_33"));
        sizePolicy3.setHeightForWidth(label_33->sizePolicy().hasHeightForWidth());
        label_33->setSizePolicy(sizePolicy3);
        label_33->setAlignment(Qt::AlignCenter);

        verticalLayout_31->addWidget(label_33);

        ub_value = new QLineEdit(frame_3);
        ub_value->setObjectName(QStringLiteral("ub_value"));
        sizePolicy.setHeightForWidth(ub_value->sizePolicy().hasHeightForWidth());
        ub_value->setSizePolicy(sizePolicy);
        ub_value->setReadOnly(true);

        verticalLayout_31->addWidget(ub_value);


        horizontalLayout_4->addLayout(verticalLayout_31);

        verticalLayout_23 = new QVBoxLayout();
        verticalLayout_23->setSpacing(2);
        verticalLayout_23->setObjectName(QStringLiteral("verticalLayout_23"));
        verticalLayout_23->setContentsMargins(-1, -1, -1, 2);
        label_22 = new QLabel(frame_3);
        label_22->setObjectName(QStringLiteral("label_22"));
        sizePolicy3.setHeightForWidth(label_22->sizePolicy().hasHeightForWidth());
        label_22->setSizePolicy(sizePolicy3);
        label_22->setAlignment(Qt::AlignCenter);

        verticalLayout_23->addWidget(label_22);

        uc_value = new QLineEdit(frame_3);
        uc_value->setObjectName(QStringLiteral("uc_value"));
        sizePolicy.setHeightForWidth(uc_value->sizePolicy().hasHeightForWidth());
        uc_value->setSizePolicy(sizePolicy);
        uc_value->setReadOnly(true);

        verticalLayout_23->addWidget(uc_value);


        horizontalLayout_4->addLayout(verticalLayout_23);

        verticalLayout_24 = new QVBoxLayout();
        verticalLayout_24->setSpacing(2);
        verticalLayout_24->setObjectName(QStringLiteral("verticalLayout_24"));
        verticalLayout_24->setContentsMargins(-1, -1, -1, 2);
        label_23 = new QLabel(frame_3);
        label_23->setObjectName(QStringLiteral("label_23"));
        sizePolicy3.setHeightForWidth(label_23->sizePolicy().hasHeightForWidth());
        label_23->setSizePolicy(sizePolicy3);
        label_23->setAlignment(Qt::AlignCenter);

        verticalLayout_24->addWidget(label_23);

        ud_value = new QLineEdit(frame_3);
        ud_value->setObjectName(QStringLiteral("ud_value"));
        sizePolicy.setHeightForWidth(ud_value->sizePolicy().hasHeightForWidth());
        ud_value->setSizePolicy(sizePolicy);
        ud_value->setReadOnly(true);

        verticalLayout_24->addWidget(ud_value);


        horizontalLayout_4->addLayout(verticalLayout_24);


        gridLayout_4->addLayout(horizontalLayout_4, 0, 0, 1, 2);

        verticalSpacer = new QSpacerItem(20, 44, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer, 4, 1, 1, 1);

        label = new QLabel(frame_3);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_4->addWidget(label, 1, 0, 1, 1);

        gridLayout_4->setColumnStretch(0, 1);

        gridLayout_7->addWidget(frame_3, 0, 0, 1, 1);

        tabWidget->addTab(tab_4, QString());

        horizontalLayout_5->addWidget(tabWidget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        frame_4 = new QFrame(List_out);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        sizePolicy.setHeightForWidth(frame_4->sizePolicy().hasHeightForWidth());
        frame_4->setSizePolicy(sizePolicy);
        frame_4->setFrameShape(QFrame::Box);
        frame_4->setFrameShadow(QFrame::Raised);
        frame_4->setLineWidth(2);
        gridLayout_2 = new QGridLayout(frame_4);
        gridLayout_2->setSpacing(2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(2, 2, 2, 2);
        freq_set = new QCheckBox(frame_4);
        freq_set->setObjectName(QStringLiteral("freq_set"));
        freq_set->setChecked(true);

        gridLayout_2->addWidget(freq_set, 0, 1, 1, 1);

        label_7 = new QLabel(frame_4);
        label_7->setObjectName(QStringLiteral("label_7"));
        sizePolicy3.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy3);

        gridLayout_2->addWidget(label_7, 0, 0, 1, 1);

        u_view = new QTableView(frame_4);
        u_view->setObjectName(QStringLiteral("u_view"));

        gridLayout_2->addWidget(u_view, 1, 0, 1, 3);

        zero_seq = new QCheckBox(frame_4);
        zero_seq->setObjectName(QStringLiteral("zero_seq"));
        zero_seq->setChecked(true);

        gridLayout_2->addWidget(zero_seq, 0, 2, 1, 1);


        verticalLayout->addWidget(frame_4);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(2);
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(2);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(2);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_9 = new QLabel(List_out);
        label_9->setObjectName(QStringLiteral("label_9"));
        sizePolicy.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy);

        verticalLayout_5->addWidget(label_9);

        gear = new QComboBox(List_out);
        gear->setObjectName(QStringLiteral("gear"));
        sizePolicy.setHeightForWidth(gear->sizePolicy().hasHeightForWidth());
        gear->setSizePolicy(sizePolicy);

        verticalLayout_5->addWidget(gear);


        horizontalLayout_9->addLayout(verticalLayout_5);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(2);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_5 = new QLabel(List_out);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_4->addWidget(label_5);

        max_value = new QLineEdit(List_out);
        max_value->setObjectName(QStringLiteral("max_value"));
        max_value->setReadOnly(true);

        verticalLayout_4->addWidget(max_value);


        horizontalLayout_9->addLayout(verticalLayout_4);

        horizontalLayout_9->setStretch(0, 1);
        horizontalLayout_9->setStretch(1, 1);

        horizontalLayout_18->addLayout(horizontalLayout_9);

        read_gear = new QPushButton(List_out);
        read_gear->setObjectName(QStringLiteral("read_gear"));
        sizePolicy.setHeightForWidth(read_gear->sizePolicy().hasHeightForWidth());
        read_gear->setSizePolicy(sizePolicy);

        horizontalLayout_18->addWidget(read_gear);


        verticalLayout->addLayout(horizontalLayout_18);

        frame_2 = new QFrame(List_out);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::Box);
        frame_2->setFrameShadow(QFrame::Raised);
        frame_2->setLineWidth(2);
        gridLayout = new QGridLayout(frame_2);
        gridLayout->setSpacing(2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(1, 0, 0, 1);
        stop_out = new QPushButton(frame_2);
        stop_out->setObjectName(QStringLiteral("stop_out"));
        sizePolicy.setHeightForWidth(stop_out->sizePolicy().hasHeightForWidth());
        stop_out->setSizePolicy(sizePolicy);

        gridLayout->addWidget(stop_out, 3, 2, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_3 = new QLabel(frame_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        u_all = new QCheckBox(frame_2);
        u_all->setObjectName(QStringLiteral("u_all"));
        u_all->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout->addWidget(u_all);

        ua = new QCheckBox(frame_2);
        ua->setObjectName(QStringLiteral("ua"));
        QFont font;
        font.setPointSize(12);
        ua->setFont(font);
        ua->setLayoutDirection(Qt::LeftToRight);
        ua->setChecked(true);

        horizontalLayout->addWidget(ua);

        ub = new QCheckBox(frame_2);
        ub->setObjectName(QStringLiteral("ub"));
        ub->setFont(font);

        horizontalLayout->addWidget(ub);

        uc = new QCheckBox(frame_2);
        uc->setObjectName(QStringLiteral("uc"));
        uc->setFont(font);

        horizontalLayout->addWidget(uc);

        ud = new QCheckBox(frame_2);
        ud->setObjectName(QStringLiteral("ud"));
        ud->setFont(font);

        horizontalLayout->addWidget(ud);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 1);
        horizontalLayout->setStretch(3, 1);
        horizontalLayout->setStretch(4, 1);

        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 3);

        change_set = new QPushButton(frame_2);
        change_set->setObjectName(QStringLiteral("change_set"));
        sizePolicy.setHeightForWidth(change_set->sizePolicy().hasHeightForWidth());
        change_set->setSizePolicy(sizePolicy);

        gridLayout->addWidget(change_set, 2, 0, 2, 1);

        start_out = new QPushButton(frame_2);
        start_out->setObjectName(QStringLiteral("start_out"));
        sizePolicy.setHeightForWidth(start_out->sizePolicy().hasHeightForWidth());
        start_out->setSizePolicy(sizePolicy);

        gridLayout->addWidget(start_out, 3, 1, 1, 1);


        verticalLayout->addWidget(frame_2);

        verticalLayout->setStretch(0, 3);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 2);

        horizontalLayout_5->addLayout(verticalLayout);

        horizontalLayout_5->setStretch(0, 3);
        horizontalLayout_5->setStretch(1, 2);

        verticalLayout_3->addLayout(horizontalLayout_5);

        verticalLayout_3->setStretch(1, 1);
        verticalLayout_3->setStretch(2, 2);

        gridLayout_5->addLayout(verticalLayout_3, 0, 0, 1, 1);


        retranslateUi(List_out);

        tabWidget_2->setCurrentIndex(1);
        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(List_out);
    } // setupUi

    void retranslateUi(QDialog *List_out)
    {
        List_out->setWindowTitle(QApplication::translate("List_out", "Dialog", 0));
        label_4->setText(QApplication::translate("List_out", "\345\275\223\345\211\215\347\212\266\346\200\201\357\274\232", 0));
        state_mesg->setText(QString());
        ua_flag->setText(QApplication::translate("List_out", "UA", 0));
        ub_flag->setText(QApplication::translate("List_out", "UB", 0));
        uc_flag->setText(QApplication::translate("List_out", "UC", 0));
        ud_flag->setText(QApplication::translate("List_out", "UD", 0));
        start_flag->setText(QApplication::translate("List_out", "\346\234\252\345\220\257\345\212\250", 0));
        stop_flag->setText(QApplication::translate("List_out", "\345\267\262\345\220\257\345\212\250", 0));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab), QApplication::translate("List_out", "Tab 1", 0));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_2), QApplication::translate("List_out", "Tab 2", 0));
#ifndef QT_NO_TOOLTIP
        freq_view->setToolTip(QApplication::translate("List_out", "\346\230\276\347\244\272\351\242\221\347\216\207\346\226\207\344\273\266\344\277\241\346\201\257", 0));
#endif // QT_NO_TOOLTIP
        last_3->setText(QApplication::translate("List_out", "\345\210\240\351\231\244", 0));
        now_index_3->setText(QApplication::translate("List_out", "\347\254\254", 0));
        remove_start->setSuffix(QString());
        remove_start->setPrefix(QString());
        now_index_2->setText(QApplication::translate("List_out", "\351\241\271\350\207\263\347\254\254", 0));
        remove_end->setSuffix(QString());
        remove_end->setPrefix(QString());
        all_index_2->setText(QApplication::translate("List_out", "\351\241\271", 0));
        last->setText(QApplication::translate("List_out", "\344\270\212\344\270\200\351\241\265", 0));
        go_to->setText(QApplication::translate("List_out", "\350\267\263\350\275\254\350\207\263", 0));
        go_index->setSuffix(QString());
        go_index->setPrefix(QString());
        next->setText(QApplication::translate("List_out", "\344\270\213\344\270\200\351\241\265", 0));
        now_index->setText(QApplication::translate("List_out", "1", 0));
        label_12->setText(QApplication::translate("List_out", "/", 0));
        all_index->setText(QApplication::translate("List_out", "1", 0));
        label_8->setText(QApplication::translate("List_out", "\351\241\265", 0));
#ifndef QT_NO_TOOLTIP
        in_file->setToolTip(QApplication::translate("List_out", "\345\260\206\350\241\250\346\240\274\345\257\274\345\205\245\347\250\213\345\272\217\344\270\255\357\274\214\346\224\257\346\214\201\345\220\204\347\247\215\345\270\270\347\224\250\350\241\250\346\240\274\346\240\274\345\274\217", 0));
#endif // QT_NO_TOOLTIP
        in_file->setText(QApplication::translate("List_out", "\345\257\274\345\205\245\n"
"\351\242\221\347\216\207\346\226\207\344\273\266", 0));
#ifndef QT_NO_TOOLTIP
        down_data->setToolTip(QApplication::translate("List_out", "\345\260\206\351\242\221\347\216\207\346\225\260\346\215\256\344\270\213\350\275\275\345\210\260\345\206\205\345\255\230\344\270\255\357\274\214\351\241\273\345\205\210\345\257\274\345\205\245\351\242\221\347\216\207\346\226\207\344\273\266\343\200\202", 0));
#endif // QT_NO_TOOLTIP
        down_data->setText(QApplication::translate("List_out", "\344\270\213\350\275\275\346\225\260\346\215\256", 0));
#ifndef QT_NO_TOOLTIP
        start_freq->setToolTip(QApplication::translate("List_out", "\345\274\200\345\247\213\345\217\230\351\242\221\357\274\214\345\217\230\351\242\221\346\227\266\345\217\230\345\216\213\344\270\215\345\217\257\347\224\250\343\200\202", 0));
#endif // QT_NO_TOOLTIP
        start_freq->setText(QApplication::translate("List_out", "\345\220\257\345\212\250\345\217\230\351\242\221", 0));
        creat_line_data->setText(QApplication::translate("List_out", "\347\224\237\346\210\220\n"
"\351\242\221\347\216\207\346\233\262\347\272\277", 0));
        label_6->setText(QApplication::translate("List_out", "\351\242\221\347\216\207\346\226\207\344\273\266:", 0));
        file_name->setText(QString());
#ifndef QT_NO_TOOLTIP
        add_data->setToolTip(QApplication::translate("List_out", "\345\260\206\351\242\221\347\216\207\346\225\260\346\215\256\344\270\213\350\275\275\345\210\260\345\206\205\345\255\230\344\270\255\357\274\214\351\241\273\345\205\210\345\257\274\345\205\245\351\242\221\347\216\207\346\226\207\344\273\266\343\200\202", 0));
#endif // QT_NO_TOOLTIP
        add_data->setText(QApplication::translate("List_out", "\350\277\275\345\212\240\346\225\260\346\215\256", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("List_out", "Tab 1", 0));
#ifndef QT_NO_TOOLTIP
        u_change_view->setToolTip(QApplication::translate("List_out", "\347\224\250\344\272\216\350\256\276\347\275\256\346\234\200\347\273\210\345\217\230\345\214\226\347\224\265\345\216\213\357\274\214\350\260\203\346\225\264\347\232\204\345\271\205\345\200\274\n"
"\345\222\214\345\217\230\345\214\226\347\232\204\351\227\264\351\232\224\346\227\266\351\227\264\357\274\214\351\227\264\351\232\224\346\227\266\351\227\264\344\270\211\347\233\270\347\233\270\345\220\214.", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        start_change_u->setToolTip(QApplication::translate("List_out", "\345\274\200\345\247\213\350\260\203\346\225\264\347\224\265\345\216\213\357\274\214\345\220\257\345\212\250\345\220\216\345\217\230\351\242\221\344\270\215\345\217\257\347\224\250\343\200\202", 0));
#endif // QT_NO_TOOLTIP
        start_change_u->setText(QApplication::translate("List_out", "\345\220\257\345\212\250\345\217\230\345\216\213", 0));
        pushButton->setText(QApplication::translate("List_out", "\347\224\237\346\210\220\n"
"\345\217\230\345\216\213\346\233\262\347\272\277", 0));
#ifndef QT_NO_TOOLTIP
        label_2->setToolTip(QApplication::translate("List_out", "\346\230\276\347\244\272\345\275\223\345\211\215\350\276\223\345\207\272\347\224\265\345\216\213", 0));
#endif // QT_NO_TOOLTIP
        label_2->setText(QApplication::translate("List_out", "\345\275\223\345\211\215\347\224\265\345\216\213", 0));
        label_32->setText(QApplication::translate("List_out", "UA", 0));
#ifndef QT_NO_TOOLTIP
        ua_value->setToolTip(QApplication::translate("List_out", "UA\345\275\223\345\211\215\350\276\223\345\207\272\345\200\274", 0));
#endif // QT_NO_TOOLTIP
        label_33->setText(QApplication::translate("List_out", "UB", 0));
#ifndef QT_NO_TOOLTIP
        ub_value->setToolTip(QApplication::translate("List_out", "UB\345\275\223\345\211\215\350\276\223\345\207\272\345\200\274", 0));
#endif // QT_NO_TOOLTIP
        label_22->setText(QApplication::translate("List_out", "UC", 0));
#ifndef QT_NO_TOOLTIP
        uc_value->setToolTip(QApplication::translate("List_out", "UC\345\275\223\345\211\215\350\276\223\345\207\272\345\200\274", 0));
#endif // QT_NO_TOOLTIP
        label_23->setText(QApplication::translate("List_out", "UD", 0));
#ifndef QT_NO_TOOLTIP
        ud_value->setToolTip(QApplication::translate("List_out", "UC\345\275\223\345\211\215\350\276\223\345\207\272\345\200\274", 0));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("List_out", "\345\217\230\345\216\213\350\256\276\347\275\256", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("List_out", "Tab 2", 0));
        freq_set->setText(QApplication::translate("List_out", "\351\242\221\347\216\207\345\220\214\346\255\245", 0));
        label_7->setText(QApplication::translate("List_out", "\347\224\265\345\216\213\350\256\276\347\275\256", 0));
#ifndef QT_NO_TOOLTIP
        u_view->setToolTip(QApplication::translate("List_out", "\347\224\250\344\272\216\350\256\276\347\275\256\347\224\265\345\216\213\345\220\257\345\212\250\346\227\266\347\232\204\351\205\215\347\275\256", 0));
#endif // QT_NO_TOOLTIP
        zero_seq->setText(QApplication::translate("List_out", "\351\233\266\345\272\217\350\256\241\347\256\227", 0));
        label_9->setText(QApplication::translate("List_out", "\346\241\243\344\275\215", 0));
        label_5->setText(QApplication::translate("List_out", "\346\234\200\345\244\247\345\200\274", 0));
        read_gear->setText(QApplication::translate("List_out", "\350\257\273\345\217\226\346\241\243\344\275\215", 0));
#ifndef QT_NO_TOOLTIP
        stop_out->setToolTip(QApplication::translate("List_out", "\345\201\234\346\255\242\345\275\223\345\211\215\347\224\265\345\216\213\350\276\223\345\207\272\343\200\202", 0));
#endif // QT_NO_TOOLTIP
        stop_out->setText(QApplication::translate("List_out", "\345\201\234\346\255\242\347\224\265\345\216\213", 0));
        label_3->setText(QApplication::translate("List_out", "\351\200\211\346\213\251\350\276\223\345\207\272\347\233\270:", 0));
        u_all->setText(QApplication::translate("List_out", "\345\205\250\351\200\211", 0));
        ua->setText(QApplication::translate("List_out", "UA", 0));
        ub->setText(QApplication::translate("List_out", "UB", 0));
        uc->setText(QApplication::translate("List_out", "UC", 0));
        ud->setText(QApplication::translate("List_out", "UD", 0));
#ifndef QT_NO_TOOLTIP
        change_set->setToolTip(QApplication::translate("List_out", "\345\220\257\345\212\250\347\224\265\345\216\213\357\274\214\350\276\223\345\207\272\345\200\274\344\273\245\347\224\265\345\216\213\350\256\276\347\275\256\345\200\274\344\270\272\345\207\206", 0));
#endif // QT_NO_TOOLTIP
        change_set->setText(QApplication::translate("List_out", "\345\217\230\345\216\213\350\256\276\347\275\256", 0));
#ifndef QT_NO_TOOLTIP
        start_out->setToolTip(QApplication::translate("List_out", "\345\220\257\345\212\250\347\224\265\345\216\213\357\274\214\350\276\223\345\207\272\345\200\274\344\273\245\347\224\265\345\216\213\350\256\276\347\275\256\345\200\274\344\270\272\345\207\206", 0));
#endif // QT_NO_TOOLTIP
        start_out->setText(QApplication::translate("List_out", "\345\220\257\345\212\250\347\224\265\345\216\213", 0));
    } // retranslateUi

};

namespace Ui {
    class List_out: public Ui_List_out {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIST_OUT_H
