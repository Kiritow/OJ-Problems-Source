#include <iostream>
#include <stdio.h>
#include <queue>
#include <string.h>
#include <stdlib.h>
#include <set>
using namespace std;
const int maxn=200000*5,inf=0x3f3f3f3f;
struct Edge
{
    int v,next,cap;

} edge[maxn];
int tot,head[maxn];
int vis[maxn],du[maxn],dis[maxn];
void init()
{
    tot=0;
    memset(head,-1,sizeof(head));
}
void add_edge(int u,int v,int cap)
{
    edge[tot].v=v;
    edge[tot].cap=cap;
    edge[tot].next=head[u];
    head[u]=tot++;
}
void bfs(int start,int n)
{
    set<int>s1;
    set<int>s2;
    set<int>::iterator it;
    for(int i=1;i<=n;i++)
    {
        if(i!=start)
            s1.insert(i);
    }

    queue<int>que;
    que.push(start);
    dis[start]=0;
    while(!que.empty())
    {
        int u=que.front();
        que.pop();
            for(int i=head[u];i!=-1;i=edge[i].next)
            {
                int v=edge[i].v;
                if(!s1.count(v))
                    continue;
                s1.erase(v);
                s2.insert(v);

            }
            for(it=s1.begin();it!=s1.end();it++)
            {
                que.push(*it);
                dis[*it]=dis[u]+1;
            }
            s1.swap(s2);
            s2.clear();
    }
}
int main()
{
    int s,n,t,m;
    int u,v;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        init();
        memset(du,0,sizeof(du));
        for(int i=0; i<m; i++)
        {
            scanf("%d%d",&u,&v);
            add_edge(u,v,1);
            add_edge(v,u,1);
        }
         scanf("%d",&s);
        bfs(s,n);

        for(int i=1; i<=n; i++)
        {
            if(i==s)
                continue;
            if(dis[i]==inf)
                dis[i]=-1;

            printf("%d",dis[i]);
            if(i==n)
                printf("\n");
            else
                printf(" ");
        }
    }
    return 0;
}
