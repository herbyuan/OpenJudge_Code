#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int a[100010] = {0};
int n, m;

int f(int k)
{
    int cnt = 1;
    int t = 0;
    for (int i = 0; i < n; ++i)
    {
        if(a[i] > k)
            return 0; 
        t += a[i];
        if(t > k)
        {
            cnt++;
            t = a[i];
        }
        if(cnt > m)
            return 0;
    }
    return 1;
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
    }
    int L = 1;
    int R = 1 << 30;
    int ans = R;
    while(L <= R)
    {
        int M = L + (R - L) / 2;
        if(f(M))
        {
            ans = min(ans,M);
            R = M - 1;
        }
        else
        {
            L = M + 1;
        }
    }
    cout<<ans<<endl;
    return 0;
}