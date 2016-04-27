/* ***********************************************
Author        :devil
Created Time  :2016/4/26 22:47:45
************************************************ */
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <stdlib.h>
using namespace std;
#define inf 0x3f3f3f3f
#define maxn 1010
struct node
{
    int v,d;
    node(int a=0,int b=0):v(a),d(b){}
    bool operator < (const node &a) const
    {
        return d>a.d;
    }
};
struct edge
{
    int v,cost;
    edge(int a=0,int b=0):v(a),cost(b){}
};
vector<edge> eg[maxn];
bool vis[maxn];
int n,m,s,a,b,t,c,dis[maxn],ss[maxn],tt[maxn];
void dijkstra(int x)
{
    memset(vis,false,sizeof(vis));
    for(int i=0; i<=n; i++)
        dis[i]=inf;
    priority_queue<node>q;
    while(!q.empty()) q.pop();
    dis[x]=0;
    q.push(node(x,0));
    node tmp;
    while(!q.empty())
    {
        tmp=q.top();
        q.pop();
        int u=tmp.v;
        if(vis[u]) continue;
        vis[u]=true;
        for(int i=0; i<eg[u].size(); i++)
        {
            int v=eg[tmp.v][i].v;
            int cost=eg[u][i].cost;
            if(!vis[v]&&dis[v]>dis[u]+cost)
            {
                dis[v]=dis[u]+cost;
                q.push(node(v,dis[v]));
            }
        }
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    while(~scanf("%d%d%d%d",&n,&m,&s,&t)&&n)
    {
        for(int i=1;i<=n;i++)
            eg[i].clear();
        while(m--)
        {
            scanf("%d%d%d",&a,&b,&c);
            eg[a].push_back(edge(b,c));
            eg[b].push_back(edge(a,c));
        }
        for(int i=1;i<=s;i++)
            scanf("%d",&ss[i]);
        for(int i=1;i<=t;i++)
            scanf("%d",&tt[i]);
        int ans=inf;
        for(int i=1;i<=s;i++)
        {
            dijkstra(ss[i]);
            for(int j=1;j<=t;j++)
                ans=min(ans,dis[tt[j]]);
        }
        if(ans!=inf) printf("%d\n",ans);
        else printf("What a pity!\n");
    }
    return 0;
}
