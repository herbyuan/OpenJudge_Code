/*
*程序名：二叉树
*作者：何卓远
*编制时间：2018-11-08
*功能：计算二叉树中两个数对应相同的最后一个树杈。
*/

#include <iostream> 
#include <cmath>//预处理指令

using namespace std;
int min(int a, int b)
{
	if (a < b) return a;
	else return b;
}
int main()
{
	int x, y, i, j, r1 = 0, r2 = 0, ans = 0;
	int a[20] = { 0 }, b[20] = { 0 };
	cin >> x >> y;
	for (i = 1; i <= 11; i++)
	{
		if (int(x / (pow(2.0, i))) == 0)
		{
			r1 = i;
			break;
		}
	}
	for (i = 1; i <= 11; i++)
	{
		if (int(y / (pow(2.0, i))) == 0)
		{
			r2 = i;
			break;
		}
	}              //r1,r2是x，y对应二叉树的阶数
	for (i = 1; i <=r1; i++)
	{
		a[i] = x / (int)pow(2.0, r1 - i);
		x %= int(pow(2.0, r1 - i));     //a[i]存储第i+1层在哪个位置
	}
	for (i = 1; i <= r2; i++)
	{
		b[i] = y / (int)pow(2.0, r2 - i); 
		y %= int(pow(2.0, r2 - i));     //b[i]存储第i+1层在哪个位置
	}
	for (i = 1; i <= min(r1, r2); )
	{
		if (a[i] != b[i]) break;
		i++;
	}                      //对比每一层是否相同,结果是a[i]开始不同
	for (j = 1; j < i; j++)
	{
		ans += a[j] * int(pow(2.0, i-j-1));
	}         //求相同位置对应的数
	cout << ans;
	return 0; //程序结束
}
