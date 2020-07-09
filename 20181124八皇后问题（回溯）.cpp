/*
*程序名：八皇后问题(回溯)
*作者：何卓远
*编制时间：2018-11-24
*功能：会下国际象棋的人都很清楚：皇后可以在横、竖、斜线上不限步数地吃掉其他棋子。如何将8个皇后放在棋盘上（有8 * 8个方格），使它们谁也不能被吃掉！即任何两个皇后都不会在同一行、同一列、或同一斜线上。这就是著名的八皇后问题。 
*/
#include <iostream>
#include <cstring>
using namespace std;
char board[9][9];
bool righttop[16],lefttop[16],row[9];
int solutionNum=0;
void queen(int col)
{
	if (col == 9)
	{
		cout<<"No."<<++solutionNum<<endl;
		for (int i = 1; i <= 8; i++)
		{
			for (int j = 1; j < 8; j++)
				cout << board[i][j] << ' ';
			cout<<board[i][8]<<endl;
		}
	}        //成功就输出
	else 
	{
		for (int i = 1; i <= 8; i++)      //对于给定列，穷举所有的行
		{
			if (row[i] || righttop[i+col-1] || lefttop[8+i-col]) continue;
			board[i][col]='*';
			row[i]=1;
			righttop[i+col-1]=1;
			lefttop[8+i-col]=1;
			queen(col+1);     //改变棋盘状态，并尝试下一列皇后
			board[i][col]='.';
			row[i]=0;
			righttop[i+col-1]=0;
			lefttop[8+i-col]=0;     //回溯尝试下一行，需改回棋盘状态
		}
	}
}
int main()
{
	memset(board,'.',sizeof(board));
	queen(1);
	return 0;
}