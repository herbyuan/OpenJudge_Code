/*
*程序名： 大整数加法
*作者：何卓远
*编制时间：2018-11-16
*功能：第一行输入测试数据的数目 n 
接下来 n 行，每行输入两个非负整数a和b，它们的位数<=200
输出数据有 n 行，每行输出一个非负整数，即对应数据 a+b 的值，不允许有前导的“0”
用字符串输入数据，并模拟人工竖式计算
*/

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	int sign = 0, n, l[3] = {0}, b[3][202] = {0}, c[203] = {0};
	int temp = 0;
	char a[3][202] = {0};
	cin >> n;
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < 2; i++)
		{
			cin >> a[i];
			l[i] = strlen(a[i]);
			for (int j = l[i] - 1; j >= 0; j--)
				{
					b[i][j] = int(a[i][l[i] - j - 1]-'0');
				}
		}      //从后往前读每一位存到b
		for (int i = 0; i < 202; i++)
		{
			for (int j = 0; j < 2; j++)
				{
					temp += b[j][i];
				}
			c[i] = temp % 10;
			temp = temp / 10;
		}       //模拟竖式计算每一位
		for (int i = 201; i >= 0; i--)
		{
			if (c[i] > 0) 
				{
					sign = i;
					break;
				}
		}    //找到开始的非零位数
		for (int i = sign; i >= 0; i--)
			cout<<c[i];
		cout << endl;
		temp = 0;
		sign = 0;
		for (int i = 0; i < 3; i++)
		{
			l[i] = 0;
			for (int j = 0;j < 202; j++)
			{
				a[i][j] = 0;
				b[i][j] = 0;
				c[j] = 0;
			}
 		}          //清零
	}
	return 0;
}