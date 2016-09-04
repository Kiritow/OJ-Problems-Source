#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <map>
#include <sstream>
#include <queue>
#include <vector>
#define MAXN 111111
#define MAXM 211111
#define eps 1e-8
#define INF 1000000001
using namespace std;
int e, tmpdfn, top;
int n, m, ind;
int vis[MAXM], head[MAXN], dfn[MAXN], low[MAXN], num[MAXM];
vector<int>g[MAXN];
struct Edge
{
    int v, next;
}edge[MAXM];
void add(int u, int v)
{
    edge[e].v = v;
    edge[e].next = head[u];
    head[u] = e++;
    edge[e].v = u;
    edge[e].next = head[v];
    head[v] = e++;
}
struct Stack
{
    int s, e;
    Stack(){}
    Stack(int a, int b){s = a; e = b;}
}st[MAXM];
void init()
{
    e = tmpdfn = ind = 0;
    top = -1;
    memset(vis, 0, sizeof(vis));
    memset(dfn, 0, sizeof(dfn));
    memset(head, -1, sizeof(head));
    memset(num, 0, sizeof(num));
}
void color(Stack t)
{
    ind++;
    while(top >= 0)
    {
        Stack A = st[top--];
        g[A.s].push_back(ind);
        g[A.e].push_back(ind);
        if(A.s == t.s && A.e == t.e) break;
    }
}
void dfs(int u, int fa)
{
    dfn[u] = low[u] = ++tmpdfn;
    for(int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].v;
        if(vis[i] == 0)
        {
            vis[i] = vis[i ^ 1] = 1;
            Stack tmp(u, v);
            st[++top] = tmp;
            if(!dfn[v])
            {
                dfs(v, u);
                low[u] = min(low[u], low[v]);
                if(low[v] >= dfn[u]) color(tmp);
            }
            else if(v != fa) low[u] = min(low[u], dfn[v]);
        }
    }
}
int Q;
int uu[MAXM], vv[MAXM];
int fa[MAXN];
int find(int x)
{
    if(fa[x] == x) return x;
    int t = find(fa[x]);
    fa[x] = t;
    return t;
}
void join(int u, int v)
{
    int fx = find(u);
    int fy = find(v);
    if(fx != fy) fa[fx] = fy;
}
int main()
{
    int u, v;
    int cas = 0;
    while(scanf("%d%d%d", &n, &m, &Q) != EOF)
    {
        if(n == 0 && m == 0 && Q == 0) break;
        init();
        for(int i = 1; i <= n; i++) fa[i] = i;
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d", &uu[i], &vv[i]);
            uu[i]++; vv[i]++;
            add(uu[i], vv[i]);
            join(uu[i], vv[i]);
        }
        for(int i = 1; i <= n; i++) g[i].clear();
        for(int i = 1; i <= n; i++)
        {
            if(!dfn[i]) dfs(i, 0);
        }
        for(int i = 1; i <= n; i++) sort(g[i].begin(), g[i].end());
        for(int i = 1; i <= n; i++) unique(g[i].begin(), g[i].end());
        for(int i = 0; i < m; i++)
        {
            int sz1 = g[uu[i]].size();
            int sz2 = g[vv[i]].size();
            int k1 = 0, k2 = 0;
            while(k1 < sz1 && k2 < sz2)
            {
                if(g[uu[i]][k1] > g[vv[i]][k2]) k2++;
                else if(g[uu[i]][k1] < g[vv[i]][k2]) k1++;
                else if(g[uu[i]][k1] == g[vv[i]][k2])
                {
                    int tmp = g[uu[i]][k1];
                    num[tmp]++;
                    break;
                }
            }
        }
        printf("Case %d:\n", ++cas);
        for(int i = 0; i < Q; i++)
        {
            scanf("%d%d", &u, &v);
            u++; v++;
            int sz1 = g[u].size();
            int sz2 = g[v].size();
            int k1 = 0, k2 = 0;
            int tmp = -1;
            while(k1 < sz1 && k2 < sz2)
            {
                if(g[u][k1] > g[v][k2]) k2++;
                else if(g[u][k1] < g[v][k2]) k1++;
                else if(g[u][k1] == g[v][k2])
                {
                    tmp = g[u][k1];
                    break;
                }
            }
            if(find(u) != find(v)) puts("zero");
            else if(tmp == -1) puts("one");
            else if(num[tmp] == 1) puts("one");
            else puts("two or more");
        }
    }
    return 0;
}
