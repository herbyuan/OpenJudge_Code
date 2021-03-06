/*
*程序名：输出不重复的数字
*作者：何卓远
*编制时间：2018-10-19
*功能：输出不重复的数字

*/
#include <iostream>          //预处理指令

using namespace std;

int main()
{
	int n, i, j, x;
	cin >> n;          //读入n
	int a[20001];
	bool c;
	cin >> x;
	a[1] = x;       //读入第一个数
	for (i=2;i<=n;i++)
	{
		c = true;
		cin >> x;
		for (j=1;j<=i-1;j++)
		{
			if (a[j] == x) c = 0;
		}
		if (c == 1)  a[i] = x;      //如果都不重复，放入a[i]
		else 
		{
			n--; i--;
		}	                       //不然重新考虑第i位
	}
	cout << a[1];
	for (i = 2; i <= n; i++)
		cout << " " << a[i];       //输出
	return 0;    //程序结束
}

