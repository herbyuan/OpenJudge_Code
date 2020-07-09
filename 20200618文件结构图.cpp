#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
void func(int k)
{
    string s[40];
    int cnt = 0;
    while(1)
    {
        cin >> s[cnt];
        if (s[cnt][0] == ']')
            break;
        else if (s[cnt][0] == 'd')
        {
            for (int i = 0; i < k; ++i)
            {
                printf("|     ");
            }
            printf("|     %s\n", s[cnt].c_str());
            func(k + 1);
        }
        else
            cnt++;
    }
    sort(s,s + cnt);
    for (int i = 0; i < cnt; ++i)
    {
        for (int i = 0; i < k; ++i)
        {
            printf("|     ");
        }
        cout << s[i] << endl;
    }
}
int main()
{
    int n = 1;
    string s[40];
    while(1)
    {
        int k = 0;
        string S;
        cin >> S;
        if(S == "#")
            return 0;
        printf("DATA SET %d:\nROOT\n", n++);
        if(S[0] == 'd')
        {
            printf("|     %s\n", S.c_str());
            func(1);
        }
        else
        {
            s[k++] = S;
        }
        while(1)
        {
            cin >> S;
            if (S[0] == '*')
                break;
            else if (S[0] == 'd')
            {
                printf("|     %s\n", S.c_str());
                func(1);
            }
            else
            {
                s[k++] = S;
            }
        }
        sort(s, s + k);
        for (int i = 0; i < k; ++i)
        {
            cout << s[i] << endl;
        }
        cout << endl;
    }

    return 0;
}
