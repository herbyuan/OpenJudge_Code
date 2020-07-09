/*
*程序名：玛雅历
*作者：何卓远
*编制时间：2019-12-04
*功能：转换为玛雅历
*/
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int main()
{
    int i, j, k;
    
    return 0;
}
#include <iostream>
#include <cmath>
#include <cstring>
#include <iomanip>
using namespace std;
int maya()
{
    int day, month,year;
    scanf("%d.", &day);
    char x[10];
    cin >> x;
    char str[19][10] = {"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu","uayet"};
    for (int i = 0; i < 19; ++i)
    {
        if (strcmp(x, str[i]) == 0)
        {
            month = i;
            break;
        }
    }
    cin>>year;
    int s;
    s = 365*year+20*month+day;
    int y,m,d;
    y = s/260;
    m = s%20;
    d = s%13+1;
    char str2[20][10] = {"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};
    cout<<d<<" "<<str2[m]<<" "<<y<<endl;
    return 0;
}

int main()
{
    int n;
    cin>>n;
    cout<<n<<endl;
    for (int i = 0; i < n; ++i)
    {
        maya();
    }
    return 0;
}