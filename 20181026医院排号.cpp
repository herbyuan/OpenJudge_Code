/*
*程序名：医院排号
*作者：何卓远
*编制时间：2018-10-26
*功能：输出校医院当天接收的所有病人的看病顺序。

*/
#include <iostream>        //预处理指令

using namespace std;

int main()
{
	int t, i, j, n, l, k, a[100000] = { 0 }, temp, b[10000] = { 0 };
	cin >> t;
	
	for(i=1;i<=t;i++)
	{
		for (j = 1; j <= 9999; j++)
			b[j] = j;
		cin >> n >> k;   //表示请求在同一天看病的病人有n个，医院当天只能接受k个病人 
		for (j=1;j<=n;j++)
		{
			cin >> a[j];
		}
		a[0] = n;;
		for (j = 1;j < n;n--)
		{
			for (l = j;l < n;l++)
			{if (a[l] < a[l+1]) 
			{
				temp = a[l];
				a[l] = a[l + 1];
				a[l + 1] = temp;
				temp = b[l];
				b[l] = b[l + 1];
				b[l + 1] = temp;
			}                  //b中记录新的次序

			}
		}     //冒泡排序
		if (a[0] <= k)     //判断人数与挂号关系
		{
			cout << a[0] << endl;
			cout << b[1];
			for (j = 2; j <= a[0]; j++)
				cout << " " << b[j];
			cout << endl;
		}
		else
		{
			cout << k << endl;
			cout << b[1];
			for (j = 2; j <= k; j++)
			{
				cout << " " << b[j];
			}
			cout << endl;
		}

	}
	for (j = 1; j <= 9999; j++)
		a[j] = 0;
	return 0;    //程序结束
}

