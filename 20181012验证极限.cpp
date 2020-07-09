/*
*程序名：验证极限
*作者：何卓远
*编制时间：2018-10-12
*功能：验证极限

*/
#include <iostream>
#include<cmath> 
#include<iomanip>//预处理指令

using namespace std;

int main()
{
	double x, a, e;
	cin >> x >> a >> e;
	int n;
	for(n = 0;;n++)      //输入
	{
		if (abs(x / pow(a, n)) < e) break;
		
	}                                      //当最小的n符合条件时停止
	if (n == 0) cout << "0" << endl;
	else cout << n - 1 << endl;                        //输出
	return 0;    //程序结束
}

