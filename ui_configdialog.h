/********************************************************************************
** Form generated from reading UI file 'configdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGDIALOG_H
#define UI_CONFIGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_configDialog
{
public:
    QGridLayout *gridLayout;
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
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_7;
    QLineEdit *FileNameLE;
    QPushButton *OpenFileBT;

    void setupUi(QDialog *configDialog)
    {
        if (configDialog->objectName().isEmpty())
            configDialog->setObjectName(QString::fromUtf8("configDialog"));
        configDialog->resize(618, 265);
        gridLayout = new QGridLayout(configDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(configDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMinimumSize(QSize(600, 0));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(10);
        groupBox->setFont(font);
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label);

        HostNameLE = new QLineEdit(groupBox);
        HostNameLE->setObjectName(QString::fromUtf8("HostNameLE"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(HostNameLE->sizePolicy().hasHeightForWidth());
        HostNameLE->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(HostNameLE);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);
        label_4->setLayoutDirection(Qt::LeftToRight);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_4);

        PortLE = new QLineEdit(groupBox);
        PortLE->setObjectName(QString::fromUtf8("PortLE"));
        sizePolicy1.setHeightForWidth(PortLE->sizePolicy().hasHeightForWidth());
        PortLE->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(PortLE);


        gridLayout_2->addLayout(horizontalLayout_2, 0, 1, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);
        label_2->setLayoutDirection(Qt::LeftToRight);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_2);

        UserNameLE = new QLineEdit(groupBox);
        UserNameLE->setObjectName(QString::fromUtf8("UserNameLE"));
        sizePolicy1.setHeightForWidth(UserNameLE->sizePolicy().hasHeightForWidth());
        UserNameLE->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(UserNameLE);


        gridLayout_2->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);
        label_5->setLayoutDirection(Qt::LeftToRight);
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(label_5);

        PassWordLE = new QLineEdit(groupBox);
        PassWordLE->setObjectName(QString::fromUtf8("PassWordLE"));
        sizePolicy1.setHeightForWidth(PassWordLE->sizePolicy().hasHeightForWidth());
        PassWordLE->setSizePolicy(sizePolicy1);
        PassWordLE->setEchoMode(QLineEdit::PasswordEchoOnEdit);

        horizontalLayout_4->addWidget(PassWordLE);


        gridLayout_2->addLayout(horizontalLayout_4, 1, 1, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);
        label_3->setLayoutDirection(Qt::LeftToRight);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(label_3);

        DataBaseNameLE = new QLineEdit(groupBox);
        DataBaseNameLE->setObjectName(QString::fromUtf8("DataBaseNameLE"));
        sizePolicy1.setHeightForWidth(DataBaseNameLE->sizePolicy().hasHeightForWidth());
        DataBaseNameLE->setSizePolicy(sizePolicy1);

        horizontalLayout_5->addWidget(DataBaseNameLE);


        gridLayout_2->addLayout(horizontalLayout_5, 2, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        LinkDBBT = new QPushButton(groupBox);
        LinkDBBT->setObjectName(QString::fromUtf8("LinkDBBT"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(LinkDBBT->sizePolicy().hasHeightForWidth());
        LinkDBBT->setSizePolicy(sizePolicy2);
        LinkDBBT->setFont(font);
        LinkDBBT->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_6->addWidget(LinkDBBT);

        DisLinkDBBT = new QPushButton(groupBox);
        DisLinkDBBT->setObjectName(QString::fromUtf8("DisLinkDBBT"));
        sizePolicy2.setHeightForWidth(DisLinkDBBT->sizePolicy().hasHeightForWidth());
        DisLinkDBBT->setSizePolicy(sizePolicy2);
        DisLinkDBBT->setFont(font);
        DisLinkDBBT->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_6->addWidget(DisLinkDBBT);


        gridLayout_2->addLayout(horizontalLayout_6, 2, 1, 1, 1);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_3 = new QGroupBox(configDialog);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        sizePolicy.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy);
        groupBox_3->setMinimumSize(QSize(600, 0));
        groupBox_3->setFont(font);
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);

        horizontalLayout_8->addWidget(label_7);

        FileNameLE = new QLineEdit(groupBox_3);
        FileNameLE->setObjectName(QString::fromUtf8("FileNameLE"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(FileNameLE->sizePolicy().hasHeightForWidth());
        FileNameLE->setSizePolicy(sizePolicy3);

        horizontalLayout_8->addWidget(FileNameLE);

        OpenFileBT = new QPushButton(groupBox_3);
        OpenFileBT->setObjectName(QString::fromUtf8("OpenFileBT"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(OpenFileBT->sizePolicy().hasHeightForWidth());
        OpenFileBT->setSizePolicy(sizePolicy4);
        OpenFileBT->setMinimumSize(QSize(150, 0));
        OpenFileBT->setFont(font);
        OpenFileBT->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_8->addWidget(OpenFileBT);


        gridLayout_3->addLayout(horizontalLayout_8, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox_3, 1, 0, 1, 1);


        retranslateUi(configDialog);

        QMetaObject::connectSlotsByName(configDialog);
    } // setupUi

    void retranslateUi(QDialog *configDialog)
    {
        configDialog->setWindowTitle(QCoreApplication::translate("configDialog", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("configDialog", "MDS SQL", nullptr));
        label->setText(QCoreApplication::translate("configDialog", "HostName:", nullptr));
        label_4->setText(QCoreApplication::translate("configDialog", "Port:", nullptr));
        label_2->setText(QCoreApplication::translate("configDialog", "UserName:", nullptr));
        label_5->setText(QCoreApplication::translate("configDialog", "PassWord:", nullptr));
        label_3->setText(QCoreApplication::translate("configDialog", "DataBaseName:", nullptr));
        LinkDBBT->setText(QCoreApplication::translate("configDialog", "\351\223\276\346\216\245", nullptr));
        DisLinkDBBT->setText(QCoreApplication::translate("configDialog", " \346\226\255\345\274\200", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("configDialog", "XML Config", nullptr));
        label_7->setText(QCoreApplication::translate("configDialog", "\351\211\264\345\256\232\346\225\260\346\215\256\350\241\250\357\274\232", nullptr));
        OpenFileBT->setText(QCoreApplication::translate("configDialog", " \346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class configDialog: public Ui_configDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGDIALOG_H
