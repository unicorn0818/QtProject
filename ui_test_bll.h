/********************************************************************************
** Form generated from reading UI file 'test_bll.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEST_BLL_H
#define UI_TEST_BLL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_test_bll
{
public:
    QTextEdit *textEdit;
    QPushButton *pushButton;

    void setupUi(QWidget *test_bll)
    {
        if (test_bll->objectName().isEmpty())
            test_bll->setObjectName(QStringLiteral("test_bll"));
        test_bll->resize(400, 300);
        textEdit = new QTextEdit(test_bll);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(60, 60, 104, 71));
        pushButton = new QPushButton(test_bll);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(90, 160, 75, 23));

        retranslateUi(test_bll);

        QMetaObject::connectSlotsByName(test_bll);
    } // setupUi

    void retranslateUi(QWidget *test_bll)
    {
        test_bll->setWindowTitle(QApplication::translate("test_bll", "Form", 0));
        pushButton->setText(QApplication::translate("test_bll", "send", 0));
    } // retranslateUi

};

namespace Ui {
    class test_bll: public Ui_test_bll {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEST_BLL_H
