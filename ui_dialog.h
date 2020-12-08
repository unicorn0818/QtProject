/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QSpinBox *spinBox;
    QLabel *label_2;
    QSpinBox *spinBox_2;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QGridLayout *gridLayout;
    QPushButton *bind_vol;
    QPushButton *bind_ele;
    QPushButton *bind_icon;
    QPushButton *cancel_bt;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(327, 261);
        gridLayout_3 = new QGridLayout(Dialog);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label = new QLabel(Dialog);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        spinBox = new QSpinBox(Dialog);
        spinBox->setObjectName(QStringLiteral("spinBox"));

        gridLayout_2->addWidget(spinBox, 0, 1, 1, 2);

        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        spinBox_2 = new QSpinBox(Dialog);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));

        gridLayout_2->addWidget(spinBox_2, 1, 1, 1, 2);

        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 2, 0, 1, 1);

        lineEdit = new QLineEdit(Dialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout_2->addWidget(lineEdit, 2, 1, 1, 2);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        bind_vol = new QPushButton(Dialog);
        bind_vol->setObjectName(QStringLiteral("bind_vol"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(bind_vol->sizePolicy().hasHeightForWidth());
        bind_vol->setSizePolicy(sizePolicy);

        gridLayout->addWidget(bind_vol, 0, 0, 1, 1);

        bind_ele = new QPushButton(Dialog);
        bind_ele->setObjectName(QStringLiteral("bind_ele"));
        sizePolicy.setHeightForWidth(bind_ele->sizePolicy().hasHeightForWidth());
        bind_ele->setSizePolicy(sizePolicy);

        gridLayout->addWidget(bind_ele, 0, 1, 1, 1);

        bind_icon = new QPushButton(Dialog);
        bind_icon->setObjectName(QStringLiteral("bind_icon"));
        sizePolicy.setHeightForWidth(bind_icon->sizePolicy().hasHeightForWidth());
        bind_icon->setSizePolicy(sizePolicy);

        gridLayout->addWidget(bind_icon, 1, 0, 1, 1);

        cancel_bt = new QPushButton(Dialog);
        cancel_bt->setObjectName(QStringLiteral("cancel_bt"));
        sizePolicy.setHeightForWidth(cancel_bt->sizePolicy().hasHeightForWidth());
        cancel_bt->setSizePolicy(sizePolicy);

        gridLayout->addWidget(cancel_bt, 1, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout, 1, 0, 1, 1);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "\351\200\232\351\201\223\351\205\215\347\275\256", 0));
        label->setText(QApplication::translate("Dialog", "\347\224\265\345\216\213:", 0));
        spinBox->setPrefix(QApplication::translate("Dialog", "\351\200\232\351\201\223:", 0));
        label_2->setText(QApplication::translate("Dialog", "\347\224\265\346\265\201:", 0));
        spinBox_2->setPrefix(QApplication::translate("Dialog", "\351\200\232\351\201\223:", 0));
        label_3->setText(QApplication::translate("Dialog", "\347\224\250\347\224\265\345\231\250:", 0));
        bind_vol->setText(QApplication::translate("Dialog", "\347\273\221\345\256\232\347\224\265\345\216\213", 0));
        bind_ele->setText(QApplication::translate("Dialog", "\347\273\221\345\256\232\347\224\265\346\265\201", 0));
        bind_icon->setText(QApplication::translate("Dialog", "\351\200\211\346\213\251\345\233\276\346\240\207", 0));
        cancel_bt->setText(QApplication::translate("Dialog", "\347\241\256\345\256\232", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
