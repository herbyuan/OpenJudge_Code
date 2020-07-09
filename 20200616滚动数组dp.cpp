#include <iostream>
using namespace std;
int D[101][101];
int n;
int *maxsum;
int main()
{
    cin >> n;
    for (int i = 1; i < n + 1 ; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            cin >> D[i][j];
        }
    }
    maxsum = D[n];
    for (int i = n - 1; i >= 1; i--)
    {
        for(int j = 1;j <= i; j++)
        {
            maxsum[j] = max(maxsum[j],maxsum[j +1]) + D[i][j];
        }
    }
    cout<<maxsum[1]<<endl;
    return 0;
}