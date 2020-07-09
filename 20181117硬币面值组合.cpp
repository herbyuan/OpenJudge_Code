/*
*程序名：硬币面值组合
*作者：何卓远
*编制时间：2018-11-17
*功能：使用1角、2角、5角硬币组成 n 角钱。 
设1角、2角、5角的硬币各用了a、b、c个，列出所有可能的a, b, c组合。 
输出顺序为，按c的值从小到大，c相同的按b的值从小到大输出。 
要求必须使用递归。
*/

#include <iostream>
#include <iomanip>

using namespace std;

int func2(int n, int b, int c, int i)
{
	int a;
	if (5 * c + 2 * b > n) return i;
	a = n - 5 * c - 2 * b;
	cout << setw(3) << setfill('0') << i << setw(12) << setfill(' ') << a << setw(12) << setfill(' ') << b << setw(12) << setfill(' ') << c << endl;
	b++;
	i++;
	return func2(n, b, c, i);
}
int func1(int n, int c, int i)
{
	if (5 * c <= n)
	{
		i = func2(n, 0, c, i);
		c++;
		func1(n, c, i);
	}
	else return 0;
}
int main()
{
	int n;
	cin >> n;
	func1(n, 0, 1);
	return 0;
}