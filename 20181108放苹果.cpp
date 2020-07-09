/*
*程序名：放苹果
*作者：何卓远
*编制时间：2018-11-08
*功能：把M个同样的苹果放在N个同样的盘子里，允许有的盘子空着不放，问共有多少种不同的分法？
*/

#include <iostream> 
#include <cmath>//预处理指令

using namespace std;
int min(int a, int b)
{
	if (a < b) return a;
	else return b;
}
int f(int x, int y,int z)    //x是当前可用的苹果，y是盘子，z是最大的盘子中苹果数限制
{
	int s = 0;
	if (y * z < x) return 0;    //不可能
	if (x == 0) return 1;       //不放苹果
	if (y == 1) return 1;        //只有一个盘子
	else { 
		for (int i = ceil(x/y); i <= min(x,z); i++)
			s += f(x-i, y-1, i);    //最后一个盘子放ceil(x/y)到min(x,z)，利用之前数据求和
		return s;
	}
}
int main()
{
	int t, m, n, i, K;
	cin >> t;
	for (i = 1; i <= t; i++)
	{
		cin >> m >> n;
		K = f(m, n, m);
		cout << K << endl;
	}
	return 0; //程序结束
}