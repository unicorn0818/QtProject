#include "wave_reout_zj.h"
#include "ui_wave_reout_zj.h"
wave_reout_ZJ::wave_reout_ZJ(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::wave_reout_ZJ)
{
    //初始化界面
    initUi();
    //初始化数据库
    initSql();
    //使用多线程
    m_file.moveToThread(&file_thread);
    file_thread.start();
    //初始化关联函数
    initConnect();
}
file_control1::file_control1(QObject *parent){
    NUM = 1;
}
quint32 file_control1::indexAll = 0;
file_control1::~file_control1(){}
formula_control1::formula_control1(QObject *parent)
{
    send_memory.setKey("share_memory");
    all_lenth=BYTE_LEN*100;
    start_flag=false;
    qDebug()<<"creator:"<<send_memory.create(all_lenth+32);
    send_memory.attach();
}
formula_control1::~formula_control1(){}
wave_reout_ZJ::~wave_reout_ZJ()
{
    delete ui;
}
void formula_control1::formula_data(double sample,QVector<int> index_vector,QVector <QString> formula)
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
    byte_data1 len;
    len.byte_32=0;
    len.byte_16[0]=BYTE_LEN;
    quint8 addr=0x00;
    quint8 code=0xBB;
    byte_data1 p_len;
    p_len.byte_32=DATA_LEN;
    byte_data1 index;//帧序号
    index.byte_32=0;
    byte_data1 b_index;//序列号
    b_index.byte_32=0;
    quint8 check=0;
    quint8 end=0x16;
    byte_data1 now_value;
    now_value.byte_32=0;
    bool first_flag=true;
    start_flag=true;
    int a=0;
    while(*stop_flag!=(quint8)0xAA)
    {
        if((*write_len>BYTE_LEN)&&(*read_len>BYTE_LEN))
        {
            *write_len-=BYTE_LEN;
            *read_len-=BYTE_LEN;
        }
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
            (index.byte_32)++;
            *write_ptr=check;
            write_ptr=write_ptr+1;
            *write_ptr=end;
            write_ptr=write_ptr+1;
            *write_len+=BYTE_LEN;
        }
    }
}
int  formula_control1::get_str_len(int len, QString str)
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
QString formula_control1::get_max_formula(QString formula)
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
/**
 * @brief file_control1::show_map 预览电压电流波形
 * @param start 起始点数必须小于结束点数，用于波形的分段预览
 * @param end
 * @param path_name 重采样后的文件路径
 * @param pipe 要显示的波形在文件中通道
 */
void file_control1::show_map(int start,int end,QString path_name, int pipe)
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
    data.device()->seek(start*pipe_num*sizeof(quint16));
    float m_max=0;
    while(n<count)
    {
        for(int i=0;i<pipe_num;i++)
        {
            data>>value;
            if(i==pipe)
            {
                new_value=(value-(quint16)32767)/max_value.at(pipe);
                if(value==32768)
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

    if(pipe == 0)
        emit send_vector(x,y,time,m_max);
    else if(pipe == 1)
        emit send_vector1(x,y,time,m_max);
    file.close();
}
/**
 * @brief file_control::out_file 波形组帧生成输出文件
 * @param file_name
 * @param index_vector
 * @param pipe_vector
 * @param p_num
 */
void file_control1::out_file(QString file_name,QVector<int> index_vector,QVector<int> pipe_vector,int p_num,int type)
{
    if(file_name.contains("./"))
        file_name = file_name.remove("./");
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
    if(type == 0)
        file_name.replace("wave_file_new_ZJ","wave_file_out_ZJ");
    else
        file_name.replace("ele_wave_file_new","ele_wave_file_out");
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
    //add_count表示到最后一帧需要补上的点数
    int add_count=all_point%p_num;
    add_count=p_num-add_count;
    //协议文本
    quint8 head=0x68;//头
    byte_data1 len;
    len.byte_32=0;
    len.byte_16[0]=20+p_num*8;//长度占两个字节
    quint32 m_len=20+p_num*8;
    quint8 addr=0x00;
    quint8 code=0xBB;//命令
    byte_data1 p_len;
    p_len.byte_32=p_num*8;
    byte_data1 index;
    index.byte_32=0;
    byte_data1 b_index;
    b_index.byte_32=0;
    //校验和
    quint8 check=0;
    //帧尾
    quint8 end=0x16;
    QDataStream out(&out_wave_file);
    out<<smaple;
    QVector<QVector<quint16> > value_vector;
    for(int i=0;i<pipe_num;i++)
    {
        value_vector.append(QVector<quint16>());
    }
    quint16 now_value=0;
    byte_data1 now_value2;
    now_value2.byte_32=0;
    //一帧的点数
    int one_lenth=p_num;
    int value = in.device()->pos();
    bool m_flag = true;
    in.device()->seek(value);

    while(!in.atEnd()&&m_flag)
    {
        //每次读两千个点出来，读到最后如果不够2000个点且在重复播放模式，那么重新回到文件开头读满2000个点
        for(int i=0;i<p_num;i++)
        {
            for(int j=0;j<pipe_num;j++)
            {
                if(in.atEnd())
                {
                    if(NUM==1)
                       now_value=add_byte;
                    else if(m_flag)
                    {
                        in.device()->seek(value);
                        m_flag = false;
                        in>>now_value;
                    }
                }else
                {
                    in>>now_value;
                }
                value_vector[j].append(now_value);
            }
        }
        //单相循环1次，三相并联循环3次
        for(int i=0;i<index_vector.length();i++)
        {
            check=0;
            out<<m_len;
            //头
            out<<head;
            //长度
            out<<len.byte_8[0];
            out<<len.byte_8[1];
            //头
            out<<head;
            //0x00
            out<<addr;
            //命令
            out<<code;
            check+=code;

            check+=p_len.byte_8[0];
            check+=p_len.byte_8[1];
            check+=p_len.byte_8[2];
            check+=p_len.byte_8[3];
            //每帧的长度
            out<<p_len.byte_8[0];
            out<<p_len.byte_8[1];
            out<<p_len.byte_8[2];
            out<<p_len.byte_8[3];

            check+=index.byte_8[0];
            check+=index.byte_8[1];
            check+=index.byte_8[2];
            check+=index.byte_8[3];
            //帧序号
            out<<index.byte_8[0];
            out<<index.byte_8[1];
            out<<index.byte_8[2];
            out<<index.byte_8[3];

            b_index.byte_32=index_vector.at(i);
            check+=b_index.byte_8[0];
            check+=b_index.byte_8[1];
            check+=b_index.byte_8[2];
            check+=b_index.byte_8[3];
            //输出序列号
            out<<b_index.byte_8[0];
            out<<b_index.byte_8[1];
            out<<b_index.byte_8[2];
            out<<b_index.byte_8[3];

            for(int j=0;j<one_lenth;j++)
            {
                now_value2.byte_16[0]=value_vector.at(pipe_vector.at(i*2)).at(j);
                check+=now_value2.byte_8[0];
                check+=now_value2.byte_8[1];
                //电压数据
                out<<now_value2.byte_8[0];
                out<<now_value2.byte_8[1];
                out<<(quint8)0x01;
                check+=(quint8)0x01;
                out<<(quint8 )0x00;
                //在这里电流是反相的，因为设备可能也是反相的
                now_value2.byte_16[0]=(quint16)0xFFFF-value_vector.at(pipe_vector.at(i*2+1)).at(j);
                check+=now_value2.byte_8[0];
                check+=now_value2.byte_8[1];
                //电流数据
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
    }
    //总帧数
    indexAll = index.byte_32;
    wave_file.close();
    out_wave_file.close();
    emit outFileName(file_name);
}
/**
 * @brief (file)_control::file
 *  初步处理将波形文件重采样并转换为二进制文件
 *  原分段读取算法在过渡的时候有丢点bug，改为廖工给的算法进行二/三阶插值
 * @param file_name 文件名
 * @param sample 输出的采样率
 * @param byte_lenth
 * @param type 文件类型标识 type = 1 为comtrade 0为CSV
 */
void file_control1::file(QString file_name,double sample,int byte_lenth,int type)
{
    QFile file(file_name);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0,"提示","文件打开失败！");
        return;
    }
    file_name.remove(file_name.lastIndexOf('.'),file_name.length()-file_name.lastIndexOf('.'));
    while(file_name.indexOf('/')>=0)
        file_name.remove(0,file_name.indexOf('/')+1);
    if(type == 0)
        file_name.insert(0,"./wave_file_reset_sample_ZJ/");
    else
        file_name.insert(0,"./ele_wave_reset_sample/");
    file_name.append(QString("_%1k.bin").arg(sample));
    QFile sample_file(file_name);
    if (!sample_file.open(QIODevice::ReadWrite)) {
        QMessageBox::information(0,"提示","文件创建失败！");
        return;
    }
    /**
     * @brief m_out
     * 临时数据存放文件用于存放插值后但未转换比例的数据
     */
    QTextStream in(&file);
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
    for(int i=0;i<num-1;i++)
    {
        value=in.readLine();
        if(value.indexOf("SampleRate")>-1)
        {
            value.remove(0,value.indexOf(",")+1);
            wave_sample=value.mid(0,value.indexOf(",")).toDouble();
            initSample1 = wave_sample;
        }else if(value.indexOf("BlockSize")>-1)
        {
            value.remove(0,value.indexOf(",")+1);
            block_size=value.mid(0,value.indexOf(",")).toInt();
        }else if(value.indexOf("TraceName")>-1)
        {
            value_count=std::count(value.begin(), value.end(), ',');
        }
    }
    quint32 all_size = block_size;
    emit send_mesg(0,all_size);
    double outSample = sample;
    //进行插值
    QVector<QList<double> > inArray;
    QList<double> rowLst;
    qint64 outInd = 0;
    qint64 inInd = -1;
    int size = 0;
    int n = 0;
    float tt = 0;
    for(int i=0;i<value_count;i++)
    {
        max_value.append(0);
    }
    while(!in.atEnd())
    {
        value=in.readLine();
        if(n==(int)all_size||(n>(int)all_size)/3||(n>(int)all_size)/6)
           emit send_mesg(3,n);
        n++;
        value = value.remove(0,value.indexOf(",")+1);
        value.chop(1);

        QStringList strLst = value.split(",");
        rowLst.clear();
        foreach(const QString &s,strLst)
        {
            rowLst.append(s.toDouble());
//            qDebug()<<s.toDouble();
        }
        inArray.append(rowLst);
        inInd ++;
        //qDebug()<<"inArray.count()"<<inArray.count()<<"N"<<N;
        if(inArray.count() < N)	//N阶插值
            continue;

        double inIndexF = (double)outInd * wave_sample / outSample;		//计算理论原始数据点
        qint64 inIndexI = (qint32)inIndexF;

        if(inArray.count() != N)	//N阶插值,只允许3点
        {
            inArray.removeFirst();
            continue;
        }
        while(inInd - inIndexI == (N-1) || (in.atEnd()&&outInd<(inInd+1)*outSample/wave_sample))
        {
            double t = inIndexF - inIndexI;

            if(inInd-inIndexI!=(N-1))
                t -= (inInd - inIndexI - N + 1);

            for(int c = 0; c < inArray[0].count(); c++)
            {//每一列
                double y;
//                if(inIndexF == inIndexI)
//                    y = inArray[0].at(c);
//                else
//                    y = inArray[0].at(c)*(t-1.0)*(t-2.0)/2.0 - inArray[1].at(c)*t*(t-2.0) + inArray[2].at(c)*t*(t-1.0)/2.0;
//                if(inIndexF == inIndexI)
                if(t == 0)
                    y = inArray[0].at(c);
                else
                {
                    y=0;
                    for(int i = 0; i < N; i++)
                    {
                        double yk = inArray[i].at(c);  //计算都按double
                        for(int j = 0; j < N; j++)
                        {
                            if(i!=j)
                            {
                                yk = yk*(t-j);
                                yk = yk/(i-j);
                            }
                        }
                        y += yk;
                    }
                }
                m_out<<y;
//                if(c==1)
//                    qDebug()<<"y"<<y<<"count"<<test++;
                tt = y;
                if(tt < 0)
                    tt = - tt;
                if(max_value.at(c) < tt)
                    max_value[c] = tt;
            }
            outInd ++;
            size ++;
            inIndexF = (double)outInd * wave_sample / outSample;		//计算理论原始数据点
            inIndexI = (qint32)inIndexF;
       }
        inArray.removeFirst();	//出来了说明前面完了，把第一点去掉
    }
    file.close();
    m_out.device()->seek(0);
    if(type == 0)
        file_name.replace("wave_file_reset_sample_ZJ","wave_file_new_ZJ");
    else
        file_name.replace("ele_wave_reset_sample","ele_wave_file_new");
    QFile out_wave_file(file_name);
    if (!out_wave_file.open(QIODevice::WriteOnly)) {
        QMessageBox::information(NULL,"提示","文件创建失败！");
        sample_file.close();
        return;
    }
    /**
     * @brief out_wave
     * 用于存放处理后的数据，文件为二进制方式存储
     * 格式：
     *  double  sample采样率， int value_count 通道数, int size 单通道总数据点数
     */
    QDataStream out_wave(&out_wave_file);
    out_wave<<sample;
    out_wave<<value_count;
//    if(size<62000)
//        out_wave<<62000;
//    else
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
                out_wave<<(quint16)qRound((((m_now_value/ max_value.at(x)) *(float)32767)+(float)32767));      //比例转换,
            }else
            {
                out_wave<<(quint16)32768;
            }
        }
        size_flag++;
        if(size_flag%flag==0)
            emit send_mesg(3,size_flag);
    }
//    if(size<62000){
//        for(int i=size;i<=62000;i++){
//            for(int x=0;x<value_count;x++){
//                out_wave<<(quint16)32768;
//            }
//        }
//    }
    emit send_mesg(3,size);
    sample_file.remove();
    sample_file.close();
    out_wave_file.close();
    //emit send_mesg(5,0);
    if(type == 0)
    {
        //完成重采样，保存到数据库
        emit finish(file_name,energy);
    }

}
/**
 * @brief file_control1::comtrade_convert  comtrade波形的格式转换为tmp后进行重采样
 * @param path_name comrade波形文件的路径名，需为.dat或.cfg格式
 * @param sample 输出的采样率
 * @param tableName 用户在界面为场景的命名
 */
void file_control1::comtrade_convert(QString path_name,double sample,QString tableName)
{
    //转换编码格式
    QTextCodec *code = QTextCodec::codecForName("gb2312");
    code->fromUnicode(path_name).data();

    //将comtrade文件进行转换
    parse_comtrade_file(code->fromUnicode(path_name).data());
    path_name = "./scene/"+tableName+".tmp";
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
    //重采样
    //file(path_name,sample,2000,1);
    //添加到数据库中
    emit add_sql(tableName,1);
}
/**
 * @brief file_control1::comtrade_convert_CSV  CSV波形的格式转换为tmp后进行重采样
 * CSV波形文件的名称必须为电压或者电流且电压电流文件要在同一级的目录中
 * @param volCSV 电压波形文件路径
 * @param eleCSV 电流波形文件路径
 * @param sample 输出的采样率
 * @param status 电流数据是否反相标志位
 */
void file_control1::comtrade_convert_CSV(QString volCSV,QString eleCSV,QString CSVDbName,double sample,bool status)
{
    QVector<float> volTmp,eleTmp;
    volTmp = saveCSVData(volCSV);
    eleTmp = saveCSVData(eleCSV);
    if(status)
    {
        for(int i = 0;i<eleTmp.count();i++)
            eleTmp.replace(i,-eleTmp.at(i));
    }
    QString TmpFileName = volCSV.mid(0,volCSV.lastIndexOf("/"))+"/"+CSVDbName+".tmp";
    QFile fileTmp(TmpFileName);
    if(!fileTmp.open(QIODevice::WriteOnly))
        qDebug()<<"opentmp fail";
    else{
        QTextStream streamTmp(&fileTmp);
        streamTmp<<"Header Size,"<<4<<endl;
        streamTmp<<"TraceName";
        for(int i=0;i<2;i++)
           streamTmp<<QString(",CH%1").arg(i+1);
        streamTmp<<endl;
        streamTmp<<"BlockSize,"<<volTmp.count()<<endl;
        streamTmp<<"SampleRate,"<<initSample*1000<<endl;
        for(int i=0;i<volTmp.count();i++)
        {
            streamTmp<<","<<volTmp.at(i)<<","<<eleTmp.at(i)<<","<<endl;
        }
    }
    fileTmp.close();
    //计算理论电能
    energy = calEnergy(volTmp,eleTmp,0);
    //将临时文件中的数据进行重采样
    this->file(TmpFileName,sample,2000,0);
}
/**
 * @brief file_control1::calEnergy 计算原始数据的理论电能
 * @param volTmp 电压数据
 * @param eleTmp 电流数据
 * @param type 导入文件类型          type = 0为CSV type = 1为comtrade
 * @return tmp 理论电能
 */
double file_control1::calEnergy(QVector<float> volTmp,QVector<float> eleTmp,int type)
{
    if(type == 0)
        initSample *= 1000;
    else
        initSample = initSample1;
    double tmp = 0;
    for(int i=0;i<volTmp.count();i++)
    {
        tmp += (volTmp.at(i)*eleTmp.at(i))/initSample;//输出电能 = 求和(电压点*电流点/采样率)
    }
    tmp = tmp/3600000;
    return tmp;
}
/**
 * @brief file_control1::saveCSVData 将CSV文件中的数据读取并保存到容器中
 * @param filePath CSV电压或电流文件的路径
 * @return fileData 保存有CSV文件数据的容器
 */
QVector<float> file_control1::saveCSVData(QString filePath)
{
    QFile file(filePath);
    QVector<float> fileData;
    if(!file.open(QIODevice::ReadOnly))
        qDebug()<<"open fail";
    else{
        QTextStream stream(&file);
        {
            while(!file.atEnd())
            {
                QByteArray array = file.readLine();
                QString data = QString(array);
                data = data.mid(data.indexOf(",")+1);
                data = data.remove("\r\n");
                fileData.append(data.toFloat());
            }
        }
    }
    file.close();
    return fileData;
}
/**
 * @brief file_control1::setInsertMode 设置插值的形式
 * @param N 插值方式    N = 2为二阶插值  N = 3为拉格朗日三阶插值
 * @return
 */
void file_control1::setInsertMode(quint8 N)
{
    this->N = N;
}
/**
 * @brief file_control1::getVol 在线程中获取电压通道的数据
 * @param ch_vol 电压所对应的通道
 * @param file_name 文件所在路径
 */
QVector<float> file_control1::getVol(int ch_vol, QString file_name)
{
    data.clear();
    QFile file(file_name);
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug()<<"957openfail";
    }
    QTextStream stream(&file);
    QString value;
    int BlockSize=0;
    for(int i=0;i<5;i++)
    {
        stream>>value;
        if(i==3)
            BlockSize = value.remove("BlockSize,").toInt();
    }
    int pipe_count = get_pipe_count(file_name);
    QStringList tmp_list;QList<int> pos_list;

    for(int x=0;x<BlockSize;x++)
        data.append(0);
    for(int x=0;x<BlockSize;x++)
    {
        QCoreApplication::processEvents();
        value.clear();
        stream>>value;
        pos_list.clear();
        int pos = -1;
        for(int i=0;i<pipe_count+1;i++)
        {
            pos = value.indexOf(",",pos+1);
            pos_list.append(pos);
        }
        for(int j=0;j<pipe_count;j++)
        {
            if(ch_vol==j+1)
            {
                QString tmp = value.mid(pos_list.at(j)+1,pos_list.at(j+1)-pos_list.at(j)-1);
                data.replace(x,tmp.toFloat());
            }
        }
    }
    file.close();
    return data;
}
/**
 * @brief file_control1::overLay 电流通道的叠加
 * @param ch_list 需要叠加的电流通道
 * @param file_name 临时文件名
 */
QVector<float> file_control1::overLay(QList<int> ch_list, QString file_name ,bool revFlag)
{
    data1.clear();
    QFile file(file_name);
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug()<<"999openfail";
    }
    QTextStream stream(&file);
    QString value;
    int BlockSize=0;
    for(int i=0;i<5;i++)
    {
        stream>>value;
        if(i==3)
            BlockSize = value.remove("BlockSize,").toInt();
    }
    int pipe_count = get_pipe_count(file_name);
    QStringList tmp_list;
    QVector<int> pos_list;
    for(int x=0;x<BlockSize;x++)
        data1.append(0);
    emit send_mesg(6,BlockSize);
    for(int x=0;x<BlockSize;x++)
    {
        QCoreApplication::processEvents();
        value.clear();
        stream>>value;
        pos_list.clear();
        int pos = -1;
        //保存每一个点的位置
        for(int i=0;i<pipe_count+1;i++)
        {
            pos = value.indexOf(",",pos+1);
            pos_list.append(pos);
        }
        for(int j=0;j<pipe_count;j++)
        {
            if(ch_list.contains(j+1))
            {
                QString tmp = value.mid(pos_list.at(j)+1,pos_list.at(j+1)-pos_list.at(j)-1);
                //qDebug()<<"data1.at("<<x<<")"<<data1.at(x)<<"tmp.toFloat()"<<tmp.toFloat();
                data1.replace(x,data1.at(x)+tmp.toFloat());
            }
        }
        emit send_mesg(7,x);
    }
    if(revFlag)
    {
        for(int i = 0;i<data1.count();i++)
            data1.replace(i,-data1.at(i));
    }
    file.close();
    return data1;
}
/**
 * @brief wave_reout_ZJ::initSql 加载名称为wave_reout_ZJ的sqlite数据库并绑定对应数据表
 * CSV场景储存在loadfile数据表中
 * comtrade场景储存在loadfile2数据表中
 * 每添加一个comtrade场景还会在数据库中创建同名的数据表，用于保存用户对电压电流通道以及图标的配置
 */
void wave_reout_ZJ::initSql()
{
    //加载sqlite数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("wave_reout_ZJ.db");
    if (!db.open()) {
        QMessageBox::information(this,"提示","数据库初始化失败!");
        return ;
    }
    //loadfile用于保存CSV格式场景
    QString sql = "create table if not exists loadfile(id integer primary key autoincrement,filename varchar(256) unique)";
    QSqlQuery query;
    if(!query.exec(sql))
        qDebug()<<"create fail";
    //loadfile2用于保存comtrade格式场景
    sql = "create table if not exists loadfile2(id integer primary key autoincrement,filename varchar(256) unique)";
    if(!query.exec(sql))
        qDebug()<<"create fail";
    //ui->tabWidget->setCurrentIndex(0);
    model = new QSqlTableModel(this,db);
    //模型绑定数据表，控件绑定模型
    setModel("loadfile");
}
/**
 * @brief wave_reout_ZJ::initUi 初始化用电仿真页面的一些界面设置
 */
void wave_reout_ZJ::initUi()
{
    ui->setupUi(this);
    revFlag = false;
    revFlag_2 = false;
    QSettings *setting = new QSettings("./config.ini", QSettings::IniFormat);
    ui->insertMode->setCurrentIndex(setting->value("mode").toString().toInt());
    ui->insertMode->setCurrentIndex(setting->value("mode2").toString().toInt());
    //设置scrollArea无侧拉条
    ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //comtrade格式需叠加电流后才能输出
    ui->startOutput_2->setEnabled(false);
    ui->btViewWave_2->setEnabled(false);
    //初始化预览图
    line=ui->widget->addGraph();
    line->setPen(QPen(Qt::yellow,1));
    line2=ui->widget->addGraph();
    line2->setPen(QPen(Qt::red,1));
    ui->widget->xAxis->setLabel("U电压:黄线  I电流:红线");//轴标签
    L_XL803->set_map(ui->widget);
    ui->widget->xAxis->setLabelColor(Qt::green);
    //进度条
    dialog=new QProgressDialog(tr("格式转换进度"), tr("确定"), 0, 1, this);
    dialog->setWindowTitle("格式转换进度");
    dialog->setWindowModality(Qt::WindowModal);
    dialog->setValue(1);
    ui->scene->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //初始化插入模式
    if(ui->insertMode_2->currentIndex()==0)
        m_file.setInsertMode(3);
    ui->energy_2->hide();
    ui->label_46->hide();
}
/**
 * @brief wave_reout_ZJ::initConnect 关联信号与槽
 */
void wave_reout_ZJ::initConnect()
{
    //进度条
    connect(&m_file,SIGNAL(send_mesg(int,int)),this,SLOT(show_dialog(int,int)),Qt::QueuedConnection);
    //场景导入
    connect(this,SIGNAL(comtrade_path(QString,double,QString)),&m_file,SLOT(comtrade_convert(QString,double,QString)),Qt::QueuedConnection);
    connect(this,SIGNAL(comtrade_path_CSV(QString,QString,QString,double,bool)),&m_file,SLOT(comtrade_convert_CSV(QString,QString,QString,double,bool)),Qt::QueuedConnection);
    //导入完成，保存到数据库
    connect(&m_file,SIGNAL(add_sql(QString,int)),this,SLOT(sql_add(QString,int)));
    connect(&m_file,SIGNAL(finish(QString,double)),this,SLOT(addDb(QString,double)),Qt::QueuedConnection);
    //预览波形
    connect(this,SIGNAL(priview_map(int ,int ,QString,int)),&m_file,SLOT(show_map(int ,int ,QString,int)),Qt::QueuedConnection);
    connect(&m_file,SIGNAL(send_vector(QVector<double>,QVector<double>,double,float)),this,\
            SLOT(m_priview(QVector<double>,QVector<double>,double,float)),Qt::QueuedConnection);
    connect(&m_file,SIGNAL(send_vector1(QVector<double>,QVector<double>,double,float)),this,\
            SLOT(m_priview1(QVector<double>,QVector<double>,double,float)),Qt::QueuedConnection);
    //生成输出文件
    connect(this,SIGNAL(send_out_path(QString ,QVector<int>,QVector<int>,int ,int)),\
            &m_file,SLOT(out_file(QString ,QVector<int>,QVector<int>,int,int )),Qt::QueuedConnection);
    //输出文件生成好了，通知启动
    connect(&m_file,SIGNAL(outFileName(QString)),this,SLOT(recv_fileName(QString)),Qt::QueuedConnection);
    //通知发送输出文件
    connect(L_XL803,SIGNAL(send_to_Ele_Load_Sim(QByteArray,QByteArray)),\
            SLOT(recv(QByteArray,QByteArray)),Qt::QueuedConnection);
}
/**
 * @brief wave_reout_ZJ::setModel 设置model以及表的样式
 * @param dbName 数据表的名称
 */
void wave_reout_ZJ::setModel(QString dbName)
{
    model->setTable(dbName);
    model->select();
    model->setHeaderData(1,Qt::Horizontal,"场景");
    ui->scene->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->scene->setModel(model);
    ui->scene->hideColumn(0);
}
/**
 * @brief wave_reout_ZJ::getFileName 获取用户为场景的命名
 * @param TableName 用户的命名
 * @param type 文件格式 0为CSV 1位comtrade
 */
void wave_reout_ZJ::getFileName(QString TableName,int type)
{
    if(type == 0)
    {
        QString fileNameCSV1;
        if(fileNameCSV.mid(fileNameCSV.lastIndexOf("/")+1)=="电流.CSV")
            fileNameCSV1 = fileNameCSV.mid(0,fileNameCSV.lastIndexOf("/")+1)+"电压.CSV";
        else if(fileNameCSV.mid(fileNameCSV.lastIndexOf("/")+1)=="电流.csv")
            fileNameCSV1 = fileNameCSV.mid(0,fileNameCSV.lastIndexOf("/")+1)+"电压.csv";
        else if(fileNameCSV.mid(fileNameCSV.lastIndexOf("/")+1)=="电压.CSV")
            fileNameCSV1 = fileNameCSV.mid(0,fileNameCSV.lastIndexOf("/")+1)+"电流.CSV";
        else if(fileNameCSV.mid(fileNameCSV.lastIndexOf("/")+1)=="电压.csv")
            fileNameCSV1 = fileNameCSV.mid(0,fileNameCSV.lastIndexOf("/")+1)+"电流.csv";
        else
        {
            QMessageBox::information(this,"提示","电流或电压文件不再同一路径!");
            return ;
        }
        if(ui->insertMode->currentText()=="线性")
            m_file.setInsertMode(2);
        else
            m_file.setInsertMode(3);
        //解析为tmp临时文件
        if(fileNameCSV.contains("电流.CSV")||fileNameCSV.contains("电流.csv"))
            emit comtrade_path_CSV(fileNameCSV1,fileNameCSV,TableName,ui->sample->value(),revFlag);
        else
            emit comtrade_path_CSV(fileNameCSV,fileNameCSV1,TableName,ui->sample->value(),revFlag);
    }
    else
    {
        if(ui->insertMode_2->currentText()=="线性")
            m_file.setInsertMode(2);
        else
            m_file.setInsertMode(3);
        emit comtrade_path(fileNameCom,ui->sample_2->value(),TableName);
    }
}
/**
 * @brief file_control1::getFileSample 用于接收CSV文件的原始采样率
 * 在导入comtrade格式的时候不能调用此槽函数，comtrade格式的原始采样率在配置文件中即可获取
 * @param initSample 原始采样率
 */
void file_control1::getFileSample(double initSample)
{
    this->initSample = initSample;
}
/**
 * @brief wave_reout_ZJ::addDb 将解析好的CSV场景添加到数据库中
 */
void wave_reout_ZJ::addDb(QString fileName,double energy)
{
    if(ui->tabWidget->currentIndex()==0)
    {
        QSqlQuery query;
        QSqlRecord record;
        //查询场景是否重复
        if(!query.exec(QString("select * from loadfile where filename='%1'").arg(fileName)))
            qDebug()<<"error";
        while(query.next())
            record = query.record();
        if(record.value(1).toString()==fileName)
            QMessageBox::information(this,"提示","场景已存在",QMessageBox::Ok);
        else
        {
            int rowNum = model->rowCount();
            model->insertRow(rowNum);
            model->setData(model->index(rowNum,1),fileName);
            model->submitAll();
//            ui->scene->clicked(model->index(rowNum,1));
            QMessageBox::information(this,"提示","场景导入成功",QMessageBox::Ok);
            QSettings *setting = new QSettings("./config.ini", QSettings::IniFormat);
            ui->energy->setValue(energy);
            QString str = fileName+"_"+QString::number(energy);
            list1 = setting->value("list").toStringList();
            if(!list1.contains(str))
            {
                list1.append(str);
                setting->setValue("list",list1);
            }
        }

    }
}

void wave_reout_ZJ::list_append(QString name)
{
    if(!this->list.contains(name))
        this->list<<name;
}
void wave_reout_ZJ::list_remove(QString name)
{
    if(this->list.contains(name))
        this->list.removeAt(this->list.indexOf(name));
}
/**
 * @brief wave_reout_ZJ::set_false_enable
 */
void wave_reout_ZJ::set_false_enable()
{
    ui->startOutput_2->setEnabled(false);
    ui->btViewWave_2->setEnabled(false);
    ui->energy_2->setValue(0.000000000);
}
void wave_reout_ZJ::m_priview(QVector<double> x,QVector<double> y,double time,float max)
{
    line->setData(x,y);
    QSharedPointer<QCPAxisTickerFixed> ticker(new QCPAxisTickerFixed);
    ui->widget->xAxis->setRange(0,0.5);
    float lower=0;
    if(max>=0)
        lower=0-max;
    else
        lower=max*2;
    //ui->widget->yAxis->setRange(lower,max);
    minP = lower;maxP = max;
    ui->widget->replot();
}
void wave_reout_ZJ::m_priview1(QVector<double> x,QVector<double> y,double time,float max)
{
    double rate = 0-minP>maxP?0-minP:maxP;
    for(int i=0;i<y.count();i++)
       y.replace(i,(rate/max)*y.at(i));
    line2->setData(x,y);
    QSharedPointer<QCPAxisTickerFixed> ticker(new QCPAxisTickerFixed);
    ui->widget->xAxis->setRange(0,0.5);
    float lower=0;
    max *= (rate/max);
    if(max>=0)
        lower=0-max;
    else
        lower=max*2;
    ui->widget->yAxis->setRange(lower,max);
    ui->widget->replot();
}
/**
 * @brief wave_reout_ZJ::startOutPut
 *  启动源的输出
 */
void wave_reout_ZJ::startOutPut()
{
    if(!MainWindow::net_flag)
    {
        QMessageBox::information(this,"提示","请连接网口!");
        return;
    }
    if(ui->scene->currentIndex().row()<0)
        QMessageBox::information(this,"提示","请选择场景!");
    else{
            index_vector.clear();
            pipe_vector.clear();

            if(ui->output_mode->currentText()=="三相并联")
            {
                index_vector.append(0);
                pipe_vector.append(0);
                pipe_vector.append(1);

                index_vector.append(1);
                pipe_vector.append(0);
                pipe_vector.append(1);

                index_vector.append(2);
                pipe_vector.append(0);
                pipe_vector.append(1);
            }else
            {
                index_vector.append(0);
                pipe_vector.append(0);
                pipe_vector.append(1);
            }
            if(ui->tabWidget->currentIndex()==0)
            {
                emit send_out_path(model->record(ui->scene->currentIndex().row()).value(1).toString(),index_vector,\
                                   pipe_vector,2000,0);
            }
    }
}
/**
 * @brief wave_reout_ZJ::show_dialog
 *  进度条
 */
void wave_reout_ZJ::show_dialog(int index,int value)
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
            dialog->setValue(value);
            break;
        case 5:
            dialog->setLabelText(tr("波形传输中..."));
            dialog->setRange(0,value);
            dialog->show();
            break;
        case 6:
            dialog->setLabelText(tr("电流叠加中..."));
            dialog->setRange(0,value);
            dialog->show();
            break;
        case 7:
            dialog->setValue(value);
            break;
        default:
            break;
    }
}
/**
 * @brief wave_reout_ZJ::recv
 *  源通知可以下载文件了
 */
void wave_reout_ZJ::recv(QByteArray wb, QByteArray rb)
{
    if((quint8)wb[5]==0xBD&&(is_big==false))
    {
       emit send_out(outFileName);
    }
}
/**
 * @brief wave_reout_ZJ::recv_over
 *  文件输出结束
 */
void wave_reout_ZJ::recv_over()
{
//  QMessageBox::information(this,"提示","波形传输结束!");
    dialog->close();
   emit disConnect(1,false);
//   L_XL803->read_plus(XL803::wave_reout_ZJ);
//    ui->startOutput->click();
//    if(Config_set::serFlag==false)
   m_file.setNum(1);

   qDebug()<<"1394";
}
/**
 * @brief wave_reout_ZJ::recv_index
 *  接受实时传输的帧数并更新进度条
 */
void wave_reout_ZJ::recv_index(int value)
{
//    if(ui->tabWidget->currentIndex()==0)
//    {
        if(value == 0)
        {
            dialog->cancel();
            show_dialog(5,(file_control1::indexAll*net_connect::NUM)-1);
        }
        //ui->now_index->setText(QString("%1").arg(value));
        show_dialog(3,value);
//    }
//    else
//        ui->now_index_2->setText(QString("%1").arg(value));
}
/**
 * @brief wave_reout_ZJ::recv_fileName
 * 输出文件组帧完成，高精度写入相关配置后启动录播回放
 * 按609协议输出完毕或停止传输一段时间后源会自动停止输出
 */
void wave_reout_ZJ::recv_fileName(QString file_name)
{
    if(ui->tabWidget->currentIndex()==0)
    {
        QMap<XL803::MARKERB, qint32> max_type;
        QByteArray send_data;

        if(ui->output_mode->currentText()=="A相")
        {
            max_type.insert(XL803::MARKERB_WAVE_UA,L_XL803->float_to_quint(ui->ua_max->value()));
            max_type.insert(XL803::MARKERB_WAVE_IA,L_XL803->float_to_quint(ui->ia_max->value()));
            max_type.insert(XL803::MARKERB_WT_UA,4);
            max_type.insert(XL803::MARKERB_WT_IA,4);
            send_data.append(0x55);
            send_data.append(0x55);


            send_data.append(0xAA);
            send_data.append(0xAA);


            send_data.append(0xAA);
            send_data.append(0xAA);
        }
        else{
            max_type.insert(XL803::MARKERB_WAVE_UA,L_XL803->float_to_quint(ui->ua_max->value()));
            max_type.insert(XL803::MARKERB_WAVE_IA,L_XL803->float_to_quint(ui->ia_max->value()/3));
            max_type.insert(XL803::MARKERB_WT_UA,4);
            max_type.insert(XL803::MARKERB_WT_IA,4);
            send_data.append(0x55);
            send_data.append(0x55);

            max_type.insert(XL803::MARKERB_WAVE_IB,L_XL803->float_to_quint(ui->ia_max->value()/3));
            max_type.insert(XL803::MARKERB_WT_IB,4);
            send_data.append(0xAA);
            send_data.append(0x55);

            max_type.insert(XL803::MARKERB_WAVE_IC,L_XL803->float_to_quint(ui->ia_max->value()/3));
            max_type.insert(XL803::MARKERB_WT_IC,4);
            send_data.append(0xAA);
            send_data.append(0x55);
        }

        is_big=false;
        send_data.append(0xAA);
        send_data.append(0xAA);


        double sample1=0;
        QFile file("./"+file_name);
        outFileName = "./"+file_name;
        QDataStream out(&file);
        if(!file.isOpen())
            file.open(QIODevice::ReadOnly);
        else
            out.device()->seek(0);
        out>>sample1;
        qint32 sample=0;
        sample=sample1;
        send_data.append(*((qint8*)&sample));
        send_data.append(*((qint8*)&sample+1));
        send_data.append(*((qint8*)&sample+2));
        send_data.append(*((qint8*)&sample+3));
        //把峰值先写到底层
        //当A相时，只写入UA IA的峰值，当三相并联时，则写入UA IA IB IC（峰值的1/3）
        L_XL803->COM_HightWrite(max_type,XL803::wave_reout_ZJ);
        //启动录播回放
        L_XL803->big_wave_reout(send_data,XL803::wave_reout_ZJ);
        file.close();
    }
}

/**
 * @brief wave_reout_ZJ::sql_add
 * comtrade格式文件解析完成,保存至loadfile2数据表并为该场景创建一张同名数据表用来保存电压电流通道的配置
 */
void wave_reout_ZJ::sql_add(QString TableName,int type)
{
    int rowNum = model->rowCount();
    model->insertRow(rowNum);
    model->setData(model->index(rowNum,1),TableName);
    model->submitAll();
    QSqlQuery query;
    if(!query.exec(QString("create table if not exists %1(id integer primary key autoincrement,filename varchar(256),ch varchar(256) unique,equip varchar(256) unique,icon varchar(256) )").arg(TableName)))
    {
        qDebug()<<query.lastError();
        model->removeRow(rowNum);
        model->select();
        return ;
    }
    else{
        ui->scene->clicked(model->index(rowNum,1));
        QMessageBox::information(this,"提示","场景导入成功");
    }
}
/**
 * @brief wave_reout_ZJ::wave_point_count 用于获取文件中数据的总点数
 * @param filename 临时文件名
 * @return 返回原始总点数
 */
int wave_reout_ZJ::wave_point_count(QString file_name)
{
    QFile file(file_name);
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug()<<"839openfail";
        return -1;
    }
    QTextStream stream(&file);
    QString value;
    int BlockSize=0;
    for(int i=0;i<5;i++)
    {
        stream>>value;
        if(i==3)
            BlockSize = value.remove("BlockSize,").toInt();
    }
    file.close();
    return BlockSize;
}
/**
 * @brief file_control1::wave_point_count 用于获取文件中数据的总点数
 * @param filename 临时文件名
 * @return 返回原始总点数
 */
int file_control1::wave_point_count(QString file_name)
{
    QFile file(file_name);
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug()<<"839openfail";
        return -1;
    }
    QTextStream stream(&file);
    QString value;
    int BlockSize=0;
    for(int i=0;i<5;i++)
    {
        stream>>value;
        if(i==3)
            BlockSize = value.remove("BlockSize,").toInt();
    }
    file.close();
    return BlockSize;
}
/**
 * @brief wave_reout_ZJ::samplerate 用于获取文件的波特率
 * @param filename 临时文件名
 */
int wave_reout_ZJ::samplerate(QString file_name)
{
    QFile file(file_name);
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug()<<"856openfail";
        return -1;
    }
    QTextStream stream(&file);
    QString value;
    int sample=0;
    for(int i=0;i<5;i++)
    {
        stream>>value;
        if(i==4)
            sample = value.remove("SampleRate,").toInt();
    }
    file.close();
    return sample;
}
/**
 * @brief wave_reout_ZJ::samplerate 用于获取文件的波特率
 * @param filename 临时文件名
 */
int file_control1::samplerate(QString file_name)
{
    QFile file(file_name);
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug()<<"856openfail";
        return -1;
    }
    QTextStream stream(&file);
    QString value;
    int sample=0;
    for(int i=0;i<5;i++)
    {
        stream>>value;
        if(i==4)
            sample = value.remove("SampleRate,").toInt();
    }
    file.close();
    return sample;
}
/**
 * @brief file_control1::setNum 此函数用于设置录波循环播放的次数
 * @param NUM 次数
 */
void file_control1::setNum(int NUM)
{
    this->NUM = NUM;
    net_connect::NUM = NUM;
//    qDebug()<<"net_connect::NUM"<<net_connect::NUM;
}
/**
 * @brief wave_reout_ZJ::get_pipe_count 用于获取文件中的通道数
 * @param filename 临时文件名
 */
int wave_reout_ZJ::get_pipe_count(QString filename)
{
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug()<<"957openfail";
        return -1;
    }
    QTextStream stream(&file);
    QString value;int pipe_count;
    stream>>value>>pipe_count>>value;
    value.clear();
    stream>>value;
    pipe_count = value.remove(0,value.lastIndexOf(",")+1).remove("CH").toInt();
    file.close();
    return pipe_count;
}
/**
 * @brief file_control1::get_pipe_count 用于获取文件中的通道数
 * @param filename 临时文件名
 */
int file_control1::get_pipe_count(QString filename)
{
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug()<<"957openfail";
        return -1;
    }
    QTextStream stream(&file);
    QString value;int pipe_count;
    stream>>value>>pipe_count>>value;
    value.clear();
    stream>>value;
    pipe_count = value.remove(0,value.lastIndexOf(",")+1).remove("CH").toInt();
    file.close();
    return pipe_count;
}
/**
 * @brief wave_reout_ZJ::get_table_name 在comtrade格式下用于获取数据表的名称
 * @return 当前点击的场景对应的数据表名称
 */
QString wave_reout_ZJ::get_table_name()
{
    QString file_name = model->data(model->index(ui->scene->currentIndex().row(),1)).toString();
    return file_name;
}

/**
 * @brief wave_reout_ZJ::GetVol 获取电压数据
 * @param ch_vol 电压所在的通道
 * @param file_name 临时文件名
 * @return data 返回保存好的电压数据
 */
QVector<float> wave_reout_ZJ::GetVol(int ch_vol,QString file_name)
{
    QFile file(file_name);
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug()<<"957openfail";
    }
    QTextStream stream(&file);
    QString value;
    int BlockSize=0;
    for(int i=0;i<5;i++)
    {
        stream>>value;
        if(i==3)
            BlockSize = value.remove("BlockSize,").toInt();
    }
    int pipe_count = get_pipe_count(file_name);
    QStringList tmp_list;QList<int> pos_list;QVector<float> data;
    for(int x=0;x<BlockSize;x++)
        data.append(0);
    for(int x=0;x<BlockSize;x++)
    {
        QCoreApplication::processEvents();
        value.clear();
        stream>>value;
        pos_list.clear();
        int pos = -1;
        for(int i=0;i<pipe_count+1;i++)
        {
            pos = value.indexOf(",",pos+1);
            pos_list.append(pos);
        }
        for(int j=0;j<pipe_count;j++)
        {
            if(ch_vol==j+1)
            {
                QString tmp = value.mid(pos_list.at(j)+1,pos_list.at(j+1)-pos_list.at(j)-1);
                data.replace(x,tmp.toFloat());
            }
        }
    }
    file.close();
    return data;
}
/**
 * @brief wave_reout_ZJ::OverLay 叠加电流
 * @param ch_list 需要进行叠加的电流通道
 * @param file_name 临时文件名
 * @return data 返回保存好的电流数据
 */
QVector<float> wave_reout_ZJ::OverLay(QList<int> ch_list,QString file_name)
{
    QFile file(file_name);
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug()<<"999openfail";
    }
    QTextStream stream(&file);
    QString value;
    int BlockSize=0;
    for(int i=0;i<5;i++)
    {
        stream>>value;
        if(i==3)
            BlockSize = value.remove("BlockSize,").toInt();
    }
    int pipe_count = get_pipe_count(file_name);
    QStringList tmp_list;
    QVector<int> pos_list;QVector<float> data;
    for(int x=0;x<BlockSize;x++)
        data.append(0);
       //show_dialog(4,BlockSize);
    for(int x=0;x<BlockSize;x++)
    {
        QCoreApplication::processEvents();
        value.clear();
        stream>>value;
        pos_list.clear();
        int pos = -1;
        for(int i=0;i<pipe_count+1;i++)
        {
            pos = value.indexOf(",",pos+1);
            pos_list.append(pos);
        }
        for(int j=0;j<pipe_count;j++)
        {
            if(ch_list.contains(j+1))
            {
                QString tmp = value.mid(pos_list.at(j)+1,pos_list.at(j+1)-pos_list.at(j)-1);
                data.replace(x,data.at(x)+tmp.toFloat());
            }
        }
        //show_dialog(3,x);
    }
    if(revFlag_2)
    {
        for(int i = 0;i<data.count();i++)
            data.replace(i,-data.at(i));
    }
    file.close();
    return data;
}
/**
 * @brief wave_reout_ZJ::recvOrder 接受二次开发指令
 * @param order 指令的内容
 * @param flag 操作
 */
void wave_reout_ZJ::recvOrder(QStringList order, int flag)
{
    if(flag==1&&order.count()>=3)
    {
//        if(order.count()>3)
//        {
//            for(int i=3;i<order.count();i++)
//                order.removeAt(i);
//        }
        if(order.at(1).isEmpty()||order.at(2).isEmpty())
            return ;
        int INDEX = order.at(1).mid(order.at(1).indexOf(":")+1).toInt();
        int NUM = order.at(2).mid(order.at(2).indexOf(":")+1).toInt();
        if(INDEX<0||NUM<1)
            return ;
        if(model->rowCount()>INDEX&&MainWindow::net_flag)
        {
            dialog->close();
            ui->stopOutput->click();
            m_file.setNum(NUM);
            ui->scene->setCurrentIndex(model->index(INDEX,1));
            on_scene_clicked(model->index(INDEX,1));
            ui->btViewWave->click();
            ui->startOutput->click();
            emit sendBack(true,1);
        }
        else
        {
            emit sendBack(false,1);
        }
    }
    else if(flag==2)
    {
        //工控机上软件收到命令后，如果原状态在回放中，则停止回放。
        dialog->close();
        ui->stopOutput->click();
        emit sendBack(true,2);
    }
}
/**
 * @brief wave_reout_ZJ::Write_to_tmp 将叠加后的电流数据重新写入到临时文件中
 * @param data_vol 电压数据
 * @param data_ele 叠加后的电流数据
 * @param scr 初始的临时文件名
 * @return
 */
bool wave_reout_ZJ::Write_to_tmp(QVector<float> data_vol,QVector<float> data_ele,QString scr)
{
    QFile file("./1.tmp");
    if(!file.open(QIODevice::WriteOnly))
    {
        qDebug()<<"1043openfail";
    }
    QTextStream stream(&file);
    stream<<"Header Size,"<<4<<endl;
    stream<<"TraceName";
    for(int i=0;i<2;i++)
       stream<<QString(",CH%1").arg(i+1);
    stream<<endl;
    stream<<"BlockSize,"<<QString::number(wave_point_count(scr))<<endl;
    stream<<"SampleRate,"<<samplerate(scr)<<endl;
    show_dialog(2,wave_point_count(scr));
    for(int i=0;i<wave_point_count(scr);i++)
    {
        QCoreApplication::processEvents();
        stream<<","<<data_vol.at(i)<<","<<data_ele.at(i)<<","<<endl;
        show_dialog(3,i);
    }
    file.close();
    return true;
}
/**
 * @brief file_control1::writeToTmp 将叠加后的电流数据重新写入到临时文件中
 * @param data_vol 电压数据
 * @param data_ele 叠加后的电流数据
 * @param scr 初始的临时文件名
 * @return
 */
void file_control1::writeToTmp(QVector<float> data_vol,QVector<float> data_ele,QString scr)
{
    QFile file("./1.tmp");
    if(!file.open(QIODevice::WriteOnly))
    {
        qDebug()<<"1043openfail";
    }
    QTextStream stream(&file);
    stream<<"Header Size,"<<4<<endl;
    stream<<"TraceName";
    for(int i=0;i<2;i++)
       stream<<QString(",CH%1").arg(i+1);
    stream<<endl;
    int  wavePointCount = wave_point_count(scr);
    stream<<"BlockSize,"<<QString::number(wavePointCount)<<endl;
    stream<<"SampleRate,"<<samplerate(scr)<<endl;
    emit send_mesg(2,wavePointCount);
    for(int i=0;i<wavePointCount;i++)
    {
        QCoreApplication::processEvents();
        stream<<","<<data_vol.at(i)<<","<<data_ele.at(i)<<","<<endl;
        emit send_mesg(3,i);
    }
    file.close();
}
/**
 * @brief wave_reout_ZJ::ele_ch_bind 绑定对应的电流通道并保存到数据库
 */
void wave_reout_ZJ::ele_ch_bind(int ele_ch,QString equip_name)
{
    QString table_name = get_table_name();
    QSqlQuery query;
    query.exec(QString("select * from %1 where equip like '电压'").arg(table_name));
    if(!query.next())
    {
        QMessageBox::information(this,"提示","未绑定电压通道",QMessageBox::Ok);
        return;
    }
    query.prepare(QString("insert into %1(filename,ch,equip) values (?,?,?)").arg(table_name));
    query.bindValue(0, table_name);
    query.bindValue(1, ele_ch);
    query.bindValue(2,equip_name);
    if(!query.exec())
        QMessageBox::information(this,"提示","此通道已绑定",QMessageBox::Ok);
    else
        QMessageBox::information(this,"提示","绑定成功",QMessageBox::Ok);
}
/**
 * @brief wave_reout_ZJ::vol_ch_bind 绑定对应的电压通道并保存到数据库
 */
void wave_reout_ZJ::vol_ch_bind(int vol_ch)
{
    QString table_name = get_table_name();
    QSqlQuery query;
    query.prepare(QString("insert into %1(filename,ch,equip) values (?,?,?)").arg(table_name));
    query.bindValue(0, table_name);
    query.bindValue(1, vol_ch);
    query.bindValue(2,"电压");
    if(!query.exec())
        QMessageBox::information(this,"提示","电压通道已绑定",QMessageBox::Ok);
    else
        QMessageBox::information(this,"提示","绑定成功",QMessageBox::Ok);
}
/**
 * @brief wave_reout_ZJ::icon_bind 绑定对应的图标通道并保存到数据库
 */
void wave_reout_ZJ::icon_bind(QString icon_path,int ele_ch)
{
    if(icon_path.isEmpty())
    {
        return ;
    }
    QString table_name = get_table_name();
    QSqlQuery query;
    if(!query.exec(QString("update %1 set icon='%2' where ch='%3'").arg(table_name).arg(icon_path).arg(ele_ch)))
    {
        QMessageBox::information(this,"提示","未绑定电流通道",QMessageBox::Ok);
        qDebug()<<query.lastError();
    }
    else
        QMessageBox::information(this,"提示","绑定成功",QMessageBox::Ok);
}
/**
 * @brief wave_reout_ZJ::on_tabWidget_currentChanged
 * 页面切换，绑定对应的数据表
 */
void wave_reout_ZJ::on_tabWidget_currentChanged(int index)
{
    if(index == 0)
        setModel("loadfile");
    else if(index == 1)
        setModel("loadfile2");
}
void wave_reout_ZJ::cancel_click()
{
    ui->scene->clicked(ui->scene->currentIndex());
}
void wave_reout_ZJ::on_btViewWave_clicked()
{
    if(ui->scene->currentIndex().row()<0)
    {
        QMessageBox::information(this,"提示","请选择波形数据文件!");
    }else{
        if(ui->show_end->value()-ui->show_start->value()<=0)
        {
            QMessageBox::information(this,"提示","截止点不能小于或等于起始点！");
            return;
        }
        emit priview_map(ui->show_start->value(),ui->show_end->value()\
                        ,model->record(ui->scene->currentIndex().row()).value(1).toString(),0);
        emit priview_map(ui->show_start->value(),ui->show_end->value()\
                        ,model->record(ui->scene->currentIndex().row()).value(1).toString(),1);
    }
}
void wave_reout_ZJ::on_btViewWave_2_clicked()
{
    if(ui->scene->currentIndex().row()<0)
    {
        QMessageBox::information(this,"提示","请选择波形数据文件!");
    }else{
        if(ui->show_end_2->value()-ui->show_start->value()<=0)
        {
            QMessageBox::information(this,"提示","截止点不能小于或等于起始点！");
            return;
        }
        emit priview_map(ui->show_start_2->value(),ui->show_end_2->value()\
                        ,QString("./ele_wave_file_new/1_%1K.bin").arg(ui->sample_2->value()),0);
        emit priview_map(ui->show_start_2->value(),ui->show_end_2->value()\
                        ,QString("./ele_wave_file_new/1_%1K.bin").arg(ui->sample_2->value()),1);
    }

}
void wave_reout_ZJ::on_startOutput_clicked()
{
    if(ui->output_mode->currentText()=="A相"&&(ui->ia_max->value()>=20*1.414))
    {
        QMessageBox::information(this,"提示","电流过大，请选择三相并联");
        return ;
    }
    else if(ui->output_mode->currentText()=="三相并联"&&(ui->ia_max->value()>=1.414*20*3))
    {
        QMessageBox::information(this,"提示","电流过大!!!");
        return ;
    }
//    emit disConnect(1,true);
    emit setNowNum(1);
    startOutPut();
}
void wave_reout_ZJ::on_stopOutput_clicked()
{
//    emit disConnect(1,false);
    emit send_stop();
}
void wave_reout_ZJ::on_startOutput_2_clicked()
{
    if(!MainWindow::net_flag)
    {
        QMessageBox::information(this,"提示","请连接网口!");
        return;
    }
    if(ui->output_mode_2->currentText()=="A相"&&(ui->ia_max_2->value()>=20*1.414))
    {
        QMessageBox::information(this,"提示","电流过大，请选择三相并联");
        return ;
    }
    else if(ui->output_mode_2->currentText()=="三相并联"&&(ui->ia_max->value()>=1.414*20*3))
    {
        QMessageBox::information(this,"提示","电流过大!!!");
        return ;
    }
//    QFile file(QString("ele_wave_file_new/1_%1K.bin").arg(ui->sample_2->value()));
//    if (!file.open(QIODevice::ReadOnly)) {
//        QMessageBox::information(NULL,"提示","文件打开失败！");
//        return;
//    }
//    QDataStream data(&file);
//    double smaple=0;
//    int pipe_num=0;
//    quint32 all_size;
//    data>>smaple;
//    data>>pipe_num;
//    data>>all_size;
//    float max=0;
//    QVector<float> max_value;
//    for(int i=0;i<2;i++)
//    {
//        data>>max;
//        max_value<<max;
//    }
//    ui->energy_2->setValue(ui->energy_2->value()*(ui->ua_max_2->value()/max_value.at(0))*(ui->ia_max_2->value()/max_value.at(1)));
//    file.close();

    emit disConnect(1,true);
    if(ui->tabWidget->currentIndex()==1)
    {
        QMap<XL803::MARKERB, qint32> max_type;
        QByteArray send_data;

        if(ui->output_mode_2->currentText()=="A相")
        {
            max_type.insert(XL803::MARKERB_WAVE_UA,L_XL803->float_to_quint(ui->ua_max_2->value()));
            max_type.insert(XL803::MARKERB_WAVE_IA,L_XL803->float_to_quint(ui->ia_max_2->value()));
            max_type.insert(XL803::MARKERB_WT_UA,4);
            max_type.insert(XL803::MARKERB_WT_IA,4);
            send_data.append(0x55);
            send_data.append(0x55);


            send_data.append(0xAA);
            send_data.append(0xAA);


            send_data.append(0xAA);
            send_data.append(0xAA);
        }
        else{
            max_type.insert(XL803::MARKERB_WAVE_UA,L_XL803->float_to_quint(ui->ua_max_2->value()));
            max_type.insert(XL803::MARKERB_WAVE_IA,L_XL803->float_to_quint(ui->ia_max_2->value()/3));
            max_type.insert(XL803::MARKERB_WT_UA,4);
            max_type.insert(XL803::MARKERB_WT_IA,4);
            send_data.append(0x55);
            send_data.append(0x55);

            max_type.insert(XL803::MARKERB_WAVE_IB,L_XL803->float_to_quint(ui->ia_max_2->value()/3));
            max_type.insert(XL803::MARKERB_WT_IB,4);
            send_data.append(0xAA);
            send_data.append(0x55);

            max_type.insert(XL803::MARKERB_WAVE_IC,L_XL803->float_to_quint(ui->ia_max_2->value()/3));
            max_type.insert(XL803::MARKERB_WT_IC,4);
            send_data.append(0xAA);
            send_data.append(0x55);
        }

        is_big=false;
        send_data.append(0xAA);
        send_data.append(0xAA);


        double sample1=0;
        QFile file(QString("./ele_wave_file_out/1_%1k_A_0_1_2000.bin").arg(ui->sample_2->value()));
        if(ui->output_mode_2->currentText()=="A相")
            outFileName = QString("./ele_wave_file_out/1_%1k_A_0_1_2000.bin").arg(ui->sample_2->value());
        else
            outFileName = QString("./ele_wave_file_out/1_%1k_ABC_0_1_0_1_0_1_2000.bin").arg(ui->sample_2->value());
        QDataStream out(&file);
        if(!file.isOpen())
            file.open(QIODevice::ReadOnly);
        else
            out.device()->seek(0);
        out>>sample1;
        qint32 sample=0;
        sample=sample1;
        send_data.append(*((qint8*)&sample));
        send_data.append(*((qint8*)&sample+1));
        send_data.append(*((qint8*)&sample+2));
        send_data.append(*((qint8*)&sample+3));
        //把峰值先写到底层
        //当A相时，只写入UA IA的峰值，当三相并联时，则写入UA IA IB IC（峰值的1/3）
        L_XL803->COM_HightWrite(max_type,XL803::wave_reout_ZJ);
        //启动录播回放
        L_XL803->big_wave_reout(send_data,XL803::wave_reout_ZJ);
        file.close();
    }
}
void wave_reout_ZJ::on_stopOutput_2_clicked()
{
    emit send_stop();
}
void wave_reout_ZJ::on_btAdd_clicked()
{
    QSettings *setting = new QSettings("./config.ini", QSettings::IniFormat);
    QString open_path = setting->value("path").toString();
    QString file_name = QFileDialog::getOpenFileName(NULL,"选择文件",open_path,"*.*");
    if(!file_name.isEmpty()&&(file_name.contains(".CSV")||file_name.contains(".csv")))
    {
        fileNameCSV = file_name;
        setting->setValue("path",file_name);
        //获取场景名与原始采样率
        Dialog_CSV *m_dialog_csv = new Dialog_CSV(this);
        QStringList nameList = fileNameCSV.split("/");
        QVector<QString> strVector;
        foreach(QString s,nameList)
         strVector.append(s);
        strVector.removeLast();
        QString str = strVector.at(strVector.count()-1);
        m_dialog_csv->setLineEdit(str);
        connect(m_dialog_csv,SIGNAL(sendFileName(QString,int)),this,SLOT(getFileName(QString,int)));
        connect(m_dialog_csv,SIGNAL(sendFileSample(double)),&m_file,SLOT(getFileSample(double)),Qt::QueuedConnection);
        m_dialog_csv->setType(0);
        m_dialog_csv->show();
    }
    else
        return ;
}
void wave_reout_ZJ::on_btRemove_clicked()
{
    if(ui->scene->currentIndex().row()<0)
    {
        QMessageBox::information(this,"提示","请选择波形文件",QMessageBox::Ok);
        qDebug()<<"2072";
        return;
    }
    if(QMessageBox::Yes==QMessageBox::information(this,"提示","是否删除",QMessageBox::Yes|QMessageBox::No))
    {
       QString file_name = model->data(model->index(ui->scene->currentIndex().row(),1)).toString();
       model->removeRow(ui->scene->currentIndex().row());
       model->submitAll();
       model->select();
       QSqlQuery query;
       QString sql = QString("delete from %1").arg(file_name);
       if(!query.exec(sql))
           qDebug()<<query.lastError();
       QSettings *setting = new QSettings("./config.ini", QSettings::IniFormat);
       QStringList tmp = setting->value("list").toStringList();
       for(int i=0;i<tmp.count();i++)
       {
            if(tmp.indexOf(file_name+QString::number(ui->energy->value())))
            {
                tmp.removeAt(i);
                setting->setValue("list",tmp);
            }
       }

    }
}
void wave_reout_ZJ::on_btAdd_2_clicked()
{
    QSettings *setting = new QSettings("./config.ini", QSettings::IniFormat);
    QString open_path = setting->value("comtradepath").toString();
    QString file_name = QFileDialog::getOpenFileName(NULL,"选择文件",open_path,"*.*");
    if(!file_name.isEmpty()&&(file_name.contains(".dat")||file_name.contains(".cfg")||file_name.contains(".DAT")||file_name.contains(".CFG")))
    {
        setting->setValue("comtradepath",file_name);
        fileNameCom = file_name;
        fileNameCom = fileNameCom.toLower();
        Dialog_CSV *m_dialog_com = new Dialog_CSV(this);
        connect(m_dialog_com,SIGNAL(sendFileName(QString,int)),this,SLOT(getFileName(QString,int)));
        m_dialog_com->setType(1);
        m_dialog_com->show();
    }
    else
        QMessageBox::information(this,"提示","文件类型错误",QMessageBox::Ok);
}
void wave_reout_ZJ::on_btRemove_2_clicked()
{
    if(ui->scene->currentIndex().row()<0)
    {
        QMessageBox::information(this,"提示","请选择波形文件",QMessageBox::Ok);
                qDebug()<<"2122";
        return;
    }
    if(QMessageBox::Yes==QMessageBox::information(this,"提示","是否删除",QMessageBox::Yes|QMessageBox::No))
    {
       QString file_name = model->data(model->index(ui->scene->currentIndex().row(),1)).toString();
       model->removeRow(ui->scene->currentIndex().row());
       model->submitAll();
       model->select();
       QSqlQuery query;
       QString sql = QString("delete from %1").arg(file_name);
       if(!query.exec(sql))
           qDebug()<<query.lastError();
       list.clear();
       ui->scrollArea->setWidget(new QWidget());
    }
}
void wave_reout_ZJ::on_eleRev_clicked(bool checked)
{
    if(checked)
      revFlag = true;
    else
      revFlag = false;
}

void wave_reout_ZJ::on_eleRev_2_clicked(bool checked)
{
    if(checked)
      revFlag_2 = true;
    else
      revFlag_2 = false;
}

void wave_reout_ZJ::on_insertMode_currentIndexChanged(int index)
{
    QSettings *setting = new QSettings("./config.ini", QSettings::IniFormat);
    setting->setValue("mode",QString::number(index));
}

void wave_reout_ZJ::on_insertMode_2_currentIndexChanged(int index)
{
    QSettings *setting = new QSettings("./config.ini", QSettings::IniFormat);
    setting->setValue("mode2",QString::number(index));
}
void wave_reout_ZJ::on_configPipe_clicked()
{
    if(ui->scene->currentIndex().row()<0)
    {
        QMessageBox::information(this,"提示","请选择波形文件",QMessageBox::Ok);
                qDebug()<<"2171";
        return;
    }
    int pipe_count = get_pipe_count("./scene/"+model->data(model->index(ui->scene->currentIndex().row(),1)).toString()+".tmp");
    Dialog *m_dialog = new Dialog(this);
    connect(m_dialog,SIGNAL(bind_ele_ch(int,QString)),this,SLOT(ele_ch_bind(int,QString)));
    connect(m_dialog,SIGNAL(bind_vol_ch(int)),this,SLOT(vol_ch_bind(int)));
    connect(m_dialog,SIGNAL(bind_icon(QString,int)),this,SLOT(icon_bind(QString,int)));
    connect(m_dialog,SIGNAL(click_cancel()),this,SLOT(cancel_click()));
    m_dialog->setMaxValue(pipe_count);
    m_dialog->show();
    ui->scene->clicked(ui->scene->currentIndex());
}
void wave_reout_ZJ::on_scene_clicked(const QModelIndex &index)
{
    if(ui->tabWidget->currentIndex()==0)
    {
            QFile file(model->record(index.row()).value(1).toString());
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
            float max=0;
            QVector<float> max_value;
            for(int i=0;i<2;i++)
            {
                data>>max;
                max_value<<max;
            }
            ui->ua_max->setValue(max_value.at(0));
            ui->ia_max->setValue(max_value.at(1));
            curMaxValue = max_value;
            file.close();
//            ui->priview_pipe->setRange(1,pipe_num);
            ui->show_start->setRange(0,all_size-1);
            ui->show_end->setRange(0,all_size-1);
            ui->show_end->setValue(all_size-1);
            QSettings *setting = new QSettings("./config.ini", QSettings::IniFormat);
            QStringList strlist = setting->value("list").toStringList();
            for(int i=0;i<strlist.count();i++)
            {
                if(-1!=strlist.at(i).indexOf(model->record(index.row()).value(1).toString()))
                {
                    QString value = strlist.at(i).mid(strlist.at(i).lastIndexOf("_")+1);
                    ui->energy->setValue(value.toFloat());
                }
            }
            ui->btViewWave->click();

    }
    else if(ui->tabWidget->currentIndex()==1)
    {
        if(ui->startOutput_2->isEnabled())
        {
            QFile file(QString("ele_wave_file_new/1_%1K.bin").arg(ui->sample_2->value()));
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
            float max=0;
            QVector<float> max_value;
            for(int i=0;i<2;i++)
            {
                data>>max;
                max_value<<max;
            }
            ui->ua_max_2->setValue(max_value.at(0));
            ui->ia_max_2->setValue(max_value.at(1));
            file.close();
            ui->show_start_2->setRange(0,all_size-1);
            ui->show_end_2->setRange(0,all_size-1);
            ui->show_end_2->setValue(all_size-1);
        }
        info_list.clear();
        table_info_list.clear();
        QString table_name = get_table_name();
        //到数据库中读取电流通道的配置信息并显示在界面上
        QSqlQuery query;
        query.exec(QString("select * from %1").arg(table_name));
        while(query.next())
        {
            QSqlRecord record = query.record();
            if(record.value(3).toString()!="电压")
            {
                info_list.clear();
                info_list<<record.value(1).toString()<<record.value(2).toString()<<record.value(3).toString()<<record.value(4).toString();
                table_info_list.append(info_list);
            }
        }
        QHBoxLayout *h_layout = new QHBoxLayout;
        for(int i=0;i<table_info_list.count();i++)
        {
           QString icon_path = table_info_list.at(i).at(3);
           QString equip_name = table_info_list.at(i).at(2);
           MyCBB *b = new MyCBB();
           connect(b,&MyCBB::append_list,this,&wave_reout_ZJ::list_append);
           connect(b,&MyCBB::remove_list,this,&wave_reout_ZJ::list_remove);
           connect(b,&MyCBB::set_enable_false,this,&wave_reout_ZJ::set_false_enable);
           if(icon_path.isEmpty())
               b->setIcon(QIcon("./image/未知设备.png"));
           else
               b->setIcon(QIcon(icon_path));
           b->setIconSize(QSize(30,30));
           b->setLabelText(equip_name);
           list.clear();
           h_layout->addWidget(b);
           v_hbox.append(b);

        }
        QWidget *bbb = new QWidget();
        bbb->setLayout(h_layout);
        ui->scrollArea->setWidget(bbb);


    }
}
void wave_reout_ZJ::on_overlayWave_clicked()
{
    if(ui->scene->currentIndex().row()<0)
    {
        QMessageBox::information(this,"提示","请选择场景");
        return ;
    }
    if(list.isEmpty())
    {
        QMessageBox::information(this,"提示","至少选择一个用电器");
        return ;
    }
    qDebug()<<"list"<<list;
    QList<int> ch_list;
    QString table_name = get_table_name();
    QVector<float> data_vol;
    QString tmp_file_name = "./scene/"+ui->scene->currentIndex().data(0).toString()+".tmp";
    //获取电压通道的数据
    QSqlQuery query;
    query.exec(QString("select ch from %1 where equip = '电压'").arg(table_name));
    if(query.next())
    {
        QSqlRecord record = query.record();
//        data_vol = GetVol(record.value(0).toInt(),tmp_file_name);
        data_vol = m_file.getVol(record.value(0).toInt(),tmp_file_name);
    }
    else
        return ;
    //获取组合选中的用电器
    for(int i=0;i<list.count();i++)
    {
        query.exec(QString("select ch from %1 where equip = '%2'").arg(table_name).arg(list.at(i)));
        while(query.next())
        {
            QSqlRecord record = query.record();
            ch_list.append(record.value(0).toInt());
        }
    }
//    qDebug()<<"ch_list"<<ch_list;
    //获取经过叠加以后的电流通道数据
//    QVector<float> data_ele = OverLay(ch_list,tmp_file_name);
    QVector<float> data_ele = m_file.overLay(ch_list,tmp_file_name,revFlag_2);
//    //将电压和电流数据写入到文件中
//    if(!Write_to_tmp(data_vol,data_ele,tmp_file_name))
//        qDebug()<<"write fail";
    m_file.writeToTmp(data_vol,data_ele,tmp_file_name);
    //进行重采样
    m_file.file("./1.tmp",ui->sample_2->value(),2000,1);
    //计算理论电能
    energy1 = m_file.calEnergy(data_vol,data_ele,1);
    ui->energy_2->setValue(energy1);
    //往UA和IA通道输出
    index_vector.clear();
    pipe_vector.clear();
    if(ui->output_mode->currentText()=="三相并联")
    {
        index_vector.append(0);
        pipe_vector.append(0);
        pipe_vector.append(1);

        index_vector.append(1);
        pipe_vector.append(0);
        pipe_vector.append(1);

        index_vector.append(2);
        pipe_vector.append(0);
        pipe_vector.append(1);
    }else
    {
        index_vector.append(0);
        pipe_vector.append(0);
        pipe_vector.append(1);
    }
    QString str = QString("ele_wave_file_new/1_%1k.bin").arg(ui->sample_2->value());
    emit send_out_path(str,index_vector,\
                       pipe_vector,2000,1);
    ui->startOutput_2->setEnabled(true);
    ui->btViewWave_2->setEnabled(true);
    QMessageBox::information(this,"提示","电流叠加完成");
    ui->energy_2->setValue(energy1);
    ui->scene->clicked(ui->scene->currentIndex());
}
void wave_reout_ZJ::on_ua_max_editingFinished()
{
    QSettings *setting = new QSettings("./config.ini", QSettings::IniFormat);
    QStringList strlist = setting->value("list").toStringList();
    for(int i=0;i<strlist.count();i++)
    {
        if(-1!=strlist.at(i).indexOf(model->record(ui->scene->currentIndex().row()).value(1).toString()))
        {
            QString value = strlist.at(i).mid(strlist.at(i).lastIndexOf("_")+1);
            //通过用户设置的峰值与默认的峰值按比例算出理论电能
            ui->energy->setValue(value.toFloat()*(ui->ua_max->value()/curMaxValue.at(0))*(ui->ia_max->value()/curMaxValue.at(1)));
        }
    }
}
void wave_reout_ZJ::on_ia_max_editingFinished()
{
    QSettings *setting = new QSettings("./config.ini", QSettings::IniFormat);
    QStringList strlist = setting->value("list").toStringList();
    for(int i=0;i<strlist.count();i++)
    {
        if(-1!=strlist.at(i).indexOf(model->record(ui->scene->currentIndex().row()).value(1).toString()))
        {
            QString value = strlist.at(i).mid(strlist.at(i).lastIndexOf("_")+1);
            //通过用户设置的峰值与默认的峰值按比例算出理论电能
            ui->energy->setValue(value.toFloat()*(ui->ua_max->value()/curMaxValue.at(0))*(ui->ia_max->value()/curMaxValue.at(1)));
        }
    }
}
