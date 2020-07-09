

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
	int x, y, i, j, k, p;
	cin >> N >> n;
	int a[30][30] = { 0 }, b[30][30] = { 0 };
	
	for (i = 0;i < n;i++)
	{
		
		if (i % 2 == 0)
		{
			cin >> x >> y;
			a[x][y] = 1;
			for (j = 0; j <= 4; j++)
			{
				if ((x + j > N) || (y + j > N))continue;
				if ((x + j - 4 < 0) || (y + j - 4 < 0)) continue;
				k = 0;
				for (p = 0;p <= j;p++)
				{
					if (a[x + p][y + p] == 1) k++;
				}
				for (p = 0; p <= 4 - j; p++)
				{
					if (a[x - p][y - p] == 1) k++;
				}
				if (k == 6)    
				{
					cout << i + 1 << " 0";
					return 0;
				}
			}    //斜向判定（第一个人）
			k = 0;
			for (j = 0; j <= 4; j++)
			{
				if ((x + j > N) || (y - j < 0)) continue;
				if ((x + j - 4 < 0) || (y + 4 - j > N)) continue;
				k = 0;
				for (p=0;p<=j;p++)
				{
					if (a[x + p][y - p] == 1) k++;
				}
				for (p=0;p<=4-j;p++)
				{
					if (a[x - p][y + p] == 1) k++;
				}
				if (k == 6)
				{
					cout << i+1 << " 0";
				    return 0;
				}
			}           //斜向判定
			k = 0;
				for (j = 0; j <= 4; j++)
				{
					if (x + j > N) continue;
					if (x + j - 4 < 0) continue;
					k = 0;
					for (p = 0; p <= j; p++)
					{
						if (a[x + p][y] == 1) k++;

					}
					for (p = 0; p <= 4 - j; p++)
					{
						if (a[x - p][y] == 1) k++;
					}
					if (k == 6)
					{
						cout << i + 1 << " 0";
						return 0;
					}
			    }        //横向判定（第一个人）
			k = 0;
			for (j = 0; j <= 4; j++)
			{
				if (y + j > N) continue;
				if (y + j - 4 < 0) continue;
				k = 0;
				for (p = 0; p <= j; p++)
				{
					if (a[x][y + p] == 1) k++;
				}
				for (p = 0; p <= 4 - j; p++)
				{
					if (a[x][y - p] == 1) k++;
				}
				if (k == 6)
				{
					cout << i + 1 << " 0";
					return 0;
				}
			}
		}       //纵向判定（第一个人）
		else 
		{ 
			cin >> x >> y;
			b[x][y] = 1;
			for (j = 0; j <= 4; j++)
			{
				if ((x + j > N) || (y + j > N))continue;
				if ((x + j - 4 < 0) || (y + j - 4 < 0)) continue;
				k = 0;
				for (p = 0; p <= j; p++)
				{
					if (b[x + p][y + p] == 1) k++;
				}
				for (p = 0; p <= 4 - j; p++)
				{
					if (b[x - p][y - p] == 1) k++;
				}
				if (k == 6)   
				{
					cout << i + 1 << " 1";
					return 0;
				}
			}//斜向判定（2）
			k = 0;
			for (j = 0; j <= 4; j++)
			{
				if ((x + j > N) || (y - j < 0)) continue;
				if ((x + j - 4 < 0) || (y + 4 - j > N)) continue;
				k = 0;
				for (p = 0; p <= j; p++)
				{
					if (b[x + p][y - p] == 1) k++;
				}
				for (p = 0; p <= 4 - j; p++)
				{
					if (b[x - p][y + p] == 1) k++;
				}
				if (k == 6)
				{
					cout << i + 1 << " 1";
					return 0;
				}
			}       //斜向判定（2）
			k = 0;
			for (j = 0; j <= 4; j++)
			{
				if (x + j > N) continue;
				if (x + j - 4 < 0) continue;
				k = 0;
				for (p = 0; p <= j; p++)
				{
					if (b[x + p][y] == 1) k++;

				}
				for (p = 0; p <= 4 - j; p++)
				{
					if (b[x - p][y] == 1) k++;
				}
				if (k == 6)
				{
					cout << i + 1 << " 1";
					return 0;
				}
			}     //横向判定（2）
			k = 0;
			for (j = 0; j <= 4; j++)
			{
				if (y + j > N) continue;
				if (y + j - 4 < 0) continue;
				k = 0;
				for (p = 0; p <= j; p++)
				{
					if (b[x][y + p] == 1) k++;
				}
				for (p = 0; p <= 4 - j; p++)
				{
					if (b[x][y - p] == 1) k++;
				}
				if (k == 6)
				{
					cout << i + 1 << " 1";
					return 0;
				}   //纵向判定（第二个人）
			}
		}
	}
	return 0;    //程序结束
}

