/*
*程序名：过滤多余的空格
*作者：何卓远
*编制时间：2018-10-23
*功能：一个句子的每个单词之间也许有多个空格，过滤掉多余的空格，只留下一个空格
*/
#include <iostream>    //预处理指令

using namespace std;

int main()
{
	int i, j, m = 0;
	char x, w[20099], n[99] = { 0 };
	for (;;)
	{
		while ((x = getchar()) != ' ' && (x !='\n'))
		{
			w[m * 100 + n[m]] = x;
			n[m]++;              //读入每个单词,长度为n[i]
		}
		if (n[m] > 0) m++;      //共有m个单词
		if (x == '\n') break;
	}


	for (i=0;i < m-1;i++)
	{
		for (j = 0;j < n[i];j++)
		{
			cout << w[i * 100 + j];
		}
		cout << " ";
	}                       //输出前m-1个单词以及之后的空格
	for (j = 0; j < n[m - 1]; j++)
		cout << w[100 * (m - 1) + j];    //输出最后一个单词
	return 0;    //程序结束
}

