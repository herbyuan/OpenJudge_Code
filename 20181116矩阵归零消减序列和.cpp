/*
*程序名：矩阵归零消减序列和
*作者：何卓远
*编制时间：2018-11-16
*功能：给定一个n*n的矩阵（3<=n<=100，元素的值都是非负整数）。通过n-1次实施下述过程，可把这个矩阵转换成一个1*1的矩阵。每次的过程如下： 
    首先对矩阵进行归零：即对每一行（或一列）上的所有元素，都在其原来值的基础上减去该行（或列）上的最小值，保证相减后的值仍然是非负整数，且这一行（或列）上至少有一个元素的值为0。 
    然后对矩阵进行消减：即把n*n矩阵的第二行和第二列删除（如果二维数组为a[][]，则删除的是a[1][1]所在的行和列），使之转换为一个(n-1)*(n-1)的矩阵。 
    下一次过程，对生成的(n-1)*(n-1)矩阵实施上述过程。显然，经过n-1次上述过程， n*n的矩阵会被转换为一个1*1的矩阵。 
    请求出每次消减前a[1][1]值之和。 
*/

#include <iostream>

using namespace std;

int func(int a[101][101], int k, int s)
{
	if (k == 1) 
		return s;
	int i, j, min;
	for (i = 0; i < k; i++)
	{
		min = a[i][0];
		for (j = 0; j < k; j++)
			if (a[i][j] < min) min = a[i][j];
		for (j = 0; j < k; j++)
			a[i][j] = a[i][j] - min;
	}
	for (i = 0; i < k; i++)
	{
		min = a[0][i];
		for (j = 0; j < k; j++)
			if (a[j][i] < min) min = a[j][i];
		for (j = 0; j < k; j++)
			a[j][i] = a[j][i] - min;
	}
	s += a[1][1];
	for (i = 1; i < k - 1; i++)
		for (j = 0; j < k; j++)
			a[i][j] = a[i + 1][j];
	for (j = 1; j < k - 1; j++)
		for (i = 0; i < k - 1; i++)
			a[i][j] = a[i][j + 1];
	k--;
	return func(a, k, s);
}

int main()
{
	int n, s;
	cin >> n;
	int a[101][101] = {0};
	for (int i = 0; i < n; i++)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> a[i][j];
		s = func(a, n, 0);
		cout << s << endl;
	}
	return 0;
}