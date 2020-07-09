/*
*程序名：收费道路
*作者：何卓远
*编制时间：2018-12-24
*功能：一个由m条道路组成的网络连接着N个城市（编号为1到N）。不同城市之间可能有多条道路。其中有一些道路是收费的。对于一条从城市ai到城市bi的收费道路i，有两种方式付款： 
1、预先付款：在城市ci（ci可能和ai相同，也可能不同。也就是说，在通过从ai到bi的道路i之前，曾经经过城市ci，在那里预先把这段路费付清） 
2、之后付款：在城市bi（即通过这段道路i之后，在目的城市bi进行付款） 
第1种情况要付Pi元，第2种情况要付Ri元。其中Pi≤Ri。 
写一个程序寻找最低花费从城市1到城市N的路线。
输入的第1行包含整数N和m。接下来的m行每行都表示1条道路，给出了道路的5个值，ai，bi，ci，Pi，Ri (1 ≤ i ≤ m)，5个整数之间用一个或多个空格隔开。所有的值都是整数，1 ≤ m, N ≤ 10, 0 ≤ Pi , Ri ≤ 100, Pi ≤ Ri (1 ≤ i ≤ m)。
*/


#include <iostream>
using namespace std;
int N, m;    //N是城市数量，m是数据数量0
int a[100], b[100], c[100], P[100], R[100];    //用来存储m条数据
int route[100] = { 0 }, position[100] = { 0 };     //route[i]记录第i条路是否走过（1表示走过，0表示未走），position[i]表示第i个城市是否经过
int cost[100] = { 0 };         //cost[i]表示第i步的时候的花费
int MinCost = 9999999;     //记录最小花费
void caculate(int k, int i)
{
	if (position[c[i]])      //如果已经经过c[i]  这一步的花费是P[i]
		cost[k] = cost[k - 1] + P[i];   
	else cost[k] = cost[k - 1] + R[i];      //不然花费是R[i]
	//cout << "cost" << k << "=" << cost[k] << endl;
}

void try1(int n, int k)       //n是第k步在的城市
{
	if (n == N)
	{
		//cout << "n=" << n << " ";
		if (cost[k - 1] < MinCost)
			MinCost = cost[k - 1];      //如果到达了N，判断花费是不是最小
		//cout << "MinCost=" << MinCost << endl;
		return;
	}
	for (int i = 0; i < m; i++)
	{
		if (a[i] != n) continue;
		if (route[i]==3) continue;                   //搜寻路径中从n出发而且没有走过的道路
		
		//cout << "b[i]=" << b[i] << " ";
		caculate(k, i);          //计算到这里的花费
		route[i]++;
		position[b[i]]++;      //标记这条路和城市都已经到达
		try1(b[i], k+1);         //下一个点
		route[i]--;              
		position[b[i]]--;      //恢复这个点的情况
	}
}
int main()
{
	cin >> N >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a[i] >> b[i] >> c[i] >> P[i] >> R[i];
	}
	if (N == 1)
	{
		cout << "0" << endl;
		return 0;
	}
	position[1] = 1;   //标出1是不可返回的
	try1(1, 1);     //从1出发走第1步
	if (MinCost == 9999999) cout << "impossible" << endl;    //从来没有到过N
	else cout << MinCost << endl;
	return 0;
}



/*
Test Data
4 5
1 2 1 10 10
2 3 1 30 50
3 4 3 80 80
2 1 2 10 10
1 3 2 10 50

Std Output : 110
*/