/********************************************************************************
** Form generated from reading UI file 'config_set.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIG_SET_H
#define UI_CONFIG_SET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "m_spinbox.h"

QT_BEGIN_NAMESPACE

class Ui_Config_set
{
public:
    QGridLayout *gridLayout_5;
    QVBoxLayout *verticalLayout_18;
    QFrame *frame_5;
    QGridLayout *gridLayout_3;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_20;
    QFrame *frame;
    QGridLayout *gridLayout_6;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_7;
    QCheckBox *net;
    QCheckBox *serial;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_6;
    QSpinBox *spinBox;
    QVBoxLayout *verticalLayout_4;
    QPushButton *close_btn;
    QSpacerItem *verticalSpacer;
    QPushButton *reset_btn;
    QPushButton *setStart;
    QPushButton *pushButton;
    QFrame *frame_3;
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout_17;
    QLabel *label_9;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_21;
    QComboBox *com_name;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_22;
    M_spinbox *baud;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_23;
    M_spinbox *check_byte;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_24;
    M_spinbox *stop_byte;
    QHBoxLayout *horizontalLayout_19;
    QPushButton *connect_dis;
    QFrame *frame_6;
    QGridLayout *gridLayout_7;
    QVBoxLayout *verticalLayout_19;
    QLabel *label_8;
    QHBoxLayout *horizontalLayout_21;
    QLabel *label_25;
    QComboBox *com_name_2;
    QHBoxLayout *horizontalLayout_22;
    QLabel *label_26;
    M_spinbox *baud_2;
    QHBoxLayout *horizontalLayout_23;
    QLabel *label_27;
    M_spinbox *check_byte_2;
    QHBoxLayout *horizontalLayout_24;
    QLabel *label_28;
    M_spinbox *stop_byte_2;
    QHBoxLayout *horizontalLayout_25;
    QPushButton *connect_dis_2;
    QFrame *frame_2;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    M_spinbox *desc;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QFrame *frame_4;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *mac;
    QLineEdit *mac_2;
    QLineEdit *mac_3;
    QLineEdit *mac_4;
    QLineEdit *mac_5;
    QLineEdit *mac_6;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpinBox *byte_out;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *cpu_version;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *set_mac;
    QPushButton *reset_cpu;
    QPushButton *net_connect;
    QButtonGroup *buttonGroup;

    void setupUi(QWidget *Config_set)
    {
        if (Config_set->objectName().isEmpty())
            Config_set->setObjectName(QStringLiteral("Config_set"));
        Config_set->resize(750, 500);
        gridLayout_5 = new QGridLayout(Config_set);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        verticalLayout_18 = new QVBoxLayout();
        verticalLayout_18->setObjectName(QStringLiteral("verticalLayout_18"));
        frame_5 = new QFrame(Config_set);
        frame_5->setObjectName(QStringLiteral("frame_5"));
        frame_5->setFrameShape(QFrame::Box);
        frame_5->setFrameShadow(QFrame::Raised);
        frame_5->setLineWidth(2);
        gridLayout_3 = new QGridLayout(frame_5);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(frame_5);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_3->addWidget(label_5, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 0, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 0, 2, 1, 2);

        gridLayout_3->setColumnStretch(0, 1);
        gridLayout_3->setColumnStretch(1, 2);
        gridLayout_3->setColumnStretch(2, 1);

        verticalLayout_18->addWidget(frame_5);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setSpacing(2);
        horizontalLayout_20->setObjectName(QStringLiteral("horizontalLayout_20"));
        frame = new QFrame(Config_set);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        frame->setLineWidth(2);
        gridLayout_6 = new QGridLayout(frame);
        gridLayout_6->setSpacing(2);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_6->setContentsMargins(2, 2, 2, 2);
        label_7 = new QLabel(frame);
        label_7->setObjectName(QStringLiteral("label_7"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);
        label_7->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_7, 0, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        net = new QCheckBox(frame);
        net->setObjectName(QStringLiteral("net"));
        QFont font;
        font.setPointSize(11);
        net->setFont(font);

        horizontalLayout_7->addWidget(net);

        serial = new QCheckBox(frame);
        serial->setObjectName(QStringLiteral("serial"));
        serial->setFont(font);
        serial->setChecked(true);

        horizontalLayout_7->addWidget(serial);


        gridLayout_6->addLayout(horizontalLayout_7, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, -1, 5, -1);
        label_6 = new QLabel(frame);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_2->addWidget(label_6);

        spinBox = new QSpinBox(frame);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(spinBox->sizePolicy().hasHeightForWidth());
        spinBox->setSizePolicy(sizePolicy1);
        spinBox->setValue(12);

        horizontalLayout_2->addWidget(spinBox);


        gridLayout_6->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(2);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        close_btn = new QPushButton(frame);
        close_btn->setObjectName(QStringLiteral("close_btn"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(close_btn->sizePolicy().hasHeightForWidth());
        close_btn->setSizePolicy(sizePolicy2);
        close_btn->setStyleSheet(QLatin1String("background-color: rgb(255, 85, 0);\n"
"color: rgb(0, 0, 0);"));

        verticalLayout_4->addWidget(close_btn);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        reset_btn = new QPushButton(frame);
        reset_btn->setObjectName(QStringLiteral("reset_btn"));
        sizePolicy2.setHeightForWidth(reset_btn->sizePolicy().hasHeightForWidth());
        reset_btn->setSizePolicy(sizePolicy2);
        reset_btn->setStyleSheet(QStringLiteral(""));

        verticalLayout_4->addWidget(reset_btn);

        setStart = new QPushButton(frame);
        setStart->setObjectName(QStringLiteral("setStart"));
        sizePolicy2.setHeightForWidth(setStart->sizePolicy().hasHeightForWidth());
        setStart->setSizePolicy(sizePolicy2);

        verticalLayout_4->addWidget(setStart);

        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        sizePolicy2.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy2);

        verticalLayout_4->addWidget(pushButton);


        gridLayout_6->addLayout(verticalLayout_4, 3, 0, 1, 1);


        horizontalLayout_20->addWidget(frame);

        frame_3 = new QFrame(Config_set);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Preferred);
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
        verticalLayout_17 = new QVBoxLayout();
        verticalLayout_17->setSpacing(2);
        verticalLayout_17->setObjectName(QStringLiteral("verticalLayout_17"));
        verticalLayout_17->setContentsMargins(-1, 5, -1, 5);
        label_9 = new QLabel(frame_3);
        label_9->setObjectName(QStringLiteral("label_9"));

        verticalLayout_17->addWidget(label_9);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(2);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        label_21 = new QLabel(frame_3);
        label_21->setObjectName(QStringLiteral("label_21"));
        sizePolicy2.setHeightForWidth(label_21->sizePolicy().hasHeightForWidth());
        label_21->setSizePolicy(sizePolicy2);

        horizontalLayout_15->addWidget(label_21);

        com_name = new QComboBox(frame_3);
        com_name->setObjectName(QStringLiteral("com_name"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(com_name->sizePolicy().hasHeightForWidth());
        com_name->setSizePolicy(sizePolicy4);

        horizontalLayout_15->addWidget(com_name);

        horizontalLayout_15->setStretch(0, 1);
        horizontalLayout_15->setStretch(1, 2);

        verticalLayout_17->addLayout(horizontalLayout_15);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(2);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        label_22 = new QLabel(frame_3);
        label_22->setObjectName(QStringLiteral("label_22"));
        sizePolicy2.setHeightForWidth(label_22->sizePolicy().hasHeightForWidth());
        label_22->setSizePolicy(sizePolicy2);

        horizontalLayout_16->addWidget(label_22);

        baud = new M_spinbox(frame_3);
        baud->setObjectName(QStringLiteral("baud"));
        sizePolicy2.setHeightForWidth(baud->sizePolicy().hasHeightForWidth());
        baud->setSizePolicy(sizePolicy2);

        horizontalLayout_16->addWidget(baud);

        horizontalLayout_16->setStretch(0, 1);
        horizontalLayout_16->setStretch(1, 2);

        verticalLayout_17->addLayout(horizontalLayout_16);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(2);
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        label_23 = new QLabel(frame_3);
        label_23->setObjectName(QStringLiteral("label_23"));
        sizePolicy2.setHeightForWidth(label_23->sizePolicy().hasHeightForWidth());
        label_23->setSizePolicy(sizePolicy2);

        horizontalLayout_17->addWidget(label_23);

        check_byte = new M_spinbox(frame_3);
        check_byte->setObjectName(QStringLiteral("check_byte"));
        sizePolicy2.setHeightForWidth(check_byte->sizePolicy().hasHeightForWidth());
        check_byte->setSizePolicy(sizePolicy2);

        horizontalLayout_17->addWidget(check_byte);

        horizontalLayout_17->setStretch(0, 1);
        horizontalLayout_17->setStretch(1, 2);

        verticalLayout_17->addLayout(horizontalLayout_17);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(2);
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        label_24 = new QLabel(frame_3);
        label_24->setObjectName(QStringLiteral("label_24"));
        sizePolicy2.setHeightForWidth(label_24->sizePolicy().hasHeightForWidth());
        label_24->setSizePolicy(sizePolicy2);

        horizontalLayout_18->addWidget(label_24);

        stop_byte = new M_spinbox(frame_3);
        stop_byte->setObjectName(QStringLiteral("stop_byte"));
        sizePolicy2.setHeightForWidth(stop_byte->sizePolicy().hasHeightForWidth());
        stop_byte->setSizePolicy(sizePolicy2);

        horizontalLayout_18->addWidget(stop_byte);

        horizontalLayout_18->setStretch(0, 1);
        horizontalLayout_18->setStretch(1, 2);

        verticalLayout_17->addLayout(horizontalLayout_18);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        connect_dis = new QPushButton(frame_3);
        buttonGroup = new QButtonGroup(Config_set);
        buttonGroup->setObjectName(QStringLiteral("buttonGroup"));
        buttonGroup->addButton(connect_dis);
        connect_dis->setObjectName(QStringLiteral("connect_dis"));
        sizePolicy2.setHeightForWidth(connect_dis->sizePolicy().hasHeightForWidth());
        connect_dis->setSizePolicy(sizePolicy2);
        connect_dis->setCheckable(true);

        horizontalLayout_19->addWidget(connect_dis);


        verticalLayout_17->addLayout(horizontalLayout_19);


        gridLayout_4->addLayout(verticalLayout_17, 0, 0, 1, 1);


        horizontalLayout_20->addWidget(frame_3);

        frame_6 = new QFrame(Config_set);
        frame_6->setObjectName(QStringLiteral("frame_6"));
        sizePolicy3.setHeightForWidth(frame_6->sizePolicy().hasHeightForWidth());
        frame_6->setSizePolicy(sizePolicy3);
        frame_6->setFrameShape(QFrame::Box);
        frame_6->setFrameShadow(QFrame::Raised);
        frame_6->setLineWidth(2);
        gridLayout_7 = new QGridLayout(frame_6);
        gridLayout_7->setSpacing(2);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        gridLayout_7->setContentsMargins(2, 2, 2, 2);
        verticalLayout_19 = new QVBoxLayout();
        verticalLayout_19->setSpacing(2);
        verticalLayout_19->setObjectName(QStringLiteral("verticalLayout_19"));
        verticalLayout_19->setContentsMargins(-1, 5, -1, 5);
        label_8 = new QLabel(frame_6);
        label_8->setObjectName(QStringLiteral("label_8"));

        verticalLayout_19->addWidget(label_8);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setSpacing(2);
        horizontalLayout_21->setObjectName(QStringLiteral("horizontalLayout_21"));
        label_25 = new QLabel(frame_6);
        label_25->setObjectName(QStringLiteral("label_25"));
        sizePolicy2.setHeightForWidth(label_25->sizePolicy().hasHeightForWidth());
        label_25->setSizePolicy(sizePolicy2);

        horizontalLayout_21->addWidget(label_25);

        com_name_2 = new QComboBox(frame_6);
        com_name_2->setObjectName(QStringLiteral("com_name_2"));
        sizePolicy4.setHeightForWidth(com_name_2->sizePolicy().hasHeightForWidth());
        com_name_2->setSizePolicy(sizePolicy4);

        horizontalLayout_21->addWidget(com_name_2);

        horizontalLayout_21->setStretch(0, 1);
        horizontalLayout_21->setStretch(1, 2);

        verticalLayout_19->addLayout(horizontalLayout_21);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setSpacing(2);
        horizontalLayout_22->setObjectName(QStringLiteral("horizontalLayout_22"));
        label_26 = new QLabel(frame_6);
        label_26->setObjectName(QStringLiteral("label_26"));
        sizePolicy2.setHeightForWidth(label_26->sizePolicy().hasHeightForWidth());
        label_26->setSizePolicy(sizePolicy2);

        horizontalLayout_22->addWidget(label_26);

        baud_2 = new M_spinbox(frame_6);
        baud_2->setObjectName(QStringLiteral("baud_2"));
        sizePolicy2.setHeightForWidth(baud_2->sizePolicy().hasHeightForWidth());
        baud_2->setSizePolicy(sizePolicy2);

        horizontalLayout_22->addWidget(baud_2);

        horizontalLayout_22->setStretch(0, 1);
        horizontalLayout_22->setStretch(1, 2);

        verticalLayout_19->addLayout(horizontalLayout_22);

        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setSpacing(2);
        horizontalLayout_23->setObjectName(QStringLiteral("horizontalLayout_23"));
        label_27 = new QLabel(frame_6);
        label_27->setObjectName(QStringLiteral("label_27"));
        sizePolicy2.setHeightForWidth(label_27->sizePolicy().hasHeightForWidth());
        label_27->setSizePolicy(sizePolicy2);

        horizontalLayout_23->addWidget(label_27);

        check_byte_2 = new M_spinbox(frame_6);
        check_byte_2->setObjectName(QStringLiteral("check_byte_2"));
        sizePolicy2.setHeightForWidth(check_byte_2->sizePolicy().hasHeightForWidth());
        check_byte_2->setSizePolicy(sizePolicy2);

        horizontalLayout_23->addWidget(check_byte_2);

        horizontalLayout_23->setStretch(0, 1);
        horizontalLayout_23->setStretch(1, 2);

        verticalLayout_19->addLayout(horizontalLayout_23);

        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setSpacing(2);
        horizontalLayout_24->setObjectName(QStringLiteral("horizontalLayout_24"));
        label_28 = new QLabel(frame_6);
        label_28->setObjectName(QStringLiteral("label_28"));
        sizePolicy2.setHeightForWidth(label_28->sizePolicy().hasHeightForWidth());
        label_28->setSizePolicy(sizePolicy2);

        horizontalLayout_24->addWidget(label_28);

        stop_byte_2 = new M_spinbox(frame_6);
        stop_byte_2->setObjectName(QStringLiteral("stop_byte_2"));
        sizePolicy2.setHeightForWidth(stop_byte_2->sizePolicy().hasHeightForWidth());
        stop_byte_2->setSizePolicy(sizePolicy2);

        horizontalLayout_24->addWidget(stop_byte_2);

        horizontalLayout_24->setStretch(0, 1);
        horizontalLayout_24->setStretch(1, 2);

        verticalLayout_19->addLayout(horizontalLayout_24);

        horizontalLayout_25 = new QHBoxLayout();
        horizontalLayout_25->setObjectName(QStringLiteral("horizontalLayout_25"));
        connect_dis_2 = new QPushButton(frame_6);
        connect_dis_2->setObjectName(QStringLiteral("connect_dis_2"));
        sizePolicy2.setHeightForWidth(connect_dis_2->sizePolicy().hasHeightForWidth());
        connect_dis_2->setSizePolicy(sizePolicy2);
        connect_dis_2->setCheckable(true);

        horizontalLayout_25->addWidget(connect_dis_2);


        verticalLayout_19->addLayout(horizontalLayout_25);


        gridLayout_7->addLayout(verticalLayout_19, 0, 0, 1, 1);


        horizontalLayout_20->addWidget(frame_6);

        frame_2 = new QFrame(Config_set);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::Box);
        frame_2->setFrameShadow(QFrame::Raised);
        frame_2->setLineWidth(2);
        gridLayout_2 = new QGridLayout(frame_2);
        gridLayout_2->setSpacing(2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(2, 2, 2, 2);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(-1, 5, -1, 5);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(frame_2);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        desc = new M_spinbox(frame_2);
        desc->setObjectName(QStringLiteral("desc"));
        sizePolicy1.setHeightForWidth(desc->sizePolicy().hasHeightForWidth());
        desc->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(desc);


        verticalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy2);

        verticalLayout_2->addWidget(label_2);

        frame_4 = new QFrame(frame_2);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setFrameShape(QFrame::Box);
        frame_4->setFrameShadow(QFrame::Raised);
        frame_4->setLineWidth(2);
        gridLayout = new QGridLayout(frame_4);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        mac = new QLineEdit(frame_4);
        mac->setObjectName(QStringLiteral("mac"));
        sizePolicy2.setHeightForWidth(mac->sizePolicy().hasHeightForWidth());
        mac->setSizePolicy(sizePolicy2);
        mac->setMaxLength(2);
        mac->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(mac);

        mac_2 = new QLineEdit(frame_4);
        mac_2->setObjectName(QStringLiteral("mac_2"));
        sizePolicy2.setHeightForWidth(mac_2->sizePolicy().hasHeightForWidth());
        mac_2->setSizePolicy(sizePolicy2);
        mac_2->setMaxLength(2);
        mac_2->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(mac_2);

        mac_3 = new QLineEdit(frame_4);
        mac_3->setObjectName(QStringLiteral("mac_3"));
        sizePolicy2.setHeightForWidth(mac_3->sizePolicy().hasHeightForWidth());
        mac_3->setSizePolicy(sizePolicy2);
        mac_3->setMaxLength(2);
        mac_3->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(mac_3);

        mac_4 = new QLineEdit(frame_4);
        mac_4->setObjectName(QStringLiteral("mac_4"));
        sizePolicy2.setHeightForWidth(mac_4->sizePolicy().hasHeightForWidth());
        mac_4->setSizePolicy(sizePolicy2);
        mac_4->setMaxLength(2);
        mac_4->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(mac_4);

        mac_5 = new QLineEdit(frame_4);
        mac_5->setObjectName(QStringLiteral("mac_5"));
        sizePolicy2.setHeightForWidth(mac_5->sizePolicy().hasHeightForWidth());
        mac_5->setSizePolicy(sizePolicy2);
        mac_5->setMaxLength(2);
        mac_5->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(mac_5);

        mac_6 = new QLineEdit(frame_4);
        mac_6->setObjectName(QStringLiteral("mac_6"));
        sizePolicy2.setHeightForWidth(mac_6->sizePolicy().hasHeightForWidth());
        mac_6->setSizePolicy(sizePolicy2);
        mac_6->setMaxLength(2);
        mac_6->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(mac_6);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        verticalLayout_2->addWidget(frame_4);


        verticalLayout_3->addLayout(verticalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(2);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(frame_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        byte_out = new QSpinBox(frame_2);
        byte_out->setObjectName(QStringLiteral("byte_out"));
        sizePolicy2.setHeightForWidth(byte_out->sizePolicy().hasHeightForWidth());
        byte_out->setSizePolicy(sizePolicy2);
        byte_out->setMaximum(9999999);
        byte_out->setValue(300);

        horizontalLayout_3->addWidget(byte_out);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(2);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(frame_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        cpu_version = new QLineEdit(frame_2);
        cpu_version->setObjectName(QStringLiteral("cpu_version"));
        sizePolicy2.setHeightForWidth(cpu_version->sizePolicy().hasHeightForWidth());
        cpu_version->setSizePolicy(sizePolicy2);

        horizontalLayout_4->addWidget(cpu_version);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 1);

        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(2);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        set_mac = new QPushButton(frame_2);
        set_mac->setObjectName(QStringLiteral("set_mac"));
        sizePolicy2.setHeightForWidth(set_mac->sizePolicy().hasHeightForWidth());
        set_mac->setSizePolicy(sizePolicy2);

        horizontalLayout_5->addWidget(set_mac);

        reset_cpu = new QPushButton(frame_2);
        reset_cpu->setObjectName(QStringLiteral("reset_cpu"));
        sizePolicy2.setHeightForWidth(reset_cpu->sizePolicy().hasHeightForWidth());
        reset_cpu->setSizePolicy(sizePolicy2);

        horizontalLayout_5->addWidget(reset_cpu);


        verticalLayout_3->addLayout(horizontalLayout_5);

        net_connect = new QPushButton(frame_2);
        buttonGroup->addButton(net_connect);
        net_connect->setObjectName(QStringLiteral("net_connect"));
        sizePolicy2.setHeightForWidth(net_connect->sizePolicy().hasHeightForWidth());
        net_connect->setSizePolicy(sizePolicy2);
        net_connect->setCheckable(true);

        verticalLayout_3->addWidget(net_connect);

        verticalLayout_3->setStretch(0, 1);
        verticalLayout_3->setStretch(1, 1);
        verticalLayout_3->setStretch(2, 1);
        verticalLayout_3->setStretch(3, 1);
        verticalLayout_3->setStretch(4, 1);
        verticalLayout_3->setStretch(5, 1);

        gridLayout_2->addLayout(verticalLayout_3, 1, 0, 1, 1);


        horizontalLayout_20->addWidget(frame_2);

        horizontalLayout_20->setStretch(0, 1);
        horizontalLayout_20->setStretch(3, 1);

        verticalLayout_18->addLayout(horizontalLayout_20);

        verticalLayout_18->setStretch(0, 1);
        verticalLayout_18->setStretch(1, 1);

        gridLayout_5->addLayout(verticalLayout_18, 0, 0, 1, 1);


        retranslateUi(Config_set);

        QMetaObject::connectSlotsByName(Config_set);
    } // setupUi

    void retranslateUi(QWidget *Config_set)
    {
        Config_set->setWindowTitle(QApplication::translate("Config_set", "Form", 0));
        label_5->setText(QString());
        label_7->setText(QApplication::translate("Config_set", "\351\200\232\344\277\241\350\256\276\347\275\256", 0));
        net->setText(QApplication::translate("Config_set", "\344\275\277\347\224\250\347\275\221\345\217\243", 0));
        serial->setText(QApplication::translate("Config_set", "\344\275\277\347\224\250\344\270\262\345\217\243", 0));
        label_6->setText(QApplication::translate("Config_set", "\351\200\232\344\277\241\350\266\205\346\227\266\346\227\266\351\227\264", 0));
        spinBox->setSuffix(QApplication::translate("Config_set", "s", 0));
        close_btn->setText(QApplication::translate("Config_set", "\345\205\263\351\227\255\347\250\213\345\272\217", 0));
        reset_btn->setText(QApplication::translate("Config_set", "\347\252\227\345\217\243\345\214\226", 0));
        setStart->setText(QApplication::translate("Config_set", "\350\256\276\347\275\256\345\274\200\346\234\272\345\220\257\345\212\250", 0));
        pushButton->setText(QApplication::translate("Config_set", "\346\233\264\346\226\260\350\256\276\347\275\256", 0));
        label_9->setText(QApplication::translate("Config_set", "\344\270\262\345\217\243\351\205\215\347\275\256", 0));
        label_21->setText(QApplication::translate("Config_set", "\344\270\262\345\217\243\345\217\267", 0));
        label_22->setText(QApplication::translate("Config_set", "\346\263\242\347\211\271\347\216\207", 0));
        label_23->setText(QApplication::translate("Config_set", "\346\240\241\351\252\214\344\275\215", 0));
        label_24->setText(QApplication::translate("Config_set", "\345\201\234\346\255\242\344\275\215", 0));
        connect_dis->setText(QApplication::translate("Config_set", "\350\277\236\346\216\245", 0));
        label_8->setText(QApplication::translate("Config_set", "\344\272\214\346\254\241\345\274\200\345\217\221\351\205\215\347\275\256", 0));
        label_25->setText(QApplication::translate("Config_set", "\344\270\262\345\217\243\345\217\267", 0));
        label_26->setText(QApplication::translate("Config_set", "\346\263\242\347\211\271\347\216\207", 0));
        label_27->setText(QApplication::translate("Config_set", "\346\240\241\351\252\214\344\275\215", 0));
        label_28->setText(QApplication::translate("Config_set", "\345\201\234\346\255\242\344\275\215", 0));
        connect_dis_2->setText(QApplication::translate("Config_set", "\350\277\236\346\216\245", 0));
        label->setText(QApplication::translate("Config_set", "\347\275\221\345\215\241\351\200\211\346\213\251", 0));
        label_2->setText(QApplication::translate("Config_set", "\347\233\256\347\232\204MAC\345\234\260\345\235\200:", 0));
        mac->setText(QApplication::translate("Config_set", "AA", 0));
        mac_2->setText(QApplication::translate("Config_set", "BB", 0));
        mac_3->setText(QApplication::translate("Config_set", "CC", 0));
        mac_4->setText(QApplication::translate("Config_set", "DD", 0));
        mac_5->setText(QApplication::translate("Config_set", "EE", 0));
        mac_6->setText(QApplication::translate("Config_set", "FF", 0));
        label_3->setText(QApplication::translate("Config_set", "\345\270\247\345\273\266\346\227\266(\345\276\256\347\247\222)", 0));
        label_4->setText(QApplication::translate("Config_set", "CPU\347\211\210\346\234\254", 0));
        set_mac->setText(QApplication::translate("Config_set", "\350\256\276\347\275\256MAC\345\234\260\345\235\200", 0));
        reset_cpu->setText(QApplication::translate("Config_set", "CPU\345\244\215\344\275\215", 0));
        net_connect->setText(QApplication::translate("Config_set", "\350\277\236\346\216\245", 0));
    } // retranslateUi

};

namespace Ui {
    class Config_set: public Ui_Config_set {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIG_SET_H
