#include <iostream>
#include <cstring>
#include <map>
#include <queue>
using namespace std;
const int MAXN = 18;
int used[MAXN];
int W;
int m, n, ans = (1 << 30);
int item[MAXN];
int bag[MAXN];
void dfs(int k, int s)
{
    if(s >= ans)
        return;
    if(k == n)
    {
        ans = min(ans, s);
        return;
    }
    for (int i = 0; i < s; ++i)
    {
        if(bag[i] >= item[k])
        {
            bag[i] -= item[k];
            dfs(k + 1, s);
            bag[i] += item[k];
        }
    }
    bag[s] -= item[k];
    dfs(k + 1, s + 1);
    bag[s] += item[k];
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> item[i];
        bag[i] = m;
    }
    dfs(0, 1);
    cout << ans << endl;
    return 0;
}