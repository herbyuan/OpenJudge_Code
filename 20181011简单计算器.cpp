/*
*程序名：简单计算器
*作者：何卓远
*编制时间：2018-10-11
*功能：简单计算器

*/
#include <iostream>
#include<cmath>          //预处理指令

using namespace std;

int main()
{
	int a, b;
	char x;       //变量声明
	a = 0;
	b = 0;
	cin >> a >> b;
	cin >> x;
	if ((x != '+') && (x != '-') && (x != '*') && (x != '/')) cout << "Invalid operator!" << endl;
	else if ((b == 0)&&(x == '/')) cout << "Divided by zero!" << endl;                 //判断是否可进行运算
	else 
	{
		switch (x)
		{
		case '+':cout << a + b << endl; break;
		case '-':cout << a - b << endl; break;
		case '*':cout << a * b << endl; break;
		case '/':cout << a / b << endl; break;
		}                                                    //进行计算并输出结果
	}
	return 0;    //程序结束
}

