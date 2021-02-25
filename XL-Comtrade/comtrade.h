#ifndef COMTRADE_H
#define COMTRADE_H
#include<vector>
#include"dataType.h"

using namespace std;

typedef struct
{
	/// <summary>
	/// 数据值
	/// </summary>
	double value;
	/// <summary>
	/// X轴时间
	/// </summary>
	double time;
} DataPoint;
 
typedef struct
{
	/// <summary>
	/// 站名称，非必需，最大长度64字符
	/// </summary>
	char station_name[64];
	/// <summary>
	/// 录波仪的ID信息，非必须，最大长度64字符
	/// </summary>
	char rec_dev_id[64];
	/// <summary>
	/// comtrade文件的版本号，必须，如果缺少，则按照comtrade 1991 标准进行兼容解读
	/// </summary>
	char rev_year[4];
} Cmtr_summary;

typedef struct
{
	/// <summary>
	/// 总数量
	/// </summary>
	int totalNumber;
	/// <summary>
	/// 模拟量通道个数
	/// </summary>
	int analogNumber;
	/// <summary>
	/// 数字量通道个数
	/// </summary>
	int digitalNumber;
} Cmtr_channel_number;

typedef struct
{
	/// <summary>
	/// 通道编号
	/// </summary>
	int An;
	/// <summary>
	/// 通道文字说明
	/// </summary>
	char ch_id[64];
	/// <summary>
	/// 通道相位特征 A\B\C等
	/// </summary>
	char ph[2];
	/// <summary>
	/// 被监视元件名称
	/// </summary>
	char ccbm[64];
	/// <summary>
	/// 通道单位 kV,V,kA,A,k（千）,m（千分之一）,M(百万)等均可以被使用
	/// </summary>
	char uu[32];
	/// <summary>
	/// 通道乘数
	/// </summary>
	double a;
	/// <summary>
	/// 通道偏移量
	/// </summary>
	double b;
	/// <summary>
	/// 通道时滞（us）
	/// </summary>
	double skew;
	/// <summary>
	/// 通道最小值
	/// </summary>
	INT min;
	/// <summary>
	/// 通道最大值
	/// </summary>
	INT max;
	/// <summary>
	/// 通道变比：一次系数
	/// </summary>
	double primary;
	/// <summary>
	/// 通道变比：二次系数
	/// </summary>
	double secondary;
	/// <summary>
	/// 通道内容是一次值还是二次，P 一次， S 二次
	/// aX+b 的结果是一次还是二次
	/// </summary>
	char ps;
} Cmtr_analog_cfg;

typedef struct
{
	/// <summary>
	/// 通道号
	/// </summary>
	INT Dn;
	/// <summary>
	/// 通道名称
	/// </summary>
	char ch_id[32];
	/// <summary>
	/// 通道相位特征
	/// </summary>
	char ph[2];
	/// <summary>
	/// 被检测元件名称
	/// </summary>
	char ccbm[64];
	/// <summary>
	/// 数字量起始状态值
	/// </summary>
	INT y;
} Cmtr_digital_cfg;

typedef struct
{
	/// <summary>
	/// 采样率
	/// </summary>
	double samp;
	/// <summary>
	/// 以samp为采样率，采样结束时的点位置
	/// </summary>
	INT endSamp;
} Cmtr_samprate;

typedef struct
{
	/// <summary>
	/// 天
	/// </summary>
	int DD;
	/// <summary>
	/// 月份
	/// </summary>
	int MM;
	/// <summary>
	/// 年
	/// </summary>
	int YY;
	/// <summary>
	/// 小时
	/// </summary>
	int hh;
	/// <summary>
	/// 分钟
	/// </summary>
	int mm;
	/// <summary>
	/// 秒和毫秒部分
	/// </summary>
	int ss_ssssss;
} Cmtr_datetime;

typedef struct
{
	Cmtr_summary cmtrSummary;//概括
	Cmtr_channel_number cmtrChannelNumber;//通道个数统计
	vector<Cmtr_analog_cfg> cmtrAnalogCfg;//模拟通道配置
	vector<Cmtr_digital_cfg> cmtrDigitalCfg;//数字通道配置
	double frequency;//线路频率
	INT nrates;//采样率个数
	vector<Cmtr_samprate> cmtrSamprate;//nrates个的采样信息
	Cmtr_datetime firstRecordTime;//文件记录的首个时间
	Cmtr_datetime triggerTime;//触发点的时间
	char dataType[6];//文件类型
	double timeult;//时间标记乘数系数
} Comtrade_cfg;

typedef struct {

	int  num;
	int   timestamp;
	vector<INT16>  analogValues; //动态分配模拟量的通道内存，根据cfg里面的an分配即可
	vector<INT16>   digitValues;  //动态分配数字量的通道内存，根据cfg里面的dn分配即可s
} Cmtr_dat_row;

/// <summary>
/// 将.CFG 文件读取到内存中
/// </summary>
int parseComtradeConfig(const char* fileName, Comtrade_cfg* cfg);
/// <summary>
/// 将数据文件以binary的方式读取容器中
/// </summary>
int parseComtradeBinaryData(const char* fileName);
/// <summary>
/// 将数据文件以Ascii的方式读取到容器中
/// </summary>
int parseComtradeAsciiData(const char* fileName);

/// <summary>
/// 将comtrade 文件进行转换
/// </summary>
extern "C" __declspec(dllexport) void parse_comtrade_file(const char* fileName); 
/// <summary>
/// 获取文件通道个数
/// </summary>
extern "C" __declspec(dllexport) int get_comtrade_an_chan_num();
/// <summary>
/// 获取最大采样率
/// </summary>
extern "C" __declspec(dllexport) double get_max_samprate();
/// <summary>
/// 获取起始采样时间
/// </summary>
extern "C" __declspec(dllexport) double get_first_samp_time();
/// <summary>
/// 获取结束采样时间
/// </summary>
extern "C" __declspec(dllexport) double get_end_samp_time();
/// <summary>
/// 获取通道数据模拟量数据
/// </summary>
///analogValue 存放数据的内存
extern "C" __declspec(dllexport) int get_chan_value(UINT chanNo,double startTime,double endTime,double* analogValue,INT len);
/// <summary>
/// 销毁相关的数据资源
/// </summary>
extern "C" __declspec(dllexport) void destory_comtrade();

#endif COMTRADE_H