/********************************************************************************
** Form generated from reading UI file 'statu_list.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATU_LIST_H
#define UI_STATU_LIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>
#include <customplothasroll.h>
#include "m_checkbox.h"

QT_BEGIN_NAMESPACE

class Ui_Statu_list
{
public:
    QGridLayout *gridLayout_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLabel *state;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_20;
    QFrame *line;
    QLabel *label_21;
    QFrame *line_2;
    QLabel *label_22;
    QFrame *line_3;
    QLabel *label_23;
    QFrame *line_13;
    QHBoxLayout *horizontalLayout_9;
    m_checkbox *ua_state;
    m_checkbox *ub_state;
    m_checkbox *uc_state;
    m_checkbox *ud_state;
    m_checkbox *stop_state;
    m_checkbox *start_state;
    CustomPlotHasRoll *show;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QTableView *list_state_now;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_3;
    QLabel *file_name;
    QHBoxLayout *horizontalLayout;
    QFrame *frame_3;
    QGridLayout *gridLayout_3;
    QPushButton *save_file;
    QPushButton *priview;
    QPushButton *all_read;
    QPushButton *init_wave;
    QPushButton *all_write;
    QPushButton *mid;
    QHBoxLayout *horizontalLayout_11;
    QDoubleSpinBox *mid_start;
    QLabel *label_4;
    QDoubleSpinBox *mid_end;
    QPushButton *in_file;
    QPushButton *read;
    QPushButton *write;
    QFrame *frame_4;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QCheckBox *ua;
    QCheckBox *ub;
    QCheckBox *uc;
    QCheckBox *ud;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *now_start;
    QCheckBox *wait_start;
    QPushButton *start;
    QPushButton *stop;
    QPushButton *all_start;
    QPushButton *all_stop;
    QButtonGroup *buttonGroup;

    void setupUi(QWidget *Statu_list)
    {
        if (Statu_list->objectName().isEmpty())
            Statu_list->setObjectName(QStringLiteral("Statu_list"));
        Statu_list->resize(800, 480);
        gridLayout_4 = new QGridLayout(Statu_list);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_5 = new QLabel(Statu_list);
        label_5->setObjectName(QStringLiteral("label_5"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(label_5);

        state = new QLabel(Statu_list);
        state->setObjectName(QStringLiteral("state"));
        state->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(state);


        gridLayout_4->addLayout(horizontalLayout_4, 0, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_20 = new QLabel(Statu_list);
        label_20->setObjectName(QStringLiteral("label_20"));

        horizontalLayout_5->addWidget(label_20);

        line = new QFrame(Statu_list);
        line->setObjectName(QStringLiteral("line"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(line->sizePolicy().hasHeightForWidth());
        line->setSizePolicy(sizePolicy1);
        line->setStyleSheet(QStringLiteral("color: rgb(255, 255, 127);"));
        line->setFrameShadow(QFrame::Raised);
        line->setFrameShape(QFrame::HLine);

        horizontalLayout_5->addWidget(line);

        label_21 = new QLabel(Statu_list);
        label_21->setObjectName(QStringLiteral("label_21"));

        horizontalLayout_5->addWidget(label_21);

        line_2 = new QFrame(Statu_list);
        line_2->setObjectName(QStringLiteral("line_2"));
        sizePolicy1.setHeightForWidth(line_2->sizePolicy().hasHeightForWidth());
        line_2->setSizePolicy(sizePolicy1);
        line_2->setFrameShadow(QFrame::Raised);
        line_2->setFrameShape(QFrame::HLine);

        horizontalLayout_5->addWidget(line_2);

        label_22 = new QLabel(Statu_list);
        label_22->setObjectName(QStringLiteral("label_22"));

        horizontalLayout_5->addWidget(label_22);

        line_3 = new QFrame(Statu_list);
        line_3->setObjectName(QStringLiteral("line_3"));
        sizePolicy1.setHeightForWidth(line_3->sizePolicy().hasHeightForWidth());
        line_3->setSizePolicy(sizePolicy1);
        line_3->setFrameShadow(QFrame::Raised);
        line_3->setFrameShape(QFrame::HLine);

        horizontalLayout_5->addWidget(line_3);

        label_23 = new QLabel(Statu_list);
        label_23->setObjectName(QStringLiteral("label_23"));

        horizontalLayout_5->addWidget(label_23);

        line_13 = new QFrame(Statu_list);
        line_13->setObjectName(QStringLiteral("line_13"));
        sizePolicy1.setHeightForWidth(line_13->sizePolicy().hasHeightForWidth());
        line_13->setSizePolicy(sizePolicy1);
        line_13->setFrameShadow(QFrame::Raised);
        line_13->setFrameShape(QFrame::HLine);

        horizontalLayout_5->addWidget(line_13);


        gridLayout_4->addLayout(horizontalLayout_5, 0, 1, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(2);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        ua_state = new m_checkbox(Statu_list);
        ua_state->setObjectName(QStringLiteral("ua_state"));
        ua_state->setCheckable(false);

        horizontalLayout_9->addWidget(ua_state);

        ub_state = new m_checkbox(Statu_list);
        ub_state->setObjectName(QStringLiteral("ub_state"));
        ub_state->setCheckable(false);

        horizontalLayout_9->addWidget(ub_state);

        uc_state = new m_checkbox(Statu_list);
        uc_state->setObjectName(QStringLiteral("uc_state"));
        uc_state->setCheckable(false);

        horizontalLayout_9->addWidget(uc_state);

        ud_state = new m_checkbox(Statu_list);
        ud_state->setObjectName(QStringLiteral("ud_state"));
        ud_state->setCheckable(false);

        horizontalLayout_9->addWidget(ud_state);

        stop_state = new m_checkbox(Statu_list);
        stop_state->setObjectName(QStringLiteral("stop_state"));
        stop_state->setCheckable(false);

        horizontalLayout_9->addWidget(stop_state);

        start_state = new m_checkbox(Statu_list);
        start_state->setObjectName(QStringLiteral("start_state"));
        start_state->setEnabled(true);
        start_state->setCheckable(false);

        horizontalLayout_9->addWidget(start_state);


        gridLayout_4->addLayout(horizontalLayout_9, 0, 2, 1, 1);

        show = new CustomPlotHasRoll(Statu_list);
        show->setObjectName(QStringLiteral("show"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(show->sizePolicy().hasHeightForWidth());
        show->setSizePolicy(sizePolicy2);

        gridLayout_4->addWidget(show, 1, 0, 1, 3);

        frame = new QFrame(Statu_list);
        frame->setObjectName(QStringLiteral("frame"));
        sizePolicy2.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy2);
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        frame->setLineWidth(2);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        list_state_now = new QTableView(frame);
        list_state_now->setObjectName(QStringLiteral("list_state_now"));
        list_state_now->setMinimumSize(QSize(0, 1));

        gridLayout_2->addWidget(list_state_now, 1, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);

        horizontalLayout_8->addWidget(label_3);

        file_name = new QLabel(frame);
        file_name->setObjectName(QStringLiteral("file_name"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(file_name->sizePolicy().hasHeightForWidth());
        file_name->setSizePolicy(sizePolicy3);
        file_name->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(file_name);


        gridLayout_2->addLayout(horizontalLayout_8, 0, 0, 1, 1);


        gridLayout_4->addWidget(frame, 2, 0, 1, 3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        frame_3 = new QFrame(Statu_list);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        sizePolicy2.setHeightForWidth(frame_3->sizePolicy().hasHeightForWidth());
        frame_3->setSizePolicy(sizePolicy2);
        frame_3->setFrameShape(QFrame::Box);
        frame_3->setFrameShadow(QFrame::Raised);
        frame_3->setLineWidth(2);
        gridLayout_3 = new QGridLayout(frame_3);
        gridLayout_3->setSpacing(2);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(2, 2, 2, 2);
        save_file = new QPushButton(frame_3);
        save_file->setObjectName(QStringLiteral("save_file"));
        sizePolicy2.setHeightForWidth(save_file->sizePolicy().hasHeightForWidth());
        save_file->setSizePolicy(sizePolicy2);

        gridLayout_3->addWidget(save_file, 1, 3, 1, 1);

        priview = new QPushButton(frame_3);
        priview->setObjectName(QStringLiteral("priview"));
        sizePolicy2.setHeightForWidth(priview->sizePolicy().hasHeightForWidth());
        priview->setSizePolicy(sizePolicy2);

        gridLayout_3->addWidget(priview, 2, 2, 1, 1);

        all_read = new QPushButton(frame_3);
        all_read->setObjectName(QStringLiteral("all_read"));
        sizePolicy2.setHeightForWidth(all_read->sizePolicy().hasHeightForWidth());
        all_read->setSizePolicy(sizePolicy2);

        gridLayout_3->addWidget(all_read, 0, 3, 1, 1);

        init_wave = new QPushButton(frame_3);
        init_wave->setObjectName(QStringLiteral("init_wave"));
        sizePolicy2.setHeightForWidth(init_wave->sizePolicy().hasHeightForWidth());
        init_wave->setSizePolicy(sizePolicy2);

        gridLayout_3->addWidget(init_wave, 1, 4, 1, 2);

        all_write = new QPushButton(frame_3);
        all_write->setObjectName(QStringLiteral("all_write"));
        sizePolicy2.setHeightForWidth(all_write->sizePolicy().hasHeightForWidth());
        all_write->setSizePolicy(sizePolicy2);

        gridLayout_3->addWidget(all_write, 0, 5, 1, 1);

        mid = new QPushButton(frame_3);
        mid->setObjectName(QStringLiteral("mid"));
        sizePolicy2.setHeightForWidth(mid->sizePolicy().hasHeightForWidth());
        mid->setSizePolicy(sizePolicy2);

        gridLayout_3->addWidget(mid, 2, 3, 1, 1);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(2);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        mid_start = new QDoubleSpinBox(frame_3);
        mid_start->setObjectName(QStringLiteral("mid_start"));
        sizePolicy2.setHeightForWidth(mid_start->sizePolicy().hasHeightForWidth());
        mid_start->setSizePolicy(sizePolicy2);
        mid_start->setDecimals(5);
        mid_start->setMaximum(99999);

        horizontalLayout_11->addWidget(mid_start);

        label_4 = new QLabel(frame_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy2.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy2);
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_11->addWidget(label_4);

        mid_end = new QDoubleSpinBox(frame_3);
        mid_end->setObjectName(QStringLiteral("mid_end"));
        sizePolicy2.setHeightForWidth(mid_end->sizePolicy().hasHeightForWidth());
        mid_end->setSizePolicy(sizePolicy2);
        mid_end->setDecimals(5);
        mid_end->setMaximum(99999);

        horizontalLayout_11->addWidget(mid_end);


        gridLayout_3->addLayout(horizontalLayout_11, 2, 4, 1, 2);

        in_file = new QPushButton(frame_3);
        in_file->setObjectName(QStringLiteral("in_file"));
        sizePolicy2.setHeightForWidth(in_file->sizePolicy().hasHeightForWidth());
        in_file->setSizePolicy(sizePolicy2);

        gridLayout_3->addWidget(in_file, 1, 2, 1, 1);

        read = new QPushButton(frame_3);
        read->setObjectName(QStringLiteral("read"));
        sizePolicy2.setHeightForWidth(read->sizePolicy().hasHeightForWidth());
        read->setSizePolicy(sizePolicy2);

        gridLayout_3->addWidget(read, 0, 2, 1, 1);

        write = new QPushButton(frame_3);
        write->setObjectName(QStringLiteral("write"));
        sizePolicy2.setHeightForWidth(write->sizePolicy().hasHeightForWidth());
        write->setSizePolicy(sizePolicy2);

        gridLayout_3->addWidget(write, 0, 4, 1, 1);


        horizontalLayout->addWidget(frame_3);

        frame_4 = new QFrame(Statu_list);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        sizePolicy2.setHeightForWidth(frame_4->sizePolicy().hasHeightForWidth());
        frame_4->setSizePolicy(sizePolicy2);
        frame_4->setFrameShape(QFrame::Box);
        frame_4->setFrameShadow(QFrame::Raised);
        frame_4->setLineWidth(2);
        gridLayout = new QGridLayout(frame_4);
        gridLayout->setSpacing(2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(2, 2, 2, 2);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(frame_4);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        ua = new QCheckBox(frame_4);
        ua->setObjectName(QStringLiteral("ua"));
        QFont font;
        font.setPointSize(12);
        ua->setFont(font);

        horizontalLayout_2->addWidget(ua);

        ub = new QCheckBox(frame_4);
        ub->setObjectName(QStringLiteral("ub"));
        ub->setFont(font);

        horizontalLayout_2->addWidget(ub);

        uc = new QCheckBox(frame_4);
        uc->setObjectName(QStringLiteral("uc"));
        uc->setFont(font);

        horizontalLayout_2->addWidget(uc);

        ud = new QCheckBox(frame_4);
        ud->setObjectName(QStringLiteral("ud"));
        ud->setFont(font);

        horizontalLayout_2->addWidget(ud);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 2);

        label_2 = new QLabel(frame_4);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(2);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        now_start = new QCheckBox(frame_4);
        buttonGroup = new QButtonGroup(Statu_list);
        buttonGroup->setObjectName(QStringLiteral("buttonGroup"));
        buttonGroup->addButton(now_start);
        now_start->setObjectName(QStringLiteral("now_start"));
        now_start->setChecked(true);

        horizontalLayout_3->addWidget(now_start);

        wait_start = new QCheckBox(frame_4);
        buttonGroup->addButton(wait_start);
        wait_start->setObjectName(QStringLiteral("wait_start"));

        horizontalLayout_3->addWidget(wait_start);


        gridLayout->addLayout(horizontalLayout_3, 1, 1, 1, 1);

        start = new QPushButton(frame_4);
        start->setObjectName(QStringLiteral("start"));
        sizePolicy2.setHeightForWidth(start->sizePolicy().hasHeightForWidth());
        start->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(start, 2, 0, 1, 1);

        stop = new QPushButton(frame_4);
        stop->setObjectName(QStringLiteral("stop"));
        sizePolicy2.setHeightForWidth(stop->sizePolicy().hasHeightForWidth());
        stop->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(stop, 2, 1, 1, 1);

        all_start = new QPushButton(frame_4);
        all_start->setObjectName(QStringLiteral("all_start"));
        sizePolicy2.setHeightForWidth(all_start->sizePolicy().hasHeightForWidth());
        all_start->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(all_start, 3, 0, 1, 1);

        all_stop = new QPushButton(frame_4);
        all_stop->setObjectName(QStringLiteral("all_stop"));
        sizePolicy2.setHeightForWidth(all_stop->sizePolicy().hasHeightForWidth());
        all_stop->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(all_stop, 3, 1, 1, 1);


        horizontalLayout->addWidget(frame_4);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(1, 1);

        gridLayout_4->addLayout(horizontalLayout, 3, 0, 1, 3);


        retranslateUi(Statu_list);

        QMetaObject::connectSlotsByName(Statu_list);
    } // setupUi

    void retranslateUi(QWidget *Statu_list)
    {
        Statu_list->setWindowTitle(QApplication::translate("Statu_list", "Form", 0));
        label_5->setText(QApplication::translate("Statu_list", "\345\275\223\345\211\215\347\212\266\346\200\201", 0));
        state->setText(QString());
        label_20->setText(QApplication::translate("Statu_list", "A\347\233\270", 0));
        label_21->setText(QApplication::translate("Statu_list", "B\347\233\270", 0));
        label_22->setText(QApplication::translate("Statu_list", "C\347\233\270", 0));
        label_23->setText(QApplication::translate("Statu_list", "D\347\233\270", 0));
        ua_state->setText(QApplication::translate("Statu_list", "UA", 0));
        ub_state->setText(QApplication::translate("Statu_list", "UB", 0));
        uc_state->setText(QApplication::translate("Statu_list", "UC", 0));
        ud_state->setText(QApplication::translate("Statu_list", "UD", 0));
        stop_state->setText(QApplication::translate("Statu_list", "\346\234\252\345\220\257\345\212\250", 0));
        start_state->setText(QApplication::translate("Statu_list", "\345\267\262\345\220\257\345\212\250", 0));
#ifndef QT_NO_TOOLTIP
        list_state_now->setToolTip(QApplication::translate("Statu_list", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\350\276\223\345\207\272\345\200\274\344\273\245\351\200\227\345\217\267\345\210\206\351\232\224\343\200\202\345\271\205\345\200\274\350\214\203\345\233\264\344\270\2720~500V\343\200\202\347\233\270\344\275\215\350\214\203\345\233\264\344\270\272-360~360\345\272\246\343\200\202\351\242\221\347\216\207\350\214\203\345\233\264\344\270\27240~65Hz\343\200\202\346\214\201\347\273\255\346\227\266\351\227\264\345\260\217\344\272\216\347\255\211\344\272\216<span style=\" font-family:'\345\256\213\344\275\223';\">0\346\227\266\357\274\214\345\275\223\345\211\215\351\241\271"
                        "\350\277\236\347\273\255\350\276\223\345\207\272\357\274\214\347\233\264\345\210\260\346\224\266\345\210\260\345\201\234\346\255\242\345\221\275\344\273\244\343\200\202</span></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        label_3->setText(QApplication::translate("Statu_list", "\350\276\223\345\207\272\345\272\217\345\210\227: \345\271\205\345\200\274\357\274\214\347\233\270\344\275\215\357\274\214\351\242\221\347\216\207\347\232\204\345\200\274\344\273\216\345\267\246\345\210\260\345\217\263\344\276\235\346\254\241\344\270\272 A\347\233\270\357\274\214B\347\233\270\357\274\214C\347\233\270, D\347\233\270", 0));
        file_name->setText(QString());
#ifndef QT_NO_TOOLTIP
        save_file->setToolTip(QApplication::translate("Statu_list", "\345\260\206\347\212\266\346\200\201\345\272\217\345\210\227\344\277\241\346\201\257\344\277\235\345\255\230\345\210\260\346\263\242\345\275\242\346\226\207\344\273\266\344\270\255", 0));
#endif // QT_NO_TOOLTIP
        save_file->setText(QApplication::translate("Statu_list", "\344\277\235\345\255\230\345\272\217\345\210\227\346\226\207\344\273\266", 0));
#ifndef QT_NO_TOOLTIP
        priview->setToolTip(QApplication::translate("Statu_list", "\351\242\204\350\247\210\345\205\250\351\203\250\350\276\223\345\207\272\345\272\217\345\210\227\346\263\242\345\275\242", 0));
#endif // QT_NO_TOOLTIP
        priview->setText(QApplication::translate("Statu_list", "\351\242\204\350\247\210\346\263\242\345\275\242", 0));
#ifndef QT_NO_TOOLTIP
        all_read->setToolTip(QApplication::translate("Statu_list", "\350\257\273\345\217\226\344\270\273\346\235\277\344\270\255\347\232\204\345\205\250\351\203\250\345\272\217\345\210\227\344\277\241\346\201\257\345\271\266\346\230\276\347\244\272\345\207\272\346\235\245", 0));
#endif // QT_NO_TOOLTIP
        all_read->setText(QApplication::translate("Statu_list", "\350\257\273\345\217\226\345\205\250\351\203\250\345\272\217\345\210\227", 0));
        init_wave->setText(QApplication::translate("Statu_list", "\345\210\235\345\247\213\345\214\226\346\263\242\345\275\242", 0));
#ifndef QT_NO_TOOLTIP
        all_write->setToolTip(QApplication::translate("Statu_list", "\345\260\206\350\276\223\345\207\272\345\210\227\350\241\250\344\270\255\347\232\204\345\205\250\351\203\250\345\272\217\345\210\227\345\206\231\345\205\245\344\270\273\346\235\277\344\270\255\345\271\266\345\210\235\345\247\213\345\214\226", 0));
#endif // QT_NO_TOOLTIP
        all_write->setText(QApplication::translate("Statu_list", "\345\206\231\345\205\245\345\205\250\351\203\250\345\272\217\345\210\227", 0));
#ifndef QT_NO_TOOLTIP
        mid->setToolTip(QApplication::translate("Statu_list", "\346\210\252\345\217\226\344\270\200\346\256\265\346\263\242\345\275\242\350\277\233\350\241\214\351\242\204\350\247\210", 0));
#endif // QT_NO_TOOLTIP
        mid->setText(QApplication::translate("Statu_list", "\351\242\204\350\247\210\346\210\252\345\217\226\346\263\242\345\275\242", 0));
#ifndef QT_NO_TOOLTIP
        mid_start->setToolTip(QApplication::translate("Statu_list", "\346\210\252\345\217\226\350\265\267\345\247\213\347\202\271", 0));
#endif // QT_NO_TOOLTIP
        mid_start->setSuffix(QApplication::translate("Statu_list", "s", 0));
        label_4->setText(QApplication::translate("Statu_list", "\350\207\263", 0));
#ifndef QT_NO_TOOLTIP
        mid_end->setToolTip(QApplication::translate("Statu_list", "\346\210\252\345\217\226\347\273\223\346\235\237\347\202\271", 0));
#endif // QT_NO_TOOLTIP
        mid_end->setSuffix(QApplication::translate("Statu_list", "s", 0));
#ifndef QT_NO_TOOLTIP
        in_file->setToolTip(QApplication::translate("Statu_list", "\345\260\206\346\263\242\345\275\242\346\226\207\344\273\266\345\257\274\345\205\245\345\210\260\350\275\257\344\273\266\344\270\255", 0));
#endif // QT_NO_TOOLTIP
        in_file->setText(QApplication::translate("Statu_list", "\345\257\274\345\205\245\345\272\217\345\210\227\346\226\207\344\273\266", 0));
#ifndef QT_NO_TOOLTIP
        read->setToolTip(QApplication::translate("Statu_list", "\350\257\273\345\217\226\344\270\273\346\235\277\344\270\255\347\232\204\345\275\223\345\211\215\345\272\217\345\210\227\344\277\241\346\201\257\345\271\266\346\230\276\347\244\272\345\207\272\346\235\245", 0));
#endif // QT_NO_TOOLTIP
        read->setText(QApplication::translate("Statu_list", "\350\257\273\345\217\226\345\275\223\345\211\215\345\272\217\345\210\227", 0));
#ifndef QT_NO_TOOLTIP
        write->setToolTip(QApplication::translate("Statu_list", "\345\260\206\345\275\223\345\211\215\347\232\204\345\272\217\345\210\227\344\277\241\346\201\257\345\206\231\345\205\245\344\270\273\346\235\277\344\270\255\345\271\266\345\210\235\345\247\213\345\214\226\345\272\217\345\210\227\346\263\242\345\275\242", 0));
#endif // QT_NO_TOOLTIP
        write->setText(QApplication::translate("Statu_list", "\345\206\231\345\205\245\345\275\223\345\211\215\345\272\217\345\210\227", 0));
        label->setText(QApplication::translate("Statu_list", "\351\200\211\346\213\251\350\276\223\345\207\272\351\200\232\351\201\223", 0));
        ua->setText(QApplication::translate("Statu_list", "UA", 0));
        ub->setText(QApplication::translate("Statu_list", "UB", 0));
        uc->setText(QApplication::translate("Statu_list", "UC", 0));
        ud->setText(QApplication::translate("Statu_list", "UD", 0));
        label_2->setText(QApplication::translate("Statu_list", "\351\200\211\346\213\251\351\200\232\351\201\223\347\212\266\346\200\201", 0));
#ifndef QT_NO_TOOLTIP
        now_start->setToolTip(QApplication::translate("Statu_list", "\347\253\213\345\215\263\346\211\247\350\241\214\345\220\257\345\212\250\346\210\226\345\201\234\346\255\242\345\212\250\344\275\234\343\200\202", 0));
#endif // QT_NO_TOOLTIP
        now_start->setText(QApplication::translate("Statu_list", "\347\253\213\345\215\263\346\211\247\350\241\214", 0));
#ifndef QT_NO_TOOLTIP
        wait_start->setToolTip(QApplication::translate("Statu_list", "\345\220\257\345\212\250\345\221\275\344\273\244\350\246\201\347\255\211\345\276\205\350\247\246\345\217\221\344\277\241\345\217\267\357\274\214\345\201\234\346\255\242\345\221\275\344\273\244\350\246\201\n"
"\347\255\211\345\276\205\346\234\254\347\212\266\346\200\201\346\227\266\351\227\264\346\211\247\350\241\214\345\256\214\346\257\225\345\220\216\345\201\234\346\255\242", 0));
#endif // QT_NO_TOOLTIP
        wait_start->setText(QApplication::translate("Statu_list", "\350\247\246\345\217\221\346\211\247\350\241\214", 0));
#ifndef QT_NO_TOOLTIP
        start->setToolTip(QApplication::translate("Statu_list", "<html><head/><body><p>\346\240\271\346\215\256\351\200\211\344\270\255\347\232\204\351\200\232\351\201\223\357\274\214\345\220\257\345\212\250\347\233\270\345\272\224\347\232\204\347\233\270\357\274\214\345\220\257\345\212\250\345\211\215\350\246\201\345\205\210\345\210\235\345\247\213\345\214\226\346\263\242\345\275\242</p><p>\350\213\245\344\271\213\345\211\215\345\206\231\345\205\245\350\277\207\345\212\250\346\200\201\346\263\242\345\275\242\357\274\214\351\234\200\351\207\215\346\226\260\345\210\235\345\247\213\345\214\226</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        start->setText(QApplication::translate("Statu_list", "\345\220\257\345\212\250", 0));
#ifndef QT_NO_TOOLTIP
        stop->setToolTip(QApplication::translate("Statu_list", "\346\240\271\346\215\256\351\200\211\344\270\255\347\232\204\351\200\232\351\201\223\357\274\214\345\201\234\346\255\242\347\233\270\345\272\224\347\232\204\347\233\270", 0));
#endif // QT_NO_TOOLTIP
        stop->setText(QApplication::translate("Statu_list", "\345\201\234\346\255\242", 0));
#ifndef QT_NO_TOOLTIP
        all_start->setToolTip(QApplication::translate("Statu_list", "<html><head/><body><p>\345\220\257\345\212\250\344\270\211\347\233\270\347\224\265\345\216\213\357\274\214\345\220\257\345\212\250\345\211\215\350\246\201\345\205\210\345\210\235\345\247\213\345\214\226\346\263\242\345\275\242</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        all_start->setText(QApplication::translate("Statu_list", "\345\205\250\351\203\250\345\220\257\345\212\250", 0));
#ifndef QT_NO_TOOLTIP
        all_stop->setToolTip(QApplication::translate("Statu_list", "\345\201\234\346\255\242\344\270\211\347\233\270\347\224\265\345\216\213", 0));
#endif // QT_NO_TOOLTIP
        all_stop->setText(QApplication::translate("Statu_list", "\345\205\250\351\203\250\345\201\234\346\255\242", 0));
    } // retranslateUi

};

namespace Ui {
    class Statu_list: public Ui_Statu_list {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATU_LIST_H
