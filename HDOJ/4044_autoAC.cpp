#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
const int MAXN=1010;
const int INF=0x3fffffff;
struct Node
{
    int to;
    int next;
}edge[MAXN*2];
int tol;
int head[MAXN];
int dp[MAXN][220];
int price[MAXN][60];
int power[MAXN][60];
void init()
{
    memset(head,-1,sizeof(head));
    tol=0;
}
void add(int a,int b)
{
    edge[tol].to=b;
    edge[tol].next=head[a];
    head[a]=tol++;
    edge[tol].to=a;
    edge[tol].next=head[b];
    head[b]=tol++;
}
int n,m;
int tmp[MAXN];
void dfs(int u,int pre)
{
    if(head[u]==-1||(edge[head[u]].to==pre&&edge[head[u]].next==-1))
    {
        for(int i=0;i<=m;i++)dp[u][i]=0;
        for(int i=0;i<=m;i++)tmp[i]=dp[u][i];
        for(int i=m;i>=0;i--)
        {
            for(int j=1;j<=price[u][0];j++)
               if(price[u][j]<=i)
                 dp[u][i]=max(dp[u][i],tmp[i-price[u][j]]+power[u][j]);
            tmp[i]=dp[u][i];
        }
        return;
    }
    for(int i=0;i<=m;i++) dp[u][i]=INF;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==pre)continue;
        dfs(v,u);
        for(int j=m;j>=0;j--)
        {
            int t=0;
            for(int k=0;k<=j;k++)
              t=max(t,min(dp[u][j-k],dp[v][k]));
            dp[u][j]=t;
        }
    }
    for(int i=0;i<=m;i++)tmp[i]=dp[u][i];
    for(int i=m;i>=0;i--)
    {
        for(int j=1;j<=price[u][0];j++)
          if(price[u][j]<=i)
             dp[u][i]=max(dp[u][i],tmp[i-price[u][j]]+power[u][j]);
        tmp[i]=dp[u][i];
    }
}
int main()
{
    int u,v;
    int T;
    scanf("%d",&T);
    while(T--)
    {
        init();
        scanf("%d",&n);
        for(int i=1;i<n;i++)
        {
            scanf("%d%d",&u,&v);
            add(u,v);
        }
        scanf("%d",&m);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&price[i][0]);
            power[i][0]=price[i][0];
            for(int j=1;j<=price[i][0];j++)
            {
                scanf("%d%d",&price[i][j],&power[i][j]);
            }
        }
        dfs(1,0);
        printf("%d\n",dp[1][m]);
    }
    return 0;
}
