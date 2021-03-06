/*
*程序名：单词倒排
*作者：何卓远
*编制时间：2018-10-23
*功能：编写程序，读入一段英文(英文中不包含标点)，将所有单词的顺序倒排并输出，其中单词以空格分隔。
*/
#include <iostream>    //预处理指令

using namespace std;

int main()
{
	int i, j, m = 0;
	char x, w[20099], n[99] = { 0 };
	for (;;)
	{
		while ((x = getchar()) != ' ' && (x != '\n'))
		{
			w[m * 100 + n[m]] = x;
			n[m]++;              //读入每个单词,长度为n[i]
		}
		if (n[m] > 0) m++;      //共有m个单词
		if (x == '\n') break;
	}


	for (i = m-1; i >0; i--)     //倒着输出
	{
		for (j = 0; j < n[i]; j++)
		{
			cout << w[i * 100 + j];
		}
		cout << " ";
	}                       //输出前m-1个单词以及之后的空格
	for (j = 0; j < n[0]; j++)
		cout << w[j];    //输出最后一个单词
	return 0;    //程序结束
}


