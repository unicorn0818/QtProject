/********************************************************************************
** Form generated from reading UI file 'active_wave.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACTIVE_WAVE_H
#define UI_ACTIVE_WAVE_H

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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <customplothasroll.h>
#include "m_checkbox.h"
#include "m_spinbox.h"

QT_BEGIN_NAMESPACE

class Ui_active_wave
{
public:
    QGridLayout *gridLayout_6;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_4;
    m_checkbox *ua_state;
    m_checkbox *ub_state;
    m_checkbox *uc_state;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLineEdit *rms;
    QHBoxLayout *horizontalLayout_10;
    m_checkbox *ia_state;
    m_checkbox *ib_state;
    m_checkbox *ic_state;
    QHBoxLayout *horizontalLayout_7;
    m_checkbox *state1;
    m_checkbox *state2;
    m_checkbox *state3;
    QSpacerItem *horizontalSpacer_5;
    CustomPlotHasRoll *show_wave;
    QFrame *frame;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *u_pipe_state;
    QTableView *formula_table;
    QPushButton *save_formula;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_10;
    QCheckBox *set_ua;
    QCheckBox *set_ub;
    QCheckBox *set_uc;
    QCheckBox *set_ia;
    QCheckBox *set_ib;
    QCheckBox *set_ic;
    QPushButton *out_all_wave;
    QPushButton *out_now_wave;
    QPushButton *priview_all_wave;
    QPushButton *open_formula;
    QPushButton *save_wave;
    QPushButton *open_wave;
    QPushButton *priview_wave;
    QHBoxLayout *horizontalLayout;
    QFrame *frame_2;
    QLabel *label_7;
    M_spinbox *formula;
    QLabel *label_8;
    M_spinbox *tigger_type;
    QFrame *frame_5;
    QGridLayout *gridLayout_2;
    QTableView *value_view;
    QFrame *frame_3;
    QGridLayout *gridLayout_4;
    QLabel *label_5;
    QLabel *label_9;
    QSpinBox *out_count;
    QSpinBox *byte_length;
    QSpinBox *sampling;
    QLabel *label_4;
    QFrame *frame_4;
    QGridLayout *gridLayout;
    QPushButton *start_out;
    QPushButton *all_start;
    QPushButton *stop_out;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_11;
    QCheckBox *start_ua;
    QCheckBox *start_ub;
    QCheckBox *start_uc;
    QCheckBox *start_ia;
    QCheckBox *start_ib;
    QCheckBox *start_ic;
    QPushButton *all_stop;
    QButtonGroup *buttonGroup_2;
    QButtonGroup *buttonGroup;

    void setupUi(QWidget *active_wave)
    {
        if (active_wave->objectName().isEmpty())
            active_wave->setObjectName(QStringLiteral("active_wave"));
        active_wave->resize(750, 500);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(active_wave->sizePolicy().hasHeightForWidth());
        active_wave->setSizePolicy(sizePolicy);
        gridLayout_6 = new QGridLayout(active_wave);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(2);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer_3 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(10);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(2);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        ua_state = new m_checkbox(active_wave);
        ua_state->setObjectName(QStringLiteral("ua_state"));
        sizePolicy.setHeightForWidth(ua_state->sizePolicy().hasHeightForWidth());
        ua_state->setSizePolicy(sizePolicy);
        ua_state->setCheckable(false);

        horizontalLayout_4->addWidget(ua_state);

        ub_state = new m_checkbox(active_wave);
        ub_state->setObjectName(QStringLiteral("ub_state"));
        sizePolicy.setHeightForWidth(ub_state->sizePolicy().hasHeightForWidth());
        ub_state->setSizePolicy(sizePolicy);
        ub_state->setCheckable(false);

        horizontalLayout_4->addWidget(ub_state);

        uc_state = new m_checkbox(active_wave);
        uc_state->setObjectName(QStringLiteral("uc_state"));
        sizePolicy.setHeightForWidth(uc_state->sizePolicy().hasHeightForWidth());
        uc_state->setSizePolicy(sizePolicy);
        uc_state->setCheckable(false);

        horizontalLayout_4->addWidget(uc_state);


        horizontalLayout_5->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(2);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label = new QLabel(active_wave);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(label);

        rms = new QLineEdit(active_wave);
        rms->setObjectName(QStringLiteral("rms"));
        sizePolicy.setHeightForWidth(rms->sizePolicy().hasHeightForWidth());
        rms->setSizePolicy(sizePolicy);
        rms->setMinimumSize(QSize(20, 0));
        QFont font;
        font.setPointSize(6);
        rms->setFont(font);
        rms->setReadOnly(true);

        horizontalLayout_3->addWidget(rms);


        horizontalLayout_5->addLayout(horizontalLayout_3);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(2);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        ia_state = new m_checkbox(active_wave);
        ia_state->setObjectName(QStringLiteral("ia_state"));
        sizePolicy.setHeightForWidth(ia_state->sizePolicy().hasHeightForWidth());
        ia_state->setSizePolicy(sizePolicy);
        ia_state->setCheckable(false);

        horizontalLayout_10->addWidget(ia_state);

        ib_state = new m_checkbox(active_wave);
        ib_state->setObjectName(QStringLiteral("ib_state"));
        sizePolicy.setHeightForWidth(ib_state->sizePolicy().hasHeightForWidth());
        ib_state->setSizePolicy(sizePolicy);
        ib_state->setCheckable(false);

        horizontalLayout_10->addWidget(ib_state);

        ic_state = new m_checkbox(active_wave);
        ic_state->setObjectName(QStringLiteral("ic_state"));
        sizePolicy.setHeightForWidth(ic_state->sizePolicy().hasHeightForWidth());
        ic_state->setSizePolicy(sizePolicy);
        ic_state->setCheckable(false);

        horizontalLayout_10->addWidget(ic_state);


        horizontalLayout_5->addLayout(horizontalLayout_10);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(2);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        state1 = new m_checkbox(active_wave);
        state1->setObjectName(QStringLiteral("state1"));
        sizePolicy.setHeightForWidth(state1->sizePolicy().hasHeightForWidth());
        state1->setSizePolicy(sizePolicy);
        state1->setCheckable(false);

        horizontalLayout_7->addWidget(state1);

        state2 = new m_checkbox(active_wave);
        state2->setObjectName(QStringLiteral("state2"));
        sizePolicy.setHeightForWidth(state2->sizePolicy().hasHeightForWidth());
        state2->setSizePolicy(sizePolicy);
        state2->setCheckable(false);

        horizontalLayout_7->addWidget(state2);

        state3 = new m_checkbox(active_wave);
        state3->setObjectName(QStringLiteral("state3"));
        sizePolicy.setHeightForWidth(state3->sizePolicy().hasHeightForWidth());
        state3->setSizePolicy(sizePolicy);
        state3->setCheckable(false);

        horizontalLayout_7->addWidget(state3);


        horizontalLayout_5->addLayout(horizontalLayout_7);


        horizontalLayout_6->addLayout(horizontalLayout_5);

        horizontalSpacer_5 = new QSpacerItem(88, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_5);

        horizontalLayout_6->setStretch(0, 1);
        horizontalLayout_6->setStretch(2, 1);

        verticalLayout_2->addLayout(horizontalLayout_6);

        show_wave = new CustomPlotHasRoll(active_wave);
        show_wave->setObjectName(QStringLiteral("show_wave"));
        sizePolicy.setHeightForWidth(show_wave->sizePolicy().hasHeightForWidth());
        show_wave->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(show_wave);

        verticalLayout_2->setStretch(1, 1);

        verticalLayout_3->addLayout(verticalLayout_2);

        frame = new QFrame(active_wave);
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
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(label_2);

        u_pipe_state = new QLabel(frame);
        u_pipe_state->setObjectName(QStringLiteral("u_pipe_state"));
        u_pipe_state->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(u_pipe_state);

        horizontalLayout_2->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout_2);

        formula_table = new QTableView(frame);
        formula_table->setObjectName(QStringLiteral("formula_table"));
        sizePolicy.setHeightForWidth(formula_table->sizePolicy().hasHeightForWidth());
        formula_table->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(formula_table);

        verticalLayout->setStretch(1, 1);

        gridLayout_3->addLayout(verticalLayout, 0, 0, 6, 1);

        save_formula = new QPushButton(frame);
        save_formula->setObjectName(QStringLiteral("save_formula"));
        sizePolicy.setHeightForWidth(save_formula->sizePolicy().hasHeightForWidth());
        save_formula->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(save_formula, 1, 1, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_10 = new QLabel(frame);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_8->addWidget(label_10);

        set_ua = new QCheckBox(frame);
        buttonGroup = new QButtonGroup(active_wave);
        buttonGroup->setObjectName(QStringLiteral("buttonGroup"));
        buttonGroup->addButton(set_ua);
        set_ua->setObjectName(QStringLiteral("set_ua"));
        QFont font1;
        font1.setPointSize(12);
        set_ua->setFont(font1);
        set_ua->setChecked(true);

        horizontalLayout_8->addWidget(set_ua);

        set_ub = new QCheckBox(frame);
        buttonGroup->addButton(set_ub);
        set_ub->setObjectName(QStringLiteral("set_ub"));
        set_ub->setFont(font1);

        horizontalLayout_8->addWidget(set_ub);

        set_uc = new QCheckBox(frame);
        buttonGroup->addButton(set_uc);
        set_uc->setObjectName(QStringLiteral("set_uc"));
        set_uc->setFont(font1);

        horizontalLayout_8->addWidget(set_uc);

        set_ia = new QCheckBox(frame);
        buttonGroup->addButton(set_ia);
        set_ia->setObjectName(QStringLiteral("set_ia"));
        set_ia->setFont(font1);
        set_ia->setChecked(false);

        horizontalLayout_8->addWidget(set_ia);

        set_ib = new QCheckBox(frame);
        buttonGroup->addButton(set_ib);
        set_ib->setObjectName(QStringLiteral("set_ib"));
        set_ib->setFont(font1);
        set_ib->setChecked(false);

        horizontalLayout_8->addWidget(set_ib);

        set_ic = new QCheckBox(frame);
        buttonGroup->addButton(set_ic);
        set_ic->setObjectName(QStringLiteral("set_ic"));
        set_ic->setFont(font1);
        set_ic->setChecked(false);

        horizontalLayout_8->addWidget(set_ic);


        gridLayout_3->addLayout(horizontalLayout_8, 0, 1, 1, 2);

        out_all_wave = new QPushButton(frame);
        out_all_wave->setObjectName(QStringLiteral("out_all_wave"));
        sizePolicy.setHeightForWidth(out_all_wave->sizePolicy().hasHeightForWidth());
        out_all_wave->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(out_all_wave, 5, 2, 1, 1);

        out_now_wave = new QPushButton(frame);
        out_now_wave->setObjectName(QStringLiteral("out_now_wave"));
        sizePolicy.setHeightForWidth(out_now_wave->sizePolicy().hasHeightForWidth());
        out_now_wave->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(out_now_wave, 3, 2, 1, 1);

        priview_all_wave = new QPushButton(frame);
        priview_all_wave->setObjectName(QStringLiteral("priview_all_wave"));
        sizePolicy.setHeightForWidth(priview_all_wave->sizePolicy().hasHeightForWidth());
        priview_all_wave->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(priview_all_wave, 5, 1, 1, 1);

        open_formula = new QPushButton(frame);
        open_formula->setObjectName(QStringLiteral("open_formula"));
        sizePolicy.setHeightForWidth(open_formula->sizePolicy().hasHeightForWidth());
        open_formula->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(open_formula, 1, 2, 1, 1);

        save_wave = new QPushButton(frame);
        save_wave->setObjectName(QStringLiteral("save_wave"));
        sizePolicy.setHeightForWidth(save_wave->sizePolicy().hasHeightForWidth());
        save_wave->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(save_wave, 2, 1, 1, 1);

        open_wave = new QPushButton(frame);
        open_wave->setObjectName(QStringLiteral("open_wave"));
        sizePolicy.setHeightForWidth(open_wave->sizePolicy().hasHeightForWidth());
        open_wave->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(open_wave, 2, 2, 1, 1);

        priview_wave = new QPushButton(frame);
        priview_wave->setObjectName(QStringLiteral("priview_wave"));
        sizePolicy.setHeightForWidth(priview_wave->sizePolicy().hasHeightForWidth());
        priview_wave->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(priview_wave, 3, 1, 1, 1);

        gridLayout_3->setColumnStretch(0, 3);

        verticalLayout_3->addWidget(frame);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        frame_2 = new QFrame(active_wave);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        sizePolicy.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy);
        frame_2->setFrameShape(QFrame::Box);
        frame_2->setFrameShadow(QFrame::Raised);
        frame_2->setLineWidth(2);
        label_7 = new QLabel(frame_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(6, 6, 48, 16));
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);
        formula = new M_spinbox(frame_2);
        formula->setObjectName(QStringLiteral("formula"));
        formula->setGeometry(QRect(63, 6, 42, 20));
        sizePolicy.setHeightForWidth(formula->sizePolicy().hasHeightForWidth());
        formula->setSizePolicy(sizePolicy);
        label_8 = new QLabel(frame_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(6, 34, 48, 16));
        sizePolicy.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy);
        tigger_type = new M_spinbox(frame_2);
        tigger_type->setObjectName(QStringLiteral("tigger_type"));
        tigger_type->setGeometry(QRect(63, 34, 42, 20));
        sizePolicy.setHeightForWidth(tigger_type->sizePolicy().hasHeightForWidth());
        tigger_type->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(frame_2);

        frame_5 = new QFrame(active_wave);
        frame_5->setObjectName(QStringLiteral("frame_5"));
        sizePolicy.setHeightForWidth(frame_5->sizePolicy().hasHeightForWidth());
        frame_5->setSizePolicy(sizePolicy);
        frame_5->setFrameShape(QFrame::Box);
        frame_5->setFrameShadow(QFrame::Raised);
        frame_5->setLineWidth(2);
        gridLayout_2 = new QGridLayout(frame_5);
        gridLayout_2->setSpacing(2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(2, 2, 2, 2);
        value_view = new QTableView(frame_5);
        value_view->setObjectName(QStringLiteral("value_view"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Ignored);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(value_view->sizePolicy().hasHeightForWidth());
        value_view->setSizePolicy(sizePolicy2);
        value_view->setMinimumSize(QSize(400, 0));

        gridLayout_2->addWidget(value_view, 0, 0, 1, 1);


        horizontalLayout->addWidget(frame_5);

        frame_3 = new QFrame(active_wave);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(frame_3->sizePolicy().hasHeightForWidth());
        frame_3->setSizePolicy(sizePolicy3);
        frame_3->setFrameShape(QFrame::Box);
        frame_3->setFrameShadow(QFrame::Raised);
        frame_3->setLineWidth(2);
        gridLayout_4 = new QGridLayout(frame_3);
        gridLayout_4->setSpacing(2);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(2, 2, 2, 2);
        label_5 = new QLabel(frame_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);

        gridLayout_4->addWidget(label_5, 1, 0, 1, 1);

        label_9 = new QLabel(frame_3);
        label_9->setObjectName(QStringLiteral("label_9"));
        sizePolicy.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy);

        gridLayout_4->addWidget(label_9, 2, 0, 1, 1);

        out_count = new QSpinBox(frame_3);
        out_count->setObjectName(QStringLiteral("out_count"));
        sizePolicy.setHeightForWidth(out_count->sizePolicy().hasHeightForWidth());
        out_count->setSizePolicy(sizePolicy);
        out_count->setWrapping(true);
        out_count->setMinimum(0);
        out_count->setMaximum(254);
        out_count->setValue(0);

        gridLayout_4->addWidget(out_count, 2, 1, 1, 1);

        byte_length = new QSpinBox(frame_3);
        byte_length->setObjectName(QStringLiteral("byte_length"));
        sizePolicy.setHeightForWidth(byte_length->sizePolicy().hasHeightForWidth());
        byte_length->setSizePolicy(sizePolicy);
        byte_length->setMaximum(99999999);
        byte_length->setValue(5000);

        gridLayout_4->addWidget(byte_length, 1, 1, 1, 1);

        sampling = new QSpinBox(frame_3);
        sampling->setObjectName(QStringLiteral("sampling"));
        sizePolicy.setHeightForWidth(sampling->sizePolicy().hasHeightForWidth());
        sampling->setSizePolicy(sizePolicy);
        sampling->setMaximum(999999999);
        sampling->setValue(200);

        gridLayout_4->addWidget(sampling, 0, 1, 1, 1);

        label_4 = new QLabel(frame_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);

        gridLayout_4->addWidget(label_4, 0, 0, 1, 1);


        horizontalLayout->addWidget(frame_3);

        frame_4 = new QFrame(active_wave);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        sizePolicy3.setHeightForWidth(frame_4->sizePolicy().hasHeightForWidth());
        frame_4->setSizePolicy(sizePolicy3);
        frame_4->setFrameShape(QFrame::Box);
        frame_4->setFrameShadow(QFrame::Raised);
        frame_4->setLineWidth(2);
        gridLayout = new QGridLayout(frame_4);
        gridLayout->setSpacing(2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(2, 2, 2, 2);
        start_out = new QPushButton(frame_4);
        start_out->setObjectName(QStringLiteral("start_out"));
        sizePolicy.setHeightForWidth(start_out->sizePolicy().hasHeightForWidth());
        start_out->setSizePolicy(sizePolicy);

        gridLayout->addWidget(start_out, 1, 0, 1, 1);

        all_start = new QPushButton(frame_4);
        all_start->setObjectName(QStringLiteral("all_start"));
        sizePolicy.setHeightForWidth(all_start->sizePolicy().hasHeightForWidth());
        all_start->setSizePolicy(sizePolicy);

        gridLayout->addWidget(all_start, 2, 0, 1, 1);

        stop_out = new QPushButton(frame_4);
        stop_out->setObjectName(QStringLiteral("stop_out"));
        sizePolicy.setHeightForWidth(stop_out->sizePolicy().hasHeightForWidth());
        stop_out->setSizePolicy(sizePolicy);

        gridLayout->addWidget(stop_out, 1, 1, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_11 = new QLabel(frame_4);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_9->addWidget(label_11);

        start_ua = new QCheckBox(frame_4);
        buttonGroup_2 = new QButtonGroup(active_wave);
        buttonGroup_2->setObjectName(QStringLiteral("buttonGroup_2"));
        buttonGroup_2->addButton(start_ua);
        start_ua->setObjectName(QStringLiteral("start_ua"));
        start_ua->setFont(font1);
        start_ua->setChecked(true);

        horizontalLayout_9->addWidget(start_ua);

        start_ub = new QCheckBox(frame_4);
        buttonGroup_2->addButton(start_ub);
        start_ub->setObjectName(QStringLiteral("start_ub"));
        start_ub->setFont(font1);

        horizontalLayout_9->addWidget(start_ub);

        start_uc = new QCheckBox(frame_4);
        buttonGroup_2->addButton(start_uc);
        start_uc->setObjectName(QStringLiteral("start_uc"));
        start_uc->setFont(font1);

        horizontalLayout_9->addWidget(start_uc);

        start_ia = new QCheckBox(frame_4);
        buttonGroup_2->addButton(start_ia);
        start_ia->setObjectName(QStringLiteral("start_ia"));
        start_ia->setFont(font1);
        start_ia->setChecked(false);

        horizontalLayout_9->addWidget(start_ia);

        start_ib = new QCheckBox(frame_4);
        buttonGroup_2->addButton(start_ib);
        start_ib->setObjectName(QStringLiteral("start_ib"));
        start_ib->setFont(font1);

        horizontalLayout_9->addWidget(start_ib);

        start_ic = new QCheckBox(frame_4);
        buttonGroup_2->addButton(start_ic);
        start_ic->setObjectName(QStringLiteral("start_ic"));
        start_ic->setFont(font1);

        horizontalLayout_9->addWidget(start_ic);


        gridLayout->addLayout(horizontalLayout_9, 0, 0, 1, 2);

        all_stop = new QPushButton(frame_4);
        all_stop->setObjectName(QStringLiteral("all_stop"));
        sizePolicy.setHeightForWidth(all_stop->sizePolicy().hasHeightForWidth());
        all_stop->setSizePolicy(sizePolicy);

        gridLayout->addWidget(all_stop, 2, 1, 1, 1);


        horizontalLayout->addWidget(frame_4);

        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(3, 1);

        verticalLayout_3->addLayout(horizontalLayout);

        verticalLayout_3->setStretch(0, 2);
        verticalLayout_3->setStretch(1, 2);
        verticalLayout_3->setStretch(2, 1);

        gridLayout_6->addLayout(verticalLayout_3, 0, 0, 1, 1);


        retranslateUi(active_wave);

        QMetaObject::connectSlotsByName(active_wave);
    } // setupUi

    void retranslateUi(QWidget *active_wave)
    {
        active_wave->setWindowTitle(QApplication::translate("active_wave", "Form", 0));
        ua_state->setText(QApplication::translate("active_wave", "UA", 0));
        ub_state->setText(QApplication::translate("active_wave", "UB", 0));
        uc_state->setText(QApplication::translate("active_wave", "UC", 0));
        label->setText(QApplication::translate("active_wave", "RMS", 0));
        ia_state->setText(QApplication::translate("active_wave", "IA", 0));
        ib_state->setText(QApplication::translate("active_wave", "IB", 0));
        ic_state->setText(QApplication::translate("active_wave", "IC", 0));
        state1->setText(QApplication::translate("active_wave", "\346\234\252\345\206\231\345\205\245", 0));
        state2->setText(QApplication::translate("active_wave", "\345\206\231\345\205\245", 0));
        state3->setText(QApplication::translate("active_wave", "\345\267\262\345\220\257\345\212\250", 0));
        label_2->setText(QApplication::translate("active_wave", "\351\200\232\351\201\223\357\274\232", 0));
        u_pipe_state->setText(QApplication::translate("active_wave", "UA", 0));
#ifndef QT_NO_TOOLTIP
        formula_table->setToolTip(QApplication::translate("active_wave", "\345\207\275\346\225\260\350\276\223\345\205\245\345\212\237\350\203\275\347\256\200\344\273\213\357\274\232\n"
"\346\224\257\346\214\201\345\212\240+\343\200\201\345\207\217-\343\200\201\344\271\230*\343\200\201\351\231\244/\343\200\201\346\213\254\345\217\267\345\217\252\346\224\257\346\214\201()\n"
"\346\224\257\346\214\201\344\270\213\345\210\227\346\225\260\345\255\246\345\207\275\346\225\260\357\274\210\346\263\250\357\274\232\344\270\211\350\247\222\345\207\275\346\225\260\344\270\272\345\274\247\345\272\246\345\210\266\357\274\214\345\214\272\345\210\206\345\244\247\345\260\217\345\206\231\357\274\211\n"
"cos(),sin(),tan()/tg(),cot()/ctg(),abs(),sign(),\n"
"sqrt(),ln(),sinh()/sh(),cosh()/ch(),tanh(),coth()\n"
"\346\224\257\346\214\201\345\270\270\346\225\260PI(\345\215\263\317\200), E\n"
"\346\214\207\346\225\260\347\224\250\357\274\232^,\345\246\202\357\274\232E^(Ti/0.5)\n"
"Ti\357\274\232\350\241\250\347\244\272\346\227\266\351\227\264\345\217\230\351\207\217\n"
"\347\244\272\344\276\213\357\274\232s"
                        "in(2*PI*50*Ti+60/180*PI)\n"
"\345\205\254\345\274\217\350\276\223\345\205\245\345\205\201\350\256\270\346\234\200\345\244\23250\346\235\241\345\205\254\345\274\217\347\273\204\345\220\210\n"
"\346\211\200\346\234\211\350\276\223\345\207\272\347\233\270\347\232\204\346\214\201\347\273\255\346\227\266\351\227\264\351\225\277\345\272\246\347\232\204\345\222\214\345\277\205\351\241\273\344\270\200\346\240\267\357\274\214\345\220\246\345\210\231\350\276\223\345\207\272\345\217\257\350\203\275\345\207\272\351\224\231\n"
"\343\200\202", 0));
#endif // QT_NO_TOOLTIP
        save_formula->setText(QApplication::translate("active_wave", "\344\277\235\345\255\230\345\205\254\345\274\217", 0));
        label_10->setText(QApplication::translate("active_wave", "\351\200\211\346\213\251\351\200\232\351\201\223\357\274\232", 0));
        set_ua->setText(QApplication::translate("active_wave", "UA", 0));
        set_ub->setText(QApplication::translate("active_wave", "UB", 0));
        set_uc->setText(QApplication::translate("active_wave", "UC", 0));
        set_ia->setText(QApplication::translate("active_wave", "IA", 0));
        set_ib->setText(QApplication::translate("active_wave", "IB", 0));
        set_ic->setText(QApplication::translate("active_wave", "IC", 0));
        out_all_wave->setText(QApplication::translate("active_wave", "\345\272\224\347\224\250\345\205\250\351\203\250\346\263\242\345\275\242", 0));
        out_now_wave->setText(QApplication::translate("active_wave", "\345\272\224\347\224\250\345\275\223\345\211\215\346\263\242\345\275\242", 0));
        priview_all_wave->setText(QApplication::translate("active_wave", "\347\224\237\346\210\220\345\205\250\351\203\250\346\263\242\345\275\242", 0));
        open_formula->setText(QApplication::translate("active_wave", "\346\211\223\345\274\200\345\205\254\345\274\217", 0));
        save_wave->setText(QApplication::translate("active_wave", "\344\277\235\345\255\230\345\275\223\345\211\215\346\263\242\345\275\242\n"
"\345\210\260\346\226\207\344\273\266\344\270\255", 0));
        open_wave->setText(QApplication::translate("active_wave", "\346\211\223\345\274\200\346\263\242\345\275\242\346\226\207\344\273\266", 0));
        priview_wave->setText(QApplication::translate("active_wave", "\347\224\237\346\210\220\345\275\223\345\211\215\346\263\242\345\275\242", 0));
        label_7->setText(QApplication::translate("active_wave", "\345\205\254\345\274\217\351\200\211\346\213\251", 0));
        label_8->setText(QApplication::translate("active_wave", "\350\247\246\345\217\221\346\250\241\345\274\217", 0));
        label_5->setText(QApplication::translate("active_wave", "\346\257\217\345\270\247\351\225\277\345\272\246", 0));
#ifndef QT_NO_TOOLTIP
        label_9->setToolTip(QApplication::translate("active_wave", "255\344\270\272\351\207\215\345\244\215\350\276\223\345\207\272", 0));
#endif // QT_NO_TOOLTIP
        label_9->setText(QApplication::translate("active_wave", "\350\276\223\345\207\272\346\254\241\346\225\260", 0));
        sampling->setSuffix(QApplication::translate("active_wave", "k", 0));
        label_4->setText(QApplication::translate("active_wave", "\351\207\207\346\240\267\347\216\207", 0));
        start_out->setText(QApplication::translate("active_wave", "\345\220\257\345\212\250\350\276\223\345\207\272", 0));
        all_start->setText(QApplication::translate("active_wave", "\345\205\250\351\203\250\345\220\257\345\212\250", 0));
        stop_out->setText(QApplication::translate("active_wave", "\345\201\234\346\255\242\350\276\223\345\207\272", 0));
        label_11->setText(QApplication::translate("active_wave", "\351\200\211\346\213\251\350\276\223\345\207\272\351\200\232\351\201\223\357\274\232", 0));
        start_ua->setText(QApplication::translate("active_wave", "UA", 0));
        start_ub->setText(QApplication::translate("active_wave", "UB", 0));
        start_uc->setText(QApplication::translate("active_wave", "UC", 0));
        start_ia->setText(QApplication::translate("active_wave", "IA", 0));
        start_ib->setText(QApplication::translate("active_wave", "IB", 0));
        start_ic->setText(QApplication::translate("active_wave", "IC", 0));
        all_stop->setText(QApplication::translate("active_wave", "\345\205\250\351\203\250\345\201\234\346\255\242", 0));
    } // retranslateUi

};

namespace Ui {
    class active_wave: public Ui_active_wave {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACTIVE_WAVE_H
