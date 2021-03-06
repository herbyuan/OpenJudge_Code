/*
*程序名：距离排序
*作者：何卓远
*编制时间：2018-10-19
*功能：给出三维空间中的n个点（不超过10个）,求出n个点两两之间的距离,并按距离由大到小依次输出两个点的坐标及它们之间的距离。
*/
#include <iostream>
#include<cmath>
#include <algorithm>
#include<iomanip>       //预处理指令

using namespace std;

bool compare(float a, float b)
{
	return a > b; 
}

int main()
{
	int x[11] = { 0 }, y[11] = { 0 }, z[11] = { 0 }, n, i, j, k, a, b, c;
	float  d[100] = { 0 }, e[100] = { 0 };    //x,y,z分别是三个坐标
	cin >> n;
	for(i = 0;i < n;i++)
	{
		cin >> a >> b >> c;
		x[i] = a;
		y[i] = b;
		z[i] = c;
	}              //读入坐标到数组
	for (i = 0;i < n-1;i++)
	{
		for (j = i + 1;j < n;j++)
		{
			e[10 * i + j]=d[10 * i + j] = float(sqrt((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]) + (z[i] - z[j])*(z[i] - z[j])));
		}                         //计算距离
		             
	}
	sort(d, d + 100, compare);     //距离排序
	for (k = 0; k < 99; k++)
	{
		for (i = 0; i < k; i++)
		{if (d[i] == d[k]) d[k] = 0;
	    }
	}                          //去掉相同距离

	for (k = 0; k < 99; k++)
	{
		for (i = 0; i < n-1; i++)
		{
			for (j = i + 1; j < n; j++)
			{
				if (d[k] == e[10 * i + j])
				{
					cout << "(" << x[i] << "," << y[i] << "," << z[i] << ")-("
						<< x[j] << "," << y[j] << "," << z[j] << ")=" << fixed << setprecision(2) <<d[k] << endl;      //输出
				}
			}
		}

	}

	return 0;    //程序结束
}

