#pragma comment(linker, "/STACK:102400000,102400000")
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
const int INF = 1000111222;
const double INFF = 1e100;
const double eps = 1e-8;
const int mod = 1000000007;
const int NN = 100010;
const int MM = 400010;
vector<int>ad[NN];
vector<int>del[NN];
struct TR
{
    int l,r,col,ci;
    int mid()
    {
        return (l+r)>>1;
    }
}tr[NN*4];
struct G
{
    int v,next;
}E[NN*2];
int p[NN],T;
//c_dfs1
int deep[NN],si[NN],per[NN],anc[NN];
//c_dfs2
int tsp,pos[NN],top[NN];
int ans[NN],dui[NN];
void add(int u,int v)
{
    E[T].v=v;
    E[T].next=p[u];
    p[u]=T++;
}
void c_dfs1(int u,int fa,int cen)
{
    anc[u]=fa;
    deep[u]=cen;
    si[u]=1;
    per[u]=-1;
    int i,v;
    for(i=p[u];i+1;i=E[i].next)
    {
        v=E[i].v;
        if(v==fa)continue;
        c_dfs1(v,u,cen+1);
        si[u]+=si[v];
        if(per[u]==-1 || si[v]>si[ per[u] ])
            per[u]=v;
    }
}
void c_dfs2(int u,int fa,int now_top)
{
    pos[u]=++tsp;
    top[u]=now_top;
    if(per[u]!=-1)c_dfs2(per[u],u,now_top);
    int i,v;
    for(i=p[u];i+1;i=E[i].next)
    {
        v=E[i].v;
        if(v==per[u] || v==fa)continue;
        c_dfs2(v,u,v);
    }
}
void c_update(int u,int v,int col)
{
    while(top[u]!=top[v])
    {
        if(deep[ top[u] ] > deep[ top[v] ])
            swap(u,v);
        ad[ pos[ top[v] ] ].PB(col);
        del[ pos[v] ].PB(col);
        v=anc[ top[v] ];
    }
    if(pos[u]>pos[v])
        swap(u,v);
    ad[ pos[u] ].PB(col);
    del[ pos[v] ].PB(col);
}
void push_up(int R)
{
    if(tr[R<<1].ci >= tr[R<<1|1].ci)
    {
        tr[R].col = tr[R<<1].col;
        tr[R].ci = tr[R<<1].ci;
    }
    else
    {
        tr[R].col = tr[R<<1|1].col;
        tr[R].ci = tr[R<<1|1].ci;
    }
}
void build(int l,int r,int R)
{
    tr[R].l = l;
    tr[R].r = r;
    if(l==r)
    {
        tr[R].col = l;
        tr[R].ci = 0;
        return;
    }
    int mid = tr[R].mid();
    build(l,mid,R<<1);
    build(mid+1,r,R<<1|1);
    push_up(R);
}
void update(int x,int R,int ad)
{
    if(tr[R].l == tr[R].r)
    {
        tr[R].ci += ad;
        return;
    }
    int mid = tr[R].mid();
    if(x <= mid)
        update(x,R<<1,ad);
    else
        update(x,R<<1|1,ad);
    push_up(R);
}
int main()
{
    int n,m,u,v,i,c,j,si,s_col;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0 && m==0)break;
        memset(p,-1,sizeof(p));
        T=0;
        for(i=1;i<n;i++)
        {
            scanf("%d%d", &u, &v);
            add(u,v);
            add(v,u);
        }
        c_dfs1(1,-1,0);
        tsp = 0;
        c_dfs2(1,-1,1);
        for(i=1;i<=n;i++)
        {
            dui[ pos[i] ] = i;
        }
        s_col = 1;
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&u,&v,&c);
            s_col = max(s_col,c);
            c_update(u,v,c);
        }
        build(0,s_col,1);
        for(i=1;i<=n;i++)
        {
            si = ad[i].size();
            for(j=0;j<si;j++)
            {
                update(ad[i][j], 1, 1);
            }
            ans[ dui[i] ] = tr[1].col;
            si = del[i].size();
            for(j=0;j<si;j++)
            {
                update(del[i][j], 1, -1);
            }
            ad[i].clear();
            del[i].clear();
        }
        for(i=1;i<=n;i++)
        {
            printf("%d\n",ans[i]);
        }
    }
    return 0;
}
