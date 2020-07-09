#include <iostream>
#include <list>
#include <vector>
#include <set>
#include <map>
using namespace std;


int main()
{
    int n;
    cin>>n;
    map<int,int> mp;
    mp.insert(make_pair(1000000000,1));
    while(n--)
    {
        int id,force;
        scanf("%d %d",&id,&force);
        //auto p1 = mp.lower_bound(force);
        auto p2 = mp.upper_bound(force);
        if (p2 == mp.begin())
        {
            printf("%d %d\n",id,(*p2).second);
        }
        else
        {
            auto p1 = p2;
            p1--;
            if (force - (*p1).first <= (*p2).first - force)
            {
                printf("%d %d\n",id,(*p1).second);
            }
            else
            {
                printf("%d %d\n",id,(*p2).second);
            }
        }
        mp[force] = id;
    }
    return 0;
}