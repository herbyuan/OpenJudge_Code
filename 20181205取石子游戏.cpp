/*
*程序名：取石子游戏
*作者：何卓远
*编制时间：2018-12-05
*功能：有两堆石子,两个人轮流去取.每次取的时候,只能从较多的那堆石子里取,并且取的数目必须是较少的那堆石子数目的整数倍.
最后谁能够把一堆石子取空谁就算赢. 
*/
#include <iostream>
using namespace std;
bool stone(int x, int y);
bool stone1(int x, int y);
bool stone1(int x, int y)
{
	if (x < y)
	{
		int t = x;
		x = y;
		y = t;
	}
	if (x%y == 0) return 0;
	if (x / y >= 2) return 0;
	if (y % (x - y) == 0) return 1;
	return stone(x - y, y);
}
bool stone(int x, int y)
{
	if (x < y)
	{
		int t = x;
		x = y;
		y = t;
	}
	if (x%y == 0) return 1;
	if (x / y >= 2) return 1;
	if (y % (x - y) == 0) return 0;
	return stone1(x - y, y);
}
int main()
{
	int a, b;
	while (1)
	{
		cin >> a >> b;
		if (a == 0 && b == 0) break;
		if (stone(a, b)) cout << "win" << endl;
		else cout << "lose" << endl;
	}
	return 0;
}