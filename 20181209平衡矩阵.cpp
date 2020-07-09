/*
*程序名：平衡矩阵
*作者：何卓远
*编制时间：2018-12-09
*功能：现在有一个n阶正整数方阵（n<=7），现在可以对矩阵的任意一行进行左移，具体操作为：每次对于某一行a_i1,a_i2,…,a_in进行一次左移，最左边的元素移动到这一行的末尾，其他元素均向左移动一位，即变为a_i2,a_i3,…,a_in,a_i1。对某一行可以执行任意次的左移。 
现在我们的目标是：通过对矩阵的每一行进行若干次左移，使得矩阵中每列和的最大值最小。
*/

#include <iostream>
#include <cstring>
using namespace std;
int a[8][8] = { 0 }, b[8][8] = { 0 };     //a是原始矩阵，b是调整矩阵
int n;
int Min=999999;
void adjust(int k)
{
	if (k == n)
	{
		int s[8] = { 0 }, max = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				s[i] += b[j][i];
			}
			if (max < s[i]) max = s[i];
		}
		if (max < Min) Min = max;
		return;
	}        //计算并且判断最大值的最小值
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			b[k][j] = a[k][(j + i) % n];
		}        //实现右移i位
		adjust(k + 1);     //下一行
	}
}
int main()
{
	while(1)
	{
		cin >> n;
		if (n == -1) return 0;
		else
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					cin >> a[i][j];
				}
			}
		}
		if (n == 1)
		{
			cout << a[0][0] << endl;
			continue;
		}
		Min = 999999;
		adjust(0);     //从头调整
		cout << Min << endl;      //输出
	}
	return 0;
}