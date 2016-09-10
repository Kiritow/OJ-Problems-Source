#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <math.h>
using namespace std;
const int MAXN = 200010;
int x[MAXN],y[MAXN];
int d;
int n;
int L;
int nowx ;
int nextx;
int r1,l2;
const double eps = 1e-8;
double solve()
{
    double left = nowx,right = nextx;
    double ret1,ret2;
    for(int cc = 0;cc <= 30;cc++)
    {
        double mid = (left + right)/2;
        double midmid = (mid + right)/2;
        double h1 = y[r1] + (double)(y[r1-1] - y[r1]) * (mid  - x[r1])/(x[r1-1] - x[r1]);
        double h2 = y[l2] + (double)(y[l2+1] - y[l2])*(mid + 2*d - x[l2])/(x[l2 + 1] - x[l2]);
        ret1 = (double)(x[r1] - mid)*(h1 + y[r1])/2 + (double)(mid + 2*d - x[l2])*(h2 + y[l2])/2;
         h1 = y[r1] + (double)(y[r1-1] - y[r1]) * (midmid  - x[r1])/(x[r1-1] - x[r1]);
         h2 = y[l2] + (double)(y[l2+1] - y[l2])*(midmid + 2*d - x[l2])/(x[l2 + 1] - x[l2]);
        ret2 = (double)(x[r1] - midmid)*(h1 + y[r1])/2 + (double)(midmid + 2*d - x[l2])*(h2 + y[l2])/2;
        if(ret1 < ret2)
            left = mid+eps;
        else right = midmid-eps;
    }
    return ret1;
}
int input()
{
    char ch;
    ch = getchar();
    while(ch < '0' || ch >'9')
    {
        ch = getchar();
    }
    int ret = 0;
    while(ch >= '0' && ch <= '9')
    {
        ret *= 10;
        ret += ch -'0';
        ch = getchar();
    }
    return ret;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&L);
        for(int i = 1;i <= n;i++)
        {
            scanf("%d%d",&x[i],&y[i]);
        }
        scanf("%d",&d);
        double ans = 0;
         r1 = 2;
         l2 = 1;
        double tmp = 0;
        while(l2 < n && x[l2+1] < 2*d)l2++;
        for(int i = r1;i < l2;i++)
        {
            tmp += (double)(x[i+1] - x[i])*(y[i] + y[i+1])/2;
        }
        if(l2  == 1)
        {
            tmp -= (double)(x[2] - x[1])*(y[2] + y[1])/2;
        }
        x[n+1] = x[n];
        y[n+1] = y[n];
        nowx = 0;
        while(l2 < n && r1 <= n)
        {
            int p1 = x[r1];
            int p2 = x[l2 + 1] - 2*d;
            if(p1 < p2)
                nextx = p1;
            else nextx = p2;
            nextx = min(L- 2*d,nextx);
            ans = max(ans,tmp + solve());
            if(p1 < p2)
            {
                nowx = p1;
                if(r1 < n)tmp -= (double)(x[r1+1] - x[r1])*(y[r1+1] + y[r1] )/2;
                r1++;
            }
            else
            {
                nowx = p2;
                tmp += (double)(x[l2+1] - x[l2])*(y[l2+1] + y[l2])/2;
                l2++;
            }
        }
        printf("%.3lf\n",ans/2/d);
    }
    return 0;
}
