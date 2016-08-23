#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>

#define N 120
#define M 17000

using namespace std;

struct RE
{
    int l,p,s;
} re[N];

int q[M],l[N],r[N],dp[N][17000],n,k;

inline bool cmp(const RE &a,const RE &b)
{
    return a.s<b.s;
}

void read()
{
    for(int i=1; i<=k; i++)
        scanf("%d%d%d",&re[i].l,&re[i].p,&re[i].s);
    sort(re+1,re+1+k,cmp);

    for(int i=1; i<=k; i++)
    {
        l[i]=max(0,re[i].s-re[i].l);
        r[i]=min(n,re[i].s+re[i].l-1);
    }
}

void go()
{
    for(int i=0; i<=n; i++) dp[0][i]=0;
    for(int i=1; i<=k; i++)
    {
        for(int j=0; j<re[i].s; j++) dp[i][j]=dp[i-1][j]; //第i个粉刷匠不刷任何墙
        int h=0,t=0;
        for(int j=l[i],tmp; j<re[i].s; j++) //将dp[i-1]层的最优状态存入单调队列
        {
            tmp=dp[i-1][j]-j*re[i].p;
            while(t>h&&dp[i-1][q[t-1]]-q[t-1]*re[i].p<=tmp) t--;
            q[t++]=j;
        }
        for(int j=re[i].s,tmp; j<=r[i]; j++)
        {
            while(t>h&&j-q[h]>re[i].l) h++;//弹出不在范围中的元素
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            dp[i][j]=max(dp[i][j],dp[i-1][q[h]]+(j-q[h])*re[i].p);
        }
        for(int j=r[i]+1; j<=n; j++) dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
    int ans=0;
    for(int i=1; i<=n; i++) ans=max(ans,dp[k][i]);
    printf("%d\n",ans);
}

int main()
{
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        read();
        go();
    }
    return 0;
}
