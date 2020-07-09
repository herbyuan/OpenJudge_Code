/*
*程序名：多边形游戏（递归法）
*作者：何卓远
*编制时间：2018-11-24
*功能：一个多边形，开始有n个顶点。每个顶点被赋予一个正整数值，每条边被赋予一个运算符“+”或“*”。
所有边依次用整数从1到n编号。
现在来玩一个游戏，该游戏共有n步：第1步，选择一条边，将其删除；
随后n-1步，每一步都按以下方式操作：
（1）选择一条边E以及由E连接着的2个顶点v1和v2；
 (2）用一个新的顶点取代边E以及由E连接着的2个顶点v1和v2，将顶点v1和v2的整数值通过边E上的运算得到的结果值赋给新顶点。
 最后，所有边都被删除，只剩一个顶点，游戏结束。
 游戏得分就是所剩顶点上的整数值。
 求出最大分数。
*/

#include <iostream>
using namespace std;
int v[20];    //0表示无效
char e[20];
int vn;   //初始定点数
int dbx(int n)
{
	if (n == 1)   //递归边界
		for (int i = 0; i < vn; i++)    //返回有效顶点值
			if (v[i] != 0) return v[i];
	int max = 0;
	for (int i = 0; i < vn; i++)      //穷举定点合并
	{
		if (v[i] != 0)      //找到一个有效顶点
		{
			int j, vi = v[i], vj;
			for (j = i + 1; j != i; j++)
			{
				if (j == vn) j = 0;      //到达末尾
				if (v[j] != 0) break;      //找到下一个相邻顶点
			}
			vj = v[j];     //保留当前顶点值用于回溯
			if (e[i] == '+') v[j] = v[i] + v[j];
			else v[j] = v[i] * v[j];
			v[i] = 0;      //前一个顶点改为0完成合并
			int nextMax = dbx(n - 1);    //递归
			if (max < nextMax) max = nextMax;
			v[i] = vi;      //回溯需要还原合并的顶点
			v[j] = vj;
		}      //结束当前的顶点合并，尝试下一对
	}
	return max;
}
int main()
{
	cin >> vn;
	for (int i = 0; i < vn; i++)
		cin >> v[i] >> e[i];
	cout << dbx(vn);
	return 0;
}