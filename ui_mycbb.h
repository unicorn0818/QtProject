/********************************************************************************
** Form generated from reading UI file 'mycbb.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYCBB_H
#define UI_MYCBB_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyCBB
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QCheckBox *checkBox;
    QLabel *label;

    void setupUi(QWidget *MyCBB)
    {
        if (MyCBB->objectName().isEmpty())
            MyCBB->setObjectName(QStringLiteral("MyCBB"));
        MyCBB->resize(120, 100);
        MyCBB->setMinimumSize(QSize(120, 100));
        MyCBB->setMaximumSize(QSize(120, 100));
        gridLayout = new QGridLayout(MyCBB);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        checkBox = new QCheckBox(MyCBB);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(checkBox->sizePolicy().hasHeightForWidth());
        checkBox->setSizePolicy(sizePolicy);
        checkBox->setMinimumSize(QSize(0, 0));

        verticalLayout->addWidget(checkBox);

        label = new QLabel(MyCBB);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QStringLiteral("Agency FB"));
        font.setPointSize(6);
        label->setFont(font);
        label->setScaledContents(true);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

#ifndef QT_NO_SHORTCUT
        label->setBuddy(checkBox);
#endif // QT_NO_SHORTCUT

        retranslateUi(MyCBB);

        QMetaObject::connectSlotsByName(MyCBB);
    } // setupUi

    void retranslateUi(QWidget *MyCBB)
    {
        MyCBB->setWindowTitle(QApplication::translate("MyCBB", "Form", 0));
        checkBox->setText(QString());
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MyCBB: public Ui_MyCBB {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYCBB_H
