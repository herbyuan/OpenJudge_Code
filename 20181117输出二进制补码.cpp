/*
*程序名：输出二进制补码
*作者：何卓远
*编制时间：2018-11-17
*功能：输入若干int型整数，输出每个整数的二进制补码。
最后一行仅包含一个不定的字母，标志着输入结束。
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int n, i;
	bool a[32] = { 0 }, b;
	while (cin >> n)
	{
		i = 0;
		if (n >= 0) b = 0;   //判断正负
		else
		{
			b = 1;
			n = -n -1;    //化负为正
		}
		do
		{
			a[i] = n % 2;
			n /= 2;
			i++;
		} while (n != 0);   //转换为二进制
		cout << b;    //输出符号位
		if (b)
			for (i = 30; i >= 0; i--)
				cout << (!a[i]);
		else for (i = 30; i >= 0; i--)
			cout << a[i];
		cout << endl;
		for (i = 31; i >= 0; i--)
			a[i] = 0;
	}

	return 0;
}