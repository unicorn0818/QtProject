//#ifndef LAGRANGE_H
//#define LAGRANGE_H
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <vector>
//
//using namespace std;
//
////存放插值节点
//typedef struct Data{
//	double x;
//	double y;
//	struct Data *next;
//} LagrangeData;
//
///// <summary>
///// 拉格朗日插值
///// </summary>
///// <param name="header">插值前原始数据</param>
///// <param name="x">插值点的数据</param>
///// <returns>获取插值后的结果</returns>
//double LagrangeInsert(struct Data *header, double x)
//{
//	Data *pi, *pj, *p;
//	pi = pj = header->next;
//	double temp1, temp2;
//	temp1 = 0;                //记录内循环的积
//	temp2 = 1;				//记录外循环的和
//	while (pi != NULL)
//	{
//		while (pj != NULL)
//		{
//			if (pi != pj)
//				temp2 *= (x - pj->x) / (pi->x - pj->x);
//			pj = pj->next;
//		}
//		temp1 += temp2*pi->y;
//		temp2 = 1;
//		pj = header->next;
//		pi = pi->next;
//	}
//	return temp1;   //返回计算结果
//}
//
//   
//double LagrangeInsertEx(vector<DataPoint> datas, double x)
//{
//	int n = datas.size();
//	double tmp, lagrange = 0;
//	//利用拉格朗日插值公式计算函数x值的对应f(x)
//	for (int i = 0; i < n; i++)
//	{
//		tmp = 1;
//		for (int j = 0; j < n; j++)
//		{
//			if (j == i)   //去掉xi与xj相等的情况
//				continue;  //范德蒙行列式下标就是j!=k,相等分母为０就没意义了
//			tmp = tmp*(x - datas[j].time) / (datas[i].time - datas[j].time);//这个就是套公式，没什么难度
//			//tmp是拉格朗日基函数
//		}
//		lagrange = lagrange + tmp*datas[i].value; //最后计算基函数*y,全部加起来，就是该x项的拉格朗日函数了
//	}
//	return lagrange;	
//}
//
//double LagrangeInsertEx3(vector<DataPoint> datas, double x)
//{
//	int N = 20;
//	double result = 0;
//	for (int i = 0; i<N; i++){
//		double temp = datas[i].value;
//		for (int j = 0; j<N; j++){
//			if (i != j){
//				temp = temp*(x - datas[j].time);
//				temp = temp / (datas[i].time - datas[j].time);
//			}
//		}
//		result += temp;
//	}
//	return result;
//};
//
//
//
//double LagrangeInsertEx2(int N, vector<double>&X, vector<double>&Y, double x)
//{
//	double result = 0;
//	for (int i = 0; i<N; i++){
//		double temp = Y[i];
//		for (int j = 0; j<N; j++){
//			if (i != j){
//				temp = temp*(x - X[j]);
//				temp = temp / (X[i] - X[j]);
//			}
//		}
//		result += temp;
//	}
//	return result;
//};
//
//
//
//#endif LAGRANGE_H