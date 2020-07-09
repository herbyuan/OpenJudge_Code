//程序名：称硬币
//作者：何卓远
//时间：2018-11-28
#include <iostream>
#include <cstring>

using namespace std;
int coin[12] = { 0 };
bool judge(char a[], char b[], char c[])
{
	int left = 0, right = 0;
	int l;
	l = strlen(a);
	for (int i = 0; i < l; i++)
	{
		left += coin[a[i] - 'A'];
		right += coin[b[i] - 'A'];
	}
	switch (c[0])
	{
	case 'e':if (left == right) return true; break;
	case 'u':if (left > right) return true; break;
	case 'd':if (left < right) return true; break;
	}
	return false;
}
int chengyingbi()
{
	int b1, b2, b3;
	for (int i = 0; i < 12; i++)
	{
		coin[i] = 0;
	}
	char a[3][10] = { 0 }, b[3][10] = { 0 }, c[3][10] = { 0 };
	for (int j = 0; j < 3; j++)
	{
		cin >> a[j];
		cin >> b[j];
		cin >> c[j];
	}
	for (int j = 0; j < 12; j++)
	{
		coin[j] = 1;
		b1 = judge(a[0], b[0], c[0]);
		b2 = judge(a[1], b[1], c[1]);
		b3 = judge(a[2], b[2], c[2]);
		if (b1 + b2 + b3 == 3)
		{
			cout << char(j + 'A') << " is the counterfeit coin and it is heavy." << endl;
			return 0;
		}
		coin[j] = 0;
	}
	for (int j = 0; j < 12; j++)
	{
		coin[j] = -1;
		b1 = judge(a[0], b[0], c[0]);
		b2 = judge(a[1], b[1], c[1]);
		b3 = judge(a[2], b[2], c[2]);
		if (b1 + b2 + b3 == 3)
		{
			cout << char(j + 'A') << " is the counterfeit coin and it is light." << endl;
			return 0;
		}
		coin[j] = 0;
	}
}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		chengyingbi();
	}
	return 0;
}