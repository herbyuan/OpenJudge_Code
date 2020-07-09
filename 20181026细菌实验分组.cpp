/*
*程序名： 细菌实验分组
*作者：何卓远
*编制时间：2018-20-26
*功能： 细菌实验分组
*/

#include <iostream>
#include<cmath>          //预处理指令

using namespace std;

int main()
{
	int n, i, i0, j;
	float t, k[102] = { 0 }, before[102] = { 0 }, after[102] = { 0 }, f[102] = { 0 };
	float max;
	cin >> n;
	for (i=1;i<=n;i++)
	{
		cin >> k[i] >> before[i] >> after[i];
		f[i] = (after[i] - before[i]) / before[i];
	}
	
	for (i = 1;i < n;i++)
	{
		for (j = 1;j <= n-i;j++)
		{
			if (f[j] < f[j+1])
			{
				t = k[j];
				k[j] = k[j + 1];
				k[j + 1] = t;
				t = f[j];
				f[j] = f[j + 1];
				f[j + 1] = t;

			}
		}
	}
	max = 0;
	for (i=1;i<n;i++)
	{
		if (f[i] - f[i + 1] > max) 
		{
			max = f[i] - f[i + 1]; 
			i0 = i;
		}
	}
	cout << i0 << endl;
	for (i = 1; i <= i0; i++)
		cout << k[i0+1-i] << endl;
	cout << n - i0 << endl;
	for (i = 0; i < n-i0; i++)
		cout << k[n - i] << endl;
	return 0;    //程序结束
}