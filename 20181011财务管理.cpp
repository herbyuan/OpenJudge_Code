/*
*程序名：财务管理
*作者：何卓远
*编制时间：2018-10-11
*功能：帮助阿华计算出平均帐户余额
*/
#include <iostream>
#include<cmath>
#include<iomanip>//预处理指令

using namespace std;

int main()
{
	float sum, a, average;
	int i;
	sum = 0;
	for(i=1;i<=12;i++)      //十二次求和，没什么好说的
	{
		cin >> a;
		sum = sum + a;
	}
	average = sum / 12;     //总和除以十二
	cout << "$";
		cout<< fixed << setprecision(2) << average << endl;
	return 0;    //程序结束
}

