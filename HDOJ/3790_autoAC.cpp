#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
#define INF 0x7fffffff
int n,m;
int map[1005][1005];
int cost[1005][1005];
void dijkstra(int st,int ed)
{
    int i,j,v,Min;
    int visit[1005],dis[1005],value[1005];
    for(i=1;i<=n;i++)
    {
        dis[i]=map[st][i];
        value[i]=cost[st][i];
    }
    memset(visit,0,sizeof(visit));
    visit[st]=1;
    for(i=1;i<n;i++)
    {
        Min=INF;
        for(j=1;j<=n;j++)
        if(!visit[j]&&dis[j]<Min)
        {
            v=j;
            Min=dis[j];
        }
        visit[v]=1;
        for(j=1;j<=n;j++)
        {
            if(!visit[j]&&map[v][j]<INF)
            {
                if(dis[j]>dis[v]+map[v][j])
                {
                    dis[j]=dis[v]+map[v][j];
                    value[j]=value[v]+cost[v][j];
                }
                else if(dis[j]==dis[v]+map[v][j])
                {
                    if(value[j]>value[v]+cost[v][j])
                    value[j]=value[v]+cost[v][j];
                }
            }
        }
    }
    printf("%d %d\n",dis[ed],value[ed]);
}
int main()
{
    int i,j,st,ed;
    int a,b,c,d;
    while(scanf("%d%d",&n,&m),n||m)
    {
        for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            map[i][j]=INF;
            cost[i][j]=INF;
        }
        while(m--)
        {
            scanf("%d%d%d%d",&a,&b,&c,&d);
            if(map[a][b]>c)
            {
                map[a][b]=map[b][a]=c;
                cost[a][b]=cost[b][a]=d;
            }
            else if(map[a][b]==c)
            {
                if(cost[a][b]>d)
                cost[a][b]=cost[b][a]=d;
            }
        }
        scanf("%d%d",&st,&ed);
        dijkstra(st,ed);
    }
    return 0;
}
