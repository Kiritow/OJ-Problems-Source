#pragma comment(linker, "/STACK:16777216")
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<functional>
#include<string>
#include<algorithm>
#include<time.h>
#include<bitset>
using namespace std;
const int maxn = 200005;
const int maxm = 400005;
struct Edge
{
    int v;
    Edge *next;
}E[maxm], *edges, *H[maxn];
int tsum[maxn];
int size[maxn];
int sum[maxn];
int dfn[maxn];
int low[maxn];
int bcc[maxn];
int cnt[maxn];
int fa[maxn];
int a[maxn];
int c[maxn];
int n, m, tcnt, K, dfs_clock, ok;
void addedges(int u, int v)
{
    edges->v = v;
    edges->next = H[u];
    H[u] = edges++;
}
void init()
{
    dfs_clock = 0;
    tcnt = 0;
    edges = E;
    for(int i = 0; i <= n; i++) {
        H[i] = 0;
        dfn[i] = low[i] = bcc[i] = cnt[i] = 0;
    }
}
void dfs(int u)
{
    dfn[u] = low[u] = ++dfs_clock;
    for(Edge *e = H[u]; e; e = e->next) if(e->v != fa[u]) {
        int v = e->v;
        if(!dfn[v]) {
            fa[v] = u;
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else low[u] = min(low[u], dfn[v]);
        if(fa[v] != u && dfn[u] < dfn[v]) {
            int vn = v;
            bcc[u] = true;
            a[++tcnt] = u;
            do {
                a[++tcnt] = vn;
                bcc[vn] = true;
                vn = fa[vn];
            }while(vn != u);
        }
    }
}
void DFS(int u, int f)
{
    size[u] = 1;
    for(Edge *e = H[u]; e; e = e->next) if(!bcc[e->v] && e->v != f) {
        int v = e->v;
        DFS(v, u);
        size[u] += size[v];
    }
}
void work()
{
    int u, v;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &v);
        addedges(i, v);
        addedges(v, i);
    }
    dfs(1);
    int ans = 0;
    for(int i = tcnt+1; i <= 2 * tcnt; i++) a[i] = a[i - tcnt];
    for(int i = 1; i <= n; i++) if(bcc[i]) DFS(i, i); 
    for(int i = 1; i <= n; i++) if(!bcc[i]) cnt[size[i]]++;
    for(int i = 1; i <= n; i++)
        for(int j = i + i; j <= n; j += i) 
            cnt[i] += cnt[j];
    for(int i = 1; i <= n; i++) if(n % i == 0) {
        K = i;
        int tt = n / K - cnt[K];
        for(int i = 1; i <= tcnt; i++) sum[i] = size[a[i]] % K;
        for(int i = tcnt + 1; i <= 2 * tcnt; i++) sum[i] = sum[i - tcnt];
        for(int i = 1; i <= 2 * tcnt; i++) sum[i] = (sum[i] + sum[i-1]) % K;
        for(int i = 0; i <= K; i++) c[i] = -1;
        for(int i = 0; i <= 2 * tcnt; i++) {
            if(c[sum[i]] != -1) tsum[i] = tsum[c[sum[i]]] + 1;
            c[sum[i]] = i;
        }
        for(int i = tcnt+1; i <= 2 * tcnt; i++) {
            if(tsum[i] - tsum[i-tcnt] >= tt) {
                ans++;
                break;
            }
        }
    }
    printf("%d\n", ans);
}
int main()
{
    while(scanf("%d", &n) != EOF) {
        init();
        work();
    }
    return 0;
}
