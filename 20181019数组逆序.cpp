/*
*程序名：数组逆序
*作者：何卓远
*编制时间：2018-10-19
*功能：数组逆序

*/
#include <iostream>         //预处理指令

using namespace std;

int main()
{
	int x, n, a[100], i;
	cin >> n;
	for (i=1;i<=n;i++)
	{
		cin >> x;
		a[n - i] = x;      //倒着放入数组
	}
	cout << a[0];
	for (i = 1; i < n; i++)
		cout << " " << a[i];  //正序输出
	return 0;    //程序结束
}

