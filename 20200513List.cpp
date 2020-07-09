#include <iostream>
#include <list>
#include <vector>
//#include <iterator>
using namespace std;

list<int> &func(vector<list<int> > &a, int id)
{
    vector<list<int> >::iterator i;
    i = a.begin();
    return *(i + id - 1);
}

int main()
{
    int n;
    cin >> n;
    vector<list<int> > a;
    string s;
    for (int i = 0; i < n; ++i)
    {
        cin >> s;
        if (s == "new")
        {
            int id;
            cin >> id;
            a.push_back(list<int>());
        }
        else if (s == "add")
        {
            int id;
            int m;
            cin >> id >> m;
            list<int> &tmp = func(a, id);
            tmp.push_back(m);
            tmp.sort();
        }
        else if (s == "merge")
        {
            int id1, id2;
            cin >> id1 >> id2;
            list<int> &t1 = func(a, id1);
            list<int> &t2 = func(a, id2);
            t1.merge(t2);
        }
        else if (s == "unique")
        {
            int id;
            cin >> id;
            list<int> &tmp = func(a, id);
            tmp.unique();
        }
        else if (s == "out")
        {
            int id;
            cin >> id;
            list<int> &tmp = func(a, id);
            tmp.sort();
            list<int>::iterator i;
            for (i = tmp.begin(); i != tmp.end(); ++i)
            {
                cout << *i << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}