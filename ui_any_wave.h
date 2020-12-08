/********************************************************************************
** Form generated from reading UI file 'any_wave.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANY_WAVE_H
#define UI_ANY_WAVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
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
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <customplothasroll.h>
#include "m_checkbox.h"
#include "m_spinbox.h"

QT_BEGIN_NAMESPACE

class Ui_Any_wave
{
public:
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_11;
    QSpacerItem *horizontalSpacer;
    m_checkbox *ua_state;
    m_checkbox *ub_state;
    m_checkbox *uc_state;
    m_checkbox *ia_state;
    m_checkbox *ib_state;
    m_checkbox *ic_state;
    m_checkbox *state1;
    m_checkbox *state2;
    m_checkbox *state3;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_10;
    QTabWidget *change_map;
    QWidget *tab;
    QGridLayout *gridLayout_8;
    CustomPlotHasRoll *bar_map;
    CustomPlotHasRoll *wave_map;
    QWidget *tab_2;
    QGridLayout *gridLayout_9;
    CustomPlotHasRoll *printf_map;
    QWidget *tab_3;
    QGridLayout *gridLayout_12;
    CustomPlotHasRoll *show_wave;
    QGridLayout *gridLayout_7;
    QFrame *frame;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *thd;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *rms;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *ratio;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *clear;
    QPushButton *priview;
    QPushButton *save;
    QFrame *frame_4;
    QTabWidget *change_data;
    QWidget *tab_5;
    QGridLayout *gridLayout_10;
    QTableWidget *hrenter_data;
    QWidget *tab_6;
    QGridLayout *gridLayout_11;
    QTableWidget *point_data;
    QGridLayout *gridLayout_6;
    QFrame *frame_2;
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_6;
    QDoubleSpinBox *time_lenth;
    QLabel *label_5;
    QPushButton *save_data;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *print_map;
    QPushButton *back_point;
    QPushButton *smooth_wave;
    QPushButton *tran;
    QFrame *frame_5;
    QFrame *frame_3;
    QGridLayout *gridLayout_4;
    QHBoxLayout *horizontalLayout_15;
    QVBoxLayout *verticalLayout_9;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QHBoxLayout *horizontalLayout_10;
    QDoubleSpinBox *base_value;
    QDoubleSpinBox *freq;
    QDoubleSpinBox *sampling;
    QHBoxLayout *horizontalLayout_13;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_9;
    M_spinbox *tig_model;
    QVBoxLayout *verticalLayout_12;
    QLabel *label_10;
    M_spinbox *phase;
    QPushButton *set;
    QFrame *frame_6;
    QHBoxLayout *horizontalLayout_14;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_14;
    QSpinBox *out_model;
    QPushButton *start_wave;
    QPushButton *stop_wave;
    QFrame *frame_7;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_11;
    QLineEdit *all_byte;
    QLabel *label_12;
    QLineEdit *now_byte;
    QLabel *label_13;
    QLineEdit *byte_length;
    QPushButton *down_wave;

    void setupUi(QWidget *Any_wave)
    {
        if (Any_wave->objectName().isEmpty())
            Any_wave->setObjectName(QStringLiteral("Any_wave"));
        Any_wave->resize(750, 500);
        gridLayout_3 = new QGridLayout(Any_wave);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setVerticalSpacing(0);
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(2);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer);

        ua_state = new m_checkbox(Any_wave);
        ua_state->setObjectName(QStringLiteral("ua_state"));
        ua_state->setCheckable(false);
        ua_state->setTristate(false);

        horizontalLayout_11->addWidget(ua_state);

        ub_state = new m_checkbox(Any_wave);
        ub_state->setObjectName(QStringLiteral("ub_state"));
        ub_state->setCheckable(false);

        horizontalLayout_11->addWidget(ub_state);

        uc_state = new m_checkbox(Any_wave);
        uc_state->setObjectName(QStringLiteral("uc_state"));
        uc_state->setCheckable(false);

        horizontalLayout_11->addWidget(uc_state);

        ia_state = new m_checkbox(Any_wave);
        ia_state->setObjectName(QStringLiteral("ia_state"));
        ia_state->setCheckable(false);

        horizontalLayout_11->addWidget(ia_state);

        ib_state = new m_checkbox(Any_wave);
        ib_state->setObjectName(QStringLiteral("ib_state"));
        ib_state->setCheckable(false);

        horizontalLayout_11->addWidget(ib_state);

        ic_state = new m_checkbox(Any_wave);
        ic_state->setObjectName(QStringLiteral("ic_state"));
        ic_state->setCheckable(false);

        horizontalLayout_11->addWidget(ic_state);

        state1 = new m_checkbox(Any_wave);
        state1->setObjectName(QStringLiteral("state1"));
        state1->setCheckable(false);

        horizontalLayout_11->addWidget(state1);

        state2 = new m_checkbox(Any_wave);
        state2->setObjectName(QStringLiteral("state2"));
        state2->setCheckable(false);

        horizontalLayout_11->addWidget(state2);

        state3 = new m_checkbox(Any_wave);
        state3->setObjectName(QStringLiteral("state3"));
        state3->setCheckable(false);

        horizontalLayout_11->addWidget(state3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_2);


        gridLayout_3->addLayout(horizontalLayout_11, 0, 0, 1, 1);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        change_map = new QTabWidget(Any_wave);
        change_map->setObjectName(QStringLiteral("change_map"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_8 = new QGridLayout(tab);
        gridLayout_8->setSpacing(0);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        gridLayout_8->setContentsMargins(0, 0, 0, 9);
        bar_map = new CustomPlotHasRoll(tab);
        bar_map->setObjectName(QStringLiteral("bar_map"));

        gridLayout_8->addWidget(bar_map, 0, 0, 1, 1);

        wave_map = new CustomPlotHasRoll(tab);
        wave_map->setObjectName(QStringLiteral("wave_map"));

        gridLayout_8->addWidget(wave_map, 1, 0, 1, 1);

        change_map->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout_9 = new QGridLayout(tab_2);
        gridLayout_9->setSpacing(0);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        gridLayout_9->setContentsMargins(0, 0, 0, 0);
        printf_map = new CustomPlotHasRoll(tab_2);
        printf_map->setObjectName(QStringLiteral("printf_map"));

        gridLayout_9->addWidget(printf_map, 0, 0, 1, 1);

        change_map->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        gridLayout_12 = new QGridLayout(tab_3);
        gridLayout_12->setSpacing(0);
        gridLayout_12->setObjectName(QStringLiteral("gridLayout_12"));
        gridLayout_12->setContentsMargins(0, 0, 0, 0);
        show_wave = new CustomPlotHasRoll(tab_3);
        show_wave->setObjectName(QStringLiteral("show_wave"));

        gridLayout_12->addWidget(show_wave, 0, 0, 1, 1);

        change_map->addTab(tab_3, QString());

        verticalLayout_10->addWidget(change_map);

        gridLayout_7 = new QGridLayout();
        gridLayout_7->setSpacing(2);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        frame = new QFrame(Any_wave);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        frame->setLineWidth(2);
        gridLayout = new QGridLayout(frame);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(5);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(-1, 5, -1, -1);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(5, -1, -1, -1);
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(label);

        thd = new QLineEdit(frame);
        thd->setObjectName(QStringLiteral("thd"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(thd->sizePolicy().hasHeightForWidth());
        thd->setSizePolicy(sizePolicy1);
        thd->setReadOnly(true);

        horizontalLayout->addWidget(thd);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);


        horizontalLayout_5->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(label_3);

        rms = new QLineEdit(frame);
        rms->setObjectName(QStringLiteral("rms"));
        sizePolicy1.setHeightForWidth(rms->sizePolicy().hasHeightForWidth());
        rms->setSizePolicy(sizePolicy1);
        rms->setReadOnly(true);

        horizontalLayout_2->addWidget(rms);


        horizontalLayout_5->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, -1, 5, -1);
        label_4 = new QLabel(frame);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(label_4);

        ratio = new QLineEdit(frame);
        ratio->setObjectName(QStringLiteral("ratio"));
        sizePolicy1.setHeightForWidth(ratio->sizePolicy().hasHeightForWidth());
        ratio->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(ratio);


        horizontalLayout_5->addLayout(horizontalLayout_3);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(5);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(5, -1, 5, 5);
        clear = new QPushButton(frame);
        clear->setObjectName(QStringLiteral("clear"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(clear->sizePolicy().hasHeightForWidth());
        clear->setSizePolicy(sizePolicy2);

        horizontalLayout_4->addWidget(clear);

        priview = new QPushButton(frame);
        priview->setObjectName(QStringLiteral("priview"));
        sizePolicy2.setHeightForWidth(priview->sizePolicy().hasHeightForWidth());
        priview->setSizePolicy(sizePolicy2);

        horizontalLayout_4->addWidget(priview);

        save = new QPushButton(frame);
        save->setObjectName(QStringLiteral("save"));
        sizePolicy2.setHeightForWidth(save->sizePolicy().hasHeightForWidth());
        save->setSizePolicy(sizePolicy2);

        horizontalLayout_4->addWidget(save);


        verticalLayout->addLayout(horizontalLayout_4);


        verticalLayout_2->addLayout(verticalLayout);

        frame_4 = new QFrame(frame);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setFrameShape(QFrame::HLine);
        frame_4->setFrameShadow(QFrame::Raised);
        frame_4->setLineWidth(2);

        verticalLayout_2->addWidget(frame_4);

        change_data = new QTabWidget(frame);
        change_data->setObjectName(QStringLiteral("change_data"));
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        gridLayout_10 = new QGridLayout(tab_5);
        gridLayout_10->setSpacing(0);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        gridLayout_10->setContentsMargins(0, 0, 0, 0);
        hrenter_data = new QTableWidget(tab_5);
        if (hrenter_data->columnCount() < 3)
            hrenter_data->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        hrenter_data->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        hrenter_data->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        hrenter_data->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        hrenter_data->setObjectName(QStringLiteral("hrenter_data"));

        gridLayout_10->addWidget(hrenter_data, 0, 0, 1, 1);

        change_data->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        gridLayout_11 = new QGridLayout(tab_6);
        gridLayout_11->setSpacing(0);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        gridLayout_11->setContentsMargins(0, 0, 0, 0);
        point_data = new QTableWidget(tab_6);
        if (point_data->columnCount() < 2)
            point_data->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        point_data->setHorizontalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        point_data->setHorizontalHeaderItem(1, __qtablewidgetitem4);
        point_data->setObjectName(QStringLiteral("point_data"));

        gridLayout_11->addWidget(point_data, 0, 0, 1, 1);

        change_data->addTab(tab_6, QString());

        verticalLayout_2->addWidget(change_data);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 1);
        verticalLayout_2->setStretch(2, 4);

        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);


        gridLayout_7->addWidget(frame, 0, 0, 1, 1);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(0);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        frame_2 = new QFrame(Any_wave);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::Box);
        frame_2->setFrameShadow(QFrame::Raised);
        frame_2->setLineWidth(2);
        gridLayout_5 = new QGridLayout(frame_2);
        gridLayout_5->setSpacing(0);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(2);
        gridLayout_2->setVerticalSpacing(0);
        gridLayout_2->setContentsMargins(-1, -1, 2, -1);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(5, 5, 5, 5);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        time_lenth = new QDoubleSpinBox(frame_2);
        time_lenth->setObjectName(QStringLiteral("time_lenth"));
        sizePolicy2.setHeightForWidth(time_lenth->sizePolicy().hasHeightForWidth());
        time_lenth->setSizePolicy(sizePolicy2);
        time_lenth->setDecimals(3);
        time_lenth->setMaximum(1.5);
        time_lenth->setSingleStep(0.01);
        time_lenth->setValue(0.02);

        horizontalLayout_6->addWidget(time_lenth);

        label_5 = new QLabel(frame_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);

        horizontalLayout_6->addWidget(label_5);

        save_data = new QPushButton(frame_2);
        save_data->setObjectName(QStringLiteral("save_data"));
        sizePolicy2.setHeightForWidth(save_data->sizePolicy().hasHeightForWidth());
        save_data->setSizePolicy(sizePolicy2);

        horizontalLayout_6->addWidget(save_data);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(5);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, -1, 0, -1);
        print_map = new QPushButton(frame_2);
        print_map->setObjectName(QStringLiteral("print_map"));
        sizePolicy2.setHeightForWidth(print_map->sizePolicy().hasHeightForWidth());
        print_map->setSizePolicy(sizePolicy2);
        print_map->setCheckable(true);

        horizontalLayout_7->addWidget(print_map);

        back_point = new QPushButton(frame_2);
        back_point->setObjectName(QStringLiteral("back_point"));
        sizePolicy2.setHeightForWidth(back_point->sizePolicy().hasHeightForWidth());
        back_point->setSizePolicy(sizePolicy2);

        horizontalLayout_7->addWidget(back_point);

        smooth_wave = new QPushButton(frame_2);
        smooth_wave->setObjectName(QStringLiteral("smooth_wave"));
        sizePolicy2.setHeightForWidth(smooth_wave->sizePolicy().hasHeightForWidth());
        smooth_wave->setSizePolicy(sizePolicy2);

        horizontalLayout_7->addWidget(smooth_wave);


        verticalLayout_3->addLayout(horizontalLayout_7);


        gridLayout_2->addLayout(verticalLayout_3, 0, 0, 1, 1);

        tran = new QPushButton(frame_2);
        tran->setObjectName(QStringLiteral("tran"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(tran->sizePolicy().hasHeightForWidth());
        tran->setSizePolicy(sizePolicy3);

        gridLayout_2->addWidget(tran, 0, 2, 1, 1);

        frame_5 = new QFrame(frame_2);
        frame_5->setObjectName(QStringLiteral("frame_5"));
        sizePolicy1.setHeightForWidth(frame_5->sizePolicy().hasHeightForWidth());
        frame_5->setSizePolicy(sizePolicy1);
        frame_5->setFrameShape(QFrame::VLine);
        frame_5->setFrameShadow(QFrame::Raised);
        frame_5->setLineWidth(2);

        gridLayout_2->addWidget(frame_5, 0, 1, 1, 1);

        gridLayout_2->setColumnStretch(0, 3);
        gridLayout_2->setColumnStretch(2, 1);

        gridLayout_5->addLayout(gridLayout_2, 0, 0, 1, 1);


        gridLayout_6->addWidget(frame_2, 0, 0, 1, 1);

        frame_3 = new QFrame(Any_wave);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setFrameShape(QFrame::Box);
        frame_3->setFrameShadow(QFrame::Raised);
        frame_3->setLineWidth(2);
        gridLayout_4 = new QGridLayout(frame_3);
        gridLayout_4->setSpacing(0);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(0);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(0);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(-1, -1, 0, -1);
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(5, 0, 5, -1);
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(5);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, -1, -1, -1);
        label_6 = new QLabel(frame_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);

        horizontalLayout_9->addWidget(label_6);

        label_7 = new QLabel(frame_3);
        label_7->setObjectName(QStringLiteral("label_7"));
        sizePolicy1.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy1);

        horizontalLayout_9->addWidget(label_7);

        label_8 = new QLabel(frame_3);
        label_8->setObjectName(QStringLiteral("label_8"));
        sizePolicy1.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy1);

        horizontalLayout_9->addWidget(label_8);


        verticalLayout_6->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(5);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        base_value = new QDoubleSpinBox(frame_3);
        base_value->setObjectName(QStringLiteral("base_value"));
        sizePolicy1.setHeightForWidth(base_value->sizePolicy().hasHeightForWidth());
        base_value->setSizePolicy(sizePolicy1);
        base_value->setMaximum(9999.99);

        horizontalLayout_10->addWidget(base_value);

        freq = new QDoubleSpinBox(frame_3);
        freq->setObjectName(QStringLiteral("freq"));
        sizePolicy1.setHeightForWidth(freq->sizePolicy().hasHeightForWidth());
        freq->setSizePolicy(sizePolicy1);
        freq->setMaximum(999.99);

        horizontalLayout_10->addWidget(freq);

        sampling = new QDoubleSpinBox(frame_3);
        sampling->setObjectName(QStringLiteral("sampling"));
        sizePolicy1.setHeightForWidth(sampling->sizePolicy().hasHeightForWidth());
        sampling->setSizePolicy(sizePolicy1);
        sampling->setMaximum(1e+07);

        horizontalLayout_10->addWidget(sampling);

        horizontalLayout_10->setStretch(0, 1);
        horizontalLayout_10->setStretch(1, 1);
        horizontalLayout_10->setStretch(2, 1);

        verticalLayout_6->addLayout(horizontalLayout_10);

        verticalLayout_6->setStretch(0, 1);
        verticalLayout_6->setStretch(1, 1);

        verticalLayout_9->addLayout(verticalLayout_6);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(5);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        horizontalLayout_13->setContentsMargins(-1, 2, 5, 5);
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(5);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(5, -1, -1, -1);
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        label_9 = new QLabel(frame_3);
        label_9->setObjectName(QStringLiteral("label_9"));
        sizePolicy1.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy1);

        verticalLayout_7->addWidget(label_9);

        tig_model = new M_spinbox(frame_3);
        tig_model->setObjectName(QStringLiteral("tig_model"));
        sizePolicy1.setHeightForWidth(tig_model->sizePolicy().hasHeightForWidth());
        tig_model->setSizePolicy(sizePolicy1);

        verticalLayout_7->addWidget(tig_model);


        horizontalLayout_8->addLayout(verticalLayout_7);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setSpacing(0);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        label_10 = new QLabel(frame_3);
        label_10->setObjectName(QStringLiteral("label_10"));
        sizePolicy1.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy1);
        label_10->setLayoutDirection(Qt::LeftToRight);
        label_10->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_12->addWidget(label_10);

        phase = new M_spinbox(frame_3);
        phase->setObjectName(QStringLiteral("phase"));
        sizePolicy1.setHeightForWidth(phase->sizePolicy().hasHeightForWidth());
        phase->setSizePolicy(sizePolicy1);

        verticalLayout_12->addWidget(phase);


        horizontalLayout_8->addLayout(verticalLayout_12);


        horizontalLayout_13->addLayout(horizontalLayout_8);

        set = new QPushButton(frame_3);
        set->setObjectName(QStringLiteral("set"));
        sizePolicy1.setHeightForWidth(set->sizePolicy().hasHeightForWidth());
        set->setSizePolicy(sizePolicy1);

        horizontalLayout_13->addWidget(set);

        horizontalLayout_13->setStretch(0, 1);
        horizontalLayout_13->setStretch(1, 2);

        verticalLayout_9->addLayout(horizontalLayout_13);

        frame_6 = new QFrame(frame_3);
        frame_6->setObjectName(QStringLiteral("frame_6"));
        sizePolicy1.setHeightForWidth(frame_6->sizePolicy().hasHeightForWidth());
        frame_6->setSizePolicy(sizePolicy1);
        frame_6->setFrameShape(QFrame::HLine);
        frame_6->setFrameShadow(QFrame::Raised);
        frame_6->setLineWidth(2);

        verticalLayout_9->addWidget(frame_6);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(2);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        horizontalLayout_14->setContentsMargins(-1, 2, 5, 5);
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(5);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(5, -1, -1, -1);
        label_14 = new QLabel(frame_3);
        label_14->setObjectName(QStringLiteral("label_14"));
        sizePolicy1.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy1);

        verticalLayout_8->addWidget(label_14);

        out_model = new QSpinBox(frame_3);
        out_model->setObjectName(QStringLiteral("out_model"));
        sizePolicy1.setHeightForWidth(out_model->sizePolicy().hasHeightForWidth());
        out_model->setSizePolicy(sizePolicy1);
        out_model->setWrapping(true);
        out_model->setMaximum(254);
        out_model->setValue(0);

        verticalLayout_8->addWidget(out_model);


        horizontalLayout_14->addLayout(verticalLayout_8);

        start_wave = new QPushButton(frame_3);
        start_wave->setObjectName(QStringLiteral("start_wave"));
        sizePolicy1.setHeightForWidth(start_wave->sizePolicy().hasHeightForWidth());
        start_wave->setSizePolicy(sizePolicy1);

        horizontalLayout_14->addWidget(start_wave);

        stop_wave = new QPushButton(frame_3);
        stop_wave->setObjectName(QStringLiteral("stop_wave"));
        sizePolicy1.setHeightForWidth(stop_wave->sizePolicy().hasHeightForWidth());
        stop_wave->setSizePolicy(sizePolicy1);

        horizontalLayout_14->addWidget(stop_wave);


        verticalLayout_9->addLayout(horizontalLayout_14);

        verticalLayout_9->setStretch(0, 1);
        verticalLayout_9->setStretch(1, 1);
        verticalLayout_9->setStretch(3, 1);

        horizontalLayout_15->addLayout(verticalLayout_9);

        frame_7 = new QFrame(frame_3);
        frame_7->setObjectName(QStringLiteral("frame_7"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(frame_7->sizePolicy().hasHeightForWidth());
        frame_7->setSizePolicy(sizePolicy4);
        frame_7->setFrameShape(QFrame::VLine);
        frame_7->setFrameShadow(QFrame::Raised);
        frame_7->setLineWidth(2);

        horizontalLayout_15->addWidget(frame_7);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(2);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(2, 2, 2, 2);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(2);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_11 = new QLabel(frame_3);
        label_11->setObjectName(QStringLiteral("label_11"));
        sizePolicy1.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy1);

        verticalLayout_4->addWidget(label_11);

        all_byte = new QLineEdit(frame_3);
        all_byte->setObjectName(QStringLiteral("all_byte"));
        sizePolicy1.setHeightForWidth(all_byte->sizePolicy().hasHeightForWidth());
        all_byte->setSizePolicy(sizePolicy1);
        all_byte->setReadOnly(true);

        verticalLayout_4->addWidget(all_byte);

        label_12 = new QLabel(frame_3);
        label_12->setObjectName(QStringLiteral("label_12"));
        sizePolicy1.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy1);

        verticalLayout_4->addWidget(label_12);

        now_byte = new QLineEdit(frame_3);
        now_byte->setObjectName(QStringLiteral("now_byte"));
        sizePolicy1.setHeightForWidth(now_byte->sizePolicy().hasHeightForWidth());
        now_byte->setSizePolicy(sizePolicy1);
        now_byte->setReadOnly(true);

        verticalLayout_4->addWidget(now_byte);

        label_13 = new QLabel(frame_3);
        label_13->setObjectName(QStringLiteral("label_13"));
        sizePolicy1.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy1);

        verticalLayout_4->addWidget(label_13);

        byte_length = new QLineEdit(frame_3);
        byte_length->setObjectName(QStringLiteral("byte_length"));
        sizePolicy1.setHeightForWidth(byte_length->sizePolicy().hasHeightForWidth());
        byte_length->setSizePolicy(sizePolicy1);

        verticalLayout_4->addWidget(byte_length);


        verticalLayout_5->addLayout(verticalLayout_4);

        down_wave = new QPushButton(frame_3);
        down_wave->setObjectName(QStringLiteral("down_wave"));
        sizePolicy1.setHeightForWidth(down_wave->sizePolicy().hasHeightForWidth());
        down_wave->setSizePolicy(sizePolicy1);

        verticalLayout_5->addWidget(down_wave);

        verticalLayout_5->setStretch(0, 4);
        verticalLayout_5->setStretch(1, 1);

        horizontalLayout_15->addLayout(verticalLayout_5);

        horizontalLayout_15->setStretch(0, 3);
        horizontalLayout_15->setStretch(2, 1);

        gridLayout_4->addLayout(horizontalLayout_15, 0, 0, 1, 1);


        gridLayout_6->addWidget(frame_3, 1, 0, 1, 1);


        gridLayout_7->addLayout(gridLayout_6, 0, 1, 1, 1);

        gridLayout_7->setColumnStretch(0, 1);
        gridLayout_7->setColumnStretch(1, 1);

        verticalLayout_10->addLayout(gridLayout_7);

        verticalLayout_10->setStretch(0, 1);
        verticalLayout_10->setStretch(1, 1);

        gridLayout_3->addLayout(verticalLayout_10, 1, 0, 1, 1);


        retranslateUi(Any_wave);

        change_map->setCurrentIndex(0);
        change_data->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Any_wave);
    } // setupUi

    void retranslateUi(QWidget *Any_wave)
    {
        Any_wave->setWindowTitle(QApplication::translate("Any_wave", "Form", 0));
        ua_state->setText(QApplication::translate("Any_wave", "UA", 0));
        ub_state->setText(QApplication::translate("Any_wave", "UB", 0));
        uc_state->setText(QApplication::translate("Any_wave", "UC", 0));
        ia_state->setText(QApplication::translate("Any_wave", "IA", 0));
        ib_state->setText(QApplication::translate("Any_wave", "IB", 0));
        ic_state->setText(QApplication::translate("Any_wave", "IC", 0));
        state1->setText(QApplication::translate("Any_wave", "\346\234\252\345\206\231\345\205\245", 0));
        state2->setText(QApplication::translate("Any_wave", "\345\206\231\345\205\245", 0));
        state3->setText(QApplication::translate("Any_wave", "\345\267\262\345\220\257\345\212\250", 0));
        change_map->setTabText(change_map->indexOf(tab), QApplication::translate("Any_wave", "Tab 1", 0));
        change_map->setTabText(change_map->indexOf(tab_2), QApplication::translate("Any_wave", "Tab 2", 0));
        change_map->setTabText(change_map->indexOf(tab_3), QApplication::translate("Any_wave", "\351\241\265", 0));
        label->setText(QApplication::translate("Any_wave", "THD", 0));
        label_2->setText(QApplication::translate("Any_wave", "%", 0));
        label_3->setText(QApplication::translate("Any_wave", "RMS", 0));
        label_4->setText(QApplication::translate("Any_wave", "\347\233\264\346\265\201", 0));
        ratio->setText(QString());
        clear->setText(QApplication::translate("Any_wave", "\346\270\205\351\233\266", 0));
        priview->setText(QApplication::translate("Any_wave", "\351\242\204\350\247\210", 0));
        save->setText(QApplication::translate("Any_wave", "\344\277\235\345\255\230", 0));
        QTableWidgetItem *___qtablewidgetitem = hrenter_data->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Any_wave", "\350\260\220\346\263\242\345\220\253\346\234\211\347\216\207(%)", 0));
        QTableWidgetItem *___qtablewidgetitem1 = hrenter_data->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Any_wave", "\350\260\220\346\263\242\345\220\253\351\207\217", 0));
        QTableWidgetItem *___qtablewidgetitem2 = hrenter_data->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Any_wave", "\350\260\220\346\263\242\347\233\270\344\275\215", 0));
        change_data->setTabText(change_data->indexOf(tab_5), QApplication::translate("Any_wave", "Tab 1", 0));
        QTableWidgetItem *___qtablewidgetitem3 = point_data->horizontalHeaderItem(0);
        ___qtablewidgetitem3->setText(QApplication::translate("Any_wave", "\347\202\271\347\232\204t\347\232\204\344\275\215\347\275\256", 0));
        QTableWidgetItem *___qtablewidgetitem4 = point_data->horizontalHeaderItem(1);
        ___qtablewidgetitem4->setText(QApplication::translate("Any_wave", "\351\200\211\345\217\226\347\202\271\347\232\204\345\271\205\345\200\274", 0));
        change_data->setTabText(change_data->indexOf(tab_6), QApplication::translate("Any_wave", "Tab 2", 0));
        label_5->setText(QApplication::translate("Any_wave", "\346\263\242\345\275\242\351\225\277\345\272\246(\347\247\222)", 0));
        save_data->setText(QApplication::translate("Any_wave", "\344\277\235\345\255\230\346\225\260\346\215\256", 0));
        print_map->setText(QApplication::translate("Any_wave", "\346\211\213\345\267\245\347\273\230\345\210\266", 0));
        back_point->setText(QApplication::translate("Any_wave", "\346\222\244\351\224\200\345\211\215\344\270\200\347\202\271", 0));
        smooth_wave->setText(QApplication::translate("Any_wave", "\345\271\263\346\273\221\346\263\242\345\275\242", 0));
        tran->setText(QApplication::translate("Any_wave", "\346\232\202\346\200\201\346\263\242\345\275\242", 0));
        label_6->setText(QApplication::translate("Any_wave", "\346\263\242\345\275\242\345\263\260\345\200\274", 0));
        label_7->setText(QApplication::translate("Any_wave", "\351\242\221\347\216\207", 0));
        label_8->setText(QApplication::translate("Any_wave", "\351\207\207\346\240\267\347\216\207", 0));
        label_9->setText(QApplication::translate("Any_wave", "\350\247\246\345\217\221\346\250\241\345\274\217", 0));
        label_10->setText(QApplication::translate("Any_wave", "\347\233\270\351\200\211\346\213\251", 0));
#ifndef QT_NO_TOOLTIP
        set->setToolTip(QApplication::translate("Any_wave", "\350\256\276\347\275\256\350\276\223\345\207\272\347\233\270\345\222\214\350\247\246\345\217\221\346\250\241\345\274\217", 0));
#endif // QT_NO_TOOLTIP
        set->setText(QApplication::translate("Any_wave", "\350\256\276\347\275\256", 0));
        label_14->setText(QApplication::translate("Any_wave", "\350\276\223\345\207\272\346\254\241\346\225\260", 0));
#ifndef QT_NO_TOOLTIP
        out_model->setToolTip(QApplication::translate("Any_wave", "255\344\270\272\351\207\215\345\244\215\350\276\223\345\207\272", 0));
#endif // QT_NO_TOOLTIP
        start_wave->setText(QApplication::translate("Any_wave", "\345\220\257\345\212\250\346\263\242\345\275\242", 0));
        stop_wave->setText(QApplication::translate("Any_wave", "\345\201\234\346\255\242\346\263\242\345\275\242", 0));
        label_11->setText(QApplication::translate("Any_wave", "\346\200\273\345\270\247\346\225\260", 0));
        label_12->setText(QApplication::translate("Any_wave", "\345\275\223\345\211\215\345\270\247", 0));
        label_13->setText(QApplication::translate("Any_wave", "\346\257\217\345\270\247\351\225\277\345\272\246", 0));
        down_wave->setText(QApplication::translate("Any_wave", "\346\263\242\345\275\242\344\270\213\350\275\275", 0));
    } // retranslateUi

};

namespace Ui {
    class Any_wave: public Ui_Any_wave {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANY_WAVE_H
