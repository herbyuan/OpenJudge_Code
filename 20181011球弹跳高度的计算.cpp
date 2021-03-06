/*
*程序名：球弹跳高度的计算
*作者：何卓远
*编制时间：2018-10-11
*功能：球弹跳高度的计算

*/
#include <iostream>
#include<cmath> 
#include<iomanip>//预处理指令

using namespace std;

int main()
{
	int h,i;
	double s, x;
	cin >> h;
	s = -h;                    //为了避免出错赋予负的初始值
	x = h;
	for(i=1;i<=10;i++)        
	{
		s = s + 2 * x;      //循环求和
		x = x / 2;           //新的高度
	}
	
	cout << s << endl << fixed << setprecision(6) << x << endl;  // 控制精度输出
	return 0;    //程序结束
}

