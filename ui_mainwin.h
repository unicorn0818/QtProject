/********************************************************************************
** Form generated from reading UI file 'mainwin.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIN_H
#define UI_MAINWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
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
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWin
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_15;
    QTabWidget *ALLTW;
    QWidget *tab;
    QGridLayout *gridLayout_4;
    QTabWidget *DetailTW;
    QWidget *tab_1;
    QGridLayout *gridLayout_5;
    QTableWidget *BaseInfo;
    QWidget *tab2;
    QGridLayout *gridLayout_14;
    QListWidget *listWidget;
    QVBoxLayout *verticalLayout_3;
    QFrame *frame_3;
    QGridLayout *gridLayout_6;
    QPushButton *ClearBT;
    QPushButton *UpLoadBT;
    QTabWidget *error_table;
    QWidget *tab_4;
    QGridLayout *gridLayout_7;
    QTableWidget *error_Info1;
    QWidget *tab_7;
    QGridLayout *gridLayout;
    QTableWidget *error_Info2;
    QWidget *tab_2;
    QGridLayout *gridLayout_13;
    QFrame *frame_2;
    QGridLayout *gridLayout_11;
    QPushButton *ClearTable;
    QPushButton *UpdateWebBT;
    QTableWidget *UpdateWeb;
    QWidget *tab_3;
    QGridLayout *gridLayout_12;
    QFrame *frame;
    QGridLayout *gridLayout_10;
    QPushButton *DownLoadLog;
    QPushButton *ClearLog;
    QTextBrowser *ShowLog;
    QWidget *tab3;
    QGridLayout *gridLayout_9;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *HostNameLE;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLineEdit *PortLE;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *UserNameLE;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLineEdit *PassWordLE;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QLineEdit *DataBaseNameLE;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *LinkDBBT;
    QPushButton *DisLinkDBBT;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_8;
    QHBoxLayout *horizontalLayout_13;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_8;
    QLineEdit *DETECT_EQUIP_NO;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_9;
    QLineEdit *DETECT_UNIT_NO;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_6;
    QLineEdit *WebUrlLE;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_7;
    QLineEdit *FileNameLE;
    QPushButton *OpenFileBT;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QMainWindow *MainWin)
    {
        if (MainWin->objectName().isEmpty())
            MainWin->setObjectName(QString::fromUtf8("MainWin"));
        MainWin->resize(1116, 723);
        centralwidget = new QWidget(MainWin);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_15 = new QGridLayout(centralwidget);
        gridLayout_15->setSpacing(2);
        gridLayout_15->setObjectName(QString::fromUtf8("gridLayout_15"));
        gridLayout_15->setContentsMargins(2, 2, 2, 2);
        ALLTW = new QTabWidget(centralwidget);
        ALLTW->setObjectName(QString::fromUtf8("ALLTW"));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(12);
        font.setBold(false);
        font.setWeight(50);
        ALLTW->setFont(font);
        ALLTW->setStyleSheet(QString::fromUtf8("\n"
"QTabBar::tab{width:200}\n"
"QTabBar::tab{height:80}\n"
"\n"
""));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_4 = new QGridLayout(tab);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        DetailTW = new QTabWidget(tab);
        DetailTW->setObjectName(QString::fromUtf8("DetailTW"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(10);
        DetailTW->setFont(font1);
        DetailTW->setStyleSheet(QString::fromUtf8("QTabBar::tab{width:180}\n"
"\n"
"QTabBar::tab{height:40}\n"
"border-color: rgb(115, 57, 46);"));
        tab_1 = new QWidget();
        tab_1->setObjectName(QString::fromUtf8("tab_1"));
        gridLayout_5 = new QGridLayout(tab_1);
        gridLayout_5->setSpacing(2);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(2, 2, 2, 2);
        BaseInfo = new QTableWidget(tab_1);
        if (BaseInfo->columnCount() < 20)
            BaseInfo->setColumnCount(20);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        BaseInfo->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        BaseInfo->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        BaseInfo->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        BaseInfo->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        BaseInfo->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        BaseInfo->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        BaseInfo->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        BaseInfo->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        BaseInfo->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        BaseInfo->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        BaseInfo->setHorizontalHeaderItem(10, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        BaseInfo->setHorizontalHeaderItem(11, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        BaseInfo->setHorizontalHeaderItem(12, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        BaseInfo->setHorizontalHeaderItem(13, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        BaseInfo->setHorizontalHeaderItem(14, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        BaseInfo->setHorizontalHeaderItem(15, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        BaseInfo->setHorizontalHeaderItem(16, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        BaseInfo->setHorizontalHeaderItem(17, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        BaseInfo->setHorizontalHeaderItem(18, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        BaseInfo->setHorizontalHeaderItem(19, __qtablewidgetitem19);
        BaseInfo->setObjectName(QString::fromUtf8("BaseInfo"));
        BaseInfo->setMinimumSize(QSize(1001, 481));
        QFont font2;
        font2.setPointSize(10);
        BaseInfo->setFont(font2);
        BaseInfo->setStyleSheet(QString::fromUtf8(""));

        gridLayout_5->addWidget(BaseInfo, 0, 0, 1, 1);

        DetailTW->addTab(tab_1, QString());

        gridLayout_4->addWidget(DetailTW, 0, 0, 1, 1);

        ALLTW->addTab(tab, QString());
        tab2 = new QWidget();
        tab2->setObjectName(QString::fromUtf8("tab2"));
        gridLayout_14 = new QGridLayout(tab2);
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        listWidget = new QListWidget(tab2);
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::NoBrush);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(listWidget);
        __qlistwidgetitem->setForeground(brush);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy);
        QFont font3;
        font3.setPointSize(9);
        listWidget->setFont(font3);
        listWidget->setStyleSheet(QString::fromUtf8(""));

        gridLayout_14->addWidget(listWidget, 0, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        frame_3 = new QFrame(tab2);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        gridLayout_6 = new QGridLayout(frame_3);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        ClearBT = new QPushButton(frame_3);
        ClearBT->setObjectName(QString::fromUtf8("ClearBT"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(ClearBT->sizePolicy().hasHeightForWidth());
        ClearBT->setSizePolicy(sizePolicy1);
        ClearBT->setMinimumSize(QSize(0, 70));
        ClearBT->setStyleSheet(QString::fromUtf8("font: 16pt \"Agency FB\";"));

        gridLayout_6->addWidget(ClearBT, 1, 1, 1, 1);

        UpLoadBT = new QPushButton(frame_3);
        UpLoadBT->setObjectName(QString::fromUtf8("UpLoadBT"));
        sizePolicy1.setHeightForWidth(UpLoadBT->sizePolicy().hasHeightForWidth());
        UpLoadBT->setSizePolicy(sizePolicy1);
        UpLoadBT->setMinimumSize(QSize(0, 70));
        UpLoadBT->setStyleSheet(QString::fromUtf8("font: 16pt \"Agency FB\";"));

        gridLayout_6->addWidget(UpLoadBT, 1, 0, 1, 1);


        verticalLayout_3->addWidget(frame_3);

        error_table = new QTabWidget(tab2);
        error_table->setObjectName(QString::fromUtf8("error_table"));
        sizePolicy.setHeightForWidth(error_table->sizePolicy().hasHeightForWidth());
        error_table->setSizePolicy(sizePolicy);
        error_table->setFont(font1);
        error_table->setLayoutDirection(Qt::LeftToRight);
        error_table->setStyleSheet(QString::fromUtf8("QTabBar::tab{width:180}\n"
"\n"
"QTabBar::tab{height:40}\n"
"background-color: qlineargradient(spread:pad, x1:0.03125, y1:1, x2:0, y2:0, stop:0 rgba(37, 44, 106, 255), stop:1 rgba(255, 255, 255, 255));"));
        error_table->setTabPosition(QTabWidget::North);
        error_table->setTabShape(QTabWidget::Rounded);
        error_table->setIconSize(QSize(16, 16));
        error_table->setElideMode(Qt::ElideRight);
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        gridLayout_7 = new QGridLayout(tab_4);
        gridLayout_7->setSpacing(2);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setContentsMargins(2, 2, 2, 2);
        error_Info1 = new QTableWidget(tab_4);
        if (error_Info1->columnCount() < 38)
            error_Info1->setColumnCount(38);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        error_Info1->setHorizontalHeaderItem(0, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        error_Info1->setHorizontalHeaderItem(1, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        error_Info1->setHorizontalHeaderItem(2, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        error_Info1->setHorizontalHeaderItem(3, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        error_Info1->setHorizontalHeaderItem(4, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        error_Info1->setHorizontalHeaderItem(5, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        error_Info1->setHorizontalHeaderItem(6, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        error_Info1->setHorizontalHeaderItem(7, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        error_Info1->setHorizontalHeaderItem(8, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        error_Info1->setHorizontalHeaderItem(9, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        error_Info1->setHorizontalHeaderItem(10, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        error_Info1->setHorizontalHeaderItem(11, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        error_Info1->setHorizontalHeaderItem(12, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        error_Info1->setHorizontalHeaderItem(13, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        error_Info1->setHorizontalHeaderItem(14, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        error_Info1->setHorizontalHeaderItem(15, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        error_Info1->setHorizontalHeaderItem(16, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        error_Info1->setHorizontalHeaderItem(17, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        error_Info1->setHorizontalHeaderItem(18, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        error_Info1->setHorizontalHeaderItem(19, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        error_Info1->setHorizontalHeaderItem(20, __qtablewidgetitem40);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        error_Info1->setHorizontalHeaderItem(21, __qtablewidgetitem41);
        QTableWidgetItem *__qtablewidgetitem42 = new QTableWidgetItem();
        error_Info1->setHorizontalHeaderItem(22, __qtablewidgetitem42);
        QTableWidgetItem *__qtablewidgetitem43 = new QTableWidgetItem();
        error_Info1->setHorizontalHeaderItem(23, __qtablewidgetitem43);
        QTableWidgetItem *__qtablewidgetitem44 = new QTableWidgetItem();
        error_Info1->setHorizontalHeaderItem(24, __qtablewidgetitem44);
        QTableWidgetItem *__qtablewidgetitem45 = new QTableWidgetItem();
        error_Info1->setHorizontalHeaderItem(25, __qtablewidgetitem45);
        QTableWidgetItem *__qtablewidgetitem46 = new QTableWidgetItem();
        error_Info1->setHorizontalHeaderItem(26, __qtablewidgetitem46);
        QTableWidgetItem *__qtablewidgetitem47 = new QTableWidgetItem();
        error_Info1->setHorizontalHeaderItem(27, __qtablewidgetitem47);
        QTableWidgetItem *__qtablewidgetitem48 = new QTableWidgetItem();
        error_Info1->setHorizontalHeaderItem(28, __qtablewidgetitem48);
        QTableWidgetItem *__qtablewidgetitem49 = new QTableWidgetItem();
        error_Info1->setHorizontalHeaderItem(29, __qtablewidgetitem49);
        QTableWidgetItem *__qtablewidgetitem50 = new QTableWidgetItem();
        error_Info1->setHorizontalHeaderItem(30, __qtablewidgetitem50);
        QTableWidgetItem *__qtablewidgetitem51 = new QTableWidgetItem();
        error_Info1->setHorizontalHeaderItem(31, __qtablewidgetitem51);
        QTableWidgetItem *__qtablewidgetitem52 = new QTableWidgetItem();
        error_Info1->setHorizontalHeaderItem(32, __qtablewidgetitem52);
        QTableWidgetItem *__qtablewidgetitem53 = new QTableWidgetItem();
        error_Info1->setHorizontalHeaderItem(33, __qtablewidgetitem53);
        QTableWidgetItem *__qtablewidgetitem54 = new QTableWidgetItem();
        error_Info1->setHorizontalHeaderItem(34, __qtablewidgetitem54);
        QTableWidgetItem *__qtablewidgetitem55 = new QTableWidgetItem();
        error_Info1->setHorizontalHeaderItem(35, __qtablewidgetitem55);
        QTableWidgetItem *__qtablewidgetitem56 = new QTableWidgetItem();
        error_Info1->setHorizontalHeaderItem(36, __qtablewidgetitem56);
        QTableWidgetItem *__qtablewidgetitem57 = new QTableWidgetItem();
        error_Info1->setHorizontalHeaderItem(37, __qtablewidgetitem57);
        error_Info1->setObjectName(QString::fromUtf8("error_Info1"));
        error_Info1->setFont(font2);
        error_Info1->setStyleSheet(QString::fromUtf8(""));

        gridLayout_7->addWidget(error_Info1, 0, 0, 1, 1);

        error_table->addTab(tab_4, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QString::fromUtf8("tab_7"));
        gridLayout = new QGridLayout(tab_7);
        gridLayout->setSpacing(2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(2, 2, 2, 2);
        error_Info2 = new QTableWidget(tab_7);
        if (error_Info2->columnCount() < 26)
            error_Info2->setColumnCount(26);
        QTableWidgetItem *__qtablewidgetitem58 = new QTableWidgetItem();
        error_Info2->setHorizontalHeaderItem(0, __qtablewidgetitem58);
        QTableWidgetItem *__qtablewidgetitem59 = new QTableWidgetItem();
        error_Info2->setHorizontalHeaderItem(1, __qtablewidgetitem59);
        QTableWidgetItem *__qtablewidgetitem60 = new QTableWidgetItem();
        error_Info2->setHorizontalHeaderItem(2, __qtablewidgetitem60);
        QTableWidgetItem *__qtablewidgetitem61 = new QTableWidgetItem();
        error_Info2->setHorizontalHeaderItem(3, __qtablewidgetitem61);
        QTableWidgetItem *__qtablewidgetitem62 = new QTableWidgetItem();
        error_Info2->setHorizontalHeaderItem(4, __qtablewidgetitem62);
        QTableWidgetItem *__qtablewidgetitem63 = new QTableWidgetItem();
        error_Info2->setHorizontalHeaderItem(5, __qtablewidgetitem63);
        QTableWidgetItem *__qtablewidgetitem64 = new QTableWidgetItem();
        error_Info2->setHorizontalHeaderItem(6, __qtablewidgetitem64);
        QTableWidgetItem *__qtablewidgetitem65 = new QTableWidgetItem();
        error_Info2->setHorizontalHeaderItem(7, __qtablewidgetitem65);
        QTableWidgetItem *__qtablewidgetitem66 = new QTableWidgetItem();
        error_Info2->setHorizontalHeaderItem(8, __qtablewidgetitem66);
        QTableWidgetItem *__qtablewidgetitem67 = new QTableWidgetItem();
        error_Info2->setHorizontalHeaderItem(9, __qtablewidgetitem67);
        QTableWidgetItem *__qtablewidgetitem68 = new QTableWidgetItem();
        error_Info2->setHorizontalHeaderItem(10, __qtablewidgetitem68);
        QTableWidgetItem *__qtablewidgetitem69 = new QTableWidgetItem();
        error_Info2->setHorizontalHeaderItem(11, __qtablewidgetitem69);
        QTableWidgetItem *__qtablewidgetitem70 = new QTableWidgetItem();
        error_Info2->setHorizontalHeaderItem(12, __qtablewidgetitem70);
        QTableWidgetItem *__qtablewidgetitem71 = new QTableWidgetItem();
        error_Info2->setHorizontalHeaderItem(13, __qtablewidgetitem71);
        QTableWidgetItem *__qtablewidgetitem72 = new QTableWidgetItem();
        error_Info2->setHorizontalHeaderItem(14, __qtablewidgetitem72);
        QTableWidgetItem *__qtablewidgetitem73 = new QTableWidgetItem();
        error_Info2->setHorizontalHeaderItem(15, __qtablewidgetitem73);
        QTableWidgetItem *__qtablewidgetitem74 = new QTableWidgetItem();
        error_Info2->setHorizontalHeaderItem(16, __qtablewidgetitem74);
        QTableWidgetItem *__qtablewidgetitem75 = new QTableWidgetItem();
        error_Info2->setHorizontalHeaderItem(17, __qtablewidgetitem75);
        QTableWidgetItem *__qtablewidgetitem76 = new QTableWidgetItem();
        error_Info2->setHorizontalHeaderItem(18, __qtablewidgetitem76);
        QTableWidgetItem *__qtablewidgetitem77 = new QTableWidgetItem();
        error_Info2->setHorizontalHeaderItem(19, __qtablewidgetitem77);
        QTableWidgetItem *__qtablewidgetitem78 = new QTableWidgetItem();
        error_Info2->setHorizontalHeaderItem(20, __qtablewidgetitem78);
        QTableWidgetItem *__qtablewidgetitem79 = new QTableWidgetItem();
        error_Info2->setHorizontalHeaderItem(21, __qtablewidgetitem79);
        QTableWidgetItem *__qtablewidgetitem80 = new QTableWidgetItem();
        error_Info2->setHorizontalHeaderItem(22, __qtablewidgetitem80);
        QTableWidgetItem *__qtablewidgetitem81 = new QTableWidgetItem();
        error_Info2->setHorizontalHeaderItem(23, __qtablewidgetitem81);
        QTableWidgetItem *__qtablewidgetitem82 = new QTableWidgetItem();
        error_Info2->setHorizontalHeaderItem(24, __qtablewidgetitem82);
        QTableWidgetItem *__qtablewidgetitem83 = new QTableWidgetItem();
        error_Info2->setHorizontalHeaderItem(25, __qtablewidgetitem83);
        error_Info2->setObjectName(QString::fromUtf8("error_Info2"));
        error_Info2->setFont(font2);
        error_Info2->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(error_Info2, 0, 0, 1, 1);

        error_table->addTab(tab_7, QString());

        verticalLayout_3->addWidget(error_table);


        gridLayout_14->addLayout(verticalLayout_3, 0, 1, 1, 1);

        ALLTW->addTab(tab2, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_13 = new QGridLayout(tab_2);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        frame_2 = new QFrame(tab_2);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_11 = new QGridLayout(frame_2);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        ClearTable = new QPushButton(frame_2);
        ClearTable->setObjectName(QString::fromUtf8("ClearTable"));
        ClearTable->setMinimumSize(QSize(0, 70));
        ClearTable->setStyleSheet(QString::fromUtf8("font: 16pt \"Agency FB\";"));

        gridLayout_11->addWidget(ClearTable, 0, 1, 1, 1);

        UpdateWebBT = new QPushButton(frame_2);
        UpdateWebBT->setObjectName(QString::fromUtf8("UpdateWebBT"));
        UpdateWebBT->setMinimumSize(QSize(0, 70));
        UpdateWebBT->setStyleSheet(QString::fromUtf8("font: 16pt \"Agency FB\";"));

        gridLayout_11->addWidget(UpdateWebBT, 0, 0, 1, 1);


        gridLayout_13->addWidget(frame_2, 0, 0, 1, 1);

        UpdateWeb = new QTableWidget(tab_2);
        if (UpdateWeb->columnCount() < 6)
            UpdateWeb->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem84 = new QTableWidgetItem();
        UpdateWeb->setHorizontalHeaderItem(0, __qtablewidgetitem84);
        QTableWidgetItem *__qtablewidgetitem85 = new QTableWidgetItem();
        UpdateWeb->setHorizontalHeaderItem(1, __qtablewidgetitem85);
        QTableWidgetItem *__qtablewidgetitem86 = new QTableWidgetItem();
        UpdateWeb->setHorizontalHeaderItem(2, __qtablewidgetitem86);
        QTableWidgetItem *__qtablewidgetitem87 = new QTableWidgetItem();
        UpdateWeb->setHorizontalHeaderItem(3, __qtablewidgetitem87);
        QTableWidgetItem *__qtablewidgetitem88 = new QTableWidgetItem();
        UpdateWeb->setHorizontalHeaderItem(4, __qtablewidgetitem88);
        QTableWidgetItem *__qtablewidgetitem89 = new QTableWidgetItem();
        UpdateWeb->setHorizontalHeaderItem(5, __qtablewidgetitem89);
        UpdateWeb->setObjectName(QString::fromUtf8("UpdateWeb"));
        UpdateWeb->setSizeIncrement(QSize(1, 0));
        UpdateWeb->setStyleSheet(QString::fromUtf8(""));
        UpdateWeb->horizontalHeader()->setMinimumSectionSize(200);
        UpdateWeb->horizontalHeader()->setDefaultSectionSize(200);
        UpdateWeb->horizontalHeader()->setHighlightSections(true);
        UpdateWeb->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        UpdateWeb->horizontalHeader()->setStretchLastSection(false);
        UpdateWeb->verticalHeader()->setDefaultSectionSize(60);

        gridLayout_13->addWidget(UpdateWeb, 1, 0, 1, 1);

        ALLTW->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        gridLayout_12 = new QGridLayout(tab_3);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        frame = new QFrame(tab_3);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_10 = new QGridLayout(frame);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        DownLoadLog = new QPushButton(frame);
        DownLoadLog->setObjectName(QString::fromUtf8("DownLoadLog"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(DownLoadLog->sizePolicy().hasHeightForWidth());
        DownLoadLog->setSizePolicy(sizePolicy2);
        DownLoadLog->setMinimumSize(QSize(0, 70));
        DownLoadLog->setStyleSheet(QString::fromUtf8("font: 16pt \"Agency FB\";"));

        gridLayout_10->addWidget(DownLoadLog, 0, 0, 1, 1);

        ClearLog = new QPushButton(frame);
        ClearLog->setObjectName(QString::fromUtf8("ClearLog"));
        sizePolicy2.setHeightForWidth(ClearLog->sizePolicy().hasHeightForWidth());
        ClearLog->setSizePolicy(sizePolicy2);
        ClearLog->setMinimumSize(QSize(0, 70));
        ClearLog->setStyleSheet(QString::fromUtf8("font: 16pt \"Agency FB\";"));

        gridLayout_10->addWidget(ClearLog, 0, 1, 1, 1);


        gridLayout_12->addWidget(frame, 0, 0, 1, 1);

        ShowLog = new QTextBrowser(tab_3);
        ShowLog->setObjectName(QString::fromUtf8("ShowLog"));
        ShowLog->setStyleSheet(QString::fromUtf8(""));

        gridLayout_12->addWidget(ShowLog, 1, 0, 1, 1);

        ALLTW->addTab(tab_3, QString());
        tab3 = new QWidget();
        tab3->setObjectName(QString::fromUtf8("tab3"));
        gridLayout_9 = new QGridLayout(tab3);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        groupBox = new QGroupBox(tab3);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy3);
        groupBox->setMinimumSize(QSize(600, 0));
        groupBox->setFont(font1);
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font1);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label);

        HostNameLE = new QLineEdit(groupBox);
        HostNameLE->setObjectName(QString::fromUtf8("HostNameLE"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(HostNameLE->sizePolicy().hasHeightForWidth());
        HostNameLE->setSizePolicy(sizePolicy4);

        horizontalLayout->addWidget(HostNameLE);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);
        label_4->setLayoutDirection(Qt::LeftToRight);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_4);

        PortLE = new QLineEdit(groupBox);
        PortLE->setObjectName(QString::fromUtf8("PortLE"));
        sizePolicy4.setHeightForWidth(PortLE->sizePolicy().hasHeightForWidth());
        PortLE->setSizePolicy(sizePolicy4);

        horizontalLayout_2->addWidget(PortLE);


        gridLayout_2->addLayout(horizontalLayout_2, 0, 1, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);
        label_2->setLayoutDirection(Qt::LeftToRight);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_2);

        UserNameLE = new QLineEdit(groupBox);
        UserNameLE->setObjectName(QString::fromUtf8("UserNameLE"));
        sizePolicy4.setHeightForWidth(UserNameLE->sizePolicy().hasHeightForWidth());
        UserNameLE->setSizePolicy(sizePolicy4);

        horizontalLayout_3->addWidget(UserNameLE);


        gridLayout_2->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font1);
        label_5->setLayoutDirection(Qt::LeftToRight);
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(label_5);

        PassWordLE = new QLineEdit(groupBox);
        PassWordLE->setObjectName(QString::fromUtf8("PassWordLE"));
        sizePolicy4.setHeightForWidth(PassWordLE->sizePolicy().hasHeightForWidth());
        PassWordLE->setSizePolicy(sizePolicy4);
        PassWordLE->setEchoMode(QLineEdit::PasswordEchoOnEdit);

        horizontalLayout_4->addWidget(PassWordLE);


        gridLayout_2->addLayout(horizontalLayout_4, 1, 1, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);
        label_3->setLayoutDirection(Qt::LeftToRight);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(label_3);

        DataBaseNameLE = new QLineEdit(groupBox);
        DataBaseNameLE->setObjectName(QString::fromUtf8("DataBaseNameLE"));
        sizePolicy4.setHeightForWidth(DataBaseNameLE->sizePolicy().hasHeightForWidth());
        DataBaseNameLE->setSizePolicy(sizePolicy4);

        horizontalLayout_5->addWidget(DataBaseNameLE);


        gridLayout_2->addLayout(horizontalLayout_5, 2, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        LinkDBBT = new QPushButton(groupBox);
        LinkDBBT->setObjectName(QString::fromUtf8("LinkDBBT"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(LinkDBBT->sizePolicy().hasHeightForWidth());
        LinkDBBT->setSizePolicy(sizePolicy5);
        LinkDBBT->setFont(font1);
        LinkDBBT->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_6->addWidget(LinkDBBT);

        DisLinkDBBT = new QPushButton(groupBox);
        DisLinkDBBT->setObjectName(QString::fromUtf8("DisLinkDBBT"));
        sizePolicy5.setHeightForWidth(DisLinkDBBT->sizePolicy().hasHeightForWidth());
        DisLinkDBBT->setSizePolicy(sizePolicy5);
        DisLinkDBBT->setFont(font1);
        DisLinkDBBT->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_6->addWidget(DisLinkDBBT);


        gridLayout_2->addLayout(horizontalLayout_6, 2, 1, 1, 1);


        gridLayout_9->addWidget(groupBox, 0, 1, 1, 1);

        groupBox_4 = new QGroupBox(tab3);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        sizePolicy3.setHeightForWidth(groupBox_4->sizePolicy().hasHeightForWidth());
        groupBox_4->setSizePolicy(sizePolicy3);
        groupBox_4->setMinimumSize(QSize(600, 0));
        groupBox_4->setFont(font1);
        gridLayout_8 = new QGridLayout(groupBox_4);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_8 = new QLabel(groupBox_4);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font1);

        horizontalLayout_11->addWidget(label_8);

        DETECT_EQUIP_NO = new QLineEdit(groupBox_4);
        DETECT_EQUIP_NO->setObjectName(QString::fromUtf8("DETECT_EQUIP_NO"));

        horizontalLayout_11->addWidget(DETECT_EQUIP_NO);


        horizontalLayout_13->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_9 = new QLabel(groupBox_4);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font1);

        horizontalLayout_12->addWidget(label_9);

        DETECT_UNIT_NO = new QLineEdit(groupBox_4);
        DETECT_UNIT_NO->setObjectName(QString::fromUtf8("DETECT_UNIT_NO"));

        horizontalLayout_12->addWidget(DETECT_UNIT_NO);


        horizontalLayout_13->addLayout(horizontalLayout_12);


        gridLayout_8->addLayout(horizontalLayout_13, 0, 0, 1, 1);


        gridLayout_9->addWidget(groupBox_4, 2, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_9->addItem(horizontalSpacer, 1, 2, 1, 1);

        groupBox_3 = new QGroupBox(tab3);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        sizePolicy3.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy3);
        groupBox_3->setMinimumSize(QSize(600, 0));
        groupBox_3->setFont(font1);
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font1);

        horizontalLayout_7->addWidget(label_6);

        WebUrlLE = new QLineEdit(groupBox_3);
        WebUrlLE->setObjectName(QString::fromUtf8("WebUrlLE"));
        WebUrlLE->setMinimumSize(QSize(435, 0));

        horizontalLayout_7->addWidget(WebUrlLE);


        gridLayout_3->addLayout(horizontalLayout_7, 0, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font1);

        horizontalLayout_8->addWidget(label_7);

        FileNameLE = new QLineEdit(groupBox_3);
        FileNameLE->setObjectName(QString::fromUtf8("FileNameLE"));
        sizePolicy1.setHeightForWidth(FileNameLE->sizePolicy().hasHeightForWidth());
        FileNameLE->setSizePolicy(sizePolicy1);

        horizontalLayout_8->addWidget(FileNameLE);

        OpenFileBT = new QPushButton(groupBox_3);
        OpenFileBT->setObjectName(QString::fromUtf8("OpenFileBT"));
        sizePolicy4.setHeightForWidth(OpenFileBT->sizePolicy().hasHeightForWidth());
        OpenFileBT->setSizePolicy(sizePolicy4);
        OpenFileBT->setMinimumSize(QSize(150, 0));
        OpenFileBT->setFont(font1);
        OpenFileBT->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_8->addWidget(OpenFileBT);


        gridLayout_3->addLayout(horizontalLayout_8, 1, 0, 1, 1);


        gridLayout_9->addWidget(groupBox_3, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_9->addItem(horizontalSpacer_2, 1, 0, 1, 1);

        ALLTW->addTab(tab3, QString());

        gridLayout_15->addWidget(ALLTW, 0, 0, 1, 1);

        MainWin->setCentralWidget(centralwidget);

        retranslateUi(MainWin);

        ALLTW->setCurrentIndex(1);
        DetailTW->setCurrentIndex(0);
        error_table->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWin);
    } // setupUi

    void retranslateUi(QMainWindow *MainWin)
    {
        MainWin->setWindowTitle(QCoreApplication::translate("MainWin", "MainWin", nullptr));
        QTableWidgetItem *___qtablewidgetitem = BaseInfo->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWin", "\344\270\273\351\224\256", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = BaseInfo->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWin", "\350\256\276\345\244\207ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = BaseInfo->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWin", "\346\235\241\345\275\242\347\240\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = BaseInfo->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWin", "\350\256\276\345\244\207\345\220\215\347\247\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = BaseInfo->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWin", "\346\243\200\345\256\232\344\273\273\345\212\241\345\215\225\347\274\226\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = BaseInfo->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWin", "\345\255\220\344\273\273\345\212\241\347\274\226\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = BaseInfo->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWin", "\350\256\276\345\244\207\344\270\223\344\270\232", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = BaseInfo->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWin", "\350\256\276\345\244\207\345\244\247\347\261\273", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = BaseInfo->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWin", "\350\256\276\345\244\207\345\260\217\347\261\273", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = BaseInfo->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWin", "\345\210\266\351\200\240\345\215\225\344\275\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = BaseInfo->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWin", "\345\207\272\345\216\202\347\274\226\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = BaseInfo->horizontalHeaderItem(11);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWin", "\345\236\213\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = BaseInfo->horizontalHeaderItem(12);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainWin", "\350\247\204\346\240\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = BaseInfo->horizontalHeaderItem(13);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("MainWin", "\345\207\206\347\241\256\345\272\246\347\255\211\347\272\247", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = BaseInfo->horizontalHeaderItem(14);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("MainWin", "\350\257\201\344\271\246\347\274\226\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = BaseInfo->horizontalHeaderItem(15);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("MainWin", "\347\224\265\345\216\213\346\265\213\351\207\217\350\214\203\345\233\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = BaseInfo->horizontalHeaderItem(16);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("MainWin", "\347\224\265\346\265\201\346\265\213\351\207\217\350\214\203\345\233\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = BaseInfo->horizontalHeaderItem(17);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("MainWin", "\346\214\207\346\240\207\351\241\27124", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = BaseInfo->horizontalHeaderItem(18);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("MainWin", "\346\214\207\346\240\207\351\241\27125", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = BaseInfo->horizontalHeaderItem(19);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("MainWin", "\346\243\200\345\256\232\344\276\235\346\215\256", nullptr));
        DetailTW->setTabText(DetailTW->indexOf(tab_1), QCoreApplication::translate("MainWin", "\347\224\265\350\203\275\350\241\250\345\237\272\346\234\254\344\277\241\346\201\257", nullptr));
        ALLTW->setTabText(ALLTW->indexOf(tab), QCoreApplication::translate("MainWin", "\350\257\246\347\273\206\344\277\241\346\201\257", nullptr));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("MainWin", "\346\235\241\345\275\242\347\240\201", nullptr));
        listWidget->setSortingEnabled(__sortingEnabled);

        ClearBT->setText(QCoreApplication::translate("MainWin", "\346\270\205\347\251\272\350\241\250", nullptr));
        UpLoadBT->setText(QCoreApplication::translate("MainWin", "\344\270\212\344\274\240MDS", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = error_Info1->horizontalHeaderItem(0);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("MainWin", "\344\270\273\351\224\256", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = error_Info1->horizontalHeaderItem(1);
        ___qtablewidgetitem21->setText(QCoreApplication::translate("MainWin", "\350\256\276\345\244\207ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = error_Info1->horizontalHeaderItem(2);
        ___qtablewidgetitem22->setText(QCoreApplication::translate("MainWin", "\346\235\241\345\275\242\347\240\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = error_Info1->horizontalHeaderItem(3);
        ___qtablewidgetitem23->setText(QCoreApplication::translate("MainWin", "\350\256\276\345\244\207\345\220\215\347\247\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = error_Info1->horizontalHeaderItem(4);
        ___qtablewidgetitem24->setText(QCoreApplication::translate("MainWin", "\346\243\200\345\256\232\345\215\225\347\274\226\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = error_Info1->horizontalHeaderItem(5);
        ___qtablewidgetitem25->setText(QCoreApplication::translate("MainWin", "\350\256\276\345\244\207\344\270\223\344\270\232", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = error_Info1->horizontalHeaderItem(6);
        ___qtablewidgetitem26->setText(QCoreApplication::translate("MainWin", "\350\256\276\345\244\207\345\244\247\347\261\273", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = error_Info1->horizontalHeaderItem(7);
        ___qtablewidgetitem27->setText(QCoreApplication::translate("MainWin", "\350\256\276\345\244\207\345\260\217\347\261\273", nullptr));
        QTableWidgetItem *___qtablewidgetitem28 = error_Info1->horizontalHeaderItem(8);
        ___qtablewidgetitem28->setText(QCoreApplication::translate("MainWin", "\350\257\225\351\252\214\351\241\271ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem29 = error_Info1->horizontalHeaderItem(9);
        ___qtablewidgetitem29->setText(QCoreApplication::translate("MainWin", "\350\257\225\351\252\214\351\241\271\345\220\215\347\247\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem30 = error_Info1->horizontalHeaderItem(10);
        ___qtablewidgetitem30->setText(QCoreApplication::translate("MainWin", "\350\257\225\351\252\214\345\210\206\347\273\204", nullptr));
        QTableWidgetItem *___qtablewidgetitem31 = error_Info1->horizontalHeaderItem(11);
        ___qtablewidgetitem31->setText(QCoreApplication::translate("MainWin", "\347\263\273\347\273\237\347\274\226\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem32 = error_Info1->horizontalHeaderItem(12);
        ___qtablewidgetitem32->setText(QCoreApplication::translate("MainWin", "\346\243\200\345\256\232\347\272\277/\345\217\260\344\275\223\347\274\226\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem33 = error_Info1->horizontalHeaderItem(13);
        ___qtablewidgetitem33->setText(QCoreApplication::translate("MainWin", "\346\243\200\345\256\232\345\215\225\345\205\203\347\274\226\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem34 = error_Info1->horizontalHeaderItem(14);
        ___qtablewidgetitem34->setText(QCoreApplication::translate("MainWin", "\350\241\250\344\275\215\347\274\226\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem35 = error_Info1->horizontalHeaderItem(15);
        ___qtablewidgetitem35->setText(QCoreApplication::translate("MainWin", "\346\243\200\345\256\232/\346\240\241\345\207\206\346\227\245\346\234\237", nullptr));
        QTableWidgetItem *___qtablewidgetitem36 = error_Info1->horizontalHeaderItem(16);
        ___qtablewidgetitem36->setText(QCoreApplication::translate("MainWin", "\346\243\200\345\256\232\347\202\271\347\232\204\345\272\217\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem37 = error_Info1->horizontalHeaderItem(17);
        ___qtablewidgetitem37->setText(QCoreApplication::translate("MainWin", "\346\225\260\346\215\256\346\235\245\346\272\220", nullptr));
        QTableWidgetItem *___qtablewidgetitem38 = error_Info1->horizontalHeaderItem(18);
        ___qtablewidgetitem38->setText(QCoreApplication::translate("MainWin", "\346\225\260\346\215\256\347\261\273\345\236\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem39 = error_Info1->horizontalHeaderItem(19);
        ___qtablewidgetitem39->setText(QCoreApplication::translate("MainWin", "\346\270\251\345\272\246", nullptr));
        QTableWidgetItem *___qtablewidgetitem40 = error_Info1->horizontalHeaderItem(20);
        ___qtablewidgetitem40->setText(QCoreApplication::translate("MainWin", "\347\233\270\345\257\271\346\271\277\345\272\246", nullptr));
        QTableWidgetItem *___qtablewidgetitem41 = error_Info1->horizontalHeaderItem(21);
        ___qtablewidgetitem41->setText(QCoreApplication::translate("MainWin", "\346\214\207\346\240\207\351\241\2711", nullptr));
        QTableWidgetItem *___qtablewidgetitem42 = error_Info1->horizontalHeaderItem(22);
        ___qtablewidgetitem42->setText(QCoreApplication::translate("MainWin", "\346\214\207\346\240\207\351\241\2712", nullptr));
        QTableWidgetItem *___qtablewidgetitem43 = error_Info1->horizontalHeaderItem(23);
        ___qtablewidgetitem43->setText(QCoreApplication::translate("MainWin", "\346\214\207\346\240\207\351\241\2713", nullptr));
        QTableWidgetItem *___qtablewidgetitem44 = error_Info1->horizontalHeaderItem(24);
        ___qtablewidgetitem44->setText(QCoreApplication::translate("MainWin", "\346\214\207\346\240\207\351\241\2714", nullptr));
        QTableWidgetItem *___qtablewidgetitem45 = error_Info1->horizontalHeaderItem(25);
        ___qtablewidgetitem45->setText(QCoreApplication::translate("MainWin", "\346\214\207\346\240\207\351\241\2715", nullptr));
        QTableWidgetItem *___qtablewidgetitem46 = error_Info1->horizontalHeaderItem(26);
        ___qtablewidgetitem46->setText(QCoreApplication::translate("MainWin", "\346\214\207\346\240\207\351\241\2716", nullptr));
        QTableWidgetItem *___qtablewidgetitem47 = error_Info1->horizontalHeaderItem(27);
        ___qtablewidgetitem47->setText(QCoreApplication::translate("MainWin", "\346\214\207\346\240\207\351\241\2717", nullptr));
        QTableWidgetItem *___qtablewidgetitem48 = error_Info1->horizontalHeaderItem(28);
        ___qtablewidgetitem48->setText(QCoreApplication::translate("MainWin", "\346\214\207\346\240\207\351\241\2718", nullptr));
        QTableWidgetItem *___qtablewidgetitem49 = error_Info1->horizontalHeaderItem(29);
        ___qtablewidgetitem49->setText(QCoreApplication::translate("MainWin", "\346\214\207\346\240\207\351\241\2719", nullptr));
        QTableWidgetItem *___qtablewidgetitem50 = error_Info1->horizontalHeaderItem(30);
        ___qtablewidgetitem50->setText(QCoreApplication::translate("MainWin", "\346\214\207\346\240\207\351\241\27110", nullptr));
        QTableWidgetItem *___qtablewidgetitem51 = error_Info1->horizontalHeaderItem(31);
        ___qtablewidgetitem51->setText(QCoreApplication::translate("MainWin", "\346\214\207\346\240\207\351\241\27111", nullptr));
        QTableWidgetItem *___qtablewidgetitem52 = error_Info1->horizontalHeaderItem(32);
        ___qtablewidgetitem52->setText(QCoreApplication::translate("MainWin", "\346\214\207\346\240\207\351\241\27112", nullptr));
        QTableWidgetItem *___qtablewidgetitem53 = error_Info1->horizontalHeaderItem(33);
        ___qtablewidgetitem53->setText(QCoreApplication::translate("MainWin", "\346\214\207\346\240\207\351\241\27113", nullptr));
        QTableWidgetItem *___qtablewidgetitem54 = error_Info1->horizontalHeaderItem(34);
        ___qtablewidgetitem54->setText(QCoreApplication::translate("MainWin", "\346\243\200\345\256\232\347\273\223\350\256\272", nullptr));
        QTableWidgetItem *___qtablewidgetitem55 = error_Info1->horizontalHeaderItem(35);
        ___qtablewidgetitem55->setText(QCoreApplication::translate("MainWin", "\345\206\231\345\205\245\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem56 = error_Info1->horizontalHeaderItem(36);
        ___qtablewidgetitem56->setText(QCoreApplication::translate("MainWin", "\345\244\204\347\220\206\346\240\207\350\256\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem57 = error_Info1->horizontalHeaderItem(37);
        ___qtablewidgetitem57->setText(QCoreApplication::translate("MainWin", "\345\244\204\347\220\206\346\227\266\351\227\264", nullptr));
        error_table->setTabText(error_table->indexOf(tab_4), QCoreApplication::translate("MainWin", "\347\224\265\350\203\275\350\241\250\350\257\257\345\267\256\344\277\241\346\201\2571", nullptr));
        QTableWidgetItem *___qtablewidgetitem58 = error_Info2->horizontalHeaderItem(0);
        ___qtablewidgetitem58->setText(QCoreApplication::translate("MainWin", "\344\270\273\351\224\256", nullptr));
        QTableWidgetItem *___qtablewidgetitem59 = error_Info2->horizontalHeaderItem(1);
        ___qtablewidgetitem59->setText(QCoreApplication::translate("MainWin", "\350\256\276\345\244\207ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem60 = error_Info2->horizontalHeaderItem(2);
        ___qtablewidgetitem60->setText(QCoreApplication::translate("MainWin", "\346\235\241\345\275\242\347\240\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem61 = error_Info2->horizontalHeaderItem(3);
        ___qtablewidgetitem61->setText(QCoreApplication::translate("MainWin", "\350\256\276\345\244\207\345\220\215\347\247\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem62 = error_Info2->horizontalHeaderItem(4);
        ___qtablewidgetitem62->setText(QCoreApplication::translate("MainWin", "\346\243\200\345\256\232\345\215\225\347\274\226\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem63 = error_Info2->horizontalHeaderItem(5);
        ___qtablewidgetitem63->setText(QCoreApplication::translate("MainWin", "\350\256\276\345\244\207\344\270\223\344\270\232", nullptr));
        QTableWidgetItem *___qtablewidgetitem64 = error_Info2->horizontalHeaderItem(6);
        ___qtablewidgetitem64->setText(QCoreApplication::translate("MainWin", "\350\256\276\345\244\207\345\244\247\347\261\273", nullptr));
        QTableWidgetItem *___qtablewidgetitem65 = error_Info2->horizontalHeaderItem(7);
        ___qtablewidgetitem65->setText(QCoreApplication::translate("MainWin", "\350\256\276\345\244\207\345\260\217\347\261\273", nullptr));
        QTableWidgetItem *___qtablewidgetitem66 = error_Info2->horizontalHeaderItem(8);
        ___qtablewidgetitem66->setText(QCoreApplication::translate("MainWin", "\350\257\225\351\252\214\351\241\271ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem67 = error_Info2->horizontalHeaderItem(9);
        ___qtablewidgetitem67->setText(QCoreApplication::translate("MainWin", "\350\257\225\351\252\214\351\241\271\345\220\215\347\247\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem68 = error_Info2->horizontalHeaderItem(10);
        ___qtablewidgetitem68->setText(QCoreApplication::translate("MainWin", "\350\257\225\351\252\214\345\210\206\347\273\204", nullptr));
        QTableWidgetItem *___qtablewidgetitem69 = error_Info2->horizontalHeaderItem(11);
        ___qtablewidgetitem69->setText(QCoreApplication::translate("MainWin", "\347\263\273\347\273\237\347\274\226\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem70 = error_Info2->horizontalHeaderItem(12);
        ___qtablewidgetitem70->setText(QCoreApplication::translate("MainWin", "\346\243\200\345\256\232\347\272\277/\345\217\260\344\275\223\347\274\226\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem71 = error_Info2->horizontalHeaderItem(13);
        ___qtablewidgetitem71->setText(QCoreApplication::translate("MainWin", "\346\243\200\345\256\232\345\215\225\345\205\203\347\274\226\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem72 = error_Info2->horizontalHeaderItem(14);
        ___qtablewidgetitem72->setText(QCoreApplication::translate("MainWin", "\350\241\250\344\275\215\347\274\226\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem73 = error_Info2->horizontalHeaderItem(15);
        ___qtablewidgetitem73->setText(QCoreApplication::translate("MainWin", "\346\243\200\345\256\232/\346\240\241\345\207\206\346\227\245\346\234\237", nullptr));
        QTableWidgetItem *___qtablewidgetitem74 = error_Info2->horizontalHeaderItem(16);
        ___qtablewidgetitem74->setText(QCoreApplication::translate("MainWin", "\346\243\200\345\256\232\347\202\271\347\232\204\345\272\217\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem75 = error_Info2->horizontalHeaderItem(17);
        ___qtablewidgetitem75->setText(QCoreApplication::translate("MainWin", "\346\225\260\346\215\256\346\235\245\346\272\220", nullptr));
        QTableWidgetItem *___qtablewidgetitem76 = error_Info2->horizontalHeaderItem(18);
        ___qtablewidgetitem76->setText(QCoreApplication::translate("MainWin", "\346\225\260\346\215\256\347\261\273\345\236\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem77 = error_Info2->horizontalHeaderItem(19);
        ___qtablewidgetitem77->setText(QCoreApplication::translate("MainWin", "\346\270\251\345\272\246", nullptr));
        QTableWidgetItem *___qtablewidgetitem78 = error_Info2->horizontalHeaderItem(20);
        ___qtablewidgetitem78->setText(QCoreApplication::translate("MainWin", "\347\233\270\345\257\271\346\271\277\345\272\246", nullptr));
        QTableWidgetItem *___qtablewidgetitem79 = error_Info2->horizontalHeaderItem(21);
        ___qtablewidgetitem79->setText(QCoreApplication::translate("MainWin", "\346\214\207\346\240\207\351\241\2711", nullptr));
        QTableWidgetItem *___qtablewidgetitem80 = error_Info2->horizontalHeaderItem(22);
        ___qtablewidgetitem80->setText(QCoreApplication::translate("MainWin", "\346\243\200\345\256\232\347\273\223\350\256\272", nullptr));
        QTableWidgetItem *___qtablewidgetitem81 = error_Info2->horizontalHeaderItem(23);
        ___qtablewidgetitem81->setText(QCoreApplication::translate("MainWin", "\345\206\231\345\205\245\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem82 = error_Info2->horizontalHeaderItem(24);
        ___qtablewidgetitem82->setText(QCoreApplication::translate("MainWin", "\345\244\204\347\220\206\346\240\207\350\256\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem83 = error_Info2->horizontalHeaderItem(25);
        ___qtablewidgetitem83->setText(QCoreApplication::translate("MainWin", "\345\244\204\347\220\206\346\227\266\351\227\264", nullptr));
        error_table->setTabText(error_table->indexOf(tab_7), QCoreApplication::translate("MainWin", "\347\224\265\350\203\275\350\241\250\350\257\257\345\267\256\344\277\241\346\201\2572", nullptr));
        ALLTW->setTabText(ALLTW->indexOf(tab2), QCoreApplication::translate("MainWin", "\344\273\273\345\212\241\344\277\241\346\201\257", nullptr));
        ClearTable->setText(QCoreApplication::translate("MainWin", "\346\270\205\347\251\272\350\241\250", nullptr));
        UpdateWebBT->setText(QCoreApplication::translate("MainWin", " \346\233\264\346\226\260Web", nullptr));
        QTableWidgetItem *___qtablewidgetitem84 = UpdateWeb->horizontalHeaderItem(0);
        ___qtablewidgetitem84->setText(QCoreApplication::translate("MainWin", "\346\243\200\351\252\214\344\273\273\345\212\241\345\215\225\347\274\226\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem85 = UpdateWeb->horizontalHeaderItem(1);
        ___qtablewidgetitem85->setText(QCoreApplication::translate("MainWin", "\346\243\200\345\256\232\350\256\276\345\244\207\347\274\226\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem86 = UpdateWeb->horizontalHeaderItem(2);
        ___qtablewidgetitem86->setText(QCoreApplication::translate("MainWin", "\347\212\266\346\200\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem87 = UpdateWeb->horizontalHeaderItem(3);
        ___qtablewidgetitem87->setText(QCoreApplication::translate("MainWin", "\351\224\231\350\257\257\344\277\241\346\201\257", nullptr));
        QTableWidgetItem *___qtablewidgetitem88 = UpdateWeb->horizontalHeaderItem(4);
        ___qtablewidgetitem88->setText(QCoreApplication::translate("MainWin", "\344\270\212\344\274\240\346\216\245\345\217\243", nullptr));
        QTableWidgetItem *___qtablewidgetitem89 = UpdateWeb->horizontalHeaderItem(5);
        ___qtablewidgetitem89->setText(QCoreApplication::translate("MainWin", "\346\227\266\351\227\264", nullptr));
        ALLTW->setTabText(ALLTW->indexOf(tab_2), QCoreApplication::translate("MainWin", "Web\346\233\264\346\226\260", nullptr));
        DownLoadLog->setText(QCoreApplication::translate("MainWin", " \345\257\274\345\207\272", nullptr));
        ClearLog->setText(QCoreApplication::translate("MainWin", " \346\270\205\347\251\272", nullptr));
        ALLTW->setTabText(ALLTW->indexOf(tab_3), QCoreApplication::translate("MainWin", "\346\223\215\344\275\234\346\227\245\350\256\260", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWin", "MDS SQL", nullptr));
        label->setText(QCoreApplication::translate("MainWin", "HostName:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWin", "Port:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWin", "UserName:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWin", "PassWord:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWin", "DataBaseName:", nullptr));
        LinkDBBT->setText(QCoreApplication::translate("MainWin", "\351\223\276\346\216\245", nullptr));
        DisLinkDBBT->setText(QCoreApplication::translate("MainWin", " \346\226\255\345\274\200", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWin", "Local Config", nullptr));
        label_8->setText(QCoreApplication::translate("MainWin", "\346\243\200\345\256\232\347\272\277/\345\217\260\344\275\223\347\274\226\345\217\267", nullptr));
        label_9->setText(QCoreApplication::translate("MainWin", "\346\243\200\345\256\232\345\215\225\345\205\203\347\274\226\345\217\267", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWin", "Web&&Mds Config", nullptr));
        label_6->setText(QCoreApplication::translate("MainWin", "      WebUrl\357\274\232", nullptr));
        label_7->setText(QCoreApplication::translate("MainWin", "\351\211\264\345\256\232\346\225\260\346\215\256\350\241\250\357\274\232", nullptr));
        OpenFileBT->setText(QCoreApplication::translate("MainWin", " \346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
        ALLTW->setTabText(ALLTW->indexOf(tab3), QCoreApplication::translate("MainWin", "\347\263\273\347\273\237\351\205\215\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWin: public Ui_MainWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIN_H
