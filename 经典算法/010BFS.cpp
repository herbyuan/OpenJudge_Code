#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int main()
{
    int K;
    cin>>K;
    int dx[] = {0,1,0,-1};
    int dy[] = {1,0,-1,0};
    while(K--)
    {
        int m,T;
        char a[11][11];
        queue<pair<int,int> > q;
        int b[11][11];
        memset(b,0,sizeof(b));
        int xx,yy;
        cin>>m>>T;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                cin>>a[i][j];
                if (a[i][j] == 'S')
                {
                    q.push(make_pair(i,j));
                    b[i][j] = 1;
                }
                if (a[i][j] == 'E')
                {
                    xx=i;
                    yy=j;
                }
            }
        }
        int t = 0,flag = 0;
        while(t <= T && q.size())
        {
            t++;

            int s = q.size();
            for (int i = 0; i < s; ++i)
            {
                auto p = q.front();
                q.pop();
                if(p.first == xx && p.second == yy)
                {
                    flag = 1;
                    cout<<"YES"<<endl;
                    break;
                }
                for (int i = 0; i < 4; ++i)
                {
                    int tx = p.first + dx[i];
                    int ty = p.second + dy[i];
                    if (tx >= 0 && ty >= 0 && tx < m && ty < m && a[tx][ty] != '#' && b[tx][ty] == 0)
                    {
                        b[tx][ty] = 1;
                        q.push(make_pair(tx,ty));
                    }
                }
            }
        }
        if (flag == 0)
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}