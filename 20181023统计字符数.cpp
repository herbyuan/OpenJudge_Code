/*
*程序名：统计字符数
*作者：何卓远
*编制时间：2018-10-23
*功能：判断一个由a-z 这26 个字符组成的字符串中哪个字符出现的次数最多
*/
#include <iostream>
#include<cmath>          //预处理指令

using namespace std;

int main()
{
	int a[26] = { 0 }, n, i, j, k, asc;
	char x;
	cin >> n;
	for (i=1;i<=n;i++)
	{
		cin >> x;
		a[x - 97]++;
		while ((x = getchar()) != '\n')
		{
			a[x - 97]++;     //a是各个字母出现的次数
		}
		k = asc = 0;
		for (j = 0; j < 26; j++)
		{
			if (a[j] > k)
			{
				k = a[j];
				asc = j + 97;      //k是最多次数 asc是该字符
			}
		}
		cout << char(asc) << " " << k << endl;     //输出
		for (j = 0; j < 26; j++)  a[j] = 0;     //归零
		
	}
	
	return 0;    //程序结束
}

