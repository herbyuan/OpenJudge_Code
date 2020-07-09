#include <iostream>
#include <cstring>
#include <map>
#include <queue>
#include <set>
using namespace std;
struct Node
{
    string s;
    int k;
    int a;
    Node(string _s, int _k,int _a)
    {
        s = _s;
        k = _k;
        a = _a;
    }
};

int main()
{
    int n, m;
    while(cin >> n >> m && n)
    {
        queue<Node> q;
        q.push(Node("", 0, n));
        int flag = 0;
        priority_queue<string> ans;
        int step;
        set<int> s;
        s.insert(n);
        while(q.size())
        {
            if(flag)
                break;
            int size = q.size();
            for (int i = 0; i < size; ++i)
            {
                auto p = q.front();
                q.pop();
                if(p.a == m)
                {
                    flag = 1;
                    step = p.k;
                    ans.push(p.s);
                }
                int t = p.a * 3;
                if(s.count(t) == 0)
                {
                    s.insert(t);
                    q.push(Node(p.s + 'H',p.k + 1,t));
                }
                t = p.a / 2;
                if(s.count(t) == 0)
                {
                    s.insert(t);
                    q.push(Node(p.s + 'O',p.k + 1,t));
                }
            }
        }
        cout<<step<<endl;
        cout<<ans.top()<<endl;
    }

    return 0;
}