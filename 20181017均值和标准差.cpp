/*
*程序名：均值和标准差
*作者：何卓远
*编制时间：2018-10-17
*功能：给出一组样本数据，计算其均值和标准差

*/
#include <iostream>
#include<cmath>
#include<iomanip>//预处理指令

using namespace std;

int main()
{
	int n, i;
	cin >> n;
	float x, a[101], sum, ave, bzc;
	sum = 0;
	for (i = 1; i <= n; i++)
	{
		cin >> x;
		sum = sum + x;
		a[i] = x;
	}          //先求总和，并将数放入数组
	ave = sum / n;    //求平均值
	sum = 0;
	for (i = 1; i <= n; i++)
	{
		sum = sum + pow((a[i] - ave), 2);
	}
	bzc = sqrt(sum / n);    //计算标准差
	cout << fixed << setprecision(4) << ave << bzc << endl;//输出
	return 0;    //程序结束
}

