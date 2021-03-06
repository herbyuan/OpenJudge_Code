/*
*程序名：输出前k大的数
*作者：何卓远
*编制时间：2018-10-19
*功能：输出前k大的数

*/
#include <iostream>
#include<cmath>  
#include <algorithm>//预处理指令

using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

int main()
{
	int i, n, k, x;
	int a[1001] = { 0 };
	cin >> n;      
	for (i = 0; i < n; i++)  
	{
		cin >> x;
		a[i] = x;
	}       //读入数组
	cin >> k;        
	sort(a, a + n, cmp);    //排序
	for (i = 0; i <= k-1; i++)
		cout << a[i] << endl;   //输出前k个
	return 0;    //程序结束
}

