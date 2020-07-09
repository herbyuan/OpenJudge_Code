/*
*程序名：涂色
*作者：何卓远
*编制时间：2019-12-09
*功能：一条长为n的无色木板，你希望把它的n个单位长度分别涂上颜色。每次可以把一段连续的木板涂成一个给定的颜色，后涂的颜色覆盖先涂的颜色。为了达到给定的着色方案，最少要涂多少次？
例如目标为RGBGR，则最优的方案需要3次：第一次把木版涂成RRRRR，第二次涂成RGGGR，第三次涂成RGBGR。
*/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
#include <cstring>
using namespace std;
char str[100];
int n;
int dp[100][100];
int main()
{
    cin>>str;
    n = strlen(str);
    for (int i = 0; i < 10000; i++)
    {
        dp[0][i] = n;
    }
    for (int i = 0; i < 100; i++)
    {
        dp[i][i] = 1;
    }
    for (int j = 0; j<=n; j++)
    {
        for (int i = j - 1; i >= 0; i--)
        {
            //cout<<i<<' ' <<j<<endl;
            if (str[i] == str[j])
            {
                int Min = dp[i+1][j];
                if (dp[i][j - 1]<Min)
                    Min = dp[i][j - 1];
                if (dp[i+1][j - 1]+1<Min)
                    Min = dp[i+1][j - 1]+1;
                dp[i][j] = Min;
            }
            else
            {
                for (int k = i; k < j; ++k)
                {
                    if(dp[i][k] + dp[k+1][j]<dp[i][j])
                        dp[i][j] = dp[i][k] + dp[k+1][j];
                }
            }
        }
    }
    cout<<dp[0][n - 1]<<endl;
    return 0;
}