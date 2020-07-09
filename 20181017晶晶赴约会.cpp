/*
*程序名：晶晶赴约会
*作者：何卓远
*编制时间：2018-10-17
*功能：判断是否能接受邀请

*/
#include <iostream>         //预处理指令

using namespace std;

int main()
	{
		int x;
		cin >> x;      //读入日期
		if ((x == 1) || (x == 3) || (x == 5)) cout << "NO" << endl;
		else cout << "YES" << endl; //判断并输出
		return 0;    //程序结束
	}

