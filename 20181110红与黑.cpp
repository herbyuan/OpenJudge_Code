/*
*程序名：红与黑
*作者：何卓远
*编制时间：2018-11-23
*功能：有一间长方形的房子，地上铺了红色、黑色两种颜色的正方形瓷砖。你站在其中一块黑色的瓷砖上，只能向相邻的四块瓷砖中的黑色瓷砖移动。请写一个程序，计算你总共能够到达多少块黑色的瓷砖。
*/

#include <iostream>
#include <cstring>
using namespace std;
char tiles[21][21];
int W, H;
int move(int x, int y)
{
	if (x < 0 || x >= H || y < 0 || y >= W) return 0;
	if (tiles[x][y] == '#') return 0;
	tiles[x][y] = '#';
	return 1 + move(x - 1, y) + move(x + 1, y) + move(x, y + 1) + move(x, y - 1);
}

int main(int argc, char const *argv[])
{
	int ans;
	while (1)
	{
		cin >> W >> H;
		if (W == 0 && H == 0) return 0;
		memset(tiles, 0, sizeof(tiles));
		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				cin >> tiles[i][j];
			}
		}
		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++)
				if (tiles[i][j] == '@')
					ans = move(i, j);
		cout << ans << endl;
	}
	return 0;
}