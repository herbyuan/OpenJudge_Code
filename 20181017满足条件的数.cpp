/*
*程序名：满足条件的数
*作者：何卓远
*编制时间：2018-10-17
*功能：输出大于l小于h的数的个数。

*/
#include <iostream>         //预处理指令

using namespace std;

int main()
{
	int m, l, h, i, n, a;
	cin >> m >> l >> h;
	a = 0;   //计数器归零
	for( i = 1;i <= m; i++)  //循环读入
	{
		cin >> n;
		if ((l <= n) && (n <= h)) a++;
	}
	cout << a;    //输出
	return 0;    //程序结束
}

