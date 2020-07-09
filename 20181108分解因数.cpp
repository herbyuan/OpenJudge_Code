/*
*程序名：分解因数
*作者：何卓远
*编制时间：2018-11-08
*功能：给出一个正整数a，要求分解成若干个正整数的乘积，即a = a1 * a2 * a3 * ... * an，并且1 < a1 <= a2 <= a3 <= ... <= an，问这样的分解的种数有多少。注意到a = a也是一种分解。

*/

#include <iostream> 
#include <cmath>      //预处理指令

using namespace std;
int f(int n, int b)
{
	int i, j;
	if (n == 1) return 1;   //终止点
	else
	{
		j = 0;
		for (i = b; i <= n; i++)
		{
			if (n % i == 0)    //符合条件的因数
			 	j += f(n / i, i);
		}
		return j;     //j是计数器
	}       
}       //f函数是计算n从b开始的因数积的个数
int main()
{
	int n, a, i;
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> a;
		cout << f(a,2) << endl;
	}

	return 0; //程序结束
}