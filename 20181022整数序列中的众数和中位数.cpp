/*
*程序名：整数序列中的众数和中位数
*作者：何卓远
*编制时间：2018-10-22
*功能：计算整数序列中的众数和中位数

*/
#include <iostream>
#include <algorithm>
#include <cmath>          //预处理指令

using namespace std;

bool compare(int a, int b)
{
	return a < b;
}

int main()
{
	int n, i, j, k=0, l=0;
	int x=0;
	int a[501], box[151] = { 0 };
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> a[0];
		j = 0;
		box[a[0]]++;
		for(;;)
		{
			if (getchar() != ',') break;//逐个读入数字
			else
			{
				j = j + 1;
				cin >> a[j];
				box[a[j]]++;
			}                              //总个数是j，记录在a数组中，box是各个数出现的次数
		}
		
		for (l = 0; l < j; l++)
		{
			if (box[a[l]] > k)
			{
				k = box[a[l]];
				x = a[l];
			}               //当看到次数更多时替换
		}
		if (j+1 == k) cout << "mode=NO,median=";
		else cout << "mode=" << x << ",median=";
		sort(a, a + (j+1), compare);    //排序
		if ((j+1) % 2 == 0) cout << "(" << a[(j+1) / 2 - 1] << "+" << a[(j+1) / 2] << ")/2" << endl;       
		else cout << a[(j) / 2] << endl;     //分类讨论中位数
		for (l = 0; l <= 500; l++) a[l] = 0;
		for (l = 0; l <= 150; l++) box[l] = 0;
		j = k = l = x = 0;
	}
	return 0;    //程序结束
}

