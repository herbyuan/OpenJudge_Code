/*
*程序名：称体重
*作者：何卓远
*编制时间：2018-10-11
*功能：编写一个程序，按照由大到小的顺序，打印出四人的姓氏的首字母和体重数
*/
#include <iostream>
#include<cmath>		//预处理指令

using namespace std;

int main()
{
	int z, q, s, l;                      //存放四人体重
	int a, b, c, d;                     //四人体重
	for (z=10;z<=50;z=z+10)
	{
		for (q = 10;q<=50;q=q+10)
		{
			for (s = 10;s<=50;s=s+10)
			{
				for (l = 10;l<=50;l=l+10)    //开始穷举
				{if(((z+q) ==(s+l)) && ((z+l)>(s+q))
					&& ((z+s)<q) && (z!=q) && (z!=s) && (z!=l)
				    && (q!=s) && (q!=l) && (s!=l))                 //条件
				   {
					a = z;
					b = q;
					c = s;
					d = l;
				    }                                   //得到四人体重存放在abcd
				}
			}
		}
	}
	//以下开始对四人体重排序，全部采用假设条件，如果满足就换行输出
	if ((a > b) && (a > c) && (a >> d))
	{
		cout << "z " << a << endl;
		if ((b > c) && (b > d))
		{
			cout << "q " << b << endl;
			if (c > d)  cout << "s " << c << endl << "l " << d << endl;
			else  cout << "l " << d << endl << "s " << c << endl;
		}
		else if ((c > d) && (c > b))
		{
			cout << "s " << c << endl;
			if (b > d) cout << "q " << b << endl << "l " << d << endl;
			else cout << "l " << d << endl << "q " << b << endl;
		}
		else
		{
			cout << "l " << d << endl;
			if (b > c) cout << "q " << b << endl << "s " << c << endl;
			else cout << "s " << c << endl << "q " << b << endl;
		}
	}
	else if ((b > c) && (b > d))
	{
		cout << "q " << b << endl;
		if ((c>a)&&(c>d))
		{
			cout << "s " << c << endl;
			if (a > d) cout << "z " << a << endl << "l " << d << endl;
			else cout << "l " << d << endl << "z " << a << endl;
		}
		else
		{
			cout << "l " << d << endl;
			if (a>c) cout<< "z " << a << endl<< "s " << c << endl;
			else cout << "s " << c << endl << "z " << a << endl;
		}
	}

	else if (c > d)
	{
		cout << "s " << c << endl;
		if ((a>b)&&(a>d)) 
		{
			cout << "z " << a << endl;
			if (b > d) cout << "q " << b << endl << "l " << d << endl;
			else cout << "l " << d << endl << "q " << b << endl;
		}
		else if (b>d)
		{
			cout << "q " << b << endl;
			if (a > d) cout << "z " << a << endl << "l " << d << endl;
			else cout << "l " << d << endl<< "z " << a << endl;
		}
		else
		{
			cout << "l " << d << endl;
			if (a > b) cout << "z " << a << endl << "q " << b << endl;
			else cout << "q " << b << endl << "z " << a << endl;
		}
	}

	else
	{
		cout << "l " << d << endl;
		if ((a>b)&&(a>c))
		{
			cout << "z " << a << endl;
			if (b > c) cout << "q " << b << endl << "s " << c << endl;
			else cout << "s " << c << endl << "q " << b << endl;
		}
		else if (b>c)
		{
			cout << "q " << b << endl;
			if (a > c) cout << "z " << a << endl << "s " << c << endl;
			else cout << "s " << c << endl << "z " << a << endl;
		}
		else 
		{
			cout << "s " << c << endl;
			if (a > b) cout << "z " << a << endl << "q " << b << endl;
			else cout << "q " << b << endl<< "z " << a << endl;
		}
	}
	
	return 0;    //程序结束
}

