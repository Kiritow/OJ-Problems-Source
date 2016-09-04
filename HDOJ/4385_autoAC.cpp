#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define clr(x)memset(x,0,sizeof(x))
#define min(a,b)(a)<(b)?(a):(b)
#define INF 0x1f1f1f1f
#define N 21
struct node
{
    int x,y;
}p[N],be;
int dis(node a,node b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
int g[N][N];
int dp[1<<N];
int pre[1<<N];
struct ans
{
    int fi,se,num;
}res[N];
bool cmp(ans a,ans b)
{
    return a.fi<b.fi;
}
int main()
{
    int ca=1,n,i,j,k,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&be.x,&be.y);
        scanf("%d",&n);
        p[n]=be;
        for(i=0;i<n;i++)
            scanf("%d%d",&p[i].x,&p[i].y);
        memset(dp,INF,sizeof(dp));
        pre[0]=0;
        int st=1<<n;
        dp[0]=0;
        for(i=0;i<=n;i++)
            for(j=0;j<=n;j++)
                g[i][j]=dis(p[i],p[j]);
        printf("Case %d:\n",ca++);
        int stat,tmp,ss;
        for(i=0;i<st;i++)
        {
            for(j=0;j<n;j++)
            {
                if((1<<j)&i)
                    continue;
                stat=i|(1<<j);
                tmp=dp[i]+g[n][j]*2;
                if(tmp<dp[stat])
                {
                    dp[stat]=tmp;
                    pre[stat]=i;
                }
                for(k=j+1;k<n;k++)
                {
                    if((1<<k)&i)
                        continue;
                    ss=stat|(1<<k);
                    tmp=dp[i]+g[n][j]+g[j][k]+g[n][k];
                    if(tmp<dp[ss])
                    {
                        dp[ss]=tmp;
                        pre[ss]=i;
                    }
                }
            }
        }
        st-=1;
        printf("%d\n",dp[st]);
        int top=0;
        while(st)
        {
            stat=pre[st]^st;
            st=pre[st];
            res[top].num=0;
            for(i=0;i<n;i++)
                if((1<<i)&stat)
                {
                    res[top].num++;
                    if(res[top].num==1)
                        res[top].fi=i+1;
                    else res[top].se=i+1;
                }
            top++;
        }
        sort(res,res+top,cmp);
        for(i=0;i<top;i++)
        {
            if(res[i].num==1)
                printf("%d%c",res[i].fi,i==top-1?'\n':' ');
            else 
                printf("%d %d%c",res[i].fi,res[i].se,i==top-1?'\n':' ');
        }
    }
    return 0;
}
