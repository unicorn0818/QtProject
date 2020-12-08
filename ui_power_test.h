/********************************************************************************
** Form generated from reading UI file 'power_test.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POWER_TEST_H
#define UI_POWER_TEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_power_test
{
public:
    QGridLayout *gridLayout_3;
    QFrame *frame;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *u_test;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *r_test;
    QPushButton *read_u_r;
    QFrame *frame_2;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QDoubleSpinBox *i_out;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QDoubleSpinBox *u_end;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_4;
    QDoubleSpinBox *out_time;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_11;
    QLabel *label_10;
    QDoubleSpinBox *u_range;
    QVBoxLayout *verticalLayout_12;
    QLabel *label_11;
    QDoubleSpinBox *i_range;
    QPushButton *start_test;
    QFrame *frame_3;
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_5;
    QDoubleSpinBox *u_value;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_6;
    QDoubleSpinBox *r_value;
    QVBoxLayout *verticalLayout_9;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_9;
    QDoubleSpinBox *u_start_value;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_8;
    QDoubleSpinBox *power_size;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_14;
    QLabel *label_13;
    QDoubleSpinBox *temp;
    QVBoxLayout *verticalLayout_15;
    QLabel *label_14;
    QDoubleSpinBox *now_i;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_7;
    QLineEdit *test_time;

    void setupUi(QWidget *power_test)
    {
        if (power_test->objectName().isEmpty())
            power_test->setObjectName(QStringLiteral("power_test"));
        power_test->resize(800, 520);
        gridLayout_3 = new QGridLayout(power_test);
        gridLayout_3->setSpacing(2);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(2, 2, 2, 2);
        frame = new QFrame(power_test);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        frame->setLineWidth(2);
        gridLayout = new QGridLayout(frame);
        gridLayout->setSpacing(2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(2, 2, 2, 2);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        u_test = new QPushButton(frame);
        u_test->setObjectName(QStringLiteral("u_test"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(u_test->sizePolicy().hasHeightForWidth());
        u_test->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(15);
        u_test->setFont(font);

        horizontalLayout->addWidget(u_test);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        r_test = new QPushButton(frame);
        r_test->setObjectName(QStringLiteral("r_test"));
        sizePolicy.setHeightForWidth(r_test->sizePolicy().hasHeightForWidth());
        r_test->setSizePolicy(sizePolicy);
        r_test->setFont(font);

        horizontalLayout_3->addWidget(r_test);


        gridLayout->addLayout(horizontalLayout_3, 0, 1, 1, 1);

        read_u_r = new QPushButton(frame);
        read_u_r->setObjectName(QStringLiteral("read_u_r"));
        sizePolicy.setHeightForWidth(read_u_r->sizePolicy().hasHeightForWidth());
        read_u_r->setSizePolicy(sizePolicy);
        read_u_r->setFont(font);

        gridLayout->addWidget(read_u_r, 1, 0, 1, 2);


        gridLayout_3->addWidget(frame, 1, 0, 1, 1);

        frame_2 = new QFrame(power_test);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::Box);
        frame_2->setFrameShadow(QFrame::Raised);
        frame_2->setLineWidth(2);
        gridLayout_2 = new QGridLayout(frame_2);
        gridLayout_2->setSpacing(2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(2, 2, 2, 2);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(frame_2);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        i_out = new QDoubleSpinBox(frame_2);
        i_out->setObjectName(QStringLiteral("i_out"));
        sizePolicy.setHeightForWidth(i_out->sizePolicy().hasHeightForWidth());
        i_out->setSizePolicy(sizePolicy);
        i_out->setFont(font);
        i_out->setAlignment(Qt::AlignCenter);
        i_out->setDecimals(3);
        i_out->setMaximum(500);

        verticalLayout->addWidget(i_out);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_3 = new QLabel(frame_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_3);

        u_end = new QDoubleSpinBox(frame_2);
        u_end->setObjectName(QStringLiteral("u_end"));
        sizePolicy.setHeightForWidth(u_end->sizePolicy().hasHeightForWidth());
        u_end->setSizePolicy(sizePolicy);
        u_end->setFont(font);
        u_end->setAlignment(Qt::AlignCenter);
        u_end->setDecimals(3);
        u_end->setMaximum(1000);

        verticalLayout_2->addWidget(u_end);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_4 = new QLabel(frame_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_4);

        out_time = new QDoubleSpinBox(frame_2);
        out_time->setObjectName(QStringLiteral("out_time"));
        sizePolicy.setHeightForWidth(out_time->sizePolicy().hasHeightForWidth());
        out_time->setSizePolicy(sizePolicy);
        out_time->setFont(font);
        out_time->setAlignment(Qt::AlignCenter);
        out_time->setDecimals(3);
        out_time->setMaximum(999999);

        verticalLayout_3->addWidget(out_time);


        horizontalLayout_2->addLayout(verticalLayout_3);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 1);
        horizontalLayout_2->setStretch(2, 1);

        gridLayout_2->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(2);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setSpacing(2);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        label_10 = new QLabel(frame_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font);
        label_10->setAlignment(Qt::AlignCenter);

        verticalLayout_11->addWidget(label_10);

        u_range = new QDoubleSpinBox(frame_2);
        u_range->setObjectName(QStringLiteral("u_range"));
        sizePolicy.setHeightForWidth(u_range->sizePolicy().hasHeightForWidth());
        u_range->setSizePolicy(sizePolicy);
        u_range->setFont(font);
        u_range->setAlignment(Qt::AlignCenter);
        u_range->setDecimals(3);
        u_range->setMaximum(500);

        verticalLayout_11->addWidget(u_range);


        horizontalLayout_5->addLayout(verticalLayout_11);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setSpacing(2);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        label_11 = new QLabel(frame_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setFont(font);
        label_11->setAlignment(Qt::AlignCenter);

        verticalLayout_12->addWidget(label_11);

        i_range = new QDoubleSpinBox(frame_2);
        i_range->setObjectName(QStringLiteral("i_range"));
        sizePolicy.setHeightForWidth(i_range->sizePolicy().hasHeightForWidth());
        i_range->setSizePolicy(sizePolicy);
        i_range->setFont(font);
        i_range->setAlignment(Qt::AlignCenter);
        i_range->setDecimals(3);
        i_range->setMaximum(1e+07);

        verticalLayout_12->addWidget(i_range);


        horizontalLayout_5->addLayout(verticalLayout_12);

        horizontalLayout_5->setStretch(0, 1);
        horizontalLayout_5->setStretch(1, 1);

        gridLayout_2->addLayout(horizontalLayout_5, 1, 0, 1, 1);

        start_test = new QPushButton(frame_2);
        start_test->setObjectName(QStringLiteral("start_test"));
        sizePolicy.setHeightForWidth(start_test->sizePolicy().hasHeightForWidth());
        start_test->setSizePolicy(sizePolicy);
        start_test->setFont(font);
        start_test->setCheckable(true);

        gridLayout_2->addWidget(start_test, 2, 0, 1, 1);


        gridLayout_3->addWidget(frame_2, 1, 1, 1, 1);

        frame_3 = new QFrame(power_test);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setFrameShape(QFrame::Box);
        frame_3->setFrameShadow(QFrame::Raised);
        frame_3->setLineWidth(2);
        gridLayout_4 = new QGridLayout(frame_3);
        gridLayout_4->setSpacing(2);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(2, 2, 2, 2);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(2);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_5 = new QLabel(frame_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_5);

        u_value = new QDoubleSpinBox(frame_3);
        u_value->setObjectName(QStringLiteral("u_value"));
        sizePolicy.setHeightForWidth(u_value->sizePolicy().hasHeightForWidth());
        u_value->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(20);
        u_value->setFont(font1);
        u_value->setAlignment(Qt::AlignCenter);
        u_value->setReadOnly(false);
        u_value->setDecimals(3);
        u_value->setMaximum(999999);

        verticalLayout_5->addWidget(u_value);


        gridLayout_4->addLayout(verticalLayout_5, 0, 0, 1, 1);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(2);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        label_6 = new QLabel(frame_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);
        label_6->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(label_6);

        r_value = new QDoubleSpinBox(frame_3);
        r_value->setObjectName(QStringLiteral("r_value"));
        sizePolicy.setHeightForWidth(r_value->sizePolicy().hasHeightForWidth());
        r_value->setSizePolicy(sizePolicy);
        r_value->setFont(font1);
        r_value->setAlignment(Qt::AlignCenter);
        r_value->setReadOnly(true);
        r_value->setDecimals(6);
        r_value->setMaximum(999999);

        verticalLayout_7->addWidget(r_value);


        gridLayout_4->addLayout(verticalLayout_7, 0, 1, 1, 1);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(0);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalSpacer = new QSpacerItem(20, 172, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(2);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        label_9 = new QLabel(frame_3);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font);
        label_9->setAlignment(Qt::AlignCenter);

        verticalLayout_10->addWidget(label_9);

        u_start_value = new QDoubleSpinBox(frame_3);
        u_start_value->setObjectName(QStringLiteral("u_start_value"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(u_start_value->sizePolicy().hasHeightForWidth());
        u_start_value->setSizePolicy(sizePolicy1);
        u_start_value->setFont(font1);
        u_start_value->setAlignment(Qt::AlignCenter);
        u_start_value->setReadOnly(false);
        u_start_value->setDecimals(3);
        u_start_value->setMaximum(999999);

        verticalLayout_10->addWidget(u_start_value);


        verticalLayout_9->addLayout(verticalLayout_10);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(2);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        label_8 = new QLabel(frame_3);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font);
        label_8->setAlignment(Qt::AlignCenter);

        verticalLayout_8->addWidget(label_8);

        power_size = new QDoubleSpinBox(frame_3);
        power_size->setObjectName(QStringLiteral("power_size"));
        sizePolicy1.setHeightForWidth(power_size->sizePolicy().hasHeightForWidth());
        power_size->setSizePolicy(sizePolicy1);
        power_size->setFont(font1);
        power_size->setAlignment(Qt::AlignCenter);
        power_size->setReadOnly(true);
        power_size->setMaximum(100);

        verticalLayout_8->addWidget(power_size);


        verticalLayout_9->addLayout(verticalLayout_8);

        verticalSpacer_2 = new QSpacerItem(20, 98, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_2);

        verticalLayout_9->setStretch(0, 1);
        verticalLayout_9->setStretch(1, 2);
        verticalLayout_9->setStretch(2, 2);
        verticalLayout_9->setStretch(3, 1);

        gridLayout_4->addLayout(verticalLayout_9, 0, 2, 3, 1);

        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setSpacing(2);
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        label_13 = new QLabel(frame_3);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setFont(font);
        label_13->setAlignment(Qt::AlignCenter);

        verticalLayout_14->addWidget(label_13);

        temp = new QDoubleSpinBox(frame_3);
        temp->setObjectName(QStringLiteral("temp"));
        sizePolicy.setHeightForWidth(temp->sizePolicy().hasHeightForWidth());
        temp->setSizePolicy(sizePolicy);
        temp->setFont(font1);
        temp->setAlignment(Qt::AlignCenter);
        temp->setReadOnly(false);
        temp->setDecimals(3);
        temp->setMaximum(999999);

        verticalLayout_14->addWidget(temp);


        gridLayout_4->addLayout(verticalLayout_14, 1, 0, 1, 1);

        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setSpacing(2);
        verticalLayout_15->setObjectName(QStringLiteral("verticalLayout_15"));
        label_14 = new QLabel(frame_3);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setFont(font);
        label_14->setAlignment(Qt::AlignCenter);

        verticalLayout_15->addWidget(label_14);

        now_i = new QDoubleSpinBox(frame_3);
        now_i->setObjectName(QStringLiteral("now_i"));
        sizePolicy.setHeightForWidth(now_i->sizePolicy().hasHeightForWidth());
        now_i->setSizePolicy(sizePolicy);
        now_i->setFont(font1);
        now_i->setAlignment(Qt::AlignCenter);
        now_i->setReadOnly(false);
        now_i->setDecimals(3);
        now_i->setMaximum(999999);

        verticalLayout_15->addWidget(now_i);


        gridLayout_4->addLayout(verticalLayout_15, 1, 1, 1, 1);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(2);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label_7 = new QLabel(frame_3);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font);
        label_7->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label_7);

        test_time = new QLineEdit(frame_3);
        test_time->setObjectName(QStringLiteral("test_time"));
        sizePolicy.setHeightForWidth(test_time->sizePolicy().hasHeightForWidth());
        test_time->setSizePolicy(sizePolicy);
        test_time->setFont(font1);
        test_time->setAlignment(Qt::AlignCenter);
        test_time->setReadOnly(true);

        verticalLayout_6->addWidget(test_time);


        gridLayout_4->addLayout(verticalLayout_6, 2, 0, 1, 2);

        gridLayout_4->setColumnStretch(0, 1);
        gridLayout_4->setColumnStretch(1, 1);
        gridLayout_4->setColumnStretch(2, 2);

        gridLayout_3->addWidget(frame_3, 0, 0, 1, 2);

        gridLayout_3->setRowStretch(0, 1);
        gridLayout_3->setRowStretch(1, 1);
        gridLayout_3->setColumnStretch(0, 1);
        gridLayout_3->setColumnStretch(1, 1);

        retranslateUi(power_test);

        QMetaObject::connectSlotsByName(power_test);
    } // setupUi

    void retranslateUi(QWidget *power_test)
    {
        power_test->setWindowTitle(QApplication::translate("power_test", "Form", 0));
#ifndef QT_NO_TOOLTIP
        u_test->setToolTip(QApplication::translate("power_test", "<html><head/><body><p>\351\200\211\344\270\255\345\220\216\344\274\232\345\234\250\350\257\273\345\217\226\346\227\266\345\205\210\345\217\221\351\200\201\344\270\200\346\254\241\346\265\213\350\257\225\345\221\275\344\273\244</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        u_test->setText(QApplication::translate("power_test", "\346\265\213\350\257\225\347\224\265\345\216\213", 0));
#ifndef QT_NO_TOOLTIP
        r_test->setToolTip(QApplication::translate("power_test", "<html><head/><body><p>\351\200\211\344\270\255\345\220\216\344\274\232\345\234\250\350\257\273\345\217\226\346\227\266\345\205\210\345\217\221\351\200\201\344\270\200\346\254\241\346\265\213\350\257\225\345\221\275\344\273\244</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        r_test->setText(QApplication::translate("power_test", "\346\265\213\350\257\225\345\206\205\351\230\273", 0));
        read_u_r->setText(QApplication::translate("power_test", "\350\257\273\345\217\226\347\224\265\345\216\213\345\222\214\345\206\205\351\230\273", 0));
        label->setText(QApplication::translate("power_test", "\346\224\276\347\224\265\347\224\265\346\265\201", 0));
        i_out->setSuffix(QApplication::translate("power_test", "A", 0));
        label_3->setText(QApplication::translate("power_test", "\346\210\252\346\255\242\347\224\265\345\216\213", 0));
        u_end->setSuffix(QApplication::translate("power_test", "V", 0));
        label_4->setText(QApplication::translate("power_test", "\346\224\276\347\224\265\346\227\266\351\227\264", 0));
        out_time->setSuffix(QApplication::translate("power_test", "min", 0));
        label_10->setText(QApplication::translate("power_test", "\347\224\265\346\261\240\347\224\265\345\216\213\345\217\230\345\267\256", 0));
        u_range->setSuffix(QApplication::translate("power_test", "V", 0));
        label_11->setText(QApplication::translate("power_test", "\347\224\265\346\261\240\345\256\271\351\207\217", 0));
        i_range->setSuffix(QApplication::translate("power_test", "Ah", 0));
        start_test->setText(QApplication::translate("power_test", "\345\274\200\345\247\213\346\224\276\347\224\265\346\265\213\350\257\225", 0));
        label_5->setText(QApplication::translate("power_test", "\345\275\223\345\211\215\347\224\265\345\216\213", 0));
        u_value->setSuffix(QApplication::translate("power_test", "V", 0));
        label_6->setText(QApplication::translate("power_test", "\345\275\223\345\211\215\345\206\205\351\230\273", 0));
        r_value->setSuffix(QApplication::translate("power_test", "\316\251", 0));
        label_9->setText(QApplication::translate("power_test", "\345\274\200\345\247\213\346\265\213\350\257\225\347\224\265\345\216\213", 0));
        u_start_value->setSuffix(QApplication::translate("power_test", "V", 0));
        label_8->setText(QApplication::translate("power_test", "\345\211\251\344\275\231\347\224\265\346\261\240\345\256\271\351\207\217", 0));
        power_size->setSuffix(QApplication::translate("power_test", "%", 0));
        label_13->setText(QApplication::translate("power_test", "\345\275\223\345\211\215\346\270\251\345\272\246", 0));
        temp->setSuffix(QApplication::translate("power_test", "\302\260C", 0));
        label_14->setText(QApplication::translate("power_test", "\345\275\223\345\211\215\347\224\265\346\265\201", 0));
        now_i->setSuffix(QApplication::translate("power_test", "A", 0));
        label_7->setText(QApplication::translate("power_test", "\345\275\223\345\211\215\346\265\213\350\257\225\346\227\266\351\227\264 (h:mm:ss)", 0));
        test_time->setText(QApplication::translate("power_test", "00:00:00", 0));
    } // retranslateUi

};

namespace Ui {
    class power_test: public Ui_power_test {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POWER_TEST_H
