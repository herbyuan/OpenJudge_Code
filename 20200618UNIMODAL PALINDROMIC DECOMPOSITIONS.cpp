#include <iostream>
#include <cmath>
#include <cstring>
#include <set>
#include <vector>
#include <map>
#include <list>

using namespace std;
long long ans[250][250];
long long calc(int n, int k)
{
    if (ans[n][k])
        return ans[n][k];
    if (n == 0)
        return 1;
    if (k == 1)
        return 1;
    if (k == 2)
    {
        if (n % 2 == 0)
            return 1;
        else
            return 0;
    }
    if (k % 2 == 0 && n % 2 != 0)
        return 0;
    long long s = 0;
    for (long long i = 1; k * i <= n; ++i)
    {
        s += calc(n - k * i + k - 2, k - 2);
    }
    ans[n][k] = s;
    return s;

}
long long func(int n)
{
    long long s = 0;
    for (int i = 1; i <= n; ++i)
    {
        s += calc(n, i);
    }
    return s;
}
int main()
{
    memset(ans, 0, sizeof(ans));
    int n;
    while(cin >> n)
    {
        if (n == 0)
            return 0;
        else
            cout << n << ' ' << func(n) << endl;
    }
    return 0;
}