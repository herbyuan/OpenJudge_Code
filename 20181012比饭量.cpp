/*
*程序名：比饭量
*作者：何卓远
*编制时间：2018-10-12
*功能：比饭量

*/
#include <iostream>
#include<cmath>          //预处理指令

using namespace std;

int main()
{
	int a, b, c;             //存储饭量顺序
	int x, y, z;             //存储对的数量
	int j, k, l;             //导出饭量顺序
	for (a = 1; a <= 3; a++)
	{
		for (b = 1; b <= 3; b++)
		{
			for (c = 1; c <= 3; c++)     //穷举
			{
				if ((a == b) || (b == c) || (a == c)) continue;    //如果顺序相同就跳过
				else
				{
					x = y = z = 0;
					if (b > a) x = x + 1;
					if (a == c) x = x + 1;
					if (a > b) y = y + 1;
					if (a > c) y = y + 1;
					if (c > b) z = z + 1;
					if (b > a) z = z + 1;                    //计算对的话的数量
					if ((a + x == 3) && (b + y == 3) && (c + z == 3))       
					{
						j = a;
						k = b;
						l = c;                             //存储答案
					}

				}
			}
		}
	}
	if ((j < k )&&(k < l)) cout << "ABC" << endl;
	if ((j < l )&&(l < k)) cout << "ACB" << endl;
	if ((k < l )&&(l < j)) cout << "BCA" << endl;
	if ((k < j )&&(j < l)) cout << "BAC" << endl;
	if ((l < k )&&(k < j)) cout << "CBA" << endl;
	if ((l < j )&&(j < k)) cout << "CAB" << endl;                  //判断顺序输出
	return 0;    //程序结束
}

