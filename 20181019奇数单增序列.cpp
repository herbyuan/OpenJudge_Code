/*
*程序名：奇数单增序列
*作者：何卓远
*编制时间：2018-10-19
*功能：将其中的所有奇数取出，并按增序输出。

*/
#include <iostream>         //预处理指令
#include <algorithm>

using namespace std;

bool cmp(int a, int b) 
{
	return a < b;
}

int main()
{
	int n, i, x, k;
	cin >> n;
	int a[500] = { 0 };
	k = 0;
	for (i=0;i < n;i++)
	{
		cin >> x;
		if 
		
			(x % 2 != 0)
		{
			 a[i] = x;
		     k++;
		}         //当且仅当读入的数是奇数才纳入数组
	}
	sort(a, a + n , cmp);
	for (i = 0; i < n; i++)   //从小到大排列
	{
		if (a[i] != 0)
		{
			cout << a[i];
			break;
		}             //输出第一个数
	}
	for (i=i+1;i<n;i++)
	{
		if (a[i] != 0)  cout << "," << a[i];
	}              //输出完整的数列
	return 0;    //程序结束
}

