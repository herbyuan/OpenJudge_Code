//二维数组类 Array2

#include <iostream>
#include <cstring>
using namespace std;

class Array2
{
public:
    int *p;
    int x, y;
    int size;
    Array2(int a, int b)
    {
        x = a;
        y = b;
        size = a * b;
        if (size == 0)
            p = NULL;
        else
            p = new int[size];
    }
    Array2()
    {
        x = y = size = 0;
        p = NULL;
    }
    Array2(Array2 &t)
    {
        x = t.x;
        y = t.y;
        if (!t.p)
        {
            p = NULL;
            size = 0;
            return;
        }
        else
        {
            p = new int[t.size];
            for (int i = 0; i < size; ++i)
            {
                p[i] = t.p[i];
            }
            size = t.size;
        }
    }
    ~Array2()
    {
        if (p)
            delete []p;
    }
    Array2 &operator = (const Array2 &t)
    {
        if (p == t.p)
            return *this;
        if (t.p == NULL)
        {
            if (p) delete []p;
            p = NULL;
            size = 0;
            return *this;
        }
        x = t.x;
        y = t.y;
        if (p) delete []p;
        p = new int[t.size];
        memcpy(p, t.p, sizeof(int)*t.size);
        size = t.size;
        return *this;
    }
    int *operator[](int i)
    {
        return (p + y * i);
    }
    int &operator () (int i, int j)
    {
        return p[y * i + j];
    }
};

int main()
{
    Array2 a(3, 4);
    int i, j;
    for(  i = 0; i < 3; ++i )
        for(  j = 0; j < 4; j ++ )
            a[i][j] = i * 4 + j;
    for(  i = 0; i < 3; ++i )
    {
        for(  j = 0; j < 4; j ++ )
        {
            cout << a(i, j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b;
    b = a;
    for(  i = 0; i < 3; ++i )
    {
        for(  j = 0; j < 4; j ++ )
        {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}