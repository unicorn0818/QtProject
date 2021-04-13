/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_7;
    QFrame *frame_2;
    QGridLayout *gridLayout_5;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *update_ora;
    QPushButton *config_set;
    QFrame *frame;
    QGridLayout *gridLayout_6;
    QListWidget *listWidget;
    QLabel *label_2;
    QTabWidget *tabWidget_2;
    QWidget *tab_3;
    QGridLayout *gridLayout_2;
    QTableWidget *tableWidget;
    QWidget *tab_4;
    QGridLayout *gridLayout_4;
    QTableWidget *tableWidget_2;
    QWidget *tab_5;
    QGridLayout *gridLayout_3;
    QTableWidget *tableWidget_3;
    QWidget *tab_2;
    QGridLayout *gridLayout_9;
    QFrame *frame_3;
    QGridLayout *gridLayout_12;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLineEdit *task_no;
    QPushButton *jointA_1;
    QLabel *label_3;
    QComboBox *barCode;
    QPushButton *bindInfo;
    QSpacerItem *horizontalSpacer_2;
    QFrame *frame_4;
    QGridLayout *gridLayout_8;
    QTabWidget *tabWidget_3;
    QWidget *tab_7;
    QGridLayout *gridLayout_11;
    QTableWidget *tableWidget_6;
    QWidget *tab_6;
    QGridLayout *gridLayout_10;
    QTableWidget *tableWidget_5;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1050, 680);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setStyleSheet(QString::fromUtf8("QTabBar::tab{width:200}\n"
"QTabBar::tab{height:60}\n"
"\n"
"\n"
""));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_7 = new QGridLayout(tab);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        frame_2 = new QFrame(tab);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_5 = new QGridLayout(frame_2);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        update_ora = new QPushButton(frame_2);
        update_ora->setObjectName(QString::fromUtf8("update_ora"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(update_ora->sizePolicy().hasHeightForWidth());
        update_ora->setSizePolicy(sizePolicy);
        update_ora->setMinimumSize(QSize(125, 50));

        horizontalLayout->addWidget(update_ora);

        config_set = new QPushButton(frame_2);
        config_set->setObjectName(QString::fromUtf8("config_set"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(config_set->sizePolicy().hasHeightForWidth());
        config_set->setSizePolicy(sizePolicy1);
        config_set->setMinimumSize(QSize(125, 50));

        horizontalLayout->addWidget(config_set);


        gridLayout_5->addLayout(horizontalLayout, 0, 0, 1, 1);


        gridLayout_7->addWidget(frame_2, 0, 0, 1, 1);

        frame = new QFrame(tab);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_6 = new QGridLayout(frame);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setHorizontalSpacing(6);
        listWidget = new QListWidget(frame);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy2);
        listWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(224, 238, 255);"));

        gridLayout_6->addWidget(listWidget, 1, 0, 1, 1);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(120, 170, 220);\n"
"font: 12pt \"Agency FB\";\n"
""));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(label_2, 0, 0, 1, 1);

        tabWidget_2 = new QTabWidget(frame);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        tabWidget_2->setStyleSheet(QString::fromUtf8("QTabBar::tab{width:150}\n"
"QTabBar::tab{height:30}"));
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        gridLayout_2 = new QGridLayout(tab_3);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        tableWidget = new QTableWidget(tab_3);
        if (tableWidget->columnCount() < 24)
            tableWidget->setColumnCount(24);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(10, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(11, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(12, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(13, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(14, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(15, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(16, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(17, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(18, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(19, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(20, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(21, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(22, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(23, __qtablewidgetitem23);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setStyleSheet(QString::fromUtf8(""));

        gridLayout_2->addWidget(tableWidget, 0, 0, 1, 1);

        tabWidget_2->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        gridLayout_4 = new QGridLayout(tab_4);
        gridLayout_4->setSpacing(0);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        tableWidget_2 = new QTableWidget(tab_4);
        if (tableWidget_2->columnCount() < 24)
            tableWidget_2->setColumnCount(24);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(2, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(3, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(4, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(5, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(6, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(7, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(8, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(9, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(10, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(11, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(12, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(13, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(14, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(15, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(16, __qtablewidgetitem40);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(17, __qtablewidgetitem41);
        QTableWidgetItem *__qtablewidgetitem42 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(18, __qtablewidgetitem42);
        QTableWidgetItem *__qtablewidgetitem43 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(19, __qtablewidgetitem43);
        QTableWidgetItem *__qtablewidgetitem44 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(20, __qtablewidgetitem44);
        QTableWidgetItem *__qtablewidgetitem45 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(21, __qtablewidgetitem45);
        QTableWidgetItem *__qtablewidgetitem46 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(22, __qtablewidgetitem46);
        QTableWidgetItem *__qtablewidgetitem47 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(23, __qtablewidgetitem47);
        tableWidget_2->setObjectName(QString::fromUtf8("tableWidget_2"));
        tableWidget_2->setStyleSheet(QString::fromUtf8(""));

        gridLayout_4->addWidget(tableWidget_2, 0, 0, 1, 1);

        tabWidget_2->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        gridLayout_3 = new QGridLayout(tab_5);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        tableWidget_3 = new QTableWidget(tab_5);
        if (tableWidget_3->columnCount() < 24)
            tableWidget_3->setColumnCount(24);
        QTableWidgetItem *__qtablewidgetitem48 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(0, __qtablewidgetitem48);
        QTableWidgetItem *__qtablewidgetitem49 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(1, __qtablewidgetitem49);
        QTableWidgetItem *__qtablewidgetitem50 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(2, __qtablewidgetitem50);
        QTableWidgetItem *__qtablewidgetitem51 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(3, __qtablewidgetitem51);
        QTableWidgetItem *__qtablewidgetitem52 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(4, __qtablewidgetitem52);
        QTableWidgetItem *__qtablewidgetitem53 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(5, __qtablewidgetitem53);
        QTableWidgetItem *__qtablewidgetitem54 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(6, __qtablewidgetitem54);
        QTableWidgetItem *__qtablewidgetitem55 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(7, __qtablewidgetitem55);
        QTableWidgetItem *__qtablewidgetitem56 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(8, __qtablewidgetitem56);
        QTableWidgetItem *__qtablewidgetitem57 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(9, __qtablewidgetitem57);
        QTableWidgetItem *__qtablewidgetitem58 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(10, __qtablewidgetitem58);
        QTableWidgetItem *__qtablewidgetitem59 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(11, __qtablewidgetitem59);
        QTableWidgetItem *__qtablewidgetitem60 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(12, __qtablewidgetitem60);
        QTableWidgetItem *__qtablewidgetitem61 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(13, __qtablewidgetitem61);
        QTableWidgetItem *__qtablewidgetitem62 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(14, __qtablewidgetitem62);
        QTableWidgetItem *__qtablewidgetitem63 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(15, __qtablewidgetitem63);
        QTableWidgetItem *__qtablewidgetitem64 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(16, __qtablewidgetitem64);
        QTableWidgetItem *__qtablewidgetitem65 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(17, __qtablewidgetitem65);
        QTableWidgetItem *__qtablewidgetitem66 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(18, __qtablewidgetitem66);
        QTableWidgetItem *__qtablewidgetitem67 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(19, __qtablewidgetitem67);
        QTableWidgetItem *__qtablewidgetitem68 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(20, __qtablewidgetitem68);
        QTableWidgetItem *__qtablewidgetitem69 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(21, __qtablewidgetitem69);
        QTableWidgetItem *__qtablewidgetitem70 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(22, __qtablewidgetitem70);
        QTableWidgetItem *__qtablewidgetitem71 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(23, __qtablewidgetitem71);
        tableWidget_3->setObjectName(QString::fromUtf8("tableWidget_3"));
        tableWidget_3->setStyleSheet(QString::fromUtf8(""));

        gridLayout_3->addWidget(tableWidget_3, 0, 0, 1, 1);

        tabWidget_2->addTab(tab_5, QString());

        gridLayout_6->addWidget(tabWidget_2, 0, 1, 2, 1);


        gridLayout_7->addWidget(frame, 1, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_9 = new QGridLayout(tab_2);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        frame_3 = new QFrame(tab_2);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        gridLayout_12 = new QGridLayout(frame_3);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label = new QLabel(frame_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 12pt \"Agency FB\";"));

        horizontalLayout_3->addWidget(label);

        task_no = new QLineEdit(frame_3);
        task_no->setObjectName(QString::fromUtf8("task_no"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(task_no->sizePolicy().hasHeightForWidth());
        task_no->setSizePolicy(sizePolicy3);
        task_no->setMinimumSize(QSize(200, 50));
        task_no->setStyleSheet(QString::fromUtf8("font: 12pt \"Agency FB\";"));

        horizontalLayout_3->addWidget(task_no);

        jointA_1 = new QPushButton(frame_3);
        jointA_1->setObjectName(QString::fromUtf8("jointA_1"));
        sizePolicy.setHeightForWidth(jointA_1->sizePolicy().hasHeightForWidth());
        jointA_1->setSizePolicy(sizePolicy);
        jointA_1->setMinimumSize(QSize(125, 50));

        horizontalLayout_3->addWidget(jointA_1);

        label_3 = new QLabel(frame_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("font: 12pt \"Agency FB\";"));

        horizontalLayout_3->addWidget(label_3);

        barCode = new QComboBox(frame_3);
        barCode->setObjectName(QString::fromUtf8("barCode"));
        barCode->setMinimumSize(QSize(125, 50));

        horizontalLayout_3->addWidget(barCode);

        bindInfo = new QPushButton(frame_3);
        bindInfo->setObjectName(QString::fromUtf8("bindInfo"));
        sizePolicy.setHeightForWidth(bindInfo->sizePolicy().hasHeightForWidth());
        bindInfo->setSizePolicy(sizePolicy);
        bindInfo->setMinimumSize(QSize(125, 50));

        horizontalLayout_3->addWidget(bindInfo);


        gridLayout_12->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(432, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_12->addItem(horizontalSpacer_2, 0, 1, 1, 1);


        gridLayout_9->addWidget(frame_3, 0, 0, 1, 1);

        frame_4 = new QFrame(tab_2);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        sizePolicy2.setHeightForWidth(frame_4->sizePolicy().hasHeightForWidth());
        frame_4->setSizePolicy(sizePolicy2);
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        gridLayout_8 = new QGridLayout(frame_4);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        tabWidget_3 = new QTabWidget(frame_4);
        tabWidget_3->setObjectName(QString::fromUtf8("tabWidget_3"));
        tabWidget_3->setStyleSheet(QString::fromUtf8("QTabBar::tab{width:150}\n"
"QTabBar::tab{height:30}"));
        tab_7 = new QWidget();
        tab_7->setObjectName(QString::fromUtf8("tab_7"));
        gridLayout_11 = new QGridLayout(tab_7);
        gridLayout_11->setSpacing(0);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        gridLayout_11->setContentsMargins(0, 0, 0, 0);
        tableWidget_6 = new QTableWidget(tab_7);
        if (tableWidget_6->columnCount() < 23)
            tableWidget_6->setColumnCount(23);
        QTableWidgetItem *__qtablewidgetitem72 = new QTableWidgetItem();
        tableWidget_6->setHorizontalHeaderItem(0, __qtablewidgetitem72);
        QTableWidgetItem *__qtablewidgetitem73 = new QTableWidgetItem();
        tableWidget_6->setHorizontalHeaderItem(1, __qtablewidgetitem73);
        QTableWidgetItem *__qtablewidgetitem74 = new QTableWidgetItem();
        tableWidget_6->setHorizontalHeaderItem(2, __qtablewidgetitem74);
        QTableWidgetItem *__qtablewidgetitem75 = new QTableWidgetItem();
        tableWidget_6->setHorizontalHeaderItem(3, __qtablewidgetitem75);
        QTableWidgetItem *__qtablewidgetitem76 = new QTableWidgetItem();
        tableWidget_6->setHorizontalHeaderItem(4, __qtablewidgetitem76);
        QTableWidgetItem *__qtablewidgetitem77 = new QTableWidgetItem();
        tableWidget_6->setHorizontalHeaderItem(5, __qtablewidgetitem77);
        QTableWidgetItem *__qtablewidgetitem78 = new QTableWidgetItem();
        tableWidget_6->setHorizontalHeaderItem(6, __qtablewidgetitem78);
        QTableWidgetItem *__qtablewidgetitem79 = new QTableWidgetItem();
        tableWidget_6->setHorizontalHeaderItem(7, __qtablewidgetitem79);
        QTableWidgetItem *__qtablewidgetitem80 = new QTableWidgetItem();
        tableWidget_6->setHorizontalHeaderItem(8, __qtablewidgetitem80);
        QTableWidgetItem *__qtablewidgetitem81 = new QTableWidgetItem();
        tableWidget_6->setHorizontalHeaderItem(9, __qtablewidgetitem81);
        QTableWidgetItem *__qtablewidgetitem82 = new QTableWidgetItem();
        tableWidget_6->setHorizontalHeaderItem(10, __qtablewidgetitem82);
        QTableWidgetItem *__qtablewidgetitem83 = new QTableWidgetItem();
        tableWidget_6->setHorizontalHeaderItem(11, __qtablewidgetitem83);
        QTableWidgetItem *__qtablewidgetitem84 = new QTableWidgetItem();
        tableWidget_6->setHorizontalHeaderItem(12, __qtablewidgetitem84);
        QTableWidgetItem *__qtablewidgetitem85 = new QTableWidgetItem();
        tableWidget_6->setHorizontalHeaderItem(13, __qtablewidgetitem85);
        QTableWidgetItem *__qtablewidgetitem86 = new QTableWidgetItem();
        tableWidget_6->setHorizontalHeaderItem(14, __qtablewidgetitem86);
        QTableWidgetItem *__qtablewidgetitem87 = new QTableWidgetItem();
        tableWidget_6->setHorizontalHeaderItem(15, __qtablewidgetitem87);
        QTableWidgetItem *__qtablewidgetitem88 = new QTableWidgetItem();
        tableWidget_6->setHorizontalHeaderItem(16, __qtablewidgetitem88);
        QTableWidgetItem *__qtablewidgetitem89 = new QTableWidgetItem();
        tableWidget_6->setHorizontalHeaderItem(17, __qtablewidgetitem89);
        QTableWidgetItem *__qtablewidgetitem90 = new QTableWidgetItem();
        tableWidget_6->setHorizontalHeaderItem(18, __qtablewidgetitem90);
        QTableWidgetItem *__qtablewidgetitem91 = new QTableWidgetItem();
        tableWidget_6->setHorizontalHeaderItem(19, __qtablewidgetitem91);
        QTableWidgetItem *__qtablewidgetitem92 = new QTableWidgetItem();
        tableWidget_6->setHorizontalHeaderItem(20, __qtablewidgetitem92);
        QTableWidgetItem *__qtablewidgetitem93 = new QTableWidgetItem();
        tableWidget_6->setHorizontalHeaderItem(21, __qtablewidgetitem93);
        QTableWidgetItem *__qtablewidgetitem94 = new QTableWidgetItem();
        tableWidget_6->setHorizontalHeaderItem(22, __qtablewidgetitem94);
        tableWidget_6->setObjectName(QString::fromUtf8("tableWidget_6"));

        gridLayout_11->addWidget(tableWidget_6, 0, 0, 1, 1);

        tabWidget_3->addTab(tab_7, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        gridLayout_10 = new QGridLayout(tab_6);
        gridLayout_10->setSpacing(0);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        gridLayout_10->setContentsMargins(0, 0, 0, 0);
        tableWidget_5 = new QTableWidget(tab_6);
        if (tableWidget_5->columnCount() < 15)
            tableWidget_5->setColumnCount(15);
        QTableWidgetItem *__qtablewidgetitem95 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(0, __qtablewidgetitem95);
        QTableWidgetItem *__qtablewidgetitem96 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(1, __qtablewidgetitem96);
        QTableWidgetItem *__qtablewidgetitem97 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(2, __qtablewidgetitem97);
        QTableWidgetItem *__qtablewidgetitem98 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(3, __qtablewidgetitem98);
        QTableWidgetItem *__qtablewidgetitem99 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(4, __qtablewidgetitem99);
        QTableWidgetItem *__qtablewidgetitem100 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(5, __qtablewidgetitem100);
        QTableWidgetItem *__qtablewidgetitem101 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(6, __qtablewidgetitem101);
        QTableWidgetItem *__qtablewidgetitem102 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(7, __qtablewidgetitem102);
        QTableWidgetItem *__qtablewidgetitem103 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(8, __qtablewidgetitem103);
        QTableWidgetItem *__qtablewidgetitem104 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(9, __qtablewidgetitem104);
        QTableWidgetItem *__qtablewidgetitem105 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(10, __qtablewidgetitem105);
        QTableWidgetItem *__qtablewidgetitem106 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(11, __qtablewidgetitem106);
        QTableWidgetItem *__qtablewidgetitem107 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(12, __qtablewidgetitem107);
        QTableWidgetItem *__qtablewidgetitem108 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(13, __qtablewidgetitem108);
        QTableWidgetItem *__qtablewidgetitem109 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(14, __qtablewidgetitem109);
        tableWidget_5->setObjectName(QString::fromUtf8("tableWidget_5"));

        gridLayout_10->addWidget(tableWidget_5, 0, 0, 1, 1);

        tabWidget_3->addTab(tab_6, QString());

        gridLayout_8->addWidget(tabWidget_3, 0, 0, 1, 1);


        gridLayout_9->addWidget(frame_4, 1, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(0);
        tabWidget_3->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        update_ora->setText(QCoreApplication::translate("MainWindow", "\344\270\212\344\274\240", nullptr));
        config_set->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\345\272\223\351\205\215\347\275\256", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\346\235\241\345\275\242\347\240\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "\346\243\200\345\256\232\344\273\273\345\212\241\345\215\225\347\274\226\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "\344\272\222\346\204\237\345\231\250\346\235\241\347\240\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "\346\243\200\345\256\232\347\272\277\345\206\231\345\205\245\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "\345\244\204\347\220\206\346\240\207\350\256\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "\345\244\204\347\220\206\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "\350\264\237\350\215\267\346\240\207\345\277\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "\351\242\235\345\256\232\347\224\265\346\265\201\347\231\276\345\210\206\345\200\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "\346\257\224\345\267\256", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "\350\247\222\345\267\256", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "\346\257\224\345\267\256\344\277\256\347\272\246\345\200\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "\350\247\222\345\267\256\344\277\256\347\272\246\345\200\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->horizontalHeaderItem(11);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "\345\272\217\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->horizontalHeaderItem(12);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainWindow", "\347\224\265\346\265\201\345\217\230\346\257\224", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->horizontalHeaderItem(13);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("MainWindow", "\347\263\273\347\273\237\347\274\226\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->horizontalHeaderItem(14);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("MainWindow", "\346\243\200\345\256\232\347\272\277\345\217\260\347\274\226\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->horizontalHeaderItem(15);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("MainWindow", "\346\243\200\345\256\232\345\215\225\345\205\203\347\274\226\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget->horizontalHeaderItem(16);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("MainWindow", "\350\241\250\344\275\215\347\274\226\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget->horizontalHeaderItem(17);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("MainWindow", "\346\243\200\345\256\232\347\202\271\345\272\217\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget->horizontalHeaderItem(18);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("MainWindow", "\346\234\211\346\225\210\346\240\207\345\277\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget->horizontalHeaderItem(19);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("MainWindow", "\345\212\237\347\216\207\345\233\240\346\225\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget->horizontalHeaderItem(20);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("MainWindow", "\347\273\223\350\256\272", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget->horizontalHeaderItem(21);
        ___qtablewidgetitem21->setText(QCoreApplication::translate("MainWindow", "\347\233\270\345\210\253", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget->horizontalHeaderItem(22);
        ___qtablewidgetitem22->setText(QCoreApplication::translate("MainWindow", "\345\215\207\351\231\215\346\240\207\350\257\206", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget->horizontalHeaderItem(23);
        ___qtablewidgetitem23->setText(QCoreApplication::translate("MainWindow", "\350\257\257\345\267\256\347\261\273\345\236\213", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_3), QCoreApplication::translate("MainWindow", "\345\267\245\351\242\221\350\257\257\345\267\256\350\257\225\351\252\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem24->setText(QCoreApplication::translate("MainWindow", "\346\243\200\345\256\232\344\273\273\345\212\241\345\215\225\347\274\226\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem25->setText(QCoreApplication::translate("MainWindow", "\344\272\222\346\204\237\345\231\250\346\235\241\347\240\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget_2->horizontalHeaderItem(2);
        ___qtablewidgetitem26->setText(QCoreApplication::translate("MainWindow", "\346\243\200\345\256\232\347\272\277\345\206\231\345\205\245\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget_2->horizontalHeaderItem(3);
        ___qtablewidgetitem27->setText(QCoreApplication::translate("MainWindow", "\345\244\204\347\220\206\346\240\207\350\256\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidget_2->horizontalHeaderItem(4);
        ___qtablewidgetitem28->setText(QCoreApplication::translate("MainWindow", "\345\244\204\347\220\206\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem29 = tableWidget_2->horizontalHeaderItem(5);
        ___qtablewidgetitem29->setText(QCoreApplication::translate("MainWindow", "\350\264\237\350\215\267\346\240\207\345\277\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem30 = tableWidget_2->horizontalHeaderItem(6);
        ___qtablewidgetitem30->setText(QCoreApplication::translate("MainWindow", "\351\242\235\345\256\232\347\224\265\346\265\201\347\231\276\345\210\206\345\200\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem31 = tableWidget_2->horizontalHeaderItem(7);
        ___qtablewidgetitem31->setText(QCoreApplication::translate("MainWindow", "\346\257\224\345\267\256", nullptr));
        QTableWidgetItem *___qtablewidgetitem32 = tableWidget_2->horizontalHeaderItem(8);
        ___qtablewidgetitem32->setText(QCoreApplication::translate("MainWindow", "\350\247\222\345\267\256", nullptr));
        QTableWidgetItem *___qtablewidgetitem33 = tableWidget_2->horizontalHeaderItem(9);
        ___qtablewidgetitem33->setText(QCoreApplication::translate("MainWindow", "\346\257\224\345\267\256\344\277\256\347\272\246\345\200\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem34 = tableWidget_2->horizontalHeaderItem(10);
        ___qtablewidgetitem34->setText(QCoreApplication::translate("MainWindow", "\350\247\222\345\267\256\344\277\256\347\272\246\345\200\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem35 = tableWidget_2->horizontalHeaderItem(11);
        ___qtablewidgetitem35->setText(QCoreApplication::translate("MainWindow", "\345\272\217\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem36 = tableWidget_2->horizontalHeaderItem(12);
        ___qtablewidgetitem36->setText(QCoreApplication::translate("MainWindow", "\347\224\265\346\265\201\345\217\230\346\257\224", nullptr));
        QTableWidgetItem *___qtablewidgetitem37 = tableWidget_2->horizontalHeaderItem(13);
        ___qtablewidgetitem37->setText(QCoreApplication::translate("MainWindow", "\347\263\273\347\273\237\347\274\226\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem38 = tableWidget_2->horizontalHeaderItem(14);
        ___qtablewidgetitem38->setText(QCoreApplication::translate("MainWindow", "\346\243\200\345\256\232\347\272\277\345\217\260\347\274\226\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem39 = tableWidget_2->horizontalHeaderItem(15);
        ___qtablewidgetitem39->setText(QCoreApplication::translate("MainWindow", "\346\243\200\345\256\232\345\215\225\345\205\203\347\274\226\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem40 = tableWidget_2->horizontalHeaderItem(16);
        ___qtablewidgetitem40->setText(QCoreApplication::translate("MainWindow", "\350\241\250\344\275\215\347\274\226\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem41 = tableWidget_2->horizontalHeaderItem(17);
        ___qtablewidgetitem41->setText(QCoreApplication::translate("MainWindow", "\346\243\200\345\256\232\347\202\271\345\272\217\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem42 = tableWidget_2->horizontalHeaderItem(18);
        ___qtablewidgetitem42->setText(QCoreApplication::translate("MainWindow", "\346\234\211\346\225\210\346\240\207\345\277\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem43 = tableWidget_2->horizontalHeaderItem(19);
        ___qtablewidgetitem43->setText(QCoreApplication::translate("MainWindow", "\345\212\237\347\216\207\345\233\240\346\225\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem44 = tableWidget_2->horizontalHeaderItem(20);
        ___qtablewidgetitem44->setText(QCoreApplication::translate("MainWindow", "\347\273\223\350\256\272", nullptr));
        QTableWidgetItem *___qtablewidgetitem45 = tableWidget_2->horizontalHeaderItem(21);
        ___qtablewidgetitem45->setText(QCoreApplication::translate("MainWindow", "\347\233\270\345\210\253", nullptr));
        QTableWidgetItem *___qtablewidgetitem46 = tableWidget_2->horizontalHeaderItem(22);
        ___qtablewidgetitem46->setText(QCoreApplication::translate("MainWindow", "\345\215\207\351\231\215\346\240\207\350\257\206", nullptr));
        QTableWidgetItem *___qtablewidgetitem47 = tableWidget_2->horizontalHeaderItem(23);
        ___qtablewidgetitem47->setText(QCoreApplication::translate("MainWindow", "\350\257\257\345\267\256\347\261\273\345\236\213", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QCoreApplication::translate("MainWindow", "\345\217\240\345\212\240\347\224\265\346\265\201\346\243\200\345\256\232\350\257\257\345\267\256", nullptr));
        QTableWidgetItem *___qtablewidgetitem48 = tableWidget_3->horizontalHeaderItem(0);
        ___qtablewidgetitem48->setText(QCoreApplication::translate("MainWindow", "\346\243\200\345\256\232\344\273\273\345\212\241\345\215\225\347\274\226\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem49 = tableWidget_3->horizontalHeaderItem(1);
        ___qtablewidgetitem49->setText(QCoreApplication::translate("MainWindow", "\344\272\222\346\204\237\345\231\250\346\235\241\347\240\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem50 = tableWidget_3->horizontalHeaderItem(2);
        ___qtablewidgetitem50->setText(QCoreApplication::translate("MainWindow", "\346\243\200\345\256\232\347\272\277\345\206\231\345\205\245\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem51 = tableWidget_3->horizontalHeaderItem(3);
        ___qtablewidgetitem51->setText(QCoreApplication::translate("MainWindow", "\345\244\204\347\220\206\346\240\207\350\256\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem52 = tableWidget_3->horizontalHeaderItem(4);
        ___qtablewidgetitem52->setText(QCoreApplication::translate("MainWindow", "\345\244\204\347\220\206\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem53 = tableWidget_3->horizontalHeaderItem(5);
        ___qtablewidgetitem53->setText(QCoreApplication::translate("MainWindow", "\350\264\237\350\215\267\346\240\207\345\277\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem54 = tableWidget_3->horizontalHeaderItem(6);
        ___qtablewidgetitem54->setText(QCoreApplication::translate("MainWindow", "\351\242\235\345\256\232\347\224\265\346\265\201\347\231\276\345\210\206\345\200\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem55 = tableWidget_3->horizontalHeaderItem(7);
        ___qtablewidgetitem55->setText(QCoreApplication::translate("MainWindow", "\346\257\224\345\267\256", nullptr));
        QTableWidgetItem *___qtablewidgetitem56 = tableWidget_3->horizontalHeaderItem(8);
        ___qtablewidgetitem56->setText(QCoreApplication::translate("MainWindow", "\350\247\222\345\267\256", nullptr));
        QTableWidgetItem *___qtablewidgetitem57 = tableWidget_3->horizontalHeaderItem(9);
        ___qtablewidgetitem57->setText(QCoreApplication::translate("MainWindow", "\346\257\224\345\267\256\344\277\256\347\272\246\345\200\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem58 = tableWidget_3->horizontalHeaderItem(10);
        ___qtablewidgetitem58->setText(QCoreApplication::translate("MainWindow", "\350\247\222\345\267\256\344\277\256\347\272\246\345\200\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem59 = tableWidget_3->horizontalHeaderItem(11);
        ___qtablewidgetitem59->setText(QCoreApplication::translate("MainWindow", "\345\272\217\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem60 = tableWidget_3->horizontalHeaderItem(12);
        ___qtablewidgetitem60->setText(QCoreApplication::translate("MainWindow", "\347\224\265\346\265\201\345\217\230\346\257\224", nullptr));
        QTableWidgetItem *___qtablewidgetitem61 = tableWidget_3->horizontalHeaderItem(13);
        ___qtablewidgetitem61->setText(QCoreApplication::translate("MainWindow", "\347\263\273\347\273\237\347\274\226\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem62 = tableWidget_3->horizontalHeaderItem(14);
        ___qtablewidgetitem62->setText(QCoreApplication::translate("MainWindow", "\346\243\200\345\256\232\347\272\277\345\217\260\347\274\226\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem63 = tableWidget_3->horizontalHeaderItem(15);
        ___qtablewidgetitem63->setText(QCoreApplication::translate("MainWindow", "\346\243\200\345\256\232\345\215\225\345\205\203\347\274\226\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem64 = tableWidget_3->horizontalHeaderItem(16);
        ___qtablewidgetitem64->setText(QCoreApplication::translate("MainWindow", "\350\241\250\344\275\215\347\274\226\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem65 = tableWidget_3->horizontalHeaderItem(17);
        ___qtablewidgetitem65->setText(QCoreApplication::translate("MainWindow", "\346\243\200\345\256\232\347\202\271\345\272\217\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem66 = tableWidget_3->horizontalHeaderItem(18);
        ___qtablewidgetitem66->setText(QCoreApplication::translate("MainWindow", "\346\234\211\346\225\210\346\240\207\345\277\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem67 = tableWidget_3->horizontalHeaderItem(19);
        ___qtablewidgetitem67->setText(QCoreApplication::translate("MainWindow", "\345\212\237\347\216\207\345\233\240\346\225\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem68 = tableWidget_3->horizontalHeaderItem(20);
        ___qtablewidgetitem68->setText(QCoreApplication::translate("MainWindow", "\347\273\223\350\256\272", nullptr));
        QTableWidgetItem *___qtablewidgetitem69 = tableWidget_3->horizontalHeaderItem(21);
        ___qtablewidgetitem69->setText(QCoreApplication::translate("MainWindow", "\347\233\270\345\210\253", nullptr));
        QTableWidgetItem *___qtablewidgetitem70 = tableWidget_3->horizontalHeaderItem(22);
        ___qtablewidgetitem70->setText(QCoreApplication::translate("MainWindow", "\345\215\207\351\231\215\346\240\207\350\257\206", nullptr));
        QTableWidgetItem *___qtablewidgetitem71 = tableWidget_3->horizontalHeaderItem(23);
        ___qtablewidgetitem71->setText(QCoreApplication::translate("MainWindow", "\350\257\257\345\267\256\347\261\273\345\236\213", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_5), QCoreApplication::translate("MainWindow", "\346\255\243\345\274\246\345\215\212\346\263\242\346\243\200\345\256\232\350\257\257\345\267\256", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "\345\237\272\346\234\254\350\257\257\345\267\256", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\346\243\200\345\256\232\344\273\273\345\212\241\345\215\225\347\274\226\345\217\267\357\274\232", nullptr));
        jointA_1->setText(QCoreApplication::translate("MainWindow", "\346\237\245\346\211\276", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", " \346\235\241\345\275\242\347\240\201\357\274\232", nullptr));
        bindInfo->setText(QCoreApplication::translate("MainWindow", "\347\273\221\345\256\232", nullptr));
        QTableWidgetItem *___qtablewidgetitem72 = tableWidget_6->horizontalHeaderItem(0);
        ___qtablewidgetitem72->setText(QCoreApplication::translate("MainWindow", "\346\243\200\345\256\232\344\273\273\345\212\241\345\215\225\347\274\226\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem73 = tableWidget_6->horizontalHeaderItem(1);
        ___qtablewidgetitem73->setText(QCoreApplication::translate("MainWindow", "\344\273\273\345\212\241\344\274\230\345\205\210\347\272\247", nullptr));
        QTableWidgetItem *___qtablewidgetitem74 = tableWidget_6->horizontalHeaderItem(2);
        ___qtablewidgetitem74->setText(QCoreApplication::translate("MainWindow", "\346\243\200\345\256\232\346\226\271\345\274\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem75 = tableWidget_6->horizontalHeaderItem(3);
        ___qtablewidgetitem75->setText(QCoreApplication::translate("MainWindow", "\347\263\273\347\273\237\347\274\226\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem76 = tableWidget_6->horizontalHeaderItem(4);
        ___qtablewidgetitem76->setText(QCoreApplication::translate("MainWindow", "\345\210\260\350\264\247\346\211\271\346\254\241\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem77 = tableWidget_6->horizontalHeaderItem(5);
        ___qtablewidgetitem77->setText(QCoreApplication::translate("MainWindow", "\350\256\276\345\244\207\347\261\273\345\210\253", nullptr));
        QTableWidgetItem *___qtablewidgetitem78 = tableWidget_6->horizontalHeaderItem(6);
        ___qtablewidgetitem78->setText(QCoreApplication::translate("MainWindow", "\350\256\276\345\244\207\345\236\213\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem79 = tableWidget_6->horizontalHeaderItem(7);
        ___qtablewidgetitem79->setText(QCoreApplication::translate("MainWindow", "\347\211\251\346\226\231\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem80 = tableWidget_6->horizontalHeaderItem(8);
        ___qtablewidgetitem80->setText(QCoreApplication::translate("MainWindow", "\346\243\200\345\256\232\346\226\271\346\241\210\346\240\207\350\257\206", nullptr));
        QTableWidgetItem *___qtablewidgetitem81 = tableWidget_6->horizontalHeaderItem(9);
        ___qtablewidgetitem81->setText(QCoreApplication::translate("MainWindow", "\345\244\215\346\243\200\346\226\271\346\241\210\346\240\207\350\257\206", nullptr));
        QTableWidgetItem *___qtablewidgetitem82 = tableWidget_6->horizontalHeaderItem(10);
        ___qtablewidgetitem82->setText(QCoreApplication::translate("MainWindow", "\346\230\257\345\220\246\345\244\215\346\243\200", nullptr));
        QTableWidgetItem *___qtablewidgetitem83 = tableWidget_6->horizontalHeaderItem(11);
        ___qtablewidgetitem83->setText(QCoreApplication::translate("MainWindow", "\345\244\215\346\243\200\346\225\260\351\207\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem84 = tableWidget_6->horizontalHeaderItem(12);
        ___qtablewidgetitem84->setText(QCoreApplication::translate("MainWindow", "\350\256\276\345\244\207\346\225\260\351\207\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem85 = tableWidget_6->horizontalHeaderItem(13);
        ___qtablewidgetitem85->setText(QCoreApplication::translate("MainWindow", "\345\236\233\346\200\273\346\225\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem86 = tableWidget_6->horizontalHeaderItem(14);
        ___qtablewidgetitem86->setText(QCoreApplication::translate("MainWindow", "\346\243\200\351\252\214\344\272\272", nullptr));
        QTableWidgetItem *___qtablewidgetitem87 = tableWidget_6->horizontalHeaderItem(15);
        ___qtablewidgetitem87->setText(QCoreApplication::translate("MainWindow", "\346\240\270\351\252\214\344\272\272", nullptr));
        QTableWidgetItem *___qtablewidgetitem88 = tableWidget_6->horizontalHeaderItem(16);
        ___qtablewidgetitem88->setText(QCoreApplication::translate("MainWindow", "\346\230\257\345\220\246\350\207\252\345\212\250\346\226\275\345\260\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem89 = tableWidget_6->horizontalHeaderItem(17);
        ___qtablewidgetitem89->setText(QCoreApplication::translate("MainWindow", "\344\273\273\345\212\241\347\212\266\346\200\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem90 = tableWidget_6->horizontalHeaderItem(18);
        ___qtablewidgetitem90->setText(QCoreApplication::translate("MainWindow", "\345\271\263\345\217\260\345\206\231\345\205\245\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem91 = tableWidget_6->horizontalHeaderItem(19);
        ___qtablewidgetitem91->setText(QCoreApplication::translate("MainWindow", "\345\244\204\347\220\206\346\240\207\350\256\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem92 = tableWidget_6->horizontalHeaderItem(20);
        ___qtablewidgetitem92->setText(QCoreApplication::translate("MainWindow", "\345\244\204\347\220\206\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem93 = tableWidget_6->horizontalHeaderItem(21);
        ___qtablewidgetitem93->setText(QCoreApplication::translate("MainWindow", "\346\226\260\350\256\276\345\244\207\347\240\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem94 = tableWidget_6->horizontalHeaderItem(22);
        ___qtablewidgetitem94->setText(QCoreApplication::translate("MainWindow", "\345\217\230\346\233\264\345\217\202\346\225\260\347\261\273\345\236\213", nullptr));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_7), QCoreApplication::translate("MainWindow", "\346\243\200\345\256\232\344\273\273\345\212\241", nullptr));
        QTableWidgetItem *___qtablewidgetitem95 = tableWidget_5->horizontalHeaderItem(0);
        ___qtablewidgetitem95->setText(QCoreApplication::translate("MainWindow", "\346\243\200\345\256\232\344\273\273\345\212\241\345\215\225\347\274\226\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem96 = tableWidget_5->horizontalHeaderItem(1);
        ___qtablewidgetitem96->setText(QCoreApplication::translate("MainWindow", "\347\263\273\347\273\237\347\274\226\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem97 = tableWidget_5->horizontalHeaderItem(2);
        ___qtablewidgetitem97->setText(QCoreApplication::translate("MainWindow", "\347\224\250\350\241\250\347\224\263\350\257\267\344\273\273\345\212\241\347\274\226\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem98 = tableWidget_5->horizontalHeaderItem(3);
        ___qtablewidgetitem98->setText(QCoreApplication::translate("MainWindow", "\345\210\260\350\264\247\346\211\271\346\254\241\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem99 = tableWidget_5->horizontalHeaderItem(4);
        ___qtablewidgetitem99->setText(QCoreApplication::translate("MainWindow", "\350\256\276\345\244\207\347\261\273\345\210\253", nullptr));
        QTableWidgetItem *___qtablewidgetitem100 = tableWidget_5->horizontalHeaderItem(5);
        ___qtablewidgetitem100->setText(QCoreApplication::translate("MainWindow", "\350\256\276\345\244\207\346\235\241\345\275\242\347\240\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem101 = tableWidget_5->horizontalHeaderItem(6);
        ___qtablewidgetitem101->setText(QCoreApplication::translate("MainWindow", "\347\256\261\346\235\241\345\275\242\347\240\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem102 = tableWidget_5->horizontalHeaderItem(7);
        ___qtablewidgetitem102->setText(QCoreApplication::translate("MainWindow", "\345\236\233\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem103 = tableWidget_5->horizontalHeaderItem(8);
        ___qtablewidgetitem103->setText(QCoreApplication::translate("MainWindow", "\346\212\275\346\243\200\345\244\215\346\243\200\346\240\207\350\257\206", nullptr));
        QTableWidgetItem *___qtablewidgetitem104 = tableWidget_5->horizontalHeaderItem(9);
        ___qtablewidgetitem104->setText(QCoreApplication::translate("MainWindow", "\347\253\231\345\217\260\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem105 = tableWidget_5->horizontalHeaderItem(10);
        ___qtablewidgetitem105->setText(QCoreApplication::translate("MainWindow", "\344\272\272\345\221\230\347\274\226\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem106 = tableWidget_5->horizontalHeaderItem(11);
        ___qtablewidgetitem106->setText(QCoreApplication::translate("MainWindow", "\345\217\260\344\275\223\347\261\273\345\236\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem107 = tableWidget_5->horizontalHeaderItem(12);
        ___qtablewidgetitem107->setText(QCoreApplication::translate("MainWindow", "\345\271\263\345\217\260\345\206\231\345\205\245\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem108 = tableWidget_5->horizontalHeaderItem(13);
        ___qtablewidgetitem108->setText(QCoreApplication::translate("MainWindow", "\345\244\204\347\220\206\346\240\207\350\256\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem109 = tableWidget_5->horizontalHeaderItem(14);
        ___qtablewidgetitem109->setText(QCoreApplication::translate("MainWindow", "\345\244\204\347\220\206\346\227\266\351\227\264", nullptr));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_6), QCoreApplication::translate("MainWindow", "\345\207\272\345\272\223\346\230\216\347\273\206", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "\345\237\272\347\241\200\344\277\241\346\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
