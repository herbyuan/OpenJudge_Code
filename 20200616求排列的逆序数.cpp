#include <iostream>
using namespace std;
int n;
int a[100001] = {0};
int tmp[100001] = {0};
long long ans = 0;

void mergeAndCount(int s, int m, int e)
{
    int pb = 0;
    int p1 = s, p2 = m + 1;
    while(p1 <= m && p2 <= e)
    {
        if (a[p1] < a[p2])
        {
            tmp[pb++] = a[p1++];
        }
        else
        {
            tmp[pb++] = a[p2++];
            ans += m - p1 + 1;
        }
    }
    while(p1 <= m)
    {
        tmp[pb++] = a[p1++];
    }
    while(p2 <= e)
    {
        tmp[pb++] = a[p2++];
    }
    for (int i = 0; i < e - s + 1; ++i)
    {
        a[s + i] = tmp[i];
    }
}


void mergeSort(int s, int e)
{
    if (s < e)
    {
        int m = s + (e - s) / 2;
        mergeSort(s, m);
        mergeSort(m + 1, e);
        mergeAndCount(s, m, e);
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
    }
    mergeSort(0, n - 1);
    cout << ans << endl;
    return 0;
}