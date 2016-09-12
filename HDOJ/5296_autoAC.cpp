#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f
#define inf (-((LL)1<<40))
#define lson k<<1, L, (L + R)>>1
#define rson k<<1|1,  ((L + R)>>1) + 1, R
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define mem(a, b) memset(a, b, sizeof(a))
#define rep(i, a, b) for(int i = (a); i <= (b); i ++)
#define dec(i, a, b) for(int i = (a); i >= (b); i --)
template<class T> T MAX(T a, T b) { return a > b ? a : b; }
template<class T> T MIN(T a, T b) { return a < b ? a : b; }
template<class T> T GCD(T a, T b) { return b ? GCD(b, a%b) : a; }
template<class T> T LCM(T a, T b) { return a / GCD(a,b) * b;    }
typedef long long LL;
const int MAXN = 100000 + 100;
const int MAXM = 2000000 + 100;
const double eps = 1e-8;
LL MOD = 1000000007;
struct Edge {
    int v, w;
    Edge(int _v = 0, int _w = 0) {
        v = _v; w = _w;
    }
};
struct LCA {
    int idx[MAXN << 1];
    int dep[MAXN << 1];
    int dp[MAXN << 1][20];
    int K[MAXN << 1];
    int node_cnt;
    vector<Edge>G[MAXN];
    int P[MAXN];
    int dis[MAXN];
    void init(int n) {
        mem0(dep); mem0(K);
        node_cnt = 0;
        rep (i, 0, n) G[i].clear();
    }
    void add_edge(int u, int v, int w) {
        G[u].push_back(Edge(v, w));
        G[v].push_back(Edge(u, w));
    }
    void dfs(int u, int fa, int height, int dist) {
        idx[++node_cnt] = u;
        dep[node_cnt] = height;
        P[u] = node_cnt;
        dis[u] = dist;
        int sz = G[u].size();
        rep (i, 0, sz - 1) {
            int v = G[u][i].v;
            if(v == fa) continue;
            dfs(v, u, height + 1, dist + G[u][i].w);
            idx[++node_cnt] = u;
            dep[node_cnt] = height;
        }
    }
    void init_st_table() {
        dfs(1, -1, 0, 0);
        int n = node_cnt;
        rep (i, 1, n) {
            dp[i][0] = i;
            while((1 << (K[i] + 1)) <= i) K[i] ++;
        }
        for(int j = 1; (1 << j) <= n; j ++) {
            for(int i = 1; i + (1 << j) - 1 <= n; i ++) {
                int l_pos = dp[i][j - 1], r_pos = dp[i + (1 << (j - 1))][j - 1];
                dp[i][j] = dep[l_pos] < dep[r_pos] ? l_pos : r_pos;
            }
        }
    }
    int rmq_query(int L, int R) {
        if(L > R) swap(L, R);
        int len = R - L + 1, k = K[len];
        return dep[dp[L][k]] < dep[dp[R - (1 << k) + 1][k]] ? dp[L][k] : dp[R - (1 << k) + 1][k];
    }
    int lca_query(int u, int v) {
        int id = rmq_query(P[u], P[v]);
        return idx[id];
    }
}lca;
struct SegTree  {
    int s[MAXN << 3];
    void update(int k, int L, int R, int p, int v) {
        if(L == R) { s[k] = v; return ; }
        if(((L + R) >> 1) >= p)  update(lson, p, v);
        else update(rson, p, v);
        s[k] = s[k << 1] + s[k << 1 | 1];
    }
    int query_sum(int k, int L, int R, int p) {
        if(R <= p) return s[k];
        if( ((L + R) >> 1) >= p ) return query_sum(lson, p);
        return s[k << 1] + query_sum(rson, p);
    }
    int query_pos(int k, int L, int R, int x) {
        if(L == R) return L;
        if(s[k << 1] >= x) return query_pos(lson, x);
        return query_pos(rson, x - s[k << 1]);
    }
}st;
int t, n, m, cas = 0;
int u, v, w;
bool vis[MAXN << 1];
int main()
{
    cin >> t;
    while(t--) {
        scanf("%d %d", &n, &m);
        lca.init(n);
        rep (i, 2, n) {
            scanf("%d %d %d", &u, &v, &w);
            lca.add_edge(u, v, w);
        }
        lca.init_st_table();
        mem0(st.s);
        mem0(vis);
        int ans = 0;
        printf("Case #%d:\n", ++cas);
        while(m --) {
            scanf("%d %d", &u, &v);
            if( (u == 1 && !vis[v]) || (u == 2 && vis[v]) ) {
                vis[v] = !vis[v];
                if(u == 2) st.update(1, 1, lca.node_cnt, lca.P[v], 0);
                if( st.s[1] ) {
                    int x, y;
                    int sum = st.query_sum(1, 1, lca.node_cnt, lca.P[v]);
                    if( !sum || sum == st.s[1] ) x = 1, y = st.s[1];
                    else x = sum, y = sum + 1;
                    x = lca.idx[st.query_pos(1, 1, lca.node_cnt, x)];
                    y = lca.idx[st.query_pos(1, 1, lca.node_cnt, y)];
                    int xv = lca.lca_query(x, v);
                    int yv = lca.lca_query(y, v);
                    int xy = lca.lca_query(x, y);
                    ans += (u == 1 ? 1 : -1) * (lca.dis[v] - lca.dis[xv] - lca.dis[yv] + lca.dis[xy]);
                }
                else ans = 0;
                if(u == 1) st.update(1, 1, lca.node_cnt, lca.P[v], 1);
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
