/*
*程序名：旅行售货商问题
*作者：何卓远
*编制时间：2018-12-09
*功能：一个国家有 n 个城市，每两个城市之间都开设有航班，从城市 i 到城市 j 的航班价格为 cost[i, j] ，而且往、返航班的价格相同。 

售货商要从一个城市出发，途径每个城市 1 次（且每个城市只能经过 1 次），最终返回出发地，而且他的交通工具只有航班，请求出他旅行的最小开销。
*/

#include <iostream>
#include <cstring>
using namespace std;
int a[16][16] = { 0 }, via[16] = { 0 };
int mini = 999999, n;
void adjust(int k,int cost)
{
	if (cost >= mini - n + k) return;
	if (k == n)
	{
		cost += a[via[k - 1]][0];
		if (cost < mini) mini = cost;
		return;
	}        //计算并且判断最小值
	
	for (int i = 1; i < n; i++)
	{
		via[k] = i;
		int t = 0;
		for (int j = 0; j < k; j++)       //假设从0出发
		{
			t += (via[k] == via[j]);
		}
		if (t != 0) continue;    //如果重复就退回
		adjust(k + 1, cost + a[via[k-1]][via[k]]);     //下一行
	}
}
int main()
{
	scanf("%d", &n);
	int i;
	for (i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d,",&a[i][j]);
		}
	}
	for (i = 1; i < n - 1; i++)
	{
		via[1] = i;
		adjust(2, a[0][i]);
	}           
	//从第二个数开始处理，且不用讨论最后一个数（因为循环逆序和正序结果相同）
	//若果用adjust(0,1)多用1/n的时间
	printf("%d\n", mini);
	return 0;
}