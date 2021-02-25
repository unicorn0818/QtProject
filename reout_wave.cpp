#include "reout_wave.h"
#include "ui_reout_wave.h"

reout_wave::reout_wave(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::reout_wave)
{
    ui->setupUi(this);
    xl609=L_XL803;
    xl609->set_map(ui->u_map);
    xl609->set_map(ui->i_map);
    QVector<QString> list;
    l_ua=ui->u_map->addGraph();
    l_ua->setPen(QPen(Qt::yellow,1));
    l_ub=ui->u_map->addGraph();
    l_ub->setPen(QPen(Qt::green,1));
    l_uc=ui->u_map->addGraph();
    l_uc->setPen(QPen(Qt::red,1));

    l_ia=ui->i_map->addGraph();
    l_ia->setPen(QPen(Qt::yellow,1));
    l_ib=ui->i_map->addGraph();
    l_ib->setPen(QPen(Qt::green,1));
    l_ic=ui->i_map->addGraph();
    l_ic->setPen(QPen(Qt::red,1));

    l_u=ui->u_map->addGraph();
    l_i=ui->i_map->addGraph();
    l_u->setPen(QPen(Qt::blue,4));
    l_i->setPen(QPen(Qt::blue,4));
    list<<"内部触发输出"<<"外部触发输入"<<"启动立刻输出"<<"过零同步脉冲输出模式"<<"同步跟踪模式"<<"电能累计同步信号输出";
    ui->tigger_mode->set_items(list);
    ui->tigger_mode->setValue(2);
    ui->wave_start->setText("0");
    ui->wave_end->setText("0");
    ui->flush_lenth->setText("0");
    ui->wave_lenth->setText("0");
    ui->u_map->replot();
    ui->i_map->replot();
    pipe_count=0;
    max_freq=0;
    start_time=0;
    end_time=0;
    wave_point_count=0;
    QVector <QString> out_list;
    out_list<<"重复输出"<<"单次输出";
    ui->out_count->set_items(out_list);
    dialog=new QProgressDialog(tr("波形下载进度"), tr("取消"), 0, 1, this);
    dialog->setWindowTitle(tr("波形下载"));
    dialog->setWindowModality(Qt::WindowModal);
    dialog->setValue(1);
    start_down=false;
    ui->start_out->setEnabled(false);
    connect(L_XL803,SIGNAL(send_to_reout_wave(QByteArray,QByteArray)),this,SLOT(recv_mesg(QByteArray,QByteArray)));
    p_control=new map_control(this);
    p_control->hide();
    set_signal();
    u_rubber = new QRubberBand(QRubberBand::Rectangle, ui->u_map);
    connect(ui->u_map, SIGNAL(mousePress(QMouseEvent*)), this, SLOT(u_press(QMouseEvent*)));
    connect(ui->u_map, SIGNAL(mouseMove(QMouseEvent*)), this, SLOT(mouseMove(QMouseEvent*)));
    connect(ui->u_map, SIGNAL(mouseRelease(QMouseEvent*)), this, SLOT(mouseRelease(QMouseEvent*)));

    i_rubber = new QRubberBand(QRubberBand::Rectangle, ui->i_map);
    connect(ui->i_map, SIGNAL(mousePress(QMouseEvent*)), this, SLOT(i_press(QMouseEvent*)));
    connect(ui->i_map, SIGNAL(mouseMove(QMouseEvent*)), this, SLOT(mouseMove(QMouseEvent*)));
    connect(ui->i_map, SIGNAL(mouseRelease(QMouseEvent*)), this, SLOT(mouseRelease(QMouseEvent*)));
    connect(dialog,SIGNAL(canceled()),this,SLOT(cancel_down()));
    type=0;
    u_flag=false;
    i_flag=false;
    ui->label_18->hide();
    ui->tigger_mode->hide();
}
void reout_wave::cancel_down()
{
    start_down=false;
    wave_data.clear();
    one_wave.clear();
    check_byte=0;
}
reout_wave::~reout_wave()
{
    destory_comtrade();
    delete ui;
}
//录波回放启动按钮
void reout_wave::on_start_out_clicked()
{
    QMap<XL803::MARKERB, qint32> max_type;
    QByteArray all_pipe;
    quint8 m_null=0;
    max_type.insert(XL803::MARKERB_WAVE_UA,xl609->float_to_quint(ui->ua_max->text().toDouble()));
    max_type.insert(XL803::MARKERB_WAVE_UB,xl609->float_to_quint(ui->ub_max->text().toDouble()));
    max_type.insert(XL803::MARKERB_WAVE_UC,xl609->float_to_quint(ui->uc_max->text().toDouble()));
    max_type.insert(XL803::MARKERB_WAVE_IA,xl609->float_to_quint(ui->ia_max->text().toDouble()));
    max_type.insert(XL803::MARKERB_WAVE_IB,xl609->float_to_quint(ui->ib_max->text().toDouble()));
    max_type.insert(XL803::MARKERB_WAVE_IC,xl609->float_to_quint(ui->ic_max->text().toDouble()));
    max_type.insert(XL803::MARKERB_WAVE_UD,xl609->float_to_quint(ui->ic_max->text().toDouble()));
    max_type.insert(XL803::MARKERB_WAVE_ID,xl609->float_to_quint(ui->ic_max->text().toDouble()));

    max_type.insert(XL803::MARKERB_WT_UA,(qint32)4);
    max_type.insert(XL803::MARKERB_WT_UB,(qint32)4);
    max_type.insert(XL803::MARKERB_WT_UC,(qint32)4);
    max_type.insert(XL803::MARKERB_WT_IA,(qint32)4);
    max_type.insert(XL803::MARKERB_WT_IB,(qint32)4);
    max_type.insert(XL803::MARKERB_WT_IC,(qint32)4);

    max_type.insert(XL803::MARKERB_WT_UD,(qint32)4);
    max_type.insert(XL803::MARKERB_WT_ID,(qint32)4);

    max_type.insert(XL803::TRIGE_TYPE,(qint32)ui->tigger_mode->value());
    xl609->COM_HightWrite(max_type,XL803::REOUT_WAVE);
    if(ui->ua_flag->isChecked())
    {
        all_pipe.append((quint8)1);
    }else
    {
        all_pipe.append(m_null);
    }
    if(ui->ia_flag->isChecked())
    {
        all_pipe.append((quint8)1);
    }else
    {
        all_pipe.append(m_null);
    }
    if(ui->ub_flag->isChecked())
    {
        all_pipe.append((quint8)1);
    }else
    {
        all_pipe.append(m_null);
    }
    if(ui->ib_flag->isChecked())
    {
        all_pipe.append((quint8)1);
    }else
    {
        all_pipe.append(m_null);
    }
    if(ui->uc_flag->isChecked()) 
    {
        all_pipe.append((quint8)1);
    }else
    {
        all_pipe.append(m_null);
    }
    if(ui->ic_flag->isChecked())
    {
        all_pipe.append((quint8)1);
//        all_pipe.append((quint8)1);
//        all_pipe.append((quint8)1);
    }else
    {
        all_pipe.append(m_null);
    }
    all_pipe.append(m_null);
    all_pipe.append(m_null);
    qDebug()<<ui->out_count->text();
    if(ui->out_count->text().compare("重复输出")==0)
        xl609->start_reout_wave(0xFF,all_pipe,XL803::REOUT_WAVE);
    else
        xl609->start_reout_wave(0x01,all_pipe,XL803::REOUT_WAVE);
}

void reout_wave::on_stop_out_clicked()
{
    QByteArray stop_flag;
    quint8 m_null=0;
    if(ui->ua_flag->isChecked())
        stop_flag.append(m_null);
    if(ui->ia_flag->isChecked())
        stop_flag.append(1);
    if(ui->ub_flag->isChecked())
        stop_flag.append(2);
    if(ui->ib_flag->isChecked())
        stop_flag.append(3);
    if(ui->uc_flag->isChecked())
        stop_flag.append(4);
    if(ui->ic_flag->isChecked())
        stop_flag.append(5);
    stop_flag.append(6);
    stop_flag.append(7);
   xl609->output_simpdata_stop(stop_flag,XL803::REOUT_WAVE);
}

void reout_wave::on_pushButton_clicked()
{
    QMessageBox::information(this,"录波文件信息",QString("模拟量通道数: %1\n\
采样开始时间:%2秒\n采样结束时间:%3秒\n采样率:%4\n波形采样点数:%5").arg(pipe_count)\
.arg(start_time).arg(end_time).arg(max_freq).arg(qCeil(wave_point_count)));
}

void reout_wave::on_pushButton_2_clicked()
{
    int pipe=0;
    QSettings Settings("XL","9201");
    QString file_name = QFileDialog::getOpenFileName(NULL,"打开录波文件",Settings.value("path").toString(),"*.*");
    QFile file(file_name);
    QString set_path=file_name;
    set_path.remove(set_path.lastIndexOf("/"),set_path.length()-set_path.lastIndexOf("/"));
    qDebug()<<set_path;
    Settings.setValue("path",QVariant(set_path));
    if (!file.open(QIODevice::ReadOnly| QIODevice::Text))
    {
        QMessageBox::information(this,"警告","打开失败!");
        return;
    }
    file.close();

    QTextCodec *code = QTextCodec::codecForName("gb2312");
    code->fromUnicode(file_name).data();
    parse_comtrade_file(code->fromUnicode(file_name).data());
    pipe_count=get_comtrade_an_chan_num();
    max_freq=get_max_samprate();
    start_time=get_first_samp_time();
    end_time=get_end_samp_time();
    wave_point_count=qCeil(max_freq*(end_time-start_time));
//    QVector<double> x,y;
//    x<<(int)wave_point_count/2<<(int)wave_point_count/2;
    ui->ua_pipe->setRange(1,pipe_count);
    ui->ub_pipe->setRange(1,pipe_count);
    ui->uc_pipe->setRange(1,pipe_count);
    ui->ia_pipe->setRange(1,pipe_count);
    ui->ib_pipe->setRange(1,pipe_count);
    ui->ic_pipe->setRange(1,pipe_count);
    ui->wave_start->setText(QString("%1").arg(0));
    ui->wave_end->setText(QString("%1").arg(wave_point_count));
    on_mid_wave_clicked();
    pipe=ui->ua_pipe->value();
    if(pipe>pipe_count)
    {
        pipe=1;
        ui->ua_pipe->setValue(1);
    }
    double max=set_line_data(l_ua,pipe);
    double recv_value;
    ui->ua_max->setText(QString("%1").arg(max));
    pipe=ui->ub_pipe->value();
    if(pipe>pipe_count)
    {
        pipe=1;
        ui->ub_pipe->setValue(1);
    }
    recv_value=set_line_data(l_ub,pipe);
    if(recv_value>max)
        max=recv_value;
    ui->ub_max->setText(QString("%1").arg(recv_value));

    pipe=ui->uc_pipe->value();
    if(pipe>pipe_count)
    {
        pipe=1;
        ui->uc_pipe->setValue(1);
    }
    recv_value=set_line_data(l_uc,pipe);
    if(recv_value>max)
        max=recv_value;
    ui->uc_max->setText(QString("%1").arg(recv_value));
    ui->u_map->yAxis->setRange(0-max*1.2,max*1.2);
//    y<<0-max*1.2<<max*1.2;
//    l_u->setData(x,y);
    max=0;
    pipe=ui->ia_pipe->value();
    if(pipe>pipe_count)
    {
        pipe=1;
        ui->ia_pipe->setValue(1);
    }
    recv_value=set_line_data(l_ia,pipe);
    if(recv_value>max)
        max=recv_value;
    ui->ia_max->setText(QString("%1").arg(recv_value));

    pipe=ui->ib_pipe->value();
    if(pipe>pipe_count)
    {
        pipe=1;
        ui->ib_pipe->setValue(1);
    }
    recv_value=set_line_data(l_ib,pipe);
    if(recv_value>max)
        max=recv_value;
    ui->ib_max->setText(QString("%1").arg(recv_value));

    pipe=ui->ic_pipe->value();
    if(pipe>pipe_count)
    {
        pipe=1;
        ui->ic_pipe->setValue(1);
    }
    recv_value=set_line_data(l_ic,pipe);
    if(recv_value>max)
        max=recv_value;
    ui->ic_max->setText(QString("%1").arg(recv_value));
    ui->i_map->yAxis->setRange(0-max*1.2,max*1.2);
//    y.clear();
//    y<<0-max*1.2<<max*1.2;
//    l_i->setData(x,y);
    ui->u_map->replot();
    ui->i_map->replot();
}

void reout_wave::on_mid_wave_clicked()
{
    if(wave_point_count<1)
    {
        QMessageBox::information(this,"提示","无波形数据，请打开录波文件!");
        return;
    }
    QSharedPointer<QCPAxisTickerFixed> ticker(new QCPAxisTickerFixed);
    float start=ui->wave_start->text().toFloat();
    float end=ui->wave_end->text().toFloat();
    int point=end-start;
    if((end-start)<1)
    {
        QMessageBox::information(this,"警告","开始点不能大于或等于结束点!");
        return;
    }
    ticker->setTickStep(point/10>5?point/10:5);
    ui->wave_lenth->setText(QString("%1").arg(point/max_freq));
    ui->u_map->xAxis->setTicker(ticker);
    ui->i_map->xAxis->setTicker(ticker);
    ui->u_map->xAxis->setRange(start,end);
    ui->i_map->xAxis->setRange(start,end);
    ui->u_map->replot();
    ui->i_map->replot();
}

void reout_wave::on_read_falush_lenth_clicked()
{
    xl609->read_max_reout_wave_lenth(XL803::REOUT_WAVE);
}

void reout_wave::on_write_wave_date_clicked()
{    
    if(wave_point_count<1)
    {
        QMessageBox::information(this,"提示","无波形数据，请打开录波文件.");
    }
    wave_send_count=ui->wave_end->text().toDouble()-ui->wave_start->text().toDouble();
    if((wave_send_count)<1)
    {
        QMessageBox::information(this,"警告","开始点不能大于或等于结束点!");
        return;
    }
    xl609->last_control=1;
    xl609->start_down_simpdata((quint32)wave_send_count*2*all_channel,(quint32)max_freq,\
                               3000,(quint8)0,(quint8)3,XL803::REOUT_WAVE);
    ui->start_out->setEnabled(false);
}

void reout_wave::recv_mesg(QByteArray send, QByteArray read)
{
    quint8 null=0;
    QByteArray data=read;
    if((quint8)read[5]==(quint8)0xB9)
    {
        data.remove(0,6);
        float * len=(float * )data.data();
        ui->flush_lenth->setText(QString("%1").arg(*len));
    }else if((quint8)read[5]==(quint8)0xBA)
    {
        QMessageBox::information(this,"提示","录波回放波形准备完毕。");
        ui->start_out->setEnabled(true);
    }else if(start_down)
    {
        if((quint8)read[5]==0x10)
        {
            if(now_byte==all_byte-1)
            {
                start_down=false;
                xl609->stop_down_simpdata(XL803::REOUT_WAVE);
                dialog->setValue(dialog->value()+one_wave.length());
                wave_data.clear();
                one_wave.clear();
                check_byte=0;
                return;
            }
            dialog->setValue(dialog->value()+one_wave.length());
            wave_data.remove(0,one_wave.length());
            one_wave.clear();
            check_byte=0;
            for(int i=0;i<3000;i++)
            {
                if(i<wave_data.length())
                {
                    one_wave.append(wave_data.at(i));
                    check_byte+=wave_data.at(i);
                }else
                {
                    one_wave.append(null);
                }
            }
            now_byte++;
        }
        xl609->down_simpdata(now_byte,one_wave,check_byte,XL803::REOUT_WAVE);
    }else if((quint8)send[5]==0xB0)
    {
        if((quint8)read[5]!=0x10)
        {
            QMessageBox::information(this,"警告","写入应答错误!");
            return;
        }
        check_byte=0;
        dialog->show();
        int add=(3000-(((int)wave_send_count*2*all_channel)%3000));
        dialog->setRange(1,wave_send_count*2*all_channel+add);
        qDebug()<<wave_send_count*2*all_channel+add;
        start_down=true;
        one_wave.clear();
        wave_data.clear();
        now_byte=0;


        QVector<quint16> toSendData;//生成数据
        double tempValue;

        double * ua_data=(double *)malloc(wave_point_count*sizeof(double));
        get_chan_value(ui->ua_pipe->value(),start_time,end_time,ua_data,wave_point_count*sizeof(double));
        double * ub_data=(double *)malloc(wave_point_count*sizeof(double));
        get_chan_value(ui->ub_pipe->value(),start_time,end_time,ub_data,wave_point_count*sizeof(double));
        double * uc_data=(double *)malloc(wave_point_count*sizeof(double));
        get_chan_value(ui->uc_pipe->value(),start_time,end_time,uc_data,wave_point_count*sizeof(double));
        double * ia_data=(double *)malloc(wave_point_count*sizeof(double));
        get_chan_value(ui->ia_pipe->value(),start_time,end_time,ia_data,wave_point_count*sizeof(double));
        double * ib_data=(double *)malloc(wave_point_count*sizeof(double));
        get_chan_value(ui->ib_pipe->value(),start_time,end_time,ib_data,wave_point_count*sizeof(double));
        double * ic_data=(double *)malloc(wave_point_count*sizeof(double));
        get_chan_value(ui->ic_pipe->value(),start_time,end_time,ic_data,wave_point_count*sizeof(double));
        double start=ui->wave_start->text().toDouble();
        double end=ui->wave_end->text().toDouble();
        double ua_max=get_max(ua_data,start,end);
        double ia_max=get_max(ia_data,start,end);
        double ub_max=get_max(ub_data,start,end);
        double ib_max=get_max(ib_data,start,end);
        double uc_max=get_max(uc_data,start,end);
        double ic_max=get_max(ic_data,start,end);
        double ud_max=uc_max;
        double id_max=ic_max;
        //比例转换,
        double reset_value=0;
        for(int i=start;i<end;i++)
        {
            tempValue = float(( *(ua_data+i)/ua_max) *(float) 32767.0);
            toSendData<< (qint16)((tempValue>0)?(tempValue+0.5):(tempValue-0.5));
        }
        for(int i=start;i<end;i++)
        {
            reset_value=*(ia_data+i);
            reset_value=-reset_value;
            tempValue = float(( reset_value/ia_max) *(float) 32767.0);
            toSendData<< (qint16)((tempValue>0)?(tempValue+0.5):(tempValue-0.5));
        }
        for(int i=start;i<end;i++)
        {
            tempValue = float(( *(ub_data+i)/ub_max) *(float) 32767.0);
            toSendData<< (qint16)((tempValue>0)?(tempValue+0.5):(tempValue-0.5));
        }
        for(int i=start;i<end;i++)
        {
            reset_value=*(ib_data+i);
            reset_value=-reset_value;
            tempValue = float(( reset_value/ib_max) *(float) 32767.0);
            toSendData<< (qint16)((tempValue>0)?(tempValue+0.5):(tempValue-0.5));
        }
        for(int i=start;i<end;i++)
        {
            tempValue = float(( *(uc_data+i)/uc_max) *(float) 32767.0);
            toSendData<< (qint16)((tempValue>0)?(tempValue+0.5):(tempValue-0.5));
        }
        for(int i=start;i<end;i++)
        {
            reset_value=*(ic_data+i);
            reset_value=-reset_value;
            tempValue = float(( reset_value/ic_max) *(float) 32767.0);
            toSendData<< (qint16)((tempValue>0)?(tempValue+0.5):(tempValue-0.5));
        }
        for(int i=start;i<end;i++)
        {
            tempValue = float(( *(uc_data+i)/uc_max) *(float) 32767.0);
            toSendData<< (qint16)((tempValue>0)?(tempValue+0.5):(tempValue-0.5));
        }
        for(int i=start;i<end;i++)
        {
            reset_value=*(ic_data+i);
            reset_value=-reset_value;
            tempValue = float(( reset_value/ic_max) *(float) 32767.0);
            toSendData<< (qint16)((tempValue>0)?(tempValue+0.5):(tempValue-0.5));
        }

        for(int i=0;i<toSendData.count();i++)
        {
            wave_data.append(*((qint8 *)(&toSendData[i])));
            wave_data.append(*((qint8 *)(&toSendData[i])+1));
        }
        free(ua_data);
        free(ub_data);
        free(uc_data);
        free(ia_data);
        free(ib_data);
        free(ic_data);
        all_byte=qCeil((float)wave_data.count()/3000);
        for(int i=0;i<3000;i++)
        {
            if(i<wave_data.length())
            {
                one_wave.append(wave_data.at(i));
                check_byte+=(quint8)wave_data.at(i);
            }else
            {
                one_wave.append(null);
            }
        }
        // QCoreApplication::processEvents();
        xl609->down_simpdata(now_byte,one_wave,check_byte,XL803::REOUT_WAVE);
    }else if((quint8)send[5]==0xB8)//波形启动
    {

    }else if((quint8)send[5]==0xB5)//波形停止
    {

    }
}
double reout_wave::set_line_data(QCPGraph * line, unsigned int pipe, int start_point, int stop_point)
{
    double * data=(double *)malloc(wave_point_count*sizeof(double));
    memset(data,0,wave_point_count*sizeof(double));
    get_chan_value(pipe,start_time,end_time,data,wave_point_count*sizeof(double));
    int point_count=wave_point_count;
    QVector<double> x,y;
    double max=0;
    int step=1;
    int point=stop_point-start_point;
    int point_start=0;
    if(max_freq>4000)
    {
        step=qCeil(max_freq/4000);
        if(step<1)
            step=1;
    }
    if(point!=0)
    {
        if(point>40000)
        {
            step=qCeil(point/40000);
        }else
        {
            step=1;
        }
        point_count=stop_point;
        point_start=start_point;
    }
    for(;point_start<point_count;point_start+=step)
    {
        x.append(point_start);
        y.append(*(data+point_start));
        if(qAbs(*(data+point_start))>max)
            max=qAbs(*(data+point_start));
        qDebug()<<*(data+point_start);
    }
    line->setData(x,y);
    free(data);
    return max;
}

void reout_wave::on_ib_pipe_valueChanged(int arg1)
{
    double max=set_line_data(l_ib,arg1);
    double max_ib=max;
    double max_ia=ui->ia_max->text().toDouble();
    double max_ic=ui->ic_max->text().toDouble();
    if(max<max_ia)
        max=max_ia;
    if(max<max_ic)
        max=max_ic;
    ui->ib_max->setText(QString("%1").arg(max_ib));
    ui->i_map->yAxis->setRange(0-max*1.2,max*1.2);
    ui->i_map->replot();
}

void reout_wave::on_ua_pipe_valueChanged(int arg1)
{
    double max=set_line_data(l_ua,arg1);
    double max_ua=max;
    double max_ub=ui->ub_max->text().toDouble();
    double max_uc=ui->uc_max->text().toDouble();
    if(max<max_ub)
        max=max_ub;
    if(max<max_uc)
        max=max_uc;
    ui->ua_max->setText(QString("%1").arg(max_ua));
    ui->u_map->yAxis->setRange(0-max*1.2,max*1.2);
    ui->u_map->replot();
}

void reout_wave::on_ub_pipe_valueChanged(int arg1)
{
    double max=set_line_data(l_ub,arg1);
    double max_ub=max;
    double max_ua=ui->ua_max->text().toDouble();
    double max_uc=ui->uc_max->text().toDouble();
    if(max<max_ua)
        max=max_ua;
    if(max<max_uc)
        max=max_uc;
    ui->ub_max->setText(QString("%1").arg(max_ub));
    ui->u_map->yAxis->setRange(0-max*1.2,max*1.2);
    ui->u_map->replot();
}

void reout_wave::on_uc_pipe_valueChanged(int arg1)
{
    double max=set_line_data(l_uc,arg1);
    double max_uc=max;
    double max_ua=ui->ua_max->text().toDouble();
    double max_ub=ui->ub_max->text().toDouble();
    if(max<max_ua)
        max=max_ua;
    if(max<max_ub)
        max=max_ub;
    ui->uc_max->setText(QString("%1").arg(max_uc));
    ui->u_map->yAxis->setRange(0-max*1.2,max*1.2);
    ui->u_map->replot();
}

void reout_wave::on_ia_pipe_valueChanged(int arg1)
{
    double max=set_line_data(l_ia,arg1);
    double max_ia=max;
    double max_ib=ui->ib_max->text().toDouble();
    double max_ic=ui->ic_max->text().toDouble();
    if(max<max_ib)
        max=max_ib;
    if(max<max_ic)
        max=max_ic;
    ui->ia_max->setText(QString("%1").arg(max_ia));
    ui->i_map->yAxis->setRange(0-max*1.2,max*1.2);
    ui->i_map->replot();
}

void reout_wave::on_ic_pipe_valueChanged(int arg1)
{
    double max=set_line_data(l_ic,arg1);
    double max_ic=max;
    double max_ia=ui->ia_max->text().toDouble();
    double max_ib=ui->ib_max->text().toDouble();
    if(max<max_ia)
        max=max_ia;
    if(max<max_ib)
        max=max_ib;
    ui->ic_max->setText(QString("%1").arg(max_ic));
    ui->i_map->yAxis->setRange(0-max*1.2,max*1.2);
    ui->i_map->replot();
}

void reout_wave::m_reset()
{
    if(wave_point_count<1)
        return;
    double max=0;
    if(ui->ua_max->text().toDouble()>max)
        max=ui->ua_max->text().toDouble();
    if(ui->ub_max->text().toDouble()>max)
        max=ui->ub_max->text().toDouble();
    if(ui->uc_max->text().toDouble()>max)
        max=ui->uc_max->text().toDouble();
    ui->u_map->yAxis->setRange(0-max*1.2,max*1.2);
        max=0;
    if(ui->ia_max->text().toDouble()>max)
        max=ui->ia_max->text().toDouble();
    if(ui->ib_max->text().toDouble()>max)
        max=ui->ib_max->text().toDouble();
    if(ui->ic_max->text().toDouble()>max)
        max=ui->ic_max->text().toDouble();
    ui->i_map->yAxis->setRange(0-max*1.2,max*1.2);

    ui->wave_lenth->setText(QString("%1").arg(wave_point_count/max_freq));
    QSharedPointer<QCPAxisTickerFixed> ticker(new QCPAxisTickerFixed);
    ticker->setTickStep((int)wave_point_count/10);
    ui->u_map->xAxis->setTicker(ticker);
    ui->i_map->xAxis->setTicker(ticker);
    ui->u_map->xAxis->setRange(0,wave_point_count*1.01);
    ui->i_map->xAxis->setRange(0,wave_point_count*1.01);
    ui->wave_start->setText("0");
    ui->wave_end->setText(QString("%1").arg(wave_point_count));
    ui->u_map->replot();
    ui->i_map->replot();
}

void reout_wave::set_signal()
{
    connect(p_control,SIGNAL(m_reset()),this,SLOT(m_reset()));
    connect(p_control,SIGNAL(m_move()),this,SLOT(m_move()));
    connect(p_control,SIGNAL(m_sq()),this,SLOT(m_sq()));
    connect(p_control,SIGNAL(m_all_up()),this,SLOT(m_all_up()));
    connect(p_control,SIGNAL(m_all_down()),this,SLOT(m_all_down()));
    connect(p_control,SIGNAL(m_sq_x()),this,SLOT(m_sq_x()));
    connect(p_control,SIGNAL(m_x_up()),this,SLOT(m_x_up()));
    connect(p_control,SIGNAL(m_x_down()),this,SLOT(m_x_down()));
    connect(p_control,SIGNAL(m_sq_y()),this,SLOT(m_sq_y()));
    connect(p_control,SIGNAL(m_y_up()),this,SLOT(m_y_up()));
    connect(p_control,SIGNAL(m_y_down()),this,SLOT(m_y_down()));
    connect(p_control,SIGNAL(m_replot()),this,SLOT(m_replot()));
}

void reout_wave::on_map_control_clicked()
{
    p_control->show();
    QPoint pos=mapToGlobal(ui->frame_5->pos());
    p_control->move(pos.x()-5,pos.y());
}
void reout_wave::mousePress(QMouseEvent* mevent)
{
    if(type>1)
    {
        ui->u_map->axisRect()->setRangeDrag(0);
        ui->i_map->axisRect()->setRangeDrag(0);
    }
    switch (type) {
    case 1:
        ui->u_map->axisRect()->setRangeDrag(Qt::Horizontal|Qt::Vertical);
        ui->i_map->axisRect()->setRangeDrag(Qt::Horizontal|Qt::Vertical);
        break;
    case 2:
    case 3:
    case 4:
        if(mevent->button() == Qt::LeftButton)
        {
            rubberOrigin = mevent->pos();
            if(u_flag)
            {
                u_rubber->setGeometry(QRect(rubberOrigin, QSize()));
                u_rubber->show();
            }else if(i_flag)
            {
                i_rubber->setGeometry(QRect(rubberOrigin, QSize()));
                i_rubber->show();
            }
        }
        break;
    default:
        break;
    }
}


//鼠标移动槽函数
void reout_wave::mouseMove(QMouseEvent *mevent)
{
    if(u_rubber->isVisible())
        u_rubber->setGeometry(QRect(rubberOrigin, mevent->pos()).normalized());
    if(i_rubber->isVisible())
        i_rubber->setGeometry(QRect(rubberOrigin, mevent->pos()).normalized());
}

//鼠标释放槽函数
void reout_wave::mouseRelease(QMouseEvent *mevent)
{
    Q_UNUSED(mevent);
    if(type>1)
    {
        ui->i_map->axisRect()->setRangeDrag(0);
        ui->i_map->axisRect()->setRangeDrag(0);
    }
    double x1;
    double x2;
    double y1;
    double y2;
    double x;
    double y;
    if (u_rubber->isVisible())
    {
        const QRect zoomRect = u_rubber->geometry();
        int xp1, yp1, xp2, yp2;
        zoomRect.getCoords(&xp1, &yp1, &xp2, &yp2);
        x1= ui->u_map->xAxis->pixelToCoord(xp1);
        x2= ui->u_map->xAxis->pixelToCoord(xp2);
        y1= ui->u_map->yAxis->pixelToCoord(yp1);
        y2= ui->u_map->yAxis->pixelToCoord(yp2);
    }
    if (i_rubber->isVisible())
    {
        const QRect zoomRect = i_rubber->geometry();
        int xp1, yp1, xp2, yp2;
        zoomRect.getCoords(&xp1, &yp1, &xp2, &yp2);
        x1= ui->i_map->xAxis->pixelToCoord(xp1);
        x2= ui->i_map->xAxis->pixelToCoord(xp2);
        y1= ui->i_map->yAxis->pixelToCoord(yp1);
        y2= ui->i_map->yAxis->pixelToCoord(yp2);
    }
    switch (type) {
    case 1:
        ui->u_map->axisRect()->setRangeDrag(Qt::Horizontal|Qt::Vertical);
        ui->i_map->axisRect()->setRangeDrag(Qt::Horizontal|Qt::Vertical);
        break;
    case 2:
        if(u_rubber->isVisible())
        {
            ui->u_map->xAxis->setRange(x1, x2);
            ui->u_map->yAxis->setRange(y1, y2);
        }
        if(i_rubber->isVisible())
        {
            ui->i_map->xAxis->setRange(x1, x2);
            ui->i_map->yAxis->setRange(y1, y2);
        }
        reset_ticker();
        break;
    case 3:
        if (u_rubber->isVisible())
        {
            ui->u_map->xAxis->setRange(x1, x2);
        }
        if (i_rubber->isVisible())
        {
            ui->i_map->xAxis->setRange(x1, x2);
        }
        reset_ticker();
        break;
    case 4:
        if (u_rubber->isVisible())
        {
            ui->u_map->yAxis->setRange(y1, y2);
        }
        if (i_rubber->isVisible())
        {
            ui->i_map->yAxis->setRange(y1, y2);
        }
        break;
    case 5:
        if(u_flag)
        {
            x= ui->u_map->xAxis->pixelToCoord(mevent->pos().x());
            y= ui->u_map->yAxis->pixelToCoord(mevent->pos().y());
            ui->u_map->xAxis->scaleRange(0.9,x);
            ui->u_map->yAxis->scaleRange(0.9,y);
        }else if(i_flag)
        {
            x= ui->i_map->xAxis->pixelToCoord(mevent->pos().x());
            y= ui->i_map->yAxis->pixelToCoord(mevent->pos().y());
            ui->i_map->xAxis->scaleRange(0.9,x);
            ui->i_map->yAxis->scaleRange(0.9,y);
        }
        reset_ticker();
        break;
    case 6:
        if(u_flag)
        {
            x= ui->u_map->xAxis->pixelToCoord(mevent->pos().x());
            y= ui->u_map->yAxis->pixelToCoord(mevent->pos().y());
            qDebug()<<x<<y;
            ui->u_map->xAxis->scaleRange(1.1,x);
            ui->u_map->yAxis->scaleRange(1.1,y);
        }else if(i_flag)
        {
            x= ui->i_map->xAxis->pixelToCoord(mevent->pos().x());
            y= ui->i_map->yAxis->pixelToCoord(mevent->pos().y());
            ui->i_map->xAxis->scaleRange(1.1,x);
            ui->i_map->yAxis->scaleRange(1.1,y);
        }
        reset_ticker();
        break;
    case 7:
        if(u_flag)
        {
            x= ui->u_map->xAxis->pixelToCoord(mevent->pos().x());
            ui->u_map->xAxis->scaleRange(0.9,x);
        }else if(i_flag)
        {
            x= ui->i_map->xAxis->pixelToCoord(mevent->pos().x());
            ui->i_map->xAxis->scaleRange(0.9,x);
        }
        reset_ticker();
        break;
    case 8:
        if(u_flag)
        {
            x= ui->u_map->xAxis->pixelToCoord(mevent->pos().x());
            ui->u_map->xAxis->scaleRange(1.1,x);
        }else if(i_flag)
        {
            x= ui->i_map->xAxis->pixelToCoord(mevent->pos().x());
            ui->i_map->xAxis->scaleRange(1.1,x);
        }
        reset_ticker();
        break;
    case 9:
        if(u_flag)
        {
            y= ui->u_map->yAxis->pixelToCoord(mevent->pos().y());
            ui->u_map->yAxis->scaleRange(0.9,y);
        }else if(i_flag)
        {
            y= ui->i_map->yAxis->pixelToCoord(mevent->pos().y());
            ui->i_map->yAxis->scaleRange(0.9,y);
        }
        break;
    case 10:
        if(u_flag)
        {
            y= ui->u_map->yAxis->pixelToCoord(mevent->pos().y());
            ui->u_map->yAxis->scaleRange(1.1,y);
        }else if(i_flag)
        {
            y= ui->i_map->yAxis->pixelToCoord(mevent->pos().y());
            ui->i_map->yAxis->scaleRange(1.1,y);
        }
        break;
    default:
        break;
    }
    if(u_flag)
    {
        u_flag=false;
        u_rubber->hide();
        ui->u_map->replot();
    }
    if(i_flag)
    {
        i_flag=false;
        i_rubber->hide();
        ui->i_map->replot();
    }
}
void reout_wave::m_move(){type=1;}
void reout_wave::m_sq(){type=2;}
void reout_wave::m_all_up(){type=6;}
void reout_wave::m_all_down(){type=5;}
void reout_wave::m_sq_x(){type=3;}
void reout_wave::m_x_up(){type=8;}
void reout_wave::m_x_down(){type=7;}
void reout_wave::m_sq_y(){type=4;}
void reout_wave::m_y_up(){type=10;}
void reout_wave::m_y_down(){type=9;}
void reout_wave::u_press(QMouseEvent*mevent)
{
    u_flag=true;
    mousePress(mevent);
}
void reout_wave::i_press(QMouseEvent*mevent)
{
    i_flag=true;
    mousePress(mevent);
}
void reout_wave::m_replot()
{
    int start=(int)ui->u_map->xAxis->range().lower;;
    int end=(int)ui->u_map->xAxis->range().upper;
    if(start<0)
        start=0;
    if(end>wave_point_count)
        end=wave_point_count;
    if((end-start)<1)
    {
        QMessageBox::information(this,"警告","开始点不能大于或等于结束点!");
        return;
    }
    int pipe=ui->ua_pipe->value();
    if(pipe>pipe_count)
    {
        pipe=1;
        ui->ua_pipe->setValue(1);
    }
    double max=set_line_data(l_ua,pipe,start,end);
    double recv_value;
    pipe=ui->ub_pipe->value();
    if(pipe>pipe_count)
    {
        pipe=1;
        ui->ub_pipe->setValue(1);
    }
    recv_value=set_line_data(l_ub,pipe,start,end);
    if(recv_value>max)
        max=recv_value;

    pipe=ui->uc_pipe->value();
    if(pipe>pipe_count)
    {
        pipe=1;
        ui->uc_pipe->setValue(1);
    }
    recv_value=set_line_data(l_uc,pipe,start,end);
    if(recv_value>max)
        max=recv_value;
    ui->u_map->yAxis->setRange(0-max*1.2,max*1.2);
    max=0;

    pipe=ui->ia_pipe->value();
    if(pipe>pipe_count)
    {
        pipe=1;
        ui->ia_pipe->setValue(1);
    }
    recv_value=set_line_data(l_ia,pipe,start,end);
    if(recv_value>max)
        max=recv_value;
    pipe=ui->ib_pipe->value();
    if(pipe>pipe_count)
    {
        pipe=1;
        ui->ib_pipe->setValue(1);
    }
    recv_value=set_line_data(l_ib,pipe,start,end);
    if(recv_value>max)
        max=recv_value;
    pipe=ui->ic_pipe->value();
    if(pipe>pipe_count)
    {
        pipe=1;
        ui->ic_pipe->setValue(1);
    }
    recv_value=set_line_data(l_ic,pipe,start,end);
    if(recv_value>max)
        max=recv_value;
    ui->i_map->yAxis->setRange(0-max,max);
    on_mid_wave_clicked();
    ui->u_map->replot();
    ui->i_map->replot();
}
void reout_wave::reset_ticker()
{
    int start=0;
    int stop=0;
    int point=0;
    int step=0;
    QSharedPointer<QCPAxisTickerFixed> ticker(new QCPAxisTickerFixed);
    if(u_flag)
    {
        start=(int)ui->u_map->xAxis->range().lower;
        stop=(int)ui->u_map->xAxis->range().upper;
        qDebug()<<stop;
        point=stop-start;
        step=point/10;
        if(step<5)
            step=5;
        ticker->setTickStep(step);
        ui->u_map->xAxis->setTicker(ticker);
        ui->u_map->xAxis->setRange(start,stop);
        if(start<0||start>wave_point_count)
            start=0;
        if(stop>wave_point_count||stop==0)
            stop=wave_point_count;
        point=stop-start;
        ui->wave_lenth->setText(QString("%1").arg(point/max_freq));
    }else
    {
        start=(int)ui->i_map->xAxis->range().lower;
        stop=(int)ui->i_map->xAxis->range().upper;
        point=stop-start;
        step=point/10;
        if(step<5)
            step=5;
        ticker->setTickStep(step);
        ui->i_map->xAxis->setTicker(ticker);
        ui->i_map->xAxis->setRange(start,stop);
        if(start<0)
            start=0;
        if(stop>wave_point_count||stop==0)
            stop=wave_point_count;
        point=stop-start;
        ui->wave_lenth->setText(QString("%1").arg(point/max_freq));
    }
    ui->wave_start->setText(QString("%1").arg(start));
    ui->wave_end->setText(QString("%1").arg(stop));
}

void reout_wave::on_all_clicked()
{
    ui->ua_flag->setChecked(ui->all->isChecked());
    ui->ub_flag->setChecked(ui->all->isChecked());
    ui->uc_flag->setChecked(ui->all->isChecked());
    ui->ia_flag->setChecked(ui->all->isChecked());
    ui->ib_flag->setChecked(ui->all->isChecked());
    ui->ic_flag->setChecked(ui->all->isChecked());
}
double reout_wave::get_max(double * data,double start,double end)
{
    double m_max=*(data+(int)start);
    double temp;
    for(int i=start+1;i<end;i++)
    {
        temp=*(data+i);
        temp>m_max?m_max=temp:temp;
    }
    return m_max;
}
