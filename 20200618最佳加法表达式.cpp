//给定n个1到9的数字，要求在数字之间摆放m个加号(加号两边必须有数字），使得所得到的加法表达式的值最小，并输出该值。例如，在1234中摆放1个加号，最好的摆法就是12+34,和为36
#include<iostream>
#include<cstring>
using namespace std;
class MyInt
{
public:
    int num[110];
    int len;
    MyInt()
    {
        len = 1;
        memset(num, 0, sizeof(num));
    }
    MyInt(const char *n, int L)
    {
        memset(num, 0, sizeof(num));
        len = L;
        for(int i = 0; i < len; ++i)
            num[len - 1 - i] = n[i] - '0';
    }
    MyInt operator + (const MyInt &n)
    {
        int ml = max(len, n.len);
        int carry = 0;
        MyInt result;
        for(int i = 0; i < ml; ++i)
        {
            result.num[i] = num[i] + n.num[i] + carry;
            if(result.num[i] >= 10)
            {
                carry = 1;
                result.num[i] -= 10;
            }
            else
                carry = 0;
        }
        if(carry == 1)
        {
            result.len = ml + 1;
            result.num[ml] = 1;
        }
        else
            result.len = ml;
        return result;
    }
    bool operator < (const MyInt &n)
    {
        if(len > n.len)
            return false;
        else if(len < n.len)
            return true;
        else
        {
            for(int i = len - 1; i >= 0; --i)
            {
                if(num[i] < n.num[i])
                    return true;
                else if(num[i] > n.num[i])
                    return false;
            }
            return false;
        }
    }


};

ostream &operator << (ostream &o, const MyInt &n)
{
    for(int i = n.len - 1; i >= 0; --i)
        o << n.num[i];
    return o;
}

char a[60];
MyInt Num[60][60];
MyInt V[60][60];

int main()
{
    int m, n;
    MyInt inf;
    inf.num[58] = 1;
    inf.len = 59;
    while(cin >> m)
    {
        cin >> a + 1;
        n = strlen(a + 1);
        for(int i = 1; i <= n; ++i)
            for(int j = i; j <= n; ++j)
                Num[i][j] = MyInt(a + i, j - i + 1);
        for(int j = 1; j <= n; ++j)
            V[0][j] = MyInt(a + 1, j);

        for(int i = 1; i <= m; ++i)
        {
            for(int j = 1; j <= n; ++j)
            {
                if(j - 1 < i)
                    V[i][j] = inf;
                else
                {
                    MyInt tmpMin = inf;
                    for(int k = i; k < j; ++k)
                    {
                        MyInt tmp = V[i - 1][k] + Num[k + 1][j];
                        if(tmp < tmpMin)
                            tmpMin = tmp;
                    }
                    V[i][j] = tmpMin;
                }
            }
        }
        cout << V[m][n] << endl;
    }
    return 0;
}