/*
*程序名：ASCII输出
*作者：何卓远
*编制时间：2018-
*功能：ASCII输出偶数

*/
#include <iostream>
#include<cmath>         //预处理指令

using namespace std;

int main()
{ 
	int i, a;
	char x;     //变量声明
	a = 0;
	while ((x = getchar()) != '\n')     //逐个读入字符串
	{
		i = 1;
		i = x;                 //得到ASCII码
		if (i % 2==0)      //判断奇偶性
		{
			if (a != 0) { cout << ","; }
				cout << i;
			a = a + 1;           //检验是否有输出
		}
	}
	if (a == 0) { cout << "NO" << endl; }   //输出
	return 0;    //程序结束
 }

