#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int MAXN=1000010;
struct qnode
{
    int v;
    int c;
    qnode(int _v=0,int _c=0):v(_v),c(_c){}
    bool operator <(const qnode &r)const
    {
        return c>r.c;
    }
};
struct Edge
{
    int v,cost;
    Edge(int _v=0,int _cost=0):v(_v),cost(_cost){}
};
vector<Edge>E[MAXN];
bool vis[MAXN];
int dist[MAXN];
void Dijkstra(int n,int start)
{
    memset(vis,false,sizeof(vis));
    for(int i=1;i<=n;i++)dist[i]=INF;
    priority_queue<qnode>que;
    while(!que.empty())que.pop();
    dist[start]=0;
    que.push(qnode(start,0));
    qnode tmp;
    while(!que.empty())
    {
        tmp=que.top();
        que.pop();
        int u=tmp.v;
        if(vis[u])continue;
        vis[u]=true;
        for(int i=0;i<E[u].size();i++)
        {
            int v=E[tmp.v][i].v;
            int cost=E[u][i].cost;
            if(!vis[v]&&dist[v]>dist[u]+cost)
            {
                dist[v]=dist[u]+cost;
                que.push(qnode(v,dist[v]));
            }
        }
    }
}
void addedge(int u,int v,int w)
{
    E[u].push_back(Edge(v,w));
}
int main()
{
    int T;
    int N,M,C;
    scanf("%d",&T);
    int iCase = 0;
    while(T--)
    {
        scanf("%d%d%d",&N,&M,&C);
        for(int i = 1;i <= 3*N;i++) E[i].clear();
        int u,v,w;
        for(int i = 1;i <= N;i++)
        {
            scanf("%d",&u);
            addedge(i,N + 2*u - 1,0);
            addedge(N + 2*u ,i,0);
        }
        for(int i = 1;i < N;i++)
        {
            addedge(N + 2*i-1,N + 2*(i+1),C);
            addedge(N + 2*(i+1)-1,N + 2*i,C);
        }
        while(M--)
        {
            scanf("%d%d%d",&u,&v,&w);
            addedge(u,v,w);
            addedge(v,u,w);
        }
        Dijkstra(3*N,1);
        iCase++;
        if(dist[N] == INF)dist[N] = -1;
        printf("Case #%d: %d\n",iCase,dist[N]);
    }
    return 0;
}
