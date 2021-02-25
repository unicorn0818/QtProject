#include "key_board_dlg.h"
#include "ui_key_board_dlg.h"
Key_board_dlg *Key_board_dlg::key_board=NULL;
Key_board_dlg::Key_board_dlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Key_board_dlg)
{
    ui->setupUi(this);
    ui->tabWidget->tabBar()->hide();
    QFont font=QFont ("宋体",10);
    group_1=new QButtonGroup(this);
    group_2=new QButtonGroup(this);
    set_id();
    connect(group_1,SIGNAL(buttonClicked(int )),this,SLOT(send_key1(int )));
    connect(group_2,SIGNAL(buttonClicked(int )),this,SLOT(send_key2(int )));
    QList<QAbstractButton*> btns=group_1->buttons();
    for(int i=0;i<btns.count();i++)
    {
        btns.at(i)->setFont(font);
        btns.at(i)->setFocusPolicy(Qt::NoFocus);
    }
    btns=group_2->buttons();
    for(int i=0;i<btns.count();i++)
    {
        btns.at(i)->setFont(font);
        btns.at(i)->setFocusPolicy(Qt::NoFocus);
    }
    setFixedSize(200,300);
    setFocusPolicy(Qt::NoFocus);
    setWindowFlags( Qt::WindowStaysOnTopHint | Qt::Tool |Qt::WindowDoesNotAcceptFocus);

    setStyleSheet("QPushButton{border-radius: 4px;border: none;width: 75px;height: 25px;font-size: 13px;}");
}
Key_board_dlg *Key_board_dlg::get_key_board(QWidget *parent)
{
    if(key_board==NULL)
    {
        key_board=new Key_board_dlg(parent);
    }
    return key_board;
}
Key_board_dlg::~Key_board_dlg()
{
    key_board=NULL;
    delete ui;
}


void Key_board_dlg::send_key1(int  id)
{
    int k;
    switch (id) {
    case 0:
        k=Qt::Key_0;
        break;
    case 1:
        k=Qt::Key_1;
        break;
    case 2:
        k=Qt::Key_2;
        break;
    case 3:
        k=Qt::Key_3;
        break;
    case 4:
        k=Qt::Key_4;
        break;
    case 5:
        k=Qt::Key_5;
        break;
    case 6:
        k=Qt::Key_6;
        break;
    case 7:
        k=Qt::Key_7;
        break;
    case 8:
        k=Qt::Key_8;
        break;
    case 9:
        k=Qt::Key_9;
        break;
    case 10:
        k=0xBE;
        break;
    case 11:
        k=0xBD;
        break;
    case 12:
        k=0xBF;
        break;
    case 13:
        k=0x08;
        break;
    case 14:
        k=0x0D;
        break;

    case 16:
        keybd_event(Qt::Key_C, 0, 0, 0);//按键按下
        keybd_event(Qt::Key_C, 0,KEYEVENTF_KEYUP, 0);
        keybd_event(Qt::Key_O, 0, 0, 0);//按键按下
        keybd_event(Qt::Key_O, 0,KEYEVENTF_KEYUP, 0);
        keybd_event(Qt::Key_S, 0, 0, 0);//按键按下
        keybd_event(Qt::Key_S, 0,KEYEVENTF_KEYUP, 0);
        return;
    case 17:
        keybd_event(Qt::Key_S, 0, 0, 0);//按键按下
        keybd_event(Qt::Key_S, 0,KEYEVENTF_KEYUP, 0);
        keybd_event(Qt::Key_I, 0, 0, 0);//按键按下
        keybd_event(Qt::Key_I, 0,KEYEVENTF_KEYUP, 0);
        keybd_event(Qt::Key_N, 0, 0, 0);//按键按下
        keybd_event(Qt::Key_N, 0,KEYEVENTF_KEYUP, 0);
        return;
    case 18:
        keybd_event(Qt::Key_T, 0, 0, 0);//按键按下
        keybd_event(Qt::Key_T, 0,KEYEVENTF_KEYUP, 0);
        keybd_event(Qt::Key_A, 0, 0, 0);//按键按下
        keybd_event(Qt::Key_A, 0,KEYEVENTF_KEYUP, 0);
        keybd_event(Qt::Key_N, 0, 0, 0);//按键按下
        keybd_event(Qt::Key_N, 0,KEYEVENTF_KEYUP, 0);
        return;
    case 19:
        keybd_event(Qt::Key_C, 0, 0, 0);//按键按下
        keybd_event(Qt::Key_C, 0,KEYEVENTF_KEYUP, 0);
        keybd_event(Qt::Key_O, 0, 0, 0);//按键按下
        keybd_event(Qt::Key_O, 0,KEYEVENTF_KEYUP, 0);
        keybd_event(Qt::Key_T, 0, 0, 0);//按键按下
        keybd_event(Qt::Key_T, 0,KEYEVENTF_KEYUP, 0);
        return;
    case 20:
        keybd_event(Qt::Key_C, 0, 0, 0);//按键按下
        keybd_event(Qt::Key_C, 0,KEYEVENTF_KEYUP, 0);
        keybd_event(Qt::Key_O, 0, 0, 0);//按键按下
        keybd_event(Qt::Key_O, 0,KEYEVENTF_KEYUP, 0);
        keybd_event(Qt::Key_S, 0, 0, 0);//按键按下
        keybd_event(Qt::Key_S, 0,KEYEVENTF_KEYUP, 0);
        keybd_event(Qt::Key_H, 0, 0, 0);//按键按下
        keybd_event(Qt::Key_H, 0,KEYEVENTF_KEYUP, 0);
        return;
    case 21:
        keybd_event(Qt::Key_S, 0, 0, 0);//按键按下
        keybd_event(Qt::Key_S, 0,KEYEVENTF_KEYUP, 0);
        keybd_event(Qt::Key_I, 0, 0, 0);//按键按下
        keybd_event(Qt::Key_I, 0,KEYEVENTF_KEYUP, 0);
        keybd_event(Qt::Key_N, 0, 0, 0);//按键按下
        keybd_event(Qt::Key_N, 0,KEYEVENTF_KEYUP, 0);
        keybd_event(Qt::Key_H, 0, 0, 0);//按键按下
        keybd_event(Qt::Key_H, 0,KEYEVENTF_KEYUP, 0);
        return;
    case 22:
        keybd_event(Qt::Key_T, 0, 0, 0);//按键按下
        keybd_event(Qt::Key_T, 0,KEYEVENTF_KEYUP, 0);
        keybd_event(Qt::Key_A, 0, 0, 0);//按键按下
        keybd_event(Qt::Key_A, 0,KEYEVENTF_KEYUP, 0);
        keybd_event(Qt::Key_N, 0, 0, 0);//按键按下
        keybd_event(Qt::Key_N, 0,KEYEVENTF_KEYUP, 0);
        keybd_event(Qt::Key_H, 0, 0, 0);//按键按下
        keybd_event(Qt::Key_H, 0,KEYEVENTF_KEYUP, 0);
        return;
    case 23:
        keybd_event(Qt::Key_C, 0, 0, 0);//按键按下
        keybd_event(Qt::Key_C, 0,KEYEVENTF_KEYUP, 0);
        keybd_event(Qt::Key_O, 0, 0, 0);//按键按下
        keybd_event(Qt::Key_O, 0,KEYEVENTF_KEYUP, 0);
        keybd_event(Qt::Key_T, 0, 0, 0);//按键按下
        keybd_event(Qt::Key_T, 0,KEYEVENTF_KEYUP, 0);
        keybd_event(Qt::Key_H, 0, 0, 0);//按键按下
        keybd_event(Qt::Key_H, 0,KEYEVENTF_KEYUP, 0);
        return;
    case 24:
        keybd_event(Qt::Key_A, 0, 0, 0);//按键按下
        keybd_event(Qt::Key_A, 0,KEYEVENTF_KEYUP, 0);
        keybd_event(Qt::Key_B, 0, 0, 0);//按键按下
        keybd_event(Qt::Key_B, 0,KEYEVENTF_KEYUP, 0);
        keybd_event(Qt::Key_S, 0, 0, 0);//按键按下
        keybd_event(Qt::Key_S, 0,KEYEVENTF_KEYUP, 0);
        return;
    case 25:
        keybd_event(Qt::Key_S, 0, 0, 0);//按键按下
        keybd_event(Qt::Key_S, 0,KEYEVENTF_KEYUP, 0);
        keybd_event(Qt::Key_Q, 0, 0, 0);//按键按下
        keybd_event(Qt::Key_Q, 0,KEYEVENTF_KEYUP, 0);
        keybd_event(Qt::Key_R, 0, 0, 0);//按键按下
        keybd_event(Qt::Key_R, 0,KEYEVENTF_KEYUP, 0);
        keybd_event(Qt::Key_T, 0, 0, 0);//按键按下
        keybd_event(Qt::Key_T, 0,KEYEVENTF_KEYUP, 0);
        return;
    case 26:
        keybd_event(Qt::Key_L, 0, 0, 0);//按键按下
        keybd_event(Qt::Key_L, 0,KEYEVENTF_KEYUP, 0);
        keybd_event(Qt::Key_N, 0, 0, 0);//按键按下
        keybd_event(Qt::Key_N, 0,KEYEVENTF_KEYUP, 0);
        return;
    case 27:
        keybd_event(Qt::Key_S, 0, 0, 0);//按键按下
        keybd_event(Qt::Key_S, 0,KEYEVENTF_KEYUP, 0);
        keybd_event(Qt::Key_I, 0, 0, 0);//按键按下
        keybd_event(Qt::Key_I, 0,KEYEVENTF_KEYUP, 0);
        keybd_event(Qt::Key_G, 0, 0, 0);//按键按下
        keybd_event(Qt::Key_G, 0,KEYEVENTF_KEYUP, 0);
        keybd_event(Qt::Key_N, 0, 0, 0);//按键按下
        keybd_event(Qt::Key_N, 0,KEYEVENTF_KEYUP, 0);
        return;
    case 28:
        keybd_event(0x10, 0, 0, 0);//按键按下
        keybd_event(0x39, 0, 0, 0);
        keybd_event(0x39, 0, KEYEVENTF_KEYUP, 0);//按键按下
        keybd_event(0x10, 0, KEYEVENTF_KEYUP, 0);
        return;
    case 29:
        keybd_event(0x10, 0, 0, 0);//按键按下
        keybd_event(0x30, 0, 0, 0);
        keybd_event(0x30, 0, KEYEVENTF_KEYUP, 0);//按键按下
        keybd_event(0x10, 0, KEYEVENTF_KEYUP, 0);
        return;
    case 30:
        keybd_event(0x10, 0, 0, 0);//按键按下
        keybd_event(0xBB, 0, 0, 0);
        keybd_event(0xBB, 0, KEYEVENTF_KEYUP, 0);//按键按下
        keybd_event(0x10, 0, KEYEVENTF_KEYUP, 0);
        return;
    case 31:
        keybd_event(0x10, 0, 0, 0);//按键按下
        keybd_event(0x38, 0, 0, 0);
        keybd_event(0x38, 0, KEYEVENTF_KEYUP, 0);//按键按下
        keybd_event(0x10, 0, KEYEVENTF_KEYUP, 0);
        return;
    case 32:
        keybd_event(0x10, 0, 0, 0);//按键按下
        keybd_event(Qt::Key_P, 0, 0, 0);
        keybd_event(Qt::Key_P, 0, KEYEVENTF_KEYUP, 0);//按键按下
        keybd_event(Qt::Key_I, 0, 0, 0);
        keybd_event(Qt::Key_I, 0, KEYEVENTF_KEYUP, 0);//按键按下
        keybd_event(0x10, 0, KEYEVENTF_KEYUP, 0);
        return;
    case 33:
        keybd_event(0x10, 0, 0, 0);//按键按下
        keybd_event(Qt::Key_T, 0, 0, 0);
        keybd_event(Qt::Key_T, 0, KEYEVENTF_KEYUP, 0);//按键按下
        keybd_event(0x10, 0, KEYEVENTF_KEYUP, 0);
        keybd_event(Qt::Key_I, 0, 0, 0);
        keybd_event(Qt::Key_I, 0, KEYEVENTF_KEYUP, 0);//按键按下
        return;
    case 34:
        k=0xBC;
        break;
    default:
        return;
    }
    if(m_system)
    {
    }else
    {
        keybd_event(k, 0, 0, 0);//按键按下
        keybd_event(k, 0,KEYEVENTF_KEYUP, 0);
    }
}
void Key_board_dlg::send_key2(int  id)
{
    int k;
    switch (id) {
    case 0:
        k=Qt::Key_0;
        break;
    case 1:
        k=Qt::Key_1;
        break;
    case 2:
        k=Qt::Key_2;
        break;
    case 3:
        k=Qt::Key_3;
        break;
    case 4:
        k=Qt::Key_4;
        break;
    case 5:
        k=Qt::Key_5;
        break;
    case 6:
        k=Qt::Key_6;
        break;
    case 7:
        k=Qt::Key_7;
        break;
    case 8:
        k=Qt::Key_8;
        break;
    case 9:
        k=Qt::Key_9;
        break;
    case 10:
        k=Qt::Key_A;
        break;
    case 11:
        k=Qt::Key_B;
        break;
    case 12:
        k=Qt::Key_C;
        break;
    case 13:
        k=Qt::Key_D;
        break;
    case 14:
        k=Qt::Key_E;
        break;
    case 15:
        k=Qt::Key_F;
        break;
    case 16:
        k=Qt::Key_G;
        break;
    case 17:
        k=Qt::Key_H;
        break;
    case 18:
        k=Qt::Key_I;
        break;
    case 19:
        k=Qt::Key_J;
        break;
    case 20:
        k=Qt::Key_K;
        break;
    case 21:
        k=Qt::Key_L;
        break;
    case 22:
        k=Qt::Key_M;
        break;
    case 23:
        k=Qt::Key_N;
        break;
    case 24:
        k=Qt::Key_O;
        break;
    case 25:
        k=Qt::Key_P;
        break;
    case 26:
        k=Qt::Key_Q;
        break;
    case 27:
        k=Qt::Key_R;
        break;
    case 28:
        k=Qt::Key_S;
        break;
    case 29:
        k=Qt::Key_T;
        break;
    case 30:
        k=Qt::Key_U;
        break;
    case 31:
        k=Qt::Key_V;
        break;
    case 32:
        k=Qt::Key_W;
        break;
    case 33:
        k=Qt::Key_X;
        break;
    case 34:
        k=Qt::Key_Y;
        break;
    case 35:
        k=Qt::Key_Z;
        break;
    case 36:
        k=0x08;
        break;
    case 37:
        k=0xBC;
        break;
    case 38:
        k=0xBE;
        break;
    case 39:
        k=0xBF;
        break;
    case 40:
        k=0x20;
        break;
    case 41:
        keybd_event(Qt::Key_W, 0, 0, 0);
        keybd_event(Qt::Key_W, 0, KEYEVENTF_KEYUP, 0);
        keybd_event(Qt::Key_W, 0, 0, 0);
        keybd_event(Qt::Key_W, 0, KEYEVENTF_KEYUP, 0);
        keybd_event(Qt::Key_W, 0, 0, 0);
        keybd_event(Qt::Key_W, 0, KEYEVENTF_KEYUP, 0);
        keybd_event(0xBE, 0, 0, 0);
        keybd_event(0xBE, 0, KEYEVENTF_KEYUP, 0);
        keybd_event(Qt::Key_X, 0, 0, 0);
        keybd_event(Qt::Key_X, 0, KEYEVENTF_KEYUP, 0);
        keybd_event(Qt::Key_L, 0, 0, 0);
        keybd_event(Qt::Key_L, 0, KEYEVENTF_KEYUP, 0);
        keybd_event(0xBD, 0, 0, 0);
        keybd_event(0xBD, 0, KEYEVENTF_KEYUP, 0);
        keybd_event(Qt::Key_E, 0, 0, 0);
        keybd_event(Qt::Key_E, 0, KEYEVENTF_KEYUP, 0);
        keybd_event(Qt::Key_L, 0, 0, 0);
        keybd_event(Qt::Key_L, 0, KEYEVENTF_KEYUP, 0);
        keybd_event(Qt::Key_E, 0, 0, 0);
        keybd_event(Qt::Key_E, 0, KEYEVENTF_KEYUP, 0);
        keybd_event(0xBE, 0, 0, 0);
        keybd_event(0xBE, 0, KEYEVENTF_KEYUP, 0);
        keybd_event(Qt::Key_C, 0, 0, 0);
        keybd_event(Qt::Key_C, 0, KEYEVENTF_KEYUP, 0);
        keybd_event(Qt::Key_O, 0, 0, 0);
        keybd_event(Qt::Key_O, 0, KEYEVENTF_KEYUP, 0);
        keybd_event(Qt::Key_M, 0, 0, 0);
        keybd_event(Qt::Key_M, 0, KEYEVENTF_KEYUP, 0);
        return;
    case 42:
        k=0xBD;
        break;
    case 43:
        k=0xBB;
        break;
    case 44:
        k=0xBA;
        break;
    case 45:
        k=0xDE;
        break;
    case 46:
        k=0x0D;
        break;
    default:
        break;
    }
    if(m_system)
    {
    }else
    {
        keybd_event(k, 0, 0, 0);//按键按下
        keybd_event(k, 0, KEYEVENTF_KEYUP, 0);
        if(ui->btn_shi->isChecked())
        {
            ui->btn_shi->setChecked(false);
            on_btn_shi_clicked();
        }
    }
}
void Key_board_dlg::on_b_full_clicked()
{
    ui->tabWidget->setCurrentIndex(1);
    setFixedSize(350,200);
}

void Key_board_dlg::on_btn_num_clicked()
{
    ui->tabWidget->setCurrentIndex(0);
    setFixedSize(200,300);
}
void Key_board_dlg::set_id()
{
    group_1->addButton(ui->b_0,0);
    group_1->addButton(ui->b_1,1);
    group_1->addButton(ui->b_2,2);
    group_1->addButton(ui->b_3,3);
    group_1->addButton(ui->b_4,4);
    group_1->addButton(ui->b_5,5);
    group_1->addButton(ui->b_6,6);
    group_1->addButton(ui->b_7,7);
    group_1->addButton(ui->b_8,8);
    group_1->addButton(ui->b_9,9);
    group_1->addButton(ui->b_a,10);
    group_1->addButton(ui->b_b,11);
    group_1->addButton(ui->b_c,12);
    group_1->addButton(ui->b_back,13);
    group_1->addButton(ui->b_ent,14);
    group_1->addButton(ui->b_full,15);

    group_1->addButton(ui->b_cos,16);
    group_1->addButton(ui->b_sin,17);
    group_1->addButton(ui->b_tan,18);
    group_1->addButton(ui->b_cot,19);
    group_1->addButton(ui->b_cosh,20);
    group_1->addButton(ui->b_sinh,21);
    group_1->addButton(ui->b_tanh,22);
    group_1->addButton(ui->b_coth,23);
    group_1->addButton(ui->b_abs,24);
    group_1->addButton(ui->b_sqrt,25);
    group_1->addButton(ui->b_ln,26);
    group_1->addButton(ui->b_sign,27);
    group_1->addButton(ui->b_left,28);
    group_1->addButton(ui->b_right,29);
    group_1->addButton(ui->b_add,30);
    group_1->addButton(ui->b_mul,31);
    group_1->addButton(ui->b_pi,32);
    group_1->addButton(ui->b_ti,33);
    group_1->addButton(ui->b_comma,34);


    group_2->addButton(ui->btn_0,0);
    group_2->addButton(ui->btn_1,1);
    group_2->addButton(ui->btn_2,2);
    group_2->addButton(ui->btn_3,3);
    group_2->addButton(ui->btn_4,4);
    group_2->addButton(ui->btn_5,5);
    group_2->addButton(ui->btn_6,6);
    group_2->addButton(ui->btn_7,7);
    group_2->addButton(ui->btn_8,8);
    group_2->addButton(ui->btn_9,9);
    group_2->addButton(ui->btn_a,10);
    group_2->addButton(ui->btn_b,11);
    group_2->addButton(ui->btn_c,12);
    group_2->addButton(ui->btn_d,13);
    group_2->addButton(ui->btn_e,14);
    group_2->addButton(ui->btn_f,15);
    group_2->addButton(ui->btn_g,16);
    group_2->addButton(ui->btn_h,17);
    group_2->addButton(ui->btn_i,18);
    group_2->addButton(ui->btn_j,19);
    group_2->addButton(ui->btn_k,20);
    group_2->addButton(ui->btn_l,21);
    group_2->addButton(ui->btn_m,22);
    group_2->addButton(ui->btn_n,23);
    group_2->addButton(ui->btn_o,24);
    group_2->addButton(ui->btn_p,25);
    group_2->addButton(ui->btn_q,26);
    group_2->addButton(ui->btn_r,27);
    group_2->addButton(ui->btn_s,28);
    group_2->addButton(ui->btn_t,29);
    group_2->addButton(ui->btn_u,30);
    group_2->addButton(ui->btn_v,31);
    group_2->addButton(ui->btn_w,32);
    group_2->addButton(ui->btn_x,33);
    group_2->addButton(ui->btn_y,34);
    group_2->addButton(ui->btn_z,35);
    group_2->addButton(ui->btn_back,36);
    group_2->addButton(ui->btn_left,37);
    group_2->addButton(ui->btn_right,38);
    group_2->addButton(ui->btn_slash,39);


    group_2->addButton(ui->btn_space,40);
    group_2->addButton(ui->btn_www,41);
    group_2->addButton(ui->btn_sub,42);
    group_2->addButton(ui->btn_add,43);
    group_2->addButton(ui->btn_colon,44);
    group_2->addButton(ui->btn_comma,45);
    group_2->addButton(ui->btn_ent,46);
}



void Key_board_dlg::on_btn_shi_clicked()
{
    if(ui->btn_shi->isChecked())
    {
         keybd_event(0x10, 0, 0, 0);//按键按下
    }else
    {
        keybd_event(0x10, 0,KEYEVENTF_KEYUP, 0);
    }
}

void Key_board_dlg::on_btn_cap_clicked()
{
    keybd_event(0x14, 0, 0, 0);
    keybd_event(0x14, 0,KEYEVENTF_KEYUP, 0);
}
