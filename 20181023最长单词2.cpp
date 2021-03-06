/*
*程序名：最长单词2
*作者：何卓远
*编制时间：2018-10-23
*功能：输入一个以'.'结尾的简单英文句子，单词之间用空格分隔，没有缩写形式和其它特殊形式；输出该句子中最长的单词。

*/
#include <iostream>      //预处理指令

using namespace std;

int main()
{
	char x, s[100],m[100];
	int max=0, i, j, n;
	for (j=1; ; )
	{
		n = 1;
		while (((x=getchar()) != ' ') &&(x != '.'))
		{
			s[n] = x;          //将单词读入字符串s
			n++;             //计算长度为（n-1）
		}
		if (n>max) 
		{
			max = n;
			for (i = 1; i < n; i++)
			{
				m[i] = s[i];
			}
		}                   //保证m里是最长的，max-1是长度
		if (x == '.') break;
	}
	for (i = 1; i < max; i++)
	{
		cout << m[i];
	}                      //输出

	return 0;    //程序结束
}

