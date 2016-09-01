#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<stack>
#include<queue>
#include<vector>
#include<map>
#include<ctime>
using namespace std;
const int MAX=1005;
const int inf=1<<26;
struct node 
{
    int v,w,next;
}g[MAX*100];
int adj[MAX],e,vis1[MAX],vis2[MAX],kind[MAX],n,m;
int dis[MAX],fa[MAX],pre[MAX];
int flag[MAX];
bool pos[MAX],found;
void add(int u,int v,int w)
{
    g[e].v=v; g[e].w=w; g[e].next=adj[u]; adj[u]=e++;
}
void spfa(int s,int t,int k)
{
    int i,u,v;
    queue<int>que;
    for(i=0;i<=n;i++)
        dis[i]=inf;
    if(k)
        memset(pre,-1,sizeof(pre));
    dis[s]=0;
    memset(vis1,0,sizeof(vis1));
    vis1[s]=1;
    que.push(s);
    while(!que.empty())
    {
        u=que.front();
        que.pop();
        vis1[u]=0;
        for(i=adj[u];i!=-1;i=g[i].next)
        {
            v=g[i].v;
            if(vis2[kind[v]])
                continue;
            if(dis[v]>dis[u]+g[i].w)
            {
                dis[v]=dis[u]+g[i].w;
                pre[v]=u;
                if(!vis1[v])
                {
                    vis1[v]=1;
                    que.push(v);
                }
            }
        }
    }
}                
bool check()
{
    for(int i=0;i<MAX;i++)
        if(flag[i]>1)
            return false;
    return true;
}
bool dfs(int u,int now,int limit,int t)
{
    if(now>limit)
        return false;
    if(u==t)
        return true;
    spfa(u,t,0);
    if(now+dis[t]>limit)
        return false;
    int i,v;
    for(i=adj[u];i!=-1;i=g[i].next)
    {
        v=g[i].v;
        if(vis2[kind[v]])
            continue;
        vis2[kind[v]]=1;
        if(dfs(v,now+g[i].w,limit,t))
            return true;
        vis2[kind[v]]=0;
    }
    return false;
}
void solve(int s,int t,int sum)
{
    int l=1,r=sum,ans=-1,mid;
    while(l<=r)
    {
        mid=(l+r)>>1;
        memset(vis2,0,sizeof(vis2));
        vis2[kind[s]]=1;
        if(dfs(s,0,mid,t))
        {
            ans=mid;
            r=mid-1;
        }
        else
            l=mid+1;
    }
    printf("%d\n",ans);
}
inline int nextInt()
{
    int res = 0; char ch;
    bool neg = false;
    while (ch = getchar(), (ch < '0' || ch > '9') && ch != '-');
    if (ch == '-') neg = true;
    else res = ch - '0';
    while (ch = getchar(), ch >= '0' && ch <= '9') res = res * 10 + ch - '0';
    if (neg) res = - res;
    return res;
}
int main()
{
    int i,j,k,T,s,t,sum=0;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d%d",&n,&m,&s,&t);
        memset(adj,-1,sizeof(adj));
        e=0;
        while(m--)
        {
            i=nextInt(); j=nextInt(); k=nextInt();
            add(i,j,k); add(j,i,k);
            sum+=k;
        }
        for(i=0;i<n;i++)
        {
            kind[i]=nextInt();
        }
        if(s==t)
        {
            puts("0");
            continue;
        }
        memset(vis2,0,sizeof(vis2));
        vis2[kind[t]]=1;
        spfa(t,s,1);
        memset(flag,0,sizeof(flag));
        if(pre[s]==-1)
        {
            puts("-1");
            continue;
        }
        for(i=s;i!=-1;i=pre[i])
        {
            flag[kind[i]]++;
        }
        if(check())
        {
            printf("%d\n",dis[s]);
            continue;
        }
        solve(s,t,sum);
    }
    return 0;
}
