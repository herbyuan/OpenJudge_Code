/*
*程序名：侃侃而谈的四位朋友
*作者：何卓远
*编制时间：2018-10-24
*功能：判断四个人会的语言
*/
#include <iostream>     //预处理指令

using namespace std;

int main()
{
	bool a[5][5];
	int i[5], j[5], l, m;
	bool b1, b2, b3, b4;
	for (i[1] = 0; i[1] < 4; i[1]++)
	{
		for (j[1] = i[1] + 1; j[1] < 4; j[1]++)
		{
			for (i[2] = 0; i[2] < 4; i[2]++)
			{
				for (j[2] = i[2] + 1; j[2] < 4; j[2]++)
				{
					for (i[3] = 0; i[3] < 4; i[3]++)
					{
						for (j[3] = i[3] + 1; j[3] < 4; j[3]++)
						{
							for (i[4] = 0; i[4] < 4; i[4]++)
							{
								for (i[0] = 0; i[0] < 4; i[0]++)
								{
									for (j[0] = 0; j[0] < 4; j[0]++)
									{
										a[i[0]][j[0]] = false;
									}
								}
								a[0][i[1]] = a[0][j[1]] = true;
								a[1][i[2]] = a[1][j[2]] = true;
								a[2][i[3]] = a[2][j[3]] = true;
								a[3][i[4]] = true;           //条件A

								b1 = true;
								if (a[0][3] == false) b1 = false;
								if (a[3][3] == true) b1 = false;
								if (a[1][1] == true) b1 = false;    //只有满足C才继续判断
								if (!b1) continue;         //不成立时讨论下一种情况
								b2 = false;
								for (l = 0; l < 4; l++)
									if (a[0][l] + a[1][l] + a[2][l] + a[3][l] == 3) b2 = true;
								if (!b2) continue;   //判断B
								b3 = true;
								for (l = 0; l < 4; l++)
									if (a[l][2] + a[l][3] == 2) b3 = false;
								if (!b3) continue;        //判断E
								if ((a[1][0] * a[2][0] + a[1][1] * a[2][1] + a[1][2] * a[2][2] + a[1][3] * a[2][3] > 0) && (a[0][0] * a[2][0] + a[0][1] * a[2][1] + a[0][2] * a[2][2] + a[0][3] * a[2][3] == 0) && (a[2][0] * a[3][0] + a[2][1] * a[3][1] + a[2][2] * a[3][2] == 0))      //判断D
								{
									
									for (l = 0; l < 3; l++)
									{
										b4 = true;
										for (m = 0; m < 4; m++)
										{
											if ((a[l][m]) && (!b4)) cout << m + 1 << endl;
											if ((a[l][m]) && (b4)) { cout << m + 1 << " "; b4 = false; }
											
										}	
									}
									for (m = 0; m < 4; m++)
										if (a[3][m]) cout << m+1;
								}
							}
						}
					}
				}
			}
		}
	}

	return 0;    //程序结束
}