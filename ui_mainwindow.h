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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *load_file;
    QComboBox *comboBox;
    QRadioButton *radioButton;
    QPushButton *file_path;
    QPushButton *check_data;
    QPushButton *resolution_ratio;
    QPushButton *quit_system;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QPushButton *output_info;
    QPushButton *clear_info;
    QTextBrowser *textBrowser;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTableView *tableView_a;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *last_a;
    QPushButton *go_to_a;
    QSpinBox *go_index_a;
    QPushButton *next_a;
    QHBoxLayout *horizontalLayout_3;
    QLabel *now_index_a;
    QLabel *label_12;
    QLabel *all_index_a;
    QLabel *label_8;
    QTabWidget *tabWidget_2;
    QWidget *tab_3;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QTableView *tableView_b;
    QHBoxLayout *horizontalLayout_7;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *last_b;
    QPushButton *go_to_b;
    QSpinBox *go_index_b;
    QPushButton *next_b;
    QHBoxLayout *horizontalLayout_4;
    QLabel *now_index_b;
    QLabel *label_13;
    QLabel *all_index_b;
    QLabel *label_9;
    QWidget *tab_4;
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_4;
    QTableView *tableView_b_2;
    QHBoxLayout *horizontalLayout_11;
    QHBoxLayout *horizontalLayout_12;
    QPushButton *last_b_2;
    QPushButton *go_to_b_2;
    QSpinBox *go_index_b_2;
    QPushButton *next_b_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *now_index_b_2;
    QLabel *label_14;
    QLabel *all_index_b_2;
    QLabel *label_10;
    QWidget *tab_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(729, 591);
        MainWindow->setStyleSheet(QStringLiteral(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setStyleSheet(QStringLiteral(""));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_2 = new QGridLayout(tab);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        load_file = new QPushButton(tab);
        load_file->setObjectName(QStringLiteral("load_file"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(load_file->sizePolicy().hasHeightForWidth());
        load_file->setSizePolicy(sizePolicy);
        load_file->setMinimumSize(QSize(0, 40));

        horizontalLayout_8->addWidget(load_file);

        comboBox = new QComboBox(tab);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        sizePolicy.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy);
        comboBox->setMinimumSize(QSize(0, 40));

        horizontalLayout_8->addWidget(comboBox);

        radioButton = new QRadioButton(tab);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        horizontalLayout_8->addWidget(radioButton);

        file_path = new QPushButton(tab);
        file_path->setObjectName(QStringLiteral("file_path"));
        sizePolicy.setHeightForWidth(file_path->sizePolicy().hasHeightForWidth());
        file_path->setSizePolicy(sizePolicy);
        file_path->setMinimumSize(QSize(0, 40));

        horizontalLayout_8->addWidget(file_path);

        check_data = new QPushButton(tab);
        check_data->setObjectName(QStringLiteral("check_data"));
        sizePolicy.setHeightForWidth(check_data->sizePolicy().hasHeightForWidth());
        check_data->setSizePolicy(sizePolicy);
        check_data->setMinimumSize(QSize(0, 40));

        horizontalLayout_8->addWidget(check_data);

        resolution_ratio = new QPushButton(tab);
        resolution_ratio->setObjectName(QStringLiteral("resolution_ratio"));
        resolution_ratio->setMinimumSize(QSize(0, 40));

        horizontalLayout_8->addWidget(resolution_ratio);

        quit_system = new QPushButton(tab);
        quit_system->setObjectName(QStringLiteral("quit_system"));
        quit_system->setMinimumSize(QSize(0, 40));

        horizontalLayout_8->addWidget(quit_system);


        gridLayout_2->addLayout(horizontalLayout_8, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(label_3);

        output_info = new QPushButton(tab);
        output_info->setObjectName(QStringLiteral("output_info"));

        horizontalLayout->addWidget(output_info);

        clear_info = new QPushButton(tab);
        clear_info->setObjectName(QStringLiteral("clear_info"));

        horizontalLayout->addWidget(clear_info);


        gridLayout_2->addLayout(horizontalLayout, 1, 0, 1, 1);

        textBrowser = new QTextBrowser(tab);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        sizePolicy1.setHeightForWidth(textBrowser->sizePolicy().hasHeightForWidth());
        textBrowser->setSizePolicy(sizePolicy1);
        textBrowser->setStyleSheet(QString::fromUtf8("border-image: url(:/\345\233\276\347\211\2071.png);\n"
"font: 12pt \"Agency FB\";"));

        gridLayout_2->addWidget(textBrowser, 2, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        tableView_a = new QTableView(tab);
        tableView_a->setObjectName(QStringLiteral("tableView_a"));
        tableView_a->setMinimumSize(QSize(400, 0));

        verticalLayout->addWidget(tableView_a);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(0);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(1);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(1, -1, -1, 1);
        last_a = new QPushButton(tab);
        last_a->setObjectName(QStringLiteral("last_a"));
        sizePolicy.setHeightForWidth(last_a->sizePolicy().hasHeightForWidth());
        last_a->setSizePolicy(sizePolicy);
        last_a->setMinimumSize(QSize(10, 10));
        last_a->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_6->addWidget(last_a);

        go_to_a = new QPushButton(tab);
        go_to_a->setObjectName(QStringLiteral("go_to_a"));

        horizontalLayout_6->addWidget(go_to_a);

        go_index_a = new QSpinBox(tab);
        go_index_a->setObjectName(QStringLiteral("go_index_a"));
        sizePolicy1.setHeightForWidth(go_index_a->sizePolicy().hasHeightForWidth());
        go_index_a->setSizePolicy(sizePolicy1);
        go_index_a->setWrapping(true);
        go_index_a->setMinimum(1);
        go_index_a->setMaximum(1);

        horizontalLayout_6->addWidget(go_index_a);

        next_a = new QPushButton(tab);
        next_a->setObjectName(QStringLiteral("next_a"));
        sizePolicy.setHeightForWidth(next_a->sizePolicy().hasHeightForWidth());
        next_a->setSizePolicy(sizePolicy);
        next_a->setMinimumSize(QSize(10, 10));
        next_a->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_6->addWidget(next_a);

        horizontalLayout_6->setStretch(0, 2);
        horizontalLayout_6->setStretch(1, 1);
        horizontalLayout_6->setStretch(2, 2);
        horizontalLayout_6->setStretch(3, 2);

        horizontalLayout_9->addLayout(horizontalLayout_6);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(1);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, -1, 0, -1);
        now_index_a = new QLabel(tab);
        now_index_a->setObjectName(QStringLiteral("now_index_a"));

        horizontalLayout_3->addWidget(now_index_a);

        label_12 = new QLabel(tab);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_3->addWidget(label_12);

        all_index_a = new QLabel(tab);
        all_index_a->setObjectName(QStringLiteral("all_index_a"));

        horizontalLayout_3->addWidget(all_index_a);

        label_8 = new QLabel(tab);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_3->addWidget(label_8);


        horizontalLayout_9->addLayout(horizontalLayout_3);


        verticalLayout->addLayout(horizontalLayout_9);


        horizontalLayout_2->addLayout(verticalLayout);

        tabWidget_2 = new QTabWidget(tab);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        gridLayout_3 = new QGridLayout(tab_3);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_2 = new QLabel(tab_3);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);

        tableView_b = new QTableView(tab_3);
        tableView_b->setObjectName(QStringLiteral("tableView_b"));

        verticalLayout_2->addWidget(tableView_b);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(1);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(1, -1, -1, 1);
        last_b = new QPushButton(tab_3);
        last_b->setObjectName(QStringLiteral("last_b"));
        sizePolicy.setHeightForWidth(last_b->sizePolicy().hasHeightForWidth());
        last_b->setSizePolicy(sizePolicy);
        last_b->setMinimumSize(QSize(10, 10));
        last_b->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_10->addWidget(last_b);

        go_to_b = new QPushButton(tab_3);
        go_to_b->setObjectName(QStringLiteral("go_to_b"));

        horizontalLayout_10->addWidget(go_to_b);

        go_index_b = new QSpinBox(tab_3);
        go_index_b->setObjectName(QStringLiteral("go_index_b"));
        sizePolicy1.setHeightForWidth(go_index_b->sizePolicy().hasHeightForWidth());
        go_index_b->setSizePolicy(sizePolicy1);
        go_index_b->setWrapping(true);
        go_index_b->setMinimum(1);
        go_index_b->setMaximum(1);

        horizontalLayout_10->addWidget(go_index_b);

        next_b = new QPushButton(tab_3);
        next_b->setObjectName(QStringLiteral("next_b"));
        sizePolicy.setHeightForWidth(next_b->sizePolicy().hasHeightForWidth());
        next_b->setSizePolicy(sizePolicy);
        next_b->setMinimumSize(QSize(10, 10));
        next_b->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_10->addWidget(next_b);

        horizontalLayout_10->setStretch(0, 2);
        horizontalLayout_10->setStretch(1, 1);
        horizontalLayout_10->setStretch(2, 2);
        horizontalLayout_10->setStretch(3, 2);

        horizontalLayout_7->addLayout(horizontalLayout_10);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, -1, 0, -1);
        now_index_b = new QLabel(tab_3);
        now_index_b->setObjectName(QStringLiteral("now_index_b"));

        horizontalLayout_4->addWidget(now_index_b);

        label_13 = new QLabel(tab_3);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout_4->addWidget(label_13);

        all_index_b = new QLabel(tab_3);
        all_index_b->setObjectName(QStringLiteral("all_index_b"));

        horizontalLayout_4->addWidget(all_index_b);

        label_9 = new QLabel(tab_3);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_4->addWidget(label_9);


        horizontalLayout_7->addLayout(horizontalLayout_4);


        verticalLayout_2->addLayout(horizontalLayout_7);


        gridLayout_3->addLayout(verticalLayout_2, 0, 0, 1, 1);

        tabWidget_2->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        gridLayout_4 = new QGridLayout(tab_4);
        gridLayout_4->setSpacing(0);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_4 = new QLabel(tab_4);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_3->addWidget(label_4);

        tableView_b_2 = new QTableView(tab_4);
        tableView_b_2->setObjectName(QStringLiteral("tableView_b_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tableView_b_2->sizePolicy().hasHeightForWidth());
        tableView_b_2->setSizePolicy(sizePolicy2);

        verticalLayout_3->addWidget(tableView_b_2);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(0);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(1);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(1, -1, -1, 1);
        last_b_2 = new QPushButton(tab_4);
        last_b_2->setObjectName(QStringLiteral("last_b_2"));
        sizePolicy.setHeightForWidth(last_b_2->sizePolicy().hasHeightForWidth());
        last_b_2->setSizePolicy(sizePolicy);
        last_b_2->setMinimumSize(QSize(10, 10));
        last_b_2->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_12->addWidget(last_b_2);

        go_to_b_2 = new QPushButton(tab_4);
        go_to_b_2->setObjectName(QStringLiteral("go_to_b_2"));

        horizontalLayout_12->addWidget(go_to_b_2);

        go_index_b_2 = new QSpinBox(tab_4);
        go_index_b_2->setObjectName(QStringLiteral("go_index_b_2"));
        sizePolicy1.setHeightForWidth(go_index_b_2->sizePolicy().hasHeightForWidth());
        go_index_b_2->setSizePolicy(sizePolicy1);
        go_index_b_2->setWrapping(true);
        go_index_b_2->setMinimum(1);
        go_index_b_2->setMaximum(1);

        horizontalLayout_12->addWidget(go_index_b_2);

        next_b_2 = new QPushButton(tab_4);
        next_b_2->setObjectName(QStringLiteral("next_b_2"));
        sizePolicy.setHeightForWidth(next_b_2->sizePolicy().hasHeightForWidth());
        next_b_2->setSizePolicy(sizePolicy);
        next_b_2->setMinimumSize(QSize(10, 10));
        next_b_2->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_12->addWidget(next_b_2);

        horizontalLayout_12->setStretch(0, 2);
        horizontalLayout_12->setStretch(1, 1);
        horizontalLayout_12->setStretch(2, 2);
        horizontalLayout_12->setStretch(3, 2);

        horizontalLayout_11->addLayout(horizontalLayout_12);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(1);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(-1, -1, 0, -1);
        now_index_b_2 = new QLabel(tab_4);
        now_index_b_2->setObjectName(QStringLiteral("now_index_b_2"));

        horizontalLayout_5->addWidget(now_index_b_2);

        label_14 = new QLabel(tab_4);
        label_14->setObjectName(QStringLiteral("label_14"));

        horizontalLayout_5->addWidget(label_14);

        all_index_b_2 = new QLabel(tab_4);
        all_index_b_2->setObjectName(QStringLiteral("all_index_b_2"));

        horizontalLayout_5->addWidget(all_index_b_2);

        label_10 = new QLabel(tab_4);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_5->addWidget(label_10);


        horizontalLayout_11->addLayout(horizontalLayout_5);


        verticalLayout_3->addLayout(horizontalLayout_11);


        gridLayout_4->addLayout(verticalLayout_3, 0, 0, 1, 1);

        tabWidget_2->addTab(tab_4, QString());

        horizontalLayout_2->addWidget(tabWidget_2);


        gridLayout_2->addLayout(horizontalLayout_2, 3, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\350\202\245\347\214\252\345\257\271\350\264\246\345\212\251\346\211\213 V1.0.1", 0));
        load_file->setText(QApplication::translate("MainWindow", "\345\257\274\345\205\245", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\346\261\207\346\200\273\350\241\250", 0)
         << QApplication::translate("MainWindow", "\345\245\227\351\244\220\345\256\236\346\224\266\350\241\250", 0)
         << QApplication::translate("MainWindow", "\344\273\230\346\254\276\345\256\236\346\224\266\350\241\250", 0)
        );
        radioButton->setText(QApplication::translate("MainWindow", " \345\220\210\346\225\260\346\215\256", 0));
        file_path->setText(QApplication::translate("MainWindow", "\346\226\207\344\273\266\350\267\257\345\276\204", 0));
        check_data->setText(QApplication::translate("MainWindow", "\346\257\224\345\257\271", 0));
        resolution_ratio->setText(QApplication::translate("MainWindow", "\345\205\250\345\261\217", 0));
        quit_system->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", 0));
        label_3->setText(QApplication::translate("MainWindow", "\350\276\223\345\207\272\344\277\241\346\201\257", 0));
        output_info->setText(QApplication::translate("MainWindow", "\345\257\274\345\207\272", 0));
        clear_info->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272", 0));
        label->setText(QApplication::translate("MainWindow", "\346\261\207\346\200\273\350\241\250", 0));
        last_a->setText(QApplication::translate("MainWindow", "\344\270\212\344\270\200\351\241\265", 0));
        go_to_a->setText(QApplication::translate("MainWindow", "\350\267\263\350\275\254\350\207\263", 0));
        go_index_a->setSuffix(QString());
        go_index_a->setPrefix(QString());
        next_a->setText(QApplication::translate("MainWindow", "\344\270\213\344\270\200\351\241\265", 0));
        now_index_a->setText(QApplication::translate("MainWindow", "1", 0));
        label_12->setText(QApplication::translate("MainWindow", "/", 0));
        all_index_a->setText(QApplication::translate("MainWindow", "1", 0));
        label_8->setText(QApplication::translate("MainWindow", "\351\241\265", 0));
        label_2->setText(QApplication::translate("MainWindow", "\345\245\227\351\244\220\345\256\236\346\224\266\350\241\250", 0));
        last_b->setText(QApplication::translate("MainWindow", "\344\270\212\344\270\200\351\241\265", 0));
        go_to_b->setText(QApplication::translate("MainWindow", "\350\267\263\350\275\254\350\207\263", 0));
        go_index_b->setSuffix(QString());
        go_index_b->setPrefix(QString());
        next_b->setText(QApplication::translate("MainWindow", "\344\270\213\344\270\200\351\241\265", 0));
        now_index_b->setText(QApplication::translate("MainWindow", "1", 0));
        label_13->setText(QApplication::translate("MainWindow", "/", 0));
        all_index_b->setText(QApplication::translate("MainWindow", "1", 0));
        label_9->setText(QApplication::translate("MainWindow", "\351\241\265", 0));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_3), QApplication::translate("MainWindow", "Tab 1", 0));
        label_4->setText(QApplication::translate("MainWindow", "\344\273\230\346\254\276\345\256\236\346\224\266\350\241\250", 0));
        last_b_2->setText(QApplication::translate("MainWindow", "\344\270\212\344\270\200\351\241\265", 0));
        go_to_b_2->setText(QApplication::translate("MainWindow", "\350\267\263\350\275\254\350\207\263", 0));
        go_index_b_2->setSuffix(QString());
        go_index_b_2->setPrefix(QString());
        next_b_2->setText(QApplication::translate("MainWindow", "\344\270\213\344\270\200\351\241\265", 0));
        now_index_b_2->setText(QApplication::translate("MainWindow", "1", 0));
        label_14->setText(QApplication::translate("MainWindow", "/", 0));
        all_index_b_2->setText(QApplication::translate("MainWindow", "1", 0));
        label_10->setText(QApplication::translate("MainWindow", "\351\241\265", 0));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QApplication::translate("MainWindow", "Tab 2", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Tab 1", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Tab 2", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
