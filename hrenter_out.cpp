#include "hrenter_out.h"
#include "ui_hrenter_out.h"
#include <qdebug.h>

Hrenter_out::Hrenter_out(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Hrenter_out)
{
    init=false;
    ui->setupUi(this);
    QVector<QString> list;
    list<<"内部触发输出"<<"外部触发输入"<<"启动立刻输出"<<"过零同步脉冲输出模式"<<"同步跟踪模式"<<"电能累计同步信号输出";
    ui->tig_type->set_items(list);
    list.clear();
    list<<"正弦波"<<"方波"<<"三角波"<<"直流"<<"暂态波形"<<"梯形波";
    ui->write_hrenter_data->hide();
    ui->wave_type->set_items(list);
    ui->tig_type->setValue(2);
    ui->hrenter_data->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    for(int i=0;i<50;i++)
    {
        ui->hrenter_data->insertRow(i);
        for(int j=0;j<3;j++)
        {
            ui->hrenter_data->setItem(i,j,new QTableWidgetItem(("0")));
            if(j==1)
            {
                ui->hrenter_data->item(i,j)->setFlags(Qt::NoItemFlags);
                ui->hrenter_data->item(i,j)->setTextColor(QColor(Qt::black));
            }
        }
        if(i!=0)
        {
            ui->hrenter_data->setVerticalHeaderItem(i,new QTableWidgetItem(QString("%1次").arg(i+1)));
        }else {
            ui->hrenter_data->setVerticalHeaderItem(i,new QTableWidgetItem("基波"));
            ui->hrenter_data->item(0,0)->setText("100");
            ui->hrenter_data->item(0,1)->setText("50");
        }
    }
    xl609->set_map(ui->bar_map);
    xl609->set_map(ui->wave_map);
    bar=new QCPBars(ui->bar_map->xAxis, ui->bar_map->yAxis);
    QSharedPointer<QCPAxisTickerFixed> ticker(new QCPAxisTickerFixed);
    ticker->setTickStep(0.001);
    ticker->setTickCount(100);
    ui->wave_map->xAxis->setTicker(ticker);
    QSharedPointer<QCPAxisTickerFixed> ticker1(new QCPAxisTickerFixed);
    ticker1->setTickStep(5);
    ticker1->setTickCount(129);
    ui->bar_map->xAxis->setTicker(ticker1);
    ui->wave_map->xAxis->setSubTickLength(1);
    line=ui->wave_map->addGraph();
    ui->wave_map->xAxis->setRange(0,0.02);
    ui->bar_map->xAxis->setRange(0,129);
    ui->bar_map->yAxis->setRange(0,100);
    bar->setPen(QPen(QColor(150, 150, 150)));
    bar->setBrush(QBrush(Qt::yellow));
    ui->state3->set_value(2);
    //ui->wave_map->setEnabled(false);
    xl609=L_XL803;
    for(int i=0;i<XL803::SOUR_PHASE_NUM_MAX;i++)
    {
        base * now=new base;
        memset(now,0,sizeof(base));
        base_vector<<now;
    }
    enum_index<<XL803::OCM_UA<<XL803::OCM_IA<<XL803::OCM_UB<<XL803::OCM_IB\
              <<XL803::OCM_UC<<XL803::OCM_IC<<XL803::OCM_UD<<XL803::OCM_ID\
              <<XL803::OCM_UA2<<XL803::OCM_IA2<<XL803::OCM_UB2<<XL803::OCM_IB2\
              <<XL803::OCM_UC2<<XL803::OCM_IC2<<XL803::OCM_UD2<<XL803::OCM_ID2;
    memset(m_hrData,0,sizeof(m_hrData));
    init_value();
    hide_other();
    init=true;
    connect(L_XL803,SIGNAL(send_to_hrenter(QByteArray,QByteArray)),this,SLOT(recv_mesg(QByteArray,QByteArray)));
}
void Hrenter_out::recv_mesg(QByteArray last,QByteArray now)
{
    if((quint8)last[5]==0x03)
    {
        check_flag(2);
    }else if((quint8)last[5]==0x28)
    {
        check_flag(2);
    }else if((quint8)last[5]==0x04)
    {
        check_flag(0);
    }else if((quint8)last[5]==0x29)
    {
        check_flag(0);
    }
}
void Hrenter_out::hide_other()
{
    ui->label_10->hide();
    ui->label_12->hide();
    ui->label_13->hide();
    ui->label_14->hide();
    ui->label_15->hide();
    ui->label_19->hide();
    ui->label_20->hide();
    ui->label_21->hide();
    ui->label_22->hide();
    ui->label_23->hide();
    ui->ud->hide();
    ui->id->hide();
    ui->ua1->hide();
    ui->ia1->hide();
    ui->ub1->hide();
    ui->ib1->hide();
    ui->uc1->hide();
    ui->ic1->hide();
    ui->ud1->hide();
    ui->id1->hide();
    ui->tig_type->hide();
    ui->label_25->hide();
}
Hrenter_out::~Hrenter_out()
{
    delete ui;
}

void Hrenter_out::on_hrenter_data_cellChanged(int row, int column)
{
    if(init !=true)
        return;
    float data=ui->hrenter_data->item(row,column)->text().toFloat();
    int index=ui->pipe_type->currentIndex();
        if(column==0)
        {
            m_hrData[enum_index.at(index)][row].radio=data;
            qDebug()<<"base_vector.at(index)->value"<<base_vector.at(index)->value<<"data"<<data;
            ui->hrenter_data->item(row,1)->setText(QString("%1").arg(base_vector.at(index)->value/100*data));
            //set_rms(enum_index.at(index),base_vector.at(ua));
            set_thd(enum_index.at(index));
        }else if(column==2)
        {
            m_hrData[enum_index.at(index)][row].phase=data;
        }
}

void Hrenter_out::on_pipe_type_currentIndexChanged(int index)
{
    show_hr_data(enum_index.at(index),base_vector.at(index));
    show_base_data(base_vector.at(index));
    //set_rms(enum_index.at(index),base_vector.at(index));
    set_thd(enum_index.at(index));
}
void Hrenter_out::show_hr_data(int type,base * pipe)
{
    for(int i=0;i<ui->hrenter_data->rowCount();i++)
    {
        ui->hrenter_data->item(i,0)->setText(QString("%1").arg(m_hrData[type][i].radio));
        ui->hrenter_data->item(i,1)->setText(QString("%1").arg(m_hrData[type][i].radio/100*pipe->value));
        ui->hrenter_data->item(i,2)->setText(QString("%1").arg(m_hrData[type][i].phase));
    }
}
void Hrenter_out::set_rms(int type, base *pipe)
{
    float data=0;
    float value=0;
    int count=0;
    if(pipe->value!=0)
    {
        for(int i=0;i<ui->hrenter_data->rowCount();i++)
        {
            if((m_hrData[type][i].radio/100*pipe->value)!=0)
            {
                value=m_hrData[type][i].radio/100*pipe->value;
                count++;
                switch (ui->wave_type->value()) {
                case 0://正弦波
                    data+=(value*value);
                    break;
                case 1://方波
                case 2://三角波
                    data=0;
                    break;
                case 3://直流
                    data+=value;
                    break;
                default:
                    data+=(value*value);
                    break;
                }
            }
        }
        switch (ui->wave_type->value()) {
        case 0://正弦波
            data=sqrt(data);
            break;
        case 1://方波
        case 2://三角波
            for(int i=0;i<line->dataCount();i++)
            {
                value= line->data()->at(i)->value;
                data+=(value*value);
            }
            data=sqrt(data/line->dataCount());
            break;
        case 3://直流
            break;
        default:
            data=sqrt(data);
            break;
        }
        ui->rms->setText(QString("%1").arg(data));
    }else
    {
        ui->rms->setText("0");
    }
}
void Hrenter_out::set_thd(int type)
{
    float data=0;
    for(int i=1;i<ui->hrenter_data->rowCount();i++)
    {
        data+=(m_hrData[type][i].radio*m_hrData[type][i].radio);
    }
    ui->thd->setText(QString("%1").arg(sqrt(data)));
}
void Hrenter_out::show_base_data(base *pipe)
{
    ui->wave_type->setValue(pipe->wave_type);
    ui->base_value->setValue(pipe->value);
    ui->ratio->setValue(pipe->ratio);
    ui->freq->setValue(pipe->freq);
    ui->base_phase->setValue(pipe->phase);
}
void Hrenter_out::on_wave_type_valueChanged(int arg1)
{
    int index=ui->pipe_type->currentIndex();
    base_vector.at(index)->wave_type=arg1;
//    set_rms(enum_index.at(index),base_vector.at(index));
}

void Hrenter_out::on_base_value_valueChanged(double arg1)
{
    base_vector.at(ui->pipe_type->currentIndex())->value=arg1;
    for(int i=0;i<ui->hrenter_data->rowCount();i++)
    {
        if(ui->hrenter_data->item(i,0)->text().toFloat()!=0)
        {
            on_hrenter_data_cellChanged(i,0);
        }
    }
}

void Hrenter_out::on_ratio_valueChanged(double arg1)
{
    base_vector.at(ui->pipe_type->currentIndex())->ratio=arg1;
}

void Hrenter_out::on_freq_valueChanged(double arg1)
{
    if(init!=true)
        return;
    QSharedPointer<QCPAxisTickerFixed> ticker(new QCPAxisTickerFixed);
    ticker->setTickStep(1/arg1/10);
    ui->wave_map->xAxis->setTicker(ticker);
    ui->wave_map->xAxis->setRange(0,1/arg1);
    ui->wave_map->replot();
    base_vector.at(ui->pipe_type->currentIndex())->freq=arg1;
}

void Hrenter_out::on_base_start_clicked()
{
    if(xl609->last_control)
    {
        xl609->constraint_set_wave(XL803::BASE_OUT);
        xl609->last_control=0;
    }
    write_base(true);
}
void Hrenter_out::write_base(bool flag)
{
    QMap<XL803::MARKERB, qint32> data;
    QMap<XL803::MARKERB,qint32> ac;
    data.clear();
    if(ui->ua->isChecked())
    {
        start_flag<<"ua";
        set_ua_out(&data);
        ac.insert(XL803::MARKERB_SUA,0x01);
    }
    if(ui->ia->isChecked())
    {
        start_flag<<"ia";
        set_ia_out(&data);
        ac.insert(XL803::MARKERB_SIA,0x01);
    }
    if(ui->ub->isChecked())
    {
        start_flag<<"ub";
        set_ub_out(&data);
        ac.insert(XL803::MARKERB_SUB,0x01);
    }
    if(ui->ib->isChecked())
    {
        start_flag<<"ib";
        set_ib_out(&data);
        ac.insert(XL803::MARKERB_SIB,0x01);
    }
    if(ui->uc->isChecked())
    {
        start_flag<<"uc";
        set_uc_out(&data);
        ac.insert(XL803::MARKERB_SUC,0x01);
    }
    if(ui->ic->isChecked())
    {
        start_flag<<"ic";
        set_ic_out(&data);
        ac.insert(XL803::MARKERB_SIC,0x01);
    }
//    if(ui->ud->isChecked())
//    {
//        set_uc_out(&data);
//        ac.insert(XL803::MARKERB_SUD,0x01);
//    }
//    if(ui->id->isChecked())
//    {
//        set_ic_out(&data);
//        ac.insert(XL803::MARKERB_SID,0x01);
//    }
//    if(ui->ua1->isChecked())
//    {
//        set_ua_out(&data);
//        ac.insert(XL803::MARKERB_SUA1,0x01);
//    }
//    if(ui->ia1->isChecked())
//    {
//        set_ia_out(&data);
//        ac.insert(XL803::MARKERB_SIA1,0x01);
//    }
//    if(ui->ub1->isChecked())
//    {
//        set_ub_out(&data);
//        ac.insert(XL803::MARKERB_SUB1,0x01);
//    }
//    if(ui->ib1->isChecked())
//    {
//        set_ib_out(&data);
//        ac.insert(XL803::MARKERB_SIB1,0x01);
//    }
//    if(ui->uc1->isChecked())
//    {
//        set_uc_out(&data);
//        ac.insert(XL803::MARKERB_SUC1,0x01);
//    }
//    if(ui->ic1->isChecked())
//    {
//        set_ic_out(&data);
//        ac.insert(XL803::MARKERB_SIC1,0x01);
//    }
//    if(ui->ud1->isChecked())
//    {
//        set_uc_out(&data);
//        ac.insert(XL803::MARKERB_SUD1,0x01);
//    }
//    if(ui->id1->isChecked())
//    {
//        set_ic_out(&data);
//        ac.insert(XL803::MARKERB_SID1,0x01);
//    }
    xl609->COM_HightWrite(data,XL803::HRENTER_OUT);
    if(flag==true)
    {
        xl609->COM_StartUp(ac,XL803::HRENTER_OUT);
    }
}
void Hrenter_out::on_base_stop_clicked()
{
    QMap<XL803::MARKERB,qint32> ac;
    if(ui->ua->isChecked())
    {
        start_flag<<"ua";
        ac.insert(XL803::MARKERB_EUA,0x01);
    }
    if(ui->ia->isChecked())
    {
        start_flag<<"ia";
        ac.insert(XL803::MARKERB_EIA,0x01);
    }
    if(ui->ub->isChecked())
    {
        start_flag<<"ub";
        ac.insert(XL803::MARKERB_EUB,0x01);
    }
    if(ui->ib->isChecked())
    {
        start_flag<<"ib";
        ac.insert(XL803::MARKERB_EIB,0x01);
    }
    if(ui->uc->isChecked())
    {
        start_flag<<"uc";
        ac.insert(XL803::MARKERB_EUC,0x01);
    }
    if(ui->ic->isChecked())
    {
        start_flag<<"ic";
        ac.insert(XL803::MARKERB_EIC,0x01);
    }
//    if(ui->ud->isChecked())
//    {
//        ac.insert(XL803::MARKERB_EUD,0x01);
//    }
//    if(ui->id->isChecked())
//    {
//        ac.insert(XL803::MARKERB_EID,0x01);
//    }
//    if(ui->ua1->isChecked())
//    {
//        ac.insert(XL803::MARKERB_EUA1,0x01);
//    }
//    if(ui->ia1->isChecked())
//    {
//        ac.insert(XL803::MARKERB_EIA1,0x01);
//    }
//    if(ui->ub1->isChecked())
//    {
//        ac.insert(XL803::MARKERB_EUB1,0x01);
//    }
//    if(ui->ib1->isChecked())
//    {
//        ac.insert(XL803::MARKERB_EIB1,0x01);
//    }
//    if(ui->uc1->isChecked())
//    {
//        ac.insert(XL803::MARKERB_EUC1,0x01);
//    }
//    if(ui->ic1->isChecked())
//    {
//        ac.insert(XL803::MARKERB_EIC1,0x01);
//    }
//    if(ui->ud1->isChecked())
//    {
//        ac.insert(XL803::MARKERB_EUD1,0x01);
//    }
//    if(ui->id1->isChecked())
//    {
//        ac.insert(XL803::MARKERB_EID1,0x01);
//    }
    xl609->COM_Stop(ac,XL803::HRENTER_OUT);
}
void Hrenter_out::set_ia_out(QMap<XL803::MARKERB, qint32> *data)
{
    data->insert(XL803::MARKERB_IA,xl609->float_to_quint(base_vector.at(ia)->value));
    data->insert(XL803::MARKERB_IAP,xl609->float_to_quint(base_vector.at(ia)->phase));
    data->insert(XL803::MARKERB_FA,xl609->float_to_quint(base_vector.at(ia)->freq));
    data->insert(XL803::MARKERB_DIA,0x55);
    data->insert(XL803::MARKERB_WT_IA,base_vector.at(ia)->wave_type);
    data->insert(XL803::DCBias2,xl609->float_to_quint(base_vector.at(ia)->ratio));

}
void Hrenter_out::set_ua_out(QMap<XL803::MARKERB, qint32> *data)
{
    data->insert(XL803::MARKERB_UA,xl609->float_to_quint(base_vector.at(ua)->value));
    data->insert(XL803::MARKERB_UAP,xl609->float_to_quint(base_vector.at(ua)->phase));
    data->insert(XL803::MARKERB_FA,xl609->float_to_quint(base_vector.at(ua)->freq));
    data->insert(XL803::MARKERB_DUA,0x55);
    data->insert(XL803::MARKERB_WT_UA,base_vector.at(ua)->wave_type);
    data->insert(XL803::DCBias1,xl609->float_to_quint(base_vector.at(ua)->ratio));
}
void Hrenter_out::set_ib_out(QMap<XL803::MARKERB, qint32> *data)
{
    data->insert(XL803::MARKERB_IB,xl609->float_to_quint(base_vector.at(ib)->value));
    data->insert(XL803::MARKERB_IBP,base_vector.at(ib)->phase);
    data->insert(XL803::MARKERB_FB,xl609->float_to_quint(base_vector.at(ib)->freq));
    data->insert(XL803::MARKERB_DIB,0x55);
    data->insert(XL803::MARKERB_WT_IB,base_vector.at(ib)->wave_type);
    data->insert(XL803::DCBias4,xl609->float_to_quint(base_vector.at(ib)->ratio));
}
void Hrenter_out::set_ub_out(QMap<XL803::MARKERB, qint32> *data)
{
    data->insert(XL803::MARKERB_UB,xl609->float_to_quint(base_vector.at(ub)->value));
    data->insert(XL803::MARKERB_UBP,base_vector.at(ub)->phase);
    data->insert(XL803::MARKERB_FB,xl609->float_to_quint(base_vector.at(ub)->freq));
    data->insert(XL803::MARKERB_DUB,0x55);
    data->insert(XL803::MARKERB_WT_UB,base_vector.at(ub)->wave_type);
    data->insert(XL803::DCBias3,xl609->float_to_quint(base_vector.at(ub)->ratio));
}
void Hrenter_out::set_ic_out(QMap<XL803::MARKERB, qint32> *data)
{
    data->insert(XL803::MARKERB_IC,xl609->float_to_quint(base_vector.at(ic)->value));
    data->insert(XL803::MARKERB_ICP,base_vector.at(ic)->phase);
    data->insert(XL803::MARKERB_FC,xl609->float_to_quint(base_vector.at(ic)->freq));
    data->insert(XL803::MARKERB_DIC,0x55);
    data->insert(XL803::MARKERB_WT_IC,base_vector.at(ic)->wave_type);
    data->insert(XL803::DCBias6,xl609->float_to_quint(base_vector.at(ic)->ratio));
}
void Hrenter_out::set_uc_out(QMap<XL803::MARKERB, qint32> *data)
{
    data->insert(XL803::MARKERB_UC,xl609->float_to_quint(base_vector.at(uc)->value));
    data->insert(XL803::MARKERB_UCP,base_vector.at(uc)->phase);
    data->insert(XL803::MARKERB_FC,xl609->float_to_quint(base_vector.at(uc)->freq));
    data->insert(XL803::MARKERB_DUC,0x55);
    data->insert(XL803::MARKERB_WT_UC,base_vector.at(uc)->wave_type);
    data->insert(XL803::DCBias5,xl609->float_to_quint(base_vector.at(uc)->ratio));
}
void Hrenter_out::set_ud_out(QMap<XL803::MARKERB, qint32> *data)
{
    data->insert(XL803::MARKERB_UD,xl609->float_to_quint(base_vector.at(ud)->value));
    data->insert(XL803::MARKERB_UDP,base_vector.at(ud)->phase);
    data->insert(XL803::MARKERB_FD,xl609->float_to_quint(base_vector.at(ud)->freq));
    data->insert(XL803::MARKERB_DUD,0x55);
    data->insert(XL803::MARKERB_WT_UD,base_vector.at(ud)->wave_type);
    data->insert(XL803::DCBias7,xl609->float_to_quint(base_vector.at(ud)->ratio));
}
void Hrenter_out::set_id_out(QMap<XL803::MARKERB, qint32> *data)
{
    data->insert(XL803::MARKERB_ID,xl609->float_to_quint(base_vector.at(id)->value));
    data->insert(XL803::MARKERB_IDP,base_vector.at(id)->phase);
    data->insert(XL803::MARKERB_FD,xl609->float_to_quint(base_vector.at(id)->freq));
    data->insert(XL803::MARKERB_DID,0x55);
    data->insert(XL803::MARKERB_WT_ID,base_vector.at(id)->wave_type);
    data->insert(XL803::DCBias8,xl609->float_to_quint(base_vector.at(id)->ratio));
}
void Hrenter_out::set_ia1_out(QMap<XL803::MARKERB, qint32> *data)
{
    data->insert(XL803::MARKERB_IA1,xl609->float_to_quint(base_vector.at(ia1)->value));
    data->insert(XL803::MARKERB_IAP1,xl609->float_to_quint(base_vector.at(ia1)->phase));
    data->insert(XL803::MARKERB_FA,xl609->float_to_quint(base_vector.at(ia1)->freq));
    data->insert(XL803::MARKERB_DIA1,0x55);
    data->insert(XL803::MARKERB_WT_IA2,base_vector.at(ia1)->wave_type);
    data->insert(XL803::DCBias10,xl609->float_to_quint(base_vector.at(ia1)->ratio));

}
void Hrenter_out::set_ua1_out(QMap<XL803::MARKERB, qint32> *data)
{
    data->insert(XL803::MARKERB_UA1,xl609->float_to_quint(base_vector.at(ua1)->value));
    data->insert(XL803::MARKERB_UAP1,xl609->float_to_quint(base_vector.at(ua1)->phase));
    data->insert(XL803::MARKERB_FA,xl609->float_to_quint(base_vector.at(ua1)->freq));
    data->insert(XL803::MARKERB_DUA1,0x55);
    data->insert(XL803::MARKERB_WT_UA2,base_vector.at(ua1)->wave_type);
    data->insert(XL803::DCBias9,xl609->float_to_quint(base_vector.at(ua1)->ratio));
}
void Hrenter_out::set_ib1_out(QMap<XL803::MARKERB, qint32> *data)
{
    data->insert(XL803::MARKERB_IB1,xl609->float_to_quint(base_vector.at(ib1)->value));
    data->insert(XL803::MARKERB_IBP1,base_vector.at(ib1)->phase);
    data->insert(XL803::MARKERB_FB,xl609->float_to_quint(base_vector.at(ib1)->freq));
    data->insert(XL803::MARKERB_DIB1,0x55);
    data->insert(XL803::MARKERB_WT_IB2,base_vector.at(ib1)->wave_type);
    data->insert(XL803::DCBias12,xl609->float_to_quint(base_vector.at(ib1)->ratio));
}
void Hrenter_out::set_ub1_out(QMap<XL803::MARKERB, qint32> *data)
{
    data->insert(XL803::MARKERB_UB1,xl609->float_to_quint(base_vector.at(ub1)->value));
    data->insert(XL803::MARKERB_UBP1,base_vector.at(ub1)->phase);
    data->insert(XL803::MARKERB_FB,xl609->float_to_quint(base_vector.at(ub1)->freq));
    data->insert(XL803::MARKERB_DUB1,0x55);
    data->insert(XL803::MARKERB_WT_UB2,base_vector.at(ub1)->wave_type);
    data->insert(XL803::DCBias11,xl609->float_to_quint(base_vector.at(ub1)->ratio));
}
void Hrenter_out::set_ic1_out(QMap<XL803::MARKERB, qint32> *data)
{
    data->insert(XL803::MARKERB_IC1,xl609->float_to_quint(base_vector.at(ic1)->value));
    data->insert(XL803::MARKERB_ICP1,base_vector.at(ic1)->phase);
    data->insert(XL803::MARKERB_FC,xl609->float_to_quint(base_vector.at(ic1)->freq));
    data->insert(XL803::MARKERB_DIC1,0x55);
    data->insert(XL803::MARKERB_WT_IC2,base_vector.at(ic1)->wave_type);
    data->insert(XL803::DCBias14,xl609->float_to_quint(base_vector.at(ic1)->ratio));
}
void Hrenter_out::set_uc1_out(QMap<XL803::MARKERB, qint32> *data)
{
    data->insert(XL803::MARKERB_UC1,xl609->float_to_quint(base_vector.at(uc1)->value));
    data->insert(XL803::MARKERB_UCP1,base_vector.at(uc1)->phase);
    data->insert(XL803::MARKERB_FC,xl609->float_to_quint(base_vector.at(uc1)->freq));
    data->insert(XL803::MARKERB_DUC1,0x55);
    data->insert(XL803::MARKERB_WT_UC2,base_vector.at(uc1)->wave_type);
    data->insert(XL803::DCBias13,xl609->float_to_quint(base_vector.at(uc1)->ratio));
}
void Hrenter_out::set_ud1_out(QMap<XL803::MARKERB, qint32> *data)
{
    data->insert(XL803::MARKERB_UD1,xl609->float_to_quint(base_vector.at(ud1)->value));
    data->insert(XL803::MARKERB_UDP1,base_vector.at(ud1)->phase);
    data->insert(XL803::MARKERB_FD,xl609->float_to_quint(base_vector.at(ud1)->freq));
    data->insert(XL803::MARKERB_DUD1,0x55);
    data->insert(XL803::MARKERB_WT_UD2,base_vector.at(ud1)->wave_type);
    data->insert(XL803::DCBias15,xl609->float_to_quint(base_vector.at(ud1)->ratio));
}
void Hrenter_out::set_id1_out(QMap<XL803::MARKERB, qint32> *data)
{
    data->insert(XL803::MARKERB_ID1,xl609->float_to_quint(base_vector.at(id1)->value));
    data->insert(XL803::MARKERB_IDP1,base_vector.at(id1)->phase);
    data->insert(XL803::MARKERB_FD,xl609->float_to_quint(base_vector.at(id1)->freq));
    data->insert(XL803::MARKERB_DID1,0x55);
    data->insert(XL803::MARKERB_WT_UD2,base_vector.at(id1)->wave_type);
    data->insert(XL803::DCBias16,xl609->float_to_quint(base_vector.at(id1)->ratio));
}
void Hrenter_out::on_write_hrenter_data_clicked()
{
    QMap<XL803::MARKERB, qint32> data;
    if(ui->ua->isChecked())
        set_ua_out(&data);
    if(ui->ia->isChecked())
        set_ia_out(&data);
    if(ui->ub->isChecked())
        set_ub_out(&data);
    if(ui->ib->isChecked())
        set_ib_out(&data);
    if(ui->uc->isChecked())
        set_uc_out(&data);
    if(ui->ic->isChecked())
        set_ic_out(&data);
//    if(ui->ud->isChecked())
//        set_ud_out(&data);
//    if(ui->id->isChecked())
//        set_id_out(&data);
//    if(ui->ua1->isChecked())
//        set_ua1_out(&data);
//    if(ui->ia1->isChecked())
//        set_ia1_out(&data);
//    if(ui->ub1->isChecked())
//        set_ub1_out(&data);
//    if(ui->ib1->isChecked())
//        set_ib1_out(&data);
//    if(ui->uc1->isChecked())
//        set_uc1_out(&data);
//    if(ui->ic1->isChecked())
//        set_ic1_out(&data);
//    if(ui->ud1->isChecked())
//        set_ud1_out(&data);
//    if(ui->id1->isChecked())
//        set_id1_out(&data);
    xl609->COM_HightWrite(data,XL803::HRENTER_OUT);

    if(ui->ua->isChecked())
    {
        start_flag<<"ua";
        xl609->write_one_harmonic((quint8)(0),m_hrData[XL803::OCM_UA],XL803::HRENTER_OUT);
    }
    if(ui->ia->isChecked())
    {
        start_flag<<"ia";
        xl609->write_one_harmonic((quint8)(1),m_hrData[XL803::OCM_IA],XL803::HRENTER_OUT);
    }
    if(ui->ub->isChecked())
    {
        start_flag<<"ub";
        xl609->write_one_harmonic((quint8)(2),m_hrData[XL803::OCM_UB],XL803::HRENTER_OUT);
    }
    if(ui->ib->isChecked())
    {
        start_flag<<"ib";
        xl609->write_one_harmonic((quint8)(3),m_hrData[XL803::OCM_IB],XL803::HRENTER_OUT);
    }
    if(ui->uc->isChecked())
    {
        start_flag<<"uc";
        xl609->write_one_harmonic((quint8)(4),m_hrData[XL803::OCM_UC],XL803::HRENTER_OUT);
    }
    if(ui->ic->isChecked())
    {
        start_flag<<"ic";
        xl609->write_one_harmonic((quint8)(5),m_hrData[XL803::OCM_IC],XL803::HRENTER_OUT);
    }
//    if(ui->ud->isChecked())
//        xl609->write_one_harmonic((quint8)(6),m_hrData[XL803::OCM_UD],XL803::HRENTER_OUT);
//    if(ui->id->isChecked())
//        xl609->write_one_harmonic((quint8)(7),m_hrData[XL803::OCM_ID],XL803::HRENTER_OUT);
//    if(ui->ua1->isChecked())
//        xl609->write_one_harmonic((quint8)(8),m_hrData[XL803::OCM_UA2],XL803::HRENTER_OUT);
//    if(ui->ia1->isChecked())
//        xl609->write_one_harmonic((quint8)(9),m_hrData[XL803::OCM_IA2],XL803::HRENTER_OUT);
//    if(ui->ub1->isChecked())
//        xl609->write_one_harmonic((quint8)(10),m_hrData[XL803::OCM_UB2],XL803::HRENTER_OUT);
//    if(ui->ib1->isChecked())
//        xl609->write_one_harmonic((quint8)(11),m_hrData[XL803::OCM_IB2],XL803::HRENTER_OUT);
//    if(ui->uc1->isChecked())
//        xl609->write_one_harmonic((quint8)(12),m_hrData[XL803::OCM_UC2],XL803::HRENTER_OUT);
//    if(ui->ic1->isChecked())
//        xl609->write_one_harmonic((quint8)(13),m_hrData[XL803::OCM_IC2],XL803::HRENTER_OUT);
//    if(ui->ud1->isChecked())
//        xl609->write_one_harmonic((quint8)(14),m_hrData[XL803::OCM_UD2],XL803::HRENTER_OUT);
//    if(ui->id1->isChecked())
//        xl609->write_one_harmonic((quint8)(15),m_hrData[XL803::OCM_ID2],XL803::HRENTER_OUT);
}

void Hrenter_out::on_hrenter_all_start_clicked()
{
    start_flag<<"all";
    if(xl609->last_control)
    {
        xl609->constraint_set_wave(XL803::BASE_OUT);
        xl609->last_control=0;
    }
    if(ui->all->isChecked()==false)
        ui->all->click();
    on_write_hrenter_data_clicked();
    //xl609->COM_WriteHarmonic(m_hrData,XL803::HRENTER_OUT);
    xl609->COM_HarmonicStartup(XL803::SP_UIABC,1000,XL803::HRENTER_OUT);
}

void Hrenter_out::on_base_all_start_clicked()
{
    if(xl609->last_control)
    {
        xl609->constraint_set_wave(XL803::BASE_OUT);
        xl609->last_control=0;
    }
//    QMap<XL803::MARKERB,qint32> ac;
//    ac.insert(XL803::MARKERB_SUA,0x01);
//    ac.insert(XL803::MARKERB_SIA,0x01);
//    ac.insert(XL803::MARKERB_SUB,0x01);
//    ac.insert(XL803::MARKERB_SIB,0x01);
//    ac.insert(XL803::MARKERB_SUC,0x01);
//    ac.insert(XL803::MARKERB_SIC,0x01);
//        start_flag<<"all";
//    ac.insert(XL803::MARKERB_SUD,0x01);
//    ac.insert(XL803::MARKERB_SID,0x01);
//    ac.insert(XL803::MARKERB_SUA1,0x01);
//    ac.insert(XL803::MARKERB_SIA1,0x01);
//    ac.insert(XL803::MARKERB_SUB1,0x01);
//    ac.insert(XL803::MARKERB_SIB1,0x01);
//    ac.insert(XL803::MARKERB_SUC1,0x01);
//    ac.insert(XL803::MARKERB_SIC1,0x01);
//    ac.insert(XL803::MARKERB_SUD1,0x01);
//    ac.insert(XL803::MARKERB_SID1,0x01);
//    xl609->COM_StartUp(ac,XL803::HRENTER_OUT);
    ui->all->setChecked(true);
    ui->ua->setChecked(true);
    ui->ia->setChecked(true);
    ui->ub->setChecked(true);
    ui->ib->setChecked(true);
    ui->uc->setChecked(true);
    ui->ic->setChecked(true);
    write_base(true);
}

void Hrenter_out::on_all_stop_clicked()
{
    QMap<XL803::MARKERB,qint32> ac;
    ac.insert(XL803::MARKERB_EUA,0x01);
    ac.insert(XL803::MARKERB_EIA,0x01);
    ac.insert(XL803::MARKERB_EUB,0x01);
    ac.insert(XL803::MARKERB_EIB,0x01);
    ac.insert(XL803::MARKERB_EUC,0x01);
    ac.insert(XL803::MARKERB_EIC,0x01);
    start_flag<<"all";
//    ac.insert(XL803::MARKERB_EUD,0x01);
//    ac.insert(XL803::MARKERB_EID,0x01);
//    ac.insert(XL803::MARKERB_EUA1,0x01);
//    ac.insert(XL803::MARKERB_EIA1,0x01);
//    ac.insert(XL803::MARKERB_EUB1,0x01);
//    ac.insert(XL803::MARKERB_EIB1,0x01);
//    ac.insert(XL803::MARKERB_EUC1,0x01);
//    ac.insert(XL803::MARKERB_EIC1,0x01);
//    ac.insert(XL803::MARKERB_EUD1,0x01);
//    ac.insert(XL803::MARKERB_EID1,0x01);
    xl609->COM_Stop(ac,XL803::HRENTER_OUT);
    xl609->COM_HarmonicStop(XL803::SP_UIABC,XL803::HRENTER_OUT);
}

void Hrenter_out::on_hrenter_start_clicked()
{
    if(xl609->last_control)
    {
        xl609->constraint_set_wave(XL803::BASE_OUT);
        xl609->last_control=0;
    }
    write_base(false);
    XL803::PHASE_ENUM able=XL803::SP_NO;
    if(ui->ua->isChecked())
        xl609->phaseSet(able,XL803::SP_UA);
    if(ui->ia->isChecked())
        xl609->phaseSet(able,XL803::SP_IA);
    if(ui->ub->isChecked())
        xl609->phaseSet(able,XL803::SP_UB);
    if(ui->ib->isChecked())
        xl609->phaseSet(able,XL803::SP_IB);
    if(ui->uc->isChecked())
        xl609->phaseSet(able,XL803::SP_UC);
    if(ui->ic->isChecked())
        xl609->phaseSet(able,XL803::SP_IC);
//    if(ui->uc->isChecked())
//        xl609->phaseSet(able,XL803::SP_UD);
//    if(ui->ic->isChecked())
//        xl609->phaseSet(able,XL803::SP_ID);
//    if(ui->ua->isChecked())
//        xl609->phaseSet(able,XL803::SP_UA2);
//    if(ui->ia->isChecked())
//        xl609->phaseSet(able,XL803::SP_IA2);
//    if(ui->ub->isChecked())
//        xl609->phaseSet(able,XL803::SP_UB2);
//    if(ui->ib->isChecked())
//        xl609->phaseSet(able,XL803::SP_IB2);
//    if(ui->uc->isChecked())
//        xl609->phaseSet(able,XL803::SP_UC2);
//    if(ui->ic->isChecked())
//        xl609->phaseSet(able,XL803::SP_IC2);
//    if(ui->uc->isChecked())
//        xl609->phaseSet(able,XL803::SP_UD2);
//    if(ui->ic->isChecked())
//        xl609->phaseSet(able,XL803::SP_ID2);
    on_write_hrenter_data_clicked();
    xl609->COM_HarmonicStartup(able,0,XL803::HRENTER_OUT);
}

void Hrenter_out::on_hrenter_stop_clicked()
{
//    if(ui->wave_type->value()>0&&ui->wave_type->value()<3)
//    {

//        return;
//    }
    on_base_stop_clicked();
    XL803::PHASE_ENUM able=XL803::SP_NO;
    if(ui->ua->isChecked())
        xl609->phaseSet(able,XL803::SP_UA);
    if(ui->ia->isChecked())
        xl609->phaseSet(able,XL803::SP_IA);
    if(ui->ub->isChecked())
        xl609->phaseSet(able,XL803::SP_UB);
    if(ui->ib->isChecked())
        xl609->phaseSet(able,XL803::SP_IB);
    if(ui->uc->isChecked())
        xl609->phaseSet(able,XL803::SP_UC);
    if(ui->ic->isChecked())
        xl609->phaseSet(able,XL803::SP_IC);
//    if(ui->ud->isChecked())
//        xl609->phaseSet(able,XL803::SP_UD);
//    if(ui->id->isChecked())
//        xl609->phaseSet(able,XL803::SP_ID);
//    if(ui->ua1->isChecked())
//        xl609->phaseSet(able,XL803::SP_UA2);
//    if(ui->ia1->isChecked())
//        xl609->phaseSet(able,XL803::SP_IA2);
//    if(ui->ub1->isChecked())
//        xl609->phaseSet(able,XL803::SP_UB2);
//    if(ui->ib1->isChecked())
//        xl609->phaseSet(able,XL803::SP_IB2);
//    if(ui->uc1->isChecked())
//        xl609->phaseSet(able,XL803::SP_UC2);
//    if(ui->ic1->isChecked())
//        xl609->phaseSet(able,XL803::SP_IC2);
//    if(ui->ud1->isChecked())
//        xl609->phaseSet(able,XL803::SP_UD2);
//    if(ui->id1->isChecked())
//        xl609->phaseSet(able,XL803::SP_ID2);
    xl609->COM_HarmonicStop(able,XL803::HRENTER_OUT);
}

void Hrenter_out::on_clear_hrenter_data_clicked()
{
//    memset(&m_hrData,0,sizeof(m_hrData));
//    for(int i=0;i<base_vector.count();i++)
//    {
//        memset(base_vector.at(i),0,sizeof(base));
//    }
    for(int i=0;i<ui->hrenter_data->rowCount();i++)
    {
        ui->hrenter_data->item(i,0)->setText("0");
        ui->hrenter_data->item(i,1)->setText("0");
        ui->hrenter_data->item(i,2)->setText("0");
    }
}


void Hrenter_out::on_preview_hrenter_clicked()
{
    QVector<double> radio;//含有率
    QVector<double> num;//n次
    QVector<double> phase;//相位
    QVector<double> data,index;
    float value;
    float max=0;
    float min=0;
    double base_value=ui->base_value->value();//基波有效值
    double ratio=ui->ratio->text().toFloat();//直流偏移
    double freq=ui->freq->value();
    double time=0;
    for(int i=0;i<ui->hrenter_data->rowCount();i++)
    {
        if(ui->hrenter_data->item(i,0)->text().toDouble()>0||i==0)
        {
            radio<<ui->hrenter_data->item(i,0)->text().toDouble();
            num<<i+1;
            phase<<(ui->hrenter_data->item(i,2)->text().toDouble()-ui->hrenter_data->item(0,2)->text().toDouble()/180);
        }
    }
//    if(radio.count()<1)
//        return;
    double step=1/freq/500;//控制点密度
    double k=0;
    double b=0;
    for(double i=0;i+step<1/freq;)
    {
        index<<(i+=step);
        value=0;
        switch (ui->wave_type->value()) {
        case 0:
            value=((base_value*(radio[0]/100))*sqrt(2))*qSin(2*M_PI*freq*(i+phase[0]/360*(1/freq)))\
                    +(ratio/100*(base_value));
            break;
        case 1:
            time=phase[0]/360*(1/freq)+i;
            for(;time>1/freq;time-=(1/freq)){};
            for(;time<0;time+=(1/freq)){};
            if(time<1/freq/2)
            {
                value=(base_value*(radio[0]/100))+(base_value*(ratio/100));
            }else
            {
                value=(0-(base_value*(radio[0]/100)))+(base_value*(ratio/100));
            }
            break;
        case 2:
            time=phase[0]/360*(1/freq)+i;
            for(;time>1/freq;time-=(1/freq)){};
            for(;time<0;time+=(1/freq)){};
            if((time<1/freq/4))
            {
                k=4*freq*(base_value*(radio[0]/100))*(sqrt(3));
                b=0;
            }else if(time<(1/freq/4*3))
            {
                k=0-(4*freq*(base_value*(radio[0]/100))*(sqrt(3)));
                b=(base_value*(radio[0]/100))*(sqrt(3))*2;
            }else
            {
                k=4*freq*(base_value*(radio[0]/100))*(sqrt(3));
                b=(0-base_value*(radio[0]/100))*(sqrt(3))*4;
            }
            value=k*time+b+(ratio/100*base_value);
            break;
        case 3:
            value=(base_value*(radio[0]/100))+(ratio/100*base_value);
            break;
        default:
            break;
        }
        for(int j=1;j<radio.count();j++)
        {
            switch (ui->wave_type->value()) {
            case 0://正弦波波形
                value+=(radio[j]/100)*(base_value*sqrt(2))*qSin(num[j]*2*M_PI*freq*i+((phase[j]-phase[0])/180*M_PI));
                break;
            case 1://方波
                time=(phase[j]+phase[0])/360*(1/freq/num.at(j))+i;
                for(;time>1/freq/num.at(j);time-=(1/freq/num.at(j))){};
                for(;time<0;time+=(1/freq/num.at(j))){};
                if(time<1/freq/num.at(j)/2)
                {
                    value+=(radio[j]/100)*base_value;
                }else
                {
                    value+=(radio[j]/100)*(0-base_value);
                }
                break;
            case 2://三角波
                time=(phase[j]+phase[0])/360*(1/freq/num.at(j))+i;
                for(;time>1/freq/num.at(j);time-=(1/freq/num.at(j))){};
                for(;time<0;time+=(1/freq/num.at(j))){};
                if((time<1/freq/4/num.at(j)))
                {
                    k=num.at(j)*4*freq*(base_value)*(sqrt(3));
                    b=0;
                }else if(time<(1/freq/4/num.at(j)*3))
                {
                    k=num.at(j)*(-4*freq*(base_value)*(sqrt(3)));
                    b=base_value*(sqrt(3))*2;
                }else
                {
                    k=num.at(j)*4*freq*(base_value)*(sqrt(3));
                    b=(0-base_value)*(sqrt(3))*4;
                }
                value+=(radio[j]/100)*(k*time+b);
                break;
            case 3://直流
                value+=(base_value*(radio[j]/100));
                break;
            default:
                value+=(radio[j]/100)*(base_value*sqrt(2))*qSin(num[j]*2*M_PI*freq*i+((phase[j]-phase[0])/180*M_PI));
                break;
            }
        }
        max>qAbs(value)?:max=qAbs(value);
        data<<value;
    }
    bar->setData(num,radio);
    QSharedPointer<QCPAxisTickerFixed> ticker(new QCPAxisTickerFixed);
    ticker->setTickStep(max*2/4);
    ui->wave_map->yAxis->setRange(0-max*1.1,max*1.1);
    ui->wave_map->yAxis->setTicker(ticker);
    line->setData(index,data);
    line->setPen(QPen(Qt::yellow,1));
    set_rms(enum_index.at(ui->pipe_type->currentIndex()),base_vector.at(ui->pipe_type->currentIndex()));
    ui->wave_map->replot();
    ui->bar_map->replot();
}
void Hrenter_out::init_value()
{
    for(int i=0;i<XL803::SOUR_PHASE_NUM_MAX;i++)
    {
        if((i%8)/2==0)
            m_hrData[i][0].phase=0;
        if((i%8)/2==1)
            m_hrData[i][0].phase=240;
        if((i%8)/2==2)
            m_hrData[i][0].phase=120;
        if((i%8)/2==3)
            m_hrData[i][0].phase=0;
        m_hrData[i][0].radio=100;
    }
    for(int i=0;i<base_vector.count();i++)
    {
        base_vector.at(enum_index.at(i))->freq=50;
        if(i%8/2==0)
            base_vector.at(enum_index.at(i))->phase=0;
        if(i%8/2==1)
            base_vector.at(enum_index.at(i))->phase=240;
        if(i%8/2==2)
            base_vector.at(enum_index.at(i))->phase=120;
        if(i%8/2==3)
            base_vector.at(enum_index.at(i))->phase=0;
        base_vector.at(enum_index.at(i))->ratio=0;
        if(i%2==0)
            base_vector.at(enum_index.at(i))->value=50;
        if(i%2==1)
            base_vector.at(enum_index.at(i))->value=1;
        base_vector.at(enum_index.at(i))->ratio=0;
    }
}

void Hrenter_out::on_base_phase_valueChanged(double arg1)
{
    base_vector.at(enum_index.at(ui->pipe_type->currentIndex()))->phase=arg1;
}
void Hrenter_out::check_flag(int value)
{
    if(start_flag.indexOf("all")!=-1)
    {
        ui->ua_state->set_value(value);
        ui->ub_state->set_value(value);
        ui->uc_state->set_value(value);
        ui->ia_state->set_value(value);
        ui->ib_state->set_value(value);
        ui->ic_state->set_value(value);
        start_flag.clear();
        return;
    }
    if(start_flag.indexOf("ua")!=-1)
    {
        ui->ua_state->set_value(value);
    }
    if(start_flag.indexOf("ia")!=-1)
    {
        ui->ia_state->set_value(value);
    }
    if(start_flag.indexOf("ub")!=-1)
    {
        ui->ub_state->set_value(value);
    }
    if(start_flag.indexOf("ib")!=-1)
    {
        ui->ib_state->set_value(value);
    }
    if(start_flag.indexOf("uc")!=-1)
    {
        ui->uc_state->set_value(value);
    }
    if(start_flag.indexOf("ic")!=-1)
    {
        ui->ic_state->set_value(value);
    }
    start_flag.clear();
}

void Hrenter_out::on_all_clicked()
{
    ui->ua->setChecked(ui->all->isChecked());
    ui->ub->setChecked(ui->all->isChecked());
    ui->uc->setChecked(ui->all->isChecked());
    ui->ia->setChecked(ui->all->isChecked());
    ui->ib->setChecked(ui->all->isChecked());
    ui->ic->setChecked(ui->all->isChecked());
}
