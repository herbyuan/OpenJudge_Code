/*
*程序名：找相似串
*作者：何卓远
*编制时间：2018-12-11
*功能：在近似搜索中经常需要计算串的相似性。所谓找相似串，就是从某个串的集合T 中找出与给定串 S 最相似的串。如果在T中有一个串和S完全相同，那么，这个串与S的相似度最高。一般情况下，度量两个串 S1 和 S2 的相似性，可以通过从一个串变换成另一个串所需要的最少操作次数来衡量，需要的操作次数越少，则越相似。假设从一个串变化成另一个串所允许的操作只有两种：插入一个字符或者删除一个字符。无论是插入还是删除一个符号，均算作一次操作。当给定串S和集合T时，请从T中找出与 S最相似的串。

例如 两个串分别为S1=abcd 和 S2=aced
从S1 变化为 S2 所需要的最少操作是：
删除 S1 中的 b（一次操作），然后在d之前插入 e（一次操作），共2次操作。

如果S2=abed，同样由 S1 变换成 S2 也需要 2次操作（先删除 S1 中的 c， 再插入 e）。
*/

#include <iostream>
#include <cstring>
using namespace std;
char S[500] = { 0 };
char T[200][500] = { 0 };
int manipNum[500] = { -1 }, mini = 999999, length, len;
int maxLen[502][502] = { 0 };
int func(int n)        //计算最大公共子序列
{
	for (int i = 0; i < 502; i++)
	{
		maxLen[0][i] = 0;
		maxLen[i][0] = 0;
	}
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < len; j++)
		{
			if (S[i] == T[n][j])
			{
				if (i == 0 || j == 0) maxLen[i][j] = 1;
				else
					maxLen[i][j] = maxLen[i - 1][j - 1] + 1;   //如果相同，那么+1判断下一位
			}
			else
			{
				int len1;
				if (j == 0)
					len1 = 0;
				else len1 = maxLen[i][j - 1];
				int len2;
				if (i == 0)
					len2 = 0;
				else len2 = maxLen[i - 1][j];
				if (len1 > len2)
					maxLen[i][j] = len1;
				else maxLen[i][j] = len2;
			}      //即maxLen[i][j] = Max(maxLen[i][j-1],maxLen[i-1][j])

		}
	}
	return maxLen[length - 1][len - 1];
}

int main()
{
	cin >> S;
	int n;
	length = strlen(S);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> T[i];
		len = strlen(T[i]);
		manipNum[i] = length + len - 2 * func(i);          //操作次数是变成最大公共子序列然后补全
		mini = (manipNum[i] < mini) ? manipNum[i] : mini;
	}
	for (int i = 0; i < n; i++)
	{
		if (manipNum[i] == mini)
			cout << T[i] << endl;
	}
	return 0;
}
