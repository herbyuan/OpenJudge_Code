/*
*程序名：整数的个数
*作者：何卓远
*编制时间：2018-
*功能：计算整数的个数

*/
#include <iostream>
#include<cmath>           //预处理指令

using namespace std;

int main()
{
	int n, i, x, a, b, c; //变量声明
	cin >> n;            //读入整数个数
	a = 0;
	b = 0;
	c = 0;
	for (i = 1; i <= n; i++)      // 开始循环
	{
		cin >> x;                 //读入一个数
		switch(x)
		{
		case 1: a++; break;
		case 5: b++; break;
		case 10:c++; break;
		}                           //进行判断
		
	}
	cout << a << endl << endl;
	cout << b << endl << endl;
	cout << c << endl;     //输出结果
	return 0;    //程序结束
}

