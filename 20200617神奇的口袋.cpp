#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int a[50], n;
    int w[50][40];
    memset(w, 0, sizeof(w));
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        w[0][i] = 1;
    }
    w[0][0] = 1;
    for (int i = 1; i <= 40; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            w[i][j] = w[i][j - 1];
            if (i - a[j] >= 0)
            {
                w[i][j] += w[i - a[j]][j - 1];
            }
        }
    }
    cout << w[40][n] << endl;

    return 0;
}



/*
#include <iostream>
#include <cstring>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
int n;
int a[50];
int cnt = 0;
int f(int k, int l)
{
    if (l == 0)
    {
        cnt++;
        return 1;
    }
    if (k >= n || l < 0)
        return 0;

    return f(k + 1,l)+ f(k + 1,l - a[k]);
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    cout << f(0, 40) << endl;
    return 0;
}
*/