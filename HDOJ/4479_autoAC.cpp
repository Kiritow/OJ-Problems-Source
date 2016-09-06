#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
int N, M;
struct Edge {
    int x, y, d;
    bool operator < (const Edge & ot) const {
        return d < ot.d;
    }
}e[50005];
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
LL   dis[10005];
struct Rec {
    int v;
    LL d;
}rec[10005];
void update(int l, int r) {
    int u, v, d, idx = 0;
    for (int i = l; i <= r; ++i) {
        u = e[i].x, v = e[i].y, d = e[i].d;
        if (dis[u] != INF && dis[v] > dis[u] + d) {
            rec[idx].v = v, rec[idx++].d = dis[u] + d;
        }
        if (dis[v] != INF && dis[u] > dis[v] + d) {
            rec[idx].v = u, rec[idx++].d = dis[v] + d;
        }
    }
    for (int i = 0; i < idx; ++i) {
        dis[rec[i].v] = min(dis[rec[i].v], rec[i].d);
    }
}
void solve() {
    memset(dis, 0x3f, sizeof (dis));
    dis[1] = 0;
    for (int i = 0, j; i < M; i = j) {
        for (j = i + 1; j < M; ++j) {
            if (e[j].d != e[i].d) break;
        }
        update(i, j-1); 
    }
    if (dis[N] == INF) puts("No answer");
    else printf("%I64d\n", dis[N]);
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &N, &M);
        for (int i = 0; i < M; ++i) {
            scanf("%d %d %d", &e[i].x, &e[i].y, &e[i].d);
        }
        sort(e, e + M);
        solve();
    }
    return 0;
}
