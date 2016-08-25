#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const long long inf=1LL<<62;
const int maxn=110;
const int maxm=maxn*maxn*2;
int n,cnt;
long long h[maxn],s[maxm],dp[maxn][maxm],d;
int q[maxm];
void Init()
{
    for(int i=0;i<=n;i++)
        for(int j=0;j<cnt;j++)
            dp[i][j]=inf;
}
void solve()
{
    Init();
    int ind=lower_bound(s,s+cnt,h[1])-s;
    dp[1][ind]=0;
    for(int i=2;i<=n;i++)
    {
        int pre=0,last=0,now=0;
        for(int j=0;j<cnt;j++)
        {
            while(now<cnt&&s[now]<=s[j]+d)
            {
                while(pre<last&&dp[i-1][q[last-1]]>=dp[i-1][now])
                    last--;
                q[last++]=now++;
            }
            while(pre<last&&s[j]-d>s[q[pre]])
                pre++;
            dp[i][j]=abs(h[i]-s[j])+dp[i-1][q[pre]];
        }
    }
    ind=lower_bound(s,s+cnt,h[n])-s;
    if(dp[n][ind]>=inf)
        printf("impossible\n");
    else
        printf("%I64d\n",dp[n][ind]);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        cnt=0;
        scanf("%d%I64d",&n,&d);
        for(int i=1;i<=n;i++)
            scanf("%I64d",&h[i]);
        for(int i=1;i<=n;i++)
            for(long long j=0;j<n;j++)
            {
                s[cnt++]=h[i]-j*d;
                s[cnt++]=h[i]+j*d;
            }
        sort(s,s+cnt);
        cnt=unique(s,s+cnt)-s;
        solve();
    }
    return 0;
}
