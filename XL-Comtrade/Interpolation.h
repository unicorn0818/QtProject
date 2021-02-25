//stdafx.h
#include<stdio.h> 
#include<stdlib.h> 
#include<iostream> 

using namespace std;

typedef struct data
{
	double x;
	double y;
}Data;//变量x和函数值y的结构 

Data interpolationD[20];//最多二十组数据 

double f(int s, int t)//牛顿插值法，用以返回插商 
{
	if (t == s + 1)
		return (interpolationD[t].y - interpolationD[s].y) / (interpolationD[t].x - interpolationD[s].x);
	else
		return (f(s + 1, t) - f(s, t - 1)) / (interpolationD[t].x - interpolationD[s].x);
}

double Newton(double x, int count)
{
	int n;
	while (1)
	{
		cout << "请输入n值(即n次插值):";//获得插值次数 
		cin >> n;
		if (n <= count - 1)// 插值次数不得大于count－1次 
			break;
		else
			system("cls");
	}
	//初始化t，y，yt。 
	double t = 1.0;
	double y = interpolationD[0].y;
	double yt = 0.0;
	//计算y值 
	for (int j = 1; j <= n; j++)
	{
		t = (x - interpolationD[j - 1].x)*t;
		yt = f(0, j)*t;
		cout << f(0, j) << endl;
		y = y + yt;
	}
	return y;
}
double lagrange(double x, int count)
{
	double y = 0.0;
	for (int k = 0; k < count; k++)//这儿默认为count－1次插值
	{
		double p = 1.0;//初始化p
		for (int j = 0; j < count; j++)
		{//计算p的值
			if (k == j)
				continue;//判断是否为同一个数
			p = p*(x - interpolationD[j].x) / (interpolationD[k].x - interpolationD[j].x);
		}
		y = y + p*interpolationD[k].y;//求和
	}
	return y;//返回y的值
}
//void main()
//{
//	double x, y;
//	int count;
//	while (1)
//	{
//		cout << "请输入x[i],y[i]的组数，不得超过20组:";//要求用户输入数据组数 
//		cin >> count;
//		if (count <= 20)
//			break;//检查输入的是否合法 
//		system("cls");
//	}
//	//获得各组数据 
//	for (int i = 0; i < count; i++)
//	{
//		cout << "请输入第" << i + 1 << "组x的值:";
//		cin >> d[i].x;
//		cout << "请输入第" << i + 1 << "组y的值:";
//		cin >> d[i].y;
//		system("cls");
//	}
//	cout << "请输入x的值:";//获得变量x的值 
//	cin >> x;
//	while (1)
//	{
//		//cout<<"拉格朗日插值计算方法，其结果为："; 
//		y = lagrange(x, count);
//		//y = Newton(x, count);
//		break;//调用相应的处理函数 
//	}
//	cout << y << endl;//输出最终结果   
//	getchar();
//}