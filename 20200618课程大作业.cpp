#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Homework
{
    string s;
    int d;
    int c;
} hw[20];

struct Node
{
    int pre;
    int minscore;
    int last;
    int finishDay;
} dp[(1 << 16) + 1];

vector<int> Getpath(int s)
{
    vector<int> path;
    while(s)
    {
        path.push_back(dp[s].last);
        s = dp[s].pre;
    }
    reverse(path.begin(), path.end());
    return path;
}

int main()
{
    int T, N;
    cin >> T;
    while(T--)
    {
        cin >> N;
        for (int i = 0; i < N; ++i)
        {
            cin >> hw[i].s >> hw[i].d >> hw[i].c;
        }
        dp[0].finishDay = 0;
        dp[0].minscore = 0;
        dp[0].pre = -1;
        int m = 1 << N;
        for(int i = 1; i < m; i++) //代表已完成的作业的集合
        {
            dp[i].minscore = 987654321;
            for(int j = 0; j < N; j++)
            {
                if (i & (1 << j))
                {
                    int tpre = i - (1 << j);
                    int tfinishday = dp[tpre].finishDay + hw[j].c;
                    int tscore = tfinishday - hw[j].d;
                    if (tscore < 0)
                        tscore = 0;
                    if (dp[i].minscore > dp[tpre].minscore + tscore)
                    {
                        dp[i].minscore = dp[tpre].minscore + tscore;
                        dp[i].pre = tpre;
                        dp[i].finishDay = tfinishday;
                        dp[i].last = j;

                    }
                    if (dp[i].minscore == dp[tpre].minscore + tscore)
                    {
                        vector<int> p = Getpath(dp[i].pre);
                        vector<int> q = Getpath(tpre);
                        if (q < p)
                        {
                            dp[i].pre = tpre;
                            dp[i].finishDay = tfinishday;
                            dp[i].last = j;

                        }
                    }

                }
            }
        }
        cout << dp[m - 1].minscore << endl;
        vector<int> ans = Getpath(m - 1);
        for (int i = 0; i < ans.size(); ++i)
        {
            cout << hw[ans[i]].s << endl;
        }

    }
    return 0;
}