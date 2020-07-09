#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;
const int MAX = 110;
class CHugeInt
{
public:
    int n[201] = {0};
    CHugeInt(const char *s)
    {
        int l = strlen(s);
        for (int i = 0; i < l; i++)
        {
            n[i] = s[l - i - 1] - '0';
        }
    }
    CHugeInt()
    {

    }
    CHugeInt(int a)
    {
        int i = 0;
        while (a)
        {
            n[i++] = a % 10;
            a /= 10;
        }
    }
    CHugeInt operator +(const CHugeInt &t)
    {
        CHugeInt tmp;
        int k = 0;
        for (int i = 0; i < 201; ++i)
        {
            //cout<<n[i]<<' '<<t.n[i]<<' '<<k<<endl;
            tmp.n[i] = n[i] + t.n[i] + k;
            k = tmp.n[i] / 10;
            //cout<<tmp.n[i]<<' '<<k<<endl;
            tmp.n[i] = tmp.n[i] % 10;
        }
        //cout<<tmp.n[0]<<tmp.n[1]<<endl;
        return tmp;
    }
    CHugeInt operator +(int a)
    {
        CHugeInt tmp;
        CHugeInt t(a);
        int k = 0;
        for (int i = 0; i < 201; ++i)
        {
            tmp.n[i] = n[i] + t.n[i] + k;
            k = tmp.n[i] / 10;
            tmp.n[i] = tmp.n[i] % 10;
        }
        return tmp;
    }
    CHugeInt &operator++()
    {
        *this = *this + 1;
        return *this;
    }
    CHugeInt operator++(int)
    {
        CHugeInt tmp(*this);
        *this = *this + 1;
        return tmp;
    }
    CHugeInt &operator+=(int n)
    {
        *this = *this + n;
        return *this;
    }
    friend CHugeInt operator +(int a, CHugeInt &t)
    {
        CHugeInt tmp;
        tmp = t + a;
        return tmp;
    }
    friend ostream &operator <<(ostream &o, const CHugeInt &t)
    {
        int len = 200;
        for (int i = 0; i <= 200; ++i)
        {
            if (t.n[200 - i])
            {
                break;
            }
            else
                len--;
        }
        char str[201];
        if (len == 0)
        {
            str[0] = t.n[0] + '0';
            str[1] = 0;
        }
        if (len == -1)
            strcpy(str, "0");
        else
        {
            int j = 0;

            for (int i = len; i >= 0; i--)
            {
                str[j++] = '0' + t.n[i];
            }
            str[j] = 0;
        }
        cout << str;
        return o;
    }
};
int  main()
{
    char s[210];
    int n;

    while (cin >> s >> n)
    {
        CHugeInt a(s);
        CHugeInt b(n);

        cout << a + b << endl;
        cout << n + a << endl;
        cout << a + n << endl;
        b += n;
        cout  << ++ b << endl;
        cout << b++ << endl;
        cout << b << endl;
    }
    return 0;
}