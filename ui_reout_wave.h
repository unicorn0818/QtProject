/********************************************************************************
** Form generated from reading UI file 'reout_wave.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REOUT_WAVE_H
#define UI_REOUT_WAVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <customplothasroll.h>
#include "m_spinbox.h"

QT_BEGIN_NAMESPACE

class Ui_reout_wave
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_12;
    CustomPlotHasRoll *u_map;
    CustomPlotHasRoll *i_map;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_21;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *flush_lenth;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLineEdit *wave_lenth;
    QHBoxLayout *horizontalLayout_3;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_6;
    QSpinBox *uc_pipe;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_7;
    QSpinBox *ia_pipe;
    QVBoxLayout *verticalLayout_12;
    QLabel *label_8;
    QSpinBox *ic_pipe;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_4;
    QSpinBox *ua_pipe;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_5;
    QSpinBox *ub_pipe;
    QVBoxLayout *verticalLayout_11;
    QLabel *label_9;
    QSpinBox *ib_pipe;
    QFrame *frame_2;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_14;
    QLabel *label_11;
    QLineEdit *wave_end;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *read_falush_lenth;
    QPushButton *write_wave_date;
    QVBoxLayout *verticalLayout_13;
    QLabel *label_10;
    QLineEdit *wave_start;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *mid_wave;
    QPushButton *map_control;
    QVBoxLayout *verticalLayout_4;
    QFrame *frame_5;
    QGridLayout *gridLayout_5;
    QHBoxLayout *horizontalLayout;
    QCheckBox *all;
    QCheckBox *ua_flag;
    QCheckBox *ia_flag;
    QCheckBox *ub_flag;
    QCheckBox *ib_flag;
    QCheckBox *uc_flag;
    QCheckBox *ic_flag;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_4;
    QFrame *frame_3;
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout_18;
    QLabel *label_17;
    QLineEdit *ia_max;
    QVBoxLayout *verticalLayout_15;
    QLabel *label_12;
    QLineEdit *ua_max;
    QVBoxLayout *verticalLayout_20;
    QLabel *label_16;
    QLineEdit *ic_max;
    QVBoxLayout *verticalLayout_17;
    QLabel *label_14;
    QLineEdit *uc_max;
    QVBoxLayout *verticalLayout_19;
    QLabel *label_15;
    QLineEdit *ib_max;
    QVBoxLayout *verticalLayout_16;
    QLabel *label_13;
    QLineEdit *ub_max;
    QFrame *frame_4;
    QGridLayout *gridLayout_6;
    QLabel *label_18;
    QPushButton *start_out;
    M_spinbox *tigger_mode;
    M_spinbox *out_count;
    QPushButton *stop_out;
    QLabel *label_19;

    void setupUi(QWidget *reout_wave)
    {
        if (reout_wave->objectName().isEmpty())
            reout_wave->setObjectName(QStringLiteral("reout_wave"));
        reout_wave->resize(750, 500);
        gridLayout = new QGridLayout(reout_wave);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(2);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));

        verticalLayout_5->addLayout(horizontalLayout_12);

        u_map = new CustomPlotHasRoll(reout_wave);
        u_map->setObjectName(QStringLiteral("u_map"));

        verticalLayout_5->addWidget(u_map);

        i_map = new CustomPlotHasRoll(reout_wave);
        i_map->setObjectName(QStringLiteral("i_map"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(i_map->sizePolicy().hasHeightForWidth());
        i_map->setSizePolicy(sizePolicy);

        verticalLayout_5->addWidget(i_map);

        verticalLayout_5->setStretch(1, 1);
        verticalLayout_5->setStretch(2, 1);

        verticalLayout_6->addLayout(verticalLayout_5);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(2);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(-1, 5, -1, -1);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_21 = new QVBoxLayout();
        verticalLayout_21->setSpacing(2);
        verticalLayout_21->setObjectName(QStringLiteral("verticalLayout_21"));
        pushButton = new QPushButton(reout_wave);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);

        verticalLayout_21->addWidget(pushButton);

        pushButton_2 = new QPushButton(reout_wave);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);

        verticalLayout_21->addWidget(pushButton_2);


        horizontalLayout_2->addLayout(verticalLayout_21);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(4, -1, -1, -1);
        label = new QLabel(reout_wave);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(label);

        flush_lenth = new QLineEdit(reout_wave);
        flush_lenth->setObjectName(QStringLiteral("flush_lenth"));
        sizePolicy.setHeightForWidth(flush_lenth->sizePolicy().hasHeightForWidth());
        flush_lenth->setSizePolicy(sizePolicy);
        flush_lenth->setReadOnly(true);

        verticalLayout->addWidget(flush_lenth);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(4, -1, -1, -1);
        label_2 = new QLabel(reout_wave);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(label_2);

        wave_lenth = new QLineEdit(reout_wave);
        wave_lenth->setObjectName(QStringLiteral("wave_lenth"));
        sizePolicy.setHeightForWidth(wave_lenth->sizePolicy().hasHeightForWidth());
        wave_lenth->setSizePolicy(sizePolicy);
        wave_lenth->setReadOnly(true);

        verticalLayout_2->addWidget(wave_lenth);


        horizontalLayout_2->addLayout(verticalLayout_2);

        horizontalLayout_2->setStretch(0, 4);
        horizontalLayout_2->setStretch(1, 3);
        horizontalLayout_2->setStretch(2, 3);

        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(2);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        frame = new QFrame(reout_wave);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        frame->setLineWidth(2);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setSpacing(2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(2, 2, 2, 2);
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(2);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        label_6 = new QLabel(frame);
        label_6->setObjectName(QStringLiteral("label_6"));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);

        verticalLayout_9->addWidget(label_6);

        uc_pipe = new QSpinBox(frame);
        uc_pipe->setObjectName(QStringLiteral("uc_pipe"));
        sizePolicy.setHeightForWidth(uc_pipe->sizePolicy().hasHeightForWidth());
        uc_pipe->setSizePolicy(sizePolicy);
        uc_pipe->setWrapping(true);
        uc_pipe->setValue(3);

        verticalLayout_9->addWidget(uc_pipe);


        gridLayout_2->addLayout(verticalLayout_9, 2, 0, 1, 1);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(2);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        label_7 = new QLabel(frame);
        label_7->setObjectName(QStringLiteral("label_7"));
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);

        verticalLayout_10->addWidget(label_7);

        ia_pipe = new QSpinBox(frame);
        ia_pipe->setObjectName(QStringLiteral("ia_pipe"));
        sizePolicy.setHeightForWidth(ia_pipe->sizePolicy().hasHeightForWidth());
        ia_pipe->setSizePolicy(sizePolicy);
        ia_pipe->setWrapping(true);
        ia_pipe->setValue(4);

        verticalLayout_10->addWidget(ia_pipe);


        gridLayout_2->addLayout(verticalLayout_10, 0, 1, 1, 1);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setSpacing(2);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        label_8 = new QLabel(frame);
        label_8->setObjectName(QStringLiteral("label_8"));
        sizePolicy.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy);

        verticalLayout_12->addWidget(label_8);

        ic_pipe = new QSpinBox(frame);
        ic_pipe->setObjectName(QStringLiteral("ic_pipe"));
        sizePolicy.setHeightForWidth(ic_pipe->sizePolicy().hasHeightForWidth());
        ic_pipe->setSizePolicy(sizePolicy);
        ic_pipe->setWrapping(true);
        ic_pipe->setValue(6);

        verticalLayout_12->addWidget(ic_pipe);


        gridLayout_2->addLayout(verticalLayout_12, 2, 1, 1, 1);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(2);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        label_4 = new QLabel(frame);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);

        verticalLayout_7->addWidget(label_4);

        ua_pipe = new QSpinBox(frame);
        ua_pipe->setObjectName(QStringLiteral("ua_pipe"));
        sizePolicy.setHeightForWidth(ua_pipe->sizePolicy().hasHeightForWidth());
        ua_pipe->setSizePolicy(sizePolicy);
        ua_pipe->setWrapping(true);
        ua_pipe->setValue(1);

        verticalLayout_7->addWidget(ua_pipe);


        gridLayout_2->addLayout(verticalLayout_7, 0, 0, 1, 1);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(2);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        label_5 = new QLabel(frame);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);

        verticalLayout_8->addWidget(label_5);

        ub_pipe = new QSpinBox(frame);
        ub_pipe->setObjectName(QStringLiteral("ub_pipe"));
        sizePolicy.setHeightForWidth(ub_pipe->sizePolicy().hasHeightForWidth());
        ub_pipe->setSizePolicy(sizePolicy);
        ub_pipe->setWrapping(true);
        ub_pipe->setValue(2);

        verticalLayout_8->addWidget(ub_pipe);


        gridLayout_2->addLayout(verticalLayout_8, 1, 0, 1, 1);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setSpacing(2);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        label_9 = new QLabel(frame);
        label_9->setObjectName(QStringLiteral("label_9"));
        sizePolicy.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy);

        verticalLayout_11->addWidget(label_9);

        ib_pipe = new QSpinBox(frame);
        ib_pipe->setObjectName(QStringLiteral("ib_pipe"));
        sizePolicy.setHeightForWidth(ib_pipe->sizePolicy().hasHeightForWidth());
        ib_pipe->setSizePolicy(sizePolicy);
        ib_pipe->setWrapping(true);
        ib_pipe->setValue(5);

        verticalLayout_11->addWidget(ib_pipe);


        gridLayout_2->addLayout(verticalLayout_11, 1, 1, 1, 1);


        horizontalLayout_3->addWidget(frame);

        frame_2 = new QFrame(reout_wave);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::Box);
        frame_2->setFrameShadow(QFrame::Raised);
        frame_2->setLineWidth(2);
        gridLayout_3 = new QGridLayout(frame_2);
        gridLayout_3->setSpacing(2);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(2, 2, 2, 2);
        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setSpacing(2);
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        label_11 = new QLabel(frame_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        sizePolicy.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy);

        verticalLayout_14->addWidget(label_11);

        wave_end = new QLineEdit(frame_2);
        wave_end->setObjectName(QStringLiteral("wave_end"));
        sizePolicy.setHeightForWidth(wave_end->sizePolicy().hasHeightForWidth());
        wave_end->setSizePolicy(sizePolicy);

        verticalLayout_14->addWidget(wave_end);


        gridLayout_3->addLayout(verticalLayout_14, 0, 1, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(2);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        read_falush_lenth = new QPushButton(frame_2);
        read_falush_lenth->setObjectName(QStringLiteral("read_falush_lenth"));
        sizePolicy.setHeightForWidth(read_falush_lenth->sizePolicy().hasHeightForWidth());
        read_falush_lenth->setSizePolicy(sizePolicy);

        horizontalLayout_8->addWidget(read_falush_lenth);

        write_wave_date = new QPushButton(frame_2);
        write_wave_date->setObjectName(QStringLiteral("write_wave_date"));
        sizePolicy.setHeightForWidth(write_wave_date->sizePolicy().hasHeightForWidth());
        write_wave_date->setSizePolicy(sizePolicy);

        horizontalLayout_8->addWidget(write_wave_date);


        gridLayout_3->addLayout(horizontalLayout_8, 2, 0, 1, 2);

        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setSpacing(2);
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        label_10 = new QLabel(frame_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        sizePolicy.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy);

        verticalLayout_13->addWidget(label_10);

        wave_start = new QLineEdit(frame_2);
        wave_start->setObjectName(QStringLiteral("wave_start"));
        sizePolicy.setHeightForWidth(wave_start->sizePolicy().hasHeightForWidth());
        wave_start->setSizePolicy(sizePolicy);

        verticalLayout_13->addWidget(wave_start);


        gridLayout_3->addLayout(verticalLayout_13, 0, 0, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(2);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        mid_wave = new QPushButton(frame_2);
        mid_wave->setObjectName(QStringLiteral("mid_wave"));
        sizePolicy.setHeightForWidth(mid_wave->sizePolicy().hasHeightForWidth());
        mid_wave->setSizePolicy(sizePolicy);

        horizontalLayout_9->addWidget(mid_wave);

        map_control = new QPushButton(frame_2);
        map_control->setObjectName(QStringLiteral("map_control"));
        sizePolicy.setHeightForWidth(map_control->sizePolicy().hasHeightForWidth());
        map_control->setSizePolicy(sizePolicy);

        horizontalLayout_9->addWidget(map_control);

        horizontalLayout_9->setStretch(0, 1);
        horizontalLayout_9->setStretch(1, 1);

        gridLayout_3->addLayout(horizontalLayout_9, 1, 0, 1, 2);

        gridLayout_3->setRowStretch(0, 1);
        gridLayout_3->setRowStretch(1, 1);
        gridLayout_3->setRowStretch(2, 1);

        horizontalLayout_3->addWidget(frame_2);

        horizontalLayout_3->setStretch(0, 2);
        horizontalLayout_3->setStretch(1, 3);

        verticalLayout_3->addLayout(horizontalLayout_3);

        verticalLayout_3->setStretch(1, 2);

        horizontalLayout_5->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(2);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        frame_5 = new QFrame(reout_wave);
        frame_5->setObjectName(QStringLiteral("frame_5"));
        frame_5->setFrameShape(QFrame::Box);
        frame_5->setFrameShadow(QFrame::Raised);
        frame_5->setLineWidth(2);
        gridLayout_5 = new QGridLayout(frame_5);
        gridLayout_5->setSpacing(2);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setContentsMargins(2, 2, 2, 2);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        all = new QCheckBox(frame_5);
        all->setObjectName(QStringLiteral("all"));
        sizePolicy.setHeightForWidth(all->sizePolicy().hasHeightForWidth());
        all->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(11);
        all->setFont(font);
        all->setChecked(true);

        horizontalLayout->addWidget(all);

        ua_flag = new QCheckBox(frame_5);
        ua_flag->setObjectName(QStringLiteral("ua_flag"));
        sizePolicy.setHeightForWidth(ua_flag->sizePolicy().hasHeightForWidth());
        ua_flag->setSizePolicy(sizePolicy);
        ua_flag->setFont(font);
        ua_flag->setChecked(true);

        horizontalLayout->addWidget(ua_flag);

        ia_flag = new QCheckBox(frame_5);
        ia_flag->setObjectName(QStringLiteral("ia_flag"));
        sizePolicy.setHeightForWidth(ia_flag->sizePolicy().hasHeightForWidth());
        ia_flag->setSizePolicy(sizePolicy);
        ia_flag->setFont(font);
        ia_flag->setChecked(true);

        horizontalLayout->addWidget(ia_flag);

        ub_flag = new QCheckBox(frame_5);
        ub_flag->setObjectName(QStringLiteral("ub_flag"));
        sizePolicy.setHeightForWidth(ub_flag->sizePolicy().hasHeightForWidth());
        ub_flag->setSizePolicy(sizePolicy);
        ub_flag->setFont(font);
        ub_flag->setChecked(true);

        horizontalLayout->addWidget(ub_flag);

        ib_flag = new QCheckBox(frame_5);
        ib_flag->setObjectName(QStringLiteral("ib_flag"));
        sizePolicy.setHeightForWidth(ib_flag->sizePolicy().hasHeightForWidth());
        ib_flag->setSizePolicy(sizePolicy);
        ib_flag->setFont(font);
        ib_flag->setChecked(true);

        horizontalLayout->addWidget(ib_flag);

        uc_flag = new QCheckBox(frame_5);
        uc_flag->setObjectName(QStringLiteral("uc_flag"));
        sizePolicy.setHeightForWidth(uc_flag->sizePolicy().hasHeightForWidth());
        uc_flag->setSizePolicy(sizePolicy);
        uc_flag->setFont(font);
        uc_flag->setChecked(true);

        horizontalLayout->addWidget(uc_flag);

        ic_flag = new QCheckBox(frame_5);
        ic_flag->setObjectName(QStringLiteral("ic_flag"));
        sizePolicy.setHeightForWidth(ic_flag->sizePolicy().hasHeightForWidth());
        ic_flag->setSizePolicy(sizePolicy);
        ic_flag->setFont(font);
        ic_flag->setChecked(true);

        horizontalLayout->addWidget(ic_flag);


        gridLayout_5->addLayout(horizontalLayout, 1, 0, 1, 1);

        label_3 = new QLabel(frame_5);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);

        gridLayout_5->addWidget(label_3, 0, 0, 1, 1);


        verticalLayout_4->addWidget(frame_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(2);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        frame_3 = new QFrame(reout_wave);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setFrameShape(QFrame::Box);
        frame_3->setFrameShadow(QFrame::Raised);
        frame_3->setLineWidth(2);
        gridLayout_4 = new QGridLayout(frame_3);
        gridLayout_4->setSpacing(2);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(2, 2, 2, 2);
        verticalLayout_18 = new QVBoxLayout();
        verticalLayout_18->setSpacing(2);
        verticalLayout_18->setObjectName(QStringLiteral("verticalLayout_18"));
        label_17 = new QLabel(frame_3);
        label_17->setObjectName(QStringLiteral("label_17"));

        verticalLayout_18->addWidget(label_17);

        ia_max = new QLineEdit(frame_3);
        ia_max->setObjectName(QStringLiteral("ia_max"));
        sizePolicy.setHeightForWidth(ia_max->sizePolicy().hasHeightForWidth());
        ia_max->setSizePolicy(sizePolicy);
        ia_max->setReadOnly(false);

        verticalLayout_18->addWidget(ia_max);


        gridLayout_4->addLayout(verticalLayout_18, 0, 1, 1, 1);

        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setSpacing(2);
        verticalLayout_15->setObjectName(QStringLiteral("verticalLayout_15"));
        label_12 = new QLabel(frame_3);
        label_12->setObjectName(QStringLiteral("label_12"));

        verticalLayout_15->addWidget(label_12);

        ua_max = new QLineEdit(frame_3);
        ua_max->setObjectName(QStringLiteral("ua_max"));
        sizePolicy.setHeightForWidth(ua_max->sizePolicy().hasHeightForWidth());
        ua_max->setSizePolicy(sizePolicy);
        ua_max->setReadOnly(false);

        verticalLayout_15->addWidget(ua_max);


        gridLayout_4->addLayout(verticalLayout_15, 0, 0, 1, 1);

        verticalLayout_20 = new QVBoxLayout();
        verticalLayout_20->setSpacing(2);
        verticalLayout_20->setObjectName(QStringLiteral("verticalLayout_20"));
        label_16 = new QLabel(frame_3);
        label_16->setObjectName(QStringLiteral("label_16"));

        verticalLayout_20->addWidget(label_16);

        ic_max = new QLineEdit(frame_3);
        ic_max->setObjectName(QStringLiteral("ic_max"));
        sizePolicy.setHeightForWidth(ic_max->sizePolicy().hasHeightForWidth());
        ic_max->setSizePolicy(sizePolicy);
        ic_max->setReadOnly(false);

        verticalLayout_20->addWidget(ic_max);


        gridLayout_4->addLayout(verticalLayout_20, 2, 1, 1, 1);

        verticalLayout_17 = new QVBoxLayout();
        verticalLayout_17->setSpacing(2);
        verticalLayout_17->setObjectName(QStringLiteral("verticalLayout_17"));
        label_14 = new QLabel(frame_3);
        label_14->setObjectName(QStringLiteral("label_14"));

        verticalLayout_17->addWidget(label_14);

        uc_max = new QLineEdit(frame_3);
        uc_max->setObjectName(QStringLiteral("uc_max"));
        sizePolicy.setHeightForWidth(uc_max->sizePolicy().hasHeightForWidth());
        uc_max->setSizePolicy(sizePolicy);
        uc_max->setReadOnly(false);

        verticalLayout_17->addWidget(uc_max);


        gridLayout_4->addLayout(verticalLayout_17, 2, 0, 1, 1);

        verticalLayout_19 = new QVBoxLayout();
        verticalLayout_19->setSpacing(2);
        verticalLayout_19->setObjectName(QStringLiteral("verticalLayout_19"));
        label_15 = new QLabel(frame_3);
        label_15->setObjectName(QStringLiteral("label_15"));

        verticalLayout_19->addWidget(label_15);

        ib_max = new QLineEdit(frame_3);
        ib_max->setObjectName(QStringLiteral("ib_max"));
        sizePolicy.setHeightForWidth(ib_max->sizePolicy().hasHeightForWidth());
        ib_max->setSizePolicy(sizePolicy);
        ib_max->setReadOnly(false);

        verticalLayout_19->addWidget(ib_max);


        gridLayout_4->addLayout(verticalLayout_19, 1, 1, 1, 1);

        verticalLayout_16 = new QVBoxLayout();
        verticalLayout_16->setSpacing(2);
        verticalLayout_16->setObjectName(QStringLiteral("verticalLayout_16"));
        label_13 = new QLabel(frame_3);
        label_13->setObjectName(QStringLiteral("label_13"));

        verticalLayout_16->addWidget(label_13);

        ub_max = new QLineEdit(frame_3);
        ub_max->setObjectName(QStringLiteral("ub_max"));
        sizePolicy.setHeightForWidth(ub_max->sizePolicy().hasHeightForWidth());
        ub_max->setSizePolicy(sizePolicy);
        ub_max->setReadOnly(false);

        verticalLayout_16->addWidget(ub_max);


        gridLayout_4->addLayout(verticalLayout_16, 1, 0, 1, 1);


        horizontalLayout_4->addWidget(frame_3);

        frame_4 = new QFrame(reout_wave);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setFrameShape(QFrame::Box);
        frame_4->setFrameShadow(QFrame::Raised);
        frame_4->setLineWidth(2);
        gridLayout_6 = new QGridLayout(frame_4);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_6->setHorizontalSpacing(0);
        gridLayout_6->setVerticalSpacing(2);
        gridLayout_6->setContentsMargins(5, 5, 5, 5);
        label_18 = new QLabel(frame_4);
        label_18->setObjectName(QStringLiteral("label_18"));
        sizePolicy.setHeightForWidth(label_18->sizePolicy().hasHeightForWidth());
        label_18->setSizePolicy(sizePolicy);

        gridLayout_6->addWidget(label_18, 0, 0, 1, 1);

        start_out = new QPushButton(frame_4);
        start_out->setObjectName(QStringLiteral("start_out"));
        sizePolicy.setHeightForWidth(start_out->sizePolicy().hasHeightForWidth());
        start_out->setSizePolicy(sizePolicy);

        gridLayout_6->addWidget(start_out, 2, 0, 1, 2);

        tigger_mode = new M_spinbox(frame_4);
        tigger_mode->setObjectName(QStringLiteral("tigger_mode"));
        sizePolicy.setHeightForWidth(tigger_mode->sizePolicy().hasHeightForWidth());
        tigger_mode->setSizePolicy(sizePolicy);

        gridLayout_6->addWidget(tigger_mode, 0, 1, 1, 1);

        out_count = new M_spinbox(frame_4);
        out_count->setObjectName(QStringLiteral("out_count"));
        sizePolicy.setHeightForWidth(out_count->sizePolicy().hasHeightForWidth());
        out_count->setSizePolicy(sizePolicy);

        gridLayout_6->addWidget(out_count, 1, 1, 1, 1);

        stop_out = new QPushButton(frame_4);
        stop_out->setObjectName(QStringLiteral("stop_out"));
        sizePolicy.setHeightForWidth(stop_out->sizePolicy().hasHeightForWidth());
        stop_out->setSizePolicy(sizePolicy);

        gridLayout_6->addWidget(stop_out, 3, 0, 1, 2);

        label_19 = new QLabel(frame_4);
        label_19->setObjectName(QStringLiteral("label_19"));
        sizePolicy.setHeightForWidth(label_19->sizePolicy().hasHeightForWidth());
        label_19->setSizePolicy(sizePolicy);

        gridLayout_6->addWidget(label_19, 1, 0, 1, 1);


        horizontalLayout_4->addWidget(frame_4);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 1);

        verticalLayout_4->addLayout(horizontalLayout_4);

        verticalLayout_4->setStretch(1, 2);

        horizontalLayout_5->addLayout(verticalLayout_4);

        horizontalLayout_5->setStretch(0, 1);
        horizontalLayout_5->setStretch(1, 1);

        verticalLayout_6->addLayout(horizontalLayout_5);

        verticalLayout_6->setStretch(0, 1);
        verticalLayout_6->setStretch(1, 1);

        gridLayout->addLayout(verticalLayout_6, 0, 0, 1, 1);


        retranslateUi(reout_wave);

        QMetaObject::connectSlotsByName(reout_wave);
    } // setupUi

    void retranslateUi(QWidget *reout_wave)
    {
        reout_wave->setWindowTitle(QApplication::translate("reout_wave", "Form", 0));
        pushButton->setText(QApplication::translate("reout_wave", "\345\275\225\346\263\242\346\226\207\344\273\266\344\277\241\346\201\257", 0));
        pushButton_2->setText(QApplication::translate("reout_wave", "\346\211\223\345\274\200\345\275\225\346\263\242\346\226\207\344\273\266", 0));
        label->setText(QApplication::translate("reout_wave", "\347\274\223\345\255\230\351\225\277\345\272\246(s)", 0));
        flush_lenth->setText(QApplication::translate("reout_wave", "0", 0));
        label_2->setText(QApplication::translate("reout_wave", "\346\263\242\345\275\242\351\225\277\345\272\246(s)", 0));
        wave_lenth->setText(QApplication::translate("reout_wave", "0", 0));
        label_6->setText(QApplication::translate("reout_wave", "UC\345\257\271\345\272\224\351\200\232\351\201\223", 0));
        uc_pipe->setPrefix(QApplication::translate("reout_wave", "\351\200\232\351\201\223", 0));
        label_7->setText(QApplication::translate("reout_wave", "IA\345\257\271\345\272\224\351\200\232\351\201\223", 0));
        ia_pipe->setPrefix(QApplication::translate("reout_wave", "\351\200\232\351\201\223", 0));
        label_8->setText(QApplication::translate("reout_wave", "IC\345\257\271\345\272\224\351\200\232\351\201\223", 0));
        ic_pipe->setPrefix(QApplication::translate("reout_wave", "\351\200\232\351\201\223", 0));
        label_4->setText(QApplication::translate("reout_wave", "UA\345\257\271\345\272\224\351\200\232\351\201\223", 0));
        ua_pipe->setPrefix(QApplication::translate("reout_wave", "\351\200\232\351\201\223", 0));
        label_5->setText(QApplication::translate("reout_wave", "UB\345\257\271\345\272\224\351\200\232\351\201\223", 0));
        ub_pipe->setPrefix(QApplication::translate("reout_wave", "\351\200\232\351\201\223", 0));
        label_9->setText(QApplication::translate("reout_wave", "IB\345\257\271\345\272\224\351\200\232\351\201\223", 0));
        ib_pipe->setPrefix(QApplication::translate("reout_wave", "\351\200\232\351\201\223", 0));
        label_11->setText(QApplication::translate("reout_wave", "\346\263\242\345\275\242\347\273\210\347\202\271", 0));
        wave_end->setText(QApplication::translate("reout_wave", "0", 0));
        read_falush_lenth->setText(QApplication::translate("reout_wave", "\350\257\273\345\217\226\347\274\223\345\255\230\351\225\277\345\272\246", 0));
        write_wave_date->setText(QApplication::translate("reout_wave", "\345\206\231\345\205\245\346\263\242\345\275\242\346\225\260\346\215\256", 0));
        label_10->setText(QApplication::translate("reout_wave", "\346\263\242\345\275\242\350\265\267\347\202\271", 0));
        wave_start->setText(QApplication::translate("reout_wave", "0", 0));
        mid_wave->setText(QApplication::translate("reout_wave", "\346\210\252\345\217\226\346\263\242\345\275\242\345\214\272\351\227\264", 0));
        map_control->setText(QApplication::translate("reout_wave", "\345\233\276\350\241\250\346\223\215\344\275\234", 0));
        all->setText(QApplication::translate("reout_wave", "\345\205\250\351\200\211", 0));
        ua_flag->setText(QApplication::translate("reout_wave", "UA", 0));
        ia_flag->setText(QApplication::translate("reout_wave", "IA", 0));
        ub_flag->setText(QApplication::translate("reout_wave", "UB", 0));
        ib_flag->setText(QApplication::translate("reout_wave", "IB", 0));
        uc_flag->setText(QApplication::translate("reout_wave", "UC", 0));
        ic_flag->setText(QApplication::translate("reout_wave", "IC", 0));
        label_3->setText(QApplication::translate("reout_wave", "\350\276\223\345\207\272\351\200\211\346\213\251", 0));
        label_17->setText(QApplication::translate("reout_wave", "IA\345\263\260\345\200\274", 0));
        ia_max->setText(QApplication::translate("reout_wave", "0", 0));
        label_12->setText(QApplication::translate("reout_wave", "UA\345\263\260\345\200\274", 0));
        ua_max->setText(QApplication::translate("reout_wave", "0", 0));
        label_16->setText(QApplication::translate("reout_wave", "IC\345\263\260\345\200\274", 0));
        ic_max->setText(QApplication::translate("reout_wave", "0", 0));
        label_14->setText(QApplication::translate("reout_wave", "UC\345\263\260\345\200\274", 0));
        uc_max->setText(QApplication::translate("reout_wave", "0", 0));
        label_15->setText(QApplication::translate("reout_wave", "IB\345\263\260\345\200\274", 0));
        ib_max->setText(QApplication::translate("reout_wave", "0", 0));
        label_13->setText(QApplication::translate("reout_wave", "UB\345\263\260\345\200\274", 0));
        ub_max->setText(QApplication::translate("reout_wave", "0", 0));
        label_18->setText(QApplication::translate("reout_wave", "\350\247\246\345\217\221\346\250\241\345\274\217", 0));
        start_out->setText(QApplication::translate("reout_wave", "\345\220\257\345\212\250\350\276\223\345\207\272", 0));
        stop_out->setText(QApplication::translate("reout_wave", "\345\201\234\346\255\242\350\276\223\345\207\272", 0));
        label_19->setText(QApplication::translate("reout_wave", "\350\276\223\345\207\272\346\254\241\346\225\260", 0));
    } // retranslateUi

};

namespace Ui {
    class reout_wave: public Ui_reout_wave {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REOUT_WAVE_H
