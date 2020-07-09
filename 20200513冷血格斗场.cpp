#include <iostream>
#include <map>
using namespace std;


int main()
{
    map<int, int> arena;
    map<int, int>::iterator i;
    int n, id, shili;
    arena[1000000000] = 1;//key，value
    scanf("%d", &n);
    for (int j = 1; j <= n; j++)
    {
        scanf("%d%d", &id, &shili);

        i = arena.lower_bound(shili);
        if (i == arena.end()) i--;
        int id1 = i->second;
        int dshili = abs(i->first - shili);

        if (i != arena.begin())
        {
            i--;
            if (abs(i->first - shili) < dshili || (dshili == abs(i->first - shili) && i->second < id1))
                id1 = i->second;
        }

        printf("%d %d\n", id, id1);

        i = arena.find(shili);
        if (i == arena.end() || i->second > id)
            arena[shili] = id;
    }
    return 0;
}