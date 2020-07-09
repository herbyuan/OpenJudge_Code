/*
*程序名：滑雪
*作者：何卓远
*编制时间：2018-12-18
*功能：寻找一个矩阵中最长的下降路径长度
*/
#include <iostream>
#include <algorithm>
using namespace std;
int R, C, h[502][502] = { 0 }, l[502][502] = { 0 };      //h是每个点的高度，l用来记录每个点最大滑行长度
int func(int r, int c)       //找到四周比这个点低的最大解并+1
{
	if (l[r][c] != -1) return l[r][c];      //该点已经计算过
	int t = 0;
	if (h[r - 1][c] < h[r][c])
		t = max(t, func(r-1, c));
	if (h[r + 1][c] < h[r][c])
		t = max(t, func(r + 1, c));
	if (h[r][c - 1] < h[r][c])
		t = max(t, func(r, c - 1));
	if (h[r][c + 1] < h[r][c])
		t = max(t, func(r, c + 1));
	l[r][c] = t + 1;
	return l[r][c];
}

int main()
{
	int Max = 1, t;
	cin >> R >> C;
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			cin >> h[i][j];
			l[i][j] = -1;
		}
	}                        //读入每个点的高度
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
			{
				t = func(i,j);
				if (t > Max) Max = t;     //记录最优解
			}
	cout << Max << endl;
	return 0;
}
