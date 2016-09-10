#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1010;
struct Edge
{
    int to;
    int next;
    int w;
}edge[MAXN*MAXN];
int tot;
int head[MAXN];
void add(int s, int u, int w)
{
    edge[tot].to = u;
    edge[tot].w = w;
    edge[tot].next = head[s];
    head[s] = tot++;
    edge[tot].to = s;
    edge[tot].w = w;
    edge[tot].next = head[u];
    head[u] = tot++;    
}
int n, m;
int dfn[MAXN], low[MAXN], sta[MAXN], col[MAXN];
int tt, sum, scc, top;
void tarjan(int u, int fa)
{
    dfn[u] = low[u] = ++tt;
    sta[++top] = u;
    int cnt=0;
    for(int i = head[u]; i; i = edge[i].next) {
        int v = edge[i].to;
        if(!dfn[v]) {
            sum++;
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
        } else if (fa == v) {
            if (cnt) low[u] = min(low[u],dfn[v]);
            cnt++;
        } else low[u] = min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u]) {
        int x;
        scc++;
        do {
            x = sta[top--];
            col[x] = scc;
        } while(x != u);
    }
}
int main()
{
    int a, b, w;
    int ans;
    while (scanf("%d %d", &n, &m)) {
        if (n == 0 && m == 0) break;
        memset(dfn, 0, sizeof(dfn));
        memset(low, 0, sizeof(low));
        memset(col, 0, sizeof(col));
        memset(head, 0, sizeof(head));
        tot = sum = 1;
        tt = scc = top = 0;
        ans = 10010;
        while (m--) {
            scanf("%d %d %d", &a, &b, &w);
            add(a, b, w);
        }
        tarjan(1, 1);
        if (sum < n) puts("0");
        else {
            for (int i = 1; i <= n; ++i) {
                for (int j = head[i]; j; j = edge[j].next) {
                    int v = edge[j].to;
                    if (col[i] != col[v]) ans = min(ans, edge[j].w);
                }
            }
            printf("%d\n", ans?(ans == 10010?-1:ans):1);
        }
    }        
    return 0;
}
