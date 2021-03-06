/*
*程序名：计算书费
*作者：何卓远
*编制时间：2018-10-19
*功能：给定每种图书购买的数量，编程计算应付的总费用。

*/
#include <iostream>
#include<cmath>          //预处理指令

using namespace std;

int main()
{
	int k;
	int i, j, x;
	float a[11], b[11] = { 0,28.9,32.7,45.6,78,35,86.2,27.8,43,56,65 };       //数组a为本数 b为价格
	float sum = 0;
	cin >> k;
	for (i = 1; i <= k; i++)
	{
		for (j = 1; j <= 10; j++)
		{
			cin >> x;
			a[j] = x;
			sum = sum + a[j] * b[j];      //求和
		}
		printf("%.2f\n", sum);      //控制精度输出
		sum = 0;
	}
	
	return 0;    //程序结束
}

