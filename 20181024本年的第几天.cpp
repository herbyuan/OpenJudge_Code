/*
*程序名：本年的第几天
*作者：何卓远
*编制时间：2018-10-24
*功能：给定一个年、月、日值，求这天该年的第几天
*/
#include <iostream>      //预处理指令

using namespace std;

int main()
{
	int y, m, d;
	bool leap;
	int day;
	cin >> y >> m >> d;
	if ((y % 4 == 0) && (y % 100 != 0)) leap = true;
	else if (y % 400 == 0) leap = true;
	else leap = 0;    //判断闰年
	switch (m)
	{
	case 1:day = d; break;
	case 2:day = 31 + d; break;
	case 3:if (leap) day = 31 + 29 + d;
		   else day = 31 + 28 + d;
		break;
	case 4:if (leap) day = 31 + 29 + 31 + d;
		   else day = 31 + 28 + 31 + d;
		break;
	case 5:if (leap) day = 121 + d;
		   else day = 120 + d;
		break;
	case 6:if (leap) day = 152 + d;
		   else day = 151 + d;
		break;
	case 7:if (leap) day = 182 + d;
		   else day = 181 + d;
		break;
	case 8:if (leap) day = 213 + d;
		   else day = 212 + d;
		break;
	case 9:if (leap) day = 244 + d;
		   else day = 243 + d;
		break;
	case 10:if (leap) day = 274 + d;
			else day = 273 + d;
		break;
	case 11: if (leap) day = 305 + d;
			 else day = 304 + d;
		break;
	case 12:if (leap) day = 335 + d;
			else day = 334 + d;
		break;
	}   //分12个月讨论
	cout << day;   //输出
	return 0;    //程序结束
}

