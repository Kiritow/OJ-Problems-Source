#pragma comment(linker,"/STACK:102400000,102400000")
#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<set>
#include<map>
#include<vector>
#include<cstring>
#include<stack>
#include<cmath>
#include<queue>
using namespace std;
#define CL(x,v); memset(x,v,sizeof(x));
#define INF 0x3f3f3f3f
#define LL long long
#define REP(i,r,n) for(int i=r;i<=n;i++)
#define RREP(i,n,r) for(int i=n;i>=r;i--)
const int MAXN=2e5+100;
int n,m;
struct Edge{
    int u,v;
    Edge(){}
    Edge(int a,int b){
        u=a;
        v=b;
    }
};
vector<Edge> edges;
vector<int> G[MAXN];
vector<int> P[MAXN];
int dfs_clock,bcc_cnt;
int pre[MAXN];
int T[MAXN];
int dfs1(int u,int fa)
{
    int lowu=pre[u]=++dfs_clock;
    for(int i=0;i<G[u].size();i++)
    {
        int mm=G[u][i];
        int v=edges[mm].v;
        if(fa==(mm^1))continue;
        if(!pre[v])
        {
            int lowv=dfs1(v,mm);
            lowu=min(lowu,lowv);
            if(lowv>pre[u])
            {
                P[v].push_back(u);
                P[u].push_back(v);
            }
        }
        else if(pre[v]<pre[u])
        {
            lowu=min(pre[v],lowu);
        }
    }
    return lowu;
}
void dfs2(int u,int fa)
{
    T[u]=bcc_cnt;
    for(int i=0;i<G[u].size();i++)
    {
        int v=edges[G[u][i]].v;
        bool f=true;
        for(int j=0;j<P[u].size();j++)
        {
            int vv=P[u][j];
            if(v==vv)
            {
                f=false;break;
            }
        }
        if(!f||T[v])continue;
        dfs2(v,u);
    }
}
void find_bcc(int n)
{
     dfs_clock=0,bcc_cnt=0;
    memset(pre,0,sizeof(pre));
    memset(T,0,sizeof(T));
    for(int i=1;i<=n;i++)
        if(!pre[i])
            dfs1(i,-1);
    for(int i=1;i<=n;i++)
        if(!T[i])
        {
            bcc_cnt++;
            dfs2(i,-1);
        }
}
vector<int> GG[MAXN];
int d[MAXN];
void dfs(int u,int dep)
{
    d[u]=dep;
    for(int i=0;i<GG[u].size();i++)
    {
        int v=GG[u][i];
        if(!d[v])
        {
            dfs(v,dep+1);
        }
    }
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        if(n+m==0)break;
        REP(i,0,n){
            G[i].clear();
            P[i].clear();
        }
        edges.clear();
        int a,b;
        REP(i,1,m)
        {
            scanf("%d%d",&a,&b);
            Edge e;
            e=Edge(a,b);
            edges.push_back(e);
            e=Edge(b,a);
            edges.push_back(e);
            int mm=edges.size();
            G[a].push_back(mm-2);
            G[b].push_back(mm-1);
        }
        find_bcc(n);
        REP(i,0,n)
        {
            GG[i].clear();
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<P[i].size();j++)
            {
                int v=P[i][j];
                if(T[i]!=T[v])
                {
                    GG[T[i]].push_back(T[v]);
                }
            }
        }
        CL(d,0);
        dfs(1,1);
        int maxn=0;
        int flag=0;
        for(int i=1;i<=bcc_cnt;i++)
        {
            if(d[i]>maxn)
            {
                maxn=d[i];
                flag=i;
            }
        }
        CL(d,0);
        dfs(flag,1);
        maxn=0;
        for(int i=1;i<=bcc_cnt;i++)
        {
            if(d[i]>maxn)
                maxn=d[i];
        }
        cout<<bcc_cnt-maxn<<endl;
    }
    return 0;
}
