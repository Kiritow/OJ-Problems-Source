#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#include<cctype>
#include<string>
#include<algorithm>
#include<iostream>
#include<ctime>
#include<map>
#include<set>
using namespace std;
#define MP(x,y) make_pair((x),(y))
#define PB(x) push_back(x)
typedef __int64 LL;
const int INF=100011122;
const double INFF=1e100;
const double eps=1e-8;
const LL mod=1000000007;
const int NN=30010;
const int MM=60010;
struct G
{
    int v,w,next;
}E1[MM*2],E[NN*2];
int p[NN],T;
int p1[NN],T1;
bool inq[NN];
int dis[NN];
struct node
{
    int x,dis;
    node(int a=0,int b=0):x(a),dis(b){}
    bool operator<(const node &tt)const
    {
        return dis>tt.dis;
    }
};
int ans,limit;
LL ans_cnt;
int si[NN],m_si[NN],a[NN],tol;
bool vis[NN];
int re[NN],re_num[NN],t_re[NN],t_re_num[NN];
void add1(int u,int v,int w)
{
    E1[T1].v=v;
    E1[T1].w=w;
    E1[T1].next=p1[u];
    p1[u]=T1++;
}
void add(int u,int v,int w)
{
    E[T].v=v;
    E[T].w=w;
    E[T].next=p[u];
    p[u]=T++;
}
void dij(int st,int n)
{
    priority_queue<node>q;
    int i,j,v;
    for(i=1;i<=n;i++)
    {
        dis[i]=INF;
        inq[i]=false;
    }
    dis[st]=0;
    q.push( node(st,0) );
    while(!q.empty())
    {
        node ix = q.top();
        q.pop();
        if( inq[ ix.x ] )continue;
        inq[ ix.x ]=true;
        for(i=p1[ix.x];i+1;i=E1[i].next)
        {
            v=E1[i].v;
            if(dis[v]>dis[ix.x]+E1[i].w)
            {
                dis[v]=dis[ix.x]+E1[i].w;
                q.push( node(v,dis[v]) );
            }
        }
    }
    memset(p,-1,sizeof(p));
    T=0;
    for(i=1;i<=n;i++)
        inq[i]=false;
    inq[st]=true;
    for(i=1;i<=n;i++)
    {
        for(j=p1[i];j+1;j=E1[j].next)
        {
            v=E1[j].v;
            if(dis[i]+E1[j].w==dis[v] && !inq[v])
            {
                inq[v]=true;
                add(i,v,E1[j].w);
                add(v,i,E1[j].w);
            }
        }
    }
}
void dfs_fr(int u,int fa)
{
    int i,v;
    si[u]=1;
    m_si[u]=0;
    a[++tol]=u;
    for(i=p[u];i+1;i=E[i].next)
    {
        v=E[i].v;
        if(v==fa || vis[v])continue;
        dfs_fr(v,u);
        si[u]+=si[v];
        m_si[u]=max(m_si[u],si[v]);
    }
}
void dfs(int u,int fa,int ge,int d)
{
    int i,v;
    if(d>t_re[ge])
    {
        t_re[ge]=d;
        t_re_num[ge]=1;
    }
    else if(d==t_re[ge])
        t_re_num[ge]++;
    for(i=p[u];i+1;i=E[i].next)
    {
        v=E[i].v;
        if(v==fa || vis[v])continue;
        dfs(v,u,ge+1,d+E[i].w);
    }
}
void goo(int x,LL ci)
{
    if(x>ans)
    {
        ans=x;
        ans_cnt=ci;
    }
    else if(x==ans)
    {
        ans_cnt+=ci;
    }
}
void solve(int root)
{
    tol=0;
    dfs_fr(root,-1);
    int i,j,t,v,new_root=root;
    int m=m_si[root];
    for(i=1;i<=tol;i++)
    {
        t=max(m_si[a[i]],tol-si[a[i]]);
        if(m>t)
        {
            m=t;
            new_root=a[i];
        }
    }
    dfs_fr(new_root,-1);
    m = m_si[new_root];
    for(i=1;i<=m;i++)
    {
        re[i]=-INF;
        re_num[i]=0;
    }
    for(i=p[new_root];i+1;i=E[i].next)
    {
        v=E[i].v;
        if(vis[v])continue;
        for(j=1;j<=si[v];j++)
        {
            t_re[j]=-INF;
            t_re_num[j]=0;
        }
        dfs(v,new_root,1,E[i].w);
        for(j=1;j<=si[v];j++)
        {
            if(j+1==limit)
                goo(t_re[j],t_re_num[j]);
            t=limit-1-j;
            if(1<=t && t<=m)
                goo(t_re[j]+re[t],(LL)t_re_num[j]*re_num[t]);
        }
        for(j=1;j<=si[v];j++)
        {
            if(re[j]<t_re[j])
            {
                re_num[j]=t_re_num[j];
                re[j]=t_re[j];
            }
            else if(re[j]==t_re[j])
                re_num[j]+=t_re_num[j];
        }
    }
    vis[new_root]=true;
    for(i=p[new_root];i+1;i=E[i].next)
    {
        v=E[i].v;
        if(vis[v])continue;
        solve(v);
    }
}
int main()
{
    int cas;
    int n,m,k,u,v,w;
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%d%d%d",&n,&m,&k);
        memset(p1,-1,sizeof(p1));
        T1=0;
        while(m--)
        {
            scanf("%d%d%d",&u,&v,&w);
            add1(u,v,w);
            add1(v,u,w);
        }
        dij(1,n);
        ans=-1;
        memset(vis,false,sizeof(vis));
        limit=k;
        solve(1);
        printf("%d %I64d\n",ans,ans_cnt);
    }
    return 0;
}
