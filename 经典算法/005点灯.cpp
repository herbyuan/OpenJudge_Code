#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[20] = {0};
    int b[20] = {0};
    char x;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> x;
            if (x == 'w')
            {
                b[i] |= (1 << j);
            }
            else
            {
                continue;
            }
        }
    }
    int m = 1 << 30;
    for (int i = 0; i < (1 << n); ++i)
    {
        memcpy(a, b, sizeof(a));
        int cnt = 0;
        for (int j = 0; j < n; ++j)
        {
            if(1 & (i >> j))
            {
                cnt++;
                if(j != 0)
                {
                    a[0] ^= (1 << (j - 1));
                }
                if (j != n - 1)
                {
                    a[0] ^= (1 << (j + 1));
                }
                a[0] ^= 1 << j;
                a[1] ^= 1 << j;
            }
        }
        for(int j = 1; j < n; j++)
        {
            for(int k = 0; k < n; k++)
            {
                if(1 & ((a[j - 1] >> k)))
                {
                    cnt++;
                    if(k != 0)
                    {
                        a[j] ^= (1 << (k - 1));
                    }
                    if(k != n - 1)
                    {
                        a[j] ^= (1 << (k + 1));
                    }
                    a[j - 1] ^= 1 << k;
                    a[j] ^= 1 << k;
                    a[j + 1] ^= 1 << k;
                }
            }
        }
        if(a[n - 1] == 0)
        {
            m = min(m, cnt);
        }
    }
    if(m == 1<<30)
        cout << "inf" << endl;
    else
        cout << m << endl;
    return 0;
}
