/*
*程序名：数字消失
*作者：何卓远
*编制时间：2018-10-26
*功能：有一个包含n个整数的序列，序列中每个数都在[1, n]内，[1,n]中的数有些在这个序列中出现了1次或多次，而有些数没出现过。请输出[1, n]的整数中所有没出现过的整数。其中2 <= n <= 100.
*/
#include <iostream>
#include<cmath>          //预处理指令

using namespace std;

int main()
{
	int n, i, x;
	int a[101] = { 0 };
	cin >> n;
	for (i=1;i<=n;i++)
	{
		cin >> x;
		a[x]++;
	}
	for (i = 1; i <= n; i++)    //判断每一个数哪个没出现
	{
		if (a[i] == 0)
			cout << i<<endl;
	}
	return 0;    //程序结束
}

