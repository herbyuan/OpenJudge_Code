#include <iostream>
using namespace std;
int main()
{
    int n, x;
    cin >> n >> x;
    int a[10010] = {0};
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    int dp[10010] = {0};
    dp[0] = 1;
    for (int i = 1; i < n + 1; ++i)
    {
        for(int j = x; j >= a[i]; j--)
        {
            dp[j] = dp[j] + dp[j - a[i]];
        }
    }
    int g[10010] = {0};
    int cnt = 0;
    int ans[10010];
    for (int i = 1; i < n + 1; ++i)
    {
        for (int j = 0; j < x + 1; ++j)
        {
            if(j < a[i])
                g[j] = dp[j];
            else
            {
                g[j] = dp[j] - g[j - a[i]];
            }
        }
        if(dp[x] == g[x - a[i]])
            ans[cnt++] = a[i];
    }
    if(cnt == 0)
    {
        cout << cnt << endl;
    }
    else
    {
        cout << cnt << endl;
        for (int i = 0; i < cnt; ++i)
        {
            cout << ans[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}