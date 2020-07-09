/*
*程序名：模块化程序排序
*作者：何卓远
*编制时间：2018-11-16
*功能：请开发一个自上而下的模块化程序，用于完成以下任务
a)  读取两个整数数组，数组的元素未经排序。
b)  将数组元素按递增排序。
c)  将已排序的数组合并。
d)  显示已排序的列表。
使用函数来完成以上每个任务。主函数中只包含函数调用。
*/

#include <iostream>
#include <algorithm>

using namespace std;

bool compare(int a, int b)    //排序
{
	return a < b; //升序排列
}
void write(int z[], int x)  //输出
{
	for (int i = 0; i < x - 1; i++)
		cout << z[i] << ' ';
	cout << z[x - 1] << endl;
}
void hebing(int x[], int y[], int a, int b)   //合并
{
	int z[200];
	for (int i = 0; i < a; i++)
		z[i] = x[i];
	for (int i = 0; i < b; i++)
		z[i + a] = y[i];
	write(z, a + b);
}
void readin()      //读入
{
	int a, b;
	int x[100], y[100];
	cin >> a >> b;
	for (int i = 0; i < a; i++)
		cin >> x[i];
	for (int i = 0; i < b; i++)
		cin >> y[i];
	sort(y, y + b, compare);
	sort(x, x + a, compare);
	hebing(x, y, a, b);
}
int main()
{
	readin();
	return 0;
}