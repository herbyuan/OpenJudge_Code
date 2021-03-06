/*
*程序名： 不与最大数相同的数字之和
*作者：何卓远
*编制时间：2018-10-17
*功能：计算 不与最大数相同的数字之和

*/
#include <iostream>
#include<cmath>          //预处理指令

using namespace std;

int main()
{
	int n, N, i, max, a, sum;
	cin >> N;  //输入
	sum = 0;
	cin >> a;
	max = a;
	sum = a;
	n = 1; 
	if (N >= 2)      //至少两个数时
	{
		for (i = 1; i <= N - 1; i++)
		{
			cin >> a;    //读入
			sum = sum + a;   //先求总和
			if (a == max) n++;
			if (a > max)
			{
				max = a;
				n = 1;
			}       //计算最大值和个数

		}
		sum = sum - n * max;   //计算N个数中除去最大数其余数字之和
		cout << sum << endl;//输出
	}
	else cout << "0" << endl;     //只有一个数
	return 0;    //程序结束
}

