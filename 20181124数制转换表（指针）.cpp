/*
*程序名：
*作者：何卓远
*编制时间：2018-12-
*功能：
*/

#include <stdio.h>
#include <string.h>
int width;
void print(char result[], int width)
{
	for (int i = width - 1; i >= 0; i--)
	{
		printf("%c", result[i]);
	}
	if (width > 7)
		printf("\t");
	else
		printf("\t\t");
}
void transform(int n, int x, char * result)
{
	int temp, m = 0;
	width = 0;
	while (n)
	{
		width++;
		temp = n % x;
		n /= x;
		if (temp < 10) 
			*(result + m++) = temp + '0';
		else if (temp >= 10)
			*(result + m++) = temp - 10 + 'A';         //result存储转换之后的数
	}
}

int main()
{
	printf("十进制\t\t二进制\t\t七进制\t\t八进制\t\t十六进制");
	printf("\n");
	int i;
	char result[20] = { 0 };
	for (i = 1; i <= 256; i++)
	{
		transform(i, 10, result);
		print(result, width);
		memset(result, 0, sizeof(result));
		transform(i, 2, result);
		print(result, width);
		memset(result, 0, sizeof(result));
		transform(i, 7, result);
		print(result, width);
		memset(result, 0, sizeof(result));
		transform(i, 8, result);
		print(result, width);
		memset(result, 0, sizeof(result));
		transform(i, 16, result);
		print(result, width);
		memset(result, 0, sizeof(result));
		printf("\n");
	}
	return 0;
}