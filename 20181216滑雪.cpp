/*
*程序名：滑雪
*作者：何卓远
*编制时间：2018-12-15
*功能：寻找一个矩阵中最长的下降路径长度
*/
#include <iostream>
#include <algorithm>
using namespace std;
struct Point
{
	int r, c;
	int h;
	bool operator<(const Point & p) const
	{
		return h < p.h;
	}
}points[250500];       //一维数据存储所有的点
int field[503][503];
int L[503][503];     //从（i，j）出发最大滑行距离
int R, C;
int main()
{
	cin >> R >> C;
	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			cin >> field[i][j];
			points[i*C + j].h = field[i][j];
			points[i*C + j].r = i;
			points[i*C + j].c = j;
			L[i][j] = 1;
		}
	}
	sort(points, points + R * C);
	for (int i = 1; i < R*C; ++i)     //求points[i]的L,这之前的L已经求出了
	{
		int r = points[i].r;
		int c = points[i].c;
		if (r > 0 && field[r - 1][c] < field[r][c])
			L[r][c] = max(L[r][c], L[r - 1][c] + 1);
		if (c > 0 && field[r][c - 1] < field[r][c])
			L[r][c] = max(L[r][c], L[r][c - 1] + 1);
		if (r < R - 1 && field[r + 1][c] < field[r][c])
			L[r][c] = max(L[r][c], L[r + 1][c] + 1);
		if (c < C - 1 && field[r][c + 1] < field[r][c])
			L[r][c] = max(L[r][c], L[r][c + 1] + 1);
	}
	int maxLen = 0;
	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			maxLen = max(maxLen, L[i][j]);
		}
	}
	cout << maxLen << endl;
	return 0;
}