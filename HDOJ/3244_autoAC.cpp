#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m;
const int maxn = 110;
const int inf = 0x3f3f3f3f;
struct node
{
    int s1,s2;
    int p1,p2;
    int x,y;
}t[maxn];
int cal_r()
{
    int ret=inf;
    for(int i=1;i<=n;i++)
    {
        if(t[i].s1*1.0/t[i].p1 >= t[i].s2*1.0/t[i].p2)
        {
            int tmp = (m/t[i].p1*t[i].s1)+t[i].y;
            int p = tmp/t[i].x;
            ret=min(ret,p);
        }
        else
        {
            int tmp = (m/t[i].p2*t[i].s2)+t[i].y;
            int p = tmp/t[i].x;
            ret=min(ret,p);
        }
    }
    return ret;
}
int dp[6000000+20];
int cal_need(int i,int need)
{
    int w[2],c[2];
    c[0]=t[i].p1;
    w[0]=t[i].s1;
    c[1]=t[i].p2;
    w[1]=t[i].s2;
    int V=need+t[i].s2;
    for(int i=1;i<=V;i++)
        dp[i]=inf;
    dp[0]=0;
    for(int i=0;i<2;i++)
    {
        for(int v=w[i];v<=V;v++)
            dp[v]=min(dp[v],dp[v-w[i]]+c[i]);
    }
    int ret = inf;
    for(int i=need;i<=V;i++)
        ret = min(ret,dp[i]);
    return ret;
}
bool judge(int k)
{
    int s=0;
    for(int i=1;i<=n;i++)
    {
        int need = t[i].x*k-t[i].y;
        if(need<=0)
            continue;
        int tmp = cal_need(i,need);
        s+=tmp;
        if(s>m)
            return false;
    }
    return true;
}
int main()
{
    while(~scanf("%d%d",&n,&m) && n+m)
    {
        for(int i=1;i<=n;i++)
            scanf("%d%d%d%d%d%d",&t[i].x,&t[i].y,&t[i].s1,&t[i].p1,&t[i].s2,&t[i].p2);
        int r=cal_r();
        int l=0;
        int ans = 0;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if(judge(mid))
            {
                ans=mid;
                l=mid+1;
            }
            else
                r=mid-1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
