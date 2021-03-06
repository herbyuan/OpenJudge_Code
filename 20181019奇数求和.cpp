/*
*程序名：奇数求和
*作者：何卓远
*编制时间：2018-10-19
*功能：计算非负整数 m 到 n（包括m 和 n ）之间的所有奇数的和

*/
#include <iostream>
#include<cmath>          //预处理指令

using namespace std;

int main()
{
	int m, n, i ;
	int sum;
	cin >> m >> n;
	if (m % 2 == 0) m++;      //得到起始数
	if (n % 2 == 0) n--;      //得到终止数
	sum = 0;
	for (i = m; i <= n; i = i + 2)
		sum += i;
	cout << sum;     //输出
	return 0;    //程序结束
}

