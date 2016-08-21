#include <stdio.h>
#include <iostream>
#include <string.h>
#include <queue>
#define Max 305
#define inf 99999999
using namespace std;
int n,m,k,p;
bool visitedX[Max],visitedY[Max];
int lx[Max],ly[Max];
int Match[Max];
int slack[Max];
int Graph[Max][Max];
int o[Max];
struct node
{
    int adj[Max],w[Max];
    int len;
}list[Max];
void AddAdj(int s,int e,int w)
{
    list[s].adj[list[s].len] = e;
    list[s].w[list[s].len++] = w;
}
void SPFA(int locate)
{
    int dist[Max],i,u,v,w;
    bool visited[Max];
    queue<int>q;
    for(i=1;i<=n+m;i++)
        visited[i] = 0,dist[i] = inf;
    visited[locate] = 1;
    dist[locate] = 0;
    q.push(locate);
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        visited[u] = 0;
        for (i=0;i<list[u].len;i++)
        {
            v = list[u].adj[i];
            w = list[u].w[i];
            if (dist[v]>dist[u]+w)
            {
                dist[v] = dist[u]+w;
                if(!visited[v])
                    q.push(v),visited[v] = 1;
            }
        }
    }
    for (i=m+1;i<=m+n;i++)
    {
        if(dist[i]!=0x7fffffff)
            Graph[locate][i] = -dist[i];
        else
            Graph[locate][i] = 0;
    }
}
bool DFS(int i)
{
    int j,tem;
    visitedX[i] = true;
    for (j=m+1;j<=n+m;j++)
    {
        if (!visitedY[j])
        {
            tem = lx[i]+ly[j]-Graph[i][j];
            if (tem==0)
            {
                visitedY[j] = 1;
                if (Match[j]==-1||DFS(Match[j]))
                {
                    Match[j] = i;
                    return true;
                }
            }
            else if(slack[j]>tem)
                slack[j] = tem;
        }
    }
    return false;
}
void KM()
{
    int i,j,k,min;
    for (i=1;i<=n;i++)
    {
        lx[o[i]] = -inf;
        ly[i+m] = 0;
        Match[i+m] = -1;
        for (j=m+1;j<=m+n;j++)
            if(lx[o[i]]<Graph[o[i]][j])
                lx[o[i]] = Graph[o[i]][j];
    }
    for (k=1;k<=n;k++)
    {
        for(i=m+1;i<=n+m;i++)
            slack[i] = inf;
        while (1)
        {
            min = inf;        
            memset(visitedX,0,sizeof(visitedX));
            memset(visitedY,0,sizeof(visitedY));
            if(DFS(o[k]))
                break;
            for(i=1+m;i<=n+m;i++)
            {
                if(!visitedY[i]&&slack[i]<min)
                    min = slack[i];
            }
            for(i=1;i<=n;i++)
            {
                if(visitedX[o[i]])
                    lx[o[i]]-=min;
                if(visitedY[i+m])
                    ly[i+m]+=min;
                else
                    slack[i+m]-=min;
            }
        }
    }
}
int main()
{
    int i,j,val,sum;
    while (scanf("%d%d%d%d",&n,&m,&k,&p)!=EOF)
    {
        for(i=1;i<=n;i++)
            scanf("%d",&o[i]);
        for(i=1;i<=m;i++)
            list[i].len = 0;
        while (k--)
        {
            scanf("%d%d%d",&i,&j,&val);
            AddAdj(i,j,val);
            AddAdj(j,i,val);
        }
        while (p--)
        {
            scanf("%d%d%d",&i,&j,&val);
            AddAdj(j,i+m,val);
        }
        memset(Graph,0,sizeof(Graph));
        for(i=1;i<=n;i++)
            SPFA(o[i]);
        KM();
        for(sum = 0,i=m+1;i<=n+m;i++)
            sum+=lx[Match[i]]+ly[i];
        printf("%d\n",-sum);
    }
    return 0;
}
