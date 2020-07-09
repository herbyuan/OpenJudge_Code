#include <iostream>

using namespace std;

int n, m;
int a[200005];
int cnt;
void push(int x)
{
    a[++cnt] = x;
    int p = cnt;
    while(p > 1 && a[p] < a[p / 2])
    {
        swap(a[p], a[p / 2]);
        p = p / 2;
    }
}
void down(int x)
{
    int t = x * 2;
    if (t > cnt) return;
    if (t + 1 <= cnt && a[t + 1] < a[t])
        t++;
    if (a[t] < a[x])

    {
        swap(a[t], a[x]);
        down(t);
    }
}
void pop()
{
    a[1] = a[cnt];
    cnt--;
    down(1);
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        push(x);
    }
    cin >> m;
    char opt[15];
    for (int i = 0; i < m; ++i)
    {
        scanf("%s", opt);
        if (opt[0] == 'E')
        {
            if (cnt == 0)
                puts("NULL");
            else
            {
                cout << a[1] << endl;
                pop();
            }
        }
        else
        {
            int x;
            cin >> x;
            push(x);
        }
    }
    return 0;
}