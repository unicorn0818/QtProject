/********************************************************************************
** Form generated from reading UI file 'hrenter_out.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HRENTER_OUT_H
#define UI_HRENTER_OUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <customplothasroll.h>
#include "m_checkbox.h"
#include "m_spinbox.h"

QT_BEGIN_NAMESPACE

class Ui_Hrenter_out
{
public:
    QGridLayout *gridLayout_5;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_14;
    QSpacerItem *horizontalSpacer;
    m_checkbox *ua_state;
    m_checkbox *ub_state;
    m_checkbox *uc_state;
    m_checkbox *ia_state;
    m_checkbox *ib_state;
    m_checkbox *ic_state;
    m_checkbox *state1;
    m_checkbox *state3;
    QSpacerItem *horizontalSpacer_3;
    CustomPlotHasRoll *bar_map;
    CustomPlotHasRoll *wave_map;
    QHBoxLayout *horizontalLayout_7;
    QFrame *frame;
    QGridLayout *gridLayout_6;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *clear_hrenter_data;
    QComboBox *pipe_type;
    QPushButton *preview_hrenter;
    QFrame *frame_2;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *thd;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *rms;
    QHBoxLayout *horizontalLayout_8;
    QFrame *frame_3;
    QGridLayout *gridLayout;
    QTableWidget *hrenter_data;
    QFrame *frame_4;
    QHBoxLayout *horizontalLayout_11;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_4;
    M_spinbox *wave_type;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_6;
    QDoubleSpinBox *ratio;
    QVBoxLayout *verticalLayout_12;
    QLabel *label_25;
    M_spinbox *tig_type;
    QHBoxLayout *horizontalLayout_10;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_5;
    QDoubleSpinBox *base_value;
    QVBoxLayout *verticalLayout_11;
    QLabel *label_24;
    QDoubleSpinBox *base_phase;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_7;
    QDoubleSpinBox *freq;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_26;
    QLabel *label_8;
    QLabel *label_16;
    QLabel *label_11;
    QLabel *label_17;
    QLabel *label_9;
    QLabel *label_18;
    QLabel *label_12;
    QLabel *label_19;
    QHBoxLayout *horizontalLayout_5;
    QCheckBox *all;
    QCheckBox *ua;
    QCheckBox *ia;
    QCheckBox *ub;
    QCheckBox *ib;
    QCheckBox *uc;
    QCheckBox *ic;
    QCheckBox *ud;
    QCheckBox *id;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_10;
    QLabel *label_20;
    QLabel *label_15;
    QLabel *label_21;
    QLabel *label_14;
    QLabel *label_22;
    QLabel *label_13;
    QLabel *label_23;
    QHBoxLayout *horizontalLayout_13;
    QCheckBox *ua1;
    QCheckBox *ia1;
    QCheckBox *ub1;
    QCheckBox *ib1;
    QCheckBox *uc1;
    QCheckBox *ic1;
    QCheckBox *ud1;
    QCheckBox *id1;
    QGridLayout *gridLayout_3;
    QPushButton *hrenter_start;
    QPushButton *base_stop;
    QPushButton *base_start;
    QPushButton *hrenter_stop;
    QFrame *frame_5;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_6;
    QPushButton *write_hrenter_data;
    QPushButton *hrenter_all_start;
    QPushButton *base_all_start;
    QPushButton *all_stop;

    void setupUi(QWidget *Hrenter_out)
    {
        if (Hrenter_out->objectName().isEmpty())
            Hrenter_out->setObjectName(QStringLiteral("Hrenter_out"));
        Hrenter_out->resize(750, 500);
        gridLayout_5 = new QGridLayout(Hrenter_out);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(2);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer);

        ua_state = new m_checkbox(Hrenter_out);
        ua_state->setObjectName(QStringLiteral("ua_state"));
        ua_state->setCheckable(false);
        ua_state->setTristate(false);

        horizontalLayout_14->addWidget(ua_state);

        ub_state = new m_checkbox(Hrenter_out);
        ub_state->setObjectName(QStringLiteral("ub_state"));
        ub_state->setCheckable(false);

        horizontalLayout_14->addWidget(ub_state);

        uc_state = new m_checkbox(Hrenter_out);
        uc_state->setObjectName(QStringLiteral("uc_state"));
        uc_state->setCheckable(false);

        horizontalLayout_14->addWidget(uc_state);

        ia_state = new m_checkbox(Hrenter_out);
        ia_state->setObjectName(QStringLiteral("ia_state"));
        ia_state->setCheckable(false);

        horizontalLayout_14->addWidget(ia_state);

        ib_state = new m_checkbox(Hrenter_out);
        ib_state->setObjectName(QStringLiteral("ib_state"));
        ib_state->setCheckable(false);

        horizontalLayout_14->addWidget(ib_state);

        ic_state = new m_checkbox(Hrenter_out);
        ic_state->setObjectName(QStringLiteral("ic_state"));
        ic_state->setCheckable(false);

        horizontalLayout_14->addWidget(ic_state);

        state1 = new m_checkbox(Hrenter_out);
        state1->setObjectName(QStringLiteral("state1"));
        state1->setCheckable(false);

        horizontalLayout_14->addWidget(state1);

        state3 = new m_checkbox(Hrenter_out);
        state3->setObjectName(QStringLiteral("state3"));
        state3->setCheckable(false);

        horizontalLayout_14->addWidget(state3);

        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_3);


        verticalLayout_8->addLayout(horizontalLayout_14);

        bar_map = new CustomPlotHasRoll(Hrenter_out);
        bar_map->setObjectName(QStringLiteral("bar_map"));

        verticalLayout_8->addWidget(bar_map);

        wave_map = new CustomPlotHasRoll(Hrenter_out);
        wave_map->setObjectName(QStringLiteral("wave_map"));

        verticalLayout_8->addWidget(wave_map);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(-1, 2, -1, -1);
        frame = new QFrame(Hrenter_out);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        frame->setLineWidth(2);
        gridLayout_6 = new QGridLayout(frame);
        gridLayout_6->setSpacing(2);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_6->setContentsMargins(2, 2, 2, 2);
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(5);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        clear_hrenter_data = new QPushButton(frame);
        clear_hrenter_data->setObjectName(QStringLiteral("clear_hrenter_data"));

        horizontalLayout_9->addWidget(clear_hrenter_data);

        pipe_type = new QComboBox(frame);
        pipe_type->setObjectName(QStringLiteral("pipe_type"));
        pipe_type->setLayoutDirection(Qt::LeftToRight);
        pipe_type->setSizeAdjustPolicy(QComboBox::AdjustToContentsOnFirstShow);

        horizontalLayout_9->addWidget(pipe_type);

        preview_hrenter = new QPushButton(frame);
        preview_hrenter->setObjectName(QStringLiteral("preview_hrenter"));

        horizontalLayout_9->addWidget(preview_hrenter);

        horizontalLayout_9->setStretch(0, 1);
        horizontalLayout_9->setStretch(1, 1);
        horizontalLayout_9->setStretch(2, 1);

        gridLayout_6->addLayout(horizontalLayout_9, 0, 0, 1, 1);


        horizontalLayout_7->addWidget(frame);

        frame_2 = new QFrame(Hrenter_out);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::Box);
        frame_2->setFrameShadow(QFrame::Raised);
        frame_2->setLineWidth(2);
        gridLayout_2 = new QGridLayout(frame_2);
        gridLayout_2->setSpacing(2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(2, 2, 2, 2);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(frame_2);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        thd = new QLineEdit(frame_2);
        thd->setObjectName(QStringLiteral("thd"));

        horizontalLayout->addWidget(thd);

        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);


        horizontalLayout_3->addLayout(horizontalLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(frame_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        rms = new QLineEdit(frame_2);
        rms->setObjectName(QStringLiteral("rms"));

        horizontalLayout_2->addWidget(rms);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 1);
        horizontalLayout_3->setStretch(2, 1);

        gridLayout_2->addLayout(horizontalLayout_3, 0, 0, 1, 1);


        horizontalLayout_7->addWidget(frame_2);

        horizontalLayout_7->setStretch(0, 1);
        horizontalLayout_7->setStretch(1, 1);

        verticalLayout_8->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(2);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        frame_3 = new QFrame(Hrenter_out);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setFrameShape(QFrame::Box);
        frame_3->setFrameShadow(QFrame::Raised);
        frame_3->setLineWidth(2);
        gridLayout = new QGridLayout(frame_3);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        hrenter_data = new QTableWidget(frame_3);
        if (hrenter_data->columnCount() < 3)
            hrenter_data->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        hrenter_data->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        hrenter_data->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        hrenter_data->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        hrenter_data->setObjectName(QStringLiteral("hrenter_data"));

        gridLayout->addWidget(hrenter_data, 0, 0, 1, 1);


        horizontalLayout_8->addWidget(frame_3);

        frame_4 = new QFrame(Hrenter_out);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setFrameShape(QFrame::Box);
        frame_4->setFrameShadow(QFrame::Raised);
        frame_4->setLineWidth(2);
        horizontalLayout_11 = new QHBoxLayout(frame_4);
        horizontalLayout_11->setSpacing(0);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(2);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(2, 2, 2, 2);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(2);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_4 = new QLabel(frame_4);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_2->addWidget(label_4);

        wave_type = new M_spinbox(frame_4);
        wave_type->setObjectName(QStringLiteral("wave_type"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(wave_type->sizePolicy().hasHeightForWidth());
        wave_type->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(wave_type);


        horizontalLayout_6->addLayout(verticalLayout_2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(2);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_6 = new QLabel(frame_4);
        label_6->setObjectName(QStringLiteral("label_6"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);

        verticalLayout_4->addWidget(label_6);

        ratio = new QDoubleSpinBox(frame_4);
        ratio->setObjectName(QStringLiteral("ratio"));
        sizePolicy.setHeightForWidth(ratio->sizePolicy().hasHeightForWidth());
        ratio->setSizePolicy(sizePolicy);
        ratio->setWrapping(false);
        ratio->setMaximum(999.99);

        verticalLayout_4->addWidget(ratio);


        horizontalLayout_6->addLayout(verticalLayout_4);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setSpacing(2);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        label_25 = new QLabel(frame_4);
        label_25->setObjectName(QStringLiteral("label_25"));

        verticalLayout_12->addWidget(label_25);

        tig_type = new M_spinbox(frame_4);
        tig_type->setObjectName(QStringLiteral("tig_type"));
        sizePolicy.setHeightForWidth(tig_type->sizePolicy().hasHeightForWidth());
        tig_type->setSizePolicy(sizePolicy);
        tig_type->setWrapping(false);

        verticalLayout_12->addWidget(tig_type);


        horizontalLayout_6->addLayout(verticalLayout_12);

        horizontalLayout_6->setStretch(0, 1);
        horizontalLayout_6->setStretch(1, 1);

        verticalLayout_9->addLayout(horizontalLayout_6);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(2);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_5 = new QLabel(frame_4);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_3->addWidget(label_5);

        base_value = new QDoubleSpinBox(frame_4);
        base_value->setObjectName(QStringLiteral("base_value"));
        sizePolicy.setHeightForWidth(base_value->sizePolicy().hasHeightForWidth());
        base_value->setSizePolicy(sizePolicy);
        base_value->setWrapping(true);
        base_value->setMaximum(999.99);
        base_value->setValue(50);

        verticalLayout_3->addWidget(base_value);


        horizontalLayout_10->addLayout(verticalLayout_3);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setSpacing(2);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        label_24 = new QLabel(frame_4);
        label_24->setObjectName(QStringLiteral("label_24"));

        verticalLayout_11->addWidget(label_24);

        base_phase = new QDoubleSpinBox(frame_4);
        base_phase->setObjectName(QStringLiteral("base_phase"));
        sizePolicy.setHeightForWidth(base_phase->sizePolicy().hasHeightForWidth());
        base_phase->setSizePolicy(sizePolicy);
        base_phase->setWrapping(true);
        base_phase->setMinimum(-360);
        base_phase->setMaximum(360);
        base_phase->setValue(0);

        verticalLayout_11->addWidget(base_phase);


        horizontalLayout_10->addLayout(verticalLayout_11);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(2);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_7 = new QLabel(frame_4);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout_5->addWidget(label_7);

        freq = new QDoubleSpinBox(frame_4);
        freq->setObjectName(QStringLiteral("freq"));
        sizePolicy.setHeightForWidth(freq->sizePolicy().hasHeightForWidth());
        freq->setSizePolicy(sizePolicy);
        freq->setWrapping(false);
        freq->setMaximum(999.99);
        freq->setValue(50);

        verticalLayout_5->addWidget(freq);


        horizontalLayout_10->addLayout(verticalLayout_5);

        horizontalLayout_10->setStretch(0, 1);
        horizontalLayout_10->setStretch(1, 1);
        horizontalLayout_10->setStretch(2, 1);

        verticalLayout_9->addLayout(horizontalLayout_10);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_26 = new QLabel(frame_4);
        label_26->setObjectName(QStringLiteral("label_26"));

        horizontalLayout_4->addWidget(label_26);

        label_8 = new QLabel(frame_4);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_4->addWidget(label_8);

        label_16 = new QLabel(frame_4);
        label_16->setObjectName(QStringLiteral("label_16"));

        horizontalLayout_4->addWidget(label_16);

        label_11 = new QLabel(frame_4);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_4->addWidget(label_11);

        label_17 = new QLabel(frame_4);
        label_17->setObjectName(QStringLiteral("label_17"));

        horizontalLayout_4->addWidget(label_17);

        label_9 = new QLabel(frame_4);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_4->addWidget(label_9);

        label_18 = new QLabel(frame_4);
        label_18->setObjectName(QStringLiteral("label_18"));

        horizontalLayout_4->addWidget(label_18);

        label_12 = new QLabel(frame_4);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_4->addWidget(label_12);

        label_19 = new QLabel(frame_4);
        label_19->setObjectName(QStringLiteral("label_19"));

        horizontalLayout_4->addWidget(label_19);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        all = new QCheckBox(frame_4);
        all->setObjectName(QStringLiteral("all"));
        all->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_5->addWidget(all);

        ua = new QCheckBox(frame_4);
        ua->setObjectName(QStringLiteral("ua"));
        ua->setLayoutDirection(Qt::LeftToRight);
        ua->setChecked(true);

        horizontalLayout_5->addWidget(ua);

        ia = new QCheckBox(frame_4);
        ia->setObjectName(QStringLiteral("ia"));
        ia->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_5->addWidget(ia);

        ub = new QCheckBox(frame_4);
        ub->setObjectName(QStringLiteral("ub"));
        ub->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_5->addWidget(ub);

        ib = new QCheckBox(frame_4);
        ib->setObjectName(QStringLiteral("ib"));
        ib->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_5->addWidget(ib);

        uc = new QCheckBox(frame_4);
        uc->setObjectName(QStringLiteral("uc"));
        uc->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_5->addWidget(uc);

        ic = new QCheckBox(frame_4);
        ic->setObjectName(QStringLiteral("ic"));
        ic->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_5->addWidget(ic);

        ud = new QCheckBox(frame_4);
        ud->setObjectName(QStringLiteral("ud"));
        ud->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_5->addWidget(ud);

        id = new QCheckBox(frame_4);
        id->setObjectName(QStringLiteral("id"));
        id->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_5->addWidget(id);


        verticalLayout->addLayout(horizontalLayout_5);


        verticalLayout_9->addLayout(verticalLayout);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(2);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        label_10 = new QLabel(frame_4);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_12->addWidget(label_10);

        label_20 = new QLabel(frame_4);
        label_20->setObjectName(QStringLiteral("label_20"));

        horizontalLayout_12->addWidget(label_20);

        label_15 = new QLabel(frame_4);
        label_15->setObjectName(QStringLiteral("label_15"));

        horizontalLayout_12->addWidget(label_15);

        label_21 = new QLabel(frame_4);
        label_21->setObjectName(QStringLiteral("label_21"));

        horizontalLayout_12->addWidget(label_21);

        label_14 = new QLabel(frame_4);
        label_14->setObjectName(QStringLiteral("label_14"));

        horizontalLayout_12->addWidget(label_14);

        label_22 = new QLabel(frame_4);
        label_22->setObjectName(QStringLiteral("label_22"));

        horizontalLayout_12->addWidget(label_22);

        label_13 = new QLabel(frame_4);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout_12->addWidget(label_13);

        label_23 = new QLabel(frame_4);
        label_23->setObjectName(QStringLiteral("label_23"));

        horizontalLayout_12->addWidget(label_23);


        verticalLayout_10->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        ua1 = new QCheckBox(frame_4);
        ua1->setObjectName(QStringLiteral("ua1"));
        ua1->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_13->addWidget(ua1);

        ia1 = new QCheckBox(frame_4);
        ia1->setObjectName(QStringLiteral("ia1"));
        ia1->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_13->addWidget(ia1);

        ub1 = new QCheckBox(frame_4);
        ub1->setObjectName(QStringLiteral("ub1"));
        ub1->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_13->addWidget(ub1);

        ib1 = new QCheckBox(frame_4);
        ib1->setObjectName(QStringLiteral("ib1"));
        ib1->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_13->addWidget(ib1);

        uc1 = new QCheckBox(frame_4);
        uc1->setObjectName(QStringLiteral("uc1"));
        uc1->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_13->addWidget(uc1);

        ic1 = new QCheckBox(frame_4);
        ic1->setObjectName(QStringLiteral("ic1"));
        ic1->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_13->addWidget(ic1);

        ud1 = new QCheckBox(frame_4);
        ud1->setObjectName(QStringLiteral("ud1"));
        ud1->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_13->addWidget(ud1);

        id1 = new QCheckBox(frame_4);
        id1->setObjectName(QStringLiteral("id1"));
        id1->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_13->addWidget(id1);


        verticalLayout_10->addLayout(horizontalLayout_13);


        verticalLayout_9->addLayout(verticalLayout_10);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(2);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(2, 2, 2, 2);
        hrenter_start = new QPushButton(frame_4);
        hrenter_start->setObjectName(QStringLiteral("hrenter_start"));
        sizePolicy.setHeightForWidth(hrenter_start->sizePolicy().hasHeightForWidth());
        hrenter_start->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(hrenter_start, 0, 1, 1, 1);

        base_stop = new QPushButton(frame_4);
        base_stop->setObjectName(QStringLiteral("base_stop"));
        sizePolicy.setHeightForWidth(base_stop->sizePolicy().hasHeightForWidth());
        base_stop->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(base_stop, 1, 0, 1, 1);

        base_start = new QPushButton(frame_4);
        base_start->setObjectName(QStringLiteral("base_start"));
        sizePolicy.setHeightForWidth(base_start->sizePolicy().hasHeightForWidth());
        base_start->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(base_start, 0, 0, 1, 1);

        hrenter_stop = new QPushButton(frame_4);
        hrenter_stop->setObjectName(QStringLiteral("hrenter_stop"));
        sizePolicy.setHeightForWidth(hrenter_stop->sizePolicy().hasHeightForWidth());
        hrenter_stop->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(hrenter_stop, 1, 1, 1, 1);


        verticalLayout_9->addLayout(gridLayout_3);


        horizontalLayout_11->addLayout(verticalLayout_9);

        frame_5 = new QFrame(frame_4);
        frame_5->setObjectName(QStringLiteral("frame_5"));
        frame_5->setFrameShape(QFrame::VLine);
        frame_5->setFrameShadow(QFrame::Sunken);
        frame_5->setLineWidth(2);

        horizontalLayout_11->addWidget(frame_5);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(2);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(2, 2, 2, -1);
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(2);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(2, 2, 2, 2);
        write_hrenter_data = new QPushButton(frame_4);
        write_hrenter_data->setObjectName(QStringLiteral("write_hrenter_data"));
        sizePolicy.setHeightForWidth(write_hrenter_data->sizePolicy().hasHeightForWidth());
        write_hrenter_data->setSizePolicy(sizePolicy);

        verticalLayout_6->addWidget(write_hrenter_data);

        hrenter_all_start = new QPushButton(frame_4);
        hrenter_all_start->setObjectName(QStringLiteral("hrenter_all_start"));
        sizePolicy.setHeightForWidth(hrenter_all_start->sizePolicy().hasHeightForWidth());
        hrenter_all_start->setSizePolicy(sizePolicy);

        verticalLayout_6->addWidget(hrenter_all_start);

        base_all_start = new QPushButton(frame_4);
        base_all_start->setObjectName(QStringLiteral("base_all_start"));
        sizePolicy.setHeightForWidth(base_all_start->sizePolicy().hasHeightForWidth());
        base_all_start->setSizePolicy(sizePolicy);

        verticalLayout_6->addWidget(base_all_start);

        all_stop = new QPushButton(frame_4);
        all_stop->setObjectName(QStringLiteral("all_stop"));
        sizePolicy.setHeightForWidth(all_stop->sizePolicy().hasHeightForWidth());
        all_stop->setSizePolicy(sizePolicy);

        verticalLayout_6->addWidget(all_stop);

        verticalLayout_6->setStretch(0, 1);
        verticalLayout_6->setStretch(1, 1);
        verticalLayout_6->setStretch(2, 1);
        verticalLayout_6->setStretch(3, 1);

        verticalLayout_7->addLayout(verticalLayout_6);


        horizontalLayout_11->addLayout(verticalLayout_7);

        horizontalLayout_11->setStretch(0, 3);
        horizontalLayout_11->setStretch(2, 1);

        horizontalLayout_8->addWidget(frame_4);

        horizontalLayout_8->setStretch(0, 1);
        horizontalLayout_8->setStretch(1, 1);

        verticalLayout_8->addLayout(horizontalLayout_8);

        verticalLayout_8->setStretch(1, 1);
        verticalLayout_8->setStretch(2, 1);
        verticalLayout_8->setStretch(4, 2);

        gridLayout_5->addLayout(verticalLayout_8, 0, 0, 1, 1);


        retranslateUi(Hrenter_out);

        QMetaObject::connectSlotsByName(Hrenter_out);
    } // setupUi

    void retranslateUi(QWidget *Hrenter_out)
    {
        Hrenter_out->setWindowTitle(QApplication::translate("Hrenter_out", "Form", 0));
        ua_state->setText(QApplication::translate("Hrenter_out", "UA", 0));
        ub_state->setText(QApplication::translate("Hrenter_out", "UB", 0));
        uc_state->setText(QApplication::translate("Hrenter_out", "UC", 0));
        ia_state->setText(QApplication::translate("Hrenter_out", "IA", 0));
        ib_state->setText(QApplication::translate("Hrenter_out", "IB", 0));
        ic_state->setText(QApplication::translate("Hrenter_out", "IC", 0));
        state1->setText(QApplication::translate("Hrenter_out", "\346\234\252\345\220\257\345\212\250", 0));
        state3->setText(QApplication::translate("Hrenter_out", "\345\267\262\345\220\257\345\212\250", 0));
        clear_hrenter_data->setText(QApplication::translate("Hrenter_out", "\346\270\205\351\233\266\350\260\220\346\263\242\346\225\260\346\215\256", 0));
        pipe_type->clear();
        pipe_type->insertItems(0, QStringList()
         << QApplication::translate("Hrenter_out", "\350\256\276\347\275\256Ua", 0)
         << QApplication::translate("Hrenter_out", "\350\256\276\347\275\256Ia", 0)
         << QApplication::translate("Hrenter_out", "\350\256\276\347\275\256Ub", 0)
         << QApplication::translate("Hrenter_out", "\350\256\276\347\275\256Ib", 0)
         << QApplication::translate("Hrenter_out", "\350\256\276\347\275\256Uc", 0)
         << QApplication::translate("Hrenter_out", "\350\256\276\347\275\256Ic", 0)
        );
        preview_hrenter->setText(QApplication::translate("Hrenter_out", "\350\260\220\346\263\242\351\242\204\350\247\210", 0));
        label->setText(QApplication::translate("Hrenter_out", "THD", 0));
        label_2->setText(QApplication::translate("Hrenter_out", "%", 0));
        label_3->setText(QApplication::translate("Hrenter_out", "RMS", 0));
        QTableWidgetItem *___qtablewidgetitem = hrenter_data->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Hrenter_out", "\350\260\220\346\263\242\345\220\253\346\234\211\347\216\207(%)", 0));
        QTableWidgetItem *___qtablewidgetitem1 = hrenter_data->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Hrenter_out", "\350\260\220\346\263\242\345\220\253\351\207\217", 0));
        QTableWidgetItem *___qtablewidgetitem2 = hrenter_data->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Hrenter_out", "\350\260\220\346\263\242\347\233\270\344\275\215", 0));
        label_4->setText(QApplication::translate("Hrenter_out", "\346\263\242\345\275\242\347\261\273\345\236\213", 0));
        label_6->setText(QApplication::translate("Hrenter_out", "\347\233\264\346\265\201\345\201\217\347\247\273(%)", 0));
        label_25->setText(QApplication::translate("Hrenter_out", "\350\247\246\345\217\221\346\250\241\345\274\217", 0));
        label_5->setText(QApplication::translate("Hrenter_out", "\345\237\272\346\263\242\346\234\211\346\225\210\345\200\274", 0));
        label_24->setText(QApplication::translate("Hrenter_out", "\345\237\272\346\263\242\347\233\270\344\275\215", 0));
        label_7->setText(QApplication::translate("Hrenter_out", "\345\237\272\346\263\242\351\242\221\347\216\207(Hz)", 0));
        label_26->setText(QApplication::translate("Hrenter_out", "\345\205\250\351\200\211", 0));
        label_8->setText(QApplication::translate("Hrenter_out", "Ua", 0));
        label_16->setText(QApplication::translate("Hrenter_out", "Ia", 0));
        label_11->setText(QApplication::translate("Hrenter_out", "Ub", 0));
        label_17->setText(QApplication::translate("Hrenter_out", "Ib", 0));
        label_9->setText(QApplication::translate("Hrenter_out", "Uc", 0));
        label_18->setText(QApplication::translate("Hrenter_out", "Ic", 0));
        label_12->setText(QApplication::translate("Hrenter_out", "Ud", 0));
        label_19->setText(QApplication::translate("Hrenter_out", "Id", 0));
        all->setText(QString());
        ua->setText(QString());
        ia->setText(QString());
        ub->setText(QString());
        ib->setText(QString());
        uc->setText(QString());
        ic->setText(QString());
        ud->setText(QString());
        id->setText(QString());
        label_10->setText(QApplication::translate("Hrenter_out", "Ua1", 0));
        label_20->setText(QApplication::translate("Hrenter_out", "Ia1", 0));
        label_15->setText(QApplication::translate("Hrenter_out", "Ub1", 0));
        label_21->setText(QApplication::translate("Hrenter_out", "Ib1", 0));
        label_14->setText(QApplication::translate("Hrenter_out", "Uc1", 0));
        label_22->setText(QApplication::translate("Hrenter_out", "Ic1", 0));
        label_13->setText(QApplication::translate("Hrenter_out", "Ud1", 0));
        label_23->setText(QApplication::translate("Hrenter_out", "Id1", 0));
        ua1->setText(QString());
        ia1->setText(QString());
        ub1->setText(QString());
        ib1->setText(QString());
        uc1->setText(QString());
        ic1->setText(QString());
        ud1->setText(QString());
        id1->setText(QString());
        hrenter_start->setText(QApplication::translate("Hrenter_out", "\350\260\220\346\263\242\345\220\257\345\212\250", 0));
        base_stop->setText(QApplication::translate("Hrenter_out", "\345\237\272\346\263\242\345\201\234\346\255\242", 0));
        base_start->setText(QApplication::translate("Hrenter_out", "\345\237\272\346\263\242\345\220\257\345\212\250", 0));
        hrenter_stop->setText(QApplication::translate("Hrenter_out", "\350\260\220\346\263\242\345\201\234\346\255\242", 0));
        write_hrenter_data->setText(QApplication::translate("Hrenter_out", "\345\206\231\350\260\220\346\263\242\346\225\260\346\215\256", 0));
        hrenter_all_start->setText(QApplication::translate("Hrenter_out", "\350\260\220\346\263\242\n"
"\345\205\250\351\203\250\345\220\257\345\212\250", 0));
        base_all_start->setText(QApplication::translate("Hrenter_out", "\345\237\272\346\263\242\n"
"\345\205\250\351\203\250\345\220\257\345\212\250", 0));
        all_stop->setText(QApplication::translate("Hrenter_out", "\345\205\250\351\203\250\345\201\234\346\255\242", 0));
    } // retranslateUi

};

namespace Ui {
    class Hrenter_out: public Ui_Hrenter_out {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HRENTER_OUT_H
