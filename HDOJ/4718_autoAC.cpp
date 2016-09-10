#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAXN 100005
int anc[MAXN][17];
int LL[MAXN][17][2], RR[MAXN][17][2];
int ans[MAXN][17][2];
int dep[MAXN];
struct EDGE
{
    EDGE() {}
    EDGE(int _to, int _next) { to = _to, next = _next; }
    int to, next;
}edge[MAXN];
int edgecnt, head[MAXN];
void init()
{
    memset(anc, -1, sizeof(anc));
    memset(head, -1, sizeof(head));
    edgecnt = 0;
}
void add(int s, int t)
{
    edge[edgecnt] = EDGE(t, head[s]);
    head[s] = edgecnt++;
}
int val[MAXN];
void dfs(int u, int fa, int deep)
{
    anc[u][0] = fa;
    dep[u] = deep;
    if (val[u] < val[fa])
    {
        LL[u][0][0] = 2;
        LL[u][0][1] = 1;
        RR[u][0][0] = 2;
        RR[u][0][1] = 1;
        ans[u][0][0] = 2;
        ans[u][0][1] = 1;
    }
    else if (val[u]>val[fa])
    {
        LL[u][0][0] = 1;
        LL[u][0][1] = 2;
        RR[u][0][0] = 1;
        RR[u][0][1] = 2;
        ans[u][0][0] = 1;
        ans[u][0][1] = 2;
    }
    else
    {
        LL[u][0][0] = LL[u][0][1] = RR[u][0][0] = RR[u][0][1] = ans[u][0][0] = ans[u][0][1] = 1;
    }
    for (int i = head[u]; ~i; i = edge[i].next) dfs(edge[i].to, u, deep + 1);
}
void process(int n)
{
    for (int j = 0; j < 16; j++)
        for (int i = 1; i <= n; i++)
        {
            if (dep[anc[i][j]]>(1 << j))
            {
                anc[i][j + 1] = anc[anc[i][j]][j];
                int A = anc[i][j];
                int len = (1 << j) + 1;
                if (LL[i][j][0] == len) LL[i][j + 1][0] = len - 1 + LL[A][j][0];
                else LL[i][j + 1][0] = LL[i][j][0];
                if (RR[A][j][0] == len) RR[i][j + 1][0] = len - 1 + RR[i][j][0];
                else RR[i][j + 1][0] = RR[A][j][0];
                if (LL[i][j][1] == len) LL[i][j + 1][1] = len - 1 + LL[A][j][1];
                else LL[i][j + 1][1] = LL[i][j][1];
                if (RR[A][j][1] == len) RR[i][j + 1][1] = len - 1 + RR[i][j][1];
                else RR[i][j + 1][1] = RR[A][j][1];
                ans[i][j + 1][0] = max(ans[i][j][0], ans[A][j][0]);
                ans[i][j + 1][0] = max(ans[i][j + 1][0], RR[i][j][0] + LL[A][j][0] - 1);
                ans[i][j + 1][1] = max(ans[i][j][1], ans[A][j][1]);
                ans[i][j + 1][1] = max(ans[i][j + 1][1], RR[i][j][1] + LL[A][j][1] - 1);
            }
        }
}
int lca(int u, int v)
{
    if (dep[u] < dep[v]) swap(u, v);
    for (int i = 16; i >= 0; i--) if (dep[u] - (1 << i) >= dep[v]) u = anc[u][i];
    if (u == v) return u;
    for (int i = 16; i >= 0; i--)
        if (anc[u][i] != anc[v][i])
        {
            u = anc[u][i];
            v = anc[v][i];
        }
    return anc[u][0];
}
int getans(int u, int v)
{
    int l = lca(u, v);
    int Ru = 1, ansu = 1;
    bool first = 1;
    for (int i = 16; i >= 0; i--)
        if (dep[u] - (1 << i) >= dep[l])
        {
            if (first)
            {
                Ru = RR[u][i][0];
                ansu = ans[u][i][0];
                first = 0;
                u = anc[u][i];
                continue;
            }
            ansu = max(ansu, ans[u][i][0]);
            ansu = max(ansu, Ru + LL[u][i][0] - 1);
            int len = (1 << i) + 1;
            if (len == RR[u][i][0]) Ru += RR[u][i][0] - 1;
            else Ru = RR[u][i][0];
            u = anc[u][i];
        }
    int Rv = 1, ansv = 1;
    first = 1;
    for (int i = 16; i >= 0; i--)
        if (dep[v] - (1 << i) >= dep[l])
        {
            if (first)
            {
                Rv = RR[v][i][1];
                ansv = ans[v][i][1];
                first = 0;
                v = anc[v][i];
                continue;
            }
            ansv = max(ansv, ans[v][i][1]);
            ansv = max(ansv, Rv + LL[v][i][1] - 1);
            int len = (1 << i) + 1;
            if (len == RR[v][i][1]) Rv += RR[v][i][1] - 1;
            else Rv = RR[v][i][1];
            v = anc[v][i];
        }
    int ans = max(ansu, ansv);
    ans = max(ans, Ru + Rv - 1);
    return ans;
}
int main()
{
    int T;
    int ks = 0;
    scanf("%d", &T);
    bool ok = 0;
    while (T--)
    {
        if (ok != 0)
        {
            puts("");
        }
        ok = 1;
        printf("Case #%d:\n", ++ks);
        int n;
        scanf("%d", &n);
        init();
        for (int i = 1; i <= n; i++) scanf("%d", &val[i]);
        for (int i = 2; i <= n; i++)
        {
            int s;
            scanf("%d", &s);
            add(s, i);
        }
        dfs(1, -1, 1);
        process(n);
        int Q;
        scanf("%d", &Q);
        while (Q--)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            printf("%d\n", getans(u, v));
        }
    }
    return 0;
}
