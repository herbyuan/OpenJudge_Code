/*
*程序名：简单的缩略语判断
*作者：何卓远
*编制时间：2018-12-05
*功能：各种语言都充满了缩略语。如汉语上的“非典（非典型性肺炎）”，“北大（北京大学）”，英语上的“SARS(Severe Atypical Respiratory Syndrome)”。假定某个字符串A中的每个字符出现在另一个字符串S中不同的位置（大小写完全相同），且字符串 A 中字符的前后关系在 S 中不发生改变，同时，A的长度小于S的长度，就认为 A 是 S 的一个可能缩略语。现在任意给定两对串，请判断前面的串是否是后面串的可能缩略语。若是，则输出 YES，否则，输出 NO
*/
#include <iostream>
#include <cstring>
using namespace std;
bool cmp(char l[], char r[],int a, int b)
{
	if (l[a] == '\0') return 1;
	for (; r[b] != '\0'; )
	{
		if (l[a] == r[b]) return cmp(l, r, ++a, ++b);
		b++;
	}
	return 0;
}
void judge()
{
	char l[40] = { 0 }, r[310] = { 0 }, str[400] = { 0 };
	cin.getline(str, 400);
	int p, len, k;
	len = strlen(str);
	for (p = 0; p < 40; p++)
	{
		if (str[p] == ':') break;
	}
	for (int i = 0; i < p; i++)
	{
		l[i] = str[i];
	}
	for (int i = p + 1, k = 0; i < len; i++,k++)
	{
		r[k] = str[i];
	}
	if (strlen(l) >= strlen(r))
	{
		cout << "NO" << endl;
		return;
	}
	if (cmp(l, r, 0, 0)) cout << "YES" << endl;
	else cout << "NO" << endl;
}
int main()
{
	int n;
	cin >> n;
	getchar();
	for (int i = 0; i < n; i++)
	{
		judge();
	}
	return 0;
}