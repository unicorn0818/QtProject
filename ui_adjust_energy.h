/********************************************************************************
** Form generated from reading UI file 'adjust_energy.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADJUST_ENERGY_H
#define UI_ADJUST_ENERGY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "m_spinbox.h"

QT_BEGIN_NAMESPACE

class Ui_adjust_energy
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *label_5;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_8;
    QSpinBox *spinBox_6;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QDoubleSpinBox *doubleSpinBox;
    QDoubleSpinBox *doubleSpinBox_13;
    QDoubleSpinBox *doubleSpinBox_12;
    QDoubleSpinBox *doubleSpinBox_11;
    QDoubleSpinBox *doubleSpinBox_2;
    QDoubleSpinBox *doubleSpinBox_3;
    QDoubleSpinBox *doubleSpinBox_4;
    QHBoxLayout *horizontalLayout_8;
    QDoubleSpinBox *doubleSpinBox_5;
    QDoubleSpinBox *doubleSpinBox_6;
    QDoubleSpinBox *doubleSpinBox_7;
    QDoubleSpinBox *doubleSpinBox_8;
    QDoubleSpinBox *doubleSpinBox_9;
    QDoubleSpinBox *doubleSpinBox_10;
    QDoubleSpinBox *doubleSpinBox_14;
    QPushButton *pushButton_11;
    QHBoxLayout *horizontalLayout_2;
    QFrame *frame;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_7;
    QComboBox *phase;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_15;
    QSpinBox *std_byte_num;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_9;
    M_spinbox *gear;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_14;
    M_spinbox *check_type;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *set_gear;
    QPushButton *read_gear;
    QFrame *frame_3;
    QGridLayout *gridLayout_2;
    QPushButton *check_adjust;
    QPushButton *start_adjust;
    QPushButton *enable_std_num;
    QPushButton *out_std;
    QPushButton *normal;
    QPushButton *count_num;
    QPushButton *init_num;
    QPushButton *stop_adjust;
    QPushButton *stop_out;
    QPushButton *read_old_num;
    QPushButton *init_std_value;
    QPushButton *write_num;
    QSpacerItem *horizontalSpacer;
    QFrame *frame_2;
    QGridLayout *gridLayout_5;
    QVBoxLayout *verticalLayout_9;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QFrame *frame_4;
    QVBoxLayout *verticalLayout_10;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pushButton_12;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *adjust_energy)
    {
        if (adjust_energy->objectName().isEmpty())
            adjust_energy->setObjectName(QStringLiteral("adjust_energy"));
        adjust_energy->resize(798, 456);
        gridLayout = new QGridLayout(adjust_energy);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(2);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(2);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label = new QLabel(adjust_energy);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_3->addWidget(label);

        label_2 = new QLabel(adjust_energy);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        label_3 = new QLabel(adjust_energy);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        label_4 = new QLabel(adjust_energy);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_3->addWidget(label_4);

        label_6 = new QLabel(adjust_energy);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_3->addWidget(label_6);

        label_5 = new QLabel(adjust_energy);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_3->addWidget(label_5);

        horizontalLayout_3->setStretch(5, 4);

        verticalLayout_3->addLayout(horizontalLayout_3);

        tableWidget = new QTableWidget(adjust_energy);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        verticalLayout_3->addWidget(tableWidget);


        verticalLayout_4->addLayout(verticalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(2);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_8 = new QLabel(adjust_energy);
        label_8->setObjectName(QStringLiteral("label_8"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(label_8);

        spinBox_6 = new QSpinBox(adjust_energy);
        spinBox_6->setObjectName(QStringLiteral("spinBox_6"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(spinBox_6->sizePolicy().hasHeightForWidth());
        spinBox_6->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(spinBox_6);


        horizontalLayout_5->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        doubleSpinBox = new QDoubleSpinBox(adjust_energy);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        sizePolicy1.setHeightForWidth(doubleSpinBox->sizePolicy().hasHeightForWidth());
        doubleSpinBox->setSizePolicy(sizePolicy1);
        doubleSpinBox->setMaximum(999.99);
        doubleSpinBox->setValue(1);

        horizontalLayout->addWidget(doubleSpinBox);

        doubleSpinBox_13 = new QDoubleSpinBox(adjust_energy);
        doubleSpinBox_13->setObjectName(QStringLiteral("doubleSpinBox_13"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_13->sizePolicy().hasHeightForWidth());
        doubleSpinBox_13->setSizePolicy(sizePolicy1);
        doubleSpinBox_13->setMaximum(999.99);
        doubleSpinBox_13->setValue(5);

        horizontalLayout->addWidget(doubleSpinBox_13);

        doubleSpinBox_12 = new QDoubleSpinBox(adjust_energy);
        doubleSpinBox_12->setObjectName(QStringLiteral("doubleSpinBox_12"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_12->sizePolicy().hasHeightForWidth());
        doubleSpinBox_12->setSizePolicy(sizePolicy1);
        doubleSpinBox_12->setMaximum(999.99);
        doubleSpinBox_12->setValue(10);

        horizontalLayout->addWidget(doubleSpinBox_12);

        doubleSpinBox_11 = new QDoubleSpinBox(adjust_energy);
        doubleSpinBox_11->setObjectName(QStringLiteral("doubleSpinBox_11"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_11->sizePolicy().hasHeightForWidth());
        doubleSpinBox_11->setSizePolicy(sizePolicy1);
        doubleSpinBox_11->setMaximum(999.99);
        doubleSpinBox_11->setValue(20);

        horizontalLayout->addWidget(doubleSpinBox_11);

        doubleSpinBox_2 = new QDoubleSpinBox(adjust_energy);
        doubleSpinBox_2->setObjectName(QStringLiteral("doubleSpinBox_2"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_2->sizePolicy().hasHeightForWidth());
        doubleSpinBox_2->setSizePolicy(sizePolicy1);
        doubleSpinBox_2->setMaximum(999.99);
        doubleSpinBox_2->setValue(30);

        horizontalLayout->addWidget(doubleSpinBox_2);

        doubleSpinBox_3 = new QDoubleSpinBox(adjust_energy);
        doubleSpinBox_3->setObjectName(QStringLiteral("doubleSpinBox_3"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_3->sizePolicy().hasHeightForWidth());
        doubleSpinBox_3->setSizePolicy(sizePolicy1);
        doubleSpinBox_3->setMaximum(999.99);
        doubleSpinBox_3->setValue(40);

        horizontalLayout->addWidget(doubleSpinBox_3);

        doubleSpinBox_4 = new QDoubleSpinBox(adjust_energy);
        doubleSpinBox_4->setObjectName(QStringLiteral("doubleSpinBox_4"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_4->sizePolicy().hasHeightForWidth());
        doubleSpinBox_4->setSizePolicy(sizePolicy1);
        doubleSpinBox_4->setMaximum(999.99);
        doubleSpinBox_4->setValue(50);

        horizontalLayout->addWidget(doubleSpinBox_4);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(2);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        doubleSpinBox_5 = new QDoubleSpinBox(adjust_energy);
        doubleSpinBox_5->setObjectName(QStringLiteral("doubleSpinBox_5"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_5->sizePolicy().hasHeightForWidth());
        doubleSpinBox_5->setSizePolicy(sizePolicy1);
        doubleSpinBox_5->setMaximum(999.99);
        doubleSpinBox_5->setValue(60);

        horizontalLayout_8->addWidget(doubleSpinBox_5);

        doubleSpinBox_6 = new QDoubleSpinBox(adjust_energy);
        doubleSpinBox_6->setObjectName(QStringLiteral("doubleSpinBox_6"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_6->sizePolicy().hasHeightForWidth());
        doubleSpinBox_6->setSizePolicy(sizePolicy1);
        doubleSpinBox_6->setMaximum(999.99);
        doubleSpinBox_6->setValue(70);

        horizontalLayout_8->addWidget(doubleSpinBox_6);

        doubleSpinBox_7 = new QDoubleSpinBox(adjust_energy);
        doubleSpinBox_7->setObjectName(QStringLiteral("doubleSpinBox_7"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_7->sizePolicy().hasHeightForWidth());
        doubleSpinBox_7->setSizePolicy(sizePolicy1);
        doubleSpinBox_7->setMaximum(999.99);
        doubleSpinBox_7->setValue(80);

        horizontalLayout_8->addWidget(doubleSpinBox_7);

        doubleSpinBox_8 = new QDoubleSpinBox(adjust_energy);
        doubleSpinBox_8->setObjectName(QStringLiteral("doubleSpinBox_8"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_8->sizePolicy().hasHeightForWidth());
        doubleSpinBox_8->setSizePolicy(sizePolicy1);
        doubleSpinBox_8->setMaximum(999.99);
        doubleSpinBox_8->setValue(90);

        horizontalLayout_8->addWidget(doubleSpinBox_8);

        doubleSpinBox_9 = new QDoubleSpinBox(adjust_energy);
        doubleSpinBox_9->setObjectName(QStringLiteral("doubleSpinBox_9"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_9->sizePolicy().hasHeightForWidth());
        doubleSpinBox_9->setSizePolicy(sizePolicy1);
        doubleSpinBox_9->setMaximum(999.99);
        doubleSpinBox_9->setValue(100);

        horizontalLayout_8->addWidget(doubleSpinBox_9);

        doubleSpinBox_10 = new QDoubleSpinBox(adjust_energy);
        doubleSpinBox_10->setObjectName(QStringLiteral("doubleSpinBox_10"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_10->sizePolicy().hasHeightForWidth());
        doubleSpinBox_10->setSizePolicy(sizePolicy1);
        doubleSpinBox_10->setMaximum(999.99);
        doubleSpinBox_10->setValue(110);

        horizontalLayout_8->addWidget(doubleSpinBox_10);

        doubleSpinBox_14 = new QDoubleSpinBox(adjust_energy);
        doubleSpinBox_14->setObjectName(QStringLiteral("doubleSpinBox_14"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_14->sizePolicy().hasHeightForWidth());
        doubleSpinBox_14->setSizePolicy(sizePolicy1);
        doubleSpinBox_14->setMaximum(999.99);
        doubleSpinBox_14->setValue(120);

        horizontalLayout_8->addWidget(doubleSpinBox_14);


        verticalLayout->addLayout(horizontalLayout_8);


        horizontalLayout_5->addLayout(verticalLayout);

        pushButton_11 = new QPushButton(adjust_energy);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));

        horizontalLayout_5->addWidget(pushButton_11);

        horizontalLayout_5->setStretch(0, 1);
        horizontalLayout_5->setStretch(1, 7);
        horizontalLayout_5->setStretch(2, 1);

        verticalLayout_4->addLayout(horizontalLayout_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        frame = new QFrame(adjust_energy);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        frame->setLineWidth(2);
        gridLayout_3 = new QGridLayout(frame);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_7 = new QLabel(frame);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout_5->addWidget(label_7);

        phase = new QComboBox(frame);
        phase->setObjectName(QStringLiteral("phase"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(phase->sizePolicy().hasHeightForWidth());
        phase->setSizePolicy(sizePolicy2);

        verticalLayout_5->addWidget(phase);


        gridLayout_3->addLayout(verticalLayout_5, 0, 0, 1, 1);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        label_15 = new QLabel(frame);
        label_15->setObjectName(QStringLiteral("label_15"));

        verticalLayout_7->addWidget(label_15);

        std_byte_num = new QSpinBox(frame);
        std_byte_num->setObjectName(QStringLiteral("std_byte_num"));
        sizePolicy1.setHeightForWidth(std_byte_num->sizePolicy().hasHeightForWidth());
        std_byte_num->setSizePolicy(sizePolicy1);

        verticalLayout_7->addWidget(std_byte_num);


        gridLayout_3->addLayout(verticalLayout_7, 0, 1, 1, 1);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        label_9 = new QLabel(frame);
        label_9->setObjectName(QStringLiteral("label_9"));

        verticalLayout_8->addWidget(label_9);

        gear = new M_spinbox(frame);
        gear->setObjectName(QStringLiteral("gear"));
        sizePolicy1.setHeightForWidth(gear->sizePolicy().hasHeightForWidth());
        gear->setSizePolicy(sizePolicy1);
        gear->setMaximum(10);

        verticalLayout_8->addWidget(gear);


        gridLayout_3->addLayout(verticalLayout_8, 1, 0, 1, 1);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label_14 = new QLabel(frame);
        label_14->setObjectName(QStringLiteral("label_14"));

        verticalLayout_6->addWidget(label_14);

        check_type = new M_spinbox(frame);
        check_type->setObjectName(QStringLiteral("check_type"));
        sizePolicy1.setHeightForWidth(check_type->sizePolicy().hasHeightForWidth());
        check_type->setSizePolicy(sizePolicy1);

        verticalLayout_6->addWidget(check_type);


        gridLayout_3->addLayout(verticalLayout_6, 1, 1, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(2);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        set_gear = new QPushButton(frame);
        set_gear->setObjectName(QStringLiteral("set_gear"));
        sizePolicy.setHeightForWidth(set_gear->sizePolicy().hasHeightForWidth());
        set_gear->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(set_gear);

        read_gear = new QPushButton(frame);
        read_gear->setObjectName(QStringLiteral("read_gear"));
        sizePolicy.setHeightForWidth(read_gear->sizePolicy().hasHeightForWidth());
        read_gear->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(read_gear);


        gridLayout_3->addLayout(horizontalLayout_4, 2, 0, 1, 2);

        gridLayout_3->setRowStretch(0, 1);
        gridLayout_3->setRowStretch(1, 1);
        gridLayout_3->setRowStretch(2, 1);
        gridLayout_3->setColumnStretch(0, 1);
        gridLayout_3->setColumnStretch(1, 1);

        horizontalLayout_2->addWidget(frame);

        frame_3 = new QFrame(adjust_energy);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setFrameShape(QFrame::Box);
        frame_3->setFrameShadow(QFrame::Raised);
        frame_3->setLineWidth(2);
        gridLayout_2 = new QGridLayout(frame_3);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        check_adjust = new QPushButton(frame_3);
        check_adjust->setObjectName(QStringLiteral("check_adjust"));

        gridLayout_2->addWidget(check_adjust, 0, 1, 1, 1);

        start_adjust = new QPushButton(frame_3);
        start_adjust->setObjectName(QStringLiteral("start_adjust"));

        gridLayout_2->addWidget(start_adjust, 0, 2, 1, 1);

        enable_std_num = new QPushButton(frame_3);
        enable_std_num->setObjectName(QStringLiteral("enable_std_num"));

        gridLayout_2->addWidget(enable_std_num, 0, 0, 1, 1);

        out_std = new QPushButton(frame_3);
        out_std->setObjectName(QStringLiteral("out_std"));

        gridLayout_2->addWidget(out_std, 1, 4, 1, 1);

        normal = new QPushButton(frame_3);
        normal->setObjectName(QStringLiteral("normal"));

        gridLayout_2->addWidget(normal, 0, 4, 1, 1);

        count_num = new QPushButton(frame_3);
        count_num->setObjectName(QStringLiteral("count_num"));

        gridLayout_2->addWidget(count_num, 1, 1, 1, 1);

        init_num = new QPushButton(frame_3);
        init_num->setObjectName(QStringLiteral("init_num"));
        init_num->setEnabled(false);

        gridLayout_2->addWidget(init_num, 2, 0, 1, 1);

        stop_adjust = new QPushButton(frame_3);
        stop_adjust->setObjectName(QStringLiteral("stop_adjust"));

        gridLayout_2->addWidget(stop_adjust, 1, 2, 1, 1);

        stop_out = new QPushButton(frame_3);
        stop_out->setObjectName(QStringLiteral("stop_out"));

        gridLayout_2->addWidget(stop_out, 2, 4, 1, 1);

        read_old_num = new QPushButton(frame_3);
        read_old_num->setObjectName(QStringLiteral("read_old_num"));

        gridLayout_2->addWidget(read_old_num, 1, 0, 1, 1);

        init_std_value = new QPushButton(frame_3);
        init_std_value->setObjectName(QStringLiteral("init_std_value"));

        gridLayout_2->addWidget(init_std_value, 2, 1, 1, 1);

        write_num = new QPushButton(frame_3);
        write_num->setObjectName(QStringLiteral("write_num"));

        gridLayout_2->addWidget(write_num, 2, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 3, 1, 1);

        gridLayout_2->setColumnStretch(0, 5);
        gridLayout_2->setColumnStretch(1, 5);
        gridLayout_2->setColumnStretch(2, 5);
        gridLayout_2->setColumnStretch(3, 1);
        gridLayout_2->setColumnStretch(4, 5);

        horizontalLayout_2->addWidget(frame_3);

        frame_2 = new QFrame(adjust_energy);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::Box);
        frame_2->setFrameShadow(QFrame::Raised);
        frame_2->setLineWidth(2);
        gridLayout_5 = new QGridLayout(frame_2);
        gridLayout_5->setSpacing(0);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(2);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(5, 5, 5, 5);
        pushButton_13 = new QPushButton(frame_2);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));

        verticalLayout_9->addWidget(pushButton_13);

        pushButton_14 = new QPushButton(frame_2);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));

        verticalLayout_9->addWidget(pushButton_14);


        gridLayout_5->addLayout(verticalLayout_9, 0, 0, 1, 1);

        frame_4 = new QFrame(frame_2);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(frame_4->sizePolicy().hasHeightForWidth());
        frame_4->setSizePolicy(sizePolicy3);
        frame_4->setFrameShape(QFrame::HLine);
        frame_4->setFrameShadow(QFrame::Raised);
        frame_4->setLineWidth(2);

        gridLayout_5->addWidget(frame_4, 1, 0, 1, 1);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(5, -1, 5, -1);
        verticalSpacer_2 = new QSpacerItem(119, 25, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_10->addItem(verticalSpacer_2);

        pushButton_12 = new QPushButton(frame_2);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));

        verticalLayout_10->addWidget(pushButton_12);

        verticalSpacer = new QSpacerItem(119, 26, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_10->addItem(verticalSpacer);


        gridLayout_5->addLayout(verticalLayout_10, 2, 0, 1, 1);

        gridLayout_5->setRowStretch(0, 1);
        gridLayout_5->setRowStretch(2, 1);

        horizontalLayout_2->addWidget(frame_2);

        horizontalLayout_2->setStretch(0, 2);
        horizontalLayout_2->setStretch(1, 3);
        horizontalLayout_2->setStretch(2, 1);

        verticalLayout_4->addLayout(horizontalLayout_2);

        verticalLayout_4->setStretch(0, 5);
        verticalLayout_4->setStretch(1, 1);
        verticalLayout_4->setStretch(2, 4);

        gridLayout->addLayout(verticalLayout_4, 0, 0, 1, 1);


        retranslateUi(adjust_energy);

        QMetaObject::connectSlotsByName(adjust_energy);
    } // setupUi

    void retranslateUi(QWidget *adjust_energy)
    {
        adjust_energy->setWindowTitle(QApplication::translate("adjust_energy", "Form", 0));
        label->setText(QApplication::translate("adjust_energy", "\345\275\223\345\211\215\347\263\273\346\225\260\344\270\272  ", 0));
        label_2->setText(QApplication::translate("adjust_energy", "\351\200\232\351\201\223:", 0));
        label_3->setText(QApplication::translate("adjust_energy", "\347\224\265\345\216\213", 0));
        label_4->setText(QApplication::translate("adjust_energy", "  \346\241\243\344\275\215:", 0));
        label_6->setText(QApplication::translate("adjust_energy", "1", 0));
        label_5->setText(QApplication::translate("adjust_energy", "  \350\257\267\346\205\216\351\207\215\346\223\215\344\275\234\346\234\254\347\225\214\351\235\242,\346\240\241\345\207\206\345\211\215\350\257\267\350\257\273\345\217\226\351\205\215\347\275\256\344\277\241\346\201\257,\350\277\231\346\240\267\345\210\235\345\247\213\345\214\226\346\240\207\345\207\206\345\200\274\346\211\215\350\203\275\346\255\243\347\241\256\343\200\202", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("adjust_energy", "\345\256\236\346\265\213\345\200\274", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("adjust_energy", "\346\240\207\345\207\206\345\200\274", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("adjust_energy", "\345\216\237\346\240\241\345\207\206\347\263\273\346\225\260", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("adjust_energy", "\346\226\260\346\240\241\345\207\206\347\263\273\346\225\260", 0));
        label_8->setText(QApplication::translate("adjust_energy", "\346\240\241\345\207\206\347\202\271\350\256\276\347\275\256", 0));
        pushButton_11->setText(QApplication::translate("adjust_energy", "\347\233\264\346\265\201\350\264\237\350\275\275\346\240\241\345\207\206", 0));
        label_7->setText(QApplication::translate("adjust_energy", "\351\200\211\346\213\251\347\233\270", 0));
        phase->clear();
        phase->insertItems(0, QStringList()
         << QApplication::translate("adjust_energy", "UA", 0)
         << QApplication::translate("adjust_energy", "IA", 0)
         << QApplication::translate("adjust_energy", "UB", 0)
         << QApplication::translate("adjust_energy", "IB", 0)
         << QApplication::translate("adjust_energy", "UC", 0)
         << QApplication::translate("adjust_energy", "IC", 0)
         << QApplication::translate("adjust_energy", "UD", 0)
         << QApplication::translate("adjust_energy", "ID", 0)
         << QApplication::translate("adjust_energy", "UA1", 0)
         << QApplication::translate("adjust_energy", "IA1", 0)
         << QApplication::translate("adjust_energy", "UB1", 0)
         << QApplication::translate("adjust_energy", "IB1", 0)
         << QApplication::translate("adjust_energy", "UC1", 0)
         << QApplication::translate("adjust_energy", "IC1", 0)
         << QApplication::translate("adjust_energy", "UD1", 0)
         << QApplication::translate("adjust_energy", "ID1", 0)
        );
        label_15->setText(QApplication::translate("adjust_energy", "\346\240\207\345\207\206\345\200\274\345\260\217\346\225\260\344\275\215\346\225\260", 0));
        label_9->setText(QApplication::translate("adjust_energy", "\346\241\243\344\275\215", 0));
        gear->setSuffix(QString());
        label_14->setText(QApplication::translate("adjust_energy", "\346\240\241\351\252\214\347\261\273\345\236\213", 0));
        set_gear->setText(QApplication::translate("adjust_energy", "\350\256\276\347\275\256\346\241\243\344\275\215", 0));
        read_gear->setText(QApplication::translate("adjust_energy", "\350\257\273\345\217\226\346\241\243\344\275\215", 0));
        check_adjust->setText(QApplication::translate("adjust_energy", "\346\265\213\351\207\217\346\240\241\345\207\206", 0));
        start_adjust->setText(QApplication::translate("adjust_energy", "\345\274\200\345\247\213\346\240\241\345\207\206", 0));
        enable_std_num->setText(QApplication::translate("adjust_energy", "\347\246\201\347\224\250\346\240\241\345\207\206\347\263\273\346\225\260", 0));
        out_std->setText(QApplication::translate("adjust_energy", "\346\240\241\345\207\206\347\202\271\350\276\223\345\207\272", 0));
        normal->setText(QApplication::translate("adjust_energy", "\346\255\243\345\270\270\351\207\207\346\240\267", 0));
        count_num->setText(QApplication::translate("adjust_energy", "\350\256\241\347\256\227\347\263\273\346\225\260", 0));
        init_num->setText(QApplication::translate("adjust_energy", "\345\210\235\345\247\213\345\214\226\347\263\273\346\225\260", 0));
        stop_adjust->setText(QApplication::translate("adjust_energy", "\347\273\223\346\235\237\346\240\241\345\207\206", 0));
        stop_out->setText(QApplication::translate("adjust_energy", "\345\201\234\346\255\242\350\276\223\345\207\272", 0));
        read_old_num->setText(QApplication::translate("adjust_energy", "\350\257\273\345\217\226\345\216\237\347\263\273\346\225\260", 0));
        init_std_value->setText(QApplication::translate("adjust_energy", "\345\210\235\345\247\213\345\214\226\346\240\207\345\207\206\345\200\274", 0));
        write_num->setText(QApplication::translate("adjust_energy", "\345\206\231\345\205\245\347\263\273\346\225\260", 0));
        pushButton_13->setText(QApplication::translate("adjust_energy", "\345\257\274\345\205\245\346\240\241\345\207\206\347\263\273\346\225\260", 0));
        pushButton_14->setText(QApplication::translate("adjust_energy", "\345\257\274\345\207\272\346\240\241\345\207\206\347\263\273\346\225\260", 0));
        pushButton_12->setText(QApplication::translate("adjust_energy", "\350\260\220\346\263\242\346\240\241\345\207\206", 0));
    } // retranslateUi

};

namespace Ui {
    class adjust_energy: public Ui_adjust_energy {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADJUST_ENERGY_H
