/*
*程序名：角谷猜想
*作者：何卓远
*编制时间：2018-11-16
*功能：所谓角谷猜想，是指对于任意一个正整数，如果是奇数，则乘3加1，如果是偶数，则除以2，得到的结果再按照上述规则重复处理，最终总能够得到1。如，假定初始整数为5，计算过程分别为16、8、4、2、1。 
程序要求输入一个整数，将经过处理得到1的过程输出来。
*/

#include <iostream>

using namespace std;

int jg(int i)
{
	if (i == 1) 
		{
			cout << "End" << endl;
			return 0;
		}
	int a;
	if (i % 2 ==1) 
		{
			a = 3 * i + 1;
			cout << i << "*3+1=" << a << endl;
			return jg(a);
		}
	else 
		{
			a = i / 2;
	    	cout << i << "/2=" << a << endl;
	    	return jg(a);
	    }    
}

int main()
{
	int n;
	cin >> n;
	jg(n);
	return 0;
}