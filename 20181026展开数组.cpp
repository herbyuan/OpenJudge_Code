/*
*程序名：展开数组
*作者：何卓远
*编制时间：2018-10-26
*功能：展开数组

*/
#include <iostream>
#include<cmath>          //预处理指令

using namespace std;

int main()
{
	int a[101][101] = { 0 };
	int row, col;
	int i, j, k, l, m;
	cin >> row >> col;
	for (i=0;i<row;i++)
	{
		for (j = 0;j<col;j++)
		{
			cin >> a[i][j];
		}
	}
	
	if (col >= row)
	{
		for (i = 0; i < row; i++)
		{ 
			for (j = 0; j <= i; j++)
				cout << a[j][i-j] << endl;
		}
		for (i=1;i<=col-row;i++)
		{
			for (j = 0;j< row;j++)
			{
				cout << a[j][i + row - 1 - j]<<endl;
			}
		}
		for (i=1;i<row;i++)
		{
			for (j = 1; j <= row - i; j++)
			{
				cout << a[i+j-1][col-j] << endl;
			}
		}
	}
	else
	{
		for (i = 0; i < col; i++)
		{
			for (j = 0; j <= i; j++)
				cout << a[j][i - j] << endl;
		}
		for (i = 1; i <= row - col; i++)
		{
			for (j = 0; j < col; j++)
				cout << a[i + j][col - j -1]<<endl;
		}
		for (i = 1; i < col; i++)
		{
			for (j = 0; j < col - i; j++)
				cout << a[row-col+i + j][col - 1 - j]<<endl;
		}
	}
	return 0;    //程序结束
}

