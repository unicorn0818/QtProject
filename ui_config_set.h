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
#include <QtWidgets/QTextEdit>
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
    QLabel *label_3;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout_20;
    QFrame *frame;
    QGridLayout *gridLayout_6;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *net;
    QCheckBox *serial;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_6;
    QSpinBox *spinBox;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *read_gear;
    QPushButton *init_cpu;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *reset_window;
    QPushButton *btn_close;
    QPushButton *pushButton;
    QFrame *frame_2;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_4;
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
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer;
    QPushButton *net_connect;
    QFrame *frame_3;
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout_17;
    QLabel *label_5;
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
    QButtonGroup *buttonGroup;

    void setupUi(QWidget *Config_set)
    {
        if (Config_set->objectName().isEmpty())
            Config_set->setObjectName(QStringLiteral("Config_set"));
        Config_set->resize(750, 500);
        gridLayout_5 = new QGridLayout(Config_set);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        verticalLayout_18 = new QVBoxLayout();
        verticalLayout_18->setSpacing(2);
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
        label_3 = new QLabel(frame_5);
        label_3->setObjectName(QStringLiteral("label_3"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(label_3, 1, 0, 1, 1);

        textEdit = new QTextEdit(frame_5);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setReadOnly(true);

        gridLayout_3->addWidget(textEdit, 1, 1, 1, 1);

        gridLayout_3->setColumnStretch(0, 1);
        gridLayout_3->setColumnStretch(1, 1);

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
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        net = new QCheckBox(frame);
        buttonGroup = new QButtonGroup(Config_set);
        buttonGroup->setObjectName(QStringLiteral("buttonGroup"));
        buttonGroup->addButton(net);
        net->setObjectName(QStringLiteral("net"));
        sizePolicy.setHeightForWidth(net->sizePolicy().hasHeightForWidth());
        net->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(12);
        net->setFont(font);

        horizontalLayout_3->addWidget(net);

        serial = new QCheckBox(frame);
        buttonGroup->addButton(serial);
        serial->setObjectName(QStringLiteral("serial"));
        sizePolicy.setHeightForWidth(serial->sizePolicy().hasHeightForWidth());
        serial->setSizePolicy(sizePolicy);
        serial->setFont(font);
        serial->setChecked(true);

        horizontalLayout_3->addWidget(serial);


        gridLayout_6->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        label_7 = new QLabel(frame);
        label_7->setObjectName(QStringLiteral("label_7"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy1);
        label_7->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_7, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, -1, 5, -1);
        label_6 = new QLabel(frame);
        label_6->setObjectName(QStringLiteral("label_6"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy2);

        horizontalLayout_2->addWidget(label_6);

        spinBox = new QSpinBox(frame);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        sizePolicy.setHeightForWidth(spinBox->sizePolicy().hasHeightForWidth());
        spinBox->setSizePolicy(sizePolicy);
        spinBox->setValue(10);

        horizontalLayout_2->addWidget(spinBox);


        gridLayout_6->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(2);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        read_gear = new QPushButton(frame);
        read_gear->setObjectName(QStringLiteral("read_gear"));
        sizePolicy.setHeightForWidth(read_gear->sizePolicy().hasHeightForWidth());
        read_gear->setSizePolicy(sizePolicy);

        horizontalLayout_6->addWidget(read_gear);

        init_cpu = new QPushButton(frame);
        init_cpu->setObjectName(QStringLiteral("init_cpu"));
        sizePolicy.setHeightForWidth(init_cpu->sizePolicy().hasHeightForWidth());
        init_cpu->setSizePolicy(sizePolicy);

        horizontalLayout_6->addWidget(init_cpu);


        gridLayout_6->addLayout(horizontalLayout_6, 6, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(2);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        reset_window = new QPushButton(frame);
        reset_window->setObjectName(QStringLiteral("reset_window"));
        sizePolicy.setHeightForWidth(reset_window->sizePolicy().hasHeightForWidth());
        reset_window->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(reset_window);

        btn_close = new QPushButton(frame);
        btn_close->setObjectName(QStringLiteral("btn_close"));
        sizePolicy.setHeightForWidth(btn_close->sizePolicy().hasHeightForWidth());
        btn_close->setSizePolicy(sizePolicy);
        btn_close->setStyleSheet(QLatin1String("background-color: rgb(255, 85, 0);\n"
"color: rgb(0, 0, 0);"));

        horizontalLayout_4->addWidget(btn_close);


        gridLayout_6->addLayout(horizontalLayout_4, 5, 0, 1, 1);

        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);

        gridLayout_6->addWidget(pushButton, 3, 0, 1, 1);


        horizontalLayout_20->addWidget(frame);

        frame_2 = new QFrame(Config_set);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::Box);
        frame_2->setFrameShadow(QFrame::Raised);
        frame_2->setLineWidth(2);
        gridLayout_2 = new QGridLayout(frame_2);
        gridLayout_2->setSpacing(2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(2, 2, 2, 2);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(2);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(-1, 5, -1, 5);
        label_4 = new QLabel(frame_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_5->addWidget(label_4);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(frame_2);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        desc = new M_spinbox(frame_2);
        desc->setObjectName(QStringLiteral("desc"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(desc->sizePolicy().hasHeightForWidth());
        desc->setSizePolicy(sizePolicy3);

        verticalLayout->addWidget(desc);


        verticalLayout_5->addLayout(verticalLayout);

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
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(frame_4->sizePolicy().hasHeightForWidth());
        frame_4->setSizePolicy(sizePolicy4);
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
        sizePolicy.setHeightForWidth(mac->sizePolicy().hasHeightForWidth());
        mac->setSizePolicy(sizePolicy);
        mac->setMaxLength(2);
        mac->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(mac);

        mac_2 = new QLineEdit(frame_4);
        mac_2->setObjectName(QStringLiteral("mac_2"));
        sizePolicy.setHeightForWidth(mac_2->sizePolicy().hasHeightForWidth());
        mac_2->setSizePolicy(sizePolicy);
        mac_2->setMaxLength(2);
        mac_2->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(mac_2);

        mac_3 = new QLineEdit(frame_4);
        mac_3->setObjectName(QStringLiteral("mac_3"));
        sizePolicy.setHeightForWidth(mac_3->sizePolicy().hasHeightForWidth());
        mac_3->setSizePolicy(sizePolicy);
        mac_3->setMaxLength(2);
        mac_3->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(mac_3);

        mac_4 = new QLineEdit(frame_4);
        mac_4->setObjectName(QStringLiteral("mac_4"));
        sizePolicy.setHeightForWidth(mac_4->sizePolicy().hasHeightForWidth());
        mac_4->setSizePolicy(sizePolicy);
        mac_4->setMaxLength(2);
        mac_4->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(mac_4);

        mac_5 = new QLineEdit(frame_4);
        mac_5->setObjectName(QStringLiteral("mac_5"));
        sizePolicy.setHeightForWidth(mac_5->sizePolicy().hasHeightForWidth());
        mac_5->setSizePolicy(sizePolicy);
        mac_5->setMaxLength(2);
        mac_5->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(mac_5);

        mac_6 = new QLineEdit(frame_4);
        mac_6->setObjectName(QStringLiteral("mac_6"));
        sizePolicy.setHeightForWidth(mac_6->sizePolicy().hasHeightForWidth());
        mac_6->setSizePolicy(sizePolicy);
        mac_6->setMaxLength(2);
        mac_6->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(mac_6);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        verticalLayout_2->addWidget(frame_4);


        verticalLayout_5->addLayout(verticalLayout_2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);

        net_connect = new QPushButton(frame_2);
        net_connect->setObjectName(QStringLiteral("net_connect"));
        sizePolicy.setHeightForWidth(net_connect->sizePolicy().hasHeightForWidth());
        net_connect->setSizePolicy(sizePolicy);
        net_connect->setCheckable(true);

        verticalLayout_5->addWidget(net_connect);

        verticalLayout_5->setStretch(1, 1);
        verticalLayout_5->setStretch(2, 1);
        verticalLayout_5->setStretch(3, 1);
        verticalLayout_5->setStretch(4, 1);
        verticalLayout_5->setStretch(5, 1);

        gridLayout_2->addLayout(verticalLayout_5, 0, 0, 1, 1);


        horizontalLayout_20->addWidget(frame_2);

        frame_3 = new QFrame(Config_set);
        frame_3->setObjectName(QStringLiteral("frame_3"));
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
        label_5 = new QLabel(frame_3);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_17->addWidget(label_5);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(2);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        label_21 = new QLabel(frame_3);
        label_21->setObjectName(QStringLiteral("label_21"));
        sizePolicy.setHeightForWidth(label_21->sizePolicy().hasHeightForWidth());
        label_21->setSizePolicy(sizePolicy);

        horizontalLayout_15->addWidget(label_21);

        com_name = new QComboBox(frame_3);
        com_name->setObjectName(QStringLiteral("com_name"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(com_name->sizePolicy().hasHeightForWidth());
        com_name->setSizePolicy(sizePolicy5);

        horizontalLayout_15->addWidget(com_name);

        horizontalLayout_15->setStretch(0, 1);
        horizontalLayout_15->setStretch(1, 2);

        verticalLayout_17->addLayout(horizontalLayout_15);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(2);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        label_22 = new QLabel(frame_3);
        label_22->setObjectName(QStringLiteral("label_22"));
        sizePolicy.setHeightForWidth(label_22->sizePolicy().hasHeightForWidth());
        label_22->setSizePolicy(sizePolicy);

        horizontalLayout_16->addWidget(label_22);

        baud = new M_spinbox(frame_3);
        baud->setObjectName(QStringLiteral("baud"));
        sizePolicy.setHeightForWidth(baud->sizePolicy().hasHeightForWidth());
        baud->setSizePolicy(sizePolicy);

        horizontalLayout_16->addWidget(baud);

        horizontalLayout_16->setStretch(0, 1);
        horizontalLayout_16->setStretch(1, 2);

        verticalLayout_17->addLayout(horizontalLayout_16);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(2);
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        label_23 = new QLabel(frame_3);
        label_23->setObjectName(QStringLiteral("label_23"));
        sizePolicy.setHeightForWidth(label_23->sizePolicy().hasHeightForWidth());
        label_23->setSizePolicy(sizePolicy);

        horizontalLayout_17->addWidget(label_23);

        check_byte = new M_spinbox(frame_3);
        check_byte->setObjectName(QStringLiteral("check_byte"));
        sizePolicy.setHeightForWidth(check_byte->sizePolicy().hasHeightForWidth());
        check_byte->setSizePolicy(sizePolicy);

        horizontalLayout_17->addWidget(check_byte);

        horizontalLayout_17->setStretch(0, 1);
        horizontalLayout_17->setStretch(1, 2);

        verticalLayout_17->addLayout(horizontalLayout_17);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(2);
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        label_24 = new QLabel(frame_3);
        label_24->setObjectName(QStringLiteral("label_24"));
        sizePolicy.setHeightForWidth(label_24->sizePolicy().hasHeightForWidth());
        label_24->setSizePolicy(sizePolicy);

        horizontalLayout_18->addWidget(label_24);

        stop_byte = new M_spinbox(frame_3);
        stop_byte->setObjectName(QStringLiteral("stop_byte"));
        sizePolicy.setHeightForWidth(stop_byte->sizePolicy().hasHeightForWidth());
        stop_byte->setSizePolicy(sizePolicy);

        horizontalLayout_18->addWidget(stop_byte);

        horizontalLayout_18->setStretch(0, 1);
        horizontalLayout_18->setStretch(1, 2);

        verticalLayout_17->addLayout(horizontalLayout_18);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setSpacing(0);
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        connect_dis = new QPushButton(frame_3);
        connect_dis->setObjectName(QStringLiteral("connect_dis"));
        sizePolicy.setHeightForWidth(connect_dis->sizePolicy().hasHeightForWidth());
        connect_dis->setSizePolicy(sizePolicy);
        connect_dis->setCheckable(true);

        horizontalLayout_19->addWidget(connect_dis);

        horizontalLayout_19->setStretch(0, 2);

        verticalLayout_17->addLayout(horizontalLayout_19);

        verticalLayout_17->setStretch(1, 1);
        verticalLayout_17->setStretch(2, 1);
        verticalLayout_17->setStretch(3, 1);
        verticalLayout_17->setStretch(4, 1);
        verticalLayout_17->setStretch(5, 1);

        gridLayout_4->addLayout(verticalLayout_17, 0, 0, 1, 1);


        horizontalLayout_20->addWidget(frame_3);

        horizontalLayout_20->setStretch(0, 1);
        horizontalLayout_20->setStretch(1, 1);
        horizontalLayout_20->setStretch(2, 1);

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
        label_3->setText(QString());
        textEdit->setHtml(QApplication::translate("Config_set", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'SimSun';\"><br /></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-size:11pt; font-weight:600; color:#ff5500;\">\346\263\250\346\204\217\344\272\213\351\241\271</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun';\">1.\344\273\273\344\275\225\350\276\223\345\207\272\344"
                        "\270\215\350\246\201\346\267\273\345\212\240\347\233\264\346\265\201\345\210\206\351\207\217\357\274\201\357\274\201</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun';\">2.\345\237\272\346\263\242\350\276\223\345\207\272\344\270\255\347\232\204\347\224\265\346\265\201\350\256\276\347\275\256\357\274\214\347\224\261\344\272\216\350\257\245\346\272\220\344\270\272\347\224\265\345\216\213\346\272\220,\344\270\272\345\256\211\345\205\250\350\265\267\350\247\201\350\257\267\345\213\277\344\275\277\347\224\250\343\200\202</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun';\">3.\350\260\203\345\216\213\350\276\223\345\207\272\344\270\255\347\232\204\345\257\274\345\205\245\351\242\221\347\216\207\346\226\207\344\273\266\346\216\250\350\215\220\344\275\277\347\224\250csv\346\240"
                        "\274\345\274\217\357\274\214csv\346\240\274\345\274\217\346\225\260\346\215\256\345\257\274\345\205\245\351\200\237\345\272\246\346\234\200\345\277\253\357\274\214xlsx\346\254\241\344\271\213\357\274\214\345\205\266\344\273\226\346\226\207\344\273\266\346\240\274\345\274\217\351\234\200\345\256\211\350\243\205\346\234\211execl\347\273\204\344\273\266\357\274\214\345\271\266\344\270\224\345\257\274\345\205\245\350\276\203\346\205\242\343\200\202</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun';\">4.\345\212\250\346\200\201\350\276\223\345\207\272\351\241\265\351\235\242\344\270\255\347\232\204\347\224\237\346\210\220\346\263\242\345\275\242\346\230\257\344\276\235\346\215\256\350\257\245\347\233\270\347\232\204\345\205\254\345\274\217\347\224\237\346\210\220\347\232\204\343\200\202\344\275\277\347\224\250\347\224\237\346\210\220\345\205\250\351\203\250\346\263\242\345\275\242\346\227\266,"
                        "\351\234\200\346\263\250\346\204\217\345\205\266\344\273\226\347\233\270\347\232\204\346\263\242\345\275\242\344\277\241\346\201\257,\346\230\257\345\220\246\346\230\257\347\224\261\346\263\242\345\275\242\346\226\207\344\273\266\344\272\247\347\224\237\347\232\204\343\200\202\345\246\202\346\236\234\346\230\257,\345\210\231\345\205\266\346\263\242\345\275\242\344\274\232\350\242\253\350\246\206\347\233\226\346\216\211\343\200\202</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun';\">5.\346\224\271\345\217\230\351\207\207\346\240\267\347\216\207\345\220\216\351\234\200\351\207\215\346\226\260\347\224\237\346\210\220\346\263\242\345\275\242\346\226\271\345\217\257\347\224\237\346\225\210\357\274\214\345\233\240\344\270\272\346\263\242\345\275\242\346\225\260\346\215\256\344\277\241\346\201\257\346\230\257\345\234\250\347\224\237\346\210\220\346\263\242\345\275\242\346\227\266\345\206\263\345"
                        "\256\232\347\232\204\343\200\202</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun';\">6.\351\242\221\347\216\207\346\226\207\344\273\266\346\227\266\351\227\264\346\240\274\345\274\217\351\231\244\346\257\253\347\247\222\345\244\226\346\257\217\344\270\200\351\203\250\345\210\206\345\235\207\351\234\200\344\270\244\344\275\215\357\274\214\346\257\253\347\247\222\351\203\250\345\210\206\344\270\2723\344\275\215\343\200\202</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun';\">\345\246\202 00\357\274\23200\357\274\23200.000</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun';\">7.execl\346\226\207\344\273\266\344\273\205\350\257\273\345\217\226\347\254"
                        "\254\344\270\200\344\270\252\345\267\245\344\275\234\350\241\250\343\200\202</span></p></body></html>", 0));
        net->setText(QApplication::translate("Config_set", "\344\275\277\347\224\250\347\275\221\345\217\243", 0));
        serial->setText(QApplication::translate("Config_set", "\344\275\277\347\224\250\344\270\262\345\217\243", 0));
        label_7->setText(QApplication::translate("Config_set", "\351\200\232\344\277\241\350\256\276\347\275\256", 0));
        label_6->setText(QApplication::translate("Config_set", "\351\200\232\344\277\241\350\266\205\346\227\266\346\227\266\351\227\264", 0));
        spinBox->setSuffix(QApplication::translate("Config_set", "s", 0));
        read_gear->setText(QApplication::translate("Config_set", "\350\257\273\345\217\226\346\241\243\344\275\215\351\205\215\347\275\256", 0));
        init_cpu->setText(QApplication::translate("Config_set", "CPU\345\244\215\344\275\215", 0));
        reset_window->setText(QApplication::translate("Config_set", "\347\252\227\345\217\243\345\214\226", 0));
        btn_close->setText(QApplication::translate("Config_set", "\345\205\263\351\227\255\347\250\213\345\272\217", 0));
        pushButton->setText(QApplication::translate("Config_set", "\346\233\264\346\226\260\350\256\276\347\275\256", 0));
        label_4->setText(QApplication::translate("Config_set", "\347\275\221\345\217\243\351\205\215\347\275\256\357\274\232", 0));
        label->setText(QApplication::translate("Config_set", "\347\275\221\345\215\241\351\200\211\346\213\251", 0));
        label_2->setText(QApplication::translate("Config_set", "\347\233\256\347\232\204MAC\345\234\260\345\235\200:", 0));
        mac->setText(QApplication::translate("Config_set", "AA", 0));
        mac_2->setText(QApplication::translate("Config_set", "BB", 0));
        mac_3->setText(QApplication::translate("Config_set", "CC", 0));
        mac_4->setText(QApplication::translate("Config_set", "DD", 0));
        mac_5->setText(QApplication::translate("Config_set", "EE", 0));
        mac_6->setText(QApplication::translate("Config_set", "FF", 0));
        net_connect->setText(QApplication::translate("Config_set", "\350\277\236\346\216\245", 0));
        label_5->setText(QApplication::translate("Config_set", "\344\270\262\345\217\243\351\205\215\347\275\256\357\274\232", 0));
        label_21->setText(QApplication::translate("Config_set", "\344\270\262\345\217\243\345\217\267", 0));
        label_22->setText(QApplication::translate("Config_set", "\346\263\242\347\211\271\347\216\207", 0));
        label_23->setText(QApplication::translate("Config_set", "\346\240\241\351\252\214\344\275\215", 0));
        label_24->setText(QApplication::translate("Config_set", "\345\201\234\346\255\242\344\275\215", 0));
        connect_dis->setText(QApplication::translate("Config_set", "\350\277\236\346\216\245", 0));
    } // retranslateUi

};

namespace Ui {
    class Config_set: public Ui_Config_set {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIG_SET_H
