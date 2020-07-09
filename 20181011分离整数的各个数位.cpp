/*
*程序名：分离整数的各个数位
*作者：何卓远
*编制时间：2018-10-11
*功能：分离一个三位数的各个数位

*/
#include <iostream>
#include<cmath> //预处理指令

using namespace std;

int main()
{
	int x, a, b, c;
	cin >> x;             //读入三位数
	a = x / 100;            //取百位
	b = (x - 100 * a) / 10;  //取十位
	c = x - 100 * a - 10 * b;  //取个位
	cout << a << endl << endl ;
	cout << b << endl << endl ;
	cout << c << endl;     //输出
	return 0;    //程序结束
}

