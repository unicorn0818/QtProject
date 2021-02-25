#include "m_base_out.h"
#include "ui_m_base_out.h"


BaseDelegate::BaseDelegate(QObject * parent):QItemDelegate(parent)
{
}
QWidget * BaseDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index)const
{
    //M_spinbox *box;
    QComboBox * box;
    QDoubleSpinBox * d_box;
    //QVector<QString> type;
    QStringList type;
    switch(index.row())
    {
//        case 0:
//            box=new M_spinbox(parent);
//            type<<"正弦波"<<"方波"<<"三角波"<<"直流"<<"梯形波";
//            box->set_items(type);
//            return box;
        case 0:
            box=new QComboBox(parent);
            type<<"正弦波"<<"方波"<<"三角波"<<"直流"<<"暂态波形"<<"梯形波";
            box->addItems(type);
            return box;
        case 1:
            d_box=new QDoubleSpinBox(parent);
            d_box->setRange(-9999,9999);
            return d_box;
        case 2:
            d_box=new QDoubleSpinBox(parent);
            d_box->setRange(-360,360);
            d_box->setDecimals(4);
            return d_box;
        case 3:
            d_box=new QDoubleSpinBox(parent);
            d_box->setRange(-9999,9999);
            return d_box;
        case 4:
            d_box=new QDoubleSpinBox(parent);
            d_box->setRange(0,999);
            return d_box;
        default:
            d_box=new QDoubleSpinBox(parent);
            return d_box;
    }
}
void BaseDelegate::setEditorData(QWidget *editor, const QModelIndex &index)const
{
    //M_spinbox *box;
    QComboBox * box;
    QDoubleSpinBox * d_box;
    double value;
    QString str;
    switch(index.row())
    {
    case 0:
        str = index.model()->data(index, Qt::EditRole).toString();
        //box = static_cast<M_spinbox*>(editor);
        box= static_cast<QComboBox*>(editor);
        box->setCurrentText(str);
        return;

    default:
        value = index.model()->data(index, Qt::EditRole).toDouble();
        d_box = static_cast<QDoubleSpinBox*>(editor);
        d_box->setValue(value);
    }
}
void BaseDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    //M_spinbox *box;
    QComboBox * box;
    QDoubleSpinBox * d_box;
    switch(index.row())
    {
    case 0:
        //box = static_cast<M_spinbox*>(editor);
        box=static_cast<QComboBox*>(editor);
        model->setData(index, box->currentText(), Qt::EditRole);
        //box->showPopup();
        emit editd(index,box->currentIndex());
        break;
    default:
        d_box=static_cast<QDoubleSpinBox *> (editor);
        model->setData(index, d_box->value(), Qt::EditRole);
        emit editd(index,d_box->value());
        break;
    }
}
void BaseDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index)const
{
    editor->setGeometry(option.rect);
}
BaseDelegate::~BaseDelegate()
{

}

m_base_out::m_base_out(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::m_base_out)
{
    ui->setupUi(this);
    xl609->set_map(ui->U_map);
    xl609->set_map(ui->I_map);
    ui->U_map->xAxis->setLabel("U");
    ui->I_map->xAxis->setLabel("I");
    ui->wave_type->setRange(0,3);
    ui->tabWidget->tabBar()->hide();
    ui->line->setStyleSheet("border:2px solid rgb(255,215,0);");
    ui->line_2->setStyleSheet("border:2px solid rgb(0,255,0);");
    ui->line_3->setStyleSheet("border:2px solid rgb(255,0,0);");
    ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    QVector<QString> list;
    list<<"正弦波"<<"方波"<<"三角波"<<"直流"<<"暂态波形"<<"梯形波";
    ui->wave_type->set_items(list);
    ua=new out_value;
    memset(ua,0,sizeof(out_value));
    ub=new out_value;
    memset(ub,0,sizeof(out_value));
    uc=new out_value;
    memset(uc,0,sizeof(out_value));
    ia=new out_value;
    memset(ia,0,sizeof(out_value));
    ib=new out_value;
    memset(ib,0,sizeof(out_value));
    ic=new out_value;
    memset(ic,0,sizeof(out_value));
    ui->ua_value->setChecked(true);
    ui->ua_start->setChecked(true);
    xl609=L_XL803;
    group=new QButtonGroup();
    group->addButton(ui->all_value,0);
    group->addButton(ui->ua_value,1);
    group->addButton(ui->ub_value,2);
    group->addButton(ui->uc_value,3);
    group->addButton(ui->ia_value,4);
    group->addButton(ui->ib_value,5);
    group->addButton(ui->ic_value,6);
    connect(group,SIGNAL(buttonClicked(int)),this,SLOT(show_value(int )));
    connect(L_XL803,SIGNAL(send_to_base_out(QByteArray,QByteArray)),this,SLOT(recv_mesg(QByteArray,QByteArray)));
    ui->tableView->setSpan(4,0,1,2);
    ui->tableView->setSpan(4,2,1,2);
    ui->tableView->setSpan(4,4,1,2);
    model=new QStandardItemModel(this);
    QStringList label;
    label<<"UA"<<"IA"<<"UB"<<"IB"<<"UC"<<"IC";
    model->setHorizontalHeaderLabels(label);
    label.clear();
    label<<"波形"<<"有效值"<<"相位"<<"直流偏移(%)"<<"频率";
    model->setVerticalHeaderLabels(label);
    QString str;
    QStandardItem * item;
    for(int colum=0;colum<model->columnCount();colum++)
    {
        for(int row=0;row<model->rowCount();row++)
        {
            str="0";
            if(row==0)
                str="正弦波";
            item=new QStandardItem(str);
            model->setItem(row,colum,item);
        }
    }
    BaseDelegate* dele= new BaseDelegate(this);
    ui->tableView->setItemDelegate(dele);
    ui->tableView->setModel(model);

    connect(dele,SIGNAL(editd(QModelIndex ,double )),this,SLOT(update_value(QModelIndex ,double )));
    group_value<<ua<<ia<<ub<<ib<<uc<<ic;
    l_ua=ui->U_map->addGraph();
    l_ia=ui->I_map->addGraph();
    l_ub=ui->U_map->addGraph();
    l_ib=ui->I_map->addGraph();
    l_uc=ui->U_map->addGraph();
    l_ic=ui->I_map->addGraph();
    l_ua->setPen(QPen(Qt::yellow,1));
    l_ia->setPen(QPen(Qt::yellow,1));
    l_ub->setPen(QPen(Qt::green,1));
    l_ib->setPen(QPen(Qt::green,1));
    l_uc->setPen(QPen(Qt::red,1));
    l_ic->setPen(QPen(Qt::red,1));
    ui->U_map->yAxis->setRange(-20,20);
    ui->I_map->yAxis->setRange(-2,2);
    init_value();
}

m_base_out::~m_base_out()
{
    delete ui;
}
void m_base_out::recv_mesg(QByteArray send, QByteArray read)
{
    if((quint8)send[5]==0x03||(quint8)send[5]==0x04)
    {
        if((quint8)read[5]==0x10)
        {
            ui->U_map->replot();
            ui->I_map->replot();
        }
    }
}
void m_base_out::show_value(int id)
{
    switch (id) {
    case 0:
        //ui->ua_value->setChecked(true);
        break;
    case 1:
        ui->value->setValue(ua->value);
        ui->phase->setValue(ua->phase);
        ui->ratio->setValue(ua->ratio);
        ui->wave_type->setValue(ua->wave_type);
        break;
    case 2:
        ui->value->setValue(ub->value);
        ui->phase->setValue(ub->phase);
        ui->ratio->setValue(ub->ratio);
        ui->wave_type->setValue(ub->wave_type);
        break;
    case 3:
        ui->value->setValue(uc->value);
        ui->phase->setValue(uc->phase);
        ui->ratio->setValue(uc->ratio);
        ui->wave_type->setValue(uc->wave_type);
        break;
    case 4:
        ui->value->setValue(ia->value);
        ui->phase->setValue(ia->phase);
        ui->ratio->setValue(ia->ratio);
        ui->wave_type->setValue(ia->wave_type);
        break;
    case 5:
        ui->value->setValue(ib->value);
        ui->phase->setValue(ib->phase);
        ui->ratio->setValue(ib->ratio);
        ui->wave_type->setValue(ib->wave_type);
        break;
    case 6:
        ui->value->setValue(ic->value);
        ui->phase->setValue(ic->phase);
        ui->ratio->setValue(ic->ratio);
        ui->wave_type->setValue(ic->wave_type);
        break;
    default:
        break;
    }
}


void m_base_out::on_wave_type_valueChanged(int arg1)
{
    if(ui->all_value->isChecked())
    {
        set_value(arg1,0);
    }else if(ui->ua_value->isChecked())
    {
        ua->wave_type=arg1;
        model->setData(model->index(0,0),QVariant(ui->wave_type->text()));
    }else if(ui->ub_value->isChecked())
    {
        ub->wave_type=arg1;
        model->setData(model->index(0,2),QVariant(ui->wave_type->text()));
    }else if(ui->uc_value->isChecked())
    {
        uc->wave_type=arg1;
        model->setData(model->index(0,5),QVariant(ui->wave_type->text()));
    }else if(ui->ia_value->isChecked())
    {
        ia->wave_type=arg1;
        model->setData(model->index(0,1),QVariant(ui->wave_type->text()));
    }else if(ui->ib_value->isChecked())
    {
        ib->wave_type=arg1;
        model->setData(model->index(0,3),QVariant(ui->wave_type->text()));
    }else if(ui->ic_value->isChecked())
    {
        ic->wave_type=arg1;
        model->setData(model->index(0,6),QVariant(ui->wave_type->text()));
    }
}

void m_base_out::on_value_valueChanged(double arg1)
{
    if(ui->all_value->isChecked())
    {
        set_value(arg1,1);
    }else if(ui->ua_value->isChecked())
    {
        ua->value=arg1;
        model->setData(model->index(1,0),QVariant(arg1));
    }else if(ui->ub_value->isChecked())
    {
        ub->value=arg1;
        model->setData(model->index(1,2),QVariant(arg1));
    }else if(ui->uc_value->isChecked())
    {
        uc->value=arg1;
        model->setData(model->index(1,4),QVariant(arg1));
    }else if(ui->ia_value->isChecked())
    {
        ia->value=arg1;
        model->setData(model->index(1,1),QVariant(arg1));
    }else if(ui->ib_value->isChecked())
    {
        ib->value=arg1;
        model->setData(model->index(1,3),QVariant(arg1));
    }else if(ui->ic_value->isChecked())
    {
        ic->value=arg1;
        model->setData(model->index(1,5),QVariant(arg1));
    }
}

void m_base_out::on_phase_valueChanged(double arg1)
{
    if(ui->all_value->isChecked())
    {
        set_value(arg1,3);
    }else if(ui->ua_value->isChecked())
    {
        ua->phase=arg1;
        model->setData(model->index(2,0),QVariant(arg1));
    }else if(ui->ub_value->isChecked())
    {
        ub->phase=arg1;
        model->setData(model->index(2,2),QVariant(arg1));
    }else if(ui->uc_value->isChecked())
    {
        uc->phase=arg1;
        model->setData(model->index(2,4),QVariant(arg1));
    }else if(ui->ia_value->isChecked())
    {
        ia->phase=arg1;
        model->setData(model->index(2,1),QVariant(arg1));
    }else if(ui->ib_value->isChecked())
    {
        ib->phase=arg1;
        model->setData(model->index(2,3),QVariant(arg1));
    }else if(ui->ic_value->isChecked())
    {
        ic->phase=arg1;
        model->setData(model->index(2,5),QVariant(arg1));
    }
}

void m_base_out::on_ratio_valueChanged(double arg1)
{
    if(ui->all_value->isChecked())
    {
        set_value(arg1,2);
    }else if(ui->ua_value->isChecked())
    {
        ua->ratio=arg1;
        model->setData(model->index(3,0),QVariant(arg1));
    }else if(ui->ub_value->isChecked())
    {
        ub->ratio=arg1;
        model->setData(model->index(3,2),QVariant(arg1));
    }else if(ui->uc_value->isChecked())
    {
        uc->ratio=arg1;
        model->setData(model->index(3,4),QVariant(arg1));
    }else if(ui->ia_value->isChecked())
    {
        ia->ratio=arg1;
        model->setData(model->index(3,1),QVariant(arg1));
    }else if(ui->ib_value->isChecked())
    {
        ib->ratio=arg1;
        model->setData(model->index(3,3),QVariant(arg1));
    }else if(ui->ic_value->isChecked())
    {
        ic->ratio=arg1;
        model->setData(model->index(3,5),QVariant(arg1));
    }
}


void m_base_out::set_value(float value,int type)
{
    switch (type) {
    case 0:
        ua->wave_type=value;
        ub->wave_type=value;
        uc->wave_type=value;
        ia->wave_type=value;
        ib->wave_type=value;
        ic->wave_type=value;
        for(int i=0;i<model->columnCount();i++)
        {
            model->setData(model->index(0,i),QVariant(ui->wave_type->text()));
        }
        break;
    case 1:
        ua->value=value;
        ub->value=value;
        uc->value=value;
        ia->value=value;
        ib->value=value;
        ic->value=value;
        for(int i=0;i<model->columnCount();i++)
        {
            model->setData(model->index(type,i),QVariant(value));
        }
        break;
    case 2:
        ua->ratio=value;
        ub->ratio=value;
        uc->ratio=value;
        ia->ratio=value;
        ib->ratio=value;
        ic->ratio=value;
        for(int i=0;i<model->columnCount();i++)
        {
            model->setData(model->index(3,i),QVariant(value));
        }
        break;
    case 3:
        ua->phase=value;
        ub->phase=value;
        uc->phase=value;
        ia->phase=value;
        ib->phase=value;
        ic->phase=value;
        for(int i=0;i<model->columnCount();i++)
        {
            model->setData(model->index(2,i),QVariant(value));
        }
        break;
    default:
        break;
    }

}

void m_base_out::on_all_start_clicked()
{
    ui->ua_start->setChecked(ui->all_start->isChecked());
    ui->ub_start->setChecked(ui->all_start->isChecked());
    ui->uc_start->setChecked(ui->all_start->isChecked());
    ui->ia_start->setChecked(ui->all_start->isChecked());
    ui->ib_start->setChecked(ui->all_start->isChecked());
    ui->ic_start->setChecked(ui->all_start->isChecked());
}

void m_base_out::on_start_clicked()
{
    QMap<XL803::MARKERB,qint32> data;
    QMap<XL803::MARKERB,qint32> ac;
    if(xl609->last_control)
    {
        //强制波形拟合，该命令用于设置下次启动输出前进行强制波形拟合。
        //动态波形输出和任意波形输出用的是基波的缓存，如果不重新初始化波形就启动基波输出那么输出可能不正确。
        xl609->constraint_set_wave(XL803::BASE_OUT);
        xl609->last_control=0;
    }
    //判断单选框的状态
    if(ui->ua_start->isChecked())
    {
        // 获取与ua相关的数值
        set_ua_out(&data);
        //UA启动
        ac.insert(XL803::MARKERB_SUA,0x01);
        set_line_data(l_ua,0,true);
    }
    /*
    if(ui->ia_start->isChecked())
    {
        set_ia_out(&data);
        ac.insert(XL803::MARKERB_SIA,0x01);
        set_line_data(l_ia,1,false);
    }
    if(ui->ub_start->isChecked())
    {
        set_ub_out(&data);
        ac.insert(XL803::MARKERB_SUB,0x01);
        set_line_data(l_ub,2,true);
    }
    if(ui->ib_start->isChecked())
    {
        set_ib_out(&data);
        ac.insert(XL803::MARKERB_SIB,0x01);
        set_line_data(l_ib,3,false);
    }
    if(ui->uc_start->isChecked())
    {
        set_uc_out(&data);
        //set_ud_out(&data);
        ac.insert(XL803::MARKERB_SUC,0x01);
        //ac.insert(XL803::MARKERB_SUD,0x01);
        set_line_data(l_uc,4,true);
    }
    if(ui->ic_start->isChecked())
    {
        set_ic_out(&data);
        //set_id_out(&data);
        ac.insert(XL803::MARKERB_SIC,0x01);
        set_line_data(l_ic,5,false);
       // ac.insert(XL803::MARKERB_SID,0x01);
    }
    */
    xl609->COM_HightWrite(data,XL803::BASE_OUT);
    xl609->COM_StartUp(ac,XL803::BASE_OUT);
}

void m_base_out::on_stop_clicked()
{
    QMap<XL803::MARKERB,qint32> ac;
    if(ui->ua_start->isChecked())
    {
        ac.insert(XL803::MARKERB_EUA,0x01);
        l_ua->setVisible(false);
    }
    if(ui->ia_start->isChecked())
    {
        ac.insert(XL803::MARKERB_EIA,0x01);
        l_ia->setVisible(false);
    }
    if(ui->ub_start->isChecked())
    {
        ac.insert(XL803::MARKERB_EUB,0x01);
        l_ub->setVisible(false);
    }
    if(ui->ib_start->isChecked())
    {
        ac.insert(XL803::MARKERB_EIB,0x01);
        l_ib->setVisible(false);
    }
    if(ui->uc_start->isChecked())
    {
        ac.insert(XL803::MARKERB_EUC,0x01);
        ac.insert(XL803::MARKERB_EUD,0x01);
        l_uc->setVisible(false);
    }
    if(ui->ic_start->isChecked())
    {
        ac.insert(XL803::MARKERB_EIC,0x01);
        ac.insert(XL803::MARKERB_EID,0x01);
        l_ic->setVisible(false);
    }
    xl609->COM_Stop(ac,XL803::BASE_OUT);
}

void m_base_out::on_ua_start_clicked()
{
    if(ui->u_i_all_start->isChecked())
    {
        ui->ia_start->setChecked(ui->ua_start->isChecked());
    }
}

void m_base_out::on_ia_start_clicked()
{
    if(ui->u_i_all_start->isChecked())
    {
        ui->ua_start->setChecked(ui->ia_start->isChecked());
    }
}

void m_base_out::on_ub_start_clicked()
{
    if(ui->u_i_all_start->isChecked())
    {
        ui->ib_start->setChecked(ui->ub_start->isChecked());
    }
}

void m_base_out::on_uc_start_clicked()
{
    if(ui->u_i_all_start->isChecked())
    {
        ui->ic_start->setChecked(ui->uc_start->isChecked());
    }
}

void m_base_out::on_ib_start_clicked()
{
    if(ui->u_i_all_start->isChecked())
    {
        ui->ub_start->setChecked(ui->ib_start->isChecked());
    }
}

void m_base_out::on_ic_start_clicked()
{
    if(ui->u_i_all_start->isChecked())
    {
        ui->uc_start->setChecked(ui->ic_start->isChecked());
    }
}

void m_base_out::on_u_i_all_start_clicked()
{
    if(ui->ua_start->isChecked())
    {
        on_ua_start_clicked();
    }else
    {
        on_ia_start_clicked();
    }
    if(ui->ub_start->isChecked())
    {
        on_ub_start_clicked();
    }else
    {
        on_ib_start_clicked();
    }
    if(ui->uc_start->isChecked())
    {
        on_uc_start_clicked();
    }else
    {
        on_ic_start_clicked();
    }
}
void m_base_out::set_ia_out(QMap<XL803::MARKERB, qint32> *data)
{
    data->insert(XL803::MARKERB_IA,xl609->float_to_quint(ia->value));
    data->insert(XL803::MARKERB_IAP,xl609->float_to_quint(ia->phase));
    data->insert(XL803::MARKERB_FA,xl609->float_to_quint(ui->a_b_freq->value()));
    data->insert(XL803::MARKERB_DIA,0x55);
    data->insert(XL803::MARKERB_WT_IA,ia->wave_type);
    data->insert(XL803::DCBias2,xl609->float_to_quint(ia->ratio));
}
void m_base_out::set_ua_out(QMap<XL803::MARKERB, qint32> *data)
{
    data->insert(XL803::MARKERB_UA,xl609->float_to_quint(ua->value));
    data->insert(XL803::MARKERB_UAP,xl609->float_to_quint(ua->phase));
    data->insert(XL803::MARKERB_FA,xl609->float_to_quint(ui->a_b_freq->value()));
    data->insert(XL803::MARKERB_DUA,0x55);
    data->insert(XL803::MARKERB_WT_UA,ua->wave_type);
    data->insert(XL803::DCBias1,xl609->float_to_quint(ua->ratio));
}
void m_base_out::set_ib_out(QMap<XL803::MARKERB, qint32> *data)
{
    data->insert(XL803::MARKERB_IB,xl609->float_to_quint(ib->value));
    data->insert(XL803::MARKERB_IBP,xl609->float_to_quint(ib->phase));
    data->insert(XL803::MARKERB_FB,xl609->float_to_quint(ui->c_freq_2->value()));
    data->insert(XL803::MARKERB_DIB,0x55);
    data->insert(XL803::MARKERB_WT_IB,ib->wave_type);
    data->insert(XL803::DCBias4,xl609->float_to_quint(ib->ratio));
}
void m_base_out::set_ub_out(QMap<XL803::MARKERB, qint32> *data)
{
    data->insert(XL803::MARKERB_UB,xl609->float_to_quint(ub->value));
    data->insert(XL803::MARKERB_UBP,xl609->float_to_quint(ub->phase));
    data->insert(XL803::MARKERB_FB,xl609->float_to_quint(ui->c_freq_2->value()));
    data->insert(XL803::MARKERB_DUB,0x55);
    data->insert(XL803::MARKERB_WT_UB,ub->wave_type);
    data->insert(XL803::DCBias3,xl609->float_to_quint(ub->ratio));
}
void m_base_out::set_ic_out(QMap<XL803::MARKERB, qint32> *data)
{
    data->insert(XL803::MARKERB_IC,xl609->float_to_quint(ic->value));
    data->insert(XL803::MARKERB_ICP,xl609->float_to_quint(ic->phase));
    data->insert(XL803::MARKERB_FC,xl609->float_to_quint(ui->c_freq->value()));
    data->insert(XL803::MARKERB_DIC,0x55);
    data->insert(XL803::MARKERB_WT_IC,ic->wave_type);
    data->insert(XL803::DCBias6,xl609->float_to_quint(ic->ratio));
}
void m_base_out::set_uc_out(QMap<XL803::MARKERB, qint32> *data)
{
    data->insert(XL803::MARKERB_UC,xl609->float_to_quint(uc->value));
    data->insert(XL803::MARKERB_UCP,xl609->float_to_quint(uc->phase));
    data->insert(XL803::MARKERB_FC,xl609->float_to_quint(ui->c_freq->value()));
    data->insert(XL803::MARKERB_DUC,0x55);
    data->insert(XL803::MARKERB_WT_UC,uc->wave_type);
    data->insert(XL803::DCBias5,xl609->float_to_quint(uc->ratio));
}
void m_base_out::set_ud_out(QMap<XL803::MARKERB, qint32> *data)
{
    data->insert(XL803::MARKERB_UD,xl609->float_to_quint(uc->value));
    data->insert(XL803::MARKERB_UDP,xl609->float_to_quint(uc->phase));
    data->insert(XL803::MARKERB_FD,xl609->float_to_quint(ui->c_freq->value()));
    data->insert(XL803::MARKERB_DUD,0x55);
    data->insert(XL803::MARKERB_WT_UD,uc->wave_type);
    data->insert(XL803::DCBias7,xl609->float_to_quint(uc->ratio));
}
void m_base_out::set_id_out(QMap<XL803::MARKERB, qint32> *data)
{
    data->insert(XL803::MARKERB_ID,xl609->float_to_quint(uc->value));
    data->insert(XL803::MARKERB_IDP,xl609->float_to_quint(uc->phase));
    data->insert(XL803::MARKERB_FD,xl609->float_to_quint(ui->c_freq->value()));
    data->insert(XL803::MARKERB_DID,0x55);
    data->insert(XL803::MARKERB_WT_ID,uc->wave_type);
    data->insert(XL803::DCBias8,xl609->float_to_quint(uc->ratio));
}
void m_base_out::update_value(QModelIndex index,double value)
{
    int row=index.row();
    int colum=index.column();
    if(row==0)
    {
        group_value.at(colum)->wave_type=value;
    }else if(row==1)
    {
        group_value.at(colum)->value=value;
    }else if(row==2)
    {
        group_value.at(colum)->phase=value;
    }else if(row==3)
    {
        group_value.at(colum)->ratio=value;
    }else if(row==4)
    {
        if(colum==0)
        {
            ui->a_b_freq->setValue(value);
        }else if(colum==2)
        {
            ui->c_freq_2->setValue(value);
        }else if(colum==4)
        {
            ui->c_freq->setValue(value);
        }
    }
}


void m_base_out::on_tableView_clicked(const QModelIndex &index)
{
    ui->tableView->edit(index);
}

void m_base_out::set_line_data(QCPGraph * line,int type,bool u_flag)
{
    QVector<double> x,y;
    double freq;
    double max;
    double ratio;
    int w_type;
    double phase;
    double step;
    int rand_freq=200;
    QSharedPointer<QCPAxisTickerFixed> ticker(new QCPAxisTickerFixed);
    switch (type) {
    case 0:
        max=ua->value;
        ratio=ua->ratio;
        w_type=ua->wave_type;
        freq=ui->a_b_freq->value();
        phase=ua->phase;
        break;
    case 1:
        max=ia->value;
        ratio=ia->ratio;
        w_type=ia->wave_type;
        phase=ia->phase;
        freq=ui->a_b_freq->value();
        break;
    case 2:
        max=ub->value;
        ratio=ub->ratio;
        w_type=ub->wave_type;
        phase=ub->phase;
        freq=ui->c_freq_2->value();
        break;
    case 3:
        max=ib->value;
        ratio=ib->ratio;
        w_type=ib->wave_type;
        phase=ib->phase;
        freq=ui->c_freq_2->value();
        break;
    case 4:
        max=uc->value;
        ratio=uc->ratio;
        w_type=uc->wave_type;
        phase=uc->phase;
        freq=ui->c_freq->value();
        break;
    case 5:
        max=ic->value;
        ratio=ic->ratio;
        w_type=ic->wave_type;
        phase=ic->phase;
        freq=ui->c_freq->value();
        break;
    default:
        break;
    }
    ticker->setTickStep((double)1/freq/10);
    step=(double)1/freq/rand_freq;
    if(u_flag)
    {
        ui->U_map->xAxis->setTicker(ticker);
        ui->U_map->xAxis->setRange(0,(double)1/freq);
        if(ui->U_map->yAxis->range().upper<((max*sqrt(3))+ratio))
            ui->U_map->yAxis->setRange(0-((max*sqrt(3))+ratio)*1.1,((max*sqrt(3))+ratio)*1.1);
    }else
    {
        ui->I_map->xAxis->setTicker(ticker);
        ui->I_map->xAxis->setRange(0,(double)1/freq);
        if(ui->I_map->yAxis->range().upper<((max*sqrt(3))+ratio))
            ui->I_map->yAxis->setRange(0-((max*sqrt(3))+ratio)*1.1,((max*sqrt(3))+ratio)*1.1);
    }
    double time;
    double k=0;
    double b=0;
    int j=0;
    switch (w_type) {
    case 0://正弦波波形
        j=0;
        for(double i=0;j<rand_freq;j++,i+=step)
        {
            x<<i;
            y<<(max*sqrt(2))*qSin(2*M_PI*freq*(i+phase/360*(1/freq)))+ratio/100*max;
        }
        break;
    case 1://方波波形
        j=0;
        for(double i=0;j<rand_freq;j++,i+=step)
        {
            x<<i;
            time=phase/360*(1/freq)+i;
            for(;time>1/freq;time-=(1/freq)){};
            for(;time<0;time+=(1/freq)){};
            if(time<1/freq/2)
            {
                y<<max+(max*(ratio/100));
            }else
            {
                y<<(0-max)+(max*(ratio/100));
            }
        }
        break;
    case 2://三角波波形
        max*=sqrt(3);
        j=0;
        for(double i=0;j<rand_freq;j++,i+=step)
        {
            x<<i;
            time=phase/360*(1/freq)+i;
            for(;time>1/freq;time-=(1/freq)){};
            for(;time<0;time+=(1/freq)){};
            if((time<1/freq/4))
            {
                k=4*freq*max;
                b=0;
            }else if(time<(1/freq/4*3))
            {
                k=0-(4*freq*max);
                b=max*2;
            }else
            {
                k=4*freq*max;
                b=(0-max)*4;
            }
            y<<k*time+b;
        }
        break;
    case 3://直流波形
        x<<0<<1/freq;
        y<<max+(max*(ratio/100))<<max+(max*(ratio/100));
        break;
    default:
        j=0;
        for(double i=0;j<rand_freq;j++,i+=step)
        {
            x<<i;
            y<<(max*sqrt(2))*qSin(2*M_PI*freq*(i+phase/360*(1/freq)))+ratio/100*max;
        }
        break;
    }
    line->setData(x,y);
    line->setVisible(true);
}

void m_base_out::on_a_b_freq_valueChanged(double arg1)
{
    model->setData(model->index(4,0),QVariant(arg1));
}

void m_base_out::on_c_freq_2_valueChanged(double arg1)
{
    model->setData(model->index(4,2),QVariant(arg1));
}

void m_base_out::on_c_freq_valueChanged(double arg1)
{
    model->setData(model->index(4,4),QVariant(arg1));
}

void m_base_out::on_pushButton_2_clicked()
{
    ia->phase=ua->phase-(acos(0.5)*180/M_PI);
    ib->phase=ub->phase-(acos(0.5)*180/M_PI);
    ic->phase=uc->phase-(acos(0.5)*180/M_PI);
    show_model();
    show_value(group->checkedId());
}
void m_base_out::on_pushButton_3_clicked()
{
    ia->phase=ua->phase-(acos(0.8)*180/M_PI);
    ib->phase=ub->phase-(acos(0.8)*180/M_PI);
    ic->phase=uc->phase-(acos(0.8)*180/M_PI);
    show_model();
    show_value(group->checkedId());
}

void m_base_out::on_pushButton_7_clicked()
{
    ia->phase=ua->phase+(acos(0.5)*180/M_PI);
    ib->phase=ub->phase+(acos(0.5)*180/M_PI);
    ic->phase=uc->phase+(acos(0.5)*180/M_PI);
    show_model();
    show_value(group->checkedId());
}

void m_base_out::on_pushButton_6_clicked()
{
    ia->phase=ua->phase+(acos(0.8)*180/M_PI);
    ib->phase=ub->phase+(acos(0.8)*180/M_PI);
    ic->phase=uc->phase+(acos(0.8)*180/M_PI);
    show_model();
    show_value(group->checkedId());
}

void m_base_out::on_pushButton_4_clicked()
{
    ia->phase=ua->phase-(acos(1)*180/M_PI);
    ib->phase=ub->phase-(acos(1)*180/M_PI);
    ic->phase=uc->phase-(acos(1)*180/M_PI);
    show_model();
    show_value(group->checkedId());
}
void m_base_out::show_model()
{
    model->setData(model->index(2,1),QVariant(ia->phase));
    model->setData(model->index(2,3),QVariant(ib->phase));
    model->setData(model->index(2,5),QVariant(ic->phase));
}
void m_base_out::init_value()
{
    for(int i=0;i<model->columnCount();i++)
    {
        if(i%2==0)
            model->setData(model->index(1,i),QVariant(57.7));
        if(i%2)
            model->setData(model->index(1,i),QVariant(1));
    }
    model->setData(model->index(2,0),QVariant(0));
    model->setData(model->index(2,1),QVariant(0));
    model->setData(model->index(2,2),QVariant(240));
    model->setData(model->index(2,3),QVariant(240));
    model->setData(model->index(2,4),QVariant(120));
    model->setData(model->index(2,5),QVariant(120));
    model->setData(model->index(4,0),QVariant(50));
    model->setData(model->index(4,2),QVariant(50));
    model->setData(model->index(4,4),QVariant(50));
    for(int i=0;i<group_value.count();i++)
    {
        if(i%2==0)
        {
            group_value.at(i)->value=57.7;
        }
        if(i%2==1)
        {
            group_value.at(i)->value=1;
        }
        group_value.at(i)->wave_type=0;
        group_value.at(i)->ratio=0;
        if(i<2)
        {
            group_value.at(i)->phase=0;
        }else if(i<4)
        {
            group_value.at(i)->phase=240;
        }else
        {
            group_value.at(i)->phase=120;
        }
    }
}
