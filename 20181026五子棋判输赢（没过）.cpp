/*
*程序名：五子棋
*作者：何卓远
*编制时间：2018-10-26
*功能：在一个N×N的棋盘上下五子棋，给定一个五子棋黑白棋的落子序列 (x0,y0),(x1,y1), ..., （xn,yn），判断走到多少步时，哪方获胜。
*/
#include <iostream>       //预处理指令

using namespace std;

int main()
{
	int N, n;
	int x, y, i, j, k;

	cin >> N >> n;
	int a[30][30] = { 0 }, b[30][30] = { 0 };     //一开始棋盘上没有棋子
	
	for (i = 0; i < n; i++)
	{
		cin >> x >> y;
		if (i % 2 == 0)     //黑下
		{
			a[x][y] = 1;    
			for (j = 0; j <= N - 4; j++)
			{
				for (k = 0; k <= N - 4; k++)    //对于每一个可能的点判断
				{
					if ((a[j][k] * a[j][k + 1] * a[j][k + 2] * a[j][k + 3] * a[j][k + 4] == 1) || (a[j][k] * a[j + 1][k] * a[j + 2][k] * a[j + 3][k] * a[j + 4][k] == 1) || (a[j][k] * a[j + 1][k + 1] * a[j + 2][k + 2] * a[j + 3][k + 3] * a[j + 4][k + 4] == 1))
					{
						cout << i + 1 << " 0" << endl;
						return 0;
				    }
				}
				for (k=4;k<=N-4;k++)
				{
					if (a[j][k] * a[j + 1][k - 1] * a[j + 2][k - 2] * a[j + 3][k - 3] * a[j + 4][k - 4] == 1)
					{
						cout << i + 1 << " 0" << endl;
						return 0;
					}
				}
			}
		}
		else       //白下
		{
			b[x][y] = 1;
			for (j = 0; j <= N - 4; j++)
			{
				for (k = 0; k <= N - 4; k++)
				{
					if ((b[j][k] * b[j][k + 1] * b[j][k + 2] * b[j][k + 3] * b[j][k + 4] == 1) || (b[j][k] * b[j + 1][k] * b[j + 2][k] * b[j + 3][k] * b[j + 4][k] == 1) || (b[j][k] * b[j + 1][k + 1] * b[j + 2][k + 2] * b[j + 3][k + 3] * b[j + 4][k + 4] == 1))
					{
						cout << i + 1 << " 1" << endl;
						return 0;
					}
				}
				for (k = 4; k <= N - 4; k++)
				{
					if (b[j][k] * b[j + 1][k - 1] * b[j + 2][k - 2] * b[j + 3][k - 3] * b[j + 4][k - 4] == 1)
					{
						cout << i + 1 << " 1" << endl;
						return 0;
					}
				}
			}
		}
	}

	return 0;    //程序结束
}