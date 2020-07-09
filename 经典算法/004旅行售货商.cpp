#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
// 从1号点到N点最短路
int N,a[20][20];
int dp[20][1<<16];
int dfs(int k,int l)
{
    if(k == 1 && l != 1)
    {
        return dp[k][l];
    }
    if(dp[k][l] != 1 << 30)
        return dp[k][l];
    for (int i = 1; i < N; ++i)
    {
        if(i == k)
            continue;
        if(l & (1 << (i - 1)))
        {
            dp[k][l] = min(dp[k][l], dfs(i,l - (1 << (k - 1))) + a[i][k]);
        }
    }
    return dp[k][l];
}
int main()
{
    cin>>N;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            cin>>a[i][j];
        }
    }
    for (int i = 0; i < 20; ++i)
    {
        for (int j = 0; j < (1 << 16); ++j)
        {
            dp[i][j] = 1 << 30;
        }
    }
    dp[1][1] = 0;
    dfs(N,(1 << N) - 1);
    cout<<dp[N][(1 << N) - 1]<<endl;
    return 0;
}
