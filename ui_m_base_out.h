/********************************************************************************
** Form generated from reading UI file 'm_base_out.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_M_BASE_OUT_H
#define UI_M_BASE_OUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <customplothasroll.h>
#include "m_spinbox.h"

QT_BEGIN_NAMESPACE

class Ui_m_base_out
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer;
    QLabel *label_20;
    QFrame *line;
    QLabel *label_21;
    QFrame *line_2;
    QLabel *label_22;
    QFrame *line_3;
    QLabel *label_23;
    QFrame *line_7;
    QSpacerItem *horizontalSpacer_4;
    QGridLayout *gridLayout_2;
    QFrame *frame_4;
    QGridLayout *gridLayout_6;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *pushButton;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *pushButton_7;
    QPushButton *pushButton_6;
    QPushButton *pushButton_4;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QCheckBox *all_start;
    QCheckBox *u_i_all_start;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *ua_start;
    QCheckBox *ub_start;
    QCheckBox *uc_start;
    QCheckBox *ud_start;
    QHBoxLayout *horizontalLayout_5;
    QCheckBox *ia_start;
    QCheckBox *ib_start;
    QCheckBox *ic_start;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *start;
    QPushButton *stop;
    QFrame *frame_6;
    QGridLayout *gridLayout_10;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_8;
    QFrame *frame_3;
    QGridLayout *gridLayout_7;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QCheckBox *all_value;
    QCheckBox *ua_value;
    QCheckBox *ia_value;
    QCheckBox *ub_value;
    QCheckBox *ib_value;
    QCheckBox *uc_value;
    QCheckBox *ic_value;
    QCheckBox *ud_value;
    QGridLayout *gridLayout_3;
    QLabel *label;
    M_spinbox *wave_type;
    QLabel *label_2;
    QDoubleSpinBox *value;
    QLabel *label_3;
    QDoubleSpinBox *phase;
    QLabel *label_4;
    QDoubleSpinBox *ratio;
    QFrame *frame_5;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_8;
    QCheckBox *freq_set;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QDoubleSpinBox *a_b_freq;
    QLabel *label_7;
    QDoubleSpinBox *c_freq_2;
    QLabel *label_6;
    QDoubleSpinBox *c_freq;
    QLabel *label_9;
    QDoubleSpinBox *c_freq_3;
    QSpacerItem *verticalSpacer_3;
    QWidget *tab_2;
    QGridLayout *gridLayout_9;
    QTableView *tableView;
    QFrame *frame;
    QGridLayout *gridLayout_4;
    CustomPlotHasRoll *U_map;
    QFrame *frame_2;
    QGridLayout *gridLayout_5;
    CustomPlotHasRoll *I_map;

    void setupUi(QWidget *m_base_out)
    {
        if (m_base_out->objectName().isEmpty())
            m_base_out->setObjectName(QStringLiteral("m_base_out"));
        m_base_out->resize(879, 500);
        gridLayout = new QGridLayout(m_base_out);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer);

        label_20 = new QLabel(m_base_out);
        label_20->setObjectName(QStringLiteral("label_20"));

        horizontalLayout_10->addWidget(label_20);

        line = new QFrame(m_base_out);
        line->setObjectName(QStringLiteral("line"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(line->sizePolicy().hasHeightForWidth());
        line->setSizePolicy(sizePolicy);
        line->setStyleSheet(QStringLiteral("color: rgb(255, 255, 127);"));
        line->setFrameShadow(QFrame::Raised);
        line->setFrameShape(QFrame::HLine);

        horizontalLayout_10->addWidget(line);

        label_21 = new QLabel(m_base_out);
        label_21->setObjectName(QStringLiteral("label_21"));

        horizontalLayout_10->addWidget(label_21);

        line_2 = new QFrame(m_base_out);
        line_2->setObjectName(QStringLiteral("line_2"));
        sizePolicy.setHeightForWidth(line_2->sizePolicy().hasHeightForWidth());
        line_2->setSizePolicy(sizePolicy);
        line_2->setFrameShadow(QFrame::Raised);
        line_2->setFrameShape(QFrame::HLine);

        horizontalLayout_10->addWidget(line_2);

        label_22 = new QLabel(m_base_out);
        label_22->setObjectName(QStringLiteral("label_22"));

        horizontalLayout_10->addWidget(label_22);

        line_3 = new QFrame(m_base_out);
        line_3->setObjectName(QStringLiteral("line_3"));
        sizePolicy.setHeightForWidth(line_3->sizePolicy().hasHeightForWidth());
        line_3->setSizePolicy(sizePolicy);
        line_3->setFrameShadow(QFrame::Raised);
        line_3->setFrameShape(QFrame::HLine);

        horizontalLayout_10->addWidget(line_3);

        label_23 = new QLabel(m_base_out);
        label_23->setObjectName(QStringLiteral("label_23"));

        horizontalLayout_10->addWidget(label_23);

        line_7 = new QFrame(m_base_out);
        line_7->setObjectName(QStringLiteral("line_7"));
        sizePolicy.setHeightForWidth(line_7->sizePolicy().hasHeightForWidth());
        line_7->setSizePolicy(sizePolicy);
        line_7->setFrameShadow(QFrame::Raised);
        line_7->setFrameShape(QFrame::HLine);

        horizontalLayout_10->addWidget(line_7);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_4);


        gridLayout->addLayout(horizontalLayout_10, 0, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(1);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        frame_4 = new QFrame(m_base_out);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setFrameShape(QFrame::Box);
        frame_4->setFrameShadow(QFrame::Raised);
        frame_4->setLineWidth(2);
        gridLayout_6 = new QGridLayout(frame_4);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(2);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        pushButton = new QPushButton(frame_4);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);

        horizontalLayout_9->addWidget(pushButton);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(2);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        pushButton_2 = new QPushButton(frame_4);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setEnabled(false);
        sizePolicy1.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy1);

        horizontalLayout_7->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(frame_4);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setEnabled(false);
        sizePolicy1.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy1);

        horizontalLayout_7->addWidget(pushButton_3);


        verticalLayout_3->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(2);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        pushButton_7 = new QPushButton(frame_4);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setEnabled(false);
        sizePolicy1.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy1);

        horizontalLayout_8->addWidget(pushButton_7);

        pushButton_6 = new QPushButton(frame_4);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setEnabled(false);
        sizePolicy1.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy1);

        horizontalLayout_8->addWidget(pushButton_6);


        verticalLayout_3->addLayout(horizontalLayout_8);


        horizontalLayout_9->addLayout(verticalLayout_3);

        pushButton_4 = new QPushButton(frame_4);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setEnabled(false);
        sizePolicy1.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy1);

        horizontalLayout_9->addWidget(pushButton_4);


        verticalLayout_4->addLayout(horizontalLayout_9);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(2);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(59, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        all_start = new QCheckBox(frame_4);
        all_start->setObjectName(QStringLiteral("all_start"));
        all_start->setEnabled(true);
        sizePolicy.setHeightForWidth(all_start->sizePolicy().hasHeightForWidth());
        all_start->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(12);
        all_start->setFont(font);

        horizontalLayout_3->addWidget(all_start);

        u_i_all_start = new QCheckBox(frame_4);
        u_i_all_start->setObjectName(QStringLiteral("u_i_all_start"));
        u_i_all_start->setEnabled(true);
        sizePolicy.setHeightForWidth(u_i_all_start->sizePolicy().hasHeightForWidth());
        u_i_all_start->setSizePolicy(sizePolicy);
        u_i_all_start->setFont(font);

        horizontalLayout_3->addWidget(u_i_all_start);

        horizontalSpacer_3 = new QSpacerItem(59, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 1);
        horizontalLayout_3->setStretch(2, 1);
        horizontalLayout_3->setStretch(3, 1);

        verticalLayout_4->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(2);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(10, -1, 10, -1);
        ua_start = new QCheckBox(frame_4);
        ua_start->setObjectName(QStringLiteral("ua_start"));
        ua_start->setFont(font);

        horizontalLayout_4->addWidget(ua_start);

        ub_start = new QCheckBox(frame_4);
        ub_start->setObjectName(QStringLiteral("ub_start"));
        ub_start->setFont(font);

        horizontalLayout_4->addWidget(ub_start);

        uc_start = new QCheckBox(frame_4);
        uc_start->setObjectName(QStringLiteral("uc_start"));
        uc_start->setFont(font);

        horizontalLayout_4->addWidget(uc_start);

        ud_start = new QCheckBox(frame_4);
        ud_start->setObjectName(QStringLiteral("ud_start"));
        ud_start->setFont(font);

        horizontalLayout_4->addWidget(ud_start);


        verticalLayout_4->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(2);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(10, -1, 10, -1);
        ia_start = new QCheckBox(frame_4);
        ia_start->setObjectName(QStringLiteral("ia_start"));
        ia_start->setEnabled(true);
        ia_start->setFont(font);

        horizontalLayout_5->addWidget(ia_start);

        ib_start = new QCheckBox(frame_4);
        ib_start->setObjectName(QStringLiteral("ib_start"));
        ib_start->setEnabled(true);
        ib_start->setFont(font);

        horizontalLayout_5->addWidget(ib_start);

        ic_start = new QCheckBox(frame_4);
        ic_start->setObjectName(QStringLiteral("ic_start"));
        ic_start->setEnabled(true);
        ic_start->setFont(font);

        horizontalLayout_5->addWidget(ic_start);


        verticalLayout_4->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        start = new QPushButton(frame_4);
        start->setObjectName(QStringLiteral("start"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(start->sizePolicy().hasHeightForWidth());
        start->setSizePolicy(sizePolicy2);

        horizontalLayout_6->addWidget(start);

        stop = new QPushButton(frame_4);
        stop->setObjectName(QStringLiteral("stop"));
        sizePolicy2.setHeightForWidth(stop->sizePolicy().hasHeightForWidth());
        stop->setSizePolicy(sizePolicy2);

        horizontalLayout_6->addWidget(stop);


        verticalLayout_4->addLayout(horizontalLayout_6);


        gridLayout_6->addLayout(verticalLayout_4, 0, 0, 1, 1);


        gridLayout_2->addWidget(frame_4, 1, 1, 1, 1);

        frame_6 = new QFrame(m_base_out);
        frame_6->setObjectName(QStringLiteral("frame_6"));
        frame_6->setFrameShape(QFrame::Box);
        frame_6->setFrameShadow(QFrame::Raised);
        frame_6->setLineWidth(2);
        gridLayout_10 = new QGridLayout(frame_6);
        gridLayout_10->setSpacing(0);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        gridLayout_10->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(frame_6);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_8 = new QGridLayout(tab);
        gridLayout_8->setSpacing(0);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        gridLayout_8->setContentsMargins(0, 0, 0, 0);
        frame_3 = new QFrame(tab);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setFrameShape(QFrame::Box);
        frame_3->setFrameShadow(QFrame::Raised);
        frame_3->setLineWidth(2);
        gridLayout_7 = new QGridLayout(frame_3);
        gridLayout_7->setSpacing(0);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 5, -1, -1);
        all_value = new QCheckBox(frame_3);
        all_value->setObjectName(QStringLiteral("all_value"));
        all_value->setFont(font);

        horizontalLayout->addWidget(all_value);

        ua_value = new QCheckBox(frame_3);
        ua_value->setObjectName(QStringLiteral("ua_value"));
        ua_value->setFont(font);

        horizontalLayout->addWidget(ua_value);

        ia_value = new QCheckBox(frame_3);
        ia_value->setObjectName(QStringLiteral("ia_value"));
        ia_value->setFont(font);

        horizontalLayout->addWidget(ia_value);

        ub_value = new QCheckBox(frame_3);
        ub_value->setObjectName(QStringLiteral("ub_value"));
        ub_value->setFont(font);

        horizontalLayout->addWidget(ub_value);

        ib_value = new QCheckBox(frame_3);
        ib_value->setObjectName(QStringLiteral("ib_value"));
        ib_value->setFont(font);

        horizontalLayout->addWidget(ib_value);

        uc_value = new QCheckBox(frame_3);
        uc_value->setObjectName(QStringLiteral("uc_value"));
        uc_value->setFont(font);

        horizontalLayout->addWidget(uc_value);

        ic_value = new QCheckBox(frame_3);
        ic_value->setObjectName(QStringLiteral("ic_value"));
        ic_value->setFont(font);

        horizontalLayout->addWidget(ic_value);

        ud_value = new QCheckBox(frame_3);
        ud_value->setObjectName(QStringLiteral("ud_value"));
        ud_value->setFont(font);

        horizontalLayout->addWidget(ud_value);


        verticalLayout_2->addLayout(horizontalLayout);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(5);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(5, 5, 5, 5);
        label = new QLabel(frame_3);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_3->addWidget(label, 0, 0, 1, 1);

        wave_type = new M_spinbox(frame_3);
        wave_type->setObjectName(QStringLiteral("wave_type"));
        sizePolicy1.setHeightForWidth(wave_type->sizePolicy().hasHeightForWidth());
        wave_type->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(wave_type, 0, 1, 1, 1);

        label_2 = new QLabel(frame_3);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_3->addWidget(label_2, 0, 2, 1, 1);

        value = new QDoubleSpinBox(frame_3);
        value->setObjectName(QStringLiteral("value"));
        sizePolicy1.setHeightForWidth(value->sizePolicy().hasHeightForWidth());
        value->setSizePolicy(sizePolicy1);
        value->setMinimum(-500);
        value->setMaximum(500);
        value->setValue(57.7);

        gridLayout_3->addWidget(value, 0, 3, 1, 1);

        label_3 = new QLabel(frame_3);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_3->addWidget(label_3, 1, 0, 1, 1);

        phase = new QDoubleSpinBox(frame_3);
        phase->setObjectName(QStringLiteral("phase"));
        sizePolicy1.setHeightForWidth(phase->sizePolicy().hasHeightForWidth());
        phase->setSizePolicy(sizePolicy1);
        phase->setMinimum(-360);
        phase->setMaximum(360);

        gridLayout_3->addWidget(phase, 1, 1, 1, 1);

        label_4 = new QLabel(frame_3);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_3->addWidget(label_4, 1, 2, 1, 1);

        ratio = new QDoubleSpinBox(frame_3);
        ratio->setObjectName(QStringLiteral("ratio"));
        ratio->setEnabled(false);
        sizePolicy1.setHeightForWidth(ratio->sizePolicy().hasHeightForWidth());
        ratio->setSizePolicy(sizePolicy1);
        ratio->setMinimum(-180);
        ratio->setMaximum(180);

        gridLayout_3->addWidget(ratio, 1, 3, 1, 1);


        verticalLayout_2->addLayout(gridLayout_3);

        frame_5 = new QFrame(frame_3);
        frame_5->setObjectName(QStringLiteral("frame_5"));
        frame_5->setFrameShape(QFrame::HLine);
        frame_5->setFrameShadow(QFrame::Raised);
        frame_5->setLineWidth(2);

        verticalLayout_2->addWidget(frame_5);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        label_8 = new QLabel(frame_3);
        label_8->setObjectName(QStringLiteral("label_8"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy3);

        horizontalLayout_12->addWidget(label_8);

        freq_set = new QCheckBox(frame_3);
        freq_set->setObjectName(QStringLiteral("freq_set"));
        freq_set->setChecked(true);

        horizontalLayout_12->addWidget(freq_set);


        verticalLayout->addLayout(horizontalLayout_12);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_5 = new QLabel(frame_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy3.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy3);
        label_5->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout_2->addWidget(label_5);

        a_b_freq = new QDoubleSpinBox(frame_3);
        a_b_freq->setObjectName(QStringLiteral("a_b_freq"));
        sizePolicy2.setHeightForWidth(a_b_freq->sizePolicy().hasHeightForWidth());
        a_b_freq->setSizePolicy(sizePolicy2);
        a_b_freq->setMinimum(40);
        a_b_freq->setMaximum(65);
        a_b_freq->setValue(50);

        horizontalLayout_2->addWidget(a_b_freq);

        label_7 = new QLabel(frame_3);
        label_7->setObjectName(QStringLiteral("label_7"));
        sizePolicy3.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy3);
        label_7->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout_2->addWidget(label_7);

        c_freq_2 = new QDoubleSpinBox(frame_3);
        c_freq_2->setObjectName(QStringLiteral("c_freq_2"));
        sizePolicy2.setHeightForWidth(c_freq_2->sizePolicy().hasHeightForWidth());
        c_freq_2->setSizePolicy(sizePolicy2);
        c_freq_2->setMinimum(40);
        c_freq_2->setMaximum(65);
        c_freq_2->setValue(50);

        horizontalLayout_2->addWidget(c_freq_2);

        label_6 = new QLabel(frame_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        sizePolicy3.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy3);
        label_6->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout_2->addWidget(label_6);

        c_freq = new QDoubleSpinBox(frame_3);
        c_freq->setObjectName(QStringLiteral("c_freq"));
        sizePolicy2.setHeightForWidth(c_freq->sizePolicy().hasHeightForWidth());
        c_freq->setSizePolicy(sizePolicy2);
        c_freq->setMinimum(40);
        c_freq->setMaximum(65);
        c_freq->setValue(50);

        horizontalLayout_2->addWidget(c_freq);

        label_9 = new QLabel(frame_3);
        label_9->setObjectName(QStringLiteral("label_9"));
        sizePolicy3.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy3);
        label_9->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout_2->addWidget(label_9);

        c_freq_3 = new QDoubleSpinBox(frame_3);
        c_freq_3->setObjectName(QStringLiteral("c_freq_3"));
        sizePolicy2.setHeightForWidth(c_freq_3->sizePolicy().hasHeightForWidth());
        c_freq_3->setSizePolicy(sizePolicy2);
        c_freq_3->setMinimum(40);
        c_freq_3->setMaximum(65);
        c_freq_3->setValue(50);

        horizontalLayout_2->addWidget(c_freq_3);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 1);
        horizontalLayout_2->setStretch(2, 1);
        horizontalLayout_2->setStretch(3, 1);
        horizontalLayout_2->setStretch(4, 1);
        horizontalLayout_2->setStretch(5, 1);

        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 1);

        verticalLayout_2->addLayout(verticalLayout);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 2);
        verticalLayout_2->setStretch(3, 2);

        gridLayout_7->addLayout(verticalLayout_2, 0, 0, 1, 1);


        gridLayout_8->addWidget(frame_3, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout_9 = new QGridLayout(tab_2);
        gridLayout_9->setSpacing(0);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        gridLayout_9->setContentsMargins(0, 0, 0, 0);
        tableView = new QTableView(tab_2);
        tableView->setObjectName(QStringLiteral("tableView"));

        gridLayout_9->addWidget(tableView, 0, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());

        gridLayout_10->addWidget(tabWidget, 0, 0, 1, 1);


        gridLayout_2->addWidget(frame_6, 1, 0, 1, 1);

        frame = new QFrame(m_base_out);
        frame->setObjectName(QStringLiteral("frame"));
        sizePolicy3.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy3);
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        frame->setLineWidth(2);
        gridLayout_4 = new QGridLayout(frame);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        U_map = new CustomPlotHasRoll(frame);
        U_map->setObjectName(QStringLiteral("U_map"));

        gridLayout_4->addWidget(U_map, 0, 0, 1, 1);


        gridLayout_2->addWidget(frame, 0, 0, 1, 1);

        frame_2 = new QFrame(m_base_out);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::Box);
        frame_2->setFrameShadow(QFrame::Raised);
        frame_2->setLineWidth(2);
        gridLayout_5 = new QGridLayout(frame_2);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        I_map = new CustomPlotHasRoll(frame_2);
        I_map->setObjectName(QStringLiteral("I_map"));

        gridLayout_5->addWidget(I_map, 0, 0, 1, 1);


        gridLayout_2->addWidget(frame_2, 0, 1, 1, 1);

        gridLayout_2->setRowStretch(0, 1);
        gridLayout_2->setRowStretch(1, 1);

        gridLayout->addLayout(gridLayout_2, 1, 0, 1, 1);


        retranslateUi(m_base_out);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(m_base_out);
    } // setupUi

    void retranslateUi(QWidget *m_base_out)
    {
        m_base_out->setWindowTitle(QApplication::translate("m_base_out", "Form", 0));
        label_20->setText(QApplication::translate("m_base_out", "A\347\233\270", 0));
        label_21->setText(QApplication::translate("m_base_out", "B\347\233\270", 0));
        label_22->setText(QApplication::translate("m_base_out", "C\347\233\270", 0));
        label_23->setText(QApplication::translate("m_base_out", "D\347\233\270", 0));
        pushButton->setText(QApplication::translate("m_base_out", "\345\210\207\346\215\242\n"
"\350\276\223\345\205\245\346\226\271\345\274\217", 0));
        pushButton_2->setText(QApplication::translate("m_base_out", "0.5L", 0));
        pushButton_3->setText(QApplication::translate("m_base_out", "0.8L", 0));
        pushButton_7->setText(QApplication::translate("m_base_out", "0.5C", 0));
        pushButton_6->setText(QApplication::translate("m_base_out", "0.8C", 0));
        pushButton_4->setText(QApplication::translate("m_base_out", "1.0", 0));
        all_start->setText(QApplication::translate("m_base_out", "\345\205\250\351\200\211", 0));
        u_i_all_start->setText(QApplication::translate("m_base_out", "  U I \345\220\214\346\255\245\345\213\276\351\200\211", 0));
        ua_start->setText(QApplication::translate("m_base_out", "UA", 0));
        ub_start->setText(QApplication::translate("m_base_out", "UB", 0));
        uc_start->setText(QApplication::translate("m_base_out", "UC", 0));
        ud_start->setText(QApplication::translate("m_base_out", "UD", 0));
        ia_start->setText(QApplication::translate("m_base_out", "IA", 0));
        ib_start->setText(QApplication::translate("m_base_out", "IB", 0));
        ic_start->setText(QApplication::translate("m_base_out", "IC", 0));
        start->setText(QApplication::translate("m_base_out", "\345\220\257\345\212\250", 0));
        stop->setText(QApplication::translate("m_base_out", "\345\201\234\346\255\242", 0));
        all_value->setText(QApplication::translate("m_base_out", "\347\273\237\344\270\200\350\256\276\347\275\256", 0));
        ua_value->setText(QApplication::translate("m_base_out", "UA", 0));
        ia_value->setText(QApplication::translate("m_base_out", "IA", 0));
        ub_value->setText(QApplication::translate("m_base_out", "UB", 0));
        ib_value->setText(QApplication::translate("m_base_out", "IB", 0));
        uc_value->setText(QApplication::translate("m_base_out", "UC", 0));
        ic_value->setText(QApplication::translate("m_base_out", "IC", 0));
        ud_value->setText(QApplication::translate("m_base_out", "UD", 0));
        label->setText(QApplication::translate("m_base_out", "\346\263\242\345\275\242\347\261\273\345\236\213", 0));
        label_2->setText(QApplication::translate("m_base_out", "\345\271\205\345\200\274", 0));
        label_3->setText(QApplication::translate("m_base_out", "\347\233\270\344\275\215", 0));
        label_4->setText(QApplication::translate("m_base_out", "\347\233\264\346\265\201\345\201\217\347\247\273(%)", 0));
        label_8->setText(QApplication::translate("m_base_out", "\351\242\221\347\216\207:", 0));
        freq_set->setText(QApplication::translate("m_base_out", "\345\220\214\346\255\245", 0));
        label_5->setText(QApplication::translate("m_base_out", "FA:", 0));
        label_7->setText(QApplication::translate("m_base_out", "FB:", 0));
        label_6->setText(QApplication::translate("m_base_out", "FC:", 0));
        label_9->setText(QApplication::translate("m_base_out", "FD:", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("m_base_out", "Tab 1", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("m_base_out", "Tab 2", 0));
    } // retranslateUi

};

namespace Ui {
    class m_base_out: public Ui_m_base_out {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_M_BASE_OUT_H
