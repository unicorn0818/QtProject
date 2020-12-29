#include "statu_list.h"
#include "ui_statu_list.h"

StateDelegate::StateDelegate(QObject * parent):QItemDelegate(parent)
{
}
QWidget * StateDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index)const
{
    //M_spinbox *box;
    QComboBox *box;
    QLineEdit * edit;
    edit=new QLineEdit(parent);
    box= new QComboBox(parent);
    if(index.column()==4)
    {
        box->addItem("启用");
        box->addItem("禁用");//结束后停止输出，1：结束后进行下一项,1回到开始的第一项进行输出
        return box;
    }else if(index.column()==5)
    {
        QStringList list;
        list<<"停止输出"<<"输出下一项"<<"输出第一项";
        box->addItems(list);
        return box;
    }
    return edit;
}
QString StateDelegate::float_to_str(float data, int len)const
{
    QString str;
    str=QString("%1").arg(data,0,'f',len);
    while(str.at(str.length()-1)=='0'&&str.indexOf(".")>=0)
    {
        if(str.at(str.length()-2)=='.')
        {
            str.remove(str.length()-2,2);
        }else
        {
            str.remove(str.length()-1,1);
        }
    }
    return str;
}
void StateDelegate::setEditorData(QWidget *editor, const QModelIndex &index)const
{
    QLineEdit * edit;
    QComboBox * box;
    QString str;
    if(index.column()==4||index.column()==5)
    {
        str=index.model()->data(index, Qt::EditRole).toString();
        box=static_cast<QComboBox*>(editor);
        box->setCurrentText(str);
    }else
    {
        edit= static_cast<QLineEdit*>(editor);
        edit->setText(index.model()->data(index, Qt::EditRole).toString());
    }
    return;
}
void StateDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    //M_spinbox *box;
    QLineEdit * edit;
    QComboBox * box;
    if(index.column()==4||index.column()==5)
    {
        box=static_cast<QComboBox*>(editor);
        model->setData(index, box->currentText(), Qt::EditRole);
        emit editd(index,box->currentText());
    }
    else
    {
        edit=static_cast<QLineEdit*>(editor);
        model->setData(index,edit->text(), Qt::EditRole);
        emit editd(index,edit->text());
    }
}
void StateDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index)const
{
    editor->setGeometry(option.rect);
}
StateDelegate::~StateDelegate()
{

}


Statu_list::Statu_list(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Statu_list)
{
    ui->setupUi(this);
    mesg_model=new QStandardItemModel(this);
    QStringList label;
    label<<"幅值(V)"<<"相位"<<"频率(Hz)"<<"持续时间(s)"<<"是否启用"<<"结束状态";
    mesg_model->setHorizontalHeaderLabels(label);
    ui->line->setStyleSheet("border:2px solid rgb(255,215,0);");
    ui->line_2->setStyleSheet("border:2px solid rgb(0,255,0);");
    ui->line_3->setStyleSheet("border:2px solid rgb(255,0,0);");
    ui->list_state_now->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->list_state_now->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<6;j++)
        {
            mesg_model->setItem(i,j,new QStandardItem(0));
        }
    }
    StateDelegate* dele= new StateDelegate(this);
    connect(dele,SIGNAL(editd(QModelIndex,QString)),SLOT(update_vector(QModelIndex,QString)));
    ui->list_state_now->setItemDelegate(dele);
    ui->list_state_now->setModel(mesg_model);
    POWERStatus *p_st;
    for(long i=0;i<10;i++)
    {
        p_st=new POWERStatus;
        memset(p_st,0,sizeof(POWERStatus));
        p_st->number=i;
        p_st->powerset.Fa=50;
        p_st->powerset.Fb=50;
        p_st->powerset.Fc=50;
        p_st->powerset.Fd=50;
        p_st->powerset.harmoPhase[0][0]=0;
        p_st->powerset.harmoPhase[2][0]=240;
        p_st->powerset.harmoPhase[4][0]=120;
        p_st->powerset.harmoPhase[6][0]=0;
        p_st->active=1;
        state_vector<<p_st;
    }
    ui->label_2->hide();
    ui->now_start->hide();
    ui->wait_start->hide();
    xl609=L_XL803;
    connect(xl609,SIGNAL(send_to_state_out(QByteArray,QByteArray)),this,SLOT(recv_mesg(QByteArray,QByteArray)),Qt::QueuedConnection);
    ui->start_state->set_value(2);
    start_a=0;
    start_b=0;
    start_c=0;
    start_d=0;
    show_out_list();
    all_down.clear();
    all_read=false;
    flag_no_stop=false;
    read_index=0;
    reset_wave=false;
    timer=new QTimer();
    timer->setSingleShot(true);
    connect(timer,SIGNAL(timeout()),this,SLOT(set_flag()));
    mesg=new QMessageBox(QMessageBox::Information,"提示","",QMessageBox::Yes,this);
    xl609->set_map(ui->show);
    l_ua=ui->show->addGraph();
    l_ub=ui->show->addGraph();
    l_uc=ui->show->addGraph();
    l_ud=ui->show->addGraph();
    l_ua->setPen(QPen(Qt::yellow,1));
    l_ub->setPen(QPen(Qt::green,1));
    l_uc->setPen(QPen(Qt::red,1));
    l_ud->setPen(QPen(Qt::blue,1));
}

Statu_list::~Statu_list()
{
    delete ui;
}
void Statu_list::set_flag()
{
    reset_wave=false;
}
void Statu_list::show_out_list()
{
    float ua=0;
    float ub=0;
    float uc=0;
    float ud=0;
    for(int i=0;i<mesg_model->rowCount();i++)
    {
        for(int j=0;j<3;j++)
        {
            mesg_model->item(i,j)->setText(0);
        }
    }
    for(int i=0,j=0;i<mesg_model->rowCount();i++)
    {

            ua=state_vector.at(i)->powerset.fundamental[0];
            ua=ua*state_vector.at(i)->powerset.harmoVal[0][0]/100;
            ub=state_vector.at(i)->powerset.fundamental[2];
            ub=ub*state_vector.at(i)->powerset.harmoVal[2][0]/100;
            uc=state_vector.at(i)->powerset.fundamental[4];
            uc=uc*state_vector.at(i)->powerset.harmoVal[4][0]/100;
            ud=state_vector.at(i)->powerset.fundamental[6];
            ud=ud*state_vector.at(i)->powerset.harmoVal[6][0]/100;
            mesg_model->item(j,0)->setText(QString("%1,%2,%3,%4")\
                                                .arg(xl609->float_to_str(ua,5))\
                                                .arg(xl609->float_to_str(ub,5))\
                                                .arg(xl609->float_to_str(uc,5))\
                                                .arg(xl609->float_to_str(ud,5)));
            ua=state_vector.at(i)->powerset.harmoPhase[0][0];
            ub=state_vector.at(i)->powerset.harmoPhase[2][0];
            uc=state_vector.at(i)->powerset.harmoPhase[4][0];
            ud=state_vector.at(i)->powerset.harmoPhase[6][0];
            mesg_model->item(j,1)->setText(QString("%1,%2,%3,%4")\
                                                .arg(xl609->float_to_str(ua,5))\
                                                .arg(xl609->float_to_str(ub,5))\
                                                .arg(xl609->float_to_str(uc,5))\
                                                .arg(xl609->float_to_str(ud,5)));
            mesg_model->item(j,2)->setText(QString("%1,%2,%3,%4").arg(\
                                                xl609->float_to_str(state_vector.at(i)->powerset.Fa,5)).arg(\
                                                xl609->float_to_str(state_vector.at(i)->powerset.Fb,5)).arg(\
                                                xl609->float_to_str(state_vector.at(i)->powerset.Fc,5)).arg(\
                                                xl609->float_to_str(state_vector.at(i)->powerset.Fd,5)));
            mesg_model->item(j,3)->setText(QString("%1")\
                                                .arg(xl609->float_to_str(state_vector.at(i)->timeLastMs/1000)));
            QString str;
            if(state_vector.at(j)->active>0)
            {
                str="启用";
            }else
            {
                str="禁用";
            }
            mesg_model->item(j,4)->setData(str,Qt::EditRole);
            if(state_vector.at(j)->next==0)
            {
                str="停止输出";
            }else if(state_vector.at(j)->next==1)
            {
                str="输出下一项";
            }else
            {
                str="输出第一项";
            }
            mesg_model->item(j,5)->setData(str,Qt::EditRole);
            j++;
    }
}
void Statu_list::update_vector(QModelIndex index,QString value)
{
    if(value.length()<=0)
        value="0,0,0";
    if(index.row()<0)
        return;
    float ua,ub,uc,ud;
    ua=ub=uc=ud=0;
    if(index.column()<3)
    {
        bool flag;
        for(int i=0;i<3;i++)
        {
            if(i==0)
            {
                ua=(value.mid(0,value.indexOf(","))).toFloat(&flag);
                value.remove(0,value.indexOf(",")+1);
            }else if(i==1)
            {
                ub=(value.mid(0,value.indexOf(","))).toFloat(&flag);
                value.remove(0,value.indexOf(",")+1);
            }else if(i==2)
            {
                uc=(value.mid(0,value.length())).toFloat(&flag);
                value.remove(0,value.indexOf(",")+1);
            }else if(i==3)
            {
                ud=(value.mid(0,value.length())).toFloat(&flag);
                value.remove(0,value.indexOf(",")+1);
            }
            if(flag==false)
            {
                QMessageBox::information(this,"提示","无法解析!");
                value="0,0,0";
                mesg_model->item(index.row(),index.column())->setData(value,Qt::EditRole);
                return;
            }
        }
    }
    state_vector[index.row()]->number=index.row();
    float m_test=10.0;
    switch (index.column()) {
    case 0:
        if(ua>500)
            ua=500;
        if(ua<0)
            ua=0;
        if(ub>500)
            ub=500;
        if(ub<0)
            ub=0;
        if(uc>500)
            uc=500;
        if(uc<0)
            uc=0;
        if(ud>500)
            ud=500;
        if(ud<0)
            ud=0;
        state_vector[index.row()]->powerset.fundamental[0]=ua;
        state_vector[index.row()]->powerset.harmoVal[0][0]=(float)100;
        state_vector[index.row()]->powerset.fundamental[2]=ub;
        state_vector[index.row()]->powerset.harmoVal[2][0]=(float)100;
        state_vector[index.row()]->powerset.fundamental[4]=uc;
        state_vector[index.row()]->powerset.harmoVal[4][0]=(float)100;
        state_vector[index.row()]->powerset.fundamental[6]=ud;
        state_vector[index.row()]->powerset.harmoVal[6][0]=(float)100;

//        if(index.row()==0)
//        {
//            m_test=5.0;
//        }else
//        {
//            m_test=10.0;
//        }
//        state_vector[index.row()]->powerset.fundamental[1]=m_test;
//        state_vector[index.row()]->powerset.harmoVal[1][0]=(float)100;
//        state_vector[index.row()]->powerset.fundamental[3]=m_test;
//        state_vector[index.row()]->powerset.harmoVal[3][0]=(float)100;
//        state_vector[index.row()]->powerset.fundamental[5]=m_test;
//        state_vector[index.row()]->powerset.harmoVal[5][0]=(float)100;
//        qDebug()<<".....";
        break;
    case 1:
        if(ua>360)
            ua=360;
        if(ua<-360)
            ua=-360;
        if(ub>360)
            ub=360;
        if(ub<-360)
            ub=-360;
        if(uc>360)
            uc=360;
        if(uc<-360)
            uc=-360;
        if(ud>360)
            ud=360;
        if(ud<-360)
            ud=-360;
        state_vector[index.row()]->powerset.harmoPhase[0][0]=ua;
        state_vector[index.row()]->powerset.harmoPhase[2][0]=ub;
        state_vector[index.row()]->powerset.harmoPhase[4][0]=uc;
        state_vector[index.row()]->powerset.harmoPhase[6][0]=ud;
        break;
    case 2:
        if(ua>65)
            ua=65;
        if(ua<40)
            ua=40;
        if(ub>65)
            ub=65;
        if(ub<40)
            ub=40;
        if(uc>65)
            uc=65;
        if(uc<40)
            uc=40;
        if(ud>65)
            ud=65;
        if(ud<40)
            ud=40;
        state_vector[index.row()]->powerset.Fa=ua;
        state_vector[index.row()]->powerset.Fb=ub;
        state_vector[index.row()]->powerset.Fc=uc;
        state_vector[index.row()]->powerset.Fd=ud;
        break;
    case 3:
        state_vector[index.row()]->timeLastMs=value.toFloat()*1000;
        break;
    case 4:
        if(value.compare("启用")==0)
        {
            state_vector[index.row()]->active=1;
        }else
        {
            state_vector[index.row()]->active=0;
        }
        break;
    case 5:
        if(value.compare("停止输出")==0)
        {
            state_vector[index.row()]->next=0;
        }else if(value.compare("输出下一项")==0)
        {
            state_vector[index.row()]->next=1;
        }else if(value.compare("输出第一项")==0)
        {
            state_vector[index.row()]->next=-1;
        }
        break;
    default:
        break;
    }
    show_out_list();
}

void Statu_list::recv_mesg(QByteArray last,QByteArray now)
{
    if((quint8)last[5]==0x72)
    {
        if((quint8)now[5]==0x72)
        {
            now.remove(0,6);
            now.remove(now.length()-2,2);
            if(all_read==false)
            {
                memcpy(state_vector[read_index],now.data(),sizeof(POWERStatus));
                mesg->close();
                show_out_list();
            }else
            {
                memcpy(state_vector[read_index],now.data(),sizeof(POWERStatus));
                if(++read_index>=state_vector.count())
                {
                    read_index=0;
                    all_read=false;
                    ui->state->setText("读取完毕。");
                    mesg->close();
                    show_out_list();
                }else
                {
                    xl609->read_out_list(read_index,XL803::STATE_LIST);
                }
            }
        }else if((quint8)now[5]==0x80)
        {
            QMessageBox::information(this,"提示","读取失败");
            mesg->close();
        }
    }else if((quint8)last[5]==0x71)
    {
        if((quint8)now[5]==0x10)
        {
            if(all_down.count()>0)
            {
                QByteArray arry;
                arry.resize(sizeof(POWERStatus));
                memset(arry.data(),0,sizeof(POWERStatus));
                memcpy(arry.data(),state_vector.at(all_down.takeFirst()),sizeof(POWERStatus));
                xl609->write_out_list(sizeof(POWERStatus),arry,XL803::STATE_LIST);
            }else
            {
                mesg->close();
            }
        }else if((quint8)now[5]==0x80)
        {
            QMessageBox::information(this,"提示","写入错误!");
            mesg->close();
        }
    }else if((quint8)now[5]==0x73)
    {
        ui->state->setText("波形初始化完毕。");
        mesg->close();
        QMessageBox *box = new QMessageBox(QMessageBox::Information,tr("提示"),tr("写入完成!"),0,this);
        QTimer::singleShot(1500,box,SLOT(close()));
        box->exec();
    }else if((quint8)last[5]==0x74)
    {
        if((quint8)now[5]==0x10)
        {
            QString str;
            if(start_a==1)
            {
                str="ua已启动";
                ui->ua_state->set_value(2);
            }else{
                str="ua已停止";
                ui->ua_state->set_value(0);
            }
            if(start_b==1)
            {
                str+=" ub已启动";
                ui->ub_state->set_value(2);
            }else
            {
                str+=" ub已停止";
                ui->ub_state->set_value(0);
            }
            if(start_c==1)
            {
                str+=" uc已启动";
                ui->uc_state->set_value(2);
            }else
            {
                str+=" uc已停止";
                ui->uc_state->set_value(0);
            }
            if(start_d==1)
            {
                str+=" ud已启动";
                ui->ud_state->set_value(2);
            }else
            {
                str+=" ud已停止";
                ui->ud_state->set_value(0);
            }
            ui->state->setText(str);
        }else if((quint8)now[5]==0x80)
        {
            QMessageBox::information(this,"提示","启动/停止失败！");
        }
    }
}


void Statu_list::on_read_clicked()
{
    all_read=false;
    int index=ui->list_state_now->currentIndex().row();
    if(index<0)
        index=0;
    read_index=index;
    xl609->read_out_list(index,XL803::STATE_LIST);
    ui->state->setText("读取中。。。");
    mesg->setText("正在读取，请勿操作。。。");
    mesg->show();
}

void Statu_list::on_write_clicked()
{
    int index=ui->list_state_now->currentIndex().row();
    if(index<0)
        index=0;
    QByteArray arry;
    arry.resize(sizeof(POWERStatus));
    memset(arry.data(),0,sizeof(POWERStatus));
    memcpy(arry.data(),state_vector.at(index),sizeof(POWERStatus));
    xl609->clear_out_list(XL803::STATE_LIST);
    xl609->write_out_list(sizeof(POWERStatus),arry,XL803::STATE_LIST);
    ui->state->setText("写入中。。。");
    mesg->setText("正在写入，请勿操作。。。");
    mesg->show();
}

void Statu_list::on_start_clicked()
{
    if(xl609->last_contorl!=2)
    {
        QMessageBox::information(this,"提示","波形数据已更改，请重新初始化波形！");
        qDebug()<<"上一次操作不是状态序列";
        return;
    }
    qDebug()<<timer->isActive();
    if(reset_wave)
    {
        QString str="波形提前终止,\n请重新初始化波形!";
        if(timer->isActive()||flag_no_stop)
            str="波形已启动!";
        QMessageBox *box = new QMessageBox(QMessageBox::Information,tr("提示"),str,0,this);
        QTimer::singleShot(1500,box,SLOT(close()));
        box->exec();
        return;
    }else {
        QList<int> m_down;
        for(int i=0;i<state_vector.count();i++)
        {
            m_down.append(i);
            if(state_vector.at(i)->next!=1)
                break;
        }
        if(m_down.count()>0)
        {
            flag_no_stop=false;
            float start_time=0;
            for(int i=0;i<m_down.count();i++)
            {
                if(state_vector.at(i)->active)
                {
                    start_time+=state_vector.at(i)->timeLastMs;
                    if(state_vector.at(i)->next==-1||state_vector.at(i)->timeLastMs<=0)
                        flag_no_stop=true;
                }
            }
           if(!flag_no_stop)
                timer->start(start_time);
           qDebug()<<start_time;
        }else
        {
            QMessageBox *box = new QMessageBox(QMessageBox::Information,tr("提示"),tr("无输出序列!"),0,this);
            QTimer::singleShot(1500,box,SLOT(close()));
            box->exec();
            return;
        }
        reset_wave=true;
    }
    QByteArray arry;
    if(ui->now_start->isChecked())
    {
        arry.append(0x55);
    }else
    {
        arry.append(0xAA);
    }
    arry.append((char)0x00);
    if(ui->ua->isChecked())
    {
        arry.append(0x55);
        start_a=1;
    }else
    {
        if(ui->ua_state->get_value()==2)
        {
            arry.append(0x55);
            start_a=1;
        }else
        {
            arry.append(0xAA);
            start_a=0;
        }
    }
    arry.append(0xAA);
   // arry.append(0x55);
    if(ui->ub->isChecked())
    {
        arry.append(0x55);
        start_b=1;
    }else
    {
        if(ui->ub_state->get_value()==2)
        {
            arry.append(0x55);
            start_b=1;
        }else
        {
            arry.append(0xAA);
            start_b=0;
        }
    }
    arry.append(0xAA);
    //arry.append(0x55);
    if(ui->uc->isChecked())
    {
        arry.append(0x55);
        start_c=1;
    }else
    {
        if(ui->uc_state->get_value()==2)
        {
            arry.append(0x55);
            start_c=1;
        }else
        {
            arry.append(0xAA);
            start_c=0;
        }
    }
    arry.append(0xAA);
    //arry.append(0x55);
//    arry.append(0xAA);
    if(ui->ud->isChecked())
    {
        arry.append(0x55);
        start_d=1;
    }else
    {
        if(ui->ud_state->get_value()==2)
        {
            arry.append(0x55);
            start_d=1;
        }else
        {
            arry.append(0xAA);
            start_d=0;
        }
    }
    arry.append(0xAA);
    xl609->start_stop_out_list(arry,XL803::STATE_LIST);
}

void Statu_list::on_stop_clicked()
{
    timer->stop();
    QByteArray arry;
    flag_no_stop=false;
    if(ui->now_start->isChecked())
    {
        arry.append(0x55);
    }else
    {
        arry.append(0xAA);
    }
    arry.append((char)0x00);
    if(ui->ua->isChecked())
    {
        arry.append(0xAA);
        start_a=0;
    }else
    {
        if(ui->ua_state->get_value()==2)
        {
            arry.append(0x55);
            start_a=1;
        }else
        {
            arry.append(0xAA);
            start_a=0;
        }
    }
    arry.append(0xAA);
    if(ui->ub->isChecked())
    {
        arry.append(0xAA);
        start_b=0;
    }else
    {
        if(ui->ub_state->get_value()==2)
        {
            arry.append(0x55);
            start_b=1;
        }else
        {
            arry.append(0xAA);
            start_b=0;
        }
    }
    arry.append(0xAA);
    if(ui->uc->isChecked())
    {
        arry.append(0xAA);
        start_c=0;
    }else
    {
        if(ui->uc_state->get_value()==2)
        {
            arry.append(0x55);
            start_c=1;
        }else
        {
            arry.append(0xAA);
            start_c=0;
        }
    }
    arry.append(0xAA);
    if(ui->ud->isChecked())
    {
        arry.append(0xAA);
        start_d=0;
    }else
    {
        if(ui->ud_state->get_value()==2)
        {
            arry.append(0x55);
            start_d=1;
        }else
        {
            arry.append(0xAA);
            start_d=0;
        }
    }
    arry.append(0xAA);
//    arry.append(0xAA);
//    arry.append(0xAA);
    xl609->start_stop_out_list(arry,XL803::STATE_LIST);
}

void Statu_list::on_all_start_clicked()
{
    ui->ua->setChecked(true);
    ui->ub->setChecked(true);
    ui->uc->setChecked(true);
    ui->ud->setChecked(true);
    on_start_clicked();
}

void Statu_list::on_all_stop_clicked()
{
    ui->ua->setChecked(true);
    ui->ub->setChecked(true);
    ui->uc->setChecked(true);
    ui->ud->setChecked(true);
    on_stop_clicked();
}

void Statu_list::on_all_write_clicked()
{
    for(int i=0;i<state_vector.count();i++)
    {
        all_down.append(i);
        if(state_vector.at(i)->next!=1)
            break;
    }
    QByteArray arry;
    arry.resize(sizeof(POWERStatus));
    memset(arry.data(),0,sizeof(POWERStatus));
    if(all_down.count()>0)
    {
        qDebug()<<state_vector.at(all_down.first())->timeLastMs;
        memcpy(arry.data(),state_vector.at(all_down.takeFirst()),sizeof(POWERStatus));
        xl609->write_out_list(sizeof(POWERStatus),arry,XL803::STATE_LIST);
        ui->state->setText("写入中。。。");
        mesg->setText("正在写入，请勿操作。。。");
        mesg->show();
    }else
    {
        QMessageBox::information(this,"提示","无输出序列");
    }
}

void Statu_list::on_all_read_clicked()
{
    read_index=0;
    all_read=true;
    xl609->read_out_list(read_index,XL803::STATE_LIST);
    ui->state->setText("读取中。。。");
    mesg->setText("正在读取，请勿操作。。。");
    mesg->show();
}

void Statu_list::on_in_file_clicked()
{
    QString file_name = QFileDialog::getOpenFileName(NULL,"打开序列文件","./","*.txt");
    QFile file(file_name);
    if (!file.open(QIODevice::ReadOnly| QIODevice::Text))
    {
        QMessageBox::information(this," ","打开失败!");
        return;
    }
    for(;file_name.indexOf("/")>=0;)
    {
        file_name.remove(0,file_name.indexOf("/")+1);
    }
    ui->file_name->setText(file_name);
    QDataStream in(&file);
    for(int i=0;i<state_vector.count();i++)
    {
        in.readRawData((char * )(state_vector[i]),sizeof(POWERStatus));
    }
    show_out_list();
    file.close();
}

void Statu_list::on_save_file_clicked()
{
    QString file_name = QFileDialog::getSaveFileName(NULL,"保存序列文件","./","*.txt");
    QFile file(file_name);
    if (!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::information(this," ","保存失败!");
        return;
    }
    QDataStream out(&file);
    for(int i=0;i<state_vector.count();i++)
    {
        out.writeRawData((char *)state_vector.at(i),sizeof(POWERStatus));
    }
    file.close();
}

void Statu_list::on_priview_clicked()
{
    QList<int> index;
    for(int i=0;i<state_vector.count();i++)
    {
        if(state_vector.at(i)->active>0)
        {
            index.append(i);
            if(state_vector.at(i)->next!=1)
                break;
        }
    }
    QSharedPointer<QCPAxisTickerFixed> ticker(new QCPAxisTickerFixed);
    float time,all_time;
    float value=0;
    float ua_max,ub_max,uc_max,ud_max,max;
    float ua_ph,ub_ph,uc_ph,ud_ph;
    float fa,fb,fc,fd;
    float step=0;
    QVector<double> a_x,b_x,c_x,d_x,a_y,b_y,c_y,d_y;
    time=all_time=value=max=ua_max=ub_max=uc_max=ud_max=ua_ph=ub_ph=uc_ph=ud_ph=fa=fb=fc=fd=0;
    if(index.count()>0)
    {
        for(int i=0;i<index.count();i++)
        {
            int flag=0;
            time=state_vector.at(index.at(i))->timeLastMs/1000;
            if(time==0)
            {
                fa=state_vector.at(index.at(i))->powerset.Fa;
                fb=state_vector.at(index.at(i))->powerset.Fb;
                fc=state_vector.at(index.at(i))->powerset.Fc;
                fd=state_vector.at(index.at(i))->powerset.Fd;
                float min_f=fa;
                min_f<fb?min_f:min_f=fb;
                min_f<fc?min_f:min_f=fc;
                time=QString::number(1/min_f,'g',4).toFloat();
                flag=1;
            }
            all_time+=time;
            if(flag)
                break;
        }
        step=(float)all_time/2000;
        ticker->setTickStep(QString::number(all_time/10,'g',4).toFloat());
        ui->show->xAxis->setTicker(ticker);
        ui->show->xAxis->setRange(0,QString::number(all_time*1.01,'g',4).toFloat());
        float x=0;
        for(int i=0;i<index.count();i++)
        {
            int flag=0;
            time=state_vector.at(index.at(i))->timeLastMs/1000;
            ua_max=state_vector.at(index.at(i))->powerset.fundamental[0]/100*\
                    state_vector.at(index.at(i))->powerset.harmoVal[0][0];
            ub_max=state_vector.at(index.at(i))->powerset.fundamental[2]/100*\
                    state_vector.at(index.at(i))->powerset.harmoVal[2][0];
            uc_max=state_vector.at(index.at(i))->powerset.fundamental[4]/100*\
                    state_vector.at(index.at(i))->powerset.harmoVal[4][0];
            ud_max=state_vector.at(index.at(i))->powerset.fundamental[6]/100*\
                    state_vector.at(index.at(i))->powerset.harmoVal[6][0];
            ua_ph=state_vector.at(index.at(i))->powerset.harmoPhase[0][0]/180*M_PI;
            ub_ph=state_vector.at(index.at(i))->powerset.harmoPhase[2][0]/180*M_PI;
            uc_ph=state_vector.at(index.at(i))->powerset.harmoPhase[4][0]/180*M_PI;
            ud_ph=state_vector.at(index.at(i))->powerset.harmoPhase[6][0]/180*M_PI;
            fa=state_vector.at(index.at(i))->powerset.Fa;
            fb=state_vector.at(index.at(i))->powerset.Fb;
            fc=state_vector.at(index.at(i))->powerset.Fc;
            fd=state_vector.at(index.at(i))->powerset.Fd;
            max>ua_max?max:max=ua_max;
            max>ub_max?max:max=ub_max;
            max>uc_max?max:max=uc_max;
            max>ud_max?max:max=ud_max;
            if(time==0)
            {
                float min_f=fa;
                min_f<fb?min_f:min_f=fb;
                min_f<fc?min_f:min_f=fc;
                time=QString::number(1/min_f,'f',4).toFloat();
                flag=1;
            }
            for(float ti=0;ti<time;ti+=step,x+=step)
            {
                value=ua_max*sqrt(2)*sin(2*M_PI*fa*ti+ua_ph);
                a_y<<value;
                value=ub_max*sqrt(2)*sin(2*M_PI*fb*ti+ub_ph);
                b_y<<value;
                value=uc_max*sqrt(2)*sin(2*M_PI*fc*ti+uc_ph);
                c_y<<value;
                value=ud_max*sqrt(2)*sin(2*M_PI*fd*ti+ud_ph);
                d_y<<value;
                a_x<<x;
                b_x<<x;
                c_x<<x;
                d_x<<x;
            }
            if(flag)
                break;
        }
        l_ua->setData(a_x,a_y);
        l_ub->setData(b_x,b_y);
        l_uc->setData(c_x,c_y);
        l_ud->setData(d_x,d_y);
        ui->show->yAxis->setRange(-max*1.42,max*1.42);
        ui->show->replot();
    }else
    {
        QMessageBox::information(this,"提示","无输出序列!");
    }
}

void Statu_list::on_list_state_now_clicked(const QModelIndex &index)
{
    ui->list_state_now->edit(index);
}

void Statu_list::on_mid_clicked()
{
    if(ui->mid_start->value()>=ui->mid_end->value())
    {
        QMessageBox::information(this,"提示","起始时间大于或等于结束时间。");
        return;
    }
    if(ui->mid_end->value()<=0)
    {
        QMessageBox::information(this,"提示","结束时间不能小于等于0。");
        return;
    }
    bool inf=false;
    QList<int> index;
    for(int i=0;i<state_vector.count();i++)
    {
        if(state_vector.at(i)->active>0)
        {
            index.append(i);
            if(state_vector.at(i)->next!=1)
                break;
        }
    }
    QSharedPointer<QCPAxisTickerFixed> ticker(new QCPAxisTickerFixed);
    float time,all_time;
    float value=0;
    float ua_max,ub_max,uc_max,ud_max,max;
    float ua_ph,ub_ph,uc_ph,ud_ph;
    float fa,fb,fc,fd;
    double step=0;
    QVector<double> a_x,b_x,c_x,d_x,a_y,b_y,c_y,d_y;
    time=all_time=value=max=ua_max=ub_max=uc_max=ud_max=ua_ph=ub_ph=uc_ph=ud_ph=fa=fb=fc=fd=0;
    if(index.count()>0)
    {
        for(int i=0;i<index.count();i++)
        {
            int flag=0;
            time=state_vector.at(index.at(i))->timeLastMs/1000;
            all_time+=time;
            if(time==0)
            {
                flag=1;
                inf=true;
            }
            if(flag)
                break;
        }
        double x=0;
        if((ui->mid_end->value()>all_time)&&inf==false)
        {
            QMessageBox::information(this,"提示","超出时间!");
            return;
        }
        all_time=ui->mid_end->value();
        step=(all_time-(float)ui->mid_start->value())/2000;
        float f=all_time-(float)ui->mid_start->value();
        if(f<=0)
            f=0.02;
        ticker->setTickStep(QString::number(f/10,'g',4).toFloat());
        ui->show->xAxis->setTicker(ticker);
  //      qDebug()<<all_time;
        ui->show->xAxis->setRange(ui->mid_start->value(),QString::number\
        ((ui->mid_end->value()+(ui->mid_end->value()-(float)ui->mid_start->value())/100),'f',4).toFloat());
        float u_start_time=ui->mid_start->value();
        for(int i=0;i<index.count();i++)
        {
            int flag=0;
            time=state_vector.at(index.at(i))->timeLastMs/1000;
            ua_max=state_vector.at(index.at(i))->powerset.fundamental[0]/100*\
                    state_vector.at(index.at(i))->powerset.harmoVal[0][0];
            ub_max=state_vector.at(index.at(i))->powerset.fundamental[2]/100*\
                    state_vector.at(index.at(i))->powerset.harmoVal[2][0];
            uc_max=state_vector.at(index.at(i))->powerset.fundamental[4]/100*\
                    state_vector.at(index.at(i))->powerset.harmoVal[4][0];
            ud_max=state_vector.at(index.at(i))->powerset.fundamental[6]/100*\
                    state_vector.at(index.at(i))->powerset.harmoVal[6][0];
            ua_ph=state_vector.at(index.at(i))->powerset.harmoPhase[0][0]/180*M_PI;
            ub_ph=state_vector.at(index.at(i))->powerset.harmoPhase[2][0]/180*M_PI;
            uc_ph=state_vector.at(index.at(i))->powerset.harmoPhase[4][0]/180*M_PI;
            ud_ph=state_vector.at(index.at(i))->powerset.harmoPhase[6][0]/180*M_PI;
            fa=state_vector.at(index.at(i))->powerset.Fa;
            fb=state_vector.at(index.at(i))->powerset.Fb;
            fc=state_vector.at(index.at(i))->powerset.Fc;
            fd=state_vector.at(index.at(i))->powerset.Fd;
            max>ua_max?max:max=ua_max;
            max>ub_max?max:max=ub_max;
            max>uc_max?max:max=uc_max;
            max>ud_max?max:max=ud_max;
            if(index.last()==i)
            {
                time=ui->mid_end->value()-x;
                flag=1;
            }
            double ti=0;
            if(time<u_start_time&&u_start_time>=0)
            {
                if(x<ui->mid_start->value())
                {
                    x+=time;
                    u_start_time-=time;
                    continue;
                }
            }
            if(u_start_time>=0)
            {
                ti=u_start_time;
                x+=u_start_time;
                u_start_time=-1;
            }
            for(;ti<time;ti+=step,x+=step)
            {
                value=ua_max*sin(2*M_PI*fa*ti+ua_ph);
                a_y<<value;
                value=ub_max*sin(2*M_PI*fb*ti+ub_ph);
                b_y<<value;
                value=uc_max*sin(2*M_PI*fc*ti+uc_ph);
                c_y<<value;
                value=ud_max*sin(2*M_PI*fc*ti+ud_ph);
                d_y<<value;
                a_x<<x;
                b_x<<x;
                c_x<<x;
                d_x<<x;
                //qDebug()<<ti<<x;
            }
            if(flag)
                break;
        }
        l_ua->setData(a_x,a_y);
        l_ub->setData(b_x,b_y);
        l_uc->setData(c_x,c_y);
        l_ud->setData(d_x,d_y);
        ui->show->yAxis->setRange(-max*1.01,max*1.01);
        ui->show->replot();
    }else
    {
        QMessageBox::information(this,"提示","无输出序列!");
    }
}

void Statu_list::on_init_wave_clicked()
{
    xl609->last_contorl=2;
    reset_wave=false;
    xl609->write_end_list(XL803::STATE_LIST);
    ui->state->setText("初始化输出的状态波形。");
    mesg->setText("初始化波形中");
    mesg->show();
}
