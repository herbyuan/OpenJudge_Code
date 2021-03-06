/*
*程序名：菲波那契数列
*作者：何卓远
*编制时间：2018-10-11
*功能：给出一个正整数a，要求菲波那契数列中第a个数是多少。

*/
#include <iostream>
#include<cmath>        //预处理指令

using namespace std;

int main()
{
	int n, i, j , k , a[22];
	a[1] = a[2] = 1;         //给出前两个数
	for (j = 3;j <= 20; j++)
	{
		a[j] = a[j - 1] + a[j - 2];
	}                             //计算前20个斐波那契数
	cin >> n;                 //读入个数
	for (i = 1;i <= n; i++ )
	{
		cin >> k;            //读入第n个
		cout << a[k]<< endl;        //输出结果
	}
	return 0;    //程序结束
}

