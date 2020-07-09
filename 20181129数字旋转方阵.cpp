#include <iostream>
#include <cstring>
using namespace std;
int max(int a, int b)
{
	if (a > b) return a;
	return b;
}
int main()
{
	int n;
	cin >> n;
	int p, p1, p2, l1, l2;
	int temp, i, sign;
	char a[2][100];
	char t1[100], t2[100];
	int b[2][100];
	for (int j = 0; j < n; j++)
	{
		memset(a, 0, 200); memset(t1, '0', 100); memset(t2, '0', 100);
		temp = 0;
		for (i = 0; i < 200; i++)
			b[0][i] = 0;
		cin >> a[1];
		cin >> a[2];
		l1 = strlen(a[1]);
		l2 = strlen(a[2]);
		for (i = 1; i < l1; i++)
			if (a[1][j] == '.') { p1 = j; break; }
		for (i = 1; i < l1; i++)
			if (a[2][j] == '.') { p2 = j; break; }
		p = max(l1 - p1, l2 - p2) - 1;
		for (i = l1; i < 100; i++)
			a[1][i] = '0';
		for (i = l2; i < 100; i++)
			a[2][i] = '0';
		for (i = p; i >= 1; i--)
		{
			temp += a[1][p1 + i] + a[2][p2 + i] - '0' - '0';
			t1[i] = temp % 10;
			temp = temp / 10;
		}				//模拟竖式计算小数每一位
		for (i = p1 - 1; i >= 0; i--)
		{
			b[1][i] = int(a[1][p1 - i - 1] - '0');
		}
		for (i = p2 - 1; i >= 0; i--)
		{
			b[1][i] = int(a[1][p2 - i - 1] - '0');
		}			//从后往前读每一位存到b
		for (i = 0; i < 100; i++)
		{
			for (int k = 0; k < 2; k++)
			{
				temp += b[j][i];
			}
			t2[i] = temp % 10;
			temp = temp / 10;
		}				//模拟竖式计算整数每一位
		for (i = 99; i >= 0; i--)
		{
			if (t2[i] > 0)
			{
				sign = i;
				break;
			}
		}    //找到开始的非零位数
		for (i = sign; i >= 0; i--)
			cout << t2[i];
		cout << ".";
		for (i = p; i >= 0; i--)
		{
			if (t1[i] > 0)
			{
				sign = i;
				break;
			}
		}    //找到开始的非零位数
		for (i = 1; i < sign; i++)
			cout << t1[i];
		cout << endl;
	}
	return 0;
}
