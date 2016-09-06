#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
const int INF=0x3f3f3f3f;
const int MAXN=330;
int cost[MAXN][MAXN];
int dist[MAXN];
int que[MAXN];
bool vis[MAXN];
void SPFA(int start,int n)
{
    int front=0,rear=0;
    for(int v=1;v<=n;v++)
    {
        if(v==start)
        {
            dist[v]=INF;
            vis[v]=false;
        }
        else if(cost[start][v]!=INF)
        {
            dist[v]=cost[start][v];
            que[rear++]=v;
            vis[v]=true;
        }
        else
        {
            dist[v]=INF;
            vis[v]=false;
        }
    }
    while(front!=rear)
    {
        int u=que[front++];
        for(int v=1;v<=n;v++)
        {
            if(dist[v]>dist[u]+cost[u][v])
            {
                dist[v]=dist[u]+cost[u][v];
                if(!vis[v])
                {
                    vis[v]=true;
                    que[rear++]=v;
                    if(rear>=MAXN) rear=0;
                }
            }
        }
        vis[u]=false;
        if(front>=MAXN)front=0;
    }
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
          for(int j=1;j<=n;j++)
            scanf("%d",&cost[i][j]);
        SPFA(1,n);
        int ans=dist[n];
        int loop1=dist[1];
        SPFA(n,n);
        int loopn=dist[n];
        ans=min(ans,loop1+loopn);
        printf("%d\n",ans);
    }
    return 0;
}
