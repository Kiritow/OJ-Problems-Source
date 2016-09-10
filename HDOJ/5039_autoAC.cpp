#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<set>
#include<cmath>
#include<vector>
#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define eps 1e-6
#define pi acos(-1.0)
using namespace std;
typedef long long ll;
const int maxn = 30000 + 10;
struct Edge
{
    int v,color,next;
    Edge(int v = 0,int color = 0,int next = 0):v(v),color(color),next(next){}
}edges[maxn<<1];
int head[maxn],Lx[maxn],Rx[maxn],N,nEdge;
int a[maxn];
map<string,int>mp;
void AddEdges(int u,int v,int color)
{
    edges[++nEdge] = Edge(v,color,head[u]);
    head[u] = nEdge;
    edges[++nEdge] = Edge(u,color,head[v]);
    head[v] = nEdge;
}
void dfs(int u,int fa,int c)
{
    for(int k = head[u];k != -1;k = edges[k].next)
    {
        int v = edges[k].v;
        if(v == fa) continue;
        Lx[k/2] = ++N;
        a[N] = c^edges[k].color;
        dfs(v,u,c^edges[k].color);
        Rx[k/2] = N;
    }
}
int sum[maxn<<2],flip[maxn<<2];
inline void PushUp(int rt)
{
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}
void PushDown(int l,int r,int rt)
{
    if(flip[rt])
    {
        flip[rt<<1] ^= 1;
        flip[rt<<1|1] ^= 1;
        int m = (l + r)>>1;
        sum[rt<<1] = (m - l + 1) - sum[rt<<1];
        sum[rt<<1|1] = (r - m) - sum[rt<<1|1];
        flip[rt] = 0;
    }
}
void build(int l,int r,int rt)
{
    flip[rt] = 0;
    if(l == r)
    {
        sum[rt] = a[l];
        return ;
    }
    int m = (l + r)>>1;
    build(l,m,rt<<1);
    build(m+1,r,rt<<1|1);
    PushUp(rt);
}
void Update(int L,int R,int l,int r,int rt)
{
    if(l >= L && r <= R)
    {
        flip[rt] ^= 1;
        sum[rt] = r - l + 1 - sum[rt];
        return ;
    }
    PushDown(l,r,rt);
    int m = (l + r)>>1;
    if(m >= L) Update(L,R,l,m,rt<<1);
    if(m < R) Update(L,R,m+1,r,rt<<1|1);
    PushUp(rt);
}
void Init()
{
    memset(head,0xff,sizeof(head));
    nEdge = -1; N = 0;
    mp.clear();
}
int main()
{
    char str[20];
    int t,tcase = 0;
    scanf("%d",&t);
    while(t--)
    {
        Init();
        int n,m;
        scanf("%d",&n);
        for(int i = 1;i <= n;++i)
        {
            scanf("%s",str);
            mp[(string)str] = i;
        }
        int u,v,c;
        for(int i = 1;i < n;++i)
        {
            scanf("%s",str);
            u = mp[(string)str];
            scanf("%s",str);
            v = mp[(string)str];
            scanf("%d",&c);
            AddEdges(u,v,c);
        }
        dfs(1,-1,0);
        build(1,N,1);
        scanf("%d",&m);
        printf("Case #%d:\n",++tcase);
        while(m--)
        {
            scanf("%s",str);
            if(str[0] == 'Q')
            {
                ll x = sum[1];
                printf("%I64d\n",x*(n - x)*2LL);
            }
            else
            {
                scanf("%d",&u);
                Update(Lx[u-1],Rx[u-1],1,N,1);
            }
        }
    }
    return 0;
}
