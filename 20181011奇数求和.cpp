/*
*程序名：奇数求和
*作者：何卓远
*编制时间：2018-10-11
*功能：奇数求和

*/
#include <iostream>
#include<cmath>          //预处理指令

using namespace std;

int main()
{
	int sum, a, b, c;//变量声明
	sum = 0;
	cin >> a >> b;
	if (a % 2 == 1) c = a;
	else c = a + 1;             //得到第一个加数
	while (c <= b)       
	{
		sum = sum + c;
		c = c + 2;
	}                                    //逐次增加得到奇数并求和
	cout << sum << endl;
	return 0;    //程序结束
}

