/*
*程序名：判断闰年
*作者：何卓远
*编制时间：2018-10-11
*功能：判断某年是否是闰年。
*/
#include <iostream>
#include<cmath>        //预处理指令

using namespace std;

int main()
{
	int year;
	bool leap;
	cin >> year;                //输入年份
	if (year % 4 == 0)         //能否被4整除
	{
		if (year % 100 == 0)    //能否被100整除
		{
			if (year % 400 == 0)   leap = true;  //能否被400整除，判断闰年
			else leap = false;              //判断闰年
		}
		else leap = true;
	}
	else leap = false;
	if (leap) cout << "Y"<<endl;
	else cout << "N" << endl;      //输出结果
	return 0;    //程序结束
}

