#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<vector>
#include<bitset>
#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define eps 1e-6
#define pi acos(-1.0)
using namespace std;
typedef long long ll;
const int maxn=100000+10;
const int Msize=61;
int ch[maxn*Msize][2],size[maxn*Msize],tot;
ll val[maxn*Msize],p[Msize];
void Init()
{
    ch[0][0]=ch[0][1]=0;
    tot=size[0]=0;
    val[0]=-1;
}
void Insert(ll x)
{
    int u=0;
    for(int i=Msize-1;i>=0;--i)
    {
        int c=(x&p[i])>0;
        if(!ch[u][c])
        {
            ch[u][c]=++tot;
            ch[tot][0]=ch[tot][1]=0;
            size[tot]=0;val[tot]=-1;
        }
        u=ch[u][c];
        size[u]++;
    }
    val[u]=x;
}
struct Edge
{
    int v;
    ll w;
    int next;
    Edge(int v=0,ll w=0,int next=0):v(v),w(w),next(next){}
}edges[maxn<<1];
struct Query
{
    int id,k;
    bool operator <(const Query &a) const
    {
        return k<a.k;
    }
}querys[maxn];
int head[maxn],nEdge,n,m;
ll xv[maxn],ans[maxn];
void AddEdges(int u,int v,ll w)
{
    edges[++nEdge]=Edge(v,w,head[u]);
    head[u]=nEdge;
    edges[++nEdge]=Edge(u,w,head[v]);
    head[v]=nEdge;
}
void dfs(int u,int fa,ll now)
{
    xv[u]=now;
    Insert(now);
    for(int k=head[u];k!=-1;k=edges[k].next)
    {
        int v=edges[k].v;
        if(v==fa) continue;
        dfs(v,u,now^edges[k].w);
    }
}
struct Node
{
    int k;
    ll num,mxv;
    bool operator <(const Node &a) const
    {
        return mxv<a.mxv;
    }
    bool next()
    {
        k++;
        if(k>=n) return false;
        int kk=k,u=0;
        for(int dep=Msize-1;dep>=0;--dep)
        {
            int c=((num&p[dep])>0)^1;
            int v=ch[u][c];
            if(v&&size[v]>=kk) u=ch[u][c];
            else if(v&&size[v]<kk)
            {
                kk-=size[v];
                u=ch[u][c^1];
            }
            else u=ch[u][c^1];
        }
        mxv=val[u]^num;
        return true;
    }
};
void solve()
{
    sort(querys,querys+m);
    priority_queue<Node>q;
    Node node;
    for(int i=1;i<=n;++i)
    {
        node.k=0;
        node.num=xv[i];
        if(node.next()) q.push(node);
    }
    memset(ans,0xff,sizeof(ans));
    int rank=0;
    ll tmp;
    for(int i=0;i<m;++i)
    {
        while(!q.empty()&&rank<querys[i].k)
        {
            rank++;
            node=q.top();q.pop();
            tmp=node.mxv;
            if(node.next()) q.push(node);
        }
        if(querys[i].k==rank&&querys[i].k!=(ll)n*(n-1))
            ans[querys[i].id]=tmp;
    }
}
int main()
{
    p[0]=1;
    for(int i=1;i<Msize;++i) p[i]=p[i-1]<<1;
    while(~scanf("%d",&n))
    {
        if(n==0) break;
        memset(head,0xff,sizeof(head));
        nEdge=-1;
        Init();
        int u,v;
        ll w;
        for(int i=1;i<n;++i)
        {
            scanf("%d%d%I64d",&u,&v,&w);
            AddEdges(u,v,w);
        }
        dfs(1,-1,0);
        scanf("%d",&m);
        for(int i=0;i<m;++i)
        {
            scanf("%d",&querys[i].k);
            querys[i].id=i;
        }
        solve();
        for(int i=0;i<m;++i)
            printf("%I64d\n",ans[i]);
    }
    return 0;
}
