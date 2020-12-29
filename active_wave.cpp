#include "active_wave.h"
#include "ui_active_wave.h"

ActiveDelegate::ActiveDelegate(QObject * parent):QItemDelegate(parent)
{
}
QWidget * ActiveDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index)const
{
    //M_spinbox *box;
    QLineEdit * edit;
    edit=new QLineEdit(parent);
    if(index.column()==1)
    {
        //lineEdit->setValidator(new QDoubleValidator(-180.0,180.0,6,this));
        QRegExp rx("^((\\d+)(\\.\\d{0,5})?)?$");
        edit->setValidator(new QRegExpValidator(rx));
    }
    return edit;
}
void ActiveDelegate::setEditorData(QWidget *editor, const QModelIndex &index)const
{
    QLineEdit * edit;
    QString str;
    str = index.model()->data(index, Qt::EditRole).toString();
    edit= static_cast<QLineEdit*>(editor);
    edit->setText(str);
    return;
}
void ActiveDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    //M_spinbox *box;
    QLineEdit * edit;
    edit=static_cast<QLineEdit*>(editor);
    model->setData(index, edit->text(), Qt::EditRole);
    emit editd(index,edit->text());

}
void ActiveDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index)const
{
    editor->setGeometry(option.rect);
}
ActiveDelegate::~ActiveDelegate()
{

}

active_wave::active_wave(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::active_wave)
{
    ui->setupUi(this);
    xl609=L_XL803;
    xl609->set_map(ui->show_wave);
    QVector<QString> list;
    list<<"内部触发输出"<<"外部触发输入"<<"启动立刻输出"<<"过零同步脉冲输出模式"<<"同步跟踪模式"<<"电能累计同步信号输出";
    ui->tigger_type->set_items(list);
    ui->tigger_type->setValue(2);
    list.clear();
    list<<"50*sin(2*PI*50*Ti+5*sin(2*PI*50*Ti/10))"\
        <<"50*sin(2*PI*50*Ti)"\
        <<"100*sin(2*PI*50*Ti)+30*sin(2*PI*150*Ti)+18*sin(2*PI*250*Ti)+\
14*sin(2*PI*350*Ti)+9*sin(2*PI*550*Ti)+5*sin(2*PI*650*Ti)"\
        <<"(5+sin(2*PI*5*Ti))*sin(2*PI*50*Ti)"\
        <<"100*sin(2*PI*50*Ti)+3.8*sin(2*PI*150*Ti)+2.4*sin(2*PI*250*Ti+PI)\
+1.7*sin(2*PI*350*Ti)+1.5*sin(2*PI*450*Ti+PI)+1.1*sin(2*PI*550*Ti)\
+0.8*sin(2*PI*650*Ti+PI)+0.6*sin(2*PI*750*Ti)+0.4*sin(2*PI*850*Ti+PI)+0.3*sin(2*PI*950*Ti)"\
        <<"100*sin(2*PI*50*Ti)+80*sin(2*PI*150*Ti+PI)+60*sin(2*PI*250*Ti)+40*sin(2*PI*350*Ti+PI)\
+22*sin(2*PI*450*Ti)+12*sin(2*PI*550*Ti+PI)+5*sin(2*PI*650*Ti)+2*sin(2*PI*750*Ti+PI)\
+sin(2*PI*850*Ti)+0.5*sin(2*PI*950*Ti+PI)"\
        <<"100*sin(2*PI*50*Ti)+5*sin(2*PI*100*Ti+PI/2)+18*sin(2*PI*150*Ti+(-16*PI/18))+10*sin(2*PI*200*Ti+11*PI/18)\
+66*sin(2*PI*250*Ti+13*PI/18)+50*sin(2*PI*350*Ti+5*PI/18)";
     ui->formula->set_items(list);
    model=new QStandardItemModel(this);
    ui->formula_table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    connect(ui->formula_table->verticalScrollBar(),SIGNAL(valueChanged(int)),this,SLOT(add_item(int )));
    connect(L_XL803,SIGNAL(send_to_active_wave(QByteArray,QByteArray)),this,SLOT(recv_mesg(QByteArray,QByteArray)));
    QStringList label;
    label<<"公式"<<"   时间(s)  ";
    model->setHorizontalHeaderLabels(label);
    ui->formula_table->setContextMenuPolicy(Qt::CustomContextMenu);
    copy_flag=0;
    copy_row=0;
    m_contextMenu = new QMenu;
    m_copy_one = new QAction("复制当前行", this);
    m_copy_all = new QAction("复制当前相", this);
    m_past = new QAction("粘贴", this);
    m_remove= new QAction("删除", this);
    m_past->setEnabled(false);
    m_contextMenu->addAction(m_copy_one);
    m_contextMenu->addAction(m_copy_all);
    m_contextMenu->addAction(m_past);
    m_contextMenu->addAction(m_remove);

    //和该策略对应的信号，showListWidgetMenuSlot为自己定义的槽函数.
    connect(ui->formula_table, SIGNAL(customContextMenuRequested(QPoint)),this, SLOT(showListWidgetMenuSlot(QPoint)));
    connect(m_copy_one,SIGNAL(triggered(bool)),this,SLOT(copy_one(bool)));
    connect(m_copy_all,SIGNAL(triggered(bool)),this,SLOT(copy_all(bool)));
    connect(m_past,SIGNAL(triggered(bool)),this,SLOT(past(bool)));
    connect(m_remove,SIGNAL(triggered(bool)),this,SLOT(remove_one(bool)));
    QStandardItem * item;
    QString str;

    for(int row=0;row<10;row++)
    {
        for(int colum=0;colum<2;colum++)
        {
            item=new QStandardItem(0);
            model->setItem(row,colum,item);
        }
    }
    ActiveDelegate* dele= new ActiveDelegate(this);
    ui->formula_table->setItemDelegate(dele);
    ui->formula_table->setModel(model);
    ui->formula_table->horizontalHeader()->setSectionResizeMode(1,QHeaderView::ResizeToContents);

    connect(dele,SIGNAL(editd(QModelIndex ,QString )),this,SLOT(update_value(QModelIndex ,QString )));
    line=ui->show_wave->addGraph();
    QSharedPointer<QCPAxisTickerFixed> ticker(new QCPAxisTickerFixed);
    ticker->setTickStep(0.002);
    ui->show_wave->xAxis->setTicker(ticker);
    line->setPen(QPen(Qt::yellow,1));
    ui->show_wave->xAxis->setRange(0,0.02);
    pri_flag=false;
    read_formula=false;
    dialog=new  QProgressDialog(tr("波形下载进度"), tr("取消"), 0, 1, this);
    dialog->setWindowTitle(tr("波形下载"));
    dialog->setWindowModality(Qt::WindowModal);
    dialog->setValue(1);
    max_time_lenth=0;
    check_byte;
    start_down=false;
    ui->state1->set_value(0);
    ui->state2->set_value(1);
    ui->state3->set_value(2);
    map<<&ua_rule_map<<&ub_rule_map<<&uc_rule_map<<&ud_rule_map;
    connect(ui->buttonGroup,SIGNAL(buttonClicked(int)),SLOT(show_rula(int )));
    data_creator_flag=false;
    ua_max=0;
    ub_max=0;
    uc_max=0;
    ud_max=0;
    ua_sample=200;
    ub_sample=200;
    uc_sample=200;
    ud_sample=200;
    sample_vector<<&ua_sample<<&ub_sample<<&uc_sample<<&ud_sample;
    line_vector<<&ua_data<<&ub_data<<&uc_data<<&ud_data;
    wave_vector<<&wave_data<<&wave_data_2<<&wave_data_3<<&wave_data_4;
    max_vector<<&ua_max<<&ub_max<<&uc_max<<&ud_max;
    down_num=0;
    down_flag=0;
    cancel_flag=false;
    connect(dialog,SIGNAL(canceled()),this,SLOT(cancel_down()));
    ui->label_7->hide();
    ui->formula->hide();
}
void active_wave::cancel_down()
{
    start_down=false;
    cancel_flag=true;
    xl609->stop_down_simpdata(XL803::ACTIVE_WAVE);
    ui->byte_length->setReadOnly(false);
    down_wave.clear();
    one_wave.clear();
    check_byte=0;
    down_num=0;
    down_flag=0;
}
void active_wave::update_value(QModelIndex index,QString value)
{
    data_creator_flag=false;
    int row=index.row();
    rule_value rule;
    rule.rule=model->item(row,0)->data(Qt::EditRole).toString();
    rule.time=model->item(row,1)->data(Qt::EditRole).toString();
    if(index.column()==0)
    {
        model->item(row,0)->setToolTip(rule.rule);
    }else{
        model->item(row,1)->setToolTip(rule.time);
    }
    if(ui->set_ua->isChecked())
    {
        ua_rule_map.insert(row,rule);
    }else if(ui->set_ub->isChecked())
    {
        ub_rule_map.insert(row,rule);
    }else if(ui->set_uc->isChecked())
    {
        uc_rule_map.insert(row,rule);
    }else if(ui->set_ud->isChecked())
    {
        ud_rule_map.insert(row,rule);
    }
}
void active_wave::show_rula(int)
{
    int flag=0;
    if(ui->set_ua->isChecked()){
        flag=0;
        ui->u_pipe_state->setText("UA");
    }else if(ui->set_ub->isChecked()){
        flag=1;
        ui->u_pipe_state->setText("UB");
    }else if(ui->set_uc->isChecked()){
        flag=2;
        ui->u_pipe_state->setText("UC");
    }else if(ui->set_ud->isChecked()){
        flag=3;
        ui->u_pipe_state->setText("UD");
    }
    for(int i=0;i<model->rowCount();i++)
    {
        model->item(i,0)->setData("",Qt::EditRole);
        model->item(i,1)->setData("",Qt::EditRole);
    }
    ui->sampling->setValue(*sample_vector.at(flag));
    QMap<int,rule_value>::iterator it=map.at(flag)->begin();
    QString rule;
    QString time;
    for(;it!=map.at(flag)->end();it++)
    {
        rule="";
        time="";
        rule=((rule_value)it.value()).rule;
        time=((rule_value)it.value()).time;
        model->item(it.key(),0)->setData(rule, Qt::EditRole);
        model->item(it.key(),0)->setToolTip(rule);
        model->item(it.key(),1)->setData(time,Qt::EditRole);
        model->item(it.key(),1)->setToolTip(time);
    }
    show_line();
}
active_wave::~active_wave()
{
    delete ui;
}
void active_wave::add_item(int index)
{
    if(ui->formula_table->verticalScrollBar()->maximum()==index)
    {
        QList<QStandardItem*>list;
        QStandardItem * item;
        item=new QStandardItem(0);
        list<<item;
        item=new QStandardItem(0);
        list<<item;
        model->appendRow(list);
    }
}

void active_wave::on_save_formula_clicked()
{
    int max_row=0;
    max_row=ua_rule_map.count();
    max_row>ub_rule_map.count()?max_row:max_row=ub_rule_map.count();
    max_row>uc_rule_map.count()?max_row:max_row=uc_rule_map.count();
    max_row>ud_rule_map.count()?max_row:max_row=ud_rule_map.count();
    QMap<int,rule_value>::iterator ua_it=ua_rule_map.begin();
    QMap<int,rule_value>::iterator ub_it=ub_rule_map.begin();
    QMap<int,rule_value>::iterator uc_it=uc_rule_map.begin();//遍历map
    QMap<int,rule_value>::iterator ud_it=ud_rule_map.begin();//遍历map
    if(max_row==0)
    {
        QMessageBox::information(this,"提示","没有公式信息。");
        return;
    }
    QString file_name = QFileDialog::getSaveFileName(NULL,"保存公式文件","./","*.txt");
    QFile file(file_name);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::information(this," ","保存失败!");
        return;
    }
    QTextStream out(&file);
    for(int i=0;i<max_row;i++)
    {
        if(ua_it!=ua_rule_map.end())
            out<<((rule_value)ua_it.value()).rule;
        out<<';';
        if(ub_it!=ub_rule_map.end())
            out<<((rule_value)ub_it.value()).rule;
        out<<';';
        if(uc_it!=uc_rule_map.end())
            out<<((rule_value)uc_it.value()).rule;
        out<<';';
        if(ud_it!=ud_rule_map.end())
            out<<((rule_value)ud_it.value()).rule;
        out<<endl;
        if(ua_it!=ua_rule_map.end())
            out<<((rule_value)ua_it.value()).time;
        out<<';';
        if(ub_it!=ub_rule_map.end())
            out<<((rule_value)ub_it.value()).time;
        out<<';';
        if(uc_it!=uc_rule_map.end())
            out<<((rule_value)uc_it.value()).time;
        out<<';';
        if(ud_it!=ud_rule_map.end())
            out<<((rule_value)ud_it.value()).time;
        out<<endl;
        if(ua_it!=ua_rule_map.end())
            ua_it++;
        if(ub_it!=ub_rule_map.end())
            ub_it++;
        if(uc_it!=uc_rule_map.end())
            uc_it++;
        if(ud_it!=ud_rule_map.end())
            ud_it++;
    }
   file.close();
}

void active_wave::on_open_formula_clicked()
{
    QString file_name = QFileDialog::getOpenFileName(NULL,"打开公式文件","./","*.txt");
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
    file_name.replace(".txt","");
    QStringList label;
    label<<file_name<<"   时间  ";
    model->setHorizontalHeaderLabels(label);
    QTextStream in(&file);
    model->rowCount();
    int i=0;
    rule_value value;
    int flag=0;
    if(ui->set_ua->isChecked()){
        flag=0;
    }else if(ui->set_ub->isChecked()){
        flag=1;
    }else if(ui->set_uc->isChecked()){
        flag=2;
     }else if(ui->set_ud->isChecked()){
        flag=3;
    }
    while(!in.atEnd())
    {
        if(model->rowCount()<=i)
        {
            QList<QStandardItem*>list;
            QStandardItem * item;
            item=new QStandardItem(0);
            list<<item;
            item=new QStandardItem(0);
            list<<item;
            model->appendRow(list);
        }
        QString rula=in.readLine();
        QString time=in.readLine();
        for(int num=0;num<3;num++)
        {
            value.time="";
            value.rule="";
            value.rule=rula.mid(0,rula.indexOf(';'));
            rula.remove(0,rula.indexOf(';')+1);
            value.time=time.mid(0,time.indexOf(';'));
            time.remove(0,time.indexOf(';')+1);
            map[num]->insert(i,value);
            if(num==flag)
            {
                model->item(i,0)->setData(value.rule, Qt::EditRole);
                model->item(i,0)->setToolTip(value.rule);
                model->item(i,1)->setData(value.time,Qt::EditRole);
                model->item(i,1)->setToolTip(value.time);
            }
        }
        i++;
    }
    data_creator_flag=false;
    file.close();
}

void active_wave::on_save_wave_clicked()
{
   // int send_point=ui->sampling->value()*1000/ui->freq->value();
    QVector<quint16> toSendData;
    float tempValue;
    float value;
    float max_value;
    int flag=0;
    if(ui->set_ua->isChecked()){
        flag=0;
    }else if(ui->set_ub->isChecked()){
        flag=1;
    }else if(ui->set_uc->isChecked()){
        flag=2;
    }else if(ui->set_ud->isChecked()){
        flag=3;
    }
    max_value=*max_vector.at(flag);
    qDebug()<<"max_value"<<max_value;
    for(int i=0;i<line_vector.at(flag)->y.count();i++)
    {
        value= line_vector.at(flag)->y.at(i);
        tempValue = ( value/ max_value) *(float) 32767.0;      //比例转换,
        toSendData<< (quint16)((tempValue>0)?(tempValue+0.5):(tempValue-0.5));		//减小量化误差
    }
    QString file_name = QFileDialog::getSaveFileName(NULL,"保存波形文件","./","*.daw");
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

void active_wave::on_open_wave_clicked()
{
    int flag=0;
    if(ui->set_ua->isChecked()){
        flag=0;
    }else if(ui->set_ub->isChecked()){
        flag=1;
    }else if(ui->set_uc->isChecked()){
        flag=2;
    }else if(ui->set_ud->isChecked()){
        flag=3;
    }

    wave_vector.at(flag)->clear();
    QString file_name = QFileDialog::getOpenFileName(NULL,"波形文件","./","*.daw");
    QFile file(file_name);

    if (!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(this," ","打开失败!");
        return;
    }
    QDataStream in(&file);
    quint8 byte;
    QByteArray arry;
    while(!in.atEnd())
    {
        in>>byte;
        wave_vector.at(flag)->append(byte);
        arry.append(byte);
    }
    file.close();
    show_wave(arry);
    wave_vector.at(flag)->remove(0,8);
    start_down=false;
}
void active_wave::show_line()
{
    double value=0;
    double max_value=0;
    double rms=0;
    int flag=0;
    double time=0;
    if(ui->set_ua->isChecked()){
        flag=0;
    }else if(ui->set_ub->isChecked()){
        flag=1;
    }else if(ui->set_uc->isChecked()){
        flag=2;
    }else if(ui->set_ud->isChecked()){
        flag=3;
    }
    if(line_vector.at(flag)->y.count()<1)
    {
//        QMessageBox *box = new QMessageBox(QMessageBox::Information,tr("提示"),tr("无波形数据。"),0,this);
//        QTimer::singleShot(1500,box,SLOT(accept()));
//        box->exec();
        return;
    }
    for(int i=0;i<line_vector.at(flag)->y.count();i++)
    {
        value=line_vector.at(flag)->y.at(i);
        rms+=(value*value);
        qAbs(value)>max_value?max_value=qAbs(value):max_value;
    }
    time=line_vector.at(flag)->x.last();
    line->setData(line_vector.at(flag)->x,line_vector.at(flag)->y);
    QSharedPointer<QCPAxisTickerFixed> ticker(new QCPAxisTickerFixed);
    ticker->setTickStep(QString::number(time/10,'f',4).toFloat());
    ui->show_wave->xAxis->setTicker(ticker);
    ui->show_wave->xAxis->setRange(0,time*1.01);
    ui->max_value->setValue(max_value);
    ui->rms->setText(QString("%1").arg(sqrt(rms/line_vector.at(flag)->x.count())));
    ui->show_wave->replot();
}
void active_wave::set_line_data(int u_all,int num)
{
    float all_time=0;
    bool ok=false;
    double value=0;
    double max_value=0;
    float step=(float)1/(ui->sampling->value()*1000);
    QString str = QString::number(step, 'f', 2);
    step=str.toFloat();
    double time=0;
    QString formula;
    QString now_formula;
    for(int x=0;x<num;u_all++,x++)
    {
        all_time=0;
        ok=false;
        value=0;
        step=(float)1/(ui->sampling->value()*1000);
        time=0;
        formula="";
        now_formula="";
        max_value=0;
        QMap<int,rule_value>::iterator it=map.at(u_all)->begin();
        line_vector.at(u_all)->x.clear();
        line_vector.at(u_all)->y.clear();
        *max_vector.at(u_all)=0;
        for(;it!=map.at(u_all)->end();it++)
        {
            time=0;
            time=((rule_value)it.value()).time.toDouble(&ok);
            if(ok&&time>0)
            {
                formula=((rule_value)it.value()).rule;
                for(double i=0;i<time;i+=step)
                {
                    now_formula=formula;
                    now_formula=now_formula.toLower();
                    now_formula.replace("ti",QString("%1").arg(i,0,'f',10));
                    if(xl609->getCalculatorValue(now_formula.toLatin1().data(),value)==(quint8)-1)
                    {
                        QMessageBox::information(this,"异常","解析公式失败！");
                        return;
                    }
                    line_vector.at(u_all)->x<<all_time;
                    line_vector.at(u_all)->y<<value;
                    qAbs(value)>max_value?max_value=qAbs(value):max_value;
                    if(i<time-step)
                        all_time+=step;
                }
            }
        }
        *sample_vector.at(u_all)=ui->sampling->value();
        get_box(u_all)->set_value(0);
        *max_vector.at(u_all)=max_value;
        wave_vector.at(u_all)->clear();
        QVector<quint16> toSendData;
        float tempValue;
        for(int i=0;i<line_vector.at(u_all)->y.count();i++)
        {
            //比例转换,
            tempValue = ( line_vector.at(u_all)->y.at(i)/ max_value) *(float) 32767.0;
            toSendData<< (quint16)((tempValue>0)?(tempValue+0.5):(tempValue-0.5));		//减小量化误差
        }
        for(int i=0;i<toSendData.count();i++)
        {
            wave_vector.at(u_all)->append(*((quint8 *)(&toSendData[i])));
            wave_vector.at(u_all)->append(*((quint8 *)(&toSendData[i])+1));
        }
    }
    xl609->get_dma_freq(XL803::ACTIVE_WAVE);
    if(line_vector.at(0)->x.count()>0&&line_vector.at(1)->x.count()>0&&line_vector.at(2)->x.count()>0)
    {
        data_creator_flag=true;
    }
}
void active_wave::on_priview_wave_clicked()
{
//    time=line_vector.at(flag)->x.last();
//    if(time==0)
//    {
//        QMessageBox::information(this,"","总持续时间为零.");
//        return;
//    }
//    if(time>=max_time_lenth&&max_time_lenth!=0)
//    {
//        QMessageBox::information(this,"","波形过长");
//        return;
//    }
    int flag=0;
    if(ui->set_ua->isChecked()){
        flag=0;
    }else if(ui->set_ub->isChecked()){
        flag=1;
    }else if(ui->set_uc->isChecked()){
        flag=2;
    }else if(ui->set_ud->isChecked()){
        flag=3;
    }
//    if(data_creator_flag==false)
//    {
        set_line_data(flag,1);
//    }
    show_line();
    start_down=false;
}

void active_wave::on_out_now_wave_clicked()
{
    if(MainWindow::connect_flag!=true)
    {
        QMessageBox *box = new QMessageBox(QMessageBox::Information,tr("提示"),tr("无连接，请检测通讯设置!"),0,this);
        QTimer::singleShot(1500,box,SLOT(accept()));
        box->exec();
        return;
    }
    xl609->last_contorl=1;
    quint8 pipe=0;
    int flag=0;
    if(ui->set_ua->isChecked()){
        flag=0;
        pipe=0;
    }else if(ui->set_ub->isChecked()){
        flag=1;
        pipe=2;
    }else if(ui->set_uc->isChecked()){
        flag=2;
        pipe=4;
    }else if(ui->set_ud->isChecked()){
        flag=3;
        pipe=6;
    }
    if(wave_vector.at(flag)->count()<1)
    {
        QMessageBox::information(this," ","无波形数据，请生成波形或者打开波形文件.");
    }
    //qDebug()<<(quint32)wave_vector.at(flag)->count();
    down_flag=flag;
    down_num=0;
    set_enable(false);
    //qDebug()<<*(sample_vector.at(down_flag));
    xl609->start_down_simpdata((quint32)wave_vector.at(flag)->count(),(quint32)(*(sample_vector.at(flag))*1000),\
                               ui->byte_length->text().toInt(),pipe,1,XL803::ACTIVE_WAVE);
}

void active_wave::on_start_out_clicked()
{
    if(xl609->last_contorl!=1)
    {
        QMessageBox::information(this,"提示","波形数据已更改，请重新应用波形！");
        qDebug()<<"上一次操作为状态序列";
        return;
    }
    if(MainWindow::connect_flag!=true)
    {
        QMessageBox *box = new QMessageBox(QMessageBox::Information,tr("提示"),tr("无连接，请检测通讯设置!"),0,this);
        QTimer::singleShot(1500,box,SLOT(accept()));
        box->exec();
        return;
    }
    QByteArray arry;
    quint8 pipe=0;
    QMap<XL803::MARKERB, qint32> max_type;
    int start_num=0;
    bool mesg=false;
    if(ui->start_ua->isChecked())
    {
        max_type.insert(XL803::MARKERB_WAVE_UA,xl609->float_to_quint(ui->max_value->value()));
        max_type.insert(XL803::MARKERB_WT_UA,4);
        max_type.insert(XL803::MARKERB_DUA,0x55);
        //pipe=0;
        arry.append(pipe);
        qDebug()<<"ua_max"<<ua_max;
        start_num+=1;
    }
    if(ui->start_ub->isChecked())
    {
        max_type.insert(XL803::MARKERB_WAVE_UB,xl609->float_to_quint(ui->max_value->value()));
        max_type.insert(XL803::MARKERB_WT_UB,4);
        max_type.insert(XL803::MARKERB_DUB,0x55);
        pipe=2;
        arry.append((quint8)2);
        qDebug()<<"ub_max"<<ub_max;
        start_num+=2;
    }
    if(ui->start_uc->isChecked())
    {
        max_type.insert(XL803::MARKERB_WAVE_UC,xl609->float_to_quint(ui->max_value->value()));
        max_type.insert(XL803::MARKERB_WT_UC,4);
        max_type.insert(XL803::MARKERB_DUC,0x55);
        pipe=4;
        arry.append((quint8)4);
        qDebug()<<"uc_max"<<uc_max;
        start_num+=4;
    }
    if(ui->start_ud->isChecked())
    {
        max_type.insert(XL803::MARKERB_WAVE_UD,xl609->float_to_quint(ui->max_value->value()));
        max_type.insert(XL803::MARKERB_WT_UD,4);
        max_type.insert(XL803::MARKERB_DUD,0x55);
        pipe=6;
        arry.append((quint8)4);
        qDebug()<<"ud_max"<<ud_max;
        start_num+=6;
    }
    if(max_type.count()<1)
    {
        QMessageBox::information(this,"提示","请选择输出相!");
        return;
    }
    if(start_num!=1&&start_num!=2&&start_num!=4&&start_num!=6)
    {
        float time1=0;
        float time2=0;
        float time3=0;
        float time4=0;
        QMap<int,rule_value>::iterator ua_it=ua_rule_map.begin();
        QMap<int,rule_value>::iterator ub_it=ub_rule_map.begin();
        QMap<int,rule_value>::iterator uc_it=uc_rule_map.begin();
        QMap<int,rule_value>::iterator ud_it=ud_rule_map.begin();
        for(;ua_it!=ua_rule_map.end();ua_it++)
        {
            time1+=((rule_value)ua_it.value()).time.toFloat();
        }
        for(;ub_it!=ub_rule_map.end();ub_it++)
        {
            time2+=((rule_value)ub_it.value()).time.toFloat();
        }
        for(;uc_it!=uc_rule_map.end();uc_it++)
        {
            time3+=((rule_value)uc_it.value()).time.toFloat();
        }
        for(;ud_it!=ud_rule_map.end();ud_it++)
        {
            time4+=((rule_value)ud_it.value()).time.toFloat();
        }
        switch (start_num) {
        case 3:
            if(time1!=time2)
            {
                mesg=true;
            }
            break;
        case 5:
            if(time1!=time3)
            {
                mesg=true;
            }
            break;
        case 6:
            if(time2!=time3)
            {
                mesg=true;
            }
            break;
        case 7:
            if(time1!=time4)
            {
                mesg=true;
            }
            break;
        case 8:
            if(time2!=time4)
            {
                mesg=true;
            }
            break;
        case 10:
            if(time3!=time4)
            {
                mesg=true;
            }
            break;
        case 13:
            if(time1!=time2||time2!=time3||time1!=time3||time1!=time4)
            {
                mesg=true;
            }
            break;
        }
    }
    if(mesg)
    {
        QMessageBox::StandardButton rb = QMessageBox::information(this, "提示", "输出相持续时间不一致,\n是否继续输出？", \
                                                                  QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
        if(rb == QMessageBox::No)
        {
            return;
        }
    }
    max_type.insert(XL803::TRIGE_TYPE,ui->tigger_type->value());
    xl609->COM_HightWrite(max_type,XL803::ACTIVE_WAVE);
    xl609->output_simpdata_start((quint8)ui->out_count->value(),arry,XL803::ACTIVE_WAVE);
}

void active_wave::on_stop_out_clicked()
{
    if(MainWindow::connect_flag!=true)
    {
        QMessageBox *box = new QMessageBox(QMessageBox::Information,tr("提示"),tr("无连接，请检测通讯设置!"),0,this);
        QTimer::singleShot(1500,box,SLOT(accept()));
        box->exec();
        return;
    }
    QByteArray arry;
    quint8 pipe=0;
    QMap<XL803::MARKERB, qint32> max_type;
    if(ui->start_ua->isChecked())
        arry.append(pipe);
    if(ui->start_ub->isChecked())
        arry.append((quint8)2);
    if(ui->start_uc->isChecked())
        arry.append((quint8)4);
    if(ui->start_ud->isChecked())
        arry.append((quint8)6);
    xl609->output_simpdata_stop(arry,XL803::ACTIVE_WAVE);
}

void active_wave::on_all_start_clicked()
{
    if(MainWindow::connect_flag!=true)
    {
        QMessageBox *box = new QMessageBox(QMessageBox::Information,tr("提示"),tr("无连接，请检测通讯设置!"),0,this);
        QTimer::singleShot(1500,box,SLOT(accept()));
        box->exec();
        return;
    }
   ui->start_ua->setChecked(true);
   ui->start_ub->setChecked(true);
   ui->start_uc->setChecked(true);
   ui->start_ud->setChecked(true);
   on_start_out_clicked();
}

void active_wave::on_all_stop_clicked()
{
    if(MainWindow::connect_flag!=true)
    {
        QMessageBox *box = new QMessageBox(QMessageBox::Information,tr("提示"),tr("无连接，请检测通讯设置!"),0,this);
        QTimer::singleShot(1500,box,SLOT(accept()));
        box->exec();
        return;
    }
    QByteArray arry;
    arry.append((quint8)0x55);
    xl609->output_simpdata_stop(arry,XL803::ACTIVE_WAVE);
}
void  active_wave::show_wave(QByteArray  data)
{
    ui->byte_length->setReadOnly(true);
    quint32 sampling=*((quint32 *)data.data());
    ui->sampling->setValue(sampling/1000);
    all_byte=qCeil((float)data.count()/ui->byte_length->value());
    data.remove(0,4);
    float max_value=*((float *)data.data());
    ui->max_value->setValue(max_value);
    data.remove(0,4);
    float p_num=data.count()/2;
    float step=1.0/sampling;
    float index=0;
    int flag=0;
    if(ui->set_ua->isChecked()){
        flag=0;
    }else if(ui->set_ub->isChecked()){
        flag=1;
    }else if(ui->set_uc->isChecked()){
        flag=2;
    }else if(ui->set_ud->isChecked()){
        flag=3;
    }
    *sample_vector.at(flag)=sampling/1000;
    *max_vector.at(flag)=max_value;
    QSharedPointer<QCPAxisTickerFixed> ticker(new QCPAxisTickerFixed);
    ticker->setTickStep(QString::number((p_num/sampling)/10,'f',4).toFloat());
    qDebug()<<p_num/sampling+(1.0/(sampling+1000))/10;
    ui->show_wave->xAxis->setTicker(ticker);
    ui->show_wave->xAxis->setRange(0,(p_num/sampling)*1.01);
    ui->show_wave->yAxis->setRange(0-max_value*1.2,max_value*1.2);
    line_vector.at(flag)->x.clear();
    line_vector.at(flag)->y.clear();
    for(int i=0;i<p_num;i++)
    {
        line_vector.at(flag)->x<<index;
        line_vector.at(flag)->y<<*(qint16 *)data.data()/32767.0*max_value;
        data.remove(0,2);
        index+=step;
    }
    line->setData(line_vector.at(flag)->x,line_vector.at(flag)->y);
    ui->show_wave->replot();
}
void active_wave::recv_mesg(QByteArray send,QByteArray read)
{
    quint8 null=0;
    if(start_down)
    {
        if((quint8)read[5]==0x10)
        {
            if(now_byte==all_byte-1)
            {
                start_down=false;
                xl609->stop_down_simpdata(XL803::ACTIVE_WAVE);
                ui->byte_length->setReadOnly(false);
                dialog->setValue(dialog->value()+one_wave.length());
                down_wave.clear();
                one_wave.clear();
                check_byte=0;
                return;
            }
            dialog->setValue(dialog->value()+one_wave.length());
            down_wave.remove(0,one_wave.length());
            one_wave.clear();
            check_byte=0;
            for(int i=0;i<ui->byte_length->text().toInt();i++)
            {
                if(i<down_wave.length())
                {
                    one_wave.append(down_wave.at(i));
                    check_byte+=down_wave.at(i);
                }else
                {
                    one_wave.append(null);
                }
            }
            now_byte++;
        }
        xl609->down_simpdata(now_byte,one_wave,check_byte,XL803::ACTIVE_WAVE);
    }else if((quint8)send[5]==0xB0)
    {
        if((quint8)read[5]!=0x10)
        {
            QMessageBox::information(this," ","写入应答错误!");
            return;
        }
        check_byte=0;
        dialog->show();
        //int one_size=ui->byte_length->text().toInt();
        //int add=all_byte*one_size;
        all_byte=qCeil((float)wave_vector.at(down_flag)->count()/ui->byte_length->value());
        QString la;
        if(down_flag==0){
            la="UA";
        }else if(down_flag==1){
            la="UB";
        }else if(down_flag==2){
            la="UC";
        }else if(down_flag==3){
            la="UD";
        }
        la+="波形数据下载中...";
        dialog->setLabelText(la);
        dialog->setRange(1,all_byte*ui->byte_length->text().toInt());
        start_down=true;
        down_wave.clear();
        one_wave.clear();
        down_wave=*wave_vector.at(down_flag);
        now_byte=0;
        for(int i=0;i<ui->byte_length->text().toInt();i++)
        {
            if(i<down_wave.count())
            {
                one_wave.append(down_wave.at(i));
                check_byte+=(quint8)down_wave.at(i);
            }else
            {
                one_wave.append(null);
            }
        }
        // QCoreApplication::processEvents();
        xl609->down_simpdata(now_byte,one_wave,check_byte,XL803::ACTIVE_WAVE);
    }else if((quint8)send[5]==0xB2)
    {
        if(cancel_flag)
        {
            cancel_flag=false;
            QMessageBox::information(this,"提示","下载已取消.");
            return;
        }
        get_box(down_flag)->set_value(1);
        if(down_num>0&&down_num<3)
        {
            if(down_flag<2)
                down_flag++;
            if(down_flag<3)
            {
                quint8 pipe=0;
                if(down_flag==1)
                    pipe=2;
                if(down_flag==2)
                    pipe=4;
                qDebug()<<"down"<<pipe;
                qDebug()<<*(sample_vector.at(down_flag));
                xl609->start_down_simpdata((quint32)wave_vector.at(down_flag)->count(),(quint32)(*(sample_vector.at(down_flag))*1000),\
                                       ui->byte_length->text().toInt(),pipe,1,XL803::ACTIVE_WAVE);
            }
            down_num++;
        }else
        {
            down_num=0;
            down_flag=0;
            set_enable(true);
            QMessageBox::information(this,"提示","下载完毕!");
        }
    }else if((quint8)send[5]==0xB3)
    {
        read.remove(0,6);
        quint32 freq=*((quint32 *)read.data());
        read.remove(0,4);
        max_time_lenth=(*((quint32 *)read.data()))/(float)freq;
        qDebug()<<max_time_lenth;
    }else if((quint8)send[5]==0xB4)
    {
        if(ui->start_ua->isChecked()){
            ui->ua_state->set_value(2);
        }
        if(ui->start_ub->isChecked()){
            ui->ub_state->set_value(2);
        }
        if(ui->start_uc->isChecked()){
           ui->uc_state->set_value(2);
        }
        if(ui->start_ud->isChecked()){
           ui->ud_state->set_value(2);
        }
    }else if((quint8)send[5]==0xB5)
    {
        if(ui->start_ua->isChecked()){
            ui->ua_state->set_value(1);
        }
        if(ui->start_ub->isChecked()){
            ui->ub_state->set_value(1);
        }
        if(ui->start_uc->isChecked()){
           ui->uc_state->set_value(1);
        }
        if(ui->start_ud->isChecked()){
           ui->ud_state->set_value(1);
        }
    }
}

void active_wave::on_max_value_valueChanged(double arg1)
{
//    if(init==false)
//        return;
    ui->show_wave->yAxis->setRange(0-arg1*1.2,arg1*1.2);
}

void active_wave::on_formula_valueChanged(int arg1)
{
    int row=ui->formula_table->currentIndex().row();
    if(row<0)
        return;
    model->item(row,0)->setData(ui->formula->text(),Qt::EditRole);
    model->item(row,0)->setToolTip(ui->formula->text());
    model->item(row,1)->setText("0.02");
    model->item(row,1)->setToolTip("0.02");
    rule_value rula;
    rula.rule=ui->formula->text();
    rula.time="0.02";
    if(ui->set_ua->isChecked()){
        ua_rule_map.insert(row,rula);
    }else if(ui->set_ub->isChecked()){
        ub_rule_map.insert(row,rula);
    }else if(ui->set_uc->isChecked()){
        uc_rule_map.insert(row,rula);
    }else if(ui->set_ud->isChecked()){
        ud_rule_map.insert(row,rula);
    }
    data_creator_flag=false;
}

m_checkbox *active_wave::get_box(int index)
{
    int m_index=0;
    if(index==-1)
    {
 //       m_index=ui->out_pipe->value();
    }else
    {
        m_index=index;
    }
    switch (m_index) {
    case 0:
        return ui->ua_state;
    case 1:
        return ui->ub_state;
    case 2:
        return ui->uc_state;
    case 3:
        return ui->ud_state;
    default:
        return ui->ua_state;
    }
}
void active_wave::set_enable(bool flag)
{
  //  ui->max_value->setEnabled(flag);
    ui->byte_length->setEnabled(flag);
    ui->sampling->setEnabled(flag);
}

void active_wave::on_priview_all_wave_clicked()
{
    set_line_data();
    show_line();
    start_down=false;
}

void active_wave::on_out_all_wave_clicked()
{
    if(MainWindow::connect_flag!=true)
    {
        QMessageBox *box = new QMessageBox(QMessageBox::Information,tr("提示"),tr("无连接，请检测通讯设置!"),0,this);
        QTimer::singleShot(1500,box,SLOT(accept()));
        box->exec();
        return;
    }
    xl609->last_contorl=1;
    QString str;
    int flag=0;
    quint8 pipe=0;
    if(wave_vector.at(0)->count()<1)
    {
        str="UA ";
        flag=1;
    }
    if(wave_vector.at(1)->count()<1)
    {
        str+="UB ";
        flag=1;
    }
    if(wave_vector.at(2)->count()<1)
    {
        str+="UC ";
        flag=1;
    }
    if(wave_vector.at(3)->count()<1)
    {
        str+="UD ";
        flag=1;
    }
    if(flag)
    {
        str+="无波形数据，请生成波形或者打开波形文件.";
        QMessageBox::information(this,"提示",str);
        return;
    }
    down_flag=0;
    down_num=1;
    set_enable(false);
    qDebug()<<*(sample_vector.at(down_flag));
    xl609->start_down_simpdata((quint32)wave_vector.at(down_flag)->count(),(quint32)(*(sample_vector.at(down_flag))*1000),\
                               ui->byte_length->text().toInt(),pipe,1,XL803::ACTIVE_WAVE);
}
void active_wave::showListWidgetMenuSlot(QPoint pos)
{
    m_contextMenu->exec(QCursor::pos());
}
void active_wave::copy_one(bool)
{
    int row=ui->formula_table->currentIndex().row();
    int flag=get_set_flag();
    QMap<int,rule_value>::iterator it=map.at(flag)->begin();
    it=map.at(flag)->find(row);
    if(it!=map.at(flag)->end())
    {
        m_past->setEnabled(true);
        copy_row=it.key();
        copy_flag=1;
        copy_phase=flag;
        QClipboard *board = QApplication::clipboard();
        if(ui->formula_table->currentIndex().column()==0)
        {
            board->setText(((rule_value)it.value()).rule);
        }else
        {
            board->setText(((rule_value)it.value()).time);
        }
    }
}

void active_wave::copy_all(bool)
{
    int flag=get_set_flag();
    int all=map.at(flag)->count();
    if(all>0)
    {
        m_past->setEnabled(true);
        copy_flag=2;
        copy_phase=flag;
        QClipboard *board = QApplication::clipboard();
        board->setText(ui->formula_table->currentIndex().data(Qt::EditRole).toString());
    }
}

void active_wave::past(bool)
{
    int flag=get_set_flag();
    if(copy_flag==1)
    {
        QMap<int,rule_value>::iterator it=map.at(copy_phase)->begin();
        QMap<int,rule_value>::iterator it_1=map.at(flag)->begin();
        it=map.at(copy_phase)->find(copy_row);
        it_1=map.at(flag)->find(copy_row);
        if(it_1==map.at(flag)->end())
        {
            map.at(flag)->insert(it.key(),it.value());
        }else
        {
            map.at(flag)->insert(ui->formula_table->currentIndex().row(),it.value());
        }

    }else if(copy_flag==2)
    {
        if(copy_phase!=flag)
        {
            map.at(flag)->clear();
            *map.at(flag)=*map.at(copy_phase);
        }
    }
    show_rula(0);
}
int  active_wave::get_set_flag()
{
    if(ui->set_ua->isChecked()){
        return 0;
    }else if(ui->set_ub->isChecked()){
        return 1;
    }else if(ui->set_uc->isChecked()){
        return 2;
    }else if(ui->set_ud->isChecked()){
        return 3;
    }
}
void   active_wave::remove_one(bool)
{
    int row=ui->formula_table->currentIndex().row();
    int flag=get_set_flag();
    QMap<int,rule_value>::iterator it=map.at(flag)->begin();
    it=map.at(flag)->find(row);
    if(it!=map.at(flag)->end())
    {
        map.at(flag)->remove(it.key());
        if(m_past->isEnabled()&&copy_phase==flag&&copy_row==row)
        {
            copy_row=0;
            copy_flag=0;
            copy_phase=0;
            m_past->setEnabled(false);
        }
    }
    show_rula(0);
}
