#include <cstdlib>
#include <iostream>
using namespace std;
int strlen(const char *s)
{
    int i = 0;
    for(; s[i]; ++i);
    return i;
}
void strcpy(char *d, const char *s)
{
    int i = 0;
    for( i = 0; s[i]; ++i)
        d[i] = s[i];
    d[i] = 0;

}
int strcmp(const char *s1, const char *s2)
{
    for(int i = 0; s1[i] && s2[i] ; ++i)
    {
        if( s1[i] < s2[i] )
            return -1;
        else if( s1[i] > s2[i])
            return 1;
    }
    return 0;
}
void strcat(char *d, const char *s)
{
    int len = strlen(d);
    strcpy(d + len, s);
}
class MyString
{
public:
    char *s;
    MyString(char *s1)
    {
        s = new char[strlen(s1) + 1];
        strcpy(s, s1);
    }
    MyString()
    {
        s = new char[1];
        s[0] = 0;
    }
    ~MyString()
    {
        if (s)
            delete []s;
    }
    MyString(const MyString &s1)
    {
        if (s1.s)
        {
            s = new char[strlen(s1.s) + 1];
            strcpy(s, s1.s);
        }
        else
        {
            s = new char[1];
            s[0] = 0;
        }

    }
    MyString &operator = (char *s1)
    {
        if (s)
            delete []s;
        if (s1)
        {
            s = new char[strlen(s1) + 1];
            strcpy(s, s1);
        }
        else
        {
            s = new char[1];
            s[0] = 0;
        }
        return *this;
    }
    MyString &operator = (const MyString &t)
    {
        if (this == &t)
        {
            return * this;
        }
        if (s)
            delete []s;
        if (t.s)
        {
            s = new char[strlen(t.s) + 1];
            strcpy(s, t.s);
        }
        else
        {
            s = new char[1];
            s[0] = 0;
        }
        return *this;
    }
    MyString operator +(const MyString &s1)
    {
        MyString tmp;
        tmp.s = new char[strlen(s) + strlen(s1.s) + 1];
        strcpy(tmp.s, s);
        strcat(tmp.s, s1.s);
        return tmp;
    }
    MyString operator +(char *s1)
    {
        MyString tmp;
        tmp.s = new char[strlen(s) + strlen(s1) + 1];
        strcpy(tmp.s, s);
        strcat(tmp.s, s1);
        return tmp;
    }
    MyString &operator += (char *s1)
    {
        char *tmp = new char[strlen(s) + 1];
        strcpy(tmp, s);
        delete []s;
        s = new char[strlen(tmp) + strlen(s1) + 1];
        strcpy(s, tmp);
        strcat(s, s1);
        return *this;
    }
    friend MyString operator + (char *s1, const MyString &s2)
    {
        MyString tmp;
        tmp.s = new char[strlen(s1) + strlen(s2.s) + 1];
        strcpy(tmp.s, s1);
        strcat(tmp.s, s2.s);
        return tmp;
    }

    char &operator [] (int i)
    {
        return s[i];
    }
    char *operator () (int i, int j)
    {
        char *str = new char[j + 1];
        for (int k = 0; k < j; ++k)
        {
            str[k] = s[i + k];
        }
        str[j] = 0;
        return str;
    }
    friend ostream &operator << (ostream &o, MyString &t)
    {
        cout << t.s;
        return o;
    }
    friend bool operator < (MyString &s1, MyString &s2)
    {
        if (strcmp(s1.s, s2.s) < 0)
            return 1;
        else
            return 0;
    }
    friend bool operator > (MyString &s1, MyString &s2)
    {
        if (strcmp(s1.s, s2.s) > 0)
            return 1;
        else
            return 0;
    }
    friend bool operator == (MyString &s1, MyString &s2)
    {
        if (strcmp(s1.s, s2.s) == 0)
            return 1;
        else
            return 0;
    }
};


int CompareString( const void *e1, const void *e2)
{
    MyString *s1 = (MyString * ) e1;
    MyString *s2 = (MyString * ) e2;
    if( * s1 < *s2 )
        return -1;
    else if( *s1 == *s2)
        return 0;
    else if( *s1 > *s2 )
        return 1;
}
int main()
{
    MyString s1("abcd-"), s2, s3("efgh-"), s4(s1);
    MyString SArray[4] = {"big", "me", "about", "take"};
    cout << "1. " << s1 << s2 << s3 << s4 << endl;
    s4 = s3;
    s3 = s1 + s3;
    cout << "2. " << s1 << endl;
    cout << "3. " << s2 << endl;
    cout << "4. " << s3 << endl;
    cout << "5. " << s4 << endl;
    cout << "6. " << s1[2] << endl;
    s2 = s1;
    s1 = "ijkl-";
    s1[2] = 'A' ;
    cout << "7. " << s2 << endl;
    cout << "8. " << s1 << endl;
    s1 += "mnop";
    cout << "9. " << s1 << endl;
    s4 = "qrst-" + s2;
    cout << "10. " << s4 << endl;
    s1 = s2 + s4 + " uvw " + "xyz";
    cout << "11. " << s1 << endl;
    qsort(SArray, 4, sizeof(MyString), CompareString);
    for( int i = 0; i < 4; i ++ )
        cout << SArray[i] << endl;
    //s1的从下标0开始长度为4的子串
    cout << s1(0, 4) << endl;
    //s1的从下标5开始长度为10的子串
    cout << s1(5, 10) << endl;
    return 0;
}