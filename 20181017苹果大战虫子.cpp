/*
*程序名：苹果大战虫子
*作者：何卓远
*编制时间：2018-10-17
*功能：计算完整的苹果数目

*/
#include <iostream>
#include<cmath>          //预处理指令

using namespace std;

int main()
{
	float n, x, y;    //定义变量
	cin >> n >> x >> y;//读入
	n = int(n - y / x);//计算完整苹果数目并且取整
	cout << n << endl;//输出
	return 0;    //程序结束
}

