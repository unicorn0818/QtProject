#include "list_out.h"
#include "ui_list_out.h"


UDataDelegate::UDataDelegate(QObject * parent):QItemDelegate(parent)
{
}
QWidget * UDataDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index)const
{
    QDoubleSpinBox *d_box=new QDoubleSpinBox(parent);
    switch(index.column())
    {
        case 0:
            d_box->setRange(0,MAX_U_SIZE);
            d_box->setSingleStep(0.05);
            d_box->setSuffix("V");
            break;
        case 1:
            d_box->setRange(-360,360);
            break;
        case 2:
            d_box->setDecimals(3);
            d_box->setRange(40,65);
            d_box->setSingleStep(0.001);
            d_box->setSuffix("Hz");
            break;
        default:
            d_box->setRange(0,MAX_U_SIZE);
            d_box->setSingleStep(0.05);
            break;
    }
        return d_box;
}
void UDataDelegate::setEditorData(QWidget *editor, const QModelIndex &index)const
{
    QDoubleSpinBox * d_box;
    double value;
    value = index.model()->data(index, Qt::EditRole).toDouble();
    d_box = static_cast<QDoubleSpinBox*>(editor);
    d_box->setValue(value);

}
void UDataDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QComboBox * box;
    QDoubleSpinBox * d_box;
    d_box=static_cast<QDoubleSpinBox *> (editor);
    model->setData(index, d_box->value(), Qt::EditRole);
    emit editd(index,d_box->value());
}

void UDataDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index)const
{
    editor->setGeometry(option.rect);
}
UDataDelegate::~UDataDelegate()
{

}


UchDelegate::UchDelegate(QObject * parent):QItemDelegate(parent)
{
}
QWidget * UchDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index)const
{
    QDoubleSpinBox *d_box=new QDoubleSpinBox(parent);
    switch(index.column())
    {
        case 0:
            d_box->setRange(0,MAX_U_SIZE);
            d_box->setSingleStep(0.05);
            d_box->setSuffix("V");
            break;
        case 1:
            d_box->setRange(-MAX_U_SIZE,MAX_U_SIZE);
            d_box->setSingleStep(0.05);
            d_box->setSuffix("V");
            break;
        case 2:
            d_box->setRange(5,99999);
            d_box->setSuffix("s");
            break;
        default:
            d_box->setRange(0,MAX_U_SIZE);
            d_box->setSingleStep(0.05);
            d_box->setSuffix("V");
            break;
    }
        return d_box;
}
void UchDelegate::setEditorData(QWidget *editor, const QModelIndex &index)const
{
    QDoubleSpinBox * d_box;
    double value;
    value = index.model()->data(index, Qt::EditRole).toDouble();
    d_box = static_cast<QDoubleSpinBox*>(editor);
    d_box->setValue(value);

}
void UchDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QComboBox * box;
    QDoubleSpinBox * d_box;
    d_box=static_cast<QDoubleSpinBox *> (editor);
    model->setData(index, d_box->value(), Qt::EditRole);
    if(index.column()==2)
    {
        model->setData(model->index(0,2), d_box->value(), Qt::EditRole);
        model->setData(model->index(1,2), d_box->value(), Qt::EditRole);
        model->setData(model->index(2,2), d_box->value(), Qt::EditRole);
    }
    emit editd(index,d_box->value());
}
TimeDelegate::TimeDelegate(QObject * parent):QItemDelegate(parent)
{
}
//createEditor是双击item后创建什么控件
QWidget * TimeDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QLineEdit  * edit =new QLineEdit(parent);
    //        QRegExp rx("^(-?\\d+)(\\.\\d+)?$");
    //QRegExp rx("^((\\d{2}):){2}\\d{2}\\.\\d{3}$");
    return edit;
}
//setEditorData是显示控件后 设置里面的值，提供index 自己从model内提取数据
void TimeDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QLineEdit * edit;
    QString value;
    value = index.model()->data(index, Qt::EditRole).toString();
    edit = static_cast<QLineEdit*>(editor);
    edit->setText(value);
}
//setmodeldata是确定 （按下回车后）设置model的值，
void TimeDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QLineEdit * edit;
    edit=static_cast<QLineEdit *> (editor);
    QRegExp rx;
    if(index.column()==0)
    {
        rx=QRegExp("^(20|21|22|23|[0-1]\\d):[0-5]\\d:[0-5]\\d\\.\\d{3}$");
    }else
    {
        rx=QRegExp("^(-?\\d+)(\\.\\d+)?$");
    }
    if(rx.exactMatch(edit->text()))
    {
        model->setData(index, edit->text(), Qt::EditRole);
        emit editd(index,edit->text());
    }/*else
    {
        model->setData(index, last_text, Qt::EditRole);
    }
    */
}
void TimeDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}

TimeDelegate::~TimeDelegate(){}
void UchDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index)const
{
    editor->setGeometry(option.rect);
}
UchDelegate::~UchDelegate()
{

}
List_out::List_out(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::List_out)
{
    ui->setupUi(this);
    freq_model=new QStandardItemModel(this);
    u_model=new QStandardItemModel(this);
    u_change_model=new QStandardItemModel(this);
    QStringList label;
    label<<"时间(时:分:秒.毫秒)"<<"频率(Hz)";
    //ui->freq_view->setHeader(new QHeaderView(label));
    freq_model->setHorizontalHeaderLabels(label);
    label.clear();
    label<<"电压幅值(V)"<<"相位"<<"频率(Hz)";
    u_model->setHorizontalHeaderLabels(label);
    label.clear();
    label<<"最终电压(V)"<<"调压幅值(V)"<<"间隔时间(s)";
    u_change_model->setHorizontalHeaderLabels(label);
    label.clear();
    label<<"UA"<<"UB"<<"UC"<<"UD";
    m_set=new PowerSet;
    u_change_model->setVerticalHeaderLabels(label);
    u_model->setVerticalHeaderLabels(label);
    ui->u_view->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->u_change_view->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->u_change_view->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->u_view->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    UDataDelegate* dele= new UDataDelegate(this);
    UchDelegate * dele_2=new UchDelegate(this);
    TimeDelegate * dele_3=new TimeDelegate(this);
    xl609=L_XL803;
    u_timer = new QTimer(this);
    u_init_timer= new QTimer(this);
    connect(u_timer, SIGNAL(timeout()), this, SLOT(change_u_time()));
    connect(xl609,SIGNAL(send_to_list_out(QByteArray,QByteArray)),this,SLOT(recv_mesg(QByteArray,QByteArray)),Qt::QueuedConnection);
    connect(dele_3,SIGNAL(editd(QModelIndex,QString)),this,SLOT(set_time(QModelIndex,QString)));
    connect(dele,SIGNAL(editd(QModelIndex,double)),this,SLOT(set_freq(QModelIndex,double)));
    ui->u_view->setItemDelegate(dele);
    ui->u_view->setModel(u_model);
    ui->freq_view->setModel(freq_model);
    ui->freq_view->setItemDelegate(dele_3);
    ui->u_change_view->setModel(u_change_model);
    ui->u_change_view->setItemDelegate(dele_2);
    ui->freq_view->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    freq_is_start=false;
    //ui->freq_view->horizontalHeader()->setStretchLastSection(true);
    //ui->freq_view->horizontalHeader()->setSectionResizeMode(0,QHeaderView::ResizeToContents);      //第1列宽100
    //ui->freq_view->header()->setSectionResizeMode(1,QHeaderView::Stretch);
    //ui->widget->hide();
    type=1;
    ui->tabWidget->tabBar()->hide();
    ui->tabWidget_2->tabBar()->hide();
    line=ui->freq_map->addGraph();
    line->setPen(QPen(Qt::yellow,1));
    l_ua=ui->value_map->addGraph();
    l_ub=ui->value_map->addGraph();
    l_uc=ui->value_map->addGraph();
    l_ud=ui->value_map->addGraph();
    l_ua->setPen(QPen(Qt::yellow,1));
    l_ub->setPen(QPen(Qt::green,1));
    l_uc->setPen(QPen(Qt::red,1));
    l_ud->setPen(QPen(Qt::blue,1));
    step_flag=false;
    end_flag=false;
    count_flag=false;
    down_flag=false;
    flush_over=false;
    edit_flag=true;
    old_ua=0;
    old_ub=0;
    old_uc=0;
    old_ud=0;
    for(int i=0;i<15;i++)
    {
        freq_model->setItem(i,0,new QStandardItem("--:--:--.-"));
        freq_model->setItem(i,1,new QStandardItem("0"));
        freq_model->item(i,0)->setEditable(false);
        freq_model->item(i,1)->setEditable(false);
    };
    for(int i=0;i<4;i++)
    {
        u_model->setItem(i,0,new QStandardItem("100"));
        if(i==0){
            u_model->setItem(i,1,new QStandardItem("0"));
        }else if(i==1){
            u_model->setItem(i,1,new QStandardItem("240"));
        }else if(i==2){
            u_model->setItem(i,1,new QStandardItem("120"));
        }else if(i==3){
            u_model->setItem(i,1,new QStandardItem("0"));
        }
        u_model->setItem(i,2,new QStandardItem("50"));
    };
    for(int i=0;i<4;i++)
    {
        u_change_model->setItem(i,0,new QStandardItem("500"));
        u_change_model->setItem(i,1,new QStandardItem("5"));
        u_change_model->setItem(i,2,new QStandardItem("5"));
    };
    data_index=0;
    byte_index=0;
    u_end=0;
    dialog=new  QProgressDialog(tr("数据传输中，请勿操作..."), tr("取消"), 0, 1, this);
    dialog->setWindowTitle(tr("频率下载"));
    dialog->setWindowModality(Qt::WindowModal);
    dialog->setValue(1);
    ui->stop_flag->set_value(2);
    xl609->set_map(ui->freq_map);
    xl609->set_map(ui->value_map);
    p_control=new map_control(this);
    p_control->hide();
    set_signal();
    u_rubber = new QRubberBand(QRubberBand::Rectangle, ui->freq_map);
    connect(ui->freq_map, SIGNAL(mousePress(QMouseEvent*)), this, SLOT(u_press(QMouseEvent*)));
    connect(ui->freq_map, SIGNAL(mouseMove(QMouseEvent*)), this, SLOT(mouseMove(QMouseEvent*)));
    connect(ui->freq_map, SIGNAL(mouseRelease(QMouseEvent*)), this, SLOT(mouseRelease(QMouseEvent*)));

    i_rubber = new QRubberBand(QRubberBand::Rectangle, ui->value_map);
    connect(ui->value_map, SIGNAL(mousePress(QMouseEvent*)), this, SLOT(i_press(QMouseEvent*)));
    connect(ui->value_map, SIGNAL(mouseMove(QMouseEvent*)), this, SLOT(mouseMove(QMouseEvent*)));
    connect(ui->value_map, SIGNAL(mouseRelease(QMouseEvent*)), this, SLOT(mouseRelease(QMouseEvent*)));
    connect(dialog,SIGNAL(canceled()),this,SLOT(cancel_down()));
    m_contextMenu = new QMenu;
    m_move_item = new QAction("拖动", this);
    m_move_item->setCheckable(true);
    m_reset_item = new QAction("重置", this);
    m_sq_item = new QAction("块选择", this);
    m_sq_item->setCheckable(true);
    m_sq_x_item= new QAction("块选X轴", this);
    m_sq_x_item->setCheckable(true);
    m_sq_y_item= new QAction("块选Y轴", this);
    m_sq_y_item->setCheckable(true);
    m_all_up_item= new QAction("同比放大", this);
    m_all_up_item->setCheckable(true);
    m_all_down_item= new QAction("同比缩小", this);
    m_all_down_item->setCheckable(true);
    m_x_up_item= new QAction("X轴放大", this);
    m_x_up_item->setCheckable(true);
    m_x_down_item= new QAction("X轴缩小", this);
    m_x_down_item->setCheckable(true);
    m_y_up_item= new QAction("Y轴放大", this);
    m_y_up_item->setCheckable(true);
    m_y_down_item= new QAction("Y轴缩小", this);
    m_y_down_item->setCheckable(true);
    group=new QActionGroup(this);
    group->addAction(m_move_item);
    group->addAction(m_reset_item);
    group->addAction(m_sq_item);
    group->addAction(m_sq_x_item);
    group->addAction(m_sq_y_item);
    group->addAction(m_all_up_item);
    group->addAction(m_all_down_item);
    group->addAction(m_x_up_item);
    group->addAction(m_x_down_item);
    group->addAction(m_y_up_item);
    group->addAction(m_y_down_item);
    m_contextMenu->addActions(group->actions());
    m_move_item->setChecked(true);
    //和该策略对应的信号，showListWidgetMenuSlot为自己定义的槽函数.
    connect(m_move_item,SIGNAL(triggered(bool)),this,SLOT(m_move()));
    connect(m_reset_item,SIGNAL(triggered(bool)),this,SLOT(m_reset()));
    connect(m_sq_item,SIGNAL(triggered(bool)),this,SLOT(m_sq()));
    connect(m_sq_x_item,SIGNAL(triggered(bool)),this,SLOT(m_sq_x()));
    connect(m_sq_y_item,SIGNAL(triggered(bool)),this,SLOT(m_sq_y()));
    connect(m_all_up_item,SIGNAL(triggered(bool)),this,SLOT(m_all_up()));
    connect(m_all_down_item,SIGNAL(triggered(bool)),this,SLOT(m_all_down()));
    connect(m_x_up_item,SIGNAL(triggered(bool)),this,SLOT(m_x_up()));
    connect(m_x_down_item,SIGNAL(triggered(bool)),this,SLOT(m_x_down()));
    connect(m_y_up_item,SIGNAL(triggered(bool)),this,SLOT(m_y_up()));
    connect(m_y_down_item,SIGNAL(triggered(bool)),this,SLOT(m_y_down()));

    connect(ui->gear,SIGNAL(currentIndexChanged(int)),this,SLOT(gear_Change(int)));
    ui->read_gear->hide();
}

List_out::~List_out()
{
    delete ui;
}

void List_out::on_u_view_clicked(QModelIndex index)
{
    if(edit_flag)
    {
        ui->u_view->edit(index);
    }
}

void List_out::on_in_file_clicked()
{
    QString file_name = QFileDialog::getOpenFileName(NULL,"波形文件","./","*.csv *.xlsx *.xls *.xlsm");
    QFile file(file_name);
    QString name=file_name;
//    QMessageBox * box= new QMessageBox(this);
//    box->setText("准备数据中，请勿进行其他操作。");
//    box->show();
    if (!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(this," ","打开失败!");
        return;
    }
    file.close();
    qDebug()<<name;
    for(;name.indexOf("/")>0;)
    {
        name.remove(0,name.indexOf("/")+1);
    }
    ui->file_name->setText(name);
    QString file_type=file_name;
    for(;file_type.indexOf('.')>=0;)
    {
        file_type.remove(0,file_type.indexOf('.')+1);
    }
    ui->state_mesg->setText("数据导入中...");
    qApp->processEvents();
    if(file_type.compare("csv")==0)
    {
        open_by_file(file_name);
    }else if(file_type.compare("xlsx")==0)
    {
        open_by_xlsx(file_name);
    }else
    {
        open_by_execl(file_name);
    }
}


void List_out::on_go_index_valueChanged(int arg1)
{

}
void List_out::recv_mesg(QByteArray last,QByteArray now)
{
    if((quint8)last.at(5)==0x7A&&down_flag)
    {
//        last.remove(0,14);
//        for(int i=0;last.length()>4;i++)
//        {
//            qDebug()<<xl609->quint_to_float(*((quint32 *)last.data()));
//            last.remove(0,4);
//        }
        if((quint8)now.at(5)==0x10)
        {
            dialog->setValue(data_index);
            if(data_index>=freq_vector.length())
            {
                data_index=0;
                byte_index=0;
                down_flag=false;
                flush_over=true;
                ui->state_mesg->setText("频率下载结束。");
            }else
            {
                freq_data.clear();
                float time=0;
                float b=0;
                for(int i=0;i<100;i++)
                {
                    if(data_index<freq_vector.length())
                    {
                        if(data_index<freq_vector.length()-1)
                        {
                            time=freq_vector.at(data_index).time.msecsTo(freq_vector.at(data_index+1).time);
                        }else
                        {
                            time=0;
                        }
                        freq_data.append((char *)&freq_vector[data_index].freq,sizeof(float));
                        freq_data.append((char *)&time,sizeof(float));
                        data_index++;
                    }else
                    {
                        freq_data.append((char *)&b,sizeof(float));
                        freq_data.append((char *)&b,sizeof(float));
                    }
                }
                xl609->write_freq_control_data(freq_data.length(),byte_index,freq_data,XL803::List_out);
                byte_index++;
            }
        }
    }else if((quint8)last.at(5)==0x03&&(quint8)now.at(5)==0x10)
    {
        last.remove(0,6);
        last.remove(last.length()-2,2);
        quint8 flag=0;
        for(;last.length()>2;)
        {
            flag=(quint8)last.at(0);
            switch (flag)
            {
                case XL803::MARKERB_SUA:
                    ui->ua_flag->set_value(2);
                    break;
                case XL803::MARKERB_SUB:
                    ui->ub_flag->set_value(2);
                    break;
                case XL803::MARKERB_SUC:
                    ui->uc_flag->set_value(2);
                    break;
                case XL803::MARKERB_SUD:
                    ui->ud_flag->set_value(2);
                    break;
            }
            last.remove(0,3);
        }
    }else if((quint8)last.at(5)==0x04&&(quint8)now.at(5)==0x10)
    {
        last.remove(0,6);
        last.remove(last.length()-2,2);
        quint8 flag=0;
        for(;last.length()>2;)
        {
            flag=(quint8)last.at(0);
            switch (flag)
            {
                case XL803::MARKERB_EUA:
                    ui->ua_flag->set_value(0);
                    ui->ua_value->clear();
                    break;
                case XL803::MARKERB_EUB:
                    ui->ub_flag->set_value(0);
                    ui->ub_value->clear();
                    break;
                case XL803::MARKERB_EUC:
                    ui->uc_flag->set_value(0);
                    ui->uc_value->clear();
                    break;
                case XL803::MARKERB_EUD:
                    ui->ud_flag->set_value(0);
                    ui->ud_value->clear();
                    break;
            }
            last.remove(0,3);
        }
    }else if((quint8)last.at(5)==0x7B&&(quint8)now.at(5)==0x10)
    {
        ui->state_mesg->setText("变频输出进行中...");
        ui->start_freq->setText("变频已启动");
        ui->start_change_u->setEnabled(false);
        freq_is_start=true;
        emit show_tab_bar(false);
    }else if((quint8)last.at(5)==0x7C)
    {
        QMessageBox::information(this,"提示","变频输出结束！");
        ui->state_mesg->setText("频率调制输出结束");
        emit show_tab_bar(true);
        freq_is_start=false;
        ui->start_freq->setText("启动变频");
        ui->start_change_u->setEnabled(true);
    }else if((quint8)now[5]==0xC0)
    {
        now.remove(0,6);
        now.remove(now.length()-2,2);
        memcpy(m_set,now.data(),sizeof(PowerSet));
        disconnect(ui->gear,SIGNAL(currentIndexChanged(int)),this,SLOT(gear_Change(int)));
        max_value.clear();
        if(ui->gear->count()>0)
            ui->gear->clear();
        ui->gear->addItem(QString("自动档"));
        for(int i=0;i<LEVELNUM;i++)
        {
            if(m_set->levelLimit[0][i]>0)
            {
                ui->gear->addItem(QString("%1档").arg(i));
                max_value<<m_set->levelLimit[0][i];
            }else
            {
                break;
            }
        }
        int m_i=ui->gear->currentIndex()-1;
        if(m_i<0)
        {
            ui->max_value->setText(QString("%1V").arg(max_value.last()));
        }else
        {
            ui->max_value->setText(QString("%1V").arg(max_value.at(m_i)));
        }
        connect(ui->gear,SIGNAL(currentIndexChanged(int)),this,SLOT(gear_Change(int)));
    }
}

void List_out::on_go_index_editingFinished()
{
    if(freq_vector.length()<1)
        return;
    int index=ui->go_index->value();
    QStringList label;
    for(int i=0;i<15;i++)
    {
        if((index-1)*15+i<freq_vector.length())
        {
            freq_model->item(i)->setText(freq_vector.at((index-1)*15+i).time.toString("hh:mm:ss.zzz"));
            freq_model->item(i,1)->setText(QString("%1").arg(freq_vector.at((index-1)*15+i).freq));
            label<<QString("%1").arg((index-1)*15+i+1);
            freq_model->item(i,0)->setEditable(true);
            freq_model->item(i,1)->setEditable(true);
        }else
        {
            freq_model->item(i)->setText("--:--:--.-");
            freq_model->item(i,1)->setText("0");
            label<<"-";
            freq_model->item(i,0)->setEditable(false);
            freq_model->item(i,1)->setEditable(false);
        }
    }
    freq_model->setVerticalHeaderLabels(label);
    ui->now_index->setText(QString("%1").arg(index));
    ui->all_index->setText(QString("%1").arg(qCeil((float)freq_vector.count()/15)));
    ui->go_index->setRange(1,qCeil((float)freq_vector.count()/15));
    ui->remove_start->setRange(1,freq_vector.length());
    ui->remove_end->setRange(ui->remove_start->value(),freq_vector.length());
}
void List_out::set_freq_data()
{
    int max_lenth=0;
    float time=0;
    freq_data.clear();
    if(freq_vector.length()>100)
    {
        max_lenth=100;
    }else
    {
        max_lenth=freq_vector.length();
    }
    for(int i=0;i<max_lenth;i++)
    {
        if(i<freq_vector.length()-1)
        {
            time=freq_vector.at(i).time.msecsTo(freq_vector.at(i+1).time);
            qDebug()<<"time:"<<time;
        }else
        {
            time=0;
        }
        data_index=i;
        freq_data.append((char *)&freq_vector[i].freq,sizeof(float));
        freq_data.append((char *)&time,sizeof(float));
    }
    data_index++;
    byte_index=1;
    dialog->setValue(data_index);
    qDebug()<<freq_data.length();
    xl609->write_freq_control_data(freq_data.length(),0,freq_data,XL803::List_out);
    down_flag=true;
}

void List_out::on_start_freq_clicked()
{
    if(MainWindow::connect_flag!=true)
    {
        QMessageBox *box = new QMessageBox(QMessageBox::Information,tr("提示"),tr("无连接，请检测通讯设置!"),0,this);
        QTimer::singleShot(1500,box,SLOT(accept()));
        box->exec();
        return;
    }
    if(ui->start_freq->text().compare("启动变频")==0)
    {
        if(u_start==false)
        {
            u_start=true;
        }
        if(freq_is_start)
        {
            QMessageBox *box = new QMessageBox(QMessageBox::Information,tr("提示"),tr("变频输出未结束！"),0,this);
            QTimer::singleShot(1500,box,SLOT(accept()));
            box->exec();
            return;
        }
        on_creat_line_data_clicked();
        ui->gear->setEnabled(false);
        QMap<XL803::MARKERB, qint32> data;
        QMap<XL803::MARKERB,qint32> ac;
        QStandardItem *item;
        float value=0;
        qint32 gear=(ui->gear->currentIndex()-1);
        if(gear<0)
            gear=0x55;
        data.insert(XL803::MARKERB_DUA,gear);
        data.insert(XL803::MARKERB_DUB,gear);
        data.insert(XL803::MARKERB_DUC,gear);
        data.insert(XL803::MARKERB_DUD,gear);

        data.insert(XL803::MARKERB_WT_UA,xl609->float_to_quint(value));
        item=u_model->item(0,0);
        value=item->data(Qt::EditRole).toFloat();
        ui->ua_value->setText(xl609->float_to_str(value));
        data.insert(XL803::MARKERB_UA,xl609->float_to_quint(value));
        item=u_model->item(0,1);
        data.insert(XL803::MARKERB_UAP,xl609->float_to_quint(item->data(Qt::EditRole).toFloat()));
        item=u_model->item(0,2);
        data.insert(XL803::MARKERB_FA,xl609->float_to_quint(item->data(Qt::EditRole).toFloat()));

        data.insert(XL803::MARKERB_WT_UB,xl609->float_to_quint(value));
        item=u_model->item(1,0);
        value=item->data(Qt::EditRole).toFloat();
        ui->ub_value->setText(xl609->float_to_str(value));
        data.insert(XL803::MARKERB_UB,xl609->float_to_quint(value));
        item=u_model->item(1,1);
        data.insert(XL803::MARKERB_UBP,xl609->float_to_quint(item->data(Qt::EditRole).toFloat()));
        item=u_model->item(0,2);
        data.insert(XL803::MARKERB_FB,xl609->float_to_quint(item->data(Qt::EditRole).toFloat()));

        data.insert(XL803::MARKERB_WT_UC,xl609->float_to_quint(value));
        item=u_model->item(2,0);
        value=item->data(Qt::EditRole).toFloat();
        ui->uc_value->setText(xl609->float_to_str(value));
        data.insert(XL803::MARKERB_UC,xl609->float_to_quint(value));
        item=u_model->item(2,1);
        data.insert(XL803::MARKERB_UCP,xl609->float_to_quint(item->data(Qt::EditRole).toFloat()));
        item=u_model->item(0,2);
        data.insert(XL803::MARKERB_FC,xl609->float_to_quint(item->data(Qt::EditRole).toFloat()));

        data.insert(XL803::MARKERB_WT_UD,xl609->float_to_quint(value));
        item=u_model->item(3,0);
        value=item->data(Qt::EditRole).toFloat();
        ui->ud_value->setText(xl609->float_to_str(value));
        data.insert(XL803::MARKERB_UD,xl609->float_to_quint(value));
        item=u_model->item(3,1);
        data.insert(XL803::MARKERB_UDP,xl609->float_to_quint(item->data(Qt::EditRole).toFloat()));
        item=u_model->item(0,2);
        data.insert(XL803::MARKERB_FD,xl609->float_to_quint(item->data(Qt::EditRole).toFloat()));

        if(ui->ua->isChecked()&&ui->ua_flag->get_value()!=2)
            ac.insert(XL803::MARKERB_SUA,0x01);
        if(ui->ub->isChecked()&&ui->ub_flag->get_value()!=2)
            ac.insert(XL803::MARKERB_SUB,0x01);
        if(ui->uc->isChecked()&&ui->uc_flag->get_value()!=2)
            ac.insert(XL803::MARKERB_SUC,0x01);
        if(ui->ud->isChecked()&&ui->ud_flag->get_value()!=2)
            ac.insert(XL803::MARKERB_SUD,0x01);
        if(ac.count()>0)
        {
            xl609->COM_HightWrite(data,XL803::List_out);
            xl609->COM_StartUp(ac,XL803::List_out);
        }
        send_start_freq();
    }else
    {
        QMessageBox::information(this,"提示","请先将数据下载到内存中。");
    }
}
void List_out::send_start_freq()
{
    xl609->start_freq_control(XL803::List_out);
}
void List_out::on_start_out_clicked()
{
    if(MainWindow::connect_flag!=true)
    {
        QMessageBox *box = new QMessageBox(QMessageBox::Information,tr("提示"),tr("无连接，请检测通讯设置!"),0,this);
        QTimer::singleShot(1500,box,SLOT(accept()));
        box->exec();
        return;
    }
    if(ui->start_out->text().compare("启动电压")==0)
    {
        edit_flag=false;
        u_start=true;
        ui->u_view->setEditTriggers(QAbstractItemView::NoEditTriggers);
        xl609->constraint_set_wave(XL803::List_out);
        ui->gear->setEnabled(false);
        init_u_data();
        xl609->last_contorl=0;
    }
}

void List_out::on_stop_out_clicked()
{
    emit show_tab_bar(true);
    if(MainWindow::connect_flag!=true)
    {
        QMessageBox *box = new QMessageBox(QMessageBox::Information,tr("提示"),tr("无连接，请检测通讯设置!"),0,this);
        QTimer::singleShot(1500,box,SLOT(accept()));
        box->exec();
        return;
    }
    QMap<XL803::MARKERB,qint32> ac;
    if(ui->ua->isChecked())
        ac.insert(XL803::MARKERB_EUA,0x01);
    if(ui->ub->isChecked())
        ac.insert(XL803::MARKERB_EUB,0x01);
    if(ui->uc->isChecked())
        ac.insert(XL803::MARKERB_EUC,0x01);
    if(ui->ud->isChecked())
        ac.insert(XL803::MARKERB_EUD,0x01);
    if(ac.count()>0)
        xl609->COM_Stop(ac,XL803::List_out);
    ui->gear->setEnabled(true);
    ui->start_change_u->setEnabled(true);
    ui->start_freq->setEnabled(true);
    ui->start_freq->setText("启动变频");
    ui->start_change_u->setText("启动变压");
    ui->ua_value->setText(0);
    ui->ub_value->setText(0);
    ui->uc_value->setText(0);
    ui->ud_value->setText(0);
    edit_flag=true;
    u_start=false;
    ui->u_view->setEditTriggers(QAbstractItemView::DoubleClicked\
                                |QAbstractItemView::EditKeyPressed\
                                |QAbstractItemView::AnyKeyPressed);
    ui->u_change_view->setEditTriggers(QAbstractItemView::DoubleClicked\
                                |QAbstractItemView::EditKeyPressed\
                                |QAbstractItemView::AnyKeyPressed);
    u_timer->stop();
}


void List_out::change_u_time()
{
    QMap<XL803::MARKERB,qint32> ac;
    if(ui->ua->isChecked())
        ac.insert(XL803::MARKERB_SUA,0x01);
    if(ui->ub->isChecked())
        ac.insert(XL803::MARKERB_SUB,0x01);
    if(ui->uc->isChecked())
        ac.insert(XL803::MARKERB_SUC,0x01);
    if(ui->ud->isChecked())
        ac.insert(XL803::MARKERB_SUD,0x01);
    if(ac.count()>0)
        xl609->COM_StartUp(ac,XL803::List_out);
    ui->ua_value->setText(xl609->float_to_str(old_ua));
    ui->ub_value->setText(xl609->float_to_str(old_ub));
    ui->uc_value->setText(xl609->float_to_str(old_uc));
    ui->ud_value->setText(xl609->float_to_str(old_ud));

//    if((old_ua+u_change_model->item(0,1)->data(Qt::EditRole).toFloat()<=u_change_model->item(0,0)->data(Qt::EditRole).toFloat())
//            &&(old_ub+u_change_model->item(1,1)->data(Qt::EditRole).toFloat()<=u_change_model->item(1,0)->data(Qt::EditRole).toFloat())
//            &&(old_uc+u_change_model->item(2,1)->data(Qt::EditRole).toFloat()<=u_change_model->item(2,0)->data(Qt::EditRole).toFloat()))
//    {

//        qDebug()<<"要出现bug了";
//        qDebug()<<"UA"<<old_ua+u_change_model->item(0,1)->data(Qt::EditRole).toFloat();
//        qDebug()<<"UB"<<old_ub+u_change_model->item(1,1)->data(Qt::EditRole).toFloat();
//        qDebug()<<"UC"<<old_uc+u_change_model->item(2,1)->data(Qt::EditRole).toFloat();
//    }

    if((old_ua==(u_change_model->item(0,0)->data(Qt::EditRole).toFloat())||old_ua==0)&&\
            (old_ud==(u_change_model->item(3,0)->data(Qt::EditRole).toFloat())||old_ud==0)&&\
        (old_ub==(u_change_model->item(1,0)->data(Qt::EditRole).toFloat())||old_ub==0)&&\
        (old_uc==(u_change_model->item(2,0)->data(Qt::EditRole).toFloat())||old_uc==0))
    {

        u_timer->stop();
        ui->u_view->setEditTriggers(QAbstractItemView::DoubleClicked\
                                    |QAbstractItemView::EditKeyPressed\
                                    |QAbstractItemView::AnyKeyPressed);
        ui->u_change_view->setEditTriggers(QAbstractItemView::DoubleClicked\
                                           |QAbstractItemView::EditKeyPressed\
                                           |QAbstractItemView::AnyKeyPressed);
        ui->start_change_u->setText("启动变压");
        ui->start_freq->setEnabled(true);
        ui->state_mesg->setText("变压完毕，电压输出不再变化。");
        emit show_tab_bar(true);
        QMessageBox::information(this,"提示","变压完毕!");
        return;
    }

    set_u_data();   
}
void  List_out::set_u_data()
{
    QMap<XL803::MARKERB, qint32> data;
    QStandardItem *item;
    float ua=0;
    float ub=0;
    float uc=0;
    float ud=0;
    float step=0;
    float end_value=0;
    if(ui->ua->isChecked())
    {
        ua=ui->ua_value->text().toFloat();
        if((u_change_model->item(0,0)->data(Qt::EditRole).toFloat()<u_model->item(0,0)->data(Qt::EditRole).toFloat())&&(ua-fabs(u_change_model->item(0,1)->data(Qt::EditRole).toFloat()))<=u_change_model->item(0,0)->data(Qt::EditRole).toFloat())
        {
            step =  (u_change_model->item(0,0)->data(Qt::EditRole).toFloat() - ua);
            step = -step;
        }
        else if((u_change_model->item(0,0)->data(Qt::EditRole).toFloat()<u_model->item(0,0)->data(Qt::EditRole).toFloat()))
        {
            step=fabs(u_change_model->item(0,1)->data(Qt::EditRole).toFloat());
            step = -step;
        }
        else
            step=fabs(u_change_model->item(0,1)->data(Qt::EditRole).toFloat());
        ua+=step;
        end_value=u_change_model->item(0,0)->data(Qt::EditRole).toFloat();
        if(step>0)
        {
            end_value<ua?ua=end_value:ua;
        }else
        {
            0>ua?ua=0:ua;
        }
        old_ua=ua;
        data.insert(XL803::MARKERB_UA,xl609->float_to_quint(ua));
    }
    if(ui->ub->isChecked())
    {
        ub=ui->ub_value->text().toFloat();

        if((u_change_model->item(1,0)->data(Qt::EditRole).toFloat()<u_model->item(1,0)->data(Qt::EditRole).toFloat())&&(ub-fabs(u_change_model->item(1,1)->data(Qt::EditRole).toFloat())<=u_change_model->item(1,0)->data(Qt::EditRole).toFloat()))
        {
            step = u_change_model->item(1,0)->data(Qt::EditRole).toFloat() - ub;
            step = -step;
        }
        else if((u_change_model->item(1,0)->data(Qt::EditRole).toFloat()<u_model->item(1,0)->data(Qt::EditRole).toFloat()))
        {
            step=fabs(u_change_model->item(1,1)->data(Qt::EditRole).toFloat());
            step = -step;
        }
        else
            step=fabs(u_change_model->item(1,1)->data(Qt::EditRole).toFloat());
        ub+=step;
        end_value=u_change_model->item(1,0)->data(Qt::EditRole).toFloat();
        if(step>0)
        {
            end_value<ub?ub=end_value:ub;
        }else
        {
            0>ub?ub=0:ub;
        }
        old_ub=ub;

        data.insert(XL803::MARKERB_UB,xl609->float_to_quint(ub));
    }
    if(ui->uc->isChecked())
    {
        uc=ui->uc_value->text().toFloat();

        if((u_change_model->item(2,0)->data(Qt::EditRole).toFloat()<u_model->item(2,0)->data(Qt::EditRole).toFloat())&&(uc-fabs(u_change_model->item(2,1)->data(Qt::EditRole).toFloat())<=u_change_model->item(2,0)->data(Qt::EditRole).toFloat()))
        {
            step = u_change_model->item(2,0)->data(Qt::EditRole).toFloat() - uc;
            step = -step;
        }
        else if((u_change_model->item(2,0)->data(Qt::EditRole).toFloat()<u_model->item(2,0)->data(Qt::EditRole).toFloat()))
        {
            step=fabs(u_change_model->item(2,1)->data(Qt::EditRole).toFloat());
            step = -step;
        }
        else
            step=fabs(u_change_model->item(2,1)->data(Qt::EditRole).toFloat());

        uc+=step;
        end_value=u_change_model->item(2,0)->data(Qt::EditRole).toFloat();
        if(step>0)
        {
            end_value<uc?uc=end_value:uc;
        }else
        {
            0>uc?uc=0:uc;
        }
        old_uc=uc;
        data.insert(XL803::MARKERB_UC,xl609->float_to_quint(uc));
    }
    if(ui->ud->isChecked())
    {
        ud=ui->ud_value->text().toFloat();
        if((u_change_model->item(3,0)->data(Qt::EditRole).toFloat()<u_model->item(3,0)->data(Qt::EditRole).toFloat())&&(ud-fabs(u_change_model->item(3,1)->data(Qt::EditRole).toFloat()))<=u_change_model->item(3,0)->data(Qt::EditRole).toFloat())
        {
            step =  (u_change_model->item(3,0)->data(Qt::EditRole).toFloat() - ud);
            step = -step;
        }
        else if((u_change_model->item(3,0)->data(Qt::EditRole).toFloat()<u_model->item(3,0)->data(Qt::EditRole).toFloat()))
        {
            step=fabs(u_change_model->item(3,1)->data(Qt::EditRole).toFloat());
            step = -step;
        }
        else
            step=fabs(u_change_model->item(3,1)->data(Qt::EditRole).toFloat());
        ud+=step;
        end_value=u_change_model->item(3,0)->data(Qt::EditRole).toFloat();
        if(step>0)
        {
            end_value<ud?ud=end_value:ud;
        }else
        {
            0>ud?ud=0:ud;
        }
        old_ud=ud;
        data.insert(XL803::MARKERB_UD,xl609->float_to_quint(ud));
    }
    if(data.count()>0)
        xl609->COM_HightWrite(data,XL803::List_out);
}
void List_out::init_u_data(bool flag)
{
    if(freq_is_start)
    {
        QMessageBox *box = new QMessageBox(QMessageBox::Information,tr("提示"),tr("变频输出未结束！"),0,this);
        QTimer::singleShot(1500,box,SLOT(accept()));
        box->exec();
        return;
    }
    QMap<XL803::MARKERB, qint32> data;
    QMap<XL803::MARKERB,qint32> ac;
    QStandardItem *item;
    float value=0;
    //档位
    qint32 gear=(ui->gear->currentIndex()-1);
    if(gear<0)
        gear=0x55;
    data.insert(XL803::MARKERB_DUA,gear);
    data.insert(XL803::MARKERB_DUB,gear);
    data.insert(XL803::MARKERB_DUC,gear);
    data.insert(XL803::MARKERB_DUD,gear);

    data.insert(XL803::MARKERB_WT_UA,xl609->float_to_quint(value));
    float freq=50;
    if(ui->freq_set->isChecked())
          freq=u_model->item(0,2)->data(Qt::EditRole).toFloat();
    item=u_model->item(0,0);
    value=item->data(Qt::EditRole).toFloat();
    ui->ua_value->setText(xl609->float_to_str(value));
    data.insert(XL803::MARKERB_UA,xl609->float_to_quint(value));
    item=u_model->item(0,1);
    data.insert(XL803::MARKERB_UAP,xl609->float_to_quint(item->data(Qt::EditRole).toFloat()));
    item=u_model->item(0,2);
    data.insert(XL803::MARKERB_FA,xl609->float_to_quint(freq));

    data.insert(XL803::MARKERB_WT_UB,xl609->float_to_quint(value));
    item=u_model->item(1,0);
    value=item->data(Qt::EditRole).toFloat();
    ui->ub_value->setText(xl609->float_to_str(value));
    data.insert(XL803::MARKERB_UB,xl609->float_to_quint(value));
    item=u_model->item(1,1);
    data.insert(XL803::MARKERB_UBP,xl609->float_to_quint(item->data(Qt::EditRole).toFloat()));
    item=u_model->item(1,2);
    if(ui->freq_set->isChecked())
        data.insert(XL803::MARKERB_FB,xl609->float_to_quint(freq));
    else
        data.insert(XL803::MARKERB_FB,xl609->float_to_quint(item->data(Qt::EditRole).toFloat()));

    data.insert(XL803::MARKERB_WT_UC,xl609->float_to_quint(value));
    item=u_model->item(2,0);
    value=item->data(Qt::EditRole).toFloat();
    ui->uc_value->setText(xl609->float_to_str(value));
    data.insert(XL803::MARKERB_UC,xl609->float_to_quint(value));
    item=u_model->item(2,1);
    data.insert(XL803::MARKERB_UCP,xl609->float_to_quint(item->data(Qt::EditRole).toFloat()));
    item=u_model->item(2,2);
    if(ui->freq_set->isChecked())
        data.insert(XL803::MARKERB_FC,xl609->float_to_quint(freq));
    else
        data.insert(XL803::MARKERB_FC,xl609->float_to_quint(item->data(Qt::EditRole).toFloat()));

    data.insert(XL803::MARKERB_WT_UD,xl609->float_to_quint(value));
    item=u_model->item(3,0);
    value=item->data(Qt::EditRole).toFloat();
    ui->ud_value->setText(xl609->float_to_str(value));
    data.insert(XL803::MARKERB_UD,xl609->float_to_quint(value));
    item=u_model->item(3,1);
    data.insert(XL803::MARKERB_UDP,xl609->float_to_quint(item->data(Qt::EditRole).toFloat()));
    item=u_model->item(3,2);
    if(ui->freq_set->isChecked())
        data.insert(XL803::MARKERB_FD,xl609->float_to_quint(freq));
    else
        data.insert(XL803::MARKERB_FD,xl609->float_to_quint(item->data(Qt::EditRole).toFloat()));

//    data.insert(XL803::MARKERB_FD,xl609->float_to_quint(freq));
    if(ui->ua->isChecked())
        ac.insert(XL803::MARKERB_SUA,0x01);
    if(ui->ub->isChecked())
        ac.insert(XL803::MARKERB_SUB,0x01);
    if(ui->uc->isChecked())
        ac.insert(XL803::MARKERB_SUC,0x01);
    if(ui->ud->isChecked())
        ac.insert(XL803::MARKERB_SUD,0x01);
    if(data.count()>0)
    {
        xl609->COM_HightWrite(data,XL803::List_out);
        xl609->COM_StartUp(ac,XL803::List_out);
    }
    if(flag)
    {
        set_u_data();
    }
}

void List_out::on_down_data_clicked()
{
    if(MainWindow::connect_flag!=true)
    {
        QMessageBox *box = new QMessageBox(QMessageBox::Information,tr("提示"),tr("无连接，请检测通讯设置!"),0,this);
        QTimer::singleShot(1500,box,SLOT(accept()));
        box->exec();
        return;
    }
    if(ui->start_freq->text().compare("变频已启动")==0)
    {
        QMessageBox *box = new QMessageBox(QMessageBox::Information,tr("提示"),tr("请于变频输出结束后下载数据。"),0,this);
        QTimer::singleShot(1500,box,SLOT(accept()));
        box->exec();
    }else if(freq_vector.length()>0)
    {
        dialog->setRange(0,freq_vector.length());
        ui->state_mesg->setText("频率数据下载中...");
        set_freq_data();
    }else
    {
        QMessageBox::information(this,"提示","请先导入频率文件.");
    }
}
void List_out::cancel_down()
{
    data_index=0;
    byte_index=0;
    down_flag=false;
}
void List_out::open_by_execl(QString file_name)
{
    QAxObject excel("Excel.Application");
    if(excel.isNull())
    {
        QMessageBox::information(this,"提示","无office组件.");
        return;
    }
    excel.setProperty("Visible", false); //隐藏打开的excel文件界面

    QAxObject *workbooks = excel.querySubObject("WorkBooks");
    QElapsedTimer timer;
    timer.start();
    QAxObject *workbook = workbooks->querySubObject("Open(QString, QVariant)", file_name); //打开文件
    qDebug()<<"open cost:"<<timer.elapsed()<<"ms";timer.restart();
    cell.clear();
    QAxObject *active_book = excel.querySubObject("ActiveWorkBook");//获取活动工作簿
    QAxObject *worksheets = active_book->querySubObject("WorkSheets");//获取所有的工作表
    int sheet_count = worksheets->property("Count").toInt();

    QAxObject * worksheet = workbook->querySubObject("WorkSheets(int)", 1); //访问第一个工作表
    QAxObject * usedrange = worksheet->querySubObject("UsedRange");
    QAxObject * rows = usedrange->querySubObject("Rows");
    QAxObject * colums = usedrange->querySubObject("Columns");
    int all_row = rows->property("Count").toInt(); //行数
    int all_colum = colums->property("Count").toInt(); //行数
    ui->all_index->setText(QString("%1").arg(qCeil((float)all_row/15)));
    ui->go_index->setRange(1,qCeil((float)all_row/15));
//    QString Range = "A1:B" +QString::number(all_row);
//    QAxObject *allEnvData = worksheet->querySubObject("Range(QString)", Range); //读取范围
//    QVariant allEnvDataQVariant = allEnvData->dynamicCall("Value");

    cell = usedrange->dynamicCall("Value");
    qDebug()<<"read data cost:"<<timer.elapsed()<<"ms";timer.restart();
    QString str;
    QDateTime  date_time;
    freq_value one_value;
    QVariant var;
    double sec=0;
    int sec_mid=0;
    freq_vector.clear();
    if(all_row>20000)
    {
        QMessageBox::information(this,"提示","仅支持2万条频率数据.");
        all_row=20000;
    }
    int num=0;
    int i=0;
    if(all_row>0)
    {
        if(cell.toList().at(0).toList().at(0).toDateTime().isNull())
        {
            i=1;
        }
    }

    for(;i<all_row;i++)
    {
        if(cell.toList().at(i).toList().at(1).isNull())
        {
            break;
        }
        sec=cell.toList().at(i).toList().at(1).toDouble();
        sec_mid=sec*100000;
        if(sec>((double)sec_mid/100000))
        {
            sec=((double)sec_mid/100000+0.00001);
        }
        var =cell.toList().at(i).toList().at(0).toDateTime().addSecs(sec*24*60*60)\
                .addMSecs(cell.toList().at(i).toList().at(2).toDouble());\
        date_time=var.toDateTime();
        str=date_time.toString("hh:mm:ss.zzz");
        if(num<15)
        {
            freq_model->item(num)->setText(str);
            freq_model->item(num,1)->setText(cell.toList().at(i).toList().at(3).toString());
            freq_model->item(num,0)->setEditable(true);
            freq_model->item(num,1)->setEditable(true);
            num++;
        }
        one_value.time=date_time;
        one_value.freq=cell.toList().at(i).toList().at(3).toFloat();
        freq_vector<<one_value;
    }
    qDebug()<<"show data cost:"<<timer.elapsed()<<"ms";timer.restart();
    workbooks->dynamicCall("Close()");
    excel.dynamicCall("Quit()");
    ui->state_mesg->setText("数据导入成功。");
    QMessageBox *box = new QMessageBox(QMessageBox::Information,tr("提示"),tr("导入完毕。"),0,this);
    QTimer::singleShot(1500,box,SLOT(accept()));
    box->exec();
    on_go_index_editingFinished();
}
void List_out::open_by_file(QString file_name)
{
    QFile file(file_name);
    if (!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(this," ","打开失败!");
        return;
    }
    QByteArray line;
    QString data;
    QString date;
    QString m_sec;
    int time_index;
    int count=0;
    QString freq;
    QDateTime  date_time;
    freq_value one_value;
    freq_vector.clear();
    int num=0;
    for(int i=0;!file.atEnd();i++)
    {
        line=file.readLine();
        data=QString(line.data());
        time_index=data.indexOf(',');
        data[time_index]=' ';
        time_index=data.indexOf(',');
        date=data.mid(0,time_index);
        data.remove(0,time_index+1);
        date+='.';
        time_index=data.indexOf(',');
        m_sec=data.mid(0,time_index);
        count=3-m_sec.length();
        for(int i=0;i<count;i++)
        {
            m_sec.insert(0,'0');
        }
        date+=m_sec;
        data.remove(0,time_index+1);
        freq=data.mid(0,data.indexOf(','));
        date_time=QDateTime::fromString(date,"yyyy-MM-dd hh:mm:ss.zzz");
        if(date_time.isNull())
            continue;
        if(num<15)
        {
            freq_model->item(num)->setText(date_time.toString("hh:mm:ss.zzz"));
            freq_model->item(num,1)->setText(freq);
            freq_model->item(num,0)->setEditable(true);
            freq_model->item(num,1)->setEditable(true);
            num++;
        }
        one_value.time=date_time;
        one_value.freq=freq.toFloat();
        freq_vector<<one_value;
    }
    if(freq_vector.count()>20000)
    {
        QMessageBox::information(this,"提示","仅支持2万条频率数据.");
    }
    ui->all_index->setText(QString("%1").arg(qCeil((float)freq_vector.count()/15)));
    ui->go_index->setRange(1,qCeil((float)freq_vector.count()/15));
    ui->remove_start->setRange(1,freq_vector.count());
    ui->remove_end->setRange(1,freq_vector.count());
    file.close();
    QMessageBox *box = new QMessageBox(QMessageBox::Information,tr("提示"),tr("导入完毕。"),0,this);
    QTimer::singleShot(1500,box,SLOT(accept()));
    box->exec();
    ui->state_mesg->setText("数据导入成功。");
    on_go_index_editingFinished();
}

void List_out::on_last_clicked()
{
    ui->go_index->setValue(ui->go_index->value()-1);
    on_go_index_editingFinished();
}

void List_out::on_next_clicked()
{
    ui->go_index->setValue(ui->go_index->value()+1);
    on_go_index_editingFinished();
}



void List_out::on_u_all_clicked()
{
    ui->ua->setChecked(ui->u_all->isChecked());
    ui->ub->setChecked(ui->u_all->isChecked());
    ui->uc->setChecked(ui->u_all->isChecked());
    ui->ud->setChecked(ui->u_all->isChecked());
}

void List_out::on_start_change_u_clicked()
{
    if(MainWindow::connect_flag!=true)
    {
        QMessageBox *box = new QMessageBox(QMessageBox::Information,tr("提示"),tr("无连接，请检测通讯设置!"),0,this);
        QTimer::singleShot(1500,box,SLOT(accept()));
        box->exec();
        return;
    }
    on_pushButton_clicked();
    if(ui->start_change_u->text().compare("启动变压")==0)
    {
        edit_flag=false;
        ui->start_freq->setEnabled(false);
        ui->u_change_view->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->start_change_u->setText("变压已启动");
        ui->state_mesg->setText("变压输出进行中。");
        u_start=true;
        init_u_data(true);
        u_timer->start((int)(u_change_model->item(0,2)->data(Qt::EditRole).toFloat()*1000));
    }
}

void List_out::on_u_change_view_clicked(const QModelIndex &index)
{
    if(edit_flag)
    {
        ui->u_change_view->edit(index);
    }
}

void List_out::on_go_to_clicked()
{
    on_go_index_editingFinished();
}

void List_out::on_last_3_clicked()
{
    if(freq_vector.length()<1)
    {
        QMessageBox::information(this,"提示","无数据");
        return;
    }
    if(QMessageBox::warning(this, "警告", "是否确定删除！",\
      QMessageBox::Yes | QMessageBox::No, QMessageBox::No)==QMessageBox::Yes)
    {
        int n=ui->remove_end->value()-ui->remove_start->value();
        if(n)
        {
            qDebug()<<ui->remove_start->value()-1<<n;
            freq_vector.remove(ui->remove_start->value()-1,n+1);
        }else
        {
            freq_vector.remove(ui->remove_start->value()-1);
        }
        if(freq_vector.length()<1)
        {
            QStringList label;
            for(int i=0;i<15;i++)
            {
                freq_model->setItem(i,0,new QStandardItem("--:--:--.-"));
                freq_model->setItem(i,1,new QStandardItem("0"));
                label<<QString("%1").arg(i+1);
                freq_model->item(i,0)->setEditable(false);
                freq_model->item(i,1)->setEditable(false);
            };
            freq_model->setVerticalHeaderLabels(label);
            ui->now_index->setText(QString("%1").arg(1));
            ui->all_index->setText(QString("%1").arg(1));
            ui->go_index->setRange(1,1);
            ui->go_index->setValue(1);
            ui->remove_start->setRange(1,1);
            ui->remove_end->setRange(1,1);
        }
        on_go_index_editingFinished();
    }
}

void List_out::on_freq_view_clicked(const QModelIndex &index)
{
    if(freq_vector.length()<1)
        return;
    QItemSelectionModel *selections =  ui->freq_view->selectionModel();
    QModelIndexList selected = selections->selectedIndexes();
    QList<int> all_row;
    foreach (QModelIndex indexl, selected)
    {
        if(((ui->go_index->value()-1)*15+indexl.row()+1)<freq_vector.length())
        {
            all_row<<((ui->go_index->value()-1)*15+indexl.row()+1);
        }else
        {
            all_row<<freq_vector.length();
        }
    }
    ui->remove_start->setValue(all_row.first());
    ui->remove_end->setValue(all_row.last());
}

void List_out::on_remove_start_valueChanged(int arg1)
{
   ui->remove_end->setRange(arg1,freq_vector.length());
}
void List_out::set_u_enable(bool flag)
{
    ui->u_all->setEnabled(flag);
    ui->ua->setEnabled(flag);
    ui->ub->setEnabled(flag);
    ui->uc->setEnabled(flag);
    ui->ud->setEnabled(flag);
}
void List_out::open_by_xlsx(QString file_name)
{
//    for(int i=0;i<15;i++)
//    {
//        freq_model->setItem(i,0,new QStandardItem("--:--:--.-"));
//        freq_model->setItem(i,1,new QStandardItem("0"));
//        freq_model->item(i,0)->setEditable(false);
//        freq_model->item(i,1)->setEditable(false);
//    };
    QXlsx::Document xlsx(file_name);//打开Test.xlsx表格
    QXlsx::CellRange range;
    range = xlsx.dimension();
    int rowCount = range.rowCount();
    int col=range.columnCount();
    qDebug()<<xlsx.cellAt(1,2)->dateTime().toString();
    qDebug()<<col;
    if(col<4)
    {
        QMessageBox::information(this,"提示","解析失败！");
        return;
    }
    freq_value one_value;
    freq_vector.clear();
    //输出表格内容
    QString str;
    double sec=0;
    int sec_mid=0;
    QDateTime date_time;
    int num=0;
    int i = 2;
    if(rowCount>1)
    {
        if(xlsx.cellAt(1,1)->isDateTime())
        {
            i=1;
        }
    }
    for (; i <=rowCount; i++){
        if(xlsx.cellAt(i, 2)->value().isNull())
        {
            break;
        }
        sec=xlsx.cellAt(i, 2)->value().toDouble();
//        qDebug()<<xlsx.cellAt(0,2)->value().toString();
        sec_mid=sec*100000;
        if(sec>((double)sec_mid/100000))
        {
            sec=((double)sec_mid/100000+0.00001);
        }
        date_time=xlsx.cellAt(i, 1)->dateTime().addSecs(sec*24*60*60)\
                .addMSecs(xlsx.cellAt(i, 3)->value().toInt());
        str=date_time.toString("hh:mm:ss.zzz");
        if(num<15)
        {
            freq_model->item(num)->setText(str);
            freq_model->item(num,1)->setText(xlsx.cellAt(i, 4)->value().toString());
            freq_model->item(num,0)->setEditable(true);
            freq_model->item(num,1)->setEditable(true);
            num++;
        }
        one_value.time=date_time;
        one_value.freq=xlsx.cellAt(i, 4)->value().toFloat();
        freq_vector<<one_value;
    }
    if(freq_vector.count()>20000)
    {
        QMessageBox::information(this,"提示","仅支持2万条频率数据.");
    }
    ui->all_index->setText(QString("%1").arg(qCeil((float)freq_vector.count()/15)));
    ui->go_index->setRange(1,qCeil((float)freq_vector.count()/15));
    ui->remove_start->setRange(1,freq_vector.count());
    ui->remove_end->setRange(1,freq_vector.count());
    QMessageBox *box = new QMessageBox(QMessageBox::Information,tr("提示"),tr("导入完毕。"),0,this);
    QTimer::singleShot(1500,box,SLOT(accept()));
    box->exec();
    ui->state_mesg->setText("数据导入成功。");
    on_go_index_editingFinished();
}
void List_out::set_time(QModelIndex index,QString text)
{
    int page=ui->go_index->value();
    int now_index=(page-1)*15+index.row();
    if(index.column()==0)
    {
        freq_vector[now_index].time.setTime(QTime::fromString(text,"hh:mm:ss.zzz"));
        if(now_index<freq_vector.count()-1)
        {
            if(freq_vector.at(now_index).time.msecsTo(freq_vector.at(now_index+1).time)<=0)
            {
                QMessageBox::information(this,"提示","当前频率时间大于或等于下一条频率数据！");
            }
        }
        if(now_index!=0&&now_index<freq_vector.count())
        {
            if(qAbs(freq_vector.at(now_index).time.msecsTo(freq_vector.at(now_index-1).time))>35000)
            {
                QMessageBox::information(this,"提示","两条频率间隔不能超过35秒！");
            }
        }
    }else
    {
        freq_vector[now_index].freq=text.toFloat();
    }
}

void List_out::set_freq(QModelIndex index, double text)
{
    double ua_x,ua_y,ua_v,ua_p,ub_x,ub_y,ub_v,ub_p,uc_x,uc_y,uc_v,uc_p,ud_x,ud_y,ud_v,ud_p;
    if(ui->freq_set->isChecked()&&index.column()==2)
        for(int i=0;i<u_model->rowCount();i++)
            u_model->item(i,2)->setData(text,Qt::EditRole);
    //零序计算
    if(ui->zero_seq->isChecked()&&(index.column()==0||index.column()==1)&&(index.row()!=3))
    {
        for(int i=0;i<3;i++)
            for(int j=0;j<2;j++)
            {
                if(i==0&&j==0)
                    ua_v = u_model->item(i,j)->text().toDouble();
                else if(i==0&&j==1)
                    ua_p = u_model->item(i,j)->text().toDouble();
                else if(i==1&&j==0)
                    ub_v = u_model->item(i,j)->text().toDouble();
                else if(i==1&&j==1)
                    ub_p = u_model->item(i,j)->text().toDouble();
                else if(i==2&&j==0)
                    uc_v = u_model->item(i,j)->text().toDouble();
                else if(i==2&&j==1)
                    uc_p = u_model->item(i,j)->text().toDouble();
            }
        ua_x = ua_v*cos(ua_p*M_PI/180);
        ua_y = ua_v*sin(ua_p*M_PI/180);
        ub_x = ub_v*cos(ub_p*M_PI/180);
        ub_y = ub_v*sin(ub_p*M_PI/180);
        uc_x = uc_v*cos(uc_p*M_PI/180);
        uc_y = uc_v*sin(uc_p*M_PI/180);
        ud_x = ua_x+ub_x+uc_x;
        ud_y = ua_y+ub_y+uc_y;
        ud_v = sqrt(ud_x*ud_x+ud_y*ud_y);
        if(ud_x==0)
        {
            if(ud_y>=0)
                ud_p = 90;
            else
                ud_p = 270;
        }else if(ud_y==0){
            if(ud_x>=0)
                ud_p = 0;
            else
                ud_p = 180;
        }else
            ud_p = atan(ud_y/ud_x)*180/M_PI;
        u_model->item(3,0)->setData(ud_v,Qt::EditRole);
        u_model->item(3,1)->setData(ud_p,Qt::EditRole);
    }
}

//void List_out::on_show_ferq_wave_clicked()
//{
////    if(ui->widget->isHidden())
//    {
//        ui->frame_3->hide();
//        ui->widget->show();
//        ui->show_ferq_wave->setText("隐藏");
//    }else
//    {
//        ui->widget->hide();
//        ui->frame_3->show();
//        ui->show_ferq_wave->setText("预览曲线");
//    }
//}

void List_out::on_creat_line_data_clicked()
{
    double time=0;
    double freq=0;
    freq_x.clear();
    freq_y.clear();
    if(freq_vector.length()<1)
        return;
    qDebug()<<freq_vector.length();
    freq_x<<0;
    freq_y<<freq_vector.first().freq;
    max_freq=freq_vector.first().freq;
    min_freq=freq_vector.first().freq;
    for(int i=1;i<freq_vector.length();i++)
    {
        time+=(freq_vector.at(i-1).time.msecsTo(freq_vector.at(i).time))/(double)1000;
        freq=freq_vector.at(i).freq;
        max_freq>freq?freq:max_freq=freq;
        min_freq<freq?freq:min_freq=freq;
        freq_x<<time;
        freq_y<<freq_y.last();
        freq_x<<time+0.000001;
        freq_y<<freq;
    }
    freq_map_x=freq_x.last();
    freq_map_y_max=max_freq+(max_freq-min_freq)/2;
    freq_map_y_min=min_freq-(max_freq-min_freq)/2;
    freq_ticker_step=freq_x.last()/20;
    qDebug()<<freq_ticker_step;
    QSharedPointer<QCPAxisTickerFixed> ticker(new QCPAxisTickerFixed);
    ticker->setTickStep(QString::number(freq_ticker_step,'g',4).toFloat());
    ui->freq_map->xAxis->setRange(0,freq_map_x);
    ui->freq_map->xAxis->setTicker(ticker);
    ui->freq_map->yAxis->setRange(freq_map_y_min,freq_map_y_max);
    line->setData(freq_x,freq_y);
    ui->freq_map->replot();
}

void List_out::on_change_set_clicked()
{
    if(ui->change_set->text().compare("变压设置")==0)
    {
        ui->tabWidget->setCurrentIndex(1);
        ui->tabWidget_2->setCurrentIndex(1);
        ui->change_set->setText("变频设置");
        if(freq_x.length()<1)
            return;
        ui->freq_map->xAxis->setRange(0,freq_x.last());
        QSharedPointer<QCPAxisTickerFixed> ticker(new QCPAxisTickerFixed);
        ticker->setTickStep(QString::number(freq_x.last()/20,'g',4).toFloat());
        ui->freq_map->xAxis->setTicker(ticker);
        ui->freq_map->yAxis->setRange(min_freq-(max_freq-min_freq)/2,max_freq+(max_freq-min_freq)/2);
        line->setData(freq_x,freq_y);
    }else
    {
        ui->tabWidget->setCurrentIndex(0);
        ui->tabWidget_2->setCurrentIndex(0);
        ui->change_set->setText("变压设置");
    }
    ui->freq_map->replot();
}

void List_out::on_pushButton_clicked()
{
    QVector<double> x1,y1,x2,y2,x3,y3,x4,y4;
    double ua_start,ub_start,uc_start,ud_start,ua_end,ub_end,uc_end,ud_end,ua_step,ub_step,uc_step,ud_step,time,max_lenth;
    ua_start=u_model->item(0)->data(Qt::EditRole).toDouble();
    ub_start=u_model->item(1)->data(Qt::EditRole).toDouble();
    uc_start=u_model->item(2)->data(Qt::EditRole).toDouble();
    ud_start=u_model->item(3)->data(Qt::EditRole).toDouble();
    ua_end=u_change_model->item(0)->data(Qt::EditRole).toDouble();
    ub_end=u_change_model->item(1)->data(Qt::EditRole).toDouble();
    uc_end=u_change_model->item(2)->data(Qt::EditRole).toDouble();
    ud_end=u_change_model->item(3)->data(Qt::EditRole).toDouble();
    if(ua_start>ua_end)
    {
        ua_step = -(u_change_model->item(0,1)->data(Qt::EditRole).toDouble());
        qDebug()<<"ua_step"<<QString::number(ua_step);
    }
    else
    {
        ua_step=u_change_model->item(0,1)->data(Qt::EditRole).toDouble();}
    ub_step=u_change_model->item(1,1)->data(Qt::EditRole).toDouble();
    uc_step=u_change_model->item(2,1)->data(Qt::EditRole).toDouble();
    ud_step=u_change_model->item(3,1)->data(Qt::EditRole).toDouble();
    time=u_change_model->item(0,2)->data(Qt::EditRole).toDouble();
    for(int i=ua_start,j=0;;i+=ua_step,j+=time)
    {
        if(j>0)
        {
            x1<<j;
            y1<<y1.last();
        }
        if((ua_step<0&&i<=ua_end)||(ua_step>0&&i>=ua_end))
        {
            x1<<j;
            y1<<ua_end;
            break;
        }else
        {
            x1<<j+0.00001;
            y1<<i;
        }
    }
    for(int i=ud_start,j=0;;i+=ud_step,j+=time)
    {
        if(j>0)
        {
            x4<<j;
            y4<<y4.last();
        }
        if((ud_step<0&&i<=ud_end)||(ud_step>0&&i>=ud_end))
        {
            x4<<j;
            y4<<ud_end;
            break;
        }else
        {
            x4<<j+0.00001;
            y4<<i;
        }
    }
    for(int i=ub_start,j=0;;i+=ub_step,j+=time)
    {
        if(j>0)
        {
            x2<<j;
            y2<<y2.last();
        }
        if((ub_step<0&&i<=ub_end)||(ub_step>0&&i>=ub_end))
        {
            x2<<j;
            y2<<ub_end;
            break;
        }else
        {
            x2<<j+0.00001;
            y2<<i;
        }
    }
    for(int i=uc_start,j=0;;i+=uc_step,j+=time)
    {
        if(j>0)
        {
            x3<<j;
            y3<<y3.last();
        }
        if((uc_step<0&&i<=uc_end)||(uc_step>0&&i>=uc_end))
        {
            x3<<j;
            y3<<uc_end;
            break;
        }else
        {
            x3<<j+0.00001;
            y3<<i;
        }
    }
    x1.last()>x2.last()?max_lenth=x1.last():max_lenth=x2.last();
    max_lenth<x3.last()?max_lenth=x3.last():max_lenth;
    max_lenth<x4.last()?max_lenth=x4.last():max_lenth;
    if(x1.last()<max_lenth)
    {
        x1<<max_lenth;
        y1<<y1.last();
    }
    if(x2.last()<max_lenth)
    {
        x2<<max_lenth;
        y2<<y2.last();
    }
    if(x3.last()<max_lenth)
    {
        x3<<max_lenth;
        y3<<y3.last();
    }
    if(x4.last()<max_lenth)
    {
        x4<<max_lenth;
        y4<<y4.last();
    }
    l_ua->setData(x1,y1);
    l_ub->setData(x2,y2);
    l_uc->setData(x3,y3);
    l_ud->setData(x4,y4);
    double max_value,min_value;
    if(time>0)
    {
        ua_end>ub_end?max_value=ua_end:max_value=ub_end;
        max_value<uc_end?max_value=uc_end:uc_end;
        max_value<ud_end?max_value=ud_end:ud_end;
        ua_start<ub_start?min_value=ua_start:min_value=ub_start;
        min_value>uc_start?min_value=uc_start:uc_start;
        min_value>ud_start?min_value=ud_start:ud_start;
    }else
    {
        ua_start>ub_start?max_value=ua_start:max_value=ub_start;
        max_value<uc_start?max_value=uc_start:max_value;
        max_value<ud_start?max_value=ud_start:max_value;
        ua_end<ub_end?min_value=ua_end:min_value=ub_end;
        min_value>uc_end?min_value=uc_end:min_value;
        min_value>ud_end?min_value=ud_end:min_value;
    }
    value_map_x=x1.last();
    value_map_y_min=min_value-(max_value-min_value)/2;
    value_map_y_max=max_value+(max_value-min_value)/2;
    value_ticker_step=x1.last()/(double)20;
    ui->value_map->yAxis->setRange(value_map_y_min,value_map_y_max);
    ui->value_map->xAxis->setRange(0,x1.last());
    QSharedPointer<QCPAxisTickerFixed> ticker(new QCPAxisTickerFixed);
    ticker->setTickStep(x1.last()/(double)20);
    ui->value_map->xAxis->setTicker(ticker);
    ui->value_map->replot();
}
void List_out::set_signal()
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
}
void List_out::m_reset()
{
    qDebug()<<freq_map_x;
    qDebug()<<freq_ticker_step;
    QSharedPointer<QCPAxisTickerFixed> ticker(new QCPAxisTickerFixed);
    ui->freq_map->xAxis->setRange(0,freq_map_x);
    ui->freq_map->yAxis->setRange(freq_map_y_min,freq_map_y_max);
    ticker->setTickStep(QString::number(freq_ticker_step,'g',4).toFloat());
    ui->freq_map->xAxis->setTicker(ticker);
    QSharedPointer<QCPAxisTickerFixed> ticker1(new QCPAxisTickerFixed);
    ui->value_map->xAxis->setRange(0,value_map_x);
    ui->value_map->yAxis->setRange(value_map_y_min,value_map_y_max);
    ticker1->setTickStep(value_ticker_step);
    ui->value_map->xAxis->setTicker(ticker1);
    ui->freq_map->replot();
    ui->value_map->replot();
}
void List_out::mousePress(QMouseEvent* mevent)
{
    if(type>1)
    {
        ui->freq_map->axisRect()->setRangeDrag(0);
        ui->value_map->axisRect()->setRangeDrag(0);
    }
    switch (type) {
    case 1:
        ui->freq_map->axisRect()->setRangeDrag(Qt::Horizontal|Qt::Vertical);
        ui->value_map->axisRect()->setRangeDrag(Qt::Horizontal|Qt::Vertical);
        break;
    case 2:
    case 3:
    case 4:
        if(mevent->button() == Qt::LeftButton)
        {
            rubberOrigin = mevent->pos();
            if(freq_flag)
            {
                u_rubber->setGeometry(QRect(rubberOrigin, QSize()));
                u_rubber->show();
            }else if(value_flag)
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
void List_out::mouseMove(QMouseEvent *mevent)
{
    if(u_rubber->isVisible())
        u_rubber->setGeometry(QRect(rubberOrigin, mevent->pos()).normalized());
    if(i_rubber->isVisible())
        i_rubber->setGeometry(QRect(rubberOrigin, mevent->pos()).normalized());
}

//鼠标释放槽函数
void List_out::mouseRelease(QMouseEvent *mevent)
{
    Q_UNUSED(mevent);
    if(type>1)
    {
        ui->freq_map->axisRect()->setRangeDrag(0);
        ui->value_map->axisRect()->setRangeDrag(0);
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
        x1= ui->freq_map->xAxis->pixelToCoord(xp1);
        x2= ui->freq_map->xAxis->pixelToCoord(xp2);
        y1= ui->freq_map->yAxis->pixelToCoord(yp1);
        y2= ui->freq_map->yAxis->pixelToCoord(yp2);
    }
    if (i_rubber->isVisible())
    {
        const QRect zoomRect = i_rubber->geometry();
        int xp1, yp1, xp2, yp2;
        zoomRect.getCoords(&xp1, &yp1, &xp2, &yp2);
        x1= ui->value_map->xAxis->pixelToCoord(xp1);
        x2= ui->value_map->xAxis->pixelToCoord(xp2);
        y1= ui->value_map->yAxis->pixelToCoord(yp1);
        y2= ui->value_map->yAxis->pixelToCoord(yp2);
    }
    switch (type) {
    case 1:
        ui->freq_map->axisRect()->setRangeDrag(Qt::Horizontal|Qt::Vertical);
        ui->value_map->axisRect()->setRangeDrag(Qt::Horizontal|Qt::Vertical);
        break;
    case 2:
        if(u_rubber->isVisible())
        {
            ui->freq_map->xAxis->setRange(x1, x2);
            ui->freq_map->yAxis->setRange(y1, y2);
        }
        if(i_rubber->isVisible())
        {
            ui->value_map->xAxis->setRange(x1, x2);
            ui->value_map->yAxis->setRange(y1, y2);
        }
        reset_ticker();
        break;
    case 3:
        if (u_rubber->isVisible())
        {
            ui->freq_map->xAxis->setRange(x1, x2);
        }
        if (i_rubber->isVisible())
        {
            ui->value_map->xAxis->setRange(x1, x2);
        }
        reset_ticker();
        break;
    case 4:
        if (u_rubber->isVisible())
        {
            ui->freq_map->yAxis->setRange(y1, y2);
        }
        if (i_rubber->isVisible())
        {
            ui->value_map->yAxis->setRange(y1, y2);
        }
        break;
    case 5:
        if(freq_flag)
        {
            x= ui->freq_map->xAxis->pixelToCoord(mevent->pos().x());
            y= ui->freq_map->yAxis->pixelToCoord(mevent->pos().y());
            ui->freq_map->xAxis->scaleRange(0.9,x);
            ui->freq_map->yAxis->scaleRange(0.9,y);
        }else if(value_flag)
        {
            x= ui->value_map->xAxis->pixelToCoord(mevent->pos().x());
            y= ui->value_map->yAxis->pixelToCoord(mevent->pos().y());
            ui->value_map->xAxis->scaleRange(0.9,x);
            ui->value_map->yAxis->scaleRange(0.9,y);
        }
        reset_ticker();
        break;
    case 6:
        if(freq_flag)
        {
            x= ui->freq_map->xAxis->pixelToCoord(mevent->pos().x());
            y= ui->freq_map->yAxis->pixelToCoord(mevent->pos().y());
            qDebug()<<x<<y;
            ui->freq_map->xAxis->scaleRange(1.1,x);
            ui->freq_map->yAxis->scaleRange(1.1,y);
        }else if(value_flag)
        {
            x= ui->value_map->xAxis->pixelToCoord(mevent->pos().x());
            y= ui->value_map->yAxis->pixelToCoord(mevent->pos().y());
            ui->value_map->xAxis->scaleRange(1.1,x);
            ui->value_map->yAxis->scaleRange(1.1,y);
        }
        reset_ticker();
        break;
    case 7:
        if(freq_flag)
        {
            x= ui->freq_map->xAxis->pixelToCoord(mevent->pos().x());
            ui->freq_map->xAxis->scaleRange(0.9,x);
        }else if(value_flag)
        {
            x= ui->value_map->xAxis->pixelToCoord(mevent->pos().x());
            ui->value_map->xAxis->scaleRange(0.9,x);
        }
        reset_ticker();
        break;
    case 8:
        if(freq_flag)
        {
            x= ui->freq_map->xAxis->pixelToCoord(mevent->pos().x());
            ui->freq_map->xAxis->scaleRange(1.1,x);
        }else if(value_flag)
        {
            x= ui->value_map->xAxis->pixelToCoord(mevent->pos().x());
            ui->value_map->xAxis->scaleRange(1.1,x);
        }
        reset_ticker();
        break;
    case 9:
        if(freq_flag)
        {
            y= ui->freq_map->yAxis->pixelToCoord(mevent->pos().y());
            ui->freq_map->yAxis->scaleRange(0.9,y);
        }else if(value_flag)
        {
            y= ui->value_map->yAxis->pixelToCoord(mevent->pos().y());
            ui->value_map->yAxis->scaleRange(0.9,y);
        }
        break;
    case 10:
        if(freq_flag)
        {
            y= ui->freq_map->yAxis->pixelToCoord(mevent->pos().y());
            ui->freq_map->yAxis->scaleRange(1.1,y);
        }else if(value_flag)
        {
            y= ui->value_map->yAxis->pixelToCoord(mevent->pos().y());
            ui->value_map->yAxis->scaleRange(1.1,y);
        }
        break;
    default:
        break;
    }
    if(freq_flag)
    {
        freq_flag=false;
        u_rubber->hide();
        ui->freq_map->replot();
    }
    if(value_flag)
    {
        value_flag=false;
        i_rubber->hide();
        ui->value_map->replot();
    }
}
void List_out::m_move(){type=1;m_move_item->setChecked(true);}
void List_out::m_sq(){type=2;m_sq_item->setChecked(true);}
void List_out::m_all_up(){type=6;m_all_up_item->setChecked(true);}
void List_out::m_all_down(){type=5;m_all_down_item->setChecked(true);;}
void List_out::m_sq_x(){type=3;m_sq_x_item->setChecked(true);}
void List_out::m_x_up(){type=8;m_x_up_item->setChecked(true);}
void List_out::m_x_down(){type=7;m_x_down_item->setChecked(true);}
void List_out::m_sq_y(){type=4;m_sq_y_item->setChecked(true);}
void List_out::m_y_up(){type=10;m_y_up_item->setChecked(true);}
void List_out::m_y_down(){type=9;m_y_down_item->setChecked(true);}
void List_out::u_press(QMouseEvent*mevent)
{
    if(mevent->button()==Qt::RightButton)
    {
        showListWidgetMenuSlot(mevent->pos());
    }else
    {
        freq_flag=true;
        mousePress(mevent);
    }
}
void List_out::i_press(QMouseEvent*mevent)
{
    if(mevent->button()==Qt::RightButton)
    {
        showListWidgetMenuSlot(mevent->pos());
    }else
    {
        value_flag=true;
        mousePress(mevent);
    }
}
void List_out::reset_ticker()
{
    double start=0;
    double stop=0;
    double point=0;
    double step=0;
    QSharedPointer<QCPAxisTickerFixed> ticker(new QCPAxisTickerFixed);
    if(freq_flag)
    {
        start=ui->freq_map->xAxis->range().lower;
        stop=ui->freq_map->xAxis->range().upper;
        point=stop-start;
        step=point/10;
        if(step<0)
            step=1;
        ticker->setTickStep(step);
        ui->freq_map->xAxis->setTicker(ticker);
        ui->freq_map->xAxis->setRange(start,stop);
    }else
    {
        start=ui->value_map->xAxis->range().lower;
        stop=ui->value_map->xAxis->range().upper;
        point=stop-start;
        step=point/10;
        if(step<0)
            step=1;
        ticker->setTickStep(step);
        ui->value_map->xAxis->setTicker(ticker);
        ui->value_map->xAxis->setRange(start,stop);
    }
}
void List_out::showListWidgetMenuSlot(QPoint pos)
{
    m_contextMenu->exec(QCursor::pos());
}

void List_out::on_add_data_clicked()
{
    freq_value one_value;
    one_value.time=QDateTime::currentDateTime();
    one_value.freq=50.0;
    freq_vector<<one_value;
    on_go_index_editingFinished();
}

void List_out::on_read_gear_clicked()
{
    xl609->read_all_set(XL803::List_out);
}

void List_out::gear_Change(int index)
{
    int m_i=index-1;
    if(m_i<0)
    {
        ui->max_value->setText(QString("%1V").arg(max_value.last()));
    }else
    {
        ui->max_value->setText(QString("%1V").arg(max_value.at(index-1)));
    }
}
