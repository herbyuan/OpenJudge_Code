#include <iostream>
#include <cstring>
using namespace std;
int dp[13000];
int main()
{
    int n, m;
    cin >> n >> m;
    int w[3500] = {0}, d[3500] = {0};
    for (int i = 1; i <= n; ++i)
    {
        cin >> w[i] >> d[i];
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = m; j >= 1; j--)
        {
            if (j - w[i] >= 0)
                dp[j] = max(dp[j], dp[j - w[i]] + d[i]);
            else
                dp[j] = dp[j];
        }
    }
    cout << dp[m] << endl;

    return 0;
}

/*
#include <iostream>
#include <cstring>
using namespace std;
int dp[3500][13000];
int main()
{
    int n, m;
    cin >> n >> m;
    int w[3500] = {0}, d[3500] = {0};
    for (int i = 1; i <= n; ++i)
    {
        cin >> w[i] >> d[i];
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (j - w[i] >= 0)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + d[i]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[n][m] << endl;

    return 0;
}

*/