/*
*程序名：下楼问题(回溯)
*作者：何卓远
*编制时间：2018-11-24
*功能：从楼上走到楼下共有h个台阶，每一步有3种走法：走1个台阶；走2个台阶；走3个台阶。问可以有多少种方案？并将所有的方案输出
*/
#include <iostream>
using namespace std;
int take[99];
int Num = 0;
void Try(int i, int s)
{
	int j,k;
	for (j = 3; j > 0; j--)       //枚举第s步走的台阶数
	{ 
		if (i<j) continue;      //不够走
		else 
		{
			take[s]=j;
			if (i == j)     //走到头
			{
				Num++;
				cout<<"Solution"<<Num<<':';
				for (k = 1; k <= s; k++)
					cout<<take[k];
				cout<<endl;
			}
			else Try(i-j, s+1);     //继续走
		}        //每一次函数结束都回溯到调用函数的for循环中
	}
}
int main()
{
	int h;
	cin >> h;   //台阶数量
	Try(h,1);
	return 0;
}