#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;
#define N 205
#define M 4050
#define inf 0x3f3f3f3f
struct edge
{
    int v,flow,next;
};
edge e[M];
int head[N],total;
int in[N];//搴
int dis[N];
void init()
{
    memset(head,-1,sizeof(head));
    memset(in,0,sizeof(in));
    total=0;
}
void add(int u,int v,int val)
{
    e[total].v=v,e[total].flow=val,e[total].next=head[u],head[u]=total++;
    e[total].v=u,e[total].flow=0,e[total].next=head[v],head[v]=total++;
}
bool bfs(int st,int en)
{
    memset(dis,0,sizeof(dis));
    queue<int>q;
    q.push(st);
    dis[st]=1;
    while(!q.empty())
    {
        int u=q.front();q.pop();
        if(u==en) return true;
        for(int i=head[u];i>=0;i=e[i].next)
        {
            int v=e[i].v;
            if(e[i].flow && dis[v]==0)
            {
                dis[v]=dis[u]+1;
                q.push(v);
            }
        }
    }
    return false;
}
int dfs(int u,int cur_flow,int en)
{
    if(u==en) return cur_flow;
    int sum=0;
    for(int i=head[u];i>=0 && sum<cur_flow;i=e[i].next)
    {
        int v=e[i].v;
        if(e[i].flow >0 && dis[v]==dis[u]+1)
        {
            int tmp=dfs(v,min(cur_flow-sum,e[i].flow),en);
            e[i].flow-=tmp;
            e[i^1].flow+=tmp;
            sum+=tmp;
        }
    }
    if(!sum) dis[u]=0;
    return sum;
}
int dinic(int st,int en)
{
    int ans=0;
    int tmp;
    while(bfs(st,en))
    {
        while(tmp=dfs(st,inf,en))
            ans+=tmp;
    }
    return ans;
}
int main()
{
    int  tcase,n,m,sum,flag;
    int u,v,c;
    scanf("%d",&tcase);
    while(tcase--)
    {
        init();
        sum=0;
        scanf("%d%d",&n,&m);
        while(m--)
        {
            scanf("%d%d%d",&u,&v,&c);
            --in[u],++in[v];
            if(!c)
                add(u,v,1);
        }
        flag=true;
        for(int i=1;i<=n;i++)
        {
            if(in[i]&1)
            {
                flag=false;
                break;
            }
        }
        if(flag)
        {
            for(int i=1;i<=n;i++)
            {
                if(in[i]<0)
                    add(0,i,(-in[i])>>1);
                if(in[i]>0)
                {
                    add(i,n+1,in[i]>>1);
                    sum+=(in[i]>>1);
                }
            }
            flag=(sum==dinic(0,n+1));
        }
        if(flag)
            puts("possible");
        else
            puts("impossible");
    }
    return 0;
}
