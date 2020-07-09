/*
*程序名：扩号匹配问题
*作者：何卓远
*编制时间：2018-11-17
*功能：在某个字符串（长度不超过100）中有左括号、右括号和大小写字母；规定（与常见的算术式子一样）任何一个左括号都从内到外与在它右边且距离最近的右括号匹配。写一个程序，找到无法匹配的左括号和右括号：首先输出原来字符串，下一行是和原字符串等长的一行，标出不能匹配的括号，其中不能匹配的左括号用"$"标注,不能匹配的右括号用"?"标注 
*/

#include <iostream>
#include <cstring>

using namespace std;

int a[101] = { 0 }, l;
char str[101];

bool func(int zuokuo, int len)    //zuokuo记录左括号个数，len是当前长度
{
	
	char str1[101] = { 0 };
	for (int i = l - len; i < l; i++)
	{
		str1[i - l + len] = str[i];
	}
	if (len == 0)
	{
		if (zuokuo > 0) return 0;
		else return 1;
	}          //最后一位情况
	switch (str1[0])
	{
	case'(':str[l - len] = 'A';      //改动当前括号
			bool x;
			zuokuo++;
			x = func(zuokuo, len - 1);
			if (!x) a[l - len] = -1;     //如果有问题 对当前位置标记
			else zuokuo--;         //不然这个括号pass
			return func(zuokuo, len - 1);   //返回之后的判断
			
	case')':str[l - len] = 'A'; 
		if (zuokuo <= 0)
		{
			a[l - len] = 1;
			return func(zuokuo, len - 1);
		}         //当前右括号不匹配的情况
		else
			return 1;    //右括号匹配
	default: return func(zuokuo, len - 1);    //不是括号的情况
	
	}
}
int main()
{
	int n, i, j;
	//cin >> n;
	while(cin>>str)
	{
		for ( i = 0; i < 101; i++)
		{
			//str[i] = 0;
			a[i] = 0;
		}     //清零memory
		//cin >> str;
		cout << str << endl;
		l = strlen(str);    //记录长度
		func(0, l);
		for ( i = 0; i < l; i++)
		{
			switch (a[i])
			{
			case -1:cout << '$'; break;
			case 0:cout << ' '; break;
			case 1:cout << '?'; break;
			}    //输出
		}
		cout << endl;
	}
	return 0;
}