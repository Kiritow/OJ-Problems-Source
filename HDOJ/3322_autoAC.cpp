#include <iostream>
#include <cmath>
#include <algorithm>
#include <string.h> 
using namespace std;
const int MAXN = 501;
struct data { double x,y;
}p[MAXN];
inline double sqr(double x)
{
    return x * x;
}
double dis(int a,int b)
{
    return sqrt(sqr(p[a].x - p[b].x) + sqr(p[a].y - p[b].y));
}
bool cmp(data a,data b)
{
    return a.x == b.x ? a.y < b.y : a.x < b.x;
}
int main()
{
    int n;
    double dp[MAXN][MAXN];
    while (scanf("%d",&n) != EOF && n)
    {
        for (int i = 1;i <= n;i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        sort(p,p+n+1,cmp);
        memset(dp,0,sizeof(dp));
        for (int i = 0;i <= n;i++)
            for (int j = 0;j <= n;j++)
                dp[i][j] = 1e20;
        dp[0][0] = 0;
        for (int i = 0;i < n;i++)
            for (int j = 0;j <= i;j++)
            {
                dp[i+1][j] = min(dp[i+1][j],dp[i][j] + dis(i,i+1));
                dp[i+1][i] = min(dp[i+1][i],dp[i][j] + dis(j,i+1));
            }
        double ans = 1e20;
        for (int i = 0;i <= n;i++)
        {
            if (dp[n][i] + dis(i,n) < ans)
                ans = dp[n][i] + dis(i,n);
        }
        printf("%.2lf\n",ans);
    }
}
