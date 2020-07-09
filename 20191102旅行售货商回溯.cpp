/*
15
0 9 5 2 9 9 4 8 4 6 5 4 1 1 8 
9 0 4 2 7 3 9 1 3 6 3 1 1 6 7 
5 4 0 5 6 2 2 6 5 4 6 3 2 2 2 
2 2 5 0 1 9 1 9 7 7 9 7 9 6 1 
9 7 6 1 0 8 3 8 6 2 7 9 9 8 7 
9 3 2 9 8 0 9 4 1 5 9 8 7 7 8 
4 9 2 1 3 9 0 1 2 6 1 4 5 5 5 
8 1 6 9 8 4 1 0 1 5 2 2 5 3 2 
4 3 5 7 6 1 2 1 0 2 3 5 4 5 5 
6 6 4 7 2 5 6 5 2 0 8 8 7 9 4 
5 3 6 9 7 9 1 2 3 8 0 2 1 1 1 
4 1 3 7 9 8 4 2 5 8 2 0 6 1 9 
1 1 2 9 9 7 5 5 4 7 1 6 0 6 5 
1 6 2 6 8 7 5 3 5 9 1 1 6 0 4 
8 7 2 1 7 8 5 2 5 4 1 9 5 4 0 
*/

#include <iostream>
using namespace std;
int a[20][20];
int n;
int mincost = 1000000;
int cost[20] = { 0 };
int c[20] = { 0 };
int trace[20];
int mintrace[20];
int fun(int city, int k)
{
    if (k == n)
    {
        for (int i = 0; i < n; i++)
        {
            mintrace[i+1]= trace[i + 1];
        }
        cost[k] = cost[k - 1] + a[city][1];
        if (cost[k] < mincost)
            mincost = cost[k];
        cost[k] = 0;
        return 0;
    }
    for (int i = 2; i <= n; i++)
    {
        if (c[i])
            continue;
        c[i] = 1;
        trace[k+1] = i;
        cost[k] = cost[k - 1] + a[city][i];

        if (cost[k] < mincost)
            fun(i, k + 1);
        cost[k] = 0;
        c[i] = 0;
    }
    return 0;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    trace[1] = 1;
    fun(1, 1);
    cout << mincost << endl;
    return 0;
}
