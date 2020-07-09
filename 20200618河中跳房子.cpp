
/*
每年奶牛们都要举办各种特殊版本的跳房子比赛，包括在河里从一个岩石跳到另一个岩石。这项激动人心的活动在一条长长的笔直河道中进行，在起点和离起点L远 (1 ≤ L≤ 1,000,000,000) 的终点处均有一个岩石。在起点和终点之间，有N (0 ≤ N ≤ 50,000) 个岩石，每个岩石与起点的距离分别为Di (0 < Di < L)。

在比赛过程中，奶牛轮流从起点出发，尝试到达终点，每一步只能从一个岩石跳到另一个岩石。当然，实力不济的奶牛是没有办法完成目标的。

农夫约翰为他的奶牛们感到自豪并且年年都观看了这项比赛。但随着时间的推移，看着其他农夫的胆小奶牛们在相距很近的岩石之间缓慢前行，他感到非常厌烦。他计划移走一些岩石，使得从起点到终点的过程中，最短的跳跃距离最长。他可以移走除起点和终点外的至多M (0 ≤ M ≤ N) 个岩石。

请帮助约翰确定移走这些岩石后，最长可能的最短跳跃距离是多少？
*/
#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;
int L, N, M;
int d[50002] = {0};
int func(int mid)
{
    int last = 0;
    int cur = 1;
    int cnt = 0;
    while(cur <= N + 1)
    {
        if (d[cur] - d[last] < mid)
        {
            cnt++;
            cur++;
        }
        else
        {
            last = cur;
            cur++;
        }
    }
    if (cnt <= M)
        return 1;
    else
        return 0;
}

int main()
{
    cin >> L >> N >> M;
    int Min = 1;
    for (int i = 1; i <= N; ++i)
    {
        cin >> d[i];
    }
    d[N + 1] = L;
    int Max = L;
    int valid;
    while(Max >= Min)
    {
        int mid = Min + (Max - Min) / 2;
        if(func(mid))
        {
            valid = mid;
            Min = mid + 1;
        }
        else
            Max = mid - 1;
    }
    cout << valid << endl;
    return 0;
}