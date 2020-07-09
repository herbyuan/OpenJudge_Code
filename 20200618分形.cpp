#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
char a[900][900];
void func(int k, int x, int y)
{
    if(k == 0)
    {
        a[x][y] = 'X';
        return;
    }
    func(k - 1, x + 2 * pow(3.0, k - 1), y);
    func(k - 1, x + pow(3.0, k - 1), y + pow(3.0, k - 1));
    func(k - 1, x, y + 2 * pow(3.0, k - 1));
    func(k - 1, x, y);
    func(k - 1, x + 2 * pow(3.0, k - 1), y + 2 * pow(3.0, k - 1));
}
int main()
{
    for (int i = 0; i < 900; ++i)
    {
        for (int j = 0; j < 900; ++j)
        {
            a[i][j] = ' ';
        }
    }
    func(6, 0, 0);
    int k;
    while(cin>>k && k != -1)
    {
        for (int i = 0; i < pow(3.0,k - 1); ++i)
        {
            for (int j = 0; j < pow(3.0,k - 1); ++j)
            {
                cout<<a[i][j];
            }
            cout<<endl;
        }
        cout<<'-'<<endl;
    }

    return 0;
}