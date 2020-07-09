/*
作者：何卓远
时间：2018-11-12
名称：约瑟夫问题
描述：约瑟夫问题：有ｎ只猴子，按顺时针方向围成一圈选大王（编号从１到ｎ），
从第１号开始报数，一直数到ｍ，数到ｍ的猴子退出圈外，剩下的猴子再接着从1开始报数。
就这样，直到圈内只剩下一只猴子时，这个猴子就是猴王，编程求输入ｎ，ｍ后，输出最后猴王的编号。
*/

#include <iostream>

using namespace std;

int ysf(int m, int i)
{
	int x;
	if (i == 1 || i == 0) return 1;
	x = ysf(m, i - 1) + (m % i);
	if (x > i) x = x - i;
	return x;
}

int main()
{
	int m, n, a;
	while (1)
	{
		cin >> n >> m;
 		if (n == 0) return 0;
		a = ysf(m, n-1);
		if (a + (m%n) <= n) cout << a + (m%n) << endl;
		else cout << a + (m%n) - n << endl;
	}
	return 0;
}