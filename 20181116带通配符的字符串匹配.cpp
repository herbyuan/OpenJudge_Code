/*
*程序名：  带通配符的字符串匹配
*作者：何卓远
*编制时间：2018-11-16
*功能：通配符是一类键盘字符，当我们不知道真正字符或者不想键入完整名字时，常常使用通配符代替一个或多个真正字符。通配符有问号(?)和星号(*)等，其中，“?”可以代替一个字符，而“*”可以代替零个或多个字符。 

你的任务是，给出一个带有通配符的字符串和一个不带通配符的字符串，判断他们是否能够匹配。 

例如，1?456 可以匹配 12456、13456、1a456，但是却不能够匹配23456、1aa456； 
2*77?8可以匹配 24457798、237708、27798。
*/

#include <iostream>
#include <cstring>

using namespace std;

bool func(char a[], char b[])
{
	int x, y;
	x = strlen(a);
	y = strlen(b);
	char c[20] = {0}, d[20] = {0};
	if (x == 0 && y == 0) return 1;
	if (a[0] == '?' || a[0] == b[0]) 
	{
		if (x == 1 && y == 1) return 1;   //最后一个也相同 match
		for (int i = 0; i < x - 1; i++)
			c[i] = a[i + 1];
		for (int i = 0; i < y - 1; i++)
			d[i] = b[i + 1];
		return func(c,d);
	}        //此种情况直接判断下一个字符
	if (a[0] == '*')
	{
		for (int i = 0; i < x - 1; i++)
			c[i] = a[i + 1];
		
		for (int j = 0; j <= y - x + 1; j++)
		{
			for (int i = 0; i < 20; i++)
			{
				d[i] = 0;
			}
			for (int i = 0; i < y - j; i++)
				d[i] = b[i + j];
			
			if (func(c,d)) return 1;    //从该位置开始逐个跳过字符比较
		}
		
	} 
	return 0;  //不然就是unmatch

}
int main()
{
	char a[21] = {0}, b[21] = {0};
	cin >> a >> b;
	bool c;
	c = func(a,b);
	if (c) cout	<< "matched" << endl;
	else cout << "not matched" << endl;
	return 0;
}