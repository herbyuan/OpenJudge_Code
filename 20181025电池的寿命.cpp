/*
*程序名：电池的寿命
*作者：何卓远
*编制时间：2018-10-25
*功能：计算电池的寿命

*/
#include <iostream>
#include<cmath>    
#include <iomanip>    //预处理指令

using namespace std;

int main()
{
	int n, i;
	float s, x[1001], max;
	while (cin >> n)
	{
		s = 0;
		max = 0;
		if (n==2)     //只有两节电池的时候
		{
			for (i = 1; i <= 2; i++)
			{
				cin >> x[i];
			}
			if (x[1] > x[2]) cout << fixed << setprecision(1) << x[2] << endl;
			else cout << fixed << setprecision(1) << x[1] << endl;
		}
		else  
		{
			for (i = 1; i <= n; i++)
			{
				cin >> x[i];
				s += x[i];
				if (max < x[i]) max = x[i];    //记录最大一节电量
			}
			if (2*max>s) cout << fixed << setprecision(1) << s - max << endl;    //如果大于总的一半，则s-max为时间
			else cout << fixed << setprecision(1) << s / 2 << endl;     //否则一定可以用完
		}
	
	}
	return 0;    //程序结束
}

