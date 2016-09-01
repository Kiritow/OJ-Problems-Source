#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<queue>
#define inf 0x7fffffff
using namespace std;
const int maxn=600;
const int M = 100000+10;
struct Edge
{
    int to,cap,next;
}edge[M*2];
int head[maxn],edgenum;
int n,m,from,to,vnum,s,t;
void add(int u,int v,int cap)
{
    edge[edgenum].to=v;
    edge[edgenum].cap=cap;
    edge[edgenum].next=head[u];
    head[u]=edgenum++;
    edge[edgenum].to=u;
    edge[edgenum].cap=0;
    edge[edgenum].next=head[v];
    head[v]=edgenum++;
}
int level[maxn];
int gap[maxn];
void bfs(int to)
{
    memset(level,-1,sizeof(level));
    memset(gap,0,sizeof(gap));
    level[to]=0;
    gap[level[to] ]++;
    queue<int> Q;
    Q.push(to);
    while (!Q.empty())
    {
        int u=Q.front() ;Q.pop() ;
        for (int i=head[u] ;i!=-1 ;i=edge[i].next)
        {
            int v=edge[i].to;
            if (level[v] != -1) continue;
            level[v]=level[u]+1;
            gap[level[v] ]++;
            Q.push(v);
        }
    }
}
int cur[maxn];
int pre[maxn];
int SAP(int from,int to)
{
    bfs(to);
    memset(pre,-1,sizeof(pre));
    memcpy(cur,head,sizeof(head));
    int u=pre[from]=from,flow=0,aug=inf;
    gap[from]=vnum;
    while (level[from]<vnum)
    {
        bool flag=false;
        for (int &i=cur[u] ;i!=-1 ;i=edge[i].next)
        {
            int v=edge[i].to;
            if (edge[i].cap && level[u]==level[v]+1)
            {
                flag=true;
                aug=min(aug,edge[i].cap);
                pre[v]=u;
                u=v;
                if (v==to)
                {
                    flow += aug;
                    for (u=pre[u] ;v!=from ;v=u ,u=pre[u])
                    {
                        edge[cur[u] ].cap -= aug;
                        edge[cur[u]^1 ].cap += aug;
                    }
                    aug=inf;
                }
                break;
            }
        }
        if (flag) continue;
        int minlevel=vnum;
        for (int i=head[u] ;i!=-1 ;i=edge[i].next)
        {
            int v=edge[i].to;
            if (edge[i].cap && level[v]<minlevel)
            {
                minlevel=level[v];
                cur[u]=i;
            }
        }
        if (--gap[level[u] ]==0) break;
        level[u]=minlevel+1;
        gap[level[u] ]++;
        u=pre[u];
    }
    return flow;
}
int main()
{
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        if (!n && !m) break;
        memset(head,-1,sizeof(head));
        edgenum=0;
        char c[5],c2[5];
        int u,v;
        int cap,f=M;
        s=0 ;t=n+1 ;from=t+1 ;to=from+1 ;
        vnum=to+1;
        int sum=0;
        for (int i=0 ;i<m ;i++)
        {
            scanf("%s%s%d",&c,&c2,&cap);
            sum += cap;
            if (c[0]=='+') u=s;
            else sscanf(c,"%d",&u);
            if (c2[0]=='-') v=t;
            else sscanf(c2,"%d",&v);
            add(u,v,f-cap);
            add(from,v,cap);
            add(u,to,cap);
        }
        int Maxflow=SAP(from,to);
        int d=edgenum;
        add(t,s,inf);
        Maxflow += SAP(from,to);
        int flag=0;
        for (int i=head[from] ;i!=-1 ;i=edge[i].next)
        {
            if (edge[i].cap) {flag=1;break; }
        }
        if (Maxflow==sum) printf("%d\n",edge[(d^1)].cap);
        else printf("impossible\n");
    }
    return 0;
}
