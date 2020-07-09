/*
*程序名：前缀表达式
*作者：何卓远
*编制时间：2018-11-09
*功能：前缀表达式是一种把运算符前置的算术表达式，例如普通的表达式2 + 3的前缀表示法为+ 2 3。
前缀表达式的优点是运算符之间不必有优先级关系，也不必用括号改变运算次序，
例如(2 + 3) * 4的前缀表示法为* + 2 3 4。本题求解前缀表达式的值，其中运算符包括+ - * /四个。
*/

#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;

double notation()
{
	char str[10];
	cin >> str;
	switch (str[0])
	{
	case '+':return notation() + notation();
	case '-':return notation() - notation();
	case '*':return notation() * notation();
	case '/':return notation() / notation();
	default:return atof(str);
	}
}
int main()
{
	double ans;
	ans = notation();
	printf("%.6lf", ans);
	return 0;
}