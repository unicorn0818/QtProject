/********************************************************************************
** Form generated from reading UI file 'map_control.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAP_CONTROL_H
#define UI_MAP_CONTROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_map_control
{
public:
    QGridLayout *gridLayout;
    QPushButton *move;
    QPushButton *reset;
    QPushButton *reset_2;
    QPushButton *sq;
    QPushButton *all_up;
    QPushButton *all_down;
    QPushButton *sq_x;
    QPushButton *x_up;
    QPushButton *x_down;
    QPushButton *sq_y;
    QPushButton *y_up;
    QPushButton *y_down;
    QButtonGroup *buttonGroup;

    void setupUi(QDialog *map_control)
    {
        if (map_control->objectName().isEmpty())
            map_control->setObjectName(QStringLiteral("map_control"));
        map_control->resize(229, 150);
        gridLayout = new QGridLayout(map_control);
        gridLayout->setSpacing(2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        move = new QPushButton(map_control);
        buttonGroup = new QButtonGroup(map_control);
        buttonGroup->setObjectName(QStringLiteral("buttonGroup"));
        buttonGroup->addButton(move);
        move->setObjectName(QStringLiteral("move"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(move->sizePolicy().hasHeightForWidth());
        move->setSizePolicy(sizePolicy);
        move->setCheckable(true);
        move->setChecked(true);

        gridLayout->addWidget(move, 0, 0, 1, 1);

        reset = new QPushButton(map_control);
        reset->setObjectName(QStringLiteral("reset"));
        sizePolicy.setHeightForWidth(reset->sizePolicy().hasHeightForWidth());
        reset->setSizePolicy(sizePolicy);

        gridLayout->addWidget(reset, 0, 1, 1, 1);

        reset_2 = new QPushButton(map_control);
        reset_2->setObjectName(QStringLiteral("reset_2"));
        sizePolicy.setHeightForWidth(reset_2->sizePolicy().hasHeightForWidth());
        reset_2->setSizePolicy(sizePolicy);

        gridLayout->addWidget(reset_2, 0, 2, 1, 1);

        sq = new QPushButton(map_control);
        buttonGroup->addButton(sq);
        sq->setObjectName(QStringLiteral("sq"));
        sizePolicy.setHeightForWidth(sq->sizePolicy().hasHeightForWidth());
        sq->setSizePolicy(sizePolicy);
        sq->setCheckable(true);

        gridLayout->addWidget(sq, 1, 0, 1, 1);

        all_up = new QPushButton(map_control);
        buttonGroup->addButton(all_up);
        all_up->setObjectName(QStringLiteral("all_up"));
        sizePolicy.setHeightForWidth(all_up->sizePolicy().hasHeightForWidth());
        all_up->setSizePolicy(sizePolicy);
        all_up->setCheckable(true);

        gridLayout->addWidget(all_up, 1, 1, 1, 1);

        all_down = new QPushButton(map_control);
        buttonGroup->addButton(all_down);
        all_down->setObjectName(QStringLiteral("all_down"));
        sizePolicy.setHeightForWidth(all_down->sizePolicy().hasHeightForWidth());
        all_down->setSizePolicy(sizePolicy);
        all_down->setCheckable(true);

        gridLayout->addWidget(all_down, 1, 2, 1, 1);

        sq_x = new QPushButton(map_control);
        buttonGroup->addButton(sq_x);
        sq_x->setObjectName(QStringLiteral("sq_x"));
        sizePolicy.setHeightForWidth(sq_x->sizePolicy().hasHeightForWidth());
        sq_x->setSizePolicy(sizePolicy);
        sq_x->setCheckable(true);

        gridLayout->addWidget(sq_x, 2, 0, 1, 1);

        x_up = new QPushButton(map_control);
        buttonGroup->addButton(x_up);
        x_up->setObjectName(QStringLiteral("x_up"));
        sizePolicy.setHeightForWidth(x_up->sizePolicy().hasHeightForWidth());
        x_up->setSizePolicy(sizePolicy);
        x_up->setCheckable(true);

        gridLayout->addWidget(x_up, 2, 1, 1, 1);

        x_down = new QPushButton(map_control);
        buttonGroup->addButton(x_down);
        x_down->setObjectName(QStringLiteral("x_down"));
        sizePolicy.setHeightForWidth(x_down->sizePolicy().hasHeightForWidth());
        x_down->setSizePolicy(sizePolicy);
        x_down->setCheckable(true);

        gridLayout->addWidget(x_down, 2, 2, 1, 1);

        sq_y = new QPushButton(map_control);
        buttonGroup->addButton(sq_y);
        sq_y->setObjectName(QStringLiteral("sq_y"));
        sizePolicy.setHeightForWidth(sq_y->sizePolicy().hasHeightForWidth());
        sq_y->setSizePolicy(sizePolicy);
        sq_y->setCheckable(true);

        gridLayout->addWidget(sq_y, 3, 0, 1, 1);

        y_up = new QPushButton(map_control);
        buttonGroup->addButton(y_up);
        y_up->setObjectName(QStringLiteral("y_up"));
        sizePolicy.setHeightForWidth(y_up->sizePolicy().hasHeightForWidth());
        y_up->setSizePolicy(sizePolicy);
        y_up->setCheckable(true);

        gridLayout->addWidget(y_up, 3, 1, 1, 1);

        y_down = new QPushButton(map_control);
        buttonGroup->addButton(y_down);
        y_down->setObjectName(QStringLiteral("y_down"));
        sizePolicy.setHeightForWidth(y_down->sizePolicy().hasHeightForWidth());
        y_down->setSizePolicy(sizePolicy);
        y_down->setCheckable(true);

        gridLayout->addWidget(y_down, 3, 2, 1, 1);


        retranslateUi(map_control);

        QMetaObject::connectSlotsByName(map_control);
    } // setupUi

    void retranslateUi(QDialog *map_control)
    {
        map_control->setWindowTitle(QApplication::translate("map_control", "\345\233\276\350\241\250\346\223\215\344\275\234 ", 0));
        move->setText(QApplication::translate("map_control", "\346\213\226\345\212\250", 0));
#ifndef QT_NO_TOOLTIP
        reset->setToolTip(QApplication::translate("map_control", "\346\201\242\345\244\215\345\210\260\345\210\235\345\247\213\350\214\203\345\233\264", 0));
#endif // QT_NO_TOOLTIP
        reset->setText(QApplication::translate("map_control", "\351\207\215\347\275\256", 0));
#ifndef QT_NO_TOOLTIP
        reset_2->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        reset_2->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        reset_2->setText(QApplication::translate("map_control", "\351\207\215\347\273\230", 0));
#ifndef QT_NO_TOOLTIP
        sq->setToolTip(QApplication::translate("map_control", "\344\273\245\351\200\211\346\213\251\345\214\272\345\237\237\345\206\205\347\232\204x\350\275\264\345\222\214y\350\275\264\347\232\204\350\214\203\345\233\264\n"
"\344\275\234\344\270\272x\350\275\264\345\222\214y\350\275\264\347\232\204\346\226\260\350\214\203\345\233\264", 0));
#endif // QT_NO_TOOLTIP
        sq->setText(QApplication::translate("map_control", "\345\235\227\351\200\211\346\213\251", 0));
#ifndef QT_NO_TOOLTIP
        all_up->setToolTip(QApplication::translate("map_control", "\347\202\271\345\207\273\344\270\200\346\254\241\345\260\206x\350\275\264\344\270\216y\350\275\264\347\232\204\350\214\203\345\233\264\346\211\251\345\244\247\350\207\263\345\216\237\346\235\245\347\232\2041.1\345\200\215", 0));
#endif // QT_NO_TOOLTIP
        all_up->setText(QApplication::translate("map_control", "\345\220\214\346\257\224\346\224\276\345\244\247", 0));
#ifndef QT_NO_TOOLTIP
        all_down->setToolTip(QApplication::translate("map_control", "\347\202\271\345\207\273\344\270\200\346\254\241\345\260\206x\350\275\264\344\270\216y\350\275\264\347\232\204\350\214\203\345\233\264\347\274\251\345\260\217\350\207\263\345\216\237\346\235\245\347\232\2040.9\345\200\215", 0));
#endif // QT_NO_TOOLTIP
        all_down->setText(QApplication::translate("map_control", "\345\220\214\346\257\224\347\274\251\345\260\217", 0));
#ifndef QT_NO_TOOLTIP
        sq_x->setToolTip(QApplication::translate("map_control", "\344\273\245\351\200\211\346\213\251\345\214\272\345\237\237\345\206\205\347\232\204x\350\275\264\347\232\204\350\214\203\345\233\264\344\275\234\344\270\272x\350\275\264\347\232\204\346\226\260\350\214\203\345\233\264", 0));
#endif // QT_NO_TOOLTIP
        sq_x->setText(QApplication::translate("map_control", "\345\235\227\351\200\211X\350\275\264", 0));
#ifndef QT_NO_TOOLTIP
        x_up->setToolTip(QApplication::translate("map_control", "\347\202\271\345\207\273\344\270\200\346\254\241\345\260\206x\350\275\264\347\232\204\350\214\203\345\233\264\346\211\251\345\244\247\350\207\263\345\216\237\346\235\245\347\232\2041.1\345\200\215", 0));
#endif // QT_NO_TOOLTIP
        x_up->setText(QApplication::translate("map_control", "X\350\275\264\346\224\276\345\244\247", 0));
#ifndef QT_NO_TOOLTIP
        x_down->setToolTip(QApplication::translate("map_control", "\347\202\271\345\207\273\344\270\200\346\254\241\345\260\206x\350\275\264\347\232\204\350\214\203\345\233\264\347\274\251\345\260\217\350\207\263\345\216\237\346\235\245\347\232\2040.9\345\200\215", 0));
#endif // QT_NO_TOOLTIP
        x_down->setText(QApplication::translate("map_control", "X\350\275\264\347\274\251\345\260\217", 0));
#ifndef QT_NO_TOOLTIP
        sq_y->setToolTip(QApplication::translate("map_control", "\344\273\245\351\200\211\346\213\251\345\214\272\345\237\237\345\206\205\347\232\204y\350\275\264\347\232\204\350\214\203\345\233\264\344\275\234\344\270\272y\350\275\264\347\232\204\346\226\260\350\214\203\345\233\264", 0));
#endif // QT_NO_TOOLTIP
        sq_y->setText(QApplication::translate("map_control", "\345\235\227\351\200\211Y\350\275\264", 0));
#ifndef QT_NO_TOOLTIP
        y_up->setToolTip(QApplication::translate("map_control", "\347\202\271\345\207\273\344\270\200\346\254\241\345\260\206y\350\275\264\347\232\204\350\214\203\345\233\264\346\211\251\345\244\247\350\207\263\345\216\237\346\235\245\347\232\2041.1\345\200\215", 0));
#endif // QT_NO_TOOLTIP
        y_up->setText(QApplication::translate("map_control", "Y\350\275\264\346\224\276\345\244\247", 0));
#ifndef QT_NO_TOOLTIP
        y_down->setToolTip(QApplication::translate("map_control", "\347\202\271\345\207\273\344\270\200\346\254\241\345\260\206y\350\275\264\347\232\204\350\214\203\345\233\264\347\274\251\345\260\217\350\207\263\345\216\237\346\235\245\347\232\2040.9\345\200\215", 0));
#endif // QT_NO_TOOLTIP
        y_down->setText(QApplication::translate("map_control", "Y\350\275\264\347\274\251\345\260\217", 0));
    } // retranslateUi

};

namespace Ui {
    class map_control: public Ui_map_control {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAP_CONTROL_H
