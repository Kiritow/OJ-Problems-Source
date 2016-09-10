#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 510;
const int M = 1000010;
const int INF = 0x7f7f7f7f;
struct Edge {
    int v, cap, cost, next;
    Edge() {}
    Edge(int a, int b, int c, int d)
    :v(a), cap(b), cost(c), next(d) {}
}e[M];
int head[N], sz;
int dis[N], pre[N], cur[N];
bool inq[N];
queue<int> q;
void graphinit() {
    memset(head, -1, sizeof(head));
    sz = 0;
}
void addedge(int u, int v, int cp, int ct) {
    e[sz] = Edge(v, cp, ct, head[u]);
    head[u] = sz++;
    e[sz] = Edge(u, 0, -ct, head[v]);
    head[v] = sz++;
}
pair<int, int> mcmf(int s, int t) {
    int mc = 0, mf = 0;
    while (true) {
        memset(pre, -1, sizeof(pre));
        memset(inq, 0, sizeof(inq));
        memset(dis, 0x7f, sizeof(dis));
        dis[s] = 0;
        q.push(s);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            inq[u] = false;
            for (int i = head[u]; i != -1; i = e[i].next) {
                int v = e[i].v;
                if (e[i].cap > 0 && dis[v] > dis[u] + e[i].cost) {
                    dis[v] = dis[u] + e[i].cost;
                    pre[v] = u; cur[v] = i;
                    if (!inq[v]) { inq[v] = true; q.push(v); }
                }
            }
        }
        if (pre[t] == -1) break;
        int aug = INF;
        for (int i = t; i != s; i = pre[i])
            aug = min(aug, e[cur[i]].cap);
        mf += aug;
        mc += dis[t] * aug;
        for (int i = t; i != s; i = pre[i]) {
            e[cur[i]].cap -= aug;
            e[cur[i] ^ 1].cap += aug;
        }
    }
    return make_pair(mf, mc);
}
const int MAXN = 110;
int n, m, k;
int candy_s[MAXN], candy_t[MAXN];
int start_time[MAXN][MAXN], start_cost[MAXN][MAXN];
int change_time[MAXN][MAXN], change_cost[MAXN][MAXN];
void read_matrix(int a[MAXN][MAXN], int n, int m) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);
}
void work() {
    for (int i = 0; i < n; i++)
        scanf("%d%d", candy_s + i, candy_t + i);
    read_matrix(start_time, n, m);
    read_matrix(start_cost, n, m);
    read_matrix(change_time, n, n);
    read_matrix(change_cost, n, n);
    graphinit();
    int ss = 2 * n + m, tt = ss + 1;
    for (int i = 0; i < n; i++)
        addedge(ss, i, 1, 0);
    for (int i = 0; i < m; i++)
        addedge(i + n, tt, 1, 0);
    for (int i = 0; i < n; i++)
        addedge(i + n + m, tt, 1, 0);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (start_time[i][j] >= candy_t[i]) continue;
            int cost = start_cost[i][j];
            if (start_time[i][j] > candy_s[i])
                cost += k * (start_time[i][j] - candy_s[i]);
            addedge(i, j + n, 1, cost);
        }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) if (i != j) {
            int dt = candy_t[i] + change_time[i][j];
            if (dt >= candy_t[j]) continue;
            int cost = change_cost[i][j];
            dt -= candy_s[j];
            if (dt > 0)
                cost += k * dt;
            addedge(j, i + n + m, 1, cost);
        }
    pair<int, int> ans = mcmf(ss, tt);
    if (ans.first < n) puts("-1");
    else printf("%d\n", ans.second);
}
int main() {
    while (scanf("%d%d%d", &n, &m, &k), n || m || k) {
        work();
    }
    return 0;
}
