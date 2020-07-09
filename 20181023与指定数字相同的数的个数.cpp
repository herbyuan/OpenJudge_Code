/*
*程序名：与指定数字相同的数的个数
*作者：何卓远
*编制时间：2018-10-23
*功能：计算与指定数字相同的数的个数

*/
#include <iostream>
#include<cmath>          //预处理指令

using namespace std;

int main()
{
	int N, i, m, a[101] = { 0 }, num = 0;
	cin >> N;
	for (i=1;i<=N;i++)
	{
		cin >> a[i];
	}                //将数放入数组a
	cin >> m;
	for (i=1;i<=N;i++)
	{
		if (a[i] == m) num++;
	}                      //计算与指定数字相同的数的个数
	cout << num;      //输出
	return 0;    //程序结束
}

