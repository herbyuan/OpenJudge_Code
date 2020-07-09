/*
*程序名：正整数的任意进制转换
*作者：何卓远
*编制时间：2018-11-23
*功能：将 p 进制 n 转换为 q 进制。p 和 q 的取值范围为【2，36】，
其中，用到的数码按从小到大依次为：0，1，2，3，4，5，6，7，8，9，A，B，...，Z，不考虑小写字母。
注意：n 的长度不超过50位。
三个数之间用逗号间隔。
*/

#include <iostream>
#include <cstring>
#include <cmath> //预处理指令

using namespace std;


int main()
{
	int m, i, k, l, t, p, q, len;
	int count = 0;
	char x[200] = { 0 }, res[200] = { 0 };
	int in[200] = { 0 };
	cin >> m;
	for (k = 0; k < m; k++)
	{

		l = 0;
		cin >> p;
		getchar();
		while ((x[l] = getchar()) != ',')
			l++;
		x[l] = 0;        //字符一共有l位
		cin >> q;           //读入p, n, q
		for (i = 0; i < l; i++)
		{
			if ((x[i] >= '0') && (x[i] <= '9'))
				in[i] = int(x[i]) - 48;
			if ((x[i] >= 'A') && (x[i] <= 'Z'))
				in[i] = int(x[i]) - int('A') + 10;      //得到每一位的int存入in
		}

		while (1)
		{

			t = 0;           //归零
			len = 0;
			for (i = 0; i < l;)     //对当前数字进行除q法
			{
				while (t < q && i < l)  //t小于q的时候，直接将它作为余数*p给下一个位数  当i达到最后时直接将其作为余数存进另一个数组
				{
					t = t * p + in[i];
					in[i] = 0;
					i++;
				}
				if (t >= q)    //t比q大的时候，进行除法
				{
					in[i - 1] = t / q;
					t %= q;
				}
			}
			if (t > 9)     //余数进行转换以后存入数组res
				res[count++] = t - 10 + 'A';
			else
				res[count++] = t + '0';
			len = -1;
			for (i = 0; i < l && in[i] == 0; i++)
			{
				len = i;
			}
			if (l - len < 2)
				break;
		}
		for (int i = count - 1; i >= 0; i--)
			cout << res[i];


		cout << endl;
		count = 0;
		for (i = 0; i < 200; i++)
		{
			x[i] = 0;
			res[i] = 0;
			in[i] = 0;
		}            //归零
	}
	return 0;
}