/*
*程序名：平衡矩阵
*作者：何卓远
*编制时间：2018-12-09
*功能：分解质因数
*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
		int x, i, j;
		int a[200];
		float t;
		j = 0;
			i = 2;
			cin >> x;
			t = x;
			cout << x << "=";
			for (; x >= 2 ; i++)
			{
				if (x%i == 0)
				{
					x /= i;
					a[j] = i;
					j++;
					i--;
					if (i*i > t)
						break;
				}
			}

			for (i = 0; i < j - 1; i++)
				cout << a[i] << "*";
			cout << a[i] << endl;
		return 0;
}

