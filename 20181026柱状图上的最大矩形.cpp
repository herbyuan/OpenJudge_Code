/*
*程序名：柱状图上的最大矩形
*作者：何卓远
*编制时间：2018-10-26
*功能：计算柱状图上的最大矩形

*/
#include <iostream>
#include<cmath>          //预处理指令

using namespace std;

int main()
{
	int n, i, j, s, x, y, a[20001] = { 0 }, max=0;
	cin >> n;
	for (i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for (i=1;i<=n;i++)
	{
		x = y = 0;
	    for (j=i;j>0;j--)
	    {
		    if (a[j] >= a[i]) x = i - j;
		    else break;
	    }
		for (j=i;j<=n;j++)
		{
			if (a[j] >= a[i]) y = j - i;
			else break;

		}
		s = a[i] * (1 + x + y);
		if (s > max) max = s;
	}
	cout << max;
	return 0;    //程序结束
}

