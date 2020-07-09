/*
*程序名：数制转换
*作者：何卓远
*编制时间：2018-10-30
*功能：求任意两个不同进制非负整数的转换（2进制～36进制），所给整数在long所能表达的范围之内。 
不同进制的表示符号为（0，1，...，9，a，b，...，z）或者（0，1，...，9，A，B，...，Z）。
*/

#include <iostream>
#include <cstring>
#include <cmath> //预处理指令

using namespace std;

int main()
{
	int i, j, l, t;
	long long x = 0;
	double a;
	int b;
	char n[100] = { 0 }, ans[100] = { 0 };
	int m[100] = { 0 };
	cin >> a;
	cin >> n;
	cin >> b;
	l = strlen(n);
	for (i = l - 1; i >= 0; i--)
	{
		if ((n[i] >= 30) && (n[i] <= 57))
			t = int(n[i]) - 48;
		if ((n[i] >= 65) && (n[i] <= 90))
			t = int(n[i]) - 55;
		if ((n[i] >= 97) && (n[i] <= 122))
			t = int(n[i]) - 87;
		x = x + t * long(pow(a, l - i - 1));
	}         //得到十进制结果x


	i = 0;
	if (x == 0)
	{
		cout << "0";
		return 0;
	}
	else
	{
		while (x > 0)
		{
			m[i] = x % b;
			x = (x - m[i]) / b;
			i = i + 1;
		}             //算出每一位以及总的位数

		for (j = i - 1; j >= 0; j--)
		{
			if ((m[j] >= 0) && (m[j] <= 9))
				cout << m[j];
			if ((m[j] >= 10) && (m[j] <= 35))
				cout << char(m[j] + 55);
		}           //转换格式输出
	}


	return 0;    //程序结束
}



