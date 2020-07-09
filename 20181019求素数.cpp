/*
*程序名：求素数
*作者：何卓远
*编制时间：2018-10-19
*功能：输出小于等于n的素数的个数。

*/
#include <iostream>
#include <cmath>      //预处理指令

using namespace std;

int main()
{
	int a, n, i, j, num, x;
	num = 0;
	bool prime;
	cin >> n;
	for (i=1;i<=n/2;i++)
	{
		a = 2 * i + 1;          //只考虑奇数
		if (a > n) continue;
		prime = true;
		for (j=1;j<=(sqrt(a)-1)/2;j++)     //只考虑可能的因数
		{
			x = 2 * j + 1;
			if (a % x == 0) 
			{
				prime = false;
			}
			if (prime == false) break;    //不符合条件立刻跳出
		}
		if (prime == true) num++;
	}
	cout << num+1 << endl;    //加上2是素数输出
	return 0;    //程序结束
}

