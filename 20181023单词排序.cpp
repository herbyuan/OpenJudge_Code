/*
*程序名：单词排序
*作者：何卓远
*编制时间：2018-10-23
*功能：输入一行单词序列，相邻单词之间由1个或多个空格间隔，请按照字母顺序输出这些单词（即按照字符串中字母的ASCII码排序，区分大小写，当首字母相同时，比较第2个字母，依次类推），要求重复的单词只输出一次。
*/
#include <iostream>
#include<string.h>         //预处理指令

using namespace std;



int main()
{
	int i, j, m = 0, k;
	char x, w[101][51], temp[51];
	bool b1;
	for (i = 0; i < 51; i++) temp[i] = '\0';
	for (i=0;i<101;i++)
	{
		for (j = 0; j < 51; j++) w[i][j] = '\0';
	}
	for (;;)
	{
		i = 0;
		b1 = true;
		while (((x = getchar()) != ' ') && (x != '\n'))
		{
			temp[i] = x;
			i++;              //读入每个单词,长度为i
		}              //先读到temp
		for (j = 0;j < m;j++)
		{
			if (strcmp(w[j], temp) == 0) 
			{ b1 = false; break; }     //如果一样就不算数
		}
		if ((b1) && (temp[0]!='\0'))
		{
			for (j = 0;j < i;j++)
			{
				w[m][j] = temp[j];
			}
			m++;                //共有m个单词 ，记录在w[i]
		} 
		for (j = 0; j < 51; j++)	temp[j] = '\0';
		if (x == ' ')  continue;
		if (x == '\n') break;
	}

	for (i = 0; i < m;i++)
	{
		for (j = 0; j < m - i - 1; j++)
		{
			if (strcmp(w[j], w[j + 1]) > 0)
			{
				strcpy(temp, w[j]);
				strcpy(w[j], w[j+1]);
				strcpy(w[j+1], temp);     //交换次序
			}
		}
	}       //冒泡排序
	for (i = 0; i < m; i++)      cout << w[i] << endl;
	return 0;    //程序结束
}

