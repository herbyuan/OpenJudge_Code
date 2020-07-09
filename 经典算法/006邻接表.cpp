#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int K, N, R;
struct Node
{
    int S, D, L, T;
    Node(int s, int d, int l, int t)
    {
        S = s;
        D = d;
        L = l;
        T = t;
    }
};
int m = 1 << 30;
vector<Node> v[110];
int vis[110] = {0};
int minl[110][10100];
void dfs(int s, int c, int l)
{
    if (c > K || l >= m)
        return;
    if (minl[s][c] <= l)
    {
        return;
    } 
    if (s == N)
    {
        if (l < m)
            m = l;
        return;
    }
    minl[s][c] = l;
    int size = v[s].size();
    for (int i = 0; i < size; ++i)
    {
        if (!vis[v[s][i].D])
        {
            vis[v[s][i].D] = 1;
            dfs(v[s][i].D, c + v[s][i].T, l + v[s][i].L);
            vis[v[s][i].D] = 0;
        }
    }

}
int main()
{
    for (int i = 0; i < 110; ++i)
    {
        for (int j = 0; j < 10100; ++j)
        {
            minl[i][j] = (1 << 30);
        }
    }
    int s, d, l, t;
    cin >> K >> N >> R;
    for (int i = 0; i < R; ++i)
    {
        scanf("%d%d%d%d", &s, &d, &l, &t);
        if (s != d)
            v[s].push_back(Node(s, d, l, t));
    }
    dfs(1, 0, 0);
    if (m == 1 << 30)
        cout << "-1\n";
    else
        cout << m << endl;
    return 0;
}
