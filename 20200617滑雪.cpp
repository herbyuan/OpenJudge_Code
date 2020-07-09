#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
class Node
{
public:
    int x, y, h;
    bool operator <(Node t) const
    {
        return h < t.h;
    }
};
Node n[10010];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int main()
{
    int r, c;
    int a[110][110];
    cin >> r >> c;
    int cnt = 0;
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            cin >> a[i][j];
            n[cnt].x = i;
            n[cnt].y = j;
            n[cnt++].h = a[i][j];
        }
    }
    sort(n, n + cnt);
    int s[110][110];
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            s[i][j] = 1;
        }
    }
    for (int i = 0; i < cnt; ++i)
    {
        int x = n[i].x;
        int y = n[i].y;
        for (int j = 0; j < 4; ++j)
        {
            int tx = x + dx[j];
            int ty = y + dy[j];
            if (tx >= 0 && ty >= 0 && tx < r && ty < c && a[tx][ty] > a[x][y])
            {
                s[tx][ty] = max(s[tx][ty], 1 + s[x][y]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            if (s[i][j] > ans)
                ans = s[i][j];
        }
    }
    cout << ans << endl;
    return 0;
}
