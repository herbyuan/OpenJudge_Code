/*
*程序名：跳马问题
*作者：何卓远
*编制时间：2018-11-23
*功能：在半张中国象棋的棋盘上，一匹马从左下角跳到右上角，只允许往右跳，不允许往左跳，求出有多少方案
*/

#include<iostream>
using namespace std;
const int Target_X = 8;
const int Target_Y = 4;
const int MaxStep = 9;
int num;
int path[MaxStep + 1][2];
int dx[] = { 0,1,2,2,1 };
int dy[] = { 0,2,1,-1,-2 };
int mk{ MaxStep };
void jump(int x, int y, int step)
{
	int k, i, x1, y1;
	bool t1, t2, t3, t4;
	for (k = 1; k <= 4; k++)
	{
		x1 = x + dx[k];
		y1 = y + dy[k];
		t1 = (x1 >= 0) && (x1 <= Target_X);    //x的合法范围
		t2 = (y1 >= 0) && (y1 <= Target_Y);    //y的合法范围
		t3 = (x1 == Target_X) && (y1 != Target_Y);     //没到目标
		t4 = (x1 == Target_X) && (y1 == Target_Y);     //到达目标
		if (t1 && t2 && !t3)
		{
			path[step][0] = x1;
			path[step][1] = y1;
			if (t4)
			{
				num++;
				cout << "Solution" << num << ": ";
				for (i = 0; i <= step; i++)
					cout << "(" << path[i][0] << "," << path[i][1] << ")";
				cout << endl;
			}
			else
			{
				jump(x1, y1, ++step);
			}
		}
	}
}
int main()
{
	jump(0, 0, 0);
}