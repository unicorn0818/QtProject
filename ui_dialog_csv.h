/********************************************************************************
** Form generated from reading UI file 'dialog_csv.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_CSV_H
#define UI_DIALOG_CSV_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog_CSV
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btOk;
    QPushButton *btCancel;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QDoubleSpinBox *sample;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;

    void setupUi(QDialog *Dialog_CSV)
    {
        if (Dialog_CSV->objectName().isEmpty())
            Dialog_CSV->setObjectName(QStringLiteral("Dialog_CSV"));
        Dialog_CSV->resize(300, 200);
        Dialog_CSV->setMinimumSize(QSize(300, 200));
        Dialog_CSV->setMaximumSize(QSize(300, 200));
        gridLayout = new QGridLayout(Dialog_CSV);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(10);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        btOk = new QPushButton(Dialog_CSV);
        btOk->setObjectName(QStringLiteral("btOk"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btOk->sizePolicy().hasHeightForWidth());
        btOk->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(btOk);

        btCancel = new QPushButton(Dialog_CSV);
        btCancel->setObjectName(QStringLiteral("btCancel"));
        sizePolicy.setHeightForWidth(btCancel->sizePolicy().hasHeightForWidth());
        btCancel->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(btCancel);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(Dialog_CSV);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        sample = new QDoubleSpinBox(Dialog_CSV);
        sample->setObjectName(QStringLiteral("sample"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(sample->sizePolicy().hasHeightForWidth());
        sample->setSizePolicy(sizePolicy1);
        sample->setMaximum(9999);
        sample->setValue(6.4);

        horizontalLayout_3->addWidget(sample);


        gridLayout->addLayout(horizontalLayout_3, 1, 0, 1, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(Dialog_CSV);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(Dialog_CSV);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        sizePolicy1.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy1);
        lineEdit->setStyleSheet(QStringLiteral("font: 12pt \"Agency FB\";"));

        horizontalLayout->addWidget(lineEdit);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 2);


        retranslateUi(Dialog_CSV);

        QMetaObject::connectSlotsByName(Dialog_CSV);
    } // setupUi

    void retranslateUi(QDialog *Dialog_CSV)
    {
        Dialog_CSV->setWindowTitle(QApplication::translate("Dialog_CSV", "Dialog", 0));
        btOk->setText(QApplication::translate("Dialog_CSV", "\347\241\256\350\256\244", 0));
        btCancel->setText(QApplication::translate("Dialog_CSV", "\345\217\226\346\266\210", 0));
        label_2->setText(QApplication::translate("Dialog_CSV", "\345\216\237\345\247\213\351\207\207\346\240\267\347\216\207", 0));
        sample->setSuffix(QApplication::translate("Dialog_CSV", "k", 0));
        label->setText(QApplication::translate("Dialog_CSV", "\345\234\272\346\231\257\345\220\215", 0));
        lineEdit->setText(QApplication::translate("Dialog_CSV", "TEST", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog_CSV: public Ui_Dialog_CSV {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_CSV_H
