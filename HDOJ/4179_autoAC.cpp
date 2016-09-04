#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 11111;
const int M = 55555;
int eh[2][N], ec[2];
struct Edge {
    int id, nx, df;
    double l;
    Edge() {}
    Edge(int id, int nx, int df, double l) : id(id), nx(nx), df(df), l(l) {}
} edge[2][M << 1];
inline void init() {
    memset(eh, -1, sizeof(eh));
    memset(ec, 0, sizeof(ec));
}
inline void addedge(int u, int v, int df, double l, int id) {
    edge[id][ec[id]] = Edge(v, eh[id][u], df, l);
    eh[id][u] = ec[id]++;
}
int x[N], y[N], z[N];
template<class T> inline T sqr(T a) { return a * a;}
int st[M << 1], ed[M << 1];
inline int getdf(int a, int b) {
    if (z[a] >= z[b]) return 0;
    double len = sqrt(sqr((double) x[a] - x[b]) + sqr((double) y[a] - y[b]));
    return (int) floor(100.0 * (z[b] - z[a]) / len);
}
inline double getdis(int a , int b) { return sqrt(sqr((double) x[a] - x[b]) + sqr((double) y[a] - y[b]) + sqr((double) z[a] - z[b]));}
const double FINF = 1e50;
double dis[2][N];
int q[M << 1];
bool vis[N];
void spfa(int s, int id) {
    for (int i = 0; i < N; i++) dis[id][i] = FINF;
    int qh, qt;
    qh = qt = 0;
    dis[id][s] = 0;
    q[qt++] = s;
    vis[s] = true;
    while (qh < qt) {
        int cur = q[qh++];
        vis[cur] = false;
        for (int i = eh[id][cur]; ~i; i = edge[id][i].nx) {
            if (dis[id][edge[id][i].id] > dis[id][cur] + edge[id][i].l) {
                dis[id][edge[id][i].id] = dis[id][cur] + edge[id][i].l;
                if (!vis[edge[id][i].id]) q[qt++] = edge[id][i].id, vis[edge[id][i].id] = true;
            }
        }
    }
}
int main() {
    int n, m;
    while (~scanf("%d%d", &n, &m) && (n || m)) {
        for (int i = 1; i <= n; i++) scanf("%d%d%d", &x[i], &y[i], &z[i]);
        for (int i = 0; i < m; i++) scanf("%d%d", &st[i], &ed[i]);
        int A, B, D;
        scanf("%d%d%d", &A, &B, &D);
        init();
        for (int i = 0; i < m; i++) {
            double tmp = getdis(st[i], ed[i]);
            int df = getdf(st[i], ed[i]);
            if (df <= D) {
                addedge(st[i], ed[i], df, tmp, 0);
                addedge(ed[i], st[i], df, tmp, 1);
            }
            df = getdf(ed[i], st[i]);
            if (df <= D) {
                addedge(ed[i], st[i], df, tmp, 0);
                addedge(st[i], ed[i], df, tmp, 1);
            }
        }
        spfa(A, 0);
        spfa(B, 1);
        double ans = FINF;
        for (int i = 1; i <= n; i++) {
            for (int t = eh[0][i]; ~t; t = edge[0][t].nx) {
                if (edge[0][t].df == D) ans = min(ans, dis[0][i] + edge[0][t].l + dis[1][edge[0][t].id]);
            }
        }
        if (ans < FINF) printf("%.1f\n", ans);
        else puts("None");
    }
    return 0;
}
