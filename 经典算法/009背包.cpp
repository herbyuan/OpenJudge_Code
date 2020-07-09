#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int N,M;
    cin>>N>>M;
    int w[3500];
    int d[3500];
    for (int i = 0; i < N; ++i)
    {
        cin>>w[i]>>d[i];
    }
    int m[13000] = {0};
    for (int i = 0; i < N; ++i)
    {
        for(int j = M;j >= w[i];j--)
        {
            m[j] = max(m[j],m[j - w[i]] + d[i]);
        }        
    }
    int Maxd = 0;
    for (int i = 0; i <= M; ++i)
    {
        if (m[i] > Maxd)
            Maxd = m[i];
    }
    cout<<Maxd<<endl;
    return 0;
}