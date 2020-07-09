/*又到周末了，同学们陆陆续续开开心心的来到机房上机。jbr也不例外，但是他到的有点晚，发现有些机位上已经有同学正在做题，有些机位还空着。细心的jbr发现，一位同学来到机房，坐在机位i上，如果他的左右两边都空着，他将获得能力值a[i]；如果当他坐下时，左边或者右边已经有一个人在上机了，他将获得能力值b[i]；如果当他坐下时，他的左边右边都有人在上机，他将获得能力值c[i]。

同时他发现，已经在上机的同学不会受到刚要坐下的同学的影响，即他们的能力值只会在坐下时产生，以后不会发生变化;第一个机位左边没有机位，最后一个机位右边没有机位，无论何时坐在这两个机位上将无法获得c值。

这时jbr发现有一排机器还空着，一共有N个机位，编号1到N。这时有N位同学们陆陆续续来到机房，一个一个按照顺序坐在这排机位上。聪明的jbr想知道怎么安排座位的顺序，可以使这N位同学获得能力值的和最大呢？

*/

#include <iostream>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;

int main()
{
    int N;
    int a[10010],b[10010],c[10010];
    int dp[10010][4];
    cin>>N;
    for (int i = 1; i <= N; ++i)
    {
        cin>>a[i];
    }
    for (int i = 1; i <= N; ++i)
    {
        cin>>b[i];
    }
    for (int i = 1; i <= N; ++i)
    {
        cin>>c[i];
    }
    dp[1][0] = a[1];
    dp[1][2] = b[1];
    for (int i = 2; i <= N; ++i)
    {
        dp[i][0] = max(dp[i - 1][3],dp[i - 1][2]) + a[i];
        dp[i][1] = max(dp[i - 1][0],dp[i - 1][1]) + b[i];
        dp[i][2] = max(dp[i - 1][3],dp[i - 1][2]) + b[i];
        dp[i][3] = max(dp[i - 1][0],dp[i - 1][1]) + c[i];
    }
    cout<<max(dp[N][0],dp[N][1])<<endl;
    return 0;
}