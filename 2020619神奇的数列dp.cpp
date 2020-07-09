#include <iostream>
#include <cstring>
#include <map>
#include <queue>
#include <set>
using namespace std;
int n;
int a[210];
int dp[210][210];
int main()
{
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++)
    {
        memset(a, 0, sizeof(a));
        memset(dp, 1, sizeof(dp));
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i)
        {
            dp[i][i] = 1;
        }
        for (int j = 1; j < n; j++)
        {
            for(int i = j - 1; i >= 0; i--)
            {
                if(a[i] == a[j])
                {
                    int m = min(dp[i + 1][j], dp[i][j - 1]);
                    dp[i][j] = min(m, dp[i + 1][j - 1] + 1);
                }
                else
                {
                    for(int k = i; k < j; k++)
                    {
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
                    }
                }
            }
        }

        printf("Case %d: %d\n", t, dp[0][n - 1]);
    }
    return 0;
}