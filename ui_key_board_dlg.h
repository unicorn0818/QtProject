/********************************************************************************
** Form generated from reading UI file 'key_board_dlg.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KEY_BOARD_DLG_H
#define UI_KEY_BOARD_DLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Key_board_dlg
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_2;
    QPushButton *b_2;
    QPushButton *b_cosh;
    QPushButton *b_sin;
    QPushButton *b_right;
    QPushButton *b_sign;
    QPushButton *b_ti;
    QPushButton *b_tan;
    QPushButton *b_coth;
    QPushButton *b_pi;
    QPushButton *b_sqrt;
    QPushButton *b_tanh;
    QPushButton *b_cot;
    QPushButton *b_ln;
    QPushButton *b_9;
    QPushButton *b_8;
    QPushButton *b_5;
    QPushButton *b_3;
    QPushButton *b_7;
    QPushButton *b_6;
    QPushButton *b_4;
    QPushButton *b_1;
    QPushButton *b_full;
    QPushButton *b_left;
    QPushButton *b_sinh;
    QPushButton *b_cos;
    QPushButton *b_abs;
    QPushButton *b_0;
    QPushButton *b_a;
    QPushButton *b_back;
    QPushButton *b_add;
    QPushButton *b_b;
    QPushButton *b_mul;
    QPushButton *b_c;
    QPushButton *b_ent;
    QPushButton *b_comma;
    QWidget *tab_2;
    QGridLayout *gridLayout_3;
    QPushButton *btn_1;
    QPushButton *btn_2;
    QPushButton *btn_3;
    QPushButton *btn_4;
    QPushButton *btn_5;
    QPushButton *btn_6;
    QPushButton *btn_7;
    QPushButton *btn_8;
    QPushButton *btn_9;
    QPushButton *btn_0;
    QPushButton *btn_q;
    QPushButton *btn_w;
    QPushButton *btn_e;
    QPushButton *btn_r;
    QPushButton *btn_t;
    QPushButton *btn_y;
    QPushButton *btn_u;
    QPushButton *btn_i;
    QPushButton *btn_o;
    QPushButton *btn_p;
    QPushButton *btn_a;
    QPushButton *btn_s;
    QPushButton *btn_d;
    QPushButton *btn_f;
    QPushButton *btn_g;
    QPushButton *btn_h;
    QPushButton *btn_j;
    QPushButton *btn_k;
    QPushButton *btn_l;
    QPushButton *btn_back;
    QPushButton *btn_z;
    QPushButton *btn_x;
    QPushButton *btn_c;
    QPushButton *btn_v;
    QPushButton *btn_b;
    QPushButton *btn_n;
    QPushButton *btn_m;
    QPushButton *btn_left;
    QPushButton *btn_right;
    QPushButton *btn_slash;
    QPushButton *btn_space;
    QPushButton *btn_www;
    QPushButton *btn_sub;
    QPushButton *btn_add;
    QPushButton *btn_colon;
    QPushButton *btn_comma;
    QPushButton *btn_ent;
    QPushButton *btn_num;
    QPushButton *btn_shi;
    QPushButton *btn_cap;

    void setupUi(QDialog *Key_board_dlg)
    {
        if (Key_board_dlg->objectName().isEmpty())
            Key_board_dlg->setObjectName(QStringLiteral("Key_board_dlg"));
        Key_board_dlg->resize(778, 241);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Key_board_dlg->sizePolicy().hasHeightForWidth());
        Key_board_dlg->setSizePolicy(sizePolicy);
        Key_board_dlg->setContextMenuPolicy(Qt::DefaultContextMenu);
        Key_board_dlg->setSizeGripEnabled(false);
        gridLayout = new QGridLayout(Key_board_dlg);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(Key_board_dlg);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setFocusPolicy(Qt::NoFocus);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setUsesScrollButtons(true);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_2 = new QGridLayout(tab);
        gridLayout_2->setSpacing(1);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        b_2 = new QPushButton(tab);
        b_2->setObjectName(QStringLiteral("b_2"));
        sizePolicy.setHeightForWidth(b_2->sizePolicy().hasHeightForWidth());
        b_2->setSizePolicy(sizePolicy);
        b_2->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(b_2, 7, 5, 1, 1);

        b_cosh = new QPushButton(tab);
        b_cosh->setObjectName(QStringLiteral("b_cosh"));
        sizePolicy.setHeightForWidth(b_cosh->sizePolicy().hasHeightForWidth());
        b_cosh->setSizePolicy(sizePolicy);
        b_cosh->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(b_cosh, 1, 4, 1, 1);

        b_sin = new QPushButton(tab);
        b_sin->setObjectName(QStringLiteral("b_sin"));
        sizePolicy.setHeightForWidth(b_sin->sizePolicy().hasHeightForWidth());
        b_sin->setSizePolicy(sizePolicy);
        b_sin->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(b_sin, 0, 5, 1, 1);

        b_right = new QPushButton(tab);
        b_right->setObjectName(QStringLiteral("b_right"));
        sizePolicy.setHeightForWidth(b_right->sizePolicy().hasHeightForWidth());
        b_right->setSizePolicy(sizePolicy);
        b_right->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(b_right, 3, 5, 1, 1);

        b_sign = new QPushButton(tab);
        b_sign->setObjectName(QStringLiteral("b_sign"));
        sizePolicy.setHeightForWidth(b_sign->sizePolicy().hasHeightForWidth());
        b_sign->setSizePolicy(sizePolicy);
        b_sign->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(b_sign, 2, 7, 1, 1);

        b_ti = new QPushButton(tab);
        b_ti->setObjectName(QStringLiteral("b_ti"));
        sizePolicy.setHeightForWidth(b_ti->sizePolicy().hasHeightForWidth());
        b_ti->setSizePolicy(sizePolicy);
        b_ti->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(b_ti, 3, 7, 1, 1);

        b_tan = new QPushButton(tab);
        b_tan->setObjectName(QStringLiteral("b_tan"));
        sizePolicy.setHeightForWidth(b_tan->sizePolicy().hasHeightForWidth());
        b_tan->setSizePolicy(sizePolicy);
        b_tan->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(b_tan, 0, 6, 1, 1);

        b_coth = new QPushButton(tab);
        b_coth->setObjectName(QStringLiteral("b_coth"));
        sizePolicy.setHeightForWidth(b_coth->sizePolicy().hasHeightForWidth());
        b_coth->setSizePolicy(sizePolicy);
        b_coth->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(b_coth, 1, 7, 1, 1);

        b_pi = new QPushButton(tab);
        b_pi->setObjectName(QStringLiteral("b_pi"));
        sizePolicy.setHeightForWidth(b_pi->sizePolicy().hasHeightForWidth());
        b_pi->setSizePolicy(sizePolicy);
        b_pi->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(b_pi, 3, 6, 1, 1);

        b_sqrt = new QPushButton(tab);
        b_sqrt->setObjectName(QStringLiteral("b_sqrt"));
        sizePolicy.setHeightForWidth(b_sqrt->sizePolicy().hasHeightForWidth());
        b_sqrt->setSizePolicy(sizePolicy);
        b_sqrt->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(b_sqrt, 2, 5, 1, 1);

        b_tanh = new QPushButton(tab);
        b_tanh->setObjectName(QStringLiteral("b_tanh"));
        sizePolicy.setHeightForWidth(b_tanh->sizePolicy().hasHeightForWidth());
        b_tanh->setSizePolicy(sizePolicy);
        b_tanh->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(b_tanh, 1, 6, 1, 1);

        b_cot = new QPushButton(tab);
        b_cot->setObjectName(QStringLiteral("b_cot"));
        sizePolicy.setHeightForWidth(b_cot->sizePolicy().hasHeightForWidth());
        b_cot->setSizePolicy(sizePolicy);
        b_cot->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(b_cot, 0, 7, 1, 1);

        b_ln = new QPushButton(tab);
        b_ln->setObjectName(QStringLiteral("b_ln"));
        sizePolicy.setHeightForWidth(b_ln->sizePolicy().hasHeightForWidth());
        b_ln->setSizePolicy(sizePolicy);
        b_ln->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(b_ln, 2, 6, 1, 1);

        b_9 = new QPushButton(tab);
        b_9->setObjectName(QStringLiteral("b_9"));
        sizePolicy.setHeightForWidth(b_9->sizePolicy().hasHeightForWidth());
        b_9->setSizePolicy(sizePolicy);
        b_9->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(b_9, 5, 6, 1, 1);

        b_8 = new QPushButton(tab);
        b_8->setObjectName(QStringLiteral("b_8"));
        sizePolicy.setHeightForWidth(b_8->sizePolicy().hasHeightForWidth());
        b_8->setSizePolicy(sizePolicy);
        b_8->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(b_8, 5, 5, 1, 1);

        b_5 = new QPushButton(tab);
        b_5->setObjectName(QStringLiteral("b_5"));
        sizePolicy.setHeightForWidth(b_5->sizePolicy().hasHeightForWidth());
        b_5->setSizePolicy(sizePolicy);
        b_5->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(b_5, 6, 5, 1, 1);

        b_3 = new QPushButton(tab);
        b_3->setObjectName(QStringLiteral("b_3"));
        sizePolicy.setHeightForWidth(b_3->sizePolicy().hasHeightForWidth());
        b_3->setSizePolicy(sizePolicy);
        b_3->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(b_3, 7, 6, 1, 1);

        b_7 = new QPushButton(tab);
        b_7->setObjectName(QStringLiteral("b_7"));
        sizePolicy.setHeightForWidth(b_7->sizePolicy().hasHeightForWidth());
        b_7->setSizePolicy(sizePolicy);
        b_7->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(b_7, 5, 4, 1, 1);

        b_6 = new QPushButton(tab);
        b_6->setObjectName(QStringLiteral("b_6"));
        sizePolicy.setHeightForWidth(b_6->sizePolicy().hasHeightForWidth());
        b_6->setSizePolicy(sizePolicy);
        b_6->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(b_6, 6, 6, 1, 1);

        b_4 = new QPushButton(tab);
        b_4->setObjectName(QStringLiteral("b_4"));
        sizePolicy.setHeightForWidth(b_4->sizePolicy().hasHeightForWidth());
        b_4->setSizePolicy(sizePolicy);
        b_4->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(b_4, 6, 4, 1, 1);

        b_1 = new QPushButton(tab);
        b_1->setObjectName(QStringLiteral("b_1"));
        sizePolicy.setHeightForWidth(b_1->sizePolicy().hasHeightForWidth());
        b_1->setSizePolicy(sizePolicy);
        b_1->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(b_1, 7, 4, 1, 1);

        b_full = new QPushButton(tab);
        b_full->setObjectName(QStringLiteral("b_full"));
        sizePolicy.setHeightForWidth(b_full->sizePolicy().hasHeightForWidth());
        b_full->setSizePolicy(sizePolicy);
        b_full->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(b_full, 11, 6, 1, 2);

        b_left = new QPushButton(tab);
        b_left->setObjectName(QStringLiteral("b_left"));
        sizePolicy.setHeightForWidth(b_left->sizePolicy().hasHeightForWidth());
        b_left->setSizePolicy(sizePolicy);
        b_left->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(b_left, 3, 4, 1, 1);

        b_sinh = new QPushButton(tab);
        b_sinh->setObjectName(QStringLiteral("b_sinh"));
        sizePolicy.setHeightForWidth(b_sinh->sizePolicy().hasHeightForWidth());
        b_sinh->setSizePolicy(sizePolicy);
        b_sinh->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(b_sinh, 1, 5, 1, 1);

        b_cos = new QPushButton(tab);
        b_cos->setObjectName(QStringLiteral("b_cos"));
        sizePolicy.setHeightForWidth(b_cos->sizePolicy().hasHeightForWidth());
        b_cos->setSizePolicy(sizePolicy);
        b_cos->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(b_cos, 0, 4, 1, 1);

        b_abs = new QPushButton(tab);
        b_abs->setObjectName(QStringLiteral("b_abs"));
        sizePolicy.setHeightForWidth(b_abs->sizePolicy().hasHeightForWidth());
        b_abs->setSizePolicy(sizePolicy);
        b_abs->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(b_abs, 2, 4, 1, 1);

        b_0 = new QPushButton(tab);
        b_0->setObjectName(QStringLiteral("b_0"));
        sizePolicy.setHeightForWidth(b_0->sizePolicy().hasHeightForWidth());
        b_0->setSizePolicy(sizePolicy);
        b_0->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(b_0, 4, 4, 1, 1);

        b_a = new QPushButton(tab);
        b_a->setObjectName(QStringLiteral("b_a"));
        sizePolicy.setHeightForWidth(b_a->sizePolicy().hasHeightForWidth());
        b_a->setSizePolicy(sizePolicy);
        b_a->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(b_a, 4, 5, 1, 1);

        b_back = new QPushButton(tab);
        b_back->setObjectName(QStringLiteral("b_back"));
        sizePolicy.setHeightForWidth(b_back->sizePolicy().hasHeightForWidth());
        b_back->setSizePolicy(sizePolicy);
        b_back->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(b_back, 4, 6, 1, 1);

        b_add = new QPushButton(tab);
        b_add->setObjectName(QStringLiteral("b_add"));
        sizePolicy.setHeightForWidth(b_add->sizePolicy().hasHeightForWidth());
        b_add->setSizePolicy(sizePolicy);
        b_add->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(b_add, 4, 7, 1, 1);

        b_b = new QPushButton(tab);
        b_b->setObjectName(QStringLiteral("b_b"));
        sizePolicy.setHeightForWidth(b_b->sizePolicy().hasHeightForWidth());
        b_b->setSizePolicy(sizePolicy);
        b_b->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(b_b, 5, 7, 1, 1);

        b_mul = new QPushButton(tab);
        b_mul->setObjectName(QStringLiteral("b_mul"));
        sizePolicy.setHeightForWidth(b_mul->sizePolicy().hasHeightForWidth());
        b_mul->setSizePolicy(sizePolicy);
        b_mul->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(b_mul, 6, 7, 1, 1);

        b_c = new QPushButton(tab);
        b_c->setObjectName(QStringLiteral("b_c"));
        sizePolicy.setHeightForWidth(b_c->sizePolicy().hasHeightForWidth());
        b_c->setSizePolicy(sizePolicy);
        b_c->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(b_c, 7, 7, 1, 1);

        b_ent = new QPushButton(tab);
        b_ent->setObjectName(QStringLiteral("b_ent"));
        sizePolicy.setHeightForWidth(b_ent->sizePolicy().hasHeightForWidth());
        b_ent->setSizePolicy(sizePolicy);
        b_ent->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(b_ent, 11, 5, 1, 1);

        b_comma = new QPushButton(tab);
        b_comma->setObjectName(QStringLiteral("b_comma"));
        sizePolicy.setHeightForWidth(b_comma->sizePolicy().hasHeightForWidth());
        b_comma->setSizePolicy(sizePolicy);
        b_comma->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(b_comma, 11, 4, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout_3 = new QGridLayout(tab_2);
        gridLayout_3->setSpacing(1);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        btn_1 = new QPushButton(tab_2);
        btn_1->setObjectName(QStringLiteral("btn_1"));
        sizePolicy.setHeightForWidth(btn_1->sizePolicy().hasHeightForWidth());
        btn_1->setSizePolicy(sizePolicy);
        btn_1->setMinimumSize(QSize(0, 0));
        btn_1->setMaximumSize(QSize(16777215, 16777215));
        btn_1->setStyleSheet(QStringLiteral("QPushButton{text-align : left;}"));

        gridLayout_3->addWidget(btn_1, 0, 0, 1, 1);

        btn_2 = new QPushButton(tab_2);
        btn_2->setObjectName(QStringLiteral("btn_2"));
        sizePolicy.setHeightForWidth(btn_2->sizePolicy().hasHeightForWidth());
        btn_2->setSizePolicy(sizePolicy);
        btn_2->setStyleSheet(QStringLiteral("QPushButton{text-align : left;}"));

        gridLayout_3->addWidget(btn_2, 0, 1, 1, 1);

        btn_3 = new QPushButton(tab_2);
        btn_3->setObjectName(QStringLiteral("btn_3"));
        sizePolicy.setHeightForWidth(btn_3->sizePolicy().hasHeightForWidth());
        btn_3->setSizePolicy(sizePolicy);
        btn_3->setStyleSheet(QStringLiteral("QPushButton{text-align : left;}"));

        gridLayout_3->addWidget(btn_3, 0, 2, 1, 1);

        btn_4 = new QPushButton(tab_2);
        btn_4->setObjectName(QStringLiteral("btn_4"));
        sizePolicy.setHeightForWidth(btn_4->sizePolicy().hasHeightForWidth());
        btn_4->setSizePolicy(sizePolicy);
        btn_4->setStyleSheet(QStringLiteral("QPushButton{text-align : left;}"));

        gridLayout_3->addWidget(btn_4, 0, 3, 1, 1);

        btn_5 = new QPushButton(tab_2);
        btn_5->setObjectName(QStringLiteral("btn_5"));
        sizePolicy.setHeightForWidth(btn_5->sizePolicy().hasHeightForWidth());
        btn_5->setSizePolicy(sizePolicy);
        btn_5->setStyleSheet(QStringLiteral("QPushButton{text-align : left;}"));

        gridLayout_3->addWidget(btn_5, 0, 4, 1, 1);

        btn_6 = new QPushButton(tab_2);
        btn_6->setObjectName(QStringLiteral("btn_6"));
        sizePolicy.setHeightForWidth(btn_6->sizePolicy().hasHeightForWidth());
        btn_6->setSizePolicy(sizePolicy);
        btn_6->setStyleSheet(QStringLiteral("QPushButton{text-align :left ;}"));

        gridLayout_3->addWidget(btn_6, 0, 5, 1, 1);

        btn_7 = new QPushButton(tab_2);
        btn_7->setObjectName(QStringLiteral("btn_7"));
        sizePolicy.setHeightForWidth(btn_7->sizePolicy().hasHeightForWidth());
        btn_7->setSizePolicy(sizePolicy);
        btn_7->setStyleSheet(QStringLiteral("QPushButton{text-align : left;}"));

        gridLayout_3->addWidget(btn_7, 0, 6, 1, 1);

        btn_8 = new QPushButton(tab_2);
        btn_8->setObjectName(QStringLiteral("btn_8"));
        sizePolicy.setHeightForWidth(btn_8->sizePolicy().hasHeightForWidth());
        btn_8->setSizePolicy(sizePolicy);
        btn_8->setStyleSheet(QStringLiteral("QPushButton{text-align : left;}"));

        gridLayout_3->addWidget(btn_8, 0, 7, 1, 1);

        btn_9 = new QPushButton(tab_2);
        btn_9->setObjectName(QStringLiteral("btn_9"));
        sizePolicy.setHeightForWidth(btn_9->sizePolicy().hasHeightForWidth());
        btn_9->setSizePolicy(sizePolicy);
        btn_9->setStyleSheet(QStringLiteral("QPushButton{text-align : left;}"));

        gridLayout_3->addWidget(btn_9, 0, 8, 1, 1);

        btn_0 = new QPushButton(tab_2);
        btn_0->setObjectName(QStringLiteral("btn_0"));
        sizePolicy.setHeightForWidth(btn_0->sizePolicy().hasHeightForWidth());
        btn_0->setSizePolicy(sizePolicy);
        btn_0->setStyleSheet(QStringLiteral("QPushButton{text-align : left;}"));

        gridLayout_3->addWidget(btn_0, 0, 9, 1, 1);

        btn_q = new QPushButton(tab_2);
        btn_q->setObjectName(QStringLiteral("btn_q"));
        sizePolicy.setHeightForWidth(btn_q->sizePolicy().hasHeightForWidth());
        btn_q->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(btn_q, 1, 0, 1, 1);

        btn_w = new QPushButton(tab_2);
        btn_w->setObjectName(QStringLiteral("btn_w"));
        sizePolicy.setHeightForWidth(btn_w->sizePolicy().hasHeightForWidth());
        btn_w->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(btn_w, 1, 1, 1, 1);

        btn_e = new QPushButton(tab_2);
        btn_e->setObjectName(QStringLiteral("btn_e"));
        sizePolicy.setHeightForWidth(btn_e->sizePolicy().hasHeightForWidth());
        btn_e->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(btn_e, 1, 2, 1, 1);

        btn_r = new QPushButton(tab_2);
        btn_r->setObjectName(QStringLiteral("btn_r"));
        sizePolicy.setHeightForWidth(btn_r->sizePolicy().hasHeightForWidth());
        btn_r->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(btn_r, 1, 3, 1, 1);

        btn_t = new QPushButton(tab_2);
        btn_t->setObjectName(QStringLiteral("btn_t"));
        sizePolicy.setHeightForWidth(btn_t->sizePolicy().hasHeightForWidth());
        btn_t->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(btn_t, 1, 4, 1, 1);

        btn_y = new QPushButton(tab_2);
        btn_y->setObjectName(QStringLiteral("btn_y"));
        sizePolicy.setHeightForWidth(btn_y->sizePolicy().hasHeightForWidth());
        btn_y->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(btn_y, 1, 5, 1, 1);

        btn_u = new QPushButton(tab_2);
        btn_u->setObjectName(QStringLiteral("btn_u"));
        sizePolicy.setHeightForWidth(btn_u->sizePolicy().hasHeightForWidth());
        btn_u->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(btn_u, 1, 6, 1, 1);

        btn_i = new QPushButton(tab_2);
        btn_i->setObjectName(QStringLiteral("btn_i"));
        sizePolicy.setHeightForWidth(btn_i->sizePolicy().hasHeightForWidth());
        btn_i->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(btn_i, 1, 7, 1, 1);

        btn_o = new QPushButton(tab_2);
        btn_o->setObjectName(QStringLiteral("btn_o"));
        sizePolicy.setHeightForWidth(btn_o->sizePolicy().hasHeightForWidth());
        btn_o->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(btn_o, 1, 8, 1, 1);

        btn_p = new QPushButton(tab_2);
        btn_p->setObjectName(QStringLiteral("btn_p"));
        sizePolicy.setHeightForWidth(btn_p->sizePolicy().hasHeightForWidth());
        btn_p->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(btn_p, 1, 9, 1, 1);

        btn_a = new QPushButton(tab_2);
        btn_a->setObjectName(QStringLiteral("btn_a"));
        sizePolicy.setHeightForWidth(btn_a->sizePolicy().hasHeightForWidth());
        btn_a->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(btn_a, 2, 0, 1, 1);

        btn_s = new QPushButton(tab_2);
        btn_s->setObjectName(QStringLiteral("btn_s"));
        sizePolicy.setHeightForWidth(btn_s->sizePolicy().hasHeightForWidth());
        btn_s->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(btn_s, 2, 1, 1, 1);

        btn_d = new QPushButton(tab_2);
        btn_d->setObjectName(QStringLiteral("btn_d"));
        sizePolicy.setHeightForWidth(btn_d->sizePolicy().hasHeightForWidth());
        btn_d->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(btn_d, 2, 2, 1, 1);

        btn_f = new QPushButton(tab_2);
        btn_f->setObjectName(QStringLiteral("btn_f"));
        sizePolicy.setHeightForWidth(btn_f->sizePolicy().hasHeightForWidth());
        btn_f->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(btn_f, 2, 3, 1, 1);

        btn_g = new QPushButton(tab_2);
        btn_g->setObjectName(QStringLiteral("btn_g"));
        sizePolicy.setHeightForWidth(btn_g->sizePolicy().hasHeightForWidth());
        btn_g->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(btn_g, 2, 4, 1, 1);

        btn_h = new QPushButton(tab_2);
        btn_h->setObjectName(QStringLiteral("btn_h"));
        sizePolicy.setHeightForWidth(btn_h->sizePolicy().hasHeightForWidth());
        btn_h->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(btn_h, 2, 5, 1, 1);

        btn_j = new QPushButton(tab_2);
        btn_j->setObjectName(QStringLiteral("btn_j"));
        sizePolicy.setHeightForWidth(btn_j->sizePolicy().hasHeightForWidth());
        btn_j->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(btn_j, 2, 6, 1, 1);

        btn_k = new QPushButton(tab_2);
        btn_k->setObjectName(QStringLiteral("btn_k"));
        sizePolicy.setHeightForWidth(btn_k->sizePolicy().hasHeightForWidth());
        btn_k->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(btn_k, 2, 7, 1, 1);

        btn_l = new QPushButton(tab_2);
        btn_l->setObjectName(QStringLiteral("btn_l"));
        sizePolicy.setHeightForWidth(btn_l->sizePolicy().hasHeightForWidth());
        btn_l->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(btn_l, 2, 8, 1, 1);

        btn_back = new QPushButton(tab_2);
        btn_back->setObjectName(QStringLiteral("btn_back"));
        sizePolicy.setHeightForWidth(btn_back->sizePolicy().hasHeightForWidth());
        btn_back->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(btn_back, 2, 9, 1, 1);

        btn_z = new QPushButton(tab_2);
        btn_z->setObjectName(QStringLiteral("btn_z"));
        sizePolicy.setHeightForWidth(btn_z->sizePolicy().hasHeightForWidth());
        btn_z->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(btn_z, 3, 0, 1, 1);

        btn_x = new QPushButton(tab_2);
        btn_x->setObjectName(QStringLiteral("btn_x"));
        sizePolicy.setHeightForWidth(btn_x->sizePolicy().hasHeightForWidth());
        btn_x->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(btn_x, 3, 1, 1, 1);

        btn_c = new QPushButton(tab_2);
        btn_c->setObjectName(QStringLiteral("btn_c"));
        sizePolicy.setHeightForWidth(btn_c->sizePolicy().hasHeightForWidth());
        btn_c->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(btn_c, 3, 2, 1, 1);

        btn_v = new QPushButton(tab_2);
        btn_v->setObjectName(QStringLiteral("btn_v"));
        sizePolicy.setHeightForWidth(btn_v->sizePolicy().hasHeightForWidth());
        btn_v->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(btn_v, 3, 3, 1, 1);

        btn_b = new QPushButton(tab_2);
        btn_b->setObjectName(QStringLiteral("btn_b"));
        sizePolicy.setHeightForWidth(btn_b->sizePolicy().hasHeightForWidth());
        btn_b->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(btn_b, 3, 4, 1, 1);

        btn_n = new QPushButton(tab_2);
        btn_n->setObjectName(QStringLiteral("btn_n"));
        sizePolicy.setHeightForWidth(btn_n->sizePolicy().hasHeightForWidth());
        btn_n->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(btn_n, 3, 5, 1, 1);

        btn_m = new QPushButton(tab_2);
        btn_m->setObjectName(QStringLiteral("btn_m"));
        sizePolicy.setHeightForWidth(btn_m->sizePolicy().hasHeightForWidth());
        btn_m->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(btn_m, 3, 6, 1, 1);

        btn_left = new QPushButton(tab_2);
        btn_left->setObjectName(QStringLiteral("btn_left"));
        sizePolicy.setHeightForWidth(btn_left->sizePolicy().hasHeightForWidth());
        btn_left->setSizePolicy(sizePolicy);
        btn_left->setStyleSheet(QStringLiteral("QPushButton{text-align : left;}"));

        gridLayout_3->addWidget(btn_left, 3, 7, 1, 1);

        btn_right = new QPushButton(tab_2);
        btn_right->setObjectName(QStringLiteral("btn_right"));
        sizePolicy.setHeightForWidth(btn_right->sizePolicy().hasHeightForWidth());
        btn_right->setSizePolicy(sizePolicy);
        btn_right->setStyleSheet(QStringLiteral("QPushButton{text-align : left;}"));

        gridLayout_3->addWidget(btn_right, 3, 8, 1, 1);

        btn_slash = new QPushButton(tab_2);
        btn_slash->setObjectName(QStringLiteral("btn_slash"));
        sizePolicy.setHeightForWidth(btn_slash->sizePolicy().hasHeightForWidth());
        btn_slash->setSizePolicy(sizePolicy);
        btn_slash->setStyleSheet(QStringLiteral("QPushButton{text-align : left;}"));

        gridLayout_3->addWidget(btn_slash, 3, 9, 1, 1);

        btn_space = new QPushButton(tab_2);
        btn_space->setObjectName(QStringLiteral("btn_space"));
        sizePolicy.setHeightForWidth(btn_space->sizePolicy().hasHeightForWidth());
        btn_space->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(btn_space, 4, 0, 1, 1);

        btn_www = new QPushButton(tab_2);
        btn_www->setObjectName(QStringLiteral("btn_www"));
        sizePolicy.setHeightForWidth(btn_www->sizePolicy().hasHeightForWidth());
        btn_www->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(btn_www, 4, 1, 1, 1);

        btn_sub = new QPushButton(tab_2);
        btn_sub->setObjectName(QStringLiteral("btn_sub"));
        sizePolicy.setHeightForWidth(btn_sub->sizePolicy().hasHeightForWidth());
        btn_sub->setSizePolicy(sizePolicy);
        btn_sub->setStyleSheet(QStringLiteral("QPushButton{text-align : left;}"));

        gridLayout_3->addWidget(btn_sub, 4, 2, 1, 1);

        btn_add = new QPushButton(tab_2);
        btn_add->setObjectName(QStringLiteral("btn_add"));
        sizePolicy.setHeightForWidth(btn_add->sizePolicy().hasHeightForWidth());
        btn_add->setSizePolicy(sizePolicy);
        btn_add->setStyleSheet(QStringLiteral("QPushButton{text-align : left;}"));

        gridLayout_3->addWidget(btn_add, 4, 3, 1, 1);

        btn_colon = new QPushButton(tab_2);
        btn_colon->setObjectName(QStringLiteral("btn_colon"));
        sizePolicy.setHeightForWidth(btn_colon->sizePolicy().hasHeightForWidth());
        btn_colon->setSizePolicy(sizePolicy);
        btn_colon->setStyleSheet(QStringLiteral("QPushButton{text-align : left;}"));

        gridLayout_3->addWidget(btn_colon, 4, 4, 1, 1);

        btn_comma = new QPushButton(tab_2);
        btn_comma->setObjectName(QStringLiteral("btn_comma"));
        sizePolicy.setHeightForWidth(btn_comma->sizePolicy().hasHeightForWidth());
        btn_comma->setSizePolicy(sizePolicy);
        btn_comma->setStyleSheet(QStringLiteral("QPushButton{text-align : left;}"));

        gridLayout_3->addWidget(btn_comma, 4, 5, 1, 1);

        btn_ent = new QPushButton(tab_2);
        btn_ent->setObjectName(QStringLiteral("btn_ent"));
        sizePolicy.setHeightForWidth(btn_ent->sizePolicy().hasHeightForWidth());
        btn_ent->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(btn_ent, 4, 6, 1, 1);

        btn_num = new QPushButton(tab_2);
        btn_num->setObjectName(QStringLiteral("btn_num"));
        sizePolicy.setHeightForWidth(btn_num->sizePolicy().hasHeightForWidth());
        btn_num->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(btn_num, 4, 7, 1, 1);

        btn_shi = new QPushButton(tab_2);
        btn_shi->setObjectName(QStringLiteral("btn_shi"));
        sizePolicy.setHeightForWidth(btn_shi->sizePolicy().hasHeightForWidth());
        btn_shi->setSizePolicy(sizePolicy);
        btn_shi->setCheckable(true);

        gridLayout_3->addWidget(btn_shi, 4, 8, 1, 1);

        btn_cap = new QPushButton(tab_2);
        btn_cap->setObjectName(QStringLiteral("btn_cap"));
        sizePolicy.setHeightForWidth(btn_cap->sizePolicy().hasHeightForWidth());
        btn_cap->setSizePolicy(sizePolicy);
        btn_cap->setCheckable(true);

        gridLayout_3->addWidget(btn_cap, 4, 9, 1, 1);

        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);


        retranslateUi(Key_board_dlg);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Key_board_dlg);
    } // setupUi

    void retranslateUi(QDialog *Key_board_dlg)
    {
        Key_board_dlg->setWindowTitle(QApplication::translate("Key_board_dlg", "\350\231\232\346\213\237\351\224\256\347\233\230", 0));
        b_2->setText(QApplication::translate("Key_board_dlg", "2", 0));
        b_cosh->setText(QApplication::translate("Key_board_dlg", "cosh", 0));
        b_sin->setText(QApplication::translate("Key_board_dlg", "sin", 0));
        b_right->setText(QApplication::translate("Key_board_dlg", ")", 0));
        b_sign->setText(QApplication::translate("Key_board_dlg", "sign", 0));
        b_ti->setText(QApplication::translate("Key_board_dlg", "Ti", 0));
        b_tan->setText(QApplication::translate("Key_board_dlg", "tan", 0));
        b_coth->setText(QApplication::translate("Key_board_dlg", "coth", 0));
        b_pi->setText(QApplication::translate("Key_board_dlg", "PI", 0));
        b_sqrt->setText(QApplication::translate("Key_board_dlg", "sqrt", 0));
        b_tanh->setText(QApplication::translate("Key_board_dlg", "tanh", 0));
        b_cot->setText(QApplication::translate("Key_board_dlg", "cot", 0));
        b_ln->setText(QApplication::translate("Key_board_dlg", "ln", 0));
        b_9->setText(QApplication::translate("Key_board_dlg", "9", 0));
        b_8->setText(QApplication::translate("Key_board_dlg", "8", 0));
        b_5->setText(QApplication::translate("Key_board_dlg", "5", 0));
        b_3->setText(QApplication::translate("Key_board_dlg", "3", 0));
        b_7->setText(QApplication::translate("Key_board_dlg", "7", 0));
        b_6->setText(QApplication::translate("Key_board_dlg", "6", 0));
        b_4->setText(QApplication::translate("Key_board_dlg", "4", 0));
        b_1->setText(QApplication::translate("Key_board_dlg", "1", 0));
        b_full->setText(QApplication::translate("Key_board_dlg", "Full", 0));
        b_left->setText(QApplication::translate("Key_board_dlg", "(", 0));
        b_sinh->setText(QApplication::translate("Key_board_dlg", "sinh", 0));
        b_cos->setText(QApplication::translate("Key_board_dlg", "cos", 0));
        b_abs->setText(QApplication::translate("Key_board_dlg", "abs", 0));
        b_0->setText(QApplication::translate("Key_board_dlg", "0", 0));
        b_a->setText(QApplication::translate("Key_board_dlg", ".", 0));
        b_back->setText(QApplication::translate("Key_board_dlg", "<--", 0));
        b_add->setText(QApplication::translate("Key_board_dlg", "+", 0));
        b_b->setText(QApplication::translate("Key_board_dlg", "-", 0));
        b_mul->setText(QApplication::translate("Key_board_dlg", "*", 0));
        b_c->setText(QApplication::translate("Key_board_dlg", "/", 0));
        b_ent->setText(QApplication::translate("Key_board_dlg", "Ent", 0));
        b_comma->setText(QApplication::translate("Key_board_dlg", ",", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Key_board_dlg", "Tab 1", 0));
        btn_1->setText(QApplication::translate("Key_board_dlg", "!\n"
"  1", 0));
        btn_2->setText(QApplication::translate("Key_board_dlg", "@\n"
"  2", 0));
        btn_3->setText(QApplication::translate("Key_board_dlg", "#\n"
"  3", 0));
        btn_4->setText(QApplication::translate("Key_board_dlg", "$\n"
"  4", 0));
        btn_5->setText(QApplication::translate("Key_board_dlg", "%\n"
"  5", 0));
        btn_6->setText(QApplication::translate("Key_board_dlg", "^\n"
"  6", 0));
        btn_7->setText(QApplication::translate("Key_board_dlg", "&&\n"
"  7", 0));
        btn_8->setText(QApplication::translate("Key_board_dlg", "*\n"
"  8", 0));
        btn_9->setText(QApplication::translate("Key_board_dlg", "(\n"
"  9", 0));
        btn_0->setText(QApplication::translate("Key_board_dlg", ")\n"
"  0", 0));
        btn_q->setText(QApplication::translate("Key_board_dlg", "Q", 0));
        btn_w->setText(QApplication::translate("Key_board_dlg", "W", 0));
        btn_e->setText(QApplication::translate("Key_board_dlg", "E", 0));
        btn_r->setText(QApplication::translate("Key_board_dlg", "R", 0));
        btn_t->setText(QApplication::translate("Key_board_dlg", "T", 0));
        btn_y->setText(QApplication::translate("Key_board_dlg", "Y", 0));
        btn_u->setText(QApplication::translate("Key_board_dlg", "U", 0));
        btn_i->setText(QApplication::translate("Key_board_dlg", "I", 0));
        btn_o->setText(QApplication::translate("Key_board_dlg", "O", 0));
        btn_p->setText(QApplication::translate("Key_board_dlg", "P", 0));
        btn_a->setText(QApplication::translate("Key_board_dlg", "A", 0));
        btn_s->setText(QApplication::translate("Key_board_dlg", "S", 0));
        btn_d->setText(QApplication::translate("Key_board_dlg", "D", 0));
        btn_f->setText(QApplication::translate("Key_board_dlg", "F", 0));
        btn_g->setText(QApplication::translate("Key_board_dlg", "G", 0));
        btn_h->setText(QApplication::translate("Key_board_dlg", "H", 0));
        btn_j->setText(QApplication::translate("Key_board_dlg", "J", 0));
        btn_k->setText(QApplication::translate("Key_board_dlg", "K", 0));
        btn_l->setText(QApplication::translate("Key_board_dlg", "L", 0));
        btn_back->setText(QApplication::translate("Key_board_dlg", "<--", 0));
        btn_z->setText(QApplication::translate("Key_board_dlg", "Z", 0));
        btn_x->setText(QApplication::translate("Key_board_dlg", "X", 0));
        btn_c->setText(QApplication::translate("Key_board_dlg", "C", 0));
        btn_v->setText(QApplication::translate("Key_board_dlg", "V", 0));
        btn_b->setText(QApplication::translate("Key_board_dlg", "B", 0));
        btn_n->setText(QApplication::translate("Key_board_dlg", "N", 0));
        btn_m->setText(QApplication::translate("Key_board_dlg", "M", 0));
        btn_left->setText(QApplication::translate("Key_board_dlg", "<\n"
"  ,", 0));
        btn_right->setText(QApplication::translate("Key_board_dlg", ">\n"
"  .", 0));
        btn_slash->setText(QApplication::translate("Key_board_dlg", "?\n"
"  /", 0));
        btn_space->setText(QString());
        btn_www->setText(QApplication::translate("Key_board_dlg", "www", 0));
        btn_sub->setText(QApplication::translate("Key_board_dlg", "_\n"
"  -", 0));
        btn_add->setText(QApplication::translate("Key_board_dlg", "+\n"
"  =", 0));
        btn_colon->setText(QApplication::translate("Key_board_dlg", "\357\274\232\n"
"  \357\274\233", 0));
        btn_comma->setText(QApplication::translate("Key_board_dlg", "\"\n"
"  '", 0));
        btn_ent->setText(QApplication::translate("Key_board_dlg", "Ent", 0));
        btn_num->setText(QApplication::translate("Key_board_dlg", "Num", 0));
        btn_shi->setText(QApplication::translate("Key_board_dlg", "Shi", 0));
        btn_cap->setText(QApplication::translate("Key_board_dlg", "Cap", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Key_board_dlg", "Tab 2", 0));
    } // retranslateUi

};

namespace Ui {
    class Key_board_dlg: public Ui_Key_board_dlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KEY_BOARD_DLG_H
