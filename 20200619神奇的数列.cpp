#include <iostream>
#include <cstring>
#include <map>
#include <queue>
#include <set>
using namespace std;

int f[210][210], g[210];
int h, i, j, k, n, t;

int main()
{
    cin>>t;
    for (h = 1; h <= t; h++)
    {
        cin>>n;
        for (i = 1; i <= n; i++)
            cin>>g[i];
        memset(f, 1, sizeof(f));
        for (i = n; i > 0; i--)
        {
            f[i][i - 1] = 0, f[i][i] = 1;
            for (j = i + 1; j <= n; j++)
                for (k = i; k < j; k++)
                    if (g[j] == g[k])
                        f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j - 1]);
                    else
                        f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j]);
        }
        printf("Case %d: %d\n", h, f[1][n]);
    }
    return 0;
}