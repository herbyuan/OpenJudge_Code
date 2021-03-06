/*
*程序名：谁考了第k名
*作者：何卓远
*编制时间：2018-10-19
*功能：在一次考试中，每个学生的成绩都不相同，现知道了每个学生的学号和成绩，求考第k名学生的学号和成绩。

*/
#include <iostream>
#include <algorithm>
#include<cmath>          //预处理指令

using namespace std;

bool compare(float a, float b)
{
	return a > b; 
}     //排序

int main()
{
	int xueh, i, n, k, a[101] = { 0 };
	float b[101] = { 0 }, c[101] = { 0 }, grade;
	cin >> n >> k;
	
		for (i = 1; i <= n; i++)
		{
			cin >> xueh >> grade;
			a[i] = xueh;
			b[i] = grade;
			c[i] = grade;
		}           //读入
		sort(b, b + 101, compare);    //排序
		for (i = 0; i <= 100; i++)
		{
			if (c[i] != b[k - 1]) continue;
			else cout << a[i] << " " << c[i];
		}                //如果第i个人是第k名 输出
		return 0;    //程序结束
	
}

