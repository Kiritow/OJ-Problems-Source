#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <climits>
#include <complex>
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
const int MAXN=100010;
int n,m;
int fa[MAXN];
struct Edge
{
    int u,v,next;
}e[MAXN<<1];
struct Node
{
    int u,v,colu,colv,rku,rkv,fau,fav;
    Node(){}
    Node(int u,int v,int colu,int colv,int rku,int rkv,int fau,int fav):u(u),v(v),colu(colu),colv(colv),rku(rku),rkv(rkv),fau(fau),fav(fav){}
}s[MAXN];
int col[MAXN];
int head[MAXN],tot;
int rk[MAXN],top;
int ans[MAXN];
void init(int n)
{
    CLR(head,-1);
    tot=0;top=0;
    for(int i=0;i<n+10;i++)
        fa[i]=i,col[i]=1,rk[i]=1;
}
void addedge(int u,int v)
{
    e[tot].u=u;
    e[tot].v=v;
    e[tot].next=head[u];
    head[u]=tot++;
}
int find_fa(int x)
{
    int o=x;
    while(fa[o]!=o) o=fa[o];
    return o;
}
int find_col(int x)
{
    if(fa[x]==x)    return col[x];
    if(!col[x])        return !find_col(fa[x]);
    return find_col(fa[x]);
}
bool merge(int u,int v)
{
    int a=find_fa(u),b=find_fa(v);
    int x=find_col(u),y=find_col(v);
    int root,next;
    if(a==b)
    {
        if(x==y)    return false;
        return true;
    }
    if(rk[a]>rk[b])
        root=a,next=b;
    else
        root=b,next=a;
    s[top++]=Node(a,b,col[a],col[b],rk[a],rk[b],fa[a],fa[b]);
    if(x==y && col[root]==1)
        col[next]^=1;
    fa[next]=root;
    rk[root]+=rk[next];
    return true;
}
bool unite(int l,int r,int a,int b)
{
    bool flag=true;
    int u,v;
    for(int t=l;t<=r;t++)
        for(int i=head[t];~i;i=e[i].next)
        {
            u=e[i].u;v=e[i].v;
            if(a<=v && v<=b)  continue;
            if(!merge(u,v))
                flag=false;
        }
    return flag;
}
void back(int x)
{
    Node tmp;
    while(top>x)
    {
        --top;
        tmp=s[top];
        int u=tmp.u,v=tmp.v;
        rk[u]=tmp.rku;rk[v]=tmp.rkv;
        fa[u]=tmp.fau;fa[v]=tmp.fav;
        col[u]=tmp.colu;col[v]=tmp.colv;
    }
}
void cdq(int l,int r,bool flag)
{
    if(l==r)
    {
        ans[l]=flag;
        return;
    }
    int mid=MID(l,r);
    int pre=top;
    bool now=flag&&unite(mid+1,r,l,mid);
    cdq(l,mid,now);
    back(pre);
    now=flag&&unite(l,mid,mid+1,r);
    cdq(mid+1,r,now);
    back(pre);
}
int main()
{
    int T;
    read(T);
    while(T--)
    {
        read(n),read(m);
        init(n);
        for(int i=0,u,v;i<m;i++)
        {
            read(u);read(v);
            addedge(u,v);
            addedge(v,u);
        }
        cdq(1,n,true);
        for(int i=1;i<=n;i++)
            write(ans[i]);
        putchar('\n');
    }
    return 0;
}
