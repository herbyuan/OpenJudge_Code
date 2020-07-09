#include <iostream>
using namespace std;
class MyCin
{
    // 在此处补充你的代码
public:
    bool b;
    MyCin()
    {
        b = 1;
    }
    MyCin &operator >>(int &n)
    {
        if (!b) return *this;
        cin >> n;
        if (n == -1) b = 0;
        return *this;
    }
    operator bool()
    {
        return b;
    }
};
int main()
{
    MyCin m;
    int n1, n2;
    while( m >> n1 >> n2)
        cout  << n1 << " " << n2 << endl;
    return 0;
}