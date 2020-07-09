#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int N;
int M;
int minArea = 1 << 30;
int area = 0;
int F[30] = {0};
void dfs(int v, int n, int r, int h)
{
    if (n == 0)
    {
        if (v)
            return;
        else
        {
            minArea = min(minArea, area);
            return;
        }
    }
    if (v <= 0 || area >= minArea || F[n] > v)
        return;

    for(int rr = r; rr >= n; rr--)
    {
        if(n == M)
            area = rr * rr;
        for(int hh = h; hh >= n; hh--)
        {
            area += 2 * rr * hh;
            dfs(v - rr * rr * hh, n - 1, rr - 1, hh - 1);
            area -= 2 * rr * hh;
        }
    }

}

int main()
{
    cin >> N >> M;
    int maxR, maxH;
    for (int i = 1; i < 20; ++i)
    {
        F[i] = i*i*i + F[i - 1];
    }
    maxR = sqrt((N - F[M - 1]) / M);
    maxH = (N - F[M - 1]) / M / M;
    dfs(N, M, maxR, maxH);
    if (minArea == 1 << 30)
        cout << 0 << endl;
    else
        cout << minArea << endl;
    return 0;
}


/*
#include<stdio.h>
#include<math.h>

int n,m,min=0x1FFFFFFF,minV[21],minS[21],maxV;

void dfs(int n,int m,int max_r,int max_h,int sum_rh,int R)
{
    if (m==1)
    {
        if (max_r*max_r*max_h<n)
            return;
        for (int r=max_r;r*r>=n/max_h && r>=1;r--)
            if (n%(r*r)==0)
                if (2*(sum_rh+n/r)+R*R<min)
                    min=2*(sum_rh+n/r)+R*R;
        return;
    }
    for (int r=max_r;r>=m;r--)
        for (int h=max_h;h>=m;h--)
        {
            maxV=0;
            for (int i=1;i<m;i++)
                maxV+=(r-i)*(r-i)*(h-i);
            if (n-r*r*h<minV[m-1] || maxV<n-r*r*h) 
                continue;
            if (R*R+2*(sum_rh+r*h+minS[m-1])>=min)
                continue;
            dfs(n-r*r*h,m-1,r-1,h-1,sum_rh+r*h,R);
        }
    return;
}

int main()
{
    scanf("%d%d\n",&n,&m);
    minV[0]=0;
    minS[0]=0;
    for (int i=1;i<=20;i++)
        minV[i]=minV[i-1]+i*i*i;
    for (int i=1;i<=20;i++)
        minS[i]=minS[i-1]+i*i;
    for (int R=floor(sqrt(n)+1e-5);R>=m;R--)
        dfs(n,m,R,n/R,0,R);
    printf("%d\n",min!=0x1FFFFFFF?min:0);
    return 0;
}

*/