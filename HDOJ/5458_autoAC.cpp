#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <climits>
#include <complex>
#include <cassert>
#include <cstdio>
#include <bitset>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <ctime>
#include <set>
#include <map>
#include <cmath>
#include <functional>
#include <numeric>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
#define eps 1e-9
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define LLINF 1LL<<62
#define speed std::ios::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef complex<ld> point;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;
#define CLR(x,y) memset(x,y,sizeof(x))
#define CPY(x,y) memcpy(x,y,sizeof(x))
#define clr(a,x,size) memset(a,x,sizeof(a[0])*(size))
#define cpy(a,x,size) memcpy(a,x,sizeof(a[0])*(size))
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define lowbit(x) (x&(-x))
#define MID(x,y) (x+((y-x)>>1))
#define getidx(l,r) (l+r | l!=r)
#define ls getidx(l,mid)
#define rs getidx(mid+1,r)
#define lson l,mid
#define rson mid+1,r
#define root 1,n
template<class T>
inline bool read(T &n)
{
    T x = 0, tmp = 1;
    char c = getchar();
    while((c < '0' || c > '9') && c != '-' && c != EOF) c = getchar();
    if(c == EOF) return false;
    if(c == '-') c = getchar(), tmp = -1;
    while(c >= '0' && c <= '9') x *= 10, x += (c - '0'),c = getchar();
    n = x*tmp;
    return true;
}
template <class T>
inline void write(T n)
{
    if(n < 0)
    {
        putchar('-');
        n = -n;
    }
    int len = 0,data[20];
    while(n)
    {
        data[len++] = n%10;
        n /= 10;
    }
    if(!len) data[len++] = 0;
    while(len--) putchar(data[len]+48);
}
const int MAXN=30005;
const int MAXM=100005;
const int MAXQ=100005;
int t,n,m,q;
struct edge
{
    int a,b;
    edge(){}
    edge(int aa,int bb):a(aa),b(bb){}
    bool operator < (const edge &o) const
    {
        if(a == o.a)
        {
            return b < o.b;
        }
        return a < o.a;
    }
};
multiset<edge> S;
multiset<edge> V;
struct Ans
{
    int kind;
    int a;
    int b;
    int val;
}ans[MAXQ];
struct Edge
{
    int u,v,w;
    int next;
}e[MAXN<<1];
int head[MAXN],tot;
int siz[MAXN],p[MAXN],son[MAXN],dep[MAXN];
int dfn[MAXN],top[MAXN],tim;
int sum[MAXN<<1],la[MAXN<<1];
int bingchafa[MAXN];
int getfather(int x)
{
    if(bingchafa[x] == x) return x;
    return bingchafa[x] = getfather(bingchafa[x]);
}
void init()
{
    CLR(head,-1);CLR(sum,0);
    tot=tim=0;
    for(int i=1;i<=n;i++) bingchafa[i] = i;
    S.clear();
    V.clear();
}
void addedge(int u,int v,int w)
{
    e[tot].u=u;e[tot].v=v;e[tot].w=w;
    e[tot].next=head[u];head[u]=tot++;
}
void dfs(int u,int fa=0,int depth=0)
{
    siz[u]=1;son[u]=-1;
    p[u]=fa;dep[u]=depth;
    for(int i=head[u];~i;i=e[i].next)
    {
        int v=e[i].v;
        if(v==p[u])   continue;
        dfs(v,u,depth+1);
        siz[u]+=siz[v];
        if(son[u]==-1 || siz[v]>siz[son[u]])
            son[u]=v;
    }
}
void getid(int u,int fa)
{
    dfn[u]=++tim;top[u]=fa;
    if(son[u]!=-1)
        getid(son[u],fa);
    for(int i=head[u];~i;i=e[i].next)
    {
        int v=e[i].v;
        if(v==p[u] || v==son[u])    continue;
        getid(v,v);
    }
}
void pushup(int l,int r)
{
    int idx=getidx(l,r),mid=MID(l,r);
    sum[idx]=0;
    if(!la[ls])
        sum[idx]+=sum[ls];
    if(!la[rs])
        sum[idx]+=sum[rs];
}
void pushdown(int l,int r)
{
    int idx=getidx(l,r),mid=MID(l,r);
    if(!la[idx])  return;
    la[ls]=la[idx];
    la[rs]=la[idx];
}
void build(int l,int r)
{
    int idx=getidx(l,r);
    la[idx]=0;
    if(l==r)
    {
        sum[idx]=1;
        return;
    }
    int mid=MID(l,r);
    build(l,mid);
    build(mid+1,r);
    pushup(l,r);
}
void update2(int l,int r,int L,int R)
{
    int idx=getidx(l,r);
    if(L==l && r==R)
    {
        la[idx]=1;
        sum[idx]=0;
        return;
    }
    pushdown(l,r);
    int mid=MID(l,r);
    if(R<=mid)
        update2(l,mid,L,R);
    else if(L>mid)
        update2(mid+1,r,L,R);
    else
        update2(l,mid,L,mid),update2(mid+1,r,mid+1,R);
    pushup(l,r);
}
int query(int l,int r,int L,int R)
{
    int idx=getidx(l,r);
    if(la[idx]) return 0;
    if(L==l && r==R)
    {
        return sum[idx];
    }
    int mid=MID(l,r);
    if(R<=mid)
        return query(lson,L,R);
    if(L>mid)
        return query(rson,L,R);
    return query(lson,L,mid)+query(rson,mid+1,R);
}
void change(int u,int v)
{
    while(top[u]!=top[v])
    {
        if(dep[top[u]]>dep[top[v]])
            swap(u,v);
        update2(1,tim,dfn[top[v]],dfn[v]);
        v=p[top[v]];
    }
    if(u==v)    return;
    if(dep[u]>dep[v])
        swap(u,v);
    update2(1,tim,dfn[son[u]],dfn[v]);
}
int query(int u,int v)
{
    int ans=0;
    while(top[u]!=top[v])
    {
        if(dep[top[u]]>dep[top[v]])
            swap(u,v);
        ans+=query(1,tim,dfn[top[v]],dfn[v]);
        v=p[top[v]];
    }
    if(u==v)    return ans;
    if(dep[u]>dep[v])
        swap(u,v);
    ans+=query(1,tim,dfn[u]+1,dfn[v]);
    return ans;
}
int main()
{
    scanf("%d",&t);
    for(int cas = 1;cas <= t;cas++)
    {
        scanf("%d%d%d",&n,&m,&q);
        init();
        for(int i=1;i<=m;i++)
        {
            edge tmp;
            scanf("%d%d",&tmp.a,&tmp.b);
            if(tmp.a > tmp.b) swap(tmp.a,tmp.b);
            S.insert(tmp);
        }
        for(int i=1;i<=q;i++)
        {
            scanf("%d%d%d",&ans[i].kind,&ans[i].a,&ans[i].b);
            if(ans[i].a > ans[i].b) swap(ans[i].a,ans[i].b);
            if(ans[i].kind == 1)
            {
                multiset<edge>::iterator Pos = S.find(edge(ans[i].a,ans[i].b));
                S.erase(Pos);
            }
        }
        for(multiset<edge>::iterator It = S.begin();It != S.end();++It)
        {
            if(getfather(It->a) != getfather(It->b))
            {
                bingchafa[getfather(It->a)] = getfather(It->b);
                V.insert(*It);
            }
        }
        for(multiset<edge>::iterator It = V.begin();It != V.end();++It)
        {
            addedge(It->a,It->b,1);
            addedge(It->b,It->a,1);
        }
        dfs(1);getid(1,1);
        build(1,tim);
        for(multiset<edge>::iterator It = S.begin();It != S.end();++It)
        if(V.find(*It) == V.end())
        {
            change(It->a,It->b);
        }
        for(int i=q;i>=1;i--)
        {
            if(ans[i].kind == 1)
                change(ans[i].a,ans[i].b);
            else if(ans[i].kind == 2)
                ans[i].val = query(ans[i].a,ans[i].b);
        }
        printf("Case #%d:\n",cas);
        for(int i=1;i<=q;i++)
        if(ans[i].kind == 2)
            printf("%d\n",ans[i].val);
    }
    return 0;
}
