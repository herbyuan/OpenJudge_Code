/*
*程序名：最匹配的矩阵
*作者：何卓远
*编制时间：2018-11-01
*功能：给定一个矩阵A[m,n](100 ≥ m ≥ 1,100 ≥ n ≥ 1) 和另一个矩阵B[r,s],有0 < r ≤ m, 0 < s ≤ n，A、B所有元素值都是小于100的正整数。求A中和B最匹配的矩阵C[r,s]，所谓最匹配是指B和C的对应元素差值的绝对值之和最小，如果有多个最佳匹配只需输出第一个（行号最小，行号相同时，列号最小）。

*/

#include <iostream>
#include <cmath>      //预处理指令

using namespace std;

int main()
{
	int m, n, r, s, S = 0, min = 999999;
	int i, k, j, l, a0, b0;
	int a[102][102] = { 0 }, b[102][102] = { 0 };
	cin >> m >> n;
	for (i = 1; i <= m; i++)
		for (j = 1; j <= n; j++)
			cin >> a[i][j];    //读入矩阵A
	cin >> r >> s;
	for (i = 1; i <= r; i++)
		for (j = 1; j <= s; j++)
			cin >> b[i][j];      //读入矩阵B
	for (i = 1; i <= m - r + 1; i++)
	{
		for (j = 1; j <= n - s + 1; j++)
		{
			S = 0;
			for (k = 1; k <= r; k++)
			{
				for (l = 1; l <= s; l++)
				{
					S = S + abs(b[k][l] - a[i + k - 1][j + l - 1]);
				}
			}
			if (S < min)
			{
				min = S;
				a0 = i;
				b0 = j;
			}
		}       //逐个匹配最小点
	}
	for (k = a0; k < a0 + r; k++)
	{
		for (l = b0; l < b0 + s; l++)
			cout << a[k][l] << " ";
		cout << endl;
	}     //输出矩阵

	return 0;
}
