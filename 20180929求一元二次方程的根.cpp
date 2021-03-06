/*
*程序名：求一元二次方程的根
*作者：何卓远
*编制时间：2018-
*功能：求一元二次方程的根

*/
#include <iostream>
#include<cmath>
#include<iomanip>  //预处理指令

using namespace std;

int main()
{
	double x1, x2, a, b, c, d ;
	int n,i;                         //变量声明
	i = 1;
	
		while (cin >> a >> b >> c)
		{
		if ((b*b - 4 * a*c) > 0)                 //判断delta
		{
			x1 = (-b + sqrt(b*b - 4 * a*c)) / (2 * a);
			x2 = (-b - sqrt(b*b - 4 * a*c)) / (2 * a);
			if (x1>x2)
			cout << "x1=" << fixed << setprecision(5) << x1 << ";x2=" << fixed << setprecision(5) << x2 << endl;
			else cout << "x1=" << fixed << setprecision(5) << x2 << ";x2=" << fixed << setprecision(5) << x1 << endl;

		}
		else if ((b*b - 4 * a*c) == 0)               //判断delta
		{
			x1 = -b / (2 * a);
			x2 = x1;
			cout << "x1=x2=" << fixed << setprecision(5) << x1 << endl;
		}
		else {                                 //判断delta
			cout<< "no solution" << endl;
		      }
	     }          //输出
           
	return 0;   //程序结束
}

