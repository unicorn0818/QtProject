#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include<vector>
#include <fstream>  
#include <string>  
#include <iostream>  
#include "comtrade.h"
#include"stringtool.h"
#include"Lagrange.h"
#include "Interpolation.h"
#define IPC 5

using namespace std;



Comtrade_cfg mComtradeCfg;//Comtrade 配置文件
vector<Cmtr_dat_row> mDataRows;//DAT 原始数据行

/// <summary>
/// 将.CFG 文件读取到内存中
/// </summary>
int parseComtradeConfig(const char* fileName, Comtrade_cfg* cfg)
{
	ifstream in(fileName);
	string line;
	vector<string> lines;

	if (in) // 有该文件  
	{
		while (getline(in, line)) // line中不包括每行的换行符  
		{
			lines.push_back(line);
			//cout << line << endl;
		}
		if (lines.size() < 5)//先判断是否存在足够的行数 
		{
			in.close();
			return -2;
		}
		else
		{
//			int version = lines[0].find("1999");
//			if (version)
//			{
				int rowIndex = 0;
				//1.0 读取Summary概括信息 0 ROW
				vector<string> summary = stringSplit(lines[0], ","); rowIndex++;
				if (summary.size() >= 3)
				{
					strcpy(cfg->cmtrSummary.station_name, summary[0].data());
					strcpy(cfg->cmtrSummary.rec_dev_id, summary[1].data());
					strcpy(cfg->cmtrSummary.rev_year, summary[2].data());
				}

				// 2.0 读取通道统计信息
				vector<string> counter = stringSplit(lines[1], ","); rowIndex++;
				if (summary.size() >= 3)
				{
					char countTmp[10] = { 0 };
					const char *strAnalogNubmer = counter[1].data();
					const char *strDigitalNumber = counter[2].data();
					cfg->cmtrChannelNumber.totalNumber = str_to_int(counter[0].data());
					strncpy(countTmp, strAnalogNubmer, strlen(strAnalogNubmer) - 1);
					cfg->cmtrChannelNumber.analogNumber = str_to_int(countTmp);
					memset(countTmp, 0, 10);
					strncpy(countTmp, strDigitalNumber, strlen(strDigitalNumber) - 1);
					cfg->cmtrChannelNumber.digitalNumber = str_to_int(countTmp);
				}

				//2.0.1 计算配置文件的行数是否符合规范
				int rowLen = 2 + cfg->cmtrChannelNumber.totalNumber;
				rowLen = rowLen + str_to_int(lines[rowLen + 1].data()) + 6;
				if (lines.size() < rowLen)
				{
					in.close();
					printf("ERROR: 配置文件行数和1999版本不匹配!");
					return -4;
				}
				// 3.0 读取模拟量通道信息
				for (int i = 0; i < cfg->cmtrChannelNumber.analogNumber; i++)
				{
					vector<string> adiInfo = stringSplit(lines[rowIndex], ",");
					if (adiInfo.size() != 13)
					{
						in.close();
						return -5;
					}

					Cmtr_analog_cfg analogCfgRow;

					analogCfgRow.An = str_to_int(adiInfo[0].data());//编号
					strcpy(analogCfgRow.ch_id, adiInfo[1].data());// ch_id
					strcpy(analogCfgRow.ph, adiInfo[2].data());//ph 
					strcpy(analogCfgRow.ccbm, adiInfo[3].data());//ccbm
					strcpy(analogCfgRow.uu, adiInfo[4].data());//uu  数据单位 A V kV kA 等。。。
					analogCfgRow.a = str_to_double(adiInfo[5].data());// aX+b 通道乘数a
					analogCfgRow.b = str_to_double(adiInfo[6].data());// aX+b 通道偏移数b
					analogCfgRow.skew = str_to_double(adiInfo[7].data());// 通道时滞
					analogCfgRow.min = str_to_int(adiInfo[8].data());// 通道时滞
					analogCfgRow.max = str_to_int(adiInfo[9].data());// 通道时滞
					analogCfgRow.primary = str_to_double(adiInfo[10].data());// 通道时滞
					analogCfgRow.secondary = str_to_double(adiInfo[11].data());// 通道时滞
					analogCfgRow.ps = *(adiInfo[12].data()); //ps
					cfg->cmtrAnalogCfg.push_back(analogCfgRow);
					rowIndex++;
				}

				// 4.0 读取数字量通道信息
				for (int i = 0; i < cfg->cmtrChannelNumber.digitalNumber; i++)
				{

					vector<string> digInfo = stringSplit(lines[rowIndex], ",");
					if (digInfo.size() != 5)
					{
						in.close();
						return -5;
					}

					Cmtr_digital_cfg digitalCfg;
					digitalCfg.Dn = str_to_int(digInfo[0].data());//编号
					strcpy(digitalCfg.ch_id, digInfo[1].data());// ch_id
					strcpy(digitalCfg.ph, digInfo[2].data());// ch_id
					strcpy(digitalCfg.ccbm, digInfo[3].data());// ch_id
					digitalCfg.y = str_to_int(digInfo[4].data());// 
					cfg->cmtrDigitalCfg.push_back(digitalCfg);
					rowIndex++;
				}

				//5.0 读取主线频率
				cfg->frequency = str_to_double(lines[rowIndex].data()); rowIndex++;

				//6.0 读取采样率个数
				cfg->nrates = str_to_int(lines[rowIndex].data()); rowIndex++;

				//7.0 读取采样率信息
				for (int i = 0; i < cfg->nrates; i++)
				{
					vector<string> sampInfo = stringSplit(lines[rowIndex], ",");
					Cmtr_samprate samp;
					samp.samp = str_to_double(sampInfo[0].data());
					samp.endSamp = str_to_int(sampInfo[1].data());
					cfg->cmtrSamprate.push_back(samp);
					rowIndex++;
				}

				//8.0 读取时间信息
				rowIndex++;
				rowIndex++;
				//TODO:GET THE TIME FOR COMTRADE

				//9.0 读取文件存贮类型 binary or ascii 
				strcpy(cfg->dataType, lines[rowIndex].data()); rowIndex++;

				//10.0 读取时间标记乘数信息timemult信息
				cfg->timeult = str_to_double(lines[rowIndex].data());

				in.close();
				return 1;
//			}
//			else
//			{
//				in.close();
//				//当前没有找到1991标准的文档，先不对1991 标准进行兼容处理
//				return -3;
//			}
		}
	}
	else // 没有该文件  
	{
		printf("ERROR:没有找到该文件或者该文件当前正在被占用!");
		return -1;
	}
	return -1;
}
/// <summary>
/// 将数据文件以binary的方式读取容器中
/// </summary>
int parseComtradeBinaryData(const char* fileName)
{

	//先计算每一行数据一共有多少个字节
	int dh = mComtradeCfg.cmtrChannelNumber.digitalNumber / 16;
	int dl = mComtradeCfg.cmtrChannelNumber.digitalNumber % 16;
	dh = dl > 0 ? (dh + 1) : dh;
	const int rowByteLenght = 4 + 4 + (mComtradeCfg.cmtrChannelNumber.analogNumber * 2) + dh * 2;
	//缓冲区
	char * buffer = new char[rowByteLenght];

	//然后按照每N个字节读取一次
	std::ifstream in(fileName, std::ifstream::binary);
	if (in)
	{
		// get length of file:
		in.seekg(0, in.end);
		//int length = in.tellg(); //totalSize
		in.seekg(0, in.beg);
		int mSeek = 0;
		while (1)
		{
			in.read(buffer, rowByteLenght);
			int realSize = in.gcount();
			if (realSize < rowByteLenght)
				break;
			//计算数据
			int index = 0;
			Cmtr_dat_row row;
			row.num = *((int*)(buffer + index)); index += 4;
			row.timestamp = *((int*)(buffer + index)); index += 4;
			for (int j = 0; j < mComtradeCfg.cmtrChannelNumber.analogNumber; j++)
			{
				INT16 adiValue = *((INT16*)(buffer + index));
				//printf("calc=%f , binary data=%d,\n", (mComtradeCfg.cmtrAnalogCfg[39].a*adiValue + mComtradeCfg.cmtrAnalogCfg[39].b), adiValue);
				row.analogValues.push_back(adiValue);
				index += 2;
			}
			//TODO:数字量通道暂时不解析
			mDataRows.push_back(row);
			mSeek += realSize;
		}
		delete[] buffer;
	}
	else
	{
		return -1;
	}
	in.close();
	return 1;
}
/// <summary>
/// 将数据文件以Ascii的方式读取到容器中
/// </summary>
int parseComtradeAsciiData(const char* fileName)
{
	ifstream in(fileName);
	string line;
	vector<string> lines;
	if (in)
	{
		while (getline(in, line)) // line中不包括每行的换行符  
		{
			lines.push_back(line);
			/*cout << line << endl;*/
		}
		for (int i = 0; i < lines.size(); i++)
		{
			vector<string> dataRow = stringSplit(lines[i], ",");
			int rowIndex = 0;
			if (dataRow.size() < (mComtradeCfg.cmtrChannelNumber.totalNumber + 2))
			{
				in.close();
				return -3;
			}
			Cmtr_dat_row row;
			row.num = str_to_int(dataRow[rowIndex].data()); rowIndex++;
			row.timestamp = str_to_int(dataRow[rowIndex].data()); rowIndex++;
			for (int j = 0; j < mComtradeCfg.cmtrChannelNumber.analogNumber; j++)
			{
				int adv = str_to_int(dataRow[rowIndex].data());
				row.analogValues.push_back(adv);
				rowIndex++;
			}
			for (int j = 0; j < mComtradeCfg.cmtrChannelNumber.digitalNumber; j++)
			{
				row.digitValues.push_back(str_to_int(dataRow[rowIndex].data()));
				rowIndex++;
			}
			mDataRows.push_back(row);
		}
		in.close();
		return 1;
	}
	else
	{
		return -2;
	}
	in.close();
	return -1;
}


/// <summary>
/// 将comtrade 文件进行转换
/// 
/// 读取该cfg文件获取配置信息
/// 
/// </summary>
void parse_comtrade_file(const char* fileName)
{
	char filePath[256] = { 0 };
	if (!fileName)
	{
		printf("ERROR:文件路径为空\n");
		return;
	}
    if (fileName[strlen(fileName) - 4] != '.')//判断是后缀是否为.xxx
	{
		printf("ERROR:文件读取失败\n");
		return;
	}
	int fileNameLen = strlen(fileName);
	strncpy(filePath, fileName, fileNameLen - 4);//去除.CFG .DAT

	mComtradeCfg.cmtrAnalogCfg.clear();//清除模拟量通道信息
	mComtradeCfg.cmtrDigitalCfg.clear();//清除数字量通道信息
	mComtradeCfg.cmtrSamprate.clear();//清除采样率信息
	mDataRows.clear();//读取数据前，先对原始数据记录进行清空

	char configPath[256] = { 0 };
	strcat(filePath, ".cfg");
    //将.CFG 文件读取到内存中
	int result = parseComtradeConfig(filePath, &mComtradeCfg);
	if (result)
	{
		int fileNameLen = strlen(fileName);
		memset(filePath, 0, strlen(filePath));
		strncpy(filePath, fileName, fileNameLen - 4);//去除.CFG .DAT
		strcat(filePath, ".dat");
		for (int i = 0; i < strlen(mComtradeCfg.dataType); i++)
		{
			mComtradeCfg.dataType[i] = toupper(mComtradeCfg.dataType[i]);//转换为大写后再进行比较
		}
		if (strncmp(mComtradeCfg.dataType, "ASCII", 5) == 0)
		{
			result = parseComtradeAsciiData(filePath);//读取ASCII数据
		}
		else if (strncmp(mComtradeCfg.dataType, "BINARY", 6) == 0)
		{
			result = parseComtradeBinaryData(filePath);//读取BINARY数据
		}
		else
		{
			printf("ERROR:文件类型错误 not ASCII or BINARY");
		}
	}
}
/// <summary>
/// 获取文件通道个数
/// </summary>
int get_comtrade_an_chan_num()
{
    return mComtradeCfg.cmtrChannelNumber.analogNumber;
}
/// <summary>
/// 获取最大采样率
/// </summary>
double get_max_samprate()
{
	if (mComtradeCfg.cmtrSamprate.size() <= 0)
	{
		return 0;
	}
	else
	{
		int maxSamp = 0;
		for (int i = 0; i < mComtradeCfg.cmtrSamprate.size(); i++)
		{
			if (maxSamp < mComtradeCfg.cmtrSamprate[i].samp)
			{
				maxSamp = mComtradeCfg.cmtrSamprate[i].samp;
			}
		}
		return maxSamp;
	}
	return 0;
}
/// <summary>
/// 获取起始采样时间,单位 s
/// </summary>
double get_first_samp_time()
{
	return 0;
}
/// <summary>
/// 获取结束采样时间,单位 s
/// </summary>
double get_end_samp_time()
{
	double seconds = 0;
	int lastIndex = 0;
	for (int i = 0; i < mComtradeCfg.cmtrSamprate.size(); i++)
	{
		seconds = seconds + (1.0 / (mComtradeCfg.cmtrSamprate[i].samp))*(mComtradeCfg.cmtrSamprate[i].endSamp - lastIndex);
		lastIndex = mComtradeCfg.cmtrSamprate[i].endSamp;
	}

	return seconds;
}
/// <summary>
/// 获取通道数据模拟量数据
/// </summary>
int get_chan_value(UINT chanNo, DOUBLE startTime, DOUBLE endTime, DOUBLE* analogValue, INT len)
{
	if (mDataRows.size() < 1)
	{
		return -1;
	}

	if (chanNo == 0 || chanNo > mComtradeCfg.cmtrChannelNumber.analogNumber)
	{
		printf("ERROR:通道号不正确");
		return -2;
	}

	double firstTime = get_first_samp_time();

	if (endTime <= firstTime)
	{
		printf("ERROR:时间区间设置不正确-3");
		return -3;
	}

	if ((endTime - startTime) <= 0)
	{
		printf("ERROR:时间区间设置不正确-4");
		return -3;
	}

	if (startTime >= (get_end_samp_time()))
	{
		printf("ERROR:时间区间设置不正确-5");
		return -5;
	}

	double maxSamprate = get_max_samprate();
	vector<DataPoint> dataPoints;
	int lastPointIndex = 0;
	double timePerPoint = (1.0 / maxSamprate);//每一个点的时间间距（最大采样率下）,单位秒（s）
	//将所有的数据点序列化到一个采样率中
	for (int i = 0; i < mComtradeCfg.cmtrSamprate.size(); i++)
	{
#pragma region MyRegion
		if (mComtradeCfg.cmtrSamprate[i].samp < maxSamprate)
		{
			//读取原始数据
			vector<DataPoint> temp;
			vector<DataPoint> interpPoints;//插值后的点
			int count = mComtradeCfg.cmtrSamprate[i].endSamp - lastPointIndex;
			double tempTimePerPoint = 1.0 / (mComtradeCfg.cmtrSamprate[i].samp);//未插值前的每个点时间间距
			int realSize = mDataRows.size();
			for (int j = 0; j < count; j++)
			{
				if ((lastPointIndex + j) < realSize)
				{
					DataPoint point;
					int regionData = mDataRows[lastPointIndex + j].analogValues[chanNo - 1];//获取原始值
					point.value = (mComtradeCfg.cmtrAnalogCfg[chanNo - 1].a)*regionData + (mComtradeCfg.cmtrAnalogCfg[chanNo - 1].b);//计算原始值aX+b
					point.time = (temp.size() + 1)*tempTimePerPoint;//时间点，单位s
					temp.push_back(point);
				}
			}

			//拉格朗日插值
			double timeSub = (temp[temp.size() - 1].time) - (temp[0].time);//计算时间差
			int countInterpolation = (int)(timeSub / timePerPoint);//总时间/单个采样点的时间=采样个数

			int foreachH = temp.size() / IPC;
			int foreachL = temp.size() % IPC;

			int foreachIndex = 0;
			int countAfterInp = (int)((5 * maxSamprate) / (mComtradeCfg.cmtrSamprate[i].samp));//没20个数据应该插值多少个目标
			//按20个每组进行线性插值
			for (int j = 0; j < foreachH; j++)
			{
				//准备20组数据
				for (int k = 0; k < IPC; k++)
				{
					interpolationD[k].x = temp[foreachIndex + k].time;
					interpolationD[k].y = temp[foreachIndex + k].value;
				}
				//计算在20组数据中，需要插值结果几个点
				double sTime = interpolationD[0].x;//20组的起始时间	
				for (int k = 0; k < countAfterInp; k++)
				{
					double tempTime = sTime + (k*timePerPoint);//当前点的时间（未插值前）
					DataPoint interpPoint;
					interpPoint.value = lagrange(tempTime, IPC);
					interpPoints.push_back(interpPoint);
				}
				foreachIndex += IPC;
			}
			//按剩下的数据进行插值
			if (foreachL > 0)
			{
				countAfterInp = (int)((foreachL * maxSamprate) / (mComtradeCfg.cmtrSamprate[i].samp));//没n个数据应该插值多少个目标
				for (int k = 0; k < foreachL; k++)
				{
					interpolationD[k].x = temp[foreachIndex + k].time;
					interpolationD[k].y = temp[foreachIndex + k].value;
				}
				//计算countAfterInp在组数据中，需要插值结果几个点
				double sTime = interpolationD[0].x;//20组的起始时间	
				for (int k = 0; k < countAfterInp; k++)
				{
					double tempTime = sTime + (k*timePerPoint);//当前点的时间（未插值前）
					DataPoint interpPoint;
					interpPoint.value = lagrange(tempTime, foreachL);
					interpPoints.push_back(interpPoint);
				}
			}
			//将插值后的点添加到列表中
			for (int j = 0; j < interpPoints.size(); j++)
			{
				interpPoints[j].time = (dataPoints.size() + 1)*timePerPoint;//当前点的时间
				dataPoints.push_back(interpPoints[j]);//添加到主列表中
			}
		}
		else
		{
			//直接添加到datapoint中
			int count = mComtradeCfg.cmtrSamprate[i].endSamp - lastPointIndex;
			int realSize = mDataRows.size();
			for (int j = 0; j < count; j++)
			{
				if ((lastPointIndex + j) < realSize)
				{
					DataPoint point;
					int regionData = mDataRows[lastPointIndex + j].analogValues[chanNo - 1];//获取原始值
					point.value = (mComtradeCfg.cmtrAnalogCfg[chanNo - 1].a)*regionData + (mComtradeCfg.cmtrAnalogCfg[chanNo - 1].b);//计算原始值aX+b
					point.time = (dataPoints.size() + 1)*timePerPoint;//当前点的时间
					dataPoints.push_back(point);
					//printf("i==%d", j);
				}
			}
			//printf("DEBUG");
		}
		lastPointIndex = mComtradeCfg.cmtrSamprate[i].endSamp;
#pragma endregion
	}

	if (startTime <= 0)
	{
		startTime = 0;
	}
	if (endTime >= get_end_samp_time())
	{
		endTime = get_end_samp_time();
	}

	double max = 0, min = 0;
	for (int i = 0; i < dataPoints.size(); i++)
	{
		DataPoint dp = dataPoints[i];
		if (max < dp.value)
		{
			max = dp.value;
		}
		if (min > dp.value)
		{
			min = dp.value;
		}
	}


	int index = 0;
	for (int i = 0; i < dataPoints.size(); i++)
	{
		if (len >= (i + 1))
		{
			DataPoint dp = dataPoints[i];
			if (startTime <= dp.time)
			{
				if (endTime >= dp.time)
				{
					*(analogValue + index) = dp.value; index++;
				}
				else
				{
					break;
				}
			}
		}
		else
		{
			break;
		}
	}
	double max2 = 0, min2 = 0;
	for (int i = 0; i < index; i++)
	{
		double v = *(analogValue + i);
		if (max < v)
		{
			max2 = v;
		}
		if (min > v)
		{
			min2 = v;
		}
	}


	return index;
}
/// <summary>
/// 销毁相关的数据资源
/// </summary>
void destory_comtrade()
{
	//清空所有的原始DAT行数据
	mDataRows.clear();
}
