#include <iostream>
#include<cmath>
#include <algorithm>//预处理指令

using namespace std;

bool compare1(int x, int y)
{
	return x < y; 
}      //升序排列

bool compare2(int x, int y)
{
	return x < y; 
}      //升序排列


int main()
{
	int  i = 1, j = 1, k, a[1000] = { 0 }, b[1000] = { 0 }, c[1000] = { 0 }, d[1000] = { 0 }, ans[1000] = { 0 };
	int i1 = 0, i2 = 0, num = 0;
	char x;
	cin >> a[0];
	while ((x=getchar()==','))
	{
		cin >> a[i];
		i++;
	}     //i是数组a中的元素个数
	sort(a, a + i, compare1);
	for (k = 1; k < i; k++)
	{
		if (a[k] != c[i1]) 
		{
			i1 = i1 + 1;
			c[i1] = a[k];
		}       //i1+1是新的元素个数
	}


	cin>>b[0];
	while ((x = getchar() == ','))
	{
		cin >> b[j];
		j++;
	}    //j是数组b中的元素个数
	sort(b, b + j, compare2);
	c[0] = a[0];
	d[0] = b[0];
	for (k = 1; k < j; k++)
	{
		if (b[k] != d[i2])
		{
			i2 = i2 + 1;
			d[i2] = b[k];
		}
	}        //i2+1是新的元素个数
	
    j=0;
	for (i = 0; i < i1 + 1; i++)
	{
		for (; j < i2 + 1; j++)
		{
			if (d[j] < c[i]) continue;
			if (d[j] == c[i])
				{
					ans[num] = c[i];
					num++;
					break;
				}
			if (d[j] > c[i]) 
				{
					j--; 
					break;
				}
		}
	}    //查找相同的数字,num是个数
	if (num == 0) cout << "NULL";
	else
	{
		cout << ans[0];
		for (i = 1; i < num; i++)
			if (ans[i]!=ans[i-1]) cout << ',' << ans[i];   //确认无重复后输出
	}



	return 0;    //程序结束
}

