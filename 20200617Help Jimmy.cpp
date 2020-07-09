#include <iostream>
#include <cstring>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
#define INF 987654321
struct plate
{
    int L;
    int R;
    int H;
    int t1 = 0;
    int t2 = 0;
    bool operator < (plate t)
    {
        return H > t.H;
    }
};
plate p[1010];
int n, x, y, m;
int f(int x, int h)
{
    int ans;
    for (int i = 0; i < n; ++i)
    {
        if (p[i].H < h && p[i].L <= x && x <= p[i].R)
        {
            if (h - p[i].H <= m)
            {
                ans = h - p[i].H;
                if(p[i].t1 == 0)
                    p[i].t1 = f(p[i].L, p[i].H);
                if(p[i].t2 == 0)
                    p[i].t2 = f(p[i].R, p[i].H);
                ans += min(x - p[i].L + p[i].t1, p[i].R - x + p[i].t2);
                return ans;
            }
            return INF;
        }
    }
    if (h <= m)
        return h;
    else
        return INF;
}
int main()
{
    int T;
    cin >> T;
    while(T--)
    {

        cin >> n >> x >> y >> m;
        memset(p, 0, sizeof(p));
        for (int i = 0; i < n; ++i)
        {
            cin >> p[i].L >> p[i].R >> p[i].H;
        }
        sort(p, p + n);
        cout << f(x, y) << endl;
    }
    return 0;
}