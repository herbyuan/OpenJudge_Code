/*
*程序名：删除数组中的元素
*作者：何卓远
*编制时间：2018-10-19
*功能：给定一个整数和一个整数数组，将数组中所有和该数相等的元素从数组中删除。 
*/
#include <iostream>       //预处理指令

using namespace std;

int main()
{
	int n, i, j, x, k;
	cin >> n;
	int a[100001];
	for (i = 1; i <= n; i++)
	{
		cin >> x;
		a[i] = x;
	}                              //读入数组
	cin >> k;                   //读入删除的数字
	for (i = 1; i <= n; i++)
	{
		if (a[i] == k)            //如果第i位应该删除
		{
			n = n - 1;           //总数减一
			for (j = i; j <= n; j++)    a[j] = a[j + 1];      //前移一位
			i = i - 1;            //重新判断第i位
		}
	}
	cout << a[1];
	for (i = 2; i <= n; i++)
		cout << " " << a[i];      //输出结果
    return 0;    //程序结束
}

