#include "wave_reout.h"
#include "ui_wave_reout.h"

Wave_reout::Wave_reout(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Wave_reout)
{
    ui->setupUi(this);
    ui->new_file->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->out_file->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    on_update_list_clicked();
    //启用线程进行处理
    m_file.moveToThread(&file_thread);
    m_formula.moveToThread(&formula_thread);
    ui->tabWidget->tabBar()->hide();
    ui->tabWidget_2->tabBar()->hide();
    file_thread.start();
    formula_thread.start();
    ui->d->hide();
    ui->label_41->hide();
    ui->label_42->hide();
    ui->ud_max->hide();
    ui->id_max->hide();
    ui->label_30->hide();
    ui->label_31->hide();
    ui->ud_pipe->hide();
    ui->id_pipe->hide();
    qRegisterMetaType<QVector<int> >("QVector<int>");
    qRegisterMetaType<QVector<float> >("QVector<float>");
    qRegisterMetaType<QVector<double> >("QVector<double>");
    qRegisterMetaType<QVector<QString> >("QVector<QString>");
/*    timer.setInterval(3000);
    timer.setSingleShot(true);	*/		//单次
    //connect(&timer,SIGNAL(timeout()),this,SLOT(start_send()));
//    connect(this,SIGNAL(send_path(QString , double, int)),&m_file,\
//            SLOT(file(QString , double, int)),Qt::QueuedConnection);
//    connect(L_XL803,SIGNAL(send_to_wave_reout(QByteArray,QByteArray)),\
//            SLOT(recv(QByteArray,QByteArray)),Qt::QueuedConnection);
   //connect(this,SIGNAL(send_out_path(QString ,QVector<int>,QVector<int>,int )),\
            &m_file,SLOT(out_file(QString ,QVector<int>,QVector<int>,int )),Qt::QueuedConnection);
    //录波文件名与采样率的信号槽关联
//    connect(this,SIGNAL(comtrade_path(QString,double)),&m_file,SLOT(comtrade_convert(QString,double)),Qt::QueuedConnection);
//    connect(&m_file,SIGNAL(send_mesg(int,int)),this,SLOT(show_dialog(int,int)),Qt::QueuedConnection);
//    connect(this,SIGNAL(priview_map(int ,int ,QString,int)),&m_file,SLOT(show_map(int ,int ,QString,int)),Qt::QueuedConnection);
//    connect(&m_file,SIGNAL(send_vector(QVector<double>,QVector<double>,double,float)),this,\
//            SLOT(m_priview(QVector<double>,QVector<double>,double,float)),Qt::QueuedConnection);
//    connect(&m_formula,SIGNAL(data_ready()),this,SLOT(start_send()),Qt::QueuedConnection);
//    connect(this,SIGNAL(start_formula(double , QVector<int> ,QVector<QString>)),&m_formula,\
//            SLOT(formula_data(double , QVector<int> ,QVector<QString> )),Qt::QueuedConnection);
//    connect(ui->update,SIGNAL(clicked()),this,SLOT(read_formula_file()));
    dialog=new  QProgressDialog(tr("格式转换进度"), tr("确定"), 0, 1, this);
    dialog->setWindowTitle("格式转换进度");
    dialog->setWindowModality(Qt::WindowModal);
    dialog->setValue(1);
    line=ui->widget->addGraph();
    line->setPen(QPen(Qt::yellow,1));
    byte_data test_data;
    test_data.byte_32=1;
    L_XL803->set_map(ui->widget);
    ui->no_stop->hide();
    ui->label_45->hide();
    ui->d_f->hide();
    ui->start_out->hide();
    stop_memory.setKey("share_memory");
    read_formula_file();
}
file_control::file_control(QObject *parent){}
file_control::~file_control(){}
formula_control::formula_control(QObject *parent)
{
    send_memory.setKey("share_memory");
    all_lenth=BYTE_LEN*100;
    start_flag=false;
    qDebug()<<"creator:"<<send_memory.create(all_lenth+32);
    send_memory.attach();
}
formula_control::~formula_control(){}
Wave_reout::~Wave_reout()
{
    delete ui;
}
void Wave_reout::show_dialog(int index,int value)
{
    switch (index) {
    case 0:
        dialog->setLabelText(tr("文件加载中..."));
        dialog->setRange(0,value);
        dialog->show();
        break;
    case 1:
        dialog->setLabelText(tr("格式转换中..."));
        dialog->setRange(0,value);
        dialog->show();
        break;
    case 2:
        dialog->setLabelText(tr("文件生成中..."));
        dialog->setRange(0,value);
        dialog->show();
        break;
    case 3:
        dialog->setValue(value);
        break;
    case 4:
        updata_out_file();
        break;
    case 5:
        updata_new_file();
        break;
    default:
        break;
    }
}
void Wave_reout::recv(QByteArray wb, QByteArray rb)
{
    if((quint8)wb[5]==0xBD&&(is_big==false))
    {
        now_out_path=out_path_name.at(ui->out_file->currentIndex().row());
        out_count=ui->start_out->value();
        emit send_out(out_path_name.at(ui->out_file->currentIndex().row()));
    }
}
void Wave_reout::on_update_list_clicked()
{
    //updata_old_file();
    updata_new_file();
    updata_out_file();
    QString file(".//wave_file_reset_sample//");
    QDir new_dir;
    if(!new_dir.exists(file))
    {
        new_dir.mkpath(file);
    }
}

void Wave_reout::on_change_file_clicked()
{
    QSettings Settings("XL","9201");
    //弹出对话框
    QString file_name = QFileDialog::getOpenFileName(NULL,"打开录波文件",Settings.value("path").toString(),"*.*");
    //获取到文件名称
    QFile file(file_name);
    QString set_path=file_name;
    set_path.remove(set_path.lastIndexOf("/"),set_path.length()-set_path.lastIndexOf("/"));
    qDebug()<<set_path;
    Settings.setValue("path",QVariant(set_path));
    if(file_name.isEmpty())
    {

    }else{
        //把文件名改为小写
        file_name=file_name.toLower();
        QRegExp rx("\\S+.d\\d\\d");
        rx.exactMatch(file_name);
        //查看文件后缀是否正确
        if(rx.exactMatch(file_name)||\
           file_name.contains(".hdr")||\
           file_name.contains(".cfg")||\
           file_name.contains(".dat")||\
           file_name.contains(".inf"))
        {
            //sample:采样率
            emit comtrade_path(file_name,ui->sample->value());
        }else{
            emit send_path(file_name,ui->sample->value(),2000);
        }
    }
}
/**
 * @brief file_control::file
 *  初步处理将波形文件重采样并转换为二进制文件
 * @param file_name
 * @param sample
 * @param byte_lenth
 */
void file_control::file(QString file_name,double sample,int byte_lenth)
{
    QFile file(file_name);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(NULL,"提示","文件打开失败！");
        return;
    }
    file_name.remove(file_name.lastIndexOf('.'),file_name.length()-file_name.lastIndexOf('.'));
    while(file_name.indexOf('/')>=0)
        file_name.remove(0,file_name.indexOf('/')+1);
    file_name.insert(0,"./wave_file_reset_sample/");
    qDebug()<<file_name;
    file_name.append(QString("_%1k.bin").arg(sample));
    QFile sample_file(file_name);
    if (!sample_file.open(QIODevice::ReadWrite)) {
        QMessageBox::information(NULL,"提示","文件创建失败！");
        return;
    }
    QTextStream in(&file);
    /**
     * @brief m_out
     * 临时数据存放文件用于存放插值后但未转换比例的数据
     */
    QDataStream m_out(&sample_file);
    QList<float> max_value;
    QString value;
    double wave_sample=0;
    sample*=1000;
    value=in.readLine();
    value=value.mid(value.indexOf(',')+1);
    int num=value.toInt();
    int value_count=0;
    quint32 block_size=0;
    for(int i=0;i<num;i++)
    {
        value=in.readLine();
        //qDebug()<<value;
        if(value.indexOf("SampleRate")>-1)
        {
            value.remove(0,value.indexOf(",")+1);
            wave_sample=value.mid(0,value.indexOf(",")).toDouble();
        }else if(value.indexOf("BlockSize")>-1)
        {
            value.remove(0,value.indexOf(",")+1);
            block_size=value.mid(0,value.indexOf(",")).toInt();
        }else if(value.indexOf("TraceName")>-1)
        {
            value_count=std::count(value.begin(), value.end(), ',');
        }
    }//解析头结束
    float inIndexF=0;
    quint32 inIndexI=0;		//原始数据位置
    float now_value = 0;
    float t =0;
    QList<QList<float>*> in_value;
    QList<QList<float>*> out_value;
    double n=0;
    int index;
    for(int i=0;i<value_count;i++)
    {
        in_value.append(new QList<float>);
        out_value.append(new QList<float>);
        max_value.append(0);
    }
    quint32 all_size = block_size;
    emit send_mesg(0,all_size);
    int p_num=0;
    int size=0;
//    quint32 index_lenth=0;
//    int flag=outSize/100;
//    double now_sample=wave_sample /(quint32)sample ;
    quint32 outSize=0;
    float tt = 0;
    while(!in.atEnd())
    {
        for(int i=0;i<value_count;i++)
        {
            in_value[i]->clear();
            out_value[i]->clear();
        }
        n=0;
        for(int i=0;i<5000&&(!in.atEnd());i++)
        {
            value=in.readLine();
            value.remove(0,value.indexOf(",")+1);
            for(int j=0;j<value_count;j++)
            {
                index=value.indexOf(',');
                now_value=value.mid(0,index).toFloat();
                value.remove(0,index+1);
                in_value[j]->append(now_value);
            }
            n++;
        }
        //插值，dataIn输入数据，inSize输入数据点数，simpIn输入数据采样率，simpOut需要输出的采样率，outSize输出的采样数据点数，maxValue采样点最大值。
            outSize = ((n/wave_sample) * sample + 0.5);			//输出采样点数个数。
            inIndexF=0;
            inIndexI=0;		//原始数据位置
            tt = 0;
            for(quint32 i = 0; i < outSize-1; i++)
            {
                inIndexF = (double)wave_sample /sample * i;
                inIndexI = (quint32)inIndexF;
                //拉格朗日插值，3点法
                //取前一点，跟后两点进行插值，时间单位分别为1，从而进行简化。
                float t = inIndexF - inIndexI;
                for(int x=0;x<value_count;x++)
                {
                out_value[x]->append(in_value[x]->value(inIndexI)*(t-(float)1.0)*(t-(float)2.0)/(float)2.0 - in_value[x]->value(inIndexI+ 1)*t*(t-(float)2.0)\
                        + in_value[x]->value(inIndexI + 2)*t*(t-(float)1.0)/(float)2.0);
                m_out<<out_value[x]->value(i);

                tt =out_value[x]->value(i);
                if(tt < 0)
                    tt = - tt;
                if(max_value.at(x) < tt)
                    max_value[x] = tt;
                }
                size++;
            }
            p_num+=n;
            emit send_mesg(3,p_num);
    }

    file.close();
    m_out.device()->seek(0);
    file_name.replace("wave_file_reset_sample","wave_file_new");
    QFile out_wave_file(file_name);
    if (!out_wave_file.open(QIODevice::WriteOnly)) {
        QMessageBox::information(NULL,"提示","文件创建失败！");
        sample_file.close();
        return;
    }/**
     * @brief out_wave
     * 用于存放处理后的数据，文件为二进制方式存储
     * 格式：
     *  double  sample采样率， int value_count 通道数, int size 单通道总数据点数
     */
    QDataStream out_wave(&out_wave_file);
    out_wave<<sample;
    out_wave<<value_count;
    if(size<62000)
        out_wave<<62000;
    else
        out_wave<<size;
    for(int i=0;i<value_count;i++)
    {
        out_wave<<max_value.at(i);
    }
    float m_now_value;
    emit send_mesg(1,size);
    int size_flag=0;
    int flag=size/100;
    while(!m_out.atEnd())
    {
        for(int x=0;x<value_count;x++)
        {
            m_out>>m_now_value;
            if(m_now_value!=0)
            {
                m_now_value=-m_now_value;
                out_wave<<(quint16)((( m_now_value/ max_value.at(x)) *(float) 32767)+(float)32767);      //比例转换,
            }else
            {
                out_wave<<(quint16)32768;
            }
        }
        size_flag++;
        if(size_flag%flag==0)
            emit send_mesg(3,size_flag);
    }
    if(size<62000){
        for(int i=size;i<=62000;i++){
            for(int x=0;x<value_count;x++){
                out_wave<<(quint16)32768;
            }
        }
    }

    emit send_mesg(3,size);
    sample_file.remove();
    sample_file.close();
    out_wave_file.close();
    emit send_mesg(5,0);
}
void file_control::comtrade_convert(QString path_name,double sample)
{
    //转换编码格式
    QTextCodec *code = QTextCodec::codecForName("gb2312");
    code->fromUnicode(path_name).data();
    //将comtrade 文件进行转换
    parse_comtrade_file(code->fromUnicode(path_name).data());
    path_name.remove(path_name.lastIndexOf("."),4);
    path_name.append(".tmp");
    qDebug()<<path_name;
    //获取结束采样时间,单位 s
    double end_time=get_end_samp_time();
    // 最大采样率*结束采样时间
    int wave_point_count=qCeil(get_max_samprate()*end_time);
    // 获取文件通道个数
    int pipe_count=get_comtrade_an_chan_num();
    QVector<double *> data;
    QFile m_file(path_name);
    QTextStream in(&m_file);
    double * p_data;
    if (!m_file.open(QIODevice::WriteOnly)) {
        QMessageBox::information(NULL,"提示","文件创建失败！");
        m_file.close();
        return;
    }
    in<<"Header Size,"<<4<<endl;
    in<<"TraceName";
    for(int i=0;i<pipe_count;i++)
    {
       in<<QString(",CH%1").arg(i+1);
       p_data=(double *)malloc(wave_point_count*sizeof(double));
       memset(p_data,0,wave_point_count*sizeof(double));
       data.append(p_data);
       if(p_data==NULL)
       {
           m_file.close();
           for(int j=0;j<data.count();j++)
               free(data[j]);
           QMessageBox::information(NULL,"提示","内存不足！");
           return;
       }
    }
    in<<endl;
    in<<"BlockSize,"<<QString::number(wave_point_count)<<endl;
    in<<"SampleRate,"<<get_max_samprate()<<endl;
    for(int i=0;i<pipe_count;i++)
            get_chan_value(i+1,0,end_time,data[i],wave_point_count*sizeof(double));
    for(int i=0;i<wave_point_count;i++)
    {
        in<<",";
        for(int j=0;j<pipe_count;j++){
            in<<QString::number(*(data[j]+i))<<",";
        }
        in<<endl;
    }
    m_file.close();
    for(int j=0;j<data.count();j++)
        free(data[j]);
    file(path_name,sample,2000);
}
/**
 * @brief file_control::out_file
 * 波形组帧生成输出文件
 * @param file_name
 * @param index_vector
 * @param pipe_vector
 * @param p_num
 */
void file_control::out_file(QString file_name,QVector<int> index_vector,QVector<int> pipe_vector,int p_num)
{
    QString str;
    quint16 add_byte=32768;
    str.append("_");
    if(index_vector.contains(0))
        str.append("A");
    if(index_vector.contains(1))
        str.append("B");
    if(index_vector.contains(2))
        str.append("C");
    if(index_vector.contains(3))
        str.append("D");
    for(int i=0;i<pipe_vector.count()-1;i+=2)
        str.append(QString("_%1_%2").arg(pipe_vector.at(i)).arg(pipe_vector.at(i+1)));
    str.append(QString("_%1.bin").arg(p_num));
    QFile wave_file(file_name);
    file_name.remove(file_name.indexOf('.'),file_name.length()-file_name.indexOf('.'));
    file_name.append(str);
    file_name.replace("wave_file_new","wave_file_out");
    QFile out_wave_file(file_name);
    if (!wave_file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(NULL,"提示","文件打开失败！");
        return;
    }
    if (!out_wave_file.open(QIODevice::WriteOnly)) {
        QMessageBox::information(NULL,"提示","文件创建失败！");
        return;
    }
    QDataStream in(&wave_file);
    double smaple=0;
    int pipe_num=0;
    float max_value=0;
    quint32 all_point=0;
    in>>smaple;
    in>>pipe_num;
    in>>all_point;
    for(int i=0;i<pipe_num;i++)
          in>>max_value;
    emit send_mesg(2,all_point);
    int add_count=all_point%p_num;
    add_count=p_num-add_count;
    quint8 head=0x68;
    byte_data len;
    len.byte_32=0;
    len.byte_16[0]=20+p_num*8;
    quint32 m_len=20+p_num*8;
    quint8 addr=0x00;
    quint8 code=0xBB;
    byte_data p_len;
    p_len.byte_32=p_num*8;
    byte_data index;
    index.byte_32=0;
    byte_data b_index;
    b_index.byte_32=0;
    quint8 check=0;
    quint8 end=0x16;
    quint32 now_count=0;
    QDataStream out(&out_wave_file);
    out<<smaple;
    qDebug()<<"out_sample"<<smaple;
    QVector<QVector<quint16> > value_vector;
    for(int i=0;i<pipe_num;i++)
    {
        value_vector.append(QVector<quint16>());
    }
    quint16 now_value=0;
    byte_data now_value2;
    now_value2.byte_32=0;
    int one_lenth=p_num;
    int n=0;
    int index_count=0;
    while(!in.atEnd())
    // while(n<5000)
    {
        index_count++;
        for(int i=0;i<p_num;i++)
        {
            for(int j=0;j<pipe_num;j++)
            {

                //if(j==0)
                  //  qDebug()<<now_value;
                if(in.atEnd())
                {
                    now_value=add_byte;
                }else
                {
                    in>>now_value;
                }
                value_vector[j].append(now_value);
                n++;
            }
        }
        for(int i=0;i<index_vector.length();i++)
        {
            //one_lenth=value_vector.at(pipe_vector.at(i*2)).count();
//            p_len=one_lenth*8;
//            len=p_len+20;
            check=0;
            out<<m_len;
            out<<head;
            out<<len.byte_8[0];
            out<<len.byte_8[1];
            out<<head;
            out<<addr;
            out<<code;
            check+=code;

            check+=p_len.byte_8[0];
            check+=p_len.byte_8[1];
            check+=p_len.byte_8[2];
            check+=p_len.byte_8[3];

            out<<p_len.byte_8[0];
            out<<p_len.byte_8[1];
            out<<p_len.byte_8[2];
            out<<p_len.byte_8[3];

            check+=index.byte_8[0];
            check+=index.byte_8[1];
            check+=index.byte_8[2];
            check+=index.byte_8[3];
            out<<index.byte_8[0];
            out<<index.byte_8[1];
            out<<index.byte_8[2];
            out<<index.byte_8[3];

            b_index.byte_32=index_vector.at(i);
            check+=b_index.byte_8[0];
            check+=b_index.byte_8[1];
            check+=b_index.byte_8[2];
            check+=b_index.byte_8[3];
            out<<b_index.byte_8[0];
            out<<b_index.byte_8[1];
            out<<b_index.byte_8[2];
            out<<b_index.byte_8[3];
            for(int j=0;j<one_lenth;j++)
            {
                now_value2.byte_16[0]=value_vector.at(pipe_vector.at(i*2)).at(j);
                check+=now_value2.byte_8[0];
                check+=now_value2.byte_8[1];
                out<<now_value2.byte_8[0];
                out<<now_value2.byte_8[1];
                out<<(quint8)0x01;
                check+=(quint8)0x01;
                out<<(quint8 )0x00;
                //qDebug()<<now_value2.byte_8[0]<<now_value2.byte_8[1]<<now_value2.byte_16[0];
                now_value2.byte_16[0]=(quint16)0xFFFF-value_vector.at(pipe_vector.at(i*2+1)).at(j);
                check+=now_value2.byte_8[0];
                check+=now_value2.byte_8[1];
                out<<now_value2.byte_8[0];
                out<<now_value2.byte_8[1];
                out<<(quint8)0x01;
                check+=(quint8)0x01;
                out<<(quint8 )0x00;
            }
            (index.byte_32)++;
            out<<check;
            out<<end;
        }
        for(int ii=0;ii<value_vector.count();ii++)
        {
            value_vector[ii].clear();
        }
        now_count+=p_num;
        emit send_mesg(3,now_count);
        //qDebug()<<now_count;
    }
    //qDebug()<<index.byte_32;
    emit send_mesg(3,all_point);
    wave_file.close();
    out_wave_file.close();
    emit send_mesg(4,all_point);
}
void Wave_reout::recv_over()
{
    if(--out_count>0)
    {
        emit send_out(now_out_path);
    }else
    {
       QMessageBox::information(this,"提示","波形传输结束!");
       qDebug()<<"here";
    }
//    emit disConnect(0,false);
}
void Wave_reout::on_checkBox_7_clicked()
{
    ui->a->setChecked(ui->checkBox_7->isChecked());
    ui->b->setChecked(ui->checkBox_7->isChecked());
    ui->c->setChecked(ui->checkBox_7->isChecked());
    ui->d->setChecked(ui->checkBox_7->isChecked());
    ui->ua_pipe->setEnabled(ui->checkBox_7->isChecked());
    ui->ia_pipe->setEnabled(ui->checkBox_7->isChecked());
    ui->ub_pipe->setEnabled(ui->checkBox_7->isChecked());
    ui->ib_pipe->setEnabled(ui->checkBox_7->isChecked());
    ui->uc_pipe->setEnabled(ui->checkBox_7->isChecked());
    ui->ic_pipe->setEnabled(ui->checkBox_7->isChecked());
    ui->ud_pipe->setEnabled(ui->checkBox_7->isChecked());
    ui->id_pipe->setEnabled(ui->checkBox_7->isChecked());
}
//void Wave_reout::updata_old_file()
//{
//    QDir old_dir;
//    while(ui->old_file->rowCount())
//        ui->old_file->removeRow(ui->old_file->rowCount()-1);
//    old_path_name.clear();
//    QString file(".//wave_file//");
//    if(!old_dir.exists(file))
//    {
//        old_dir.mkpath(file);
//    }
//    old_dir.cd(file);
//    QFileInfoList list = old_dir.entryInfoList();
//    QString name;
//    QFileInfo fileInfo;
//    for (int i = 0; i < list.size(); ++i){
//         fileInfo= list.at(i);
//        name=fileInfo.fileName();
//        if(fileInfo.size()>0&&(name.mid(name.indexOf('.'),\
//                                        name.length()-name.indexOf('.')).compare(".tmp")==0))
//        {
//            ui->old_file->insertRow(ui->old_file->rowCount());
//            ui->old_file->setItem(ui->old_file->rowCount()-1,0,new QTableWidgetItem(name));
//            old_path_name.append(fileInfo.filePath());
//        }
//    }
//}
void Wave_reout::updata_new_file()
{
    QDir new_dir;
    //把波形数据文件一行行地移除
    while(ui->new_file->rowCount())
        ui->new_file->removeRow(ui->new_file->rowCount()-1);
    //清除存在QVector中的名称
    new_path_name.clear();
    QString file(".//wave_file_new//");
    if(!new_dir.exists(file))
    {
        new_dir.mkpath(file);
    }
    new_dir.cd(file);
    //遍历文件夹中的文件名
    QFileInfoList list=new_dir.entryInfoList();
    QFileInfo fileInfo;
    QString name;
    for (int i = 0; i < list.size(); ++i){
        fileInfo = list.at(i);
        name=fileInfo.fileName();
        if(fileInfo.size()>0&&(name.mid(name.indexOf('.'),\
                                        name.length()-name.indexOf('.')).compare(".bin")==0))
        {
            ui->new_file->insertRow(ui->new_file->rowCount());
            ui->new_file->setItem(ui->new_file->rowCount()-1,0,new QTableWidgetItem(name));
            new_path_name.append(fileInfo.filePath());
        }
    }
}
void Wave_reout::updata_out_file()
{
    QDir out_dir;
    while(ui->out_file->rowCount())
        ui->out_file->removeRow(ui->out_file->rowCount()-1);
    out_path_name.clear();
    QString file(".//wave_file_out//");
    if(!out_dir.exists(file))
    {
        out_dir.mkpath(file);
    }
    out_dir.cd(file);
    QFileInfoList list=out_dir.entryInfoList();
    QFileInfo fileInfo;
    QString name;
    QTableWidgetItem * item;
    for (int i = 0; i < list.size(); ++i){
        fileInfo = list.at(i);
        name=fileInfo.fileName();
        if(fileInfo.size()>0&&(name.mid(name.indexOf('.'),\
                              name.length()-name.indexOf('.')).compare(".bin")==0))
        {
            ui->out_file->insertRow(ui->out_file->rowCount());
            item=new QTableWidgetItem(name);
            ui->out_file->setItem(ui->out_file->rowCount()-1,0,item);
            item->setToolTip(name);
            out_path_name.append(fileInfo.filePath());
        }
    }
}

void Wave_reout::on_a_clicked()
{
    ui->ua_pipe->setEnabled(ui->a->isChecked());
    ui->ia_pipe->setEnabled(ui->a->isChecked());
}

void Wave_reout::on_b_clicked()
{
    ui->ub_pipe->setEnabled(ui->b->isChecked());
    ui->ib_pipe->setEnabled(ui->b->isChecked());
}

void Wave_reout::on_c_clicked()
{
    ui->uc_pipe->setEnabled(ui->c->isChecked());
    ui->ic_pipe->setEnabled(ui->c->isChecked());
}

void Wave_reout::on_d_clicked()
{
    ui->ud_pipe->setEnabled(ui->d->isChecked());
    ui->id_pipe->setEnabled(ui->d->isChecked());
}

void Wave_reout::on_wave_start_file_clicked()
{
    if(ui->new_file->currentIndex().row()<0)
    {
        QMessageBox::information(this,"提示","请选择波形数据文件!");
    }else{
        index_vector.clear();
        pipe_vector.clear();
        if(ui->a->isChecked())
        {
            index_vector.append(0);
            pipe_vector.append(ui->ua_pipe->value()-1);
            pipe_vector.append(ui->ia_pipe->value()-1);
        }
        if(ui->b->isChecked())
        {
            index_vector.append(1);
            pipe_vector.append(ui->ub_pipe->value()-1);
            pipe_vector.append(ui->ib_pipe->value()-1);
        }
        if(ui->c->isChecked())
        {
            index_vector.append(2);
            pipe_vector.append(ui->uc_pipe->value()-1);
            pipe_vector.append(ui->ic_pipe->value()-1);
        }
        if(ui->d->isChecked())
        {
            index_vector.append(3);
            pipe_vector.append(ui->ud_pipe->value()-1);
            pipe_vector.append(ui->id_pipe->value()-1);
        }
        emit send_out_path(new_path_name.at(ui->new_file->currentIndex().row()),index_vector,\
                           pipe_vector,2000);
    }
}

void Wave_reout::on_new_file_clicked(const QModelIndex &index)
{
    QFile file(new_path_name.at(index.row()));
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(NULL,"提示","文件打开失败！");
        return;
    }
    QDataStream data(&file);
    double smaple=0;
    int pipe_num=0;
    quint32 all_size;
    data>>smaple;
    data>>pipe_num;
    data>>all_size;
    file.close();
    set_pipe_range(pipe_num-1);
    ui->pipe_num->setText(QString::number(pipe_num));
    ui->show_start->setRange(0,all_size);
    ui->show_end->setRange(0,all_size);
    ui->show_end->setValue(all_size);
}
void Wave_reout::set_pipe_range(int value )
{
    ui->ua_pipe->setRange(1,value+1);
    ui->ia_pipe->setRange(1,value+1);
    ui->ub_pipe->setRange(1,value+1);
    ui->ib_pipe->setRange(1,value+1);
    ui->uc_pipe->setRange(1,value+1);
    ui->ic_pipe->setRange(1,value+1);
    ui->ud_pipe->setRange(1,value+1);
    ui->id_pipe->setRange(1,value+1);
    ui->priview_pipe->setRange(1,value+1);
}

void Wave_reout::on_wave_start_clicked()
{
    //未连接网口
    if(!MainWindow::net_flag)
    {
        QMessageBox::information(this,"提示","请连接网口!");
        return;
    }
    //未选择波形启动文件
    if(ui->out_file->currentIndex().row()<0)
    {
        QMessageBox::information(this,"提示","请选择波形启动文件!");
    }else{
        QMap<XL803::MARKERB, qint32> max_type;
        QByteArray send_data;
        if(ui->a_2->isChecked())
        {
            max_type.insert(XL803::MARKERB_WAVE_UA,L_XL803->float_to_quint(ui->ua_max->value()));
            max_type.insert(XL803::MARKERB_WAVE_IA,L_XL803->float_to_quint(ui->ia_max->value()));
            max_type.insert(XL803::MARKERB_WT_UA,4);
            max_type.insert(XL803::MARKERB_WT_IA,4);
            send_data.append(0x55);
            send_data.append(0x55);
        }else
        {
            send_data.append(0xAA);
            send_data.append(0xAA);
        }
        if(ui->b_2->isChecked())
        {
            max_type.insert(XL803::MARKERB_WAVE_UB,L_XL803->float_to_quint(ui->ub_max->value()));
            max_type.insert(XL803::MARKERB_WAVE_IB,L_XL803->float_to_quint(ui->ib_max->value()));
            max_type.insert(XL803::MARKERB_WT_UB,4);
            max_type.insert(XL803::MARKERB_WT_IB,4);
            send_data.append(0x55);
            send_data.append(0x55);
        }else
        {
            send_data.append(0xAA);
            send_data.append(0xAA);
        }
        if(ui->c_2->isChecked())
        {
            max_type.insert(XL803::MARKERB_WAVE_UC,L_XL803->float_to_quint(ui->uc_max->value()));
            max_type.insert(XL803::MARKERB_WAVE_IC,L_XL803->float_to_quint(ui->ic_max->value()));
            max_type.insert(XL803::MARKERB_WT_UC,4);
            max_type.insert(XL803::MARKERB_WT_IC,4);
            send_data.append(0x55);
            send_data.append(0x55);
        }else
        {
            send_data.append(0xAA);
            send_data.append(0xAA);
        }

        is_big=false;
//        if(ui->d->isChecked())
//        {
//            max_type.insert(XL803::MARKERB_WAVE_UD,L_XL803->float_to_quint(ui->ud_max->value()));
//            max_type.insert(XL803::MARKERB_WAVE_ID,L_XL803->float_to_quint(ui->id_max->value()));
//            max_type.insert(XL803::MARKERB_WT_UD,4);
//            max_type.insert(XL803::MARKERB_WT_ID,4);
//            send_data.append(0x55);
//            send_data.append(0x55);
//        }else
//        {
            send_data.append(0xAA);
            send_data.append(0xAA);
//        }
        QFile file;
        double sample1=0;
        file.setFileName(out_path_name.at(ui->out_file->currentIndex().row()));
        QDataStream out(&file);
        if(!file.isOpen())
        {
            file.open(QIODevice::ReadOnly);
        }else
        {
            out.device()->seek(0);
        }

        out>>sample1;
        qint32 sample=0;
        sample=sample1;
        qDebug()<<"out:"<<sample1<<sample;
        send_data.append(*((qint8*)&sample));
        send_data.append(*((qint8*)&sample+1));
        send_data.append(*((qint8*)&sample+2));
        send_data.append(*((qint8*)&sample+3));
//        emit disConnect(0,true);
        L_XL803->COM_HightWrite(max_type,XL803::Wave_reout);
        L_XL803->big_wave_reout(send_data,XL803::Wave_reout);
        file.close();
    }
}

//void Wave_reout::on_wave_mesg_clicked()
//{
//    if(ui->old_file->currentIndex().row()<0)
//    {
//        QMessageBox::information(this,"提示","请选择原始波形数据文件!");
//    }else{
//        QFile file(old_path_name.at(ui->old_file->currentIndex().row()));
//        file.open(QIODevice::ReadOnly);
//        QTextStream in(&file);
//        QString value;
//        double wave_sample=0;
//        value=in.readLine();
//        value=value.mid(value.indexOf(',')+1);
//        int num=value.toInt();
//        int value_count=0;
//        quint32 block_size;
//        for(int i=1;i<num;i++)
//        {
//            value=in.readLine();
//            if(value.indexOf("SampleRate")>-1)
//            {
//                value.remove(0,value.indexOf(",")+1);
//                wave_sample=value.mid(0,value.indexOf(",")).toDouble();
//            }else if(value.indexOf("BlockSize")>-1)
//            {
//                value.remove(0,value.indexOf(",")+1);
//                block_size=value.mid(0,value.indexOf(",")).toInt();
//            }else if(value.indexOf("TraceName")>-1)
//            {
//                value_count=std::count(value.begin(), value.end(), ',');
//            }
//        }
//        QString str=QString("采样率:%1k\n数据点数:%2\n通道数:%3").arg(wave_sample/1000).arg(block_size).arg(value_count);
//        QMessageBox::information(this,"信息",str);
//    }
//}

void Wave_reout::on_new_wave_mesg_clicked()
{
    if(ui->new_file->currentIndex().row()<0)
    {
        QMessageBox::information(this,"提示","请选择原始波形数据文件!");
    }else{
        QFile file(new_path_name.at(ui->new_file->currentIndex().row()));
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::information(NULL,"提示","文件打开失败！");
            return;
        }
        QDataStream data(&file);
        double smaple=0;
        int pipe_num=0;
        quint32 all_size;
        data>>smaple;
        data>>pipe_num;
        data>>all_size;
        file.close();
        QString str=QString("采样率:%1k\n数据点数:%2\n通道数:%3").arg(smaple/1000).arg(all_size).arg(pipe_num);
        QMessageBox::information(this,"信息",str);
    }
}

void Wave_reout::on_priview_clicked()
{
    if(ui->new_file->currentIndex().row()<0)
    {
        QMessageBox::information(this,"提示","请选择波形数据文件!");
    }else{
        if(ui->show_end->value()-ui->show_start->value()<=0)
        {
            QMessageBox::information(this,"提示","截止点不能小于或等于起始点！");
            return;
        }
        emit priview_map(ui->show_start->value(),ui->show_end->value()\
                        ,new_path_name.at(ui->new_file->currentIndex().row()),ui->priview_pipe->value()-1);
    }
}
void file_control::show_map(int start,int end,QString path_name, int pipe)
{
    QFile file(path_name);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(NULL,"提示","文件打开失败！");
        return;
    }
    QDataStream data(&file);
    double smaple=0;
    int pipe_num=0;
    float max=0;
    QVector<float> max_value;
    quint32 all_size;
    data>>smaple;
    data>>pipe_num;
    data>>all_size;
    for(int i=0;i<pipe_num;i++)
    {
          data>>max;
          max_value<<max;
    }
    float time_step=1/smaple;
    quint16 value=0;
    double new_value=0;
    QVector<double>x,y;
    double time=time_step*start;
    int n=0;
    int count=end-start;
    //while(!data.atEnd())
    data.device()->seek(start*pipe_num*sizeof(quint16));
    float m_max=0;
    while(n<count)
    {
        for(int i=0;i<pipe_num;i++)
        {
            data>>value;
            if(i==pipe)
            {
                //qDebug()<<value;
                new_value=(value-(quint16)32767)/max_value.at(pipe);
                /*if(value<(quint16)32768)
                 {
                    new_value=0-new_value;
                }else */if(value==32768)
                {
                    new_value=0;
                }
                new_value=-new_value;
                m_max>new_value?m_max:m_max=new_value;
            }
        }
        n++;
        y<<new_value;
        x<<time;
        time+=time_step;
    }
    emit send_vector(x,y,time,m_max);
    file.close();
}
void Wave_reout::m_priview(QVector<double> x,QVector<double> y,double time,float max)
{
    line->setData(x,y);
    QSharedPointer<QCPAxisTickerFixed> ticker(new QCPAxisTickerFixed);
//    ticker->setTickStep(0.02);
//    ui->widget->xAxis->setTicker(ticker);
    ui->widget->xAxis->setRange(0,0.5);
    float lower=0;
    if(max>=0)
        lower=0-max;
    else
        lower=max*2;
    ui->widget->yAxis->setRange(lower,max);
    ui->widget->replot();

}

void Wave_reout::on_no_stop_clicked()
{
    ui->start_out->setEnabled(!ui->no_stop->isChecked());
}

void Wave_reout::on_stop_wave_clicked()
{
    out_count=1;
    emit send_stop();
}
void Wave_reout::recv_index(int  value)
{
    ui->now_index->setText(QString("%1").arg(value));
}


//void Wave_reout::on_all_clicked()
//{/*
//    ui->a_f->setChecked(ui->all->isChecked());
//    ui->b_f->setChecked(ui->all->isChecked());
//    ui->c_f->setChecked(ui->all->isChecked());
//    ui->d_f->setChecked(ui->all->isChecked());
//    */
//}

//void Wave_reout::on_start_formula_clicked()
//{

  /*  QMap<XL803::MARKERB, qint32> max_type;
    QByteArray send_data;
    int n=0;
    QVector<int> index_vector;
    if(ui->a_f->isChecked())
    {
        max_type.insert(XL803::MARKERB_WAVE_UA,L_XL803->float_to_quint(ui->ua_max->value()));
        max_type.insert(XL803::MARKERB_WAVE_IA,L_XL803->float_to_quint(ui->ia_max->value()));
        max_type.insert(XL803::MARKERB_WT_UA,4);
        max_type.insert(XL803::MARKERB_WT_IA,4);
        send_data.append(0x55);
        send_data.append(0x55);
        index_vector.append(0);
        n++;
    }else
    {
        send_data.append(0xAA);
        send_data.append(0xAA);
    }
    if(ui->b_f->isChecked())
    {
        max_type.insert(XL803::MARKERB_WAVE_UB,L_XL803->float_to_quint(ui->ub_max->value()));
        max_type.insert(XL803::MARKERB_WAVE_IB,L_XL803->float_to_quint(ui->ib_max->value()));
        max_type.insert(XL803::MARKERB_WT_UB,4);
        max_type.insert(XL803::MARKERB_WT_IB,4);
        send_data.append(0x55);
        send_data.append(0x55);
        index_vector.append(1);
        n++;
    }else
    {
        send_data.append(0xAA);
        send_data.append(0xAA);
    }
    if(ui->c_f->isChecked())
    {
        max_type.insert(XL803::MARKERB_WAVE_UC,L_XL803->float_to_quint(ui->uc_max->value()));
        max_type.insert(XL803::MARKERB_WAVE_IC,L_XL803->float_to_quint(ui->ic_max->value()));
        max_type.insert(XL803::MARKERB_WT_UC,4);
        max_type.insert(XL803::MARKERB_WT_IC,4);
        send_data.append(0x55);
        send_data.append(0x55);
        index_vector.append(2);
        n++;
    }else
    {
        send_data.append(0xAA);
        send_data.append(0xAA);
    }
    if(ui->d_f->isChecked())
    {
        max_type.insert(XL803::MARKERB_WAVE_UD,L_XL803->float_to_quint(ui->ud_max->value()));
        max_type.insert(XL803::MARKERB_WAVE_ID,L_XL803->float_to_quint(ui->id_max->value()));
        max_type.insert(XL803::MARKERB_WT_UD,4);
        max_type.insert(XL803::MARKERB_WT_ID,4);
        send_data.append(0x55);
        send_data.append(0x55);
        index_vector.append(3);
        n++;
    }else
    {
        send_data.append(0xAA);
        send_data.append(0xAA);
    }
    qint32 sample=(int)(ui->formula_sample->value()*1000);
    qDebug()<<"formula:"<<sample;
    send_data.append(*((qint8*)&sample));
    send_data.append(*((qint8*)&sample+1));
    send_data.append(*((qint8*)&sample+2));
    send_data.append(*((qint8*)&sample+3));
//    L_XL803->COM_HightWrite(max_type,XL803::Wave_reout);
//    L_XL803->big_wave_reout(send_data,XL803::Wave_reout);
    emit start_formula(sample,index_vector,ui->formula->toPlainText());
    timer.start();*/
//}
void Wave_reout::start_send()
{
    emit start_read();
}

//void Wave_reout::on_stop_formula_clicked()
//{
//    emit stop_formula();
//}

/*void formula_control::formula_data(double sample,QVector<int> index_vector,QString formula)
{
    QString now_formula=formula.toLower();
    double step=1/(double)sample;
    step=1/(double)20000;
    double time=0;
    float m_now_value=0;
    int * read_index=(int *)send_memory.data();
    qDebug()<<"send_memory"<<send_memory.data()<<read_index;
    *read_index=0;
    int * write_index=(int *)send_memory.data()+1;
    *write_index=0;
    quint8 *write_ptr=(quint8 *)((int *)send_memory.data()+4);
    int * read_len=(int *)send_memory.data()+2;
    int * write_len=(int *)send_memory.data()+3;
    quint8 * start_write=write_ptr;
    *read_len&=0;
    *write_len&=0;
    quint8 head=0x68;
    byte_data len;
    len.byte_32=0;
    len.byte_16[0]=BYTE_LEN;
    quint8 addr=0x00;
    quint8 code=0xBB;
    byte_data p_len;
    p_len.byte_32=DATA_LEN;
    byte_data index;//帧序号
    index.byte_32=0;
    byte_data b_index;//序列号
    b_index.byte_32=0;
    quint8 check=0;
    quint8 end=0x16;
    byte_data now_value;
    now_value.byte_32=0;
    bool first_flag=true;
    while(1)
    // while(n<5000)
    {
        //qDebug()<<*write_len<<*read_len<<((*write_len)-(*read_len))<<BYTE_LEN*80;
        if(((*write_len>BYTE_LEN)&&(*read_len>BYTE_LEN)))
        {
            *write_len-=BYTE_LEN;
            *read_len-=BYTE_LEN;
        }
        if(((*write_len)-(*read_len))>=(BYTE_LEN*50))
        {
            continue;
        }
        for(int i=0;i<index_vector.count();i++)
        {
            if((write_ptr-start_write>=all_lenth))
                write_ptr=start_write;
            check=0;
            *write_ptr=head;
            write_ptr=write_ptr+1;
            *write_ptr=len.byte_8[0];
            write_ptr=write_ptr+1;
            *write_ptr=len.byte_8[1];
            write_ptr=write_ptr+1;
            *write_ptr=head;
            write_ptr=write_ptr+1;
            *write_ptr=addr;
            write_ptr=write_ptr+1;
            *write_ptr=code;
            write_ptr=write_ptr+1;
            check+=code;

            check+=p_len.byte_8[0];
            check+=p_len.byte_8[1];
            check+=p_len.byte_8[2];
            check+=p_len.byte_8[3];

            *write_ptr=p_len.byte_8[0];
            write_ptr=write_ptr+1;
            *write_ptr=p_len.byte_8[1];
            write_ptr=write_ptr+1;
            *write_ptr=p_len.byte_8[2];
            write_ptr=write_ptr+1;
            *write_ptr=p_len.byte_8[3];
            write_ptr=write_ptr+1;

            check+=index.byte_8[0];
            check+=index.byte_8[1];
            check+=index.byte_8[2];
            check+=index.byte_8[3];

            *write_ptr=index.byte_8[0];
            write_ptr=write_ptr+1;
            *write_ptr=index.byte_8[1];
            write_ptr=write_ptr+1;
            *write_ptr=index.byte_8[2];
            write_ptr=write_ptr+1;
            *write_ptr=index.byte_8[3];
            write_ptr=write_ptr+1;

            b_index.byte_32=index_vector.at(i);
            check+=b_index.byte_8[0];
            check+=b_index.byte_8[1];
            check+=b_index.byte_8[2];
            check+=b_index.byte_8[3];
            *write_ptr=b_index.byte_8[0];
            write_ptr=write_ptr+1;
            *write_ptr=b_index.byte_8[1];
            write_ptr=write_ptr+1;
            *write_ptr=b_index.byte_8[2];
            write_ptr=write_ptr+1;
            *write_ptr=b_index.byte_8[3];
            write_ptr=write_ptr+1;
            for(int j=0;j<2000;j++)
            {
                m_now_value=100*sin(2*M_PI*50*time);
                time+=step;
                if(m_now_value!=0)
                {
                    now_value.byte_16[0]=(quint16)((( m_now_value/100) *(float) 32767)+(float)32767);      //比例转换,
                }else
                {
                     now_value.byte_16[0]=(quint16)32768;
                }
                check+=now_value.byte_8[0];
                check+=now_value.byte_8[1];
                *write_ptr=now_value.byte_8[0];
                write_ptr=write_ptr+1;
                *write_ptr=now_value.byte_8[1];
                write_ptr=write_ptr+1;
                *write_ptr=(quint8)0x01;
                write_ptr=write_ptr+1;
                check+=(quint8)0x01;
                *write_ptr=(quint8)0x00;//
                write_ptr=write_ptr+1;
                //now_value.byte_16[0]=0;//此处为转换后数据
                check+=now_value.byte_8[0];
                check+=now_value.byte_8[1];
                *write_ptr=now_value.byte_8[0];
                write_ptr=write_ptr+1;
                *write_ptr=now_value.byte_8[1];
                write_ptr=write_ptr+1;
                *write_ptr=(quint8)0x01;
                write_ptr=write_ptr+1;
                check+=(quint8)0x01;
                *write_ptr=(quint8)0x00;//
                write_ptr=write_ptr+1;
            }
            (index.byte_32)++;
            *write_ptr=check;
            write_ptr=write_ptr+1;
            *write_ptr=end;
            write_ptr=write_ptr+1;
            *write_len+=BYTE_LEN;
        }
    }
}

*/

void Wave_reout::on_checkBox_8_clicked()
{
    ui->a_2->setChecked(ui->checkBox_8->isChecked());
    ui->b_2->setChecked(ui->checkBox_8->isChecked());
    ui->c_2->setChecked(ui->checkBox_8->isChecked());
}

void Wave_reout::on_data_control_clicked()
{
    ui->tabWidget->setCurrentIndex(0);
}


void Wave_reout::on_checkBox_clicked()
{
    ui->tabWidget_2->setCurrentIndex(0);
}

void Wave_reout::on_checkBox_2_clicked()
{
    ui->tabWidget_2->setCurrentIndex(1);
}

void Wave_reout::on_checkBox_3_clicked()
{
    ui->tabWidget_2->setCurrentIndex(2);
}
void Wave_reout::on_all_clicked()
{
    ui->a_f->setChecked(ui->all->isChecked());
    ui->b_f->setChecked(ui->all->isChecked());
    ui->c_f->setChecked(ui->all->isChecked());
    ui->d_f->setChecked(ui->all->isChecked());
}

void Wave_reout::on_start_formula_clicked()
{
    if(ui->formula_sample->value()==0)
    {
        QMessageBox::information(NULL," ","采样率不能为零!");
        return;
    }
    is_big=true;
    QMap<XL803::MARKERB, qint32> max_type;
    QByteArray send_data;
    int n=0;
    QVector<int> index_vector;
    QVector<QString> formula;
    if(ui->a_f->isChecked())
    {
        max_type.insert(XL803::MARKERB_WAVE_UA,L_XL803->float_to_quint(ui->ua_max->value()));
        max_type.insert(XL803::MARKERB_WAVE_IA,L_XL803->float_to_quint(ui->ia_max->value()));
        max_type.insert(XL803::MARKERB_WT_UA,4);
        max_type.insert(XL803::MARKERB_WT_IA,4);
        send_data.append(0x55);
        send_data.append(0x55);
        index_vector.append(0);
        n++;
        if(ui->formula->toPlainText().length()<1)
        {
            is_big=false;
            return;
        }
        formula.append(ui->formula->toPlainText());
    }else
    {
        send_data.append(0xAA);
        send_data.append(0xAA);
    }
    if(ui->b_f->isChecked())
    {
        max_type.insert(XL803::MARKERB_WAVE_UB,L_XL803->float_to_quint(ui->ub_max->value()));
        max_type.insert(XL803::MARKERB_WAVE_IB,L_XL803->float_to_quint(ui->ib_max->value()));
        max_type.insert(XL803::MARKERB_WT_UB,4);
        max_type.insert(XL803::MARKERB_WT_IB,4);
        send_data.append(0x55);
        send_data.append(0x55);
        index_vector.append(1);
        n++;
        if(ui->formula_2->toPlainText().length()<1)
        {
            is_big=false;
            return;
        }
        formula.append(ui->formula_2->toPlainText());
    }else
    {
        send_data.append(0xAA);
        send_data.append(0xAA);
    }
    if(ui->c_f->isChecked())
    {
        max_type.insert(XL803::MARKERB_WAVE_UC,L_XL803->float_to_quint(ui->uc_max->value()));
        max_type.insert(XL803::MARKERB_WAVE_IC,L_XL803->float_to_quint(ui->ic_max->value()));
        max_type.insert(XL803::MARKERB_WT_UC,4);
        max_type.insert(XL803::MARKERB_WT_IC,4);
        send_data.append(0x55);
        send_data.append(0x55);
        index_vector.append(2);
        n++;
        if(ui->formula_3->toPlainText().length()<1)
        {
            is_big=false;
            return;
        }
        formula.append(ui->formula_3->toPlainText());
    }else
    {
        send_data.append(0xAA);
        send_data.append(0xAA);
    }
    if(ui->d_f->isChecked())
    {
        max_type.insert(XL803::MARKERB_WAVE_UD,L_XL803->float_to_quint(ui->ud_max->value()));
        max_type.insert(XL803::MARKERB_WAVE_ID,L_XL803->float_to_quint(ui->id_max->value()));
        max_type.insert(XL803::MARKERB_WT_UD,4);
        max_type.insert(XL803::MARKERB_WT_ID,4);
        send_data.append(0x55);
        send_data.append(0x55);
        index_vector.append(3);
        n++;
    }else
    {
        send_data.append(0xAA);
        send_data.append(0xAA);
    }
    qint32 sample=(int)(ui->formula_sample->value()*1000);
    qDebug()<<"formula:"<<sample;
    send_data.append(*((qint8*)&sample));
    send_data.append(*((qint8*)&sample+1));
    send_data.append(*((qint8*)&sample+2));
    send_data.append(*((qint8*)&sample+3));
    formula_thread.start();
    L_XL803->COM_HightWrite(max_type,XL803::Wave_reout);
    L_XL803->big_wave_reout(send_data,XL803::Wave_reout);
    emit start_formula(sample,index_vector,formula);
    //timer.start();
}
void Wave_reout::on_stop_formula_clicked()
{
    stop_memory.attach();
    stop_memory.lock();
    quint8 *write_ptr=(quint8 *)((int *)stop_memory.data()+4);
    *write_ptr=0xAA;
    stop_memory.unlock();
    stop_memory.detach();
}

void formula_control::formula_data(double sample,QVector<int> index_vector,QVector <QString> formula)
{
    QVector<QString> now_formula;
    QVector<QString> max_str;
    QVector<double> max_value;
    for(int i=0;i<index_vector.count();i++)
    {
        now_formula.append(formula[i].toLower());
        max_str.append(get_max_formula(now_formula[i]));
        if(L_XL803->getCalculatorValue(max_str[i].toLatin1().data(),i)<0)
        {
            QMessageBox::information(NULL,"提示","公式不符合规则!");
            return;
        }
        max_value.append(L_XL803->get_value(0,i));
        L_XL803->getCalculatorValue(now_formula[i].toLatin1().data(),i);
    }
    double step=1.0/sample;
    double time=0;
    double now_time=0;
    double m_now_value=0;
    memset(send_memory.data(),0,all_lenth);
    int * read_index=(int *)send_memory.data();
    *read_index=0;
    int * write_index=(int *)send_memory.data()+1;
    *write_index=0;
    quint8 *write_ptr=(quint8 *)((int *)send_memory.data()+4);
    int * read_len=(int *)send_memory.data()+2;
    int * write_len=(int *)send_memory.data()+3;
    quint8 * stop_flag;
    stop_flag=write_ptr;
    *stop_flag=(quint8)0xBB;
    write_ptr++;
    quint8 * start_write=write_ptr;
    *read_len&=0;
    *write_len&=0;
    quint8 head=0x68;
    byte_data len;
    len.byte_32=0;
    len.byte_16[0]=BYTE_LEN;
    quint8 addr=0x00;
    quint8 code=0xBB;
    byte_data p_len;
    p_len.byte_32=DATA_LEN;
    byte_data index;//帧序号
    index.byte_32=0;
    byte_data b_index;//序列号
    b_index.byte_32=0;
    quint8 check=0;
    quint8 end=0x16;
    byte_data now_value;
    now_value.byte_32=0;
    bool first_flag=true;
    start_flag=true;
    int a=0;
    while(*stop_flag!=(quint8)0xAA)
    // while(n<5000)
    {
        //qDebug()<<*write_len<<*read_len<<((*write_len)-(*read_len))<<BYTE_LEN*80;
        if((*write_len>BYTE_LEN)&&(*read_len>BYTE_LEN))
        {
            *write_len-=BYTE_LEN;
            *read_len-=BYTE_LEN;
        }
//        qDebug()<<"read:"<<*write_len<<*read_len;
//        qDebug()<<((*write_len)-(*read_len))<<(BYTE_LEN*80);
        if(((*write_len)-(*read_len))>=(BYTE_LEN*80))
        {
            if(first_flag)
            {
                first_flag=false;
                emit data_ready();
            }
            continue;
        }
        for(int i=0;i<index_vector.count();i++)
        {
            if((write_ptr-start_write>=all_lenth))
                write_ptr=start_write;
            if(i==0)
            {
                now_time=time;
            }else
            {
                time=now_time;
            }
            check=0;
            *write_ptr=head;
            write_ptr=write_ptr+1;
            *write_ptr=len.byte_8[0];
            write_ptr=write_ptr+1;
            *write_ptr=len.byte_8[1];
            write_ptr=write_ptr+1;
            *write_ptr=head;
            write_ptr=write_ptr+1;
            *write_ptr=addr;
            write_ptr=write_ptr+1;
            *write_ptr=code;
            write_ptr=write_ptr+1;
            check+=code;

            check+=p_len.byte_8[0];
            check+=p_len.byte_8[1];
            check+=p_len.byte_8[2];
            check+=p_len.byte_8[3];

            *write_ptr=p_len.byte_8[0];
            write_ptr=write_ptr+1;
            *write_ptr=p_len.byte_8[1];
            write_ptr=write_ptr+1;
            *write_ptr=p_len.byte_8[2];
            write_ptr=write_ptr+1;
            *write_ptr=p_len.byte_8[3];
            write_ptr=write_ptr+1;

            check+=index.byte_8[0];
            check+=index.byte_8[1];
            check+=index.byte_8[2];
            check+=index.byte_8[3];

            *write_ptr=index.byte_8[0];
            write_ptr=write_ptr+1;
            *write_ptr=index.byte_8[1];
            write_ptr=write_ptr+1;
            *write_ptr=index.byte_8[2];
            write_ptr=write_ptr+1;
            *write_ptr=index.byte_8[3];
            write_ptr=write_ptr+1;

            b_index.byte_32=index_vector[i];
            check+=b_index.byte_8[0];
            check+=b_index.byte_8[1];
            check+=b_index.byte_8[2];
            check+=b_index.byte_8[3];
            *write_ptr=b_index.byte_8[0];
            write_ptr=write_ptr+1;
            *write_ptr=b_index.byte_8[1];
            write_ptr=write_ptr+1;
            *write_ptr=b_index.byte_8[2];
            write_ptr=write_ptr+1;
            *write_ptr=b_index.byte_8[3];
            write_ptr=write_ptr+1;
           // qDebug()<<QString::number(time,'g',12)<<QString::number(L_XL803->get_value(time),'g',12);
            for(int j=0;j<2000;j++)
            {
                time+=step;
                m_now_value=L_XL803->get_value(time,i);

                if(m_now_value!=0)
                {
                    now_value.byte_16[0]=(quint16)((( m_now_value/max_value[i]) *(double) 32767)+(double)32767);      //比例转换,
                }else
                {
                     now_value.byte_16[0]=(quint16)32768;
                }

                check+=now_value.byte_8[0];
                check+=now_value.byte_8[1];
                *write_ptr=now_value.byte_8[0];
                write_ptr=write_ptr+1;
                *write_ptr=now_value.byte_8[1];
                write_ptr=write_ptr+1;
                *write_ptr=(quint8)0x01;
                write_ptr=write_ptr+1;
                check+=(quint8)0x01;
                *write_ptr=(quint8)0x00;//
                write_ptr=write_ptr+1;
                //now_value.byte_16[0]=0;//此处为转换后数据
                check+=now_value.byte_8[0];
                check+=now_value.byte_8[1];
                *write_ptr=now_value.byte_8[0];
                write_ptr=write_ptr+1;
                *write_ptr=now_value.byte_8[1];
                write_ptr=write_ptr+1;
                *write_ptr=(quint8)0x01;
                write_ptr=write_ptr+1;
                check+=(quint8)0x01;
                *write_ptr=(quint8)0x00;//
                write_ptr=write_ptr+1;
            }
//            time_2+=step_2;
//            time=time_2;
            (index.byte_32)++;
            *write_ptr=check;
            write_ptr=write_ptr+1;
            *write_ptr=end;
            write_ptr=write_ptr+1;
            *write_len+=BYTE_LEN;
        }
    }
}

int  formula_control::get_str_len(int len, QString str)
{
    int left_num=0;
    int right_num=0;
    for(int i=len;i<str.length();i++)
    {
        if(str.at(i)=='(')
          left_num++;
        if(str.at(i)==')')
          right_num++;
        if((right_num==left_num)&&(right_num>0))
            return i;
    }
    return str.length();
}

QString formula_control::get_max_formula(QString formula)
{
    QString str;
    for(int i=0;i<formula.length();i++)
    {
        if((formula.at(i)>='0'&&formula.at(i)<='9')\
          ||(formula.at(i)=='+')||(formula.at(i)=='-')\
          ||(formula.at(i)=='*')||(formula.at(i)=='/'))
        {
            str.append(formula.at(i));
        }else if (formula.at(i) >= 'a' && formula.at(i)<= 'z')//说明是函数或者是常数
        {
            if (formula.at(i) == 'e') {str.append('e'); continue;}//常数E
            char tmp[5];
            for (int k = 0; k < 4; k++)//提取
                tmp[k] = formula.at(i+k).toLatin1();
            tmp[4] = '\0';
            if (!strcmp(tmp, "sinh"))	{ i += 3;i=get_str_len(i,formula);str.append("(1)"); continue;}
            if (!strcmp(tmp, "cosh"))	{ i += 3;i=get_str_len(i,formula);str.append("(1)");  continue;}
            if (!strcmp(tmp, "tanh"))	{ i += 3;i=get_str_len(i,formula);str.append("(1)");  continue;}
            if (!strcmp(tmp, "coth"))	{ i += 3;i=get_str_len(i,formula);str.append("(1)");  continue;}
            if (!strcmp(tmp, "sign"))	{ i += 3;i=get_str_len(i,formula);str.append("(1)");  continue;}
            if (!strcmp(tmp, "sqrt"))	{ i += 3;i=get_str_len(i,formula);str.append("(1)");  continue;}
            tmp[3] = '\0';
            if (!strcmp(tmp, "sin"))	{ i += 2;i=get_str_len(i,formula);str.append("(1)");  continue;}
            if (!strcmp(tmp, "cos"))	{ i += 2;i=get_str_len(i,formula);str.append("(1)");  continue;}
            if (!strcmp(tmp, "tan"))	{ i += 2;i=get_str_len(i,formula);str.append("(1)");  continue;}
            if (!strcmp(tmp, "cot"))	{ i += 2;i=get_str_len(i,formula);str.append("(1)");  continue;}
            if (!strcmp(tmp, "ctg"))	{ i += 2;i=get_str_len(i,formula);str.append("(1)");  continue;}
            if (!strcmp(tmp, "abs"))	{ i += 2;i=get_str_len(i,formula);str.append("(1)");  continue;}
            if (!strcmp(tmp, "log"))	{ i += 2;i=get_str_len(i,formula);str.append("(1)");  continue;}
            tmp[2] = '\0';
            if (!strcmp(tmp, "tg"))		{ i += 1;i=get_str_len(i,formula);str.append("(1)");  continue;}
            if (!strcmp(tmp, "ln"))		{ i += 1;i=get_str_len(i,formula);str.append("(1)");  continue;}
            if (!strcmp(tmp, "sh"))		{ i += 1;i=get_str_len(i,formula);str.append("(1)");  continue;}
            if (!strcmp(tmp, "ch"))		{ i += 1;i=get_str_len(i,formula);str.append("(1)");  continue;}
        }
    }
    return str;
}


void Wave_reout::on_wave_reout_clicked()
{
    ui->tabWidget->setCurrentIndex(1);
}

void Wave_reout::on_remove1_clicked()
{
    if(ui->new_file->currentIndex().row()<0)
    {
        QMessageBox::information(this,"提示","请选择波形数据文件!");
    }else{
        QFile file(new_path_name.at(ui->new_file->currentIndex().row()));
        QMessageBox::StandardButton rb = QMessageBox::information\
                (this,"提示","确认删除?",QMessageBox::Yes|QMessageBox::No,QMessageBox::No);
        if(rb==QMessageBox::Yes)
            file.remove();
        on_update_list_clicked();
    }
}

void Wave_reout::on_remove2_clicked()
{
    if(ui->out_file->currentIndex().row()<0)
    {
        QMessageBox::information(this,"提示","请选择波形启动文件!");
    }else{
        QFile file(out_path_name.at(ui->out_file->currentIndex().row()));
         QMessageBox::StandardButton rb = QMessageBox::information\
                 (this,"提示","确认删除?",QMessageBox::Yes|QMessageBox::No,QMessageBox::No);
         if(rb==QMessageBox::Yes)
            file.remove();
        on_update_list_clicked();
    }
}

void Wave_reout::read_formula_file()
{
    QFile file("./formula_config.cfg");
    if (!file.open(QIODevice::ReadOnly)) {
        //QMessageBox::information(NULL,"提示","文件打开失败！");
        return;
    }
    QTextStream out(&file);
    file_formula_list.clear();
    ui->formula_list->clear();
    QStringList data;
    while(!out.atEnd())
    {
        data=out.readLine().split(",");
        ui->formula_list->addItem(data.at(0));
        file_formula_list.append(data.at(1));
    }
    file.close();
}

void Wave_reout::on_formula_list_activated(int index)
{
    switch(ui->tabWidget_2->currentIndex())
    {
        case 0:
            ui->formula->setText(file_formula_list.at(index));
            break;
        case 1:
            ui->formula_2->setText(file_formula_list.at(index));
            break;
        case 2:
            ui->formula_3->setText(file_formula_list.at(index));
            break;
    }
}
