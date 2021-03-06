/*
*程序名：连续分数求和
*作者：何卓远
*编制时间：2019-10-09
*功能：给定正整数n（1 < n < 10000），求S=1 + 1/2 + 1/3 + ... + 1/n

*/
#include <iostream>
#include<cmath>
#include <iomanip>//预处理指令

using namespace std;

int main()
{
    int n;             //定义变量
    cin >> n;
    double s = 0;
    for (double i = 1; i <= n; i++)
    {
        s += 1/i;
    }
    cout << fixed << setprecision(9) << s << endl;
    return 0;    //程序结束
}

