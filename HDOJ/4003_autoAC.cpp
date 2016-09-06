#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<iostream>
using namespace std;
const int MAXN=10010;
struct Node
{
    int to;
    int next;
    int cost;
}edge[MAXN*2];
int head[MAXN];
int tol;
int dp[MAXN][11];
void init()
{
    memset(head,-1,sizeof(head));
    tol=0;
    memset(dp,0,sizeof(dp));
}
void add(int a,int b,int val)
{
    edge[tol].to=b;
    edge[tol].cost=val;
    edge[tol].next=head[a];
    head[a]=tol++;
    edge[tol].to=a;
    edge[tol].cost=val;
    edge[tol].next=head[b];
    head[b]=tol++;
}
int N,K;
void dfs(int u,int pre)
{
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==pre)continue;
        dfs(v,u);
        for(int k=K;k>=0;k--)
        {
            dp[u][k]+=dp[v][0]+2*edge[i].cost;
            for(int j=1;j<=k;j++)
              dp[u][k]=min(dp[u][k],dp[u][k-j]+dp[v][j]+j*edge[i].cost);
        }
    }
}
int main()
{
    int S;
    int a,b,val;
    while(scanf("%d%d%d",&N,&S,&K)!=EOF)
    {
        init();
        for(int i=1;i<N;i++)
        {
            scanf("%d%d%d",&a,&b,&val);
            add(a,b,val);
        }
        dfs(S,-1);
        printf("%d\n",dp[S][K]);
    }
    return 0;
}
