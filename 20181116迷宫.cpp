/*
*程序名： 迷宫
*作者：何卓远
*编制时间：2018-11-16
*功能：在N*N的迷宫内，“#”为墙，“.”为路，“s”为起点，“e”为终点，一共4个方向可以走。从左上角（(0,0)“s”）位置处走到右下角（(n-1,n-1)“e”）位置处，可以走通则输出YES，不可以走则输出NO。
*/

#include <iostream>

using namespace std;

char a[17][17] = {0};
int b[17][17] = {0};
int func(int x, int y, int m) 
{
	if (x < 0 || x >= m || y < 0 || y >= m) return 0;
	if (a[x][y] == '#') return 0;
	if ((a[x][y] == '.' || a[x][y] == 's') && b[x][y] == 0)
	{
		b[x][y] = -1;
		func(x - 1, y, m);
		func(x + 1, y, m);
		func(x, y - 1, m);
		func(x, y + 1, m);
		return 0;     //判断周围情况并给自己标记为已经判断
	}
return 0;

}
int main()
{
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> m;
		for (int j = 0; j < m; j++)
			for (int k = 0; k < m; k++)
				cin >> a[j][k];    //读入迷宫
		func(0,0,m);
		
		if (b[m-2][m-1] == -1 || b[m-1][m-2] == -1)//出口周围可以达到出口也可以达到
			cout << "YES" << endl;
		else cout << "NO" << endl;
		for (int j = 0; j < 17; j++)
			for (int k = 0; k < 17; k++)
			{
				a[j][k] = 0;
				b[j][k] = 0;
			}    //清零

	}
	return 0;
}