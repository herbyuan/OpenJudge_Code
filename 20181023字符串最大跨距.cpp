/*
*程序名：字符串最大跨距
*作者：何卓远
*编制时间：2018-10-23
*功能：计算字符串最大跨距

*/
#include <iostream>       //预处理指令

using namespace std;

int main()
{
	char s[501], s1[11], s2[11];
	char x;
	bool b1, b2;
	int i, j, k, l, n, m;
	i = j = k= n = l = m =1;
	int zz, qs;
	zz = qs = 0;        //终止和起始的位置
	while ((x=getchar())!=',')
	{
		s[n] = x;
		n++;
	}
	n--;        //n是S的长度
	while ((x = getchar()) != ',')
	{
		s1[l] = x;
		l++;
	}
	l--;       //l是S1长度
	while ((x = getchar()) != '\n')
	{
		s2[m] = x;
		m++;
	}
	m--;       //m是S2长度
	for (i=1;i<=n-l+1;i++)
	{
		if (s[i]==s1[1])
		{
			b1 = true;
			for (j = i + 1; j <= i + l - 1; j++)
			{ if (s[j]!=s1[j-i+1])
			   {
				b1 = false;
				break;
			    }
			}
			if (b1)
			{
				zz = i + l - 1;
				break;
			}
		} 
	}                      //取得第一个S1的终止位置
	for (i = 1; i <= n - m + 1; i++)
	{
		if (s[i] == s2[1])
		{
			b2 = true;
			for (j = i + 1; j <= i + m - 1; j++)
			{
				if (s[j] != s2[j-i+1])
				{
					b2 = false;
					break;
				}
			}
			if (b2) qs = i;
		}
	}                           //取得最后一个S2的起始位置
	if (zz >= qs) cout << "-1";
	else cout << (qs - zz - 1);     //输出

	return 0;    //程序结束
}

