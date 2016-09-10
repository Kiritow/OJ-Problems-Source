#include <cstdio>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;
const int MAXN = 210;
const int MAXE = 210 * 210 * 2;
const int INF = 0x3f3f3f3f;
struct ZKW_flow{
    int st, ed, ecnt, n;
    int head[MAXN];
    int cap[MAXE], cost[MAXE], to[MAXE], next[MAXE];
    void init(){
        memset(head, 0, sizeof(head));
        ecnt = 2;
    }
    void addEdge(int u, int v, int cc, int ww){
        cap[ecnt] = cc; cost[ecnt] = ww; to[ecnt] = v;
        next[ecnt] = head[u]; head[u] = ecnt++;
        cap[ecnt] = 0; cost[ecnt] = -ww; to[ecnt] = u;
        next[ecnt] = head[v]; head[v] = ecnt++;
    }
    int dis[MAXN];
    void SPFA(){
        for(int i = 1; i <= n; ++i) dis[i] = INF;
        priority_queue<pair<int, int> > Q;
        dis[st] = 0;
        Q.push(make_pair(0, st));
        while(!Q.empty()){
            int u = Q.top().second, d = -Q.top().first;
            Q.pop();
            if(dis[u] != d) continue;
            for(int p = head[u]; p; p = next[p]){
                int &v = to[p];
                if(cap[p] && dis[v] > d + cost[p]){
                    dis[v] = d + cost[p];
                    Q.push(make_pair(-dis[v], v));
                }
            }
        }
        for(int i = 1; i <= n; ++i) dis[i] = dis[ed] - dis[i];
    }
    int minCost, maxFlow;
    bool use[MAXN];
    int add_flow(int u, int flow){
        if(u == ed){
            maxFlow += flow;
            minCost += dis[st] * flow;
            return flow;
        }
        use[u] = true;
        int now = flow;
        for(int p = head[u]; p; p = next[p]){
            int &v = to[p];
            if(cap[p] && !use[v] && dis[u] == dis[v] + cost[p]){
                int tmp = add_flow(v, min(now, cap[p]));
                cap[p] -= tmp;
                cap[p^1] += tmp;
                now -= tmp;
                if(!now) break;
            }
        }
        return flow - now;
    }
    bool modify_label(){
        int d = INF;
        for(int u = 1; u <= n; ++u) if(use[u])
            for(int p = head[u]; p; p = next[p]){
                int &v = to[p];
                if(cap[p] && !use[v]) d = min(d, dis[v] + cost[p] - dis[u]);
            }
        if(d == INF) return false;
        for(int i = 1; i <= n; ++i) if(use[i]) dis[i] += d;
        return true;
    }
    int min_cost_flow(int ss, int tt, int nn){
        st = ss, ed = tt, n = nn;
        minCost = maxFlow = 0;
        SPFA();
        while(true){
            while(true){
                for(int i = 1; i <= n; ++i) use[i] = 0;
                if(!add_flow(st, INF)) break;
            }
            if(!modify_label()) break;
        }
        return minCost;
    }
} G;
struct Point {
    int x, y, z, w;
    void read() {
        scanf("%d%d%d%d", &x, &y, &z, &w);
    }
    int operator * (const Point &rhs) const {
        double xx = x - rhs.x, yy = y - rhs.y, zz = z - rhs.z;
        return (int)sqrt(xx * xx + yy * yy + zz * zz);
    }
};
Point a[MAXN];
int n;
int main() {
    while(scanf("%d", &n) != EOF && n) {
        int sumw = 0;
        for(int i = 1; i <= n; ++i) a[i].read(), sumw += a[i].w;
        G.init();
        int ss = 2 * n + 1, tt = ss + 1;
        for(int i = 1; i <= n; ++i) {
            G.addEdge(ss, i, a[i].w, 0);
            G.addEdge(i + n, tt, a[i].w, 0);
            for(int j = i + 1; j <= n; ++j) {
                int cost = a[i] * a[j];
                G.addEdge(i, j + n, INF, cost);
                G.addEdge(j, i + n, INF, cost);
            }
        }
        int ans = G.min_cost_flow(ss, tt, tt);
        if(sumw != G.maxFlow) ans = -1;
        printf("%d\n", ans);
    }
}
