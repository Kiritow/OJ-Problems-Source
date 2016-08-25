#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;
const int N = 5005;
const int M = N << 4;
int p[N], n, m, sum, w[N];
struct Edge {
    int u, v, w;
    void init(int a, int b, int c) {
        u = a, v = b, w = c;
    }
    bool operator <(const Edge& e) const {
        return w < e.w;
    }
}E[M];
int find(int u) {
    if (p[u] != u) 
        p[u] = find(p[u]);
    return p[u];
}
const int lim = 17;
struct Tree {
    struct Edge {
        int v, w;
        Edge* next;
        void init(int a, Edge* e, int b) {
            v = a;
            w = b;
            next = e;
        }    
    };
    Edge E[M];
    Edge* it, * head[N];
    int pa[N][lim], dep[N], dis[N];
    int maxv[N][lim];
    int W[N];
    int n;
    void init(int n) {
        this->n = n;
        for (int i = 0; i < n; head[i++] = 0);
        it = E;
    }
    void add(int u, int v, int w) {
        it->init(v, head[u], w);
        head[u] = it++;
        it->init(u, head[v], w);
        head[v] = it++;
    }
    int lca(int u, int v) {
        if (dep[u] > dep[v]) swap(u, v);
        if (dep[u] < dep[v]) {
            int d = dep[v] - dep[u];
            for (int i = 0; i < lim; i++)
                if (d & (1 << i))
                    v = pa[v][i];
        }
        if (u != v) {
            for (int i = lim - 1; i >= 0; i--)
                if (pa[u][i] != pa[v][i]) {
                    u = pa[u][i];
                    v = pa[v][i];
                }
            u = pa[u][0];
        }
        return u;
    }
    int query(int u, int v) {
        if (dep[u] > dep[v]) swap(u, v);
        int res = -1;
        if (dep[u] < dep[v]) {
            int d = dep[v] - dep[u];
            for (int i = 0; i < lim; i++)
                if (d & (1 << i)) {
                    res = max(maxv[v][i], res);
                    v = pa[v][i];        
                }
        }
        if (u != v) {
            for (int i = lim - 1; i >= 0; i--) {
                if (pa[u][i] != pa[v][i]) {
                    res = max(res, maxv[u][i]);
                    res = max(res, maxv[v][i]);
                    u = pa[u][i];
                    v = pa[v][i];
                }
            }
            res = max(res, maxv[u][0]);
            res = max(res, maxv[v][0]);
        }
        return res;
    }
    void dfs(int u, int fa) {
        pa[u][0] = fa;
        maxv[u][0] = W[u];
        dep[u] = dep[fa] + 1;
        for (int i = 1; (1 << i) < n; i++) {
            pa[u][i] = pa[pa[u][i - 1]][i - 1];
            maxv[u][i] = max(maxv[u][i - 1], maxv[pa[u][i - 1]][i - 1]);
        }
        for (Edge* e = head[u]; e; e = e->next) {
            int v = e->v;
            if (v != fa) {
                W[v] = e->w;
                dfs(v, u);
            }
        }    
    }
    void run(int rt) {
        dep[rt] = -1;
        W[rt] = -1;
        dfs(rt, rt);
    }
}T;
int main() {
    int u, v, w, c;
    while (~scanf("%d%d%d", &n, &m, &sum)) {
        c = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &w);
            E[c].init(0, i, w);
            c++;
        }
        for (int i = 0; i < m; i++) {
            scanf("%d%d%d", &u, &v, &w);
            E[c].init(u, v, w);
            c++;
        }
        n++;
        m += n;
        T.init(n);
        int res = 0;
        sort(E, E + c);
        int cnt = 0;
        for (int i = 0; i < n; i++) p[i] = i;
        for (int i = 0; i < c; i++) {
            int fu = find(E[i].u), fv = find(E[i].v);
            if (fu != fv) {
                p[fu] = fv;
                res += E[i].w;
                T.add(E[i].u, E[i].v, E[i].w);    
                cnt++;
            }
            if (cnt == n - 1) break;
        }
        T.run(0);
        for (int i = 0; i < sum; i++) {
            scanf("%d%d", &u, &v);
            int tmp = T.query(u, v);
            printf("%d\n", res - tmp);
        }
    }    
    return 0;
}
