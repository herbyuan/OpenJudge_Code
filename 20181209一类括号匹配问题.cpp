/*
*程序名：一类括号匹配问题
*作者：何卓远
*编制时间：2018-12-09
*功能：检查小括号的匹配问题。如果存在小括号不匹配，则输出 mismatch；如果所有小括号匹配，则按左右括号的匹配距离由小到大输出左、右括号的位置；若多个匹配的距离相等，则左括号先出现的匹配先输出；如果整个串中没有小括号，则左右位置均输出0，即 0,0
*/
#include <iostream>
#include <cstring>
using namespace std;
char str[500] = { 0 };
int ans[250][3] = { 0 }, s = 0;
int len;
void output()
{
	for (int i = 0; i < s; i++)
	{
		cout << ans[i][0]+1 << "," << ans[i][1]+1 << endl;
	}
}       //输出
void sort1()
{
	int i, j;
	int t;
	for (i = 1; i < s; i++)
	{
		for (j = 0; j < s - i; j++)
		{
			if (ans[j][0] > ans[j + 1][0])
			{
				t = ans[j][0];
				ans[j][0] = ans[j + 1][0];
				ans[j + 1][0] = t;
				t = ans[j][1];
				ans[j][1] = ans[j + 1][1];
				ans[j + 1][1] = t;
				t = ans[j][2];
				ans[j][2] = ans[j + 1][2];
				ans[j + 1][2] = t;
			}
		}
	}
}       //按照第一个括号排列
void sort2()
{
	int i, j;
	int t;
	for (i = 1; i < s; i++)
	{
		for (j = 0; j < s - i; j++)
		{
			if (ans[j][2] > ans[j + 1][2])
			{
				t = ans[j][0];
				ans[j][0] = ans[j + 1][0];
				ans[j + 1][0] = t;
				t = ans[j][1];
				ans[j][1] = ans[j + 1][1];
				ans[j + 1][1] = t;
				t = ans[j][2];
				ans[j][2] = ans[j + 1][2];
				ans[j + 1][2] = t;
			}
		}
	}
}     //按照距离排列
int match(int n)
{
	if (n >= len) return 0;
	if (str[n] != '(' && str[n] != ')')
	{
		return match(n + 1);
	}    //直接下一位
	if (str[n] == '(')
	{
		str[n] = '\0';
		int t;
		t = match(n + 1);
		ans[s][0] = n;
		ans[s][1] = t;
		ans[s][2] = t - n;
		s++;     //记录
		return match(n + 2);
	}
	if (str[n] == ')')
	{
		str[n] = '\0';
		return n;
	}
}        //匹配括号
int main()
{
	cin >> str;
	len = strlen(str);
	int left = 0, right = 0;
	for (int i = 0; i < len; i++)
	{
		if (str[i] == '(') left++;
		if (str[i] == ')') right++;
		if (left < right)
		{
			cout << "mismatch" << endl;
			return 0;
		}
	}          //判断是否成立
	if (left != right)
	{
		cout << "mismatch" << endl;
		return 0;
	}
	if (left == 0)
	{
		cout << "0,0" << endl;
		return 0;
	}
	match(0);
	sort1();
	sort2();
	output();
	return 0;
}