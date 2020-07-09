#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int r, c;
int a[60][60];
int b[60][60];
int cnt = 0;
int m = 0;
int t = 0;
void dfs(int x, int y)
{
    b[x][y] = 1;
    if ((a[x][y] & (1 << 0)) == 0 && b[x][y - 1] == 0)
    {
        t++;
        dfs(x, y - 1);
    }
    if ((a[x][y] & (1 << 1)) == 0 && b[x - 1][y] == 0)
    {
        t++;
        dfs(x - 1, y);
    }
    if ((a[x][y] & (1 << 2)) == 0 && b[x][y + 1] == 0)
    {
        t++;
        dfs(x, y + 1);
    }
    if ((a[x][y] & (1 << 3)) == 0 && b[x + 1][y] == 0)
    {
        t++;
        dfs(x + 1, y);
    }
    if (t > m)
        m = t;
}
int main()
{
    cin >> r >> c;
    for (int i = 1; i <= r; ++i)
    {
        for (int j = 1; j <= c; ++j)
        {
            cin >> a[i][j];
        }
    }
    memset(b, 0, sizeof(b));
    for (int i = 1; i <= r; ++i)
    {
        for (int j = 1; j <= c; ++j)
        {
            if (b[i][j] == 0)
            {
                cnt++;
                t = 1;
                dfs(i, j);
            }
        }
    }
    cout << cnt << endl;
    cout<<m<<endl;
    return 0;
}
