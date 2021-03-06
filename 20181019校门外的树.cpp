/*
*程序名：校门外的树
*作者：何卓远
*编制时间：2018-10-19
*功能：计算将这些树都移走后，马路上还有多少棵树

*/
#include <iostream>
#include<cmath>          //预处理指令

using namespace std;

int main()
{
	int L, M, num;
	int i, j;
	int m, n;
	bool tree[10001];
	cin >> L >> M;
	for (i = 0; i <= L; i++)
		tree[i] = true;       //全部位置有树
	for (i=1;i<=M;i++)
	{
		cin >> m >> n;
		for (j=m;j<=n;j++)
		{
			tree[j] = false;     //范围内记为没有树
		}
	}
	num = 0;
	for (i=0;i <= L;i++)
	{
		if (tree[i] == true) num++;    //统计树
	}
	cout << num;   //输出
	return 0;    //程序结束
}

