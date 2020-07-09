#include <stdio.h>
#include <stdlib.h>
int l = 0;
void print(char result[], int width)
{
	for (int i = l - 1; i >= 0; i--)
		printf("%c", result[i]);
	for (int i = 0; i < width - l; i++)
		printf(" ");
}
void transform(int n, int x, char result[])
{
	int temp, m = 0;
	l = 0;
	if (n == 0)
	{
		result[0] = '0';
		l++;
	}
	while (n)
	{
		l++;
		temp = n % x;
		n /= x;
		if (temp < 10)result[m++] = temp + '0';
		else if (temp >= 10)
			result[m++] = temp - 10 + 'A';         //result存储转换之后的数
	}
	
}

int main()
{
	int width;
	printf ("Pleast input width:");
	scanf ("%d",&width);
	printf ("十进制");
	for (int i = 0; i < width - 6; i++)
		printf(" ");
	printf("二进制");
	for (int i = 0; i < width - 6; i++)
		printf(" ");
	printf("七进制");
	for (int i = 0; i < width - 6; i++)
		printf(" ");
	printf("八进制");
	for (int i = 0; i < width - 6; i++)
		printf(" ");
	printf("十六进制");
	printf ("\n");
	int i;
	char result[20] = { 0 };
	for (i = 1; i <= 256; i++)
	{
		transform(i, 10, result);
		print(result, width);
		transform(i, 2, result);
		print(result, width);
		transform(i, 7, result);
		print(result, width);
		transform(i, 8, result);
		print(result, width);
		transform(i, 16, result);
		print(result, width);
		printf("\n");
	}
	return 0;
}