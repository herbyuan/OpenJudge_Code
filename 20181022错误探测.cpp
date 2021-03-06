/*
*程序名：错误探测
*作者：何卓远
*编制时间：2018-10-22
*功能：给出由0和1组成的矩阵，如果矩阵的每一行和每一列的1的数量都是偶数，则认为符合条件。 
你的任务就是检测矩阵是否符合条件，或者在仅改变一个矩阵元素的情况下能否符合条件。 
"改变矩阵元素"的操作定义为0变成1，1变成0。
*/


#include <iostream>    //预处理指令

using namespace std;

int main()
{
	int n, i, j, k, x, y, Changex, Changey;       //n是阶数 ijk循环变量 change是要更改的行列
	bool heng, shu;               //判断行列是否符合条件
	int h[100] = { 0 }, v[100] = { 0 }, a[100] = { 0 };    //h，v是各行列1的个数，a是循环过程中读入的一行数据
	for (;;)         //开始循环
	{
		cin >> n; 
		if (n == 0) break;     //只有n=0才停止
		else                
		{
			for (i = 1; i < 100; i++)
			{
				h[i] = 0; v[i] = 0;
			}
			for (j = 1; j <= n; j++)
			{
				for (k = 1; k <= n; k++)    
				{
					cin >> x;      
					a[k] = x;      //每个行读n个数据
					v[k] = v[k] + a[k];     //求各列1的个数
					h[j] = h[j] + a[k];     //求各行1的个数
				}
			}

			x = y = 0;
			heng = shu = true;
			for (j = 1; j <= n; j++)
			{
				
				if (h[j] % 2 != 0) { heng = false; x++; Changex = j; }
				if (v[j] % 2 != 0) { shu = false; y++; Changey = j; }
			}
			//对各行列进行判断，得到不符合的数量
			if (heng & shu) cout << "OK" << endl;
			else 
			{
				if ((x == 1) & (y == 1))
					cout << "Change bit (" << Changex << "," << Changey << ")" << endl;    //仅需改一个数的情况
				else cout << "Corrupt" << endl;
			}
		
		}
	
	}
	return 0;   //程序结束
}

