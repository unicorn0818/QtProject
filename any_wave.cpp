#include "any_wave.h"
#include "ui_any_wave.h"

Any_wave::Any_wave(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Any_wave)
{
    ui->setupUi(this);
    QVector <QString> list;
    list<<"内部触发输出"<<"外部触发输入"<<"启动立刻输出"<<"周波触发脉冲输出"<<"同步跟踪模式"<<"电能累计同步信号输出";
    ui->tig_model->set_items(list);
    ui->tig_model->setValue(2);
    list.clear();
    ui->byte_length->setValidator(new QRegExpValidator(QRegExp("^\\d+$"), this));
    list<<"UA"<<"IA"<<"UB"<<"IB"<<"UC"<<"IC";
    ui->phase->set_items(list);
    ui->hrenter_data->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->point_data->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    for(int i=0;i<10;i++)
    {
        ui->point_data->insertRow(i);
        ui->point_data->setItem(i,0,new QTableWidgetItem("0"));
        ui->point_data->setItem(i,1,new QTableWidgetItem("0"));
    }
    connect(ui->point_data->verticalScrollBar(),SIGNAL(valueChanged(int)),this,SLOT(add_item(int )));
    connect(ui->printf_map,SIGNAL(mousePress(QMouseEvent*)),this,SLOT(mousePress(QMouseEvent*)));
    connect(L_XL803,SIGNAL(send_to_any_wave(QByteArray,QByteArray)),this,SLOT(recv_mesg(QByteArray,QByteArray)));
    for(int i=0;i<22;i++)
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
        }
    }
    ui->base_value->setValue(50);
    ui->freq->setValue(50);
    xl609->set_map(ui->bar_map);
    xl609->set_map(ui->wave_map);
    xl609->set_map(ui->printf_map);
    xl609->set_map(ui->show_wave);
    bar=new QCPBars(ui->bar_map->xAxis, ui->bar_map->yAxis);
    ui->printf_map->setInteractions(QCP::iSelectPlottables);
    QSharedPointer<QCPAxisTickerFixed> ticker(new QCPAxisTickerFixed);
    ticker->setTickStep(0.001);
    ui->wave_map->xAxis->setTicker(ticker);
    ui->printf_map->xAxis->setTicker(ticker);
    ui->show_wave->xAxis->setTicker(ticker);
    QSharedPointer<QCPAxisTickerFixed> ticker1(new QCPAxisTickerFixed);
    ticker1->setTickStep(5);
    ticker1->setTickCount(129);
    ui->bar_map->xAxis->setTicker(ticker1);
    ui->wave_map->xAxis->setSubTickLength(1);
    line=ui->printf_map->addGraph();
    line2=ui->wave_map->addGraph();
    line3=ui->show_wave->addGraph();
    line->setPen(QPen(Qt::yellow,1));
    line2->setPen(QPen(Qt::yellow,1));
    line3->setPen(QPen(Qt::yellow,1));
    ui->wave_map->xAxis->setRange(0,0.02);
    ui->bar_map->xAxis->setRange(0,129);
    ui->bar_map->yAxis->setRange(0,100);
    bar->setPen(QPen(QColor(150, 150, 150)));
    bar->setBrush(QBrush(Qt::yellow));
    ui->change_data->tabBar()->hide();
    ui->change_map->tabBar()->hide();
    ui->printf_map->xAxis->setRange(0,1.0/50);
    ui->printf_map->replot();
    ui->sampling->setSuffix("K");
    ui->sampling->setValue(200);
    point_count=0;
    xl609=L_XL803;
    show=false;
    max_value=0;
    ui->tran->hide();
    init=true;
    ui->hrenter_data->item(0,0)->setText("100");
    wave_data.clear();
    start_down=false;
    one_wave.clear();
    ui->all_byte->setText("0");
    ui->now_byte->setText("0");
    ui->byte_length->setText("5000");
    dialog=new  QProgressDialog(tr("波形下载进度"), tr("取消"), 0, 1, this);
    dialog->setWindowTitle(tr("波形下载"));
    dialog->setWindowModality(Qt::WindowModal);
    dialog->setValue(1);
    ui->state1->set_value(0);
    ui->state2->set_value(1);
    ui->state3->set_value(2);
    mouse_flag=0;
    cell_flag=false;
    ui->tig_model->hide();
    ui->label_9->hide();
    ui->out_model->setSpecialValueText("重复输出");
}

Any_wave::~Any_wave()
{
    delete ui;
}

void Any_wave::on_print_map_clicked()
{
    if(ui->print_map->isChecked())
    {
        ui->change_data->setCurrentIndex(1);
        ui->change_map->setCurrentIndex(1);
    }else
    {
        ui->change_data->setCurrentIndex(0);
        ui->change_map->setCurrentIndex(0);
    }
}
XL803::MARKERB Any_wave::get_wt()
{
    switch (ui->phase->value()) {
    case 0:
        return XL803::MARKERB_WT_UA;
    case 1:
        return XL803::MARKERB_WT_IA;
    case 2:
        return XL803::MARKERB_WT_UB;
    case 3:
        return XL803::MARKERB_WT_IB;
    case 4:
        return XL803::MARKERB_WT_UC;
    case 5:
        return XL803::MARKERB_WT_IC;
    default:
        return XL803::MARKERB_WT_UA;
    }
}
void Any_wave::on_point_data_cellChanged(int row, int column)
{
    if(init==false)
        return;
    if(cell_flag)
    {
        cell_flag=false;
        return;
    }
    if(mouse_flag!=0)
    {
        mouse_flag--;
        return;
    }
    if(row>point_count&&row!=0)
    {
        cell_flag=true;
        ui->point_data->item(row,column)->setText("0");
        if(line->dataCount()<1)
            QMessageBox::information(this,"提示","请依次输入，中间不要有空行。");
        return;
    }
    float p_now=ui->point_data->item(row,column)->text().toFloat();
    qDebug()<<row<<point_count;
    if(row+1>point_count)
    {
        qDebug()<<"0";
        if(line->dataCount()>0)
        {
            cell_flag=true;
            ui->point_data->item(row,column)->setText("0");
            return;
        }
        XL803::M_point now_point;
        if(column==0)
        {
            now_point.x=p_now;
        }else
        {
            now_point.y=p_now;
        }
        if(m_point.count()<1)
        {
            XL803::M_point start_point;
            start_point.x=0;
            start_point.y=0;
            m_point<<start_point;

        }
        m_point<<now_point;
        point<<new QCPItemEllipse(ui->printf_map);
        point[row]->setPen(QPen(Qt::red,1));
        point_count++;
    }else
    {
        qDebug()<<"1";
        if(column==0)
        {
            m_point[row+1].x=p_now;
        }else
        {
            m_point[row+1].y=p_now;
        }
    }
    point[row]->topLeft->setCoords(m_point[row+1].x,m_point[row+1].y);
    point[row]->bottomRight->setCoords(m_point[row+1].x+ui->printf_map->xAxis->range().size()/200,\
                                        m_point[row+1].y-ui->printf_map->yAxis->range().size()/60);
    ui->printf_map->replot();
    show=false;
}
void Any_wave::add_item(int index)
{
    if(ui->point_data->verticalScrollBar()->maximum()==index)
    {
        mouse_flag+=2;
        ui->point_data->insertRow(ui->point_data->rowCount());
        ui->point_data->setItem(ui->point_data->rowCount()-1,0,new QTableWidgetItem("0"));
        ui->point_data->setItem(ui->point_data->rowCount()-1,1,new QTableWidgetItem("0"));
    }
}

void Any_wave::on_freq_valueChanged(double arg1)
{
    if(init!=true)
        return;
    ui->wave_map->xAxis->setRange(0,1/arg1);
    QSharedPointer<QCPAxisTickerFixed> ticker(new QCPAxisTickerFixed);
    ticker->setTickStep(1/arg1/10);
    ui->wave_map->xAxis->setTicker(ticker);
    on_priview_clicked();
    ui->wave_map->replot();
}
void Any_wave::mousePress(QMouseEvent* mevent)
{
    if(show&&m_point.count()-point.count()==2)
    {
        m_point.removeLast();
    }
    double x=0;
    double y=0;
    QCPItemEllipse * pp=new QCPItemEllipse(ui->printf_map);
    if(mevent->button() == Qt::LeftButton)
    {
        x= ui->printf_map->xAxis->pixelToCoord(mevent->pos().x());
        y= ui->printf_map->yAxis->pixelToCoord(mevent->pos().y());
        if(max_value<qAbs(y))
            max_value=y;
        if(point_count>=ui->point_data->rowCount())
        {
            mouse_flag+=2;
            ui->point_data->insertRow(point_count);
            ui->point_data->setItem(ui->point_data->rowCount()-1,0,new QTableWidgetItem("0"));
            ui->point_data->setItem(ui->point_data->rowCount()-1,1,new QTableWidgetItem("0"));
        }
        XL803::M_point now_point;
        now_point.x=x;
        now_point.y=y;
        if(m_point.count()<1)
        {
            XL803::M_point start_point;
            start_point.x=0;
            start_point.y=0;
            m_point<<start_point;
        }
        if(point_count>0&&x<ui->point_data->item(point_count-1,0)->text().toFloat())
        {
            for(int i=0;i<point_count;i++)
            {
                if(x<ui->point_data->item(i,0)->text().toFloat())
                {
                    mouse_flag+=2;
                    ui->point_data->insertRow(i);
                    ui->point_data->setItem(i,0,new QTableWidgetItem(QString("%1").arg(x)));
                    ui->point_data->setItem(i,1,new QTableWidgetItem(QString("%1").arg(y)));
                    m_point.insert(i+1,now_point);
                    point.insert(i,pp);
                    break;
                }
            }
        }else
        {
            mouse_flag+=2;
            ui->point_data->item(point_count,0)->setText(QString("%1").arg(x));
            ui->point_data->item(point_count,1)->setText(QString("%1").arg(y));
            m_point<<now_point;
            point<<pp;
        }
        pp->topLeft->setCoords(x,y);
        pp->setPen(QPen(Qt::red,1));
        pp->bottomRight->setCoords(x+ui->printf_map->xAxis->range().size()/200,\
                                             y-ui->printf_map->yAxis->range().size()/60);
        point_count++;
        show=false;
        ui->printf_map->replot();
    }
}

void Any_wave::on_back_point_clicked()
{
    if(point.count()>1)
    {
        mouse_flag+=2;
        ui->point_data->item(point.count()-1,0)->setText("0");
        ui->point_data->item(point.count()-1,1)->setText("0");
        m_point.removeLast();
        point_count--;
        if(show)
        {
            m_point.removeLast();
        }
        show=false;
        on_smooth_wave_clicked();
        ui->printf_map->removeItem(point.takeLast());
        ui->printf_map->replot();
    }else
    {
        on_clear_clicked();
    }
}

void Any_wave::on_smooth_wave_clicked()
{
    //插值，dataIn输入数据，inSize输入数据点数，simpIn输入数据采样率，simpOut需要输出的采样率，outSize输出的采样数据点数，maxValue采样点最大值。
    if(show||m_point.count()==0)
        return;
    QVector<double> x;
    QVector<double> y;
    XL803::M_point end_point;
    out_point.clear();
    end_point.x=ui->printf_map->xAxis->range().size();
    end_point.y=0;
    m_point<<end_point;
    //xl609->createCurve(m_point,m_point.count(),out_point);
    xl609->sin_insert(m_point,out_point,8000);
    for(int i=0;i<out_point.count();i++)
    {
        x<<out_point.at(i).x;
        y<<out_point.at(i).y;
    }
    line->setData(x,y);
    ui->printf_map->replot();
    show=true;
}

void Any_wave::on_clear_clicked()
{
    disconnect(ui->point_data,SIGNAL(cellChanged(int,int)),this,SLOT(on_point_data_cellChanged(int,int)));
    if(ui->change_data->currentIndex())
    {
        m_point.clear();
        out_point.clear();
        point_count=0;
        for(int i=0;i<point.count();i++)
        {
            ui->printf_map->removeItem(point[i]);
        }
        QVector<double> x,y;
        line->setData(x,y);
        ui->printf_map->replot();
        for(int i=0;i<point.count();i++)
        {
            ui->point_data->item(i,0)->setText("0");
            ui->point_data->item(i,1)->setText("0");
        }
        point.clear();
        max_value=0;
        show=false;
    }else
    {
        init=false;
        for(int i=1;i<ui->hrenter_data->rowCount();i++)
        {
                ui->hrenter_data->item(i,0)->setText("0");
                ui->hrenter_data->item(i,1)->setText("0");
        }
        init=true;
        ui->hrenter_data->item(0,0)->setText("100");
        QVector<double> x,y;
        line2->setData(x,y);
        bar->setData(x,y);
        ui->bar_map->replot();
        ui->wave_map->replot();
        set_rms();
    }
    connect(ui->point_data,SIGNAL(cellChanged(int,int)),this,SLOT(on_point_data_cellChanged(int,int)));
}

void Any_wave::on_priview_clicked()
{
    QVector<double> radio;
    QVector<double> num;
    QVector<double> phase;
    QVector<double> data,index;
    float value;
    float max=0;
    for(int i=0;i<ui->hrenter_data->rowCount();i++)
    {
        if(ui->hrenter_data->item(i,0)->text().toDouble()>0)
        {
            radio<<ui->hrenter_data->item(i,0)->text().toDouble();
            num<<i+1;
            phase<<(ui->hrenter_data->item(i,2)->text().toDouble()-ui->hrenter_data->item(0,2)->text().toDouble()/180);
        }
    }
    int send_count=ui->sampling->value()*1000/ui->freq->value();
    float step=ui->wave_map->xAxis->range().size()/send_count;

    float i=0;
    for(double ii=0;ii<send_count-1;ii++)
    {
        index<<(i+=step);
        value=0;
        value=ui->base_value->value()*qSin(2*M_PI*ui->freq->value()*i)*(1+ui->ratio->text().toFloat()/100);
        for(int j=1;j<radio.count();j++)
        {
            value+=radio[j]/100*ui->base_value->value()*qSin(num[j]*2*M_PI*ui->freq->value()*i+phase[j]);
        }
        max>value?:max=value;
        data<<value;
    }
    bar->setData(num,radio);
    ui->wave_map->yAxis->setRange(0-max*1.2,max*1.2);
    line2->setData(index,data);
    ui->wave_map->replot();
    ui->bar_map->replot();
}

void Any_wave::on_hrenter_data_cellChanged(int row, int column)
{
    if(init!=true)
        return;
    if(column==0)
    {
        float data=ui->hrenter_data->item(row,column)->text().toFloat()/100*ui->base_value->value();
        ui->hrenter_data->item(row,1)->setText(QString("%1").arg(data));
        set_thd();
        set_rms();
    }
}
void Any_wave::set_rms()
{
    float data=0;
    float radio=0;
    if(ui->base_value->value()!=0)
    {
        for(int i=0;i<ui->hrenter_data->rowCount();i++)
        {
            radio=ui->hrenter_data->item(i,1)->text().toFloat();
            if(radio!=0)
            {
                data+=(radio*radio);
            }
        }
    }else
    {
        ui->rms->setText("0");
    }
     ui->rms->setText(QString("%1").arg(sqrt(0.5*data)));
}
void Any_wave::set_thd()
{
    float data=0;
    float radio=0;
    for(int i=1;i<ui->hrenter_data->rowCount();i++)
    {
        radio=ui->hrenter_data->item(i,0)->text().toFloat();
        data+=radio*radio;
    }
    ui->thd->setText(QString("%1").arg(sqrt(data)));
}

void Any_wave::on_base_value_valueChanged(double arg1)
{
    ui->printf_map->yAxis->setRange(0-arg1,arg1);
    ui->printf_map->replot();
}

void Any_wave::on_save_data_clicked()
{
    int send_point=ui->sampling->value()*1000*ui->printf_map->xAxis->range().size();
    QVector<quint16> toSendData;
    float tempValue;
    float value;
    if(ui->change_data->currentIndex())
    {
        for(int i=0;i<out_point.count();i++)
        {
            value=out_point[i].y;
            if(value<0)
                value=0-value;
            if(max_value<value)
                max_value=value;
        }
        if(send_point<out_point.count())
        {
            for(int i=0;i<send_point;i++)
            {
                //比例转换,
                tempValue = (out_point[out_point.count()/send_point*i].y / max_value) *(float) 32767.0;
                toSendData<< (quint16)((tempValue>0)?(tempValue+0.5):(tempValue-0.5));		//减小量化误差
                //toSendData<<tempValue;
            }
        }else
        {

        }
    }else
    {
        for(int i=0;i<line2->dataCount();i++)
        {
            value= line2->data()->at(i)->value;
            if(value<0)
                value=0-value;
            if(max_value<value)
                max_value=value;
        }
        for(int i=0;i<line2->dataCount();i++)
        {
            //比例转换,
            tempValue = ( line2->data()->at(i)->value/ max_value) *(float) 32767.0;
            toSendData<< (quint16)((tempValue>0)?(tempValue+0.5):(tempValue-0.5));		//减小量化误差
        }
    }
    QString file_name = QFileDialog::getSaveFileName(NULL,"标题","./","*.daw");
    QFile file(file_name);
    if (!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::information(this," ","保存失败!");
        return;
    }
    QDataStream out(&file);
    quint32 byte=(quint32)ui->sampling->value()*1000;
    for(int i=0;i<4;i++)
    {
        out<<*((quint8 *)(&byte)+i);
    }
    for(int i=0;i<4;i++)
    {
        out<<*((quint8 *)(&max_value)+i);
    }
    for(int i=0;i<toSendData.count();i++)
    {
        out<<*((quint8 *)(&toSendData[i]));
        out<<*((quint8 *)(&toSendData[i])+1);
    }
    file.close();
}

void Any_wave::on_down_wave_clicked()
{
    wave_data.clear();
    QString file_name = QFileDialog::getOpenFileName(NULL,"波形文件","./","*.daw");
    QFile file(file_name);

    if (!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(this," ","打开失败!");
        return;
    }
    QDataStream in(&file);
    quint8 byte;
    while(!in.atEnd())
    {
        in>>byte;
        wave_data.append(byte);
    }
    file.close();
    quint32 byte_freq=*((quint32 *)wave_data.data());
    ui->sampling->setValue(byte_freq/1000);
    quint8 pipe=0;
    get_pipe(pipe);
    on_set_clicked();
    show_wave(wave_data);
    wave_data.remove(0,8);
    xl609->last_control=1;
    xl609->start_down_simpdata(wave_data.length(),byte_freq,ui->byte_length->text().toInt(),pipe,1,XL803::ANY_WAVE);
}

void Any_wave::on_ratio_textChanged(const QString &arg1)
{
    on_priview_clicked();
}

void Any_wave::recv_mesg(QByteArray send,QByteArray read)
{
    quint8 null=0;
    if(start_down)
    {
        if((quint8)read[5]==0x10)
        {
            if(ui->now_byte->text().toShort()==(ui->all_byte->text().toShort()-1))
            {
                ui->all_byte->setText("0");
                ui->now_byte->setText("0");
                start_down=false;
                xl609->stop_down_simpdata(XL803::ANY_WAVE);
                ui->byte_length->setReadOnly(false);
                dialog->hide();
                wave_data.clear();
                one_wave.clear();
                check_byte=0;
                return;
            }
            dialog->setValue(dialog->value()+one_wave.length());
            wave_data.remove(0,one_wave.length());
            one_wave.clear();
            check_byte=0;
            for(int i=0;i<ui->byte_length->text().toInt();i++)
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
            ui->now_byte->setText(QString("%1").arg(ui->now_byte->text().toShort()+1));
        }
        xl609->down_simpdata(ui->now_byte->text().toShort(),one_wave,check_byte,XL803::ANY_WAVE);
    }else if((quint8)send[5]==0xB0)
    {
        if((quint8)read[5]!=0x10)
        {
            QMessageBox::information(this," ","写入应答错误!");
            return;
        }
        check_byte=0;
        dialog->show();
        dialog->setRange(0,ui->all_byte->text().toInt()*ui->byte_length->text().toInt());
        start_down=true;
        one_wave.clear();
        for(int i=0;i<ui->byte_length->text().toInt();i++)
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
        xl609->down_simpdata(ui->now_byte->text().toShort(),one_wave,check_byte,XL803::ANY_WAVE);
    }else if((quint8)send[5]==0xB2)
    {
        get_box()->set_value(1);
    }else if((quint8)send[5]==0xB3)
    {
        read.remove(0,6);
        quint32 freq=*((quint32 *)read.data());
        read.remove(0,4);
        max_time_lenth=(*((quint32 *)read.data()))/(float)freq;
        ui->time_lenth->setRange(0,max_time_lenth);
    }else if((quint8)send[5]==0xB4)
    {
        get_box()->set_value(2);
    }else if((quint8)send[5]==0xB5)
    {
        get_box()->set_value(0);
    }
}

void Any_wave::on_save_clicked()
{
    on_save_data_clicked();
}
XL803::MARKERB Any_wave::get_pipe(quint8 & pipe)
{
    switch (ui->phase->value()) {
    case 0:
        pipe=0;
        return XL803::MARKERB_WAVE_UA;
    case 1:
        pipe=1;
        return XL803::MARKERB_WAVE_IA;
    case 2:
        pipe=2;
        return XL803::MARKERB_WAVE_UB;
    case 3:
        pipe=3;
        return XL803::MARKERB_WAVE_IB;
    case 4:
        pipe=4;
        return XL803::MARKERB_WAVE_UC;
    case 5:
        pipe=5;
        return XL803::MARKERB_WAVE_IC;
    default:
        break;
    }
}

void Any_wave::on_set_clicked()
{
    quint8 pipe=0;
    QMap<XL803::MARKERB, qint32> max_type;
    max_type.insert(get_pipe(pipe),xl609->float_to_quint(ui->base_value->value()));
    max_type.insert(get_wt(),(qint32)4);
    max_type.insert(XL803::TRIGE_TYPE,ui->tig_model->value());
    xl609->COM_HightWrite(max_type,XL803::ANY_WAVE);
}

void Any_wave::on_start_wave_clicked()
{
    quint8 pipe=0;
    get_pipe(pipe);
    QByteArray arry;
    arry.append(pipe);
    on_set_clicked();
    quint8 count=(quint8)ui->out_model->value();
    if(count==0)
        count=0xFF;
    xl609->output_simpdata_start(count,arry,XL803::ANY_WAVE);

}

void Any_wave::on_stop_wave_clicked()
{
    quint8 pipe=0;
    get_pipe(pipe);
    QByteArray arry;
    arry.append(pipe);
    xl609->output_simpdata_stop(arry,XL803::ANY_WAVE);
}

void  Any_wave::show_wave(QByteArray  data)
{
    ui->byte_length->setReadOnly(true);
    ui->change_map->setCurrentIndex(2);
    quint32 sampling=*((quint32 *)data.data());
    int  all_byte;
    all_byte=qCeil(data.count()/ui->byte_length->text().toFloat());
    ui->all_byte->setText(QString("%1").arg(all_byte));
    data.remove(0,4);
    float max_value=*((float *)data.data());
    ui->base_value->setValue(max_value);
    data.remove(0,4);
    float p_num=data.count()/2;
    float step=1.0/sampling;
    float index=0;
    QVector<double> x,y;
    ui->show_wave->xAxis->setRange(0,p_num/sampling+0.0001);
    QSharedPointer<QCPAxisTickerFixed> ticker(new QCPAxisTickerFixed);
    ticker->setTickStep((p_num/sampling+0.0001)/10);
    ui->show_wave->xAxis->setTicker(ticker);
    ui->show_wave->yAxis->setRange(0-max_value*1.2,max_value*1.2);
    for(int i=0;i<p_num;i++)
    {
        x<<index;
        y<<*(qint16 *)data.data()/32767.0*max_value;
        data.remove(0,2);
        index+=step;
    }
    line3->setData(x,y);
    ui->show_wave->replot();
}
m_checkbox *Any_wave::get_box()
{
    switch (ui->phase->value()) {
    case 0:
        return ui->ua_state;
    case 1:
        return ui->ia_state;
    case 2:
        return ui->ub_state;
    case 3:
        return ui->ib_state;
    case 4:
        return ui->uc_state;
    case 5:
        return ui->ic_state;
    default:
        return ui->ua_state;
    }
}

void Any_wave::on_sampling_valueChanged(double arg1)
{
    if(init!=true)
        return;
    //ui->time_lenth->setRange(0,max_time_lenth);
}

void Any_wave::on_time_lenth_valueChanged(double arg1)
{
    if(arg1==0)
        return;
    QSharedPointer<QCPAxisTickerFixed> ticker(new QCPAxisTickerFixed);
    ticker->setTickStep(arg1/20);
    ui->printf_map->xAxis->setTicker(ticker);
    ui->printf_map->xAxis->setRange(0,arg1);
    ui->printf_map->replot();
}
