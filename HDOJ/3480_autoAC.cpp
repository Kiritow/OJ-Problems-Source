#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
#define maxn 10005
int save[maxn],q[maxn],sum[maxn],dp[5005][maxn],ans;
int n,m,h,t;
int M(int k){return k*k;}
void solve()
{
    for(int i=1;i<=n;i++)
    {
        dp[1][i]=M(save[i]-save[1]);
    }
    for(int i=2;i<=m;i++)
    {
        h=t=1;
        q[1]=0;
        q[++t]=i-1;
        for(int j=i;j<=n;j++)
        {
            while(h<t)
            {
                int p1 = q[h], p2 = q[h+1];
                int x1 = save[p1+1],x2=save[p2+1];
                int y1 = dp[i-1][p1]+x1*x1 , y2=dp[i-1][p2]+x2*x2;
                if(y2-y1<2*save[j]*(x2 - x1))
                    h++;
                else
                    break;
            }
            int k = q[h];
            dp[i][j] = dp[i - 1][k]+(save[j]-save[k+1]) * (save[j]-save[k+1]);
            while(h< t && j != n)
            {
                 int p1 = q[t-1], p2 = q[t], p3 = j;
                 int x1 = save[p1+1] , x2=save[p2+1] , x3=save[p3+1];
                 int y1 = dp[i-1][p1]+x1*x1, y2=dp[i-1][p2] + x2 * x2, y3 = dp[i - 1][p3] + x3 * x3;
                 if((y3 - y2) * (x2 - x1) <= (y2 - y1) * (x3 - x2))
                     t--;
                 else
                     break;
            }
            q[++t] = j;
        }
    }
    ans=dp[m][n];
}
int main()
{
    int cas;
    scanf("%d",&cas);
    for(int k=1;k<=cas;k++)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&save[i]);
        }
        sort(save+1,save+1+n);
        solve();
        printf("Case %d: %d\n",k, ans);
    }
    return 0;
}
