#include<stdio.h>
#include<string.h>
#define max(a,b)(a)>(b)?(a):(b)
#define INF 0x3f3f3f3f
int g[155][155];
int dp[1<<16][16];
int num[22];
int earn[22];
int cost[22];
int main()
{
    int t,i,j,k,mon,n,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&mon);
        memset(g,INF,sizeof(g));
        for(i=1;i<=n;i++)
            g[i][i]=0;
        int a,b,c;
        while(m--)
        {
            scanf("%d%d%d",&a,&b,&c);
            if(c<g[a][b])
                g[a][b]=g[b][a]=c;
        }
        for(k=1;k<=n;k++)
            for(i=1;i<=n;i++)
                if(g[i][k]!=INF)
                  for(j=1;j<=n;j++)
                         if(g[k][j]!=INF&&g[i][k]+g[k][j]<g[i][j])
                            g[i][j]=g[i][k]+g[k][j];
        memset(dp,-1,sizeof(dp));
        int h,tmp;
        scanf("%d",&h);
        for(i=0;i<h;i++)
            scanf("%d%d%d",&num[i],&earn[i],&cost[i]);
        for(i=0;i<h;i++)
        {
            tmp=mon-g[1][num[i]]-cost[i];
            if(tmp>=0)
                dp[1<<i][i]=tmp+earn[i];
        }
        int st=(1<<h)-1;
        for(i=1;i<=st;i++)
            for(j=0;j<h;j++)
            {
                if(dp[i][j]<0)
                    continue;
                for(k=0;k<h;k++)
                {
                    if(i&(1<<k))
                        continue;
                    tmp=dp[i][j]-g[num[j]][num[k]]-cost[k];
                    if(tmp>=0)
                    {
                        tmp+=earn[k];
                        int stat=i+(1<<k);
                        dp[stat][k]=max(dp[stat][k],tmp);
                    }
                }
            }
        int flag=0;
        for(i=0;i<h;i++)
        {
            tmp=dp[st][i]-g[num[i]][1];
            if(tmp>=0)
            {
                flag=1;
                break;
            }
        }
        if(flag)
            printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
