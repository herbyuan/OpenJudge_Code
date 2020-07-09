/*
*程序名：排队游戏
*作者：何卓远
*编制时间：2018-12-07
*功能：根据老师的排队，按小女孩编号从小到大的顺序，给出所有手拉手离开队列的小男孩和小女孩的编号对。
*/
#include <iostream>
#include <cstring>
using namespace std;
char a[100]={0};
char x,y;
int lenth;
int func(int k)
{
	if (k > lenth) return 0; 
	int n;
	if (a[k] == x)
	{
		a[k] = '\0';      //标记以判断
		n = func(k+1);     //得到匹配的位置
		cout << k << " " << n << endl;
		return func(k+2);
	}
	if (a[k] == y)
	{
		a[k] = '\0';
		return k;        //直接返回该位置
	}
	return func(k+1);    //判断下一个
}
int main()
{
	cin.getline(a,100);
	lenth = strlen(a);
	x = a[0];
	for (int i = 0; ; i++)
	{
		if (a[i] != x)
		{
			y=a[i];
			break;
		}
	}           //得到两种不同的字符
	func(0);
	return 0;
}