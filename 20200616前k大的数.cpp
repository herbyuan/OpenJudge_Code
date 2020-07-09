#include <iostream>
#include <cstring>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
// 前m大的数从大到小输出
int n;
int k;
int a[100001] = {0};
int arrangeRight(int s, int e, int m)
{
    if (s >= e)
        return 0;
    int t = a[s];
    int i = s;
    int j = e;
    while(i != j)
    {
        while(j > i && a[j] >= t)
            j--;
        swap(a[i], a[j]);
        while(j > i && a[i] <= t)
            i++;
        swap(a[i], a[j]);
    }

    if (e - i + 1 < m)
        arrangeRight(s, i - 1,m - e + i  - 1);
    else if(e - i + 1 > m)
    {
        arrangeRight(i + 1, e,m);
    }
    return 0;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
    }
    cin >> k;
    arrangeRight(0, n - 1, k);
    sort(a + n - k, a + n);
    for(int i = n - 1; i > n - k - 1; i--)
    {
        printf("%d\n", a[i]);
    }
    return 0;
}

/*
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int k;
int a[100001] = {0};

int arrangeLeft(int s, int e, int m)
{
    if (s >= e)
        return 0;
    int t = a[s];
    int i = s;
    int j = e;
    while(i != j)
    {
        while(j > i && a[j] <= t)
            j--;
        swap(a[i], a[j]);
        while(j > i && a[i] >= t)
            i++;
        swap(a[i], a[j]);
    }

    if (i < m)
        arrangeLeft(i + 1, e,m);
    else if(i > m)
    {
        arrangeLeft(s, i, m);
    }
    return 0;
}
void Quicksort(int a[], int s, int e)
{
    if (s >= e)
        return;
    int k = a[s];
    int i = s, j = e;
    while(i != j)
    {
        while(j > i && a[j] <= k)
            j--;
        swap(a[i], a[j]);
        while(i < j && a[i] >= k)
            i++;
        swap(a[i], a[j]);
    }
    Quicksort(a, s, i - 1);
    Quicksort(a, i + 1, e);
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
    }
    cin >> k;
    arrangeLeft(0, n - 1, k - 1);
    Quicksort(a,0, k - 1);
    for(int i = 0; i < k; i++)
    {
        printf("%d\n", a[i]);
    }
    return 0;
}

*/
