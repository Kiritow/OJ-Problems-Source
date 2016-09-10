#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <iomanip>
#include <cassert>
using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define ff(i, n) for(int i=0;i<(n);i++)
#define fff(i, n, m) for(int i=(n);i<=(m);i++)
#define dff(i, n, m) for(int i=(n);i>=(m);i--)
#define bit(n) (1LL<<(n))
typedef long long LL;
typedef unsigned long long ULL;
void work();
int main()
{
    work();
}
void nextInt(int & x)
{
    char ch;
    while(ch = getchar(), isdigit(ch) == false);
    x = 0;
    while(x = 10 * x + ch - '0', ch = getchar(), isdigit(ch) == true);
}
const int maxv = 100010;
const int maxe = 200020;
const int maxlog = 20;
int n, m;
int first[maxv], ecnt;
int vv[maxe], nxt[maxe];
void init()
{
    memset(first, 0, sizeof(first));
    ecnt = 2;
}
void addEdge(int u, int v)
{
    nxt[ecnt] = first[u], vv[ecnt] = v, first[u] = ecnt ++;
}
int fa[maxlog][maxv];
int dep[maxv], size[maxv];
void dfs(int u, int f, int d)
{
    fa[0][u] = f, size[u] = 1, dep[u] = d;
    for(int e = first[u]; e; e = nxt[e]) if(vv[e] != f)
    {
        dfs(vv[e], u, d + 1);
        size[u] += size[vv[e]];
    }
}
void initFa()
{
    dfs(1, -1, 0);
    ff(k, maxlog-1) fff(u, 1, n) if(fa[k][u] == -1)
        fa[k+1][u] = -1;
    else
        fa[k+1][u] = fa[k][fa[k][u]];
}
int upSlope(int u, int p)
{
    assert(p <= dep[u]);
    ff(k, maxlog) if(p & bit(k))
        u = fa[k][u];
    return u;
}
int lca(int u, int v)
{
    if (dep[u] < dep[v]) swap(u, v);
    u = upSlope(u, dep[u] - dep[v]);
    if (u == v) return u;
    dff(k, maxlog-1, 0) if (fa[k][u] != fa[k][v])
        u = fa[k][u], v = fa[k][v];
    return fa[0][u];
}
struct Node
{
    int type, r;
    Node(int type, int r) : type(type), r(r) {}
};
Node getMiddle(int a, int b, int ab)
{
    int d = dep[a] + dep[b] - 2 * dep[ab];
    if (dep[a] >= dep[b])
        return Node(1, upSlope(a, (d - 1)/2));
    else
        return Node(2, upSlope(b, d/2));
}
int calc(int a, int b, int c, int ab, int ac)
{
    Node bn = getMiddle(a, b, ab);
    Node cn = getMiddle(a, c, ac);
    if (bn.type + cn.type == 2)
    {
        return min(size[bn.r], size[cn.r]);
    }
    else if (bn.type + cn.type == 4)
    {
        if(dep[bn.r] > dep[cn.r]) swap(bn, cn);
        if (lca(bn.r, cn.r) == bn.r)
            return n - size[bn.r];
        else
            return n - size[bn.r] - size[cn.r];
    }
    else
    {
        if (bn.type == 2) swap(bn, cn);
        if (lca(bn.r, cn.r) == bn.r)
            return size[bn.r] - size[cn.r];
        else
            return size[bn.r];
    }
}
void work()
{
    int T;
    scanf("%d", &T);
    fff(cas, 1, T)
    {
        init();
        scanf("%d", &n);
        ff(i, n-1)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            addEdge(u, v);
            addEdge(v, u);
        }
        initFa();
        scanf("%d", &m);
        while(m--)
        {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            int ab = lca(a, b);
            int ac = lca(a, c);
            int bc = lca(b, c);
            printf("%d %d %d\n", calc(a, b, c, ab, ac), calc(b, a, c, ab, bc), calc(c, a, b, ac, bc));
        }
    }
}
