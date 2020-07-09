#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define INF 987654321
int a[22][22][22];
int f(int w, int h, int m)
{
    if (w * h < m + 1)
        return INF;
    if (m == 0)
        return w * h;
    if (a[w][h][m] != 0)
        return a[w][h][m];
    int ans = INF;
    for (int i = 1; i < w; ++i)
    {
        int t = INF;
        for (int k = 0; k < m; ++k)
        {
            t = min(t, max(f(i, h, k), f(w - i, h, m - 1 - k)));
        }
        if (t < ans)
            ans = t;
    }
    for (int i = 1; i < h; ++i)
    {
        int t = INF;
        for (int k = 0; k < m; ++k)
        {
            t = min(t, max(f(w, i, k), f(w, h - i, m - 1 - k)));
        }
        if (t < ans)
            ans = t;
    }
    a[w][h][m] = ans;
    return ans;
}
int main()
{
    int w, h, m;
    while(cin >> w >> h >> m && w)
    {
        memset(a, 0, sizeof(a));
        cout << f(w, h, m - 1) << endl;
    }
    return 0;
}

/*
#include<iostream>
using namespace std;
#define N 25
#define INF 5005
int f[N][N][N];
int w, h, m;
int main()
{
    w = h = m = 20;
    for(int i = 1; i <= w; i++)
    {
        for(int j = 1; j <= h; j++)
        {
            f[i][j][1] = i * j;
            for(int k = 2; k <= m; k++)
            {
                f[i][j][k] = INF;
                for(int r = 1; r < i; r++)
                {
                    f[i][j][k] = min(f[i][j][k], max(f[r][j][k - 1], (i - r) * j));
                    for(int p = 1; p < k; p++)
                        f[i][j][k] = min(f[i][j][k], max(f[r][j][p], f[i - r][j][k - p]));
                }

                for(int c = 1; c < j; c++)
                {
                    f[i][j][k] = min(f[i][j][k], max(f[i][c][k - 1], (j - c) * i));
                    for(int p = 1; p < k; p++)
                        f[i][j][k] = min(f[i][j][k], max(f[i][c][p], f[i][j - c][k - p]));
                }
            }
        }
    }
    while(scanf("%d%d%d", &w, &h, &m) && (w || h || m))
    {
        printf("%d\n", f[w][h][m]);
    }
    return 0;
}
*/