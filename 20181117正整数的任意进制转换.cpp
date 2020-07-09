/*
*程序名：正整数的任意进制转换
*作者：何卓远
*编制时间：2018-11-17
*功能：将 p 进制 n 转换为 q 进制。p 和 q 的取值范围为【2，36】，
其中，用到的数码按从小到大依次为：0，1，2，3，4，5，6，7，8，9，A，B，...，Z，不考虑小写字母。
注意：n 的长度不超过50位。
三个数之间用逗号间隔。
*/

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
char x[10000];
int y[10000], z[10000];
int a, b, c, e, d, n;
int chu()  //除法
{
	int yu1 = 0, yu2 = 0;
	for (int i = 0; i < c; i++) {
		yu1 = (y[i] + yu2 * a) % b;
		y[i] = (y[i] + yu2 * a) / b;
		yu2 = yu1;
	}
	return yu1;
}
int main()
{
	cin >> n;
	while (n) {
		n--;
		memset(x, 0, sizeof(x));
		memset(y, 0, sizeof(y));
		memset(z, 0, sizeof(z));
		cin >> a;
		getchar();//p进制
		for (int i = 0;; i++) {
			cin >> x[i];
			if (x[i] == ',')
			{
				x[i] = 0; break;
			}
			if (x[i] >= '0' && x[i] <= '9')//转换成int存入y
				y[i] = x[i] - '0';
			else
				y[i] = x[i] - 'A' + 10;
		}
		cin >> b;//q进制
		c = strlen(x);
		for (e = 0, d = 1;; e++, d = 1) {
			z[e] = chu();
			for (int i = 0; i < c; i++) {//y全为0终止
				if (y[i] != 0)
				{
					d = 0; break;
				}
			}
			if (d == 1)
				break;
		}
		while (e >= 0) {//逆序输出
			if (z[e] >= 0 && z[e] <= 9)
				cout << z[e];
			else
				cout << char(z[e] - 10 + 'A');
			e--;
		}
		cout << endl;
	}
	return 0;
}