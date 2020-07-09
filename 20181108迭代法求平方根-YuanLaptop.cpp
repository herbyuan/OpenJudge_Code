/*
*程序名：迭代法求平方根
*作者：何卓远
*编制时间：2018-12-24
*功能：根据级数运算，一个数的平方根能用如下公式表示： 
sqrt(a) = lim f(n) 
          n趋向∞ 
其中，f(n) 是一个递推函数，其递推式如下：f(n+1)= 0.5*(f(n)+a/f(n)) 
显然，迭代的次数越多，求出的值就越精确。 
对于一个给定的实数 a，请用上述方法求出它的平方根。 
要求前后两次迭代出的 f(n) 的差的绝对值小于等于 1E-5 方可终止。

*/

#include <iostream> 
#include <cmath>
#include <iomanip>//预处理指令

using namespace std;

int main()
{
	double a, ans, f;
	cin >> a;
	f = 1;
	for (;;)
	{
		if (abs(0.5*(f + a / f) - f) <= 1E-5) break;
		else f = 0.5*(f + a / f);
	}
	ans = f;
	cout << fixed << setprecision(7) << ans << endl;
	return 0; //程序结束
}