/*
*程序名：迷信的吴医生和机智的护士
*作者：何卓远
*编制时间：2018-10-26
*功能：panduan小李能开给这n位病人的挂号单的序号总和最小是多少

*/
#include <iostream>
#include<cmath>          //预处理指令

using namespace std;

int main()
{
	int a[60] = { 0 };
	int i, n, sum = 0;
	cin >> n;
	a[1] = 1;
	for (i=1;i<=50;i++)
	{
		a[i + 1] = a[i] + 1;
		for (;;)
		{
			if ((a[i + 1] % 10 != 4) && (a[i + 1] / 10 != 4) && (a[i+1] % 4 != 0)) break;
			else a[i + 1]++;
		}
	}
	for (i=1;i<=n;i++)
	{
		
		sum = sum + a[i];
	}
	cout << sum;
	return 0;    //程序结束
}

