/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QFrame *frame_2;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_8;
    QComboBox *connect_mode;
    QComboBox *connect_serial;
    QComboBox *connect_net;
    QPushButton *connect_bt;
    QPushButton *key_borad;
    QPushButton *quit_bt;
    QPushButton *smallbt;
    QComboBox *waveSet;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_4;
    QFrame *frame_4;
    QGridLayout *gridLayout_6;
    QLabel *label_10;
    QLabel *label_9;
    QLabel *label_12;
    QComboBox *output_mode;
    QLabel *label_7;
    QLabel *label_5;
    QDoubleSpinBox *output_ele;
    QLabel *label_11;
    QLabel *label_6;
    QComboBox *rated_value;
    QComboBox *output_hz;
    QFrame *frame;
    QGridLayout *gridLayout_5;
    QLabel *label;
    QPushButton *a1A;
    QPushButton *a01A;
    QPushButton *a001A;
    QPushButton *a0001A;
    QPushButton *s1A;
    QPushButton *s01A;
    QPushButton *s001A;
    QPushButton *s0001A;
    QPushButton *p_1;
    QPushButton *p_5;
    QPushButton *p_10;
    QPushButton *p_20;
    QPushButton *p_50;
    QPushButton *p_80;
    QPushButton *p_100;
    QPushButton *p_120;
    QPushButton *start_bt;
    QPushButton *stop_bt;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setMaximumSize(QSize(800, 600));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        frame_2 = new QFrame(groupBox_3);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font;
        font.setFamily(QStringLiteral("Agency FB"));
        font.setPointSize(14);
        label_2->setFont(font);

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        label_3 = new QLabel(frame_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 0, 1, 1, 1);

        label_4 = new QLabel(frame_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        gridLayout_2->addWidget(label_4, 0, 2, 1, 1);

        label_8 = new QLabel(frame_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font);

        gridLayout_2->addWidget(label_8, 0, 3, 1, 1);

        connect_mode = new QComboBox(frame_2);
        connect_mode->setObjectName(QStringLiteral("connect_mode"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(connect_mode->sizePolicy().hasHeightForWidth());
        connect_mode->setSizePolicy(sizePolicy);
        connect_mode->setFont(font);

        gridLayout_2->addWidget(connect_mode, 1, 0, 2, 1);

        connect_serial = new QComboBox(frame_2);
        connect_serial->setObjectName(QStringLiteral("connect_serial"));
        sizePolicy.setHeightForWidth(connect_serial->sizePolicy().hasHeightForWidth());
        connect_serial->setSizePolicy(sizePolicy);
        connect_serial->setFont(font);

        gridLayout_2->addWidget(connect_serial, 1, 1, 2, 1);

        connect_net = new QComboBox(frame_2);
        connect_net->setObjectName(QStringLiteral("connect_net"));
        sizePolicy.setHeightForWidth(connect_net->sizePolicy().hasHeightForWidth());
        connect_net->setSizePolicy(sizePolicy);
        connect_net->setFont(font);

        gridLayout_2->addWidget(connect_net, 1, 2, 2, 1);

        connect_bt = new QPushButton(frame_2);
        connect_bt->setObjectName(QStringLiteral("connect_bt"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(connect_bt->sizePolicy().hasHeightForWidth());
        connect_bt->setSizePolicy(sizePolicy1);
        connect_bt->setFont(font);

        gridLayout_2->addWidget(connect_bt, 0, 4, 3, 1);

        key_borad = new QPushButton(frame_2);
        key_borad->setObjectName(QStringLiteral("key_borad"));
        sizePolicy1.setHeightForWidth(key_borad->sizePolicy().hasHeightForWidth());
        key_borad->setSizePolicy(sizePolicy1);
        key_borad->setFont(font);
        key_borad->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(key_borad, 0, 5, 3, 1);

        quit_bt = new QPushButton(frame_2);
        quit_bt->setObjectName(QStringLiteral("quit_bt"));
        sizePolicy1.setHeightForWidth(quit_bt->sizePolicy().hasHeightForWidth());
        quit_bt->setSizePolicy(sizePolicy1);
        quit_bt->setFont(font);
        quit_bt->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(quit_bt, 0, 6, 3, 1);

        smallbt = new QPushButton(frame_2);
        smallbt->setObjectName(QStringLiteral("smallbt"));
        sizePolicy1.setHeightForWidth(smallbt->sizePolicy().hasHeightForWidth());
        smallbt->setSizePolicy(sizePolicy1);
        smallbt->setFont(font);
        smallbt->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(smallbt, 0, 7, 3, 1);

        waveSet = new QComboBox(frame_2);
        waveSet->setObjectName(QStringLiteral("waveSet"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(waveSet->sizePolicy().hasHeightForWidth());
        waveSet->setSizePolicy(sizePolicy2);
        waveSet->setFont(font);

        gridLayout_2->addWidget(waveSet, 1, 3, 2, 1);


        gridLayout_3->addWidget(frame_2, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox_3, 0, 0, 1, 1);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMaximumSize(QSize(790, 16777215));
        gridLayout_4 = new QGridLayout(groupBox);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        frame_4 = new QFrame(groupBox);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setMaximumSize(QSize(392, 16777215));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        gridLayout_6 = new QGridLayout(frame_4);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        label_10 = new QLabel(frame_4);
        label_10->setObjectName(QStringLiteral("label_10"));
        sizePolicy1.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy1);
        label_10->setMinimumSize(QSize(112, 119));
        label_10->setMaximumSize(QSize(112, 119));
        QFont font1;
        font1.setFamily(QStringLiteral("Agency FB"));
        font1.setPointSize(16);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        label_10->setFont(font1);
        label_10->setStyleSheet(QStringLiteral("font: 16pt \"Agency FB\";"));
        label_10->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_10, 4, 0, 1, 2);

        label_9 = new QLabel(frame_4);
        label_9->setObjectName(QStringLiteral("label_9"));
        sizePolicy1.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy1);
        label_9->setMinimumSize(QSize(112, 119));
        label_9->setMaximumSize(QSize(112, 119));
        label_9->setFont(font1);
        label_9->setStyleSheet(QStringLiteral("font: 16pt \"Agency FB\";"));

        gridLayout_6->addWidget(label_9, 2, 0, 2, 2);

        label_12 = new QLabel(frame_4);
        label_12->setObjectName(QStringLiteral("label_12"));
        sizePolicy1.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy1);
        label_12->setMaximumSize(QSize(60, 16777215));
        QFont font2;
        font2.setFamily(QStringLiteral("Agency FB"));
        font2.setPointSize(36);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        label_12->setFont(font2);
        label_12->setStyleSheet(QStringLiteral("font: 36pt \"Agency FB\";"));

        gridLayout_6->addWidget(label_12, 4, 4, 1, 2);

        output_mode = new QComboBox(frame_4);
        output_mode->setObjectName(QStringLiteral("output_mode"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(output_mode->sizePolicy().hasHeightForWidth());
        output_mode->setSizePolicy(sizePolicy3);
        output_mode->setMinimumSize(QSize(40, 49));
        output_mode->setFont(font);

        gridLayout_6->addWidget(output_mode, 1, 0, 1, 3);

        label_7 = new QLabel(frame_4);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setStyleSheet(QStringLiteral("font: 28pt \"Agency FB\";"));

        gridLayout_6->addWidget(label_7, 1, 5, 1, 1);

        label_5 = new QLabel(frame_4);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        gridLayout_6->addWidget(label_5, 0, 0, 1, 1);

        output_ele = new QDoubleSpinBox(frame_4);
        output_ele->setObjectName(QStringLiteral("output_ele"));
        output_ele->setEnabled(true);
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(output_ele->sizePolicy().hasHeightForWidth());
        output_ele->setSizePolicy(sizePolicy4);
        output_ele->setMinimumSize(QSize(169, 119));
        QFont font3;
        font3.setFamily(QStringLiteral("Agency FB"));
        font3.setPointSize(36);
        output_ele->setFont(font3);
        output_ele->setAutoFillBackground(true);
        output_ele->setFrame(true);
        output_ele->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        output_ele->setButtonSymbols(QAbstractSpinBox::NoButtons);
        output_ele->setCorrectionMode(QAbstractSpinBox::CorrectToPreviousValue);
        output_ele->setDecimals(4);

        gridLayout_6->addWidget(output_ele, 2, 2, 2, 2);

        label_11 = new QLabel(frame_4);
        label_11->setObjectName(QStringLiteral("label_11"));
        sizePolicy1.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy1);
        label_11->setMaximumSize(QSize(60, 16777215));
        label_11->setFont(font2);
        label_11->setStyleSheet(QStringLiteral("font: 36pt \"Agency FB\";"));

        gridLayout_6->addWidget(label_11, 2, 4, 2, 2);

        label_6 = new QLabel(frame_4);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);

        gridLayout_6->addWidget(label_6, 0, 3, 1, 1);

        rated_value = new QComboBox(frame_4);
        rated_value->setObjectName(QStringLiteral("rated_value"));
        sizePolicy3.setHeightForWidth(rated_value->sizePolicy().hasHeightForWidth());
        rated_value->setSizePolicy(sizePolicy3);
        rated_value->setMinimumSize(QSize(40, 40));
        rated_value->setMaximumSize(QSize(16777215, 16777215));
        QFont font4;
        font4.setFamily(QStringLiteral("Agency FB"));
        font4.setPointSize(28);
        font4.setBold(false);
        font4.setItalic(false);
        font4.setWeight(50);
        rated_value->setFont(font4);
        rated_value->setStyleSheet(QLatin1String("QComboBox {padding-right: 0px;font: 28pt \"Agency FB\";}\n"
"\n"
"\n"
"QComboBox::drop-down {\n"
"width: 40px;\n"
"};"));
        rated_value->setEditable(true);

        gridLayout_6->addWidget(rated_value, 1, 3, 1, 2);

        output_hz = new QComboBox(frame_4);
        output_hz->setObjectName(QStringLiteral("output_hz"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(169);
        sizePolicy5.setVerticalStretch(119);
        sizePolicy5.setHeightForWidth(output_hz->sizePolicy().hasHeightForWidth());
        output_hz->setSizePolicy(sizePolicy5);
        output_hz->setMinimumSize(QSize(169, 119));
        output_hz->setFont(font2);
        output_hz->setStyleSheet(QLatin1String("QComboBox {padding-right: 0px;font: 36pt \"Agency FB\";}\n"
"\n"
"\n"
"QComboBox::drop-down {\n"
"width: 40px;\n"
"};"));
        output_hz->setEditable(true);

        gridLayout_6->addWidget(output_hz, 4, 2, 1, 2);


        gridLayout_4->addWidget(frame_4, 0, 0, 1, 1);

        frame = new QFrame(groupBox);
        frame->setObjectName(QStringLiteral("frame"));
        sizePolicy3.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy3);
        frame->setMaximumSize(QSize(392, 16777215));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_5 = new QGridLayout(frame);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        gridLayout_5->addWidget(label, 0, 0, 1, 1);

        a1A = new QPushButton(frame);
        a1A->setObjectName(QStringLiteral("a1A"));
        QSizePolicy sizePolicy6(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(a1A->sizePolicy().hasHeightForWidth());
        a1A->setSizePolicy(sizePolicy6);
        a1A->setFont(font);

        gridLayout_5->addWidget(a1A, 1, 0, 1, 1);

        a01A = new QPushButton(frame);
        a01A->setObjectName(QStringLiteral("a01A"));
        sizePolicy6.setHeightForWidth(a01A->sizePolicy().hasHeightForWidth());
        a01A->setSizePolicy(sizePolicy6);
        a01A->setFont(font);

        gridLayout_5->addWidget(a01A, 1, 1, 1, 1);

        a001A = new QPushButton(frame);
        a001A->setObjectName(QStringLiteral("a001A"));
        sizePolicy6.setHeightForWidth(a001A->sizePolicy().hasHeightForWidth());
        a001A->setSizePolicy(sizePolicy6);
        a001A->setFont(font);

        gridLayout_5->addWidget(a001A, 1, 2, 1, 1);

        a0001A = new QPushButton(frame);
        a0001A->setObjectName(QStringLiteral("a0001A"));
        sizePolicy6.setHeightForWidth(a0001A->sizePolicy().hasHeightForWidth());
        a0001A->setSizePolicy(sizePolicy6);
        a0001A->setFont(font);

        gridLayout_5->addWidget(a0001A, 1, 3, 1, 1);

        s1A = new QPushButton(frame);
        s1A->setObjectName(QStringLiteral("s1A"));
        sizePolicy6.setHeightForWidth(s1A->sizePolicy().hasHeightForWidth());
        s1A->setSizePolicy(sizePolicy6);
        s1A->setFont(font);

        gridLayout_5->addWidget(s1A, 2, 0, 1, 1);

        s01A = new QPushButton(frame);
        s01A->setObjectName(QStringLiteral("s01A"));
        sizePolicy6.setHeightForWidth(s01A->sizePolicy().hasHeightForWidth());
        s01A->setSizePolicy(sizePolicy6);
        s01A->setFont(font);

        gridLayout_5->addWidget(s01A, 2, 1, 1, 1);

        s001A = new QPushButton(frame);
        s001A->setObjectName(QStringLiteral("s001A"));
        sizePolicy6.setHeightForWidth(s001A->sizePolicy().hasHeightForWidth());
        s001A->setSizePolicy(sizePolicy6);
        s001A->setFont(font);

        gridLayout_5->addWidget(s001A, 2, 2, 1, 1);

        s0001A = new QPushButton(frame);
        s0001A->setObjectName(QStringLiteral("s0001A"));
        sizePolicy6.setHeightForWidth(s0001A->sizePolicy().hasHeightForWidth());
        s0001A->setSizePolicy(sizePolicy6);
        s0001A->setFont(font);

        gridLayout_5->addWidget(s0001A, 2, 3, 1, 1);

        p_1 = new QPushButton(frame);
        p_1->setObjectName(QStringLiteral("p_1"));
        sizePolicy6.setHeightForWidth(p_1->sizePolicy().hasHeightForWidth());
        p_1->setSizePolicy(sizePolicy6);
        p_1->setFont(font);

        gridLayout_5->addWidget(p_1, 3, 0, 1, 1);

        p_5 = new QPushButton(frame);
        p_5->setObjectName(QStringLiteral("p_5"));
        sizePolicy6.setHeightForWidth(p_5->sizePolicy().hasHeightForWidth());
        p_5->setSizePolicy(sizePolicy6);
        p_5->setFont(font);

        gridLayout_5->addWidget(p_5, 3, 1, 1, 1);

        p_10 = new QPushButton(frame);
        p_10->setObjectName(QStringLiteral("p_10"));
        sizePolicy6.setHeightForWidth(p_10->sizePolicy().hasHeightForWidth());
        p_10->setSizePolicy(sizePolicy6);
        p_10->setFont(font);

        gridLayout_5->addWidget(p_10, 3, 2, 1, 1);

        p_20 = new QPushButton(frame);
        p_20->setObjectName(QStringLiteral("p_20"));
        sizePolicy6.setHeightForWidth(p_20->sizePolicy().hasHeightForWidth());
        p_20->setSizePolicy(sizePolicy6);
        p_20->setFont(font);

        gridLayout_5->addWidget(p_20, 3, 3, 1, 1);

        p_50 = new QPushButton(frame);
        p_50->setObjectName(QStringLiteral("p_50"));
        sizePolicy6.setHeightForWidth(p_50->sizePolicy().hasHeightForWidth());
        p_50->setSizePolicy(sizePolicy6);
        p_50->setFont(font);

        gridLayout_5->addWidget(p_50, 4, 0, 1, 1);

        p_80 = new QPushButton(frame);
        p_80->setObjectName(QStringLiteral("p_80"));
        sizePolicy6.setHeightForWidth(p_80->sizePolicy().hasHeightForWidth());
        p_80->setSizePolicy(sizePolicy6);
        p_80->setFont(font);

        gridLayout_5->addWidget(p_80, 4, 1, 1, 1);

        p_100 = new QPushButton(frame);
        p_100->setObjectName(QStringLiteral("p_100"));
        sizePolicy6.setHeightForWidth(p_100->sizePolicy().hasHeightForWidth());
        p_100->setSizePolicy(sizePolicy6);
        p_100->setFont(font);

        gridLayout_5->addWidget(p_100, 4, 2, 1, 1);

        p_120 = new QPushButton(frame);
        p_120->setObjectName(QStringLiteral("p_120"));
        sizePolicy6.setHeightForWidth(p_120->sizePolicy().hasHeightForWidth());
        p_120->setSizePolicy(sizePolicy6);
        p_120->setFont(font);

        gridLayout_5->addWidget(p_120, 4, 3, 1, 1);

        start_bt = new QPushButton(frame);
        start_bt->setObjectName(QStringLiteral("start_bt"));
        sizePolicy4.setHeightForWidth(start_bt->sizePolicy().hasHeightForWidth());
        start_bt->setSizePolicy(sizePolicy4);
        start_bt->setMinimumSize(QSize(0, 67));
        start_bt->setMaximumSize(QSize(16777215, 16777215));
        QFont font5;
        font5.setFamily(QStringLiteral("Agency FB"));
        font5.setPointSize(28);
        start_bt->setFont(font5);

        gridLayout_5->addWidget(start_bt, 5, 0, 1, 2);

        stop_bt = new QPushButton(frame);
        stop_bt->setObjectName(QStringLiteral("stop_bt"));
        sizePolicy4.setHeightForWidth(stop_bt->sizePolicy().hasHeightForWidth());
        stop_bt->setSizePolicy(sizePolicy4);
        stop_bt->setMinimumSize(QSize(0, 67));
        stop_bt->setFont(font5);

        gridLayout_5->addWidget(stop_bt, 5, 2, 1, 2);


        gridLayout_4->addWidget(frame, 0, 1, 1, 1);


        gridLayout->addWidget(groupBox, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "xl-3217 V1.0 ", 0));
        groupBox_3->setTitle(QString());
        label_2->setText(QApplication::translate("MainWindow", "\346\272\220\350\277\236\346\216\245\347\261\273\345\236\213", 0));
        label_3->setText(QApplication::translate("MainWindow", "\346\272\220\344\270\262\345\217\243", 0));
        label_4->setText(QApplication::translate("MainWindow", "\346\272\220\344\273\245\345\244\252\347\275\221\345\217\243", 0));
        label_8->setText(QApplication::translate("MainWindow", "\346\263\242\345\275\242\350\256\276\347\275\256", 0));
        connect_mode->clear();
        connect_mode->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\344\270\262\345\217\243\350\277\236\346\216\245", 0)
         << QApplication::translate("MainWindow", "\347\275\221\345\217\243\350\277\236\346\216\245", 0)
        );
        connect_bt->setText(QApplication::translate("MainWindow", "\350\277\236\346\216\245", 0));
        key_borad->setText(QApplication::translate("MainWindow", "\351\224\256\347\233\230", 0));
        quit_bt->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", 0));
        smallbt->setText(QApplication::translate("MainWindow", "\347\252\227\345\217\243\345\214\226", 0));
        waveSet->clear();
        waveSet->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\346\255\243\345\274\246\346\263\242", 0)
         << QApplication::translate("MainWindow", "\346\226\271\346\263\242", 0)
        );
        groupBox->setTitle(QString());
        label_10->setText(QApplication::translate("MainWindow", "\351\242\221\347\216\207:", 0));
        label_9->setText(QApplication::translate("MainWindow", "\350\276\223\345\207\272\347\224\265\346\265\201:", 0));
        label_12->setText(QApplication::translate("MainWindow", "HZ", 0));
        output_mode->clear();
        output_mode->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\344\272\244\346\265\201\347\224\265\346\265\201", 0)
         << QApplication::translate("MainWindow", "\347\233\264\346\265\201\347\224\265\346\265\201", 0)
        );
        label_7->setText(QApplication::translate("MainWindow", "A", 0));
        label_5->setText(QApplication::translate("MainWindow", "\350\276\223\345\207\272\347\261\273\345\236\213", 0));
        output_ele->setPrefix(QString());
        output_ele->setSuffix(QString());
        label_11->setText(QApplication::translate("MainWindow", "A           ", 0));
        label_6->setText(QApplication::translate("MainWindow", "\351\242\235\345\256\232\345\200\274", 0));
        rated_value->clear();
        rated_value->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1", 0)
         << QApplication::translate("MainWindow", "5", 0)
        );
        output_hz->clear();
        output_hz->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "50", 0)
         << QApplication::translate("MainWindow", "40", 0)
         << QApplication::translate("MainWindow", "45", 0)
         << QApplication::translate("MainWindow", "47.5", 0)
         << QApplication::translate("MainWindow", "49", 0)
         << QApplication::translate("MainWindow", "49.5", 0)
         << QApplication::translate("MainWindow", "50.5", 0)
         << QApplication::translate("MainWindow", "52.5", 0)
         << QApplication::translate("MainWindow", "55", 0)
         << QApplication::translate("MainWindow", "60", 0)
         << QApplication::translate("MainWindow", "100", 0)
         << QApplication::translate("MainWindow", "1000", 0)
        );
        label->setText(QApplication::translate("MainWindow", "\346\243\200\345\256\232\347\202\271", 0));
        a1A->setText(QApplication::translate("MainWindow", "+1A", 0));
        a01A->setText(QApplication::translate("MainWindow", "+0.1A", 0));
        a001A->setText(QApplication::translate("MainWindow", "+0.01A", 0));
        a0001A->setText(QApplication::translate("MainWindow", "+0.001A", 0));
        s1A->setText(QApplication::translate("MainWindow", "-1A", 0));
        s01A->setText(QApplication::translate("MainWindow", "-0.1A", 0));
        s001A->setText(QApplication::translate("MainWindow", "-0.01A", 0));
        s0001A->setText(QApplication::translate("MainWindow", "-0.001A", 0));
        p_1->setText(QApplication::translate("MainWindow", "1%", 0));
        p_5->setText(QApplication::translate("MainWindow", "5%", 0));
        p_10->setText(QApplication::translate("MainWindow", "10%", 0));
        p_20->setText(QApplication::translate("MainWindow", "20%", 0));
        p_50->setText(QApplication::translate("MainWindow", "50%", 0));
        p_80->setText(QApplication::translate("MainWindow", "80%", 0));
        p_100->setText(QApplication::translate("MainWindow", "100%", 0));
        p_120->setText(QApplication::translate("MainWindow", "120%", 0));
        start_bt->setText(QApplication::translate("MainWindow", "\345\220\257\345\212\250", 0));
        stop_bt->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
