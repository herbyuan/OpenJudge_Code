/*
*程序名：八皇后问题
*作者：何卓远
*编制时间：2018-11-09
*功能：会下国际象棋的人都很清楚：皇后可以在横、竖、斜线上不限步数地吃掉其他棋子。如何将8个皇后放在棋盘上（有8 * 8个方格），使它们谁也不能被吃掉！即任何两个皇后都不会在同一行、同一列、或同一斜线上。这就是著名的八皇后问题。 
*/

#include <iostream>    //预处理指令

using namespace std;

int main()
{
	int i[9], j, n = 1, k, a;
	bool chess[9][9] = { 0 };
	bool b;
	for (i[0] = 1; i[0] <= 8; i[0]++)
	{
		chess[1][i[0]] = 1;
		for (i[1] = 1; i[1] <= 8; i[1]++)
		{
			chess[2][i[1]] = 1;
			if (chess[1][i[1]] + chess[2][i[1]] >= 2) 
			{
				chess[2][i[1]] = 0;
				continue;
			}
			for (i[2] = 1; i[2] <= 8; i[2]++)
			{
				chess[3][i[2]] = 1;
				if (chess[1][i[2]] + chess[2][i[2]] + chess[3][i[2]] >= 2)
				{
					chess[3][i[2]] = 0;
					continue;
				}
				for (i[3] = 1; i[3] <= 8; i[3]++)
				{
					chess[4][i[3]] = 1;
					if (chess[1][i[3]] + chess[2][i[3]] + chess[3][i[3]] + chess[4][i[3]] >= 2)
					{
						chess[4][i[3]] = 0;
						continue;
					}
					for (i[4] = 1; i[4] <= 8; i[4]++)
					{
						chess[5][i[4]] = 1;
						if (chess[1][i[4]] + chess[2][i[4]] + chess[3][i[4]] + chess[4][i[4]] + chess[5][i[4]]>= 2)
						{
							chess[5][i[4]] = 0;
							continue;
						}
						for (i[5] = 1; i[5] <= 8; i[5]++)
						{
							chess[6][i[5]] = 1;
							if (chess[1][i[5]] + chess[2][i[5]] + chess[3][i[5]] + chess[4][i[5]] + chess[5][i[5]] + chess[6][i[5]]>= 2)
							{
								chess[6][i[5]] = 0;
								continue;
							}
							for (i[6] = 1; i[6] <= 8; i[6]++)
							{
								chess[7][i[6]] = 1;
								if (chess[1][i[6]] + chess[2][i[6]] + chess[3][i[6]] + chess[4][i[6]] + chess[5][i[6]] + chess[6][i[6]] + chess[7][i[6]]>= 2)
								{
									chess[7][i[6]] = 0;
									continue;
								}
								for (i[7] = 1; i[7] <= 8; i[7]++)
								{
									chess[8][i[7]] = 1;
									if (chess[1][i[7]] + chess[2][i[7]] + chess[3][i[7]] + chess[4][i[7]] + chess[5][i[7]] + chess[6][i[7]] + chess[7][i[7]] + chess[8][i[7]]>= 2)
									{
										chess[8][i[7]] = 0;
										continue;
									}               //分次放下各个棋子，一旦发现列有重叠就回溯
									b = 1;
									for (j = 1; j <= 7; j++)
									{
										a = 0;
										for (k = j; k <= 8; k++)
											a += chess[k][k - j + 1];
										if (a > 1) b = 0;
									}     //斜线不能吃
									for (j = 1; j <= 6; j++)
									{
										a = 0;
										for (k = j + 1; k <= 8; k++)
											a += chess[k - j][k];
										if (a > 1) b = 0;
									}         //斜线不能吃
									for (j = 2; j <= 8; j++)
									{
										a = 0;
										for (k = j; k >= 1; k--)
											a += chess[k][j + 1 - k];
										if (a > 1) b = 0;
									}        //斜线不能吃
									for (j = 2; j <= 7; j++)
									{
										a = 0;
										for (k = j; k <= 8; k++)
											a += chess[j+8-k][k];
										if (a > 1) b = 0;
									}          //斜线不能吃
									if (b)      //如果符合条件
									{
										cout << n << endl;
										for (j = 1; j <= 8; j++)
										{
											if (chess[1][j] == 1) cout << "*";
											else cout << ".";
											for (k = 2; k <= 8; k++)
											{
												if (chess[k][j] == 1) cout << " *";
												else cout << " .";
											}            //因为按照行考虑，输出时转置矩阵
											cout << endl;
										}
										n++;     //计数器+1
									}
									chess[8][i[7]] = 0;
									if (n > 100) return 0;
								}
								chess[7][i[6]] = 0;
							}
							chess[6][i[5]] = 0;
						}
						chess[5][i[4]] = 0;
					}
					chess[4][i[3]] = 0;
				}
				chess[3][i[2]] = 0;
			}
			chess[2][i[1]] = 0;
		}
		chess[1][i[0]] = 0;
	}

	return 0; //程序结束
}