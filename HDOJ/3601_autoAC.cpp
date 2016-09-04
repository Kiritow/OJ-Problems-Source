#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#define N 30009
#define lc (d<<1)
#define rc (d<<1|1)
#define mid (l+r>>1)
#define inf 0x3f3f3f3f
struct Tr{
    int mx, sum;
}tr[N<<4];
int n, sun[N], tid[N], top[N], val[N], dep[N], tot, tmp[N], fa[N];
vector<int>V[N];
int dfs(int u, int f) {
    int i, v, id = u, mx = 0, c = 1;
    fa[u] = f;
    for (i = 0;i < V[u].size();i++) {
        v = V[u][i];
        if (v == f) continue;
        int tm = dfs(v, u);
        if (tm > mx) mx = tm, id = v;
        c += tm;
    }
    sun[u] = id;
    return c;
}
void dfs1(int u, int d, int Top) {
    int i, v;
    dep[u] = d, tid[u] = ++tot, top[u] = Top;
    if (tid[sun[u]] == -1) dfs1(sun[u], d+1, Top);
    for (i = 0;i < V[u].size();i++) {
        v = V[u][i];
        if (tid[v] != -1) continue;
        dfs1(v, d+1, v);
    }
}
void Push(int d) {
    tr[d].sum = tr[lc].sum+tr[rc].sum;
    tr[d].mx = max(tr[lc].mx, tr[rc].mx);
}
void build(int d, int l, int r) {
    if (l == r) {
        tr[d].mx = tr[d].sum = val[l];
        return;
    }
    build(lc, l, mid), build(rc, mid+1, r);
    Push(d);
}
void update(int d, int l, int r, int pos, int v) {
    if (l == r && pos == l) {
        tr[d].mx = tr[d].sum = v;
        return;
    }
    if (pos <= mid) update(lc, l, mid, pos, v);
    else update(rc, mid+1, r, pos, v);
    Push(d);
}
int query(int d, int l, int r, int L, int R, int k) {
    if (l == L && r == R) {
        if (k) return tr[d].mx;
        return tr[d].sum;
    }
    if (R <= mid) return query(lc, l, mid, L, R, k);
    else if (L > mid) return query(rc, mid+1, r, L, R, k);
    else {
        if (k) return max(query(lc, l, mid, L, mid, k), query(rc, mid+1, r, mid+1, R, k));
        else return query(lc, l, mid, L, mid, k)+query(rc, mid+1, r, mid+1, R, k);
    }
}
int M(int u, int v, int k) {
    int re = 0, tm;
    if (k) re = -inf;
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) swap(u, v);
        tm = query(1, 1, tot, tid[top[u]], tid[u], k);
        if (k) re = max(tm, re);
        else re += tm;
        u = fa[top[u]];
    }
    if (tid[u] > tid[v]) swap(u, v);
    tm = query(1, 1, tot, tid[u], tid[v], k);
    if (k) re = max(tm, re);
    else re += tm;
    return re;
}
int main() {
    int i, j, u, v, m;
    char w[10];
    while (~scanf("%d", &n)) {
        for (i = 1;i <= n;i++) V[i].clear();
        for (i = 1;i < n;i++) {
            scanf("%d%d", &u, &v);
            V[u].push_back(v), V[v].push_back(u);
        }
        memset(tid, -1, sizeof(tid));
        tot = 0;
        for (i = 1;i <= n;i++) scanf("%d", &tmp[i]);
        dfs(1, -1);
        dfs1(1, 0, 1);
        for (i = 1;i <= n;i++) val[tid[i]] = tmp[i];
        build(1, 1, tot);
        scanf("%d", &m);
        while (m--) {
            scanf("%s%d%d", w, &u, &v);
            if (w[0] == 'C') {
                update(1, 1, tot, tid[u], v);
            }else if (w[1] == 'M') {
                printf("%d\n", M(u, v, 1));
            }else printf("%d\n", M(u, v, 0));
        }
    }
}
