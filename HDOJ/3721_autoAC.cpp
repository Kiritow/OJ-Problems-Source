#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;
const int maxn = 2505;
struct Graph {
    int hed[maxn], pnt[maxn*2], val[maxn*2], nxt[maxn*2], cnt;
    void init(int n) {
        cnt = 0;
        memset(hed, -1, 4 * n);
    }
    void addedge(int x, int y, int v) {
        pnt[cnt] = y; val[cnt] = v; nxt[cnt] = hed[x]; hed[x] = cnt++;
        pnt[cnt] = x; val[cnt] = v; nxt[cnt] = hed[y]; hed[y] = cnt++;
    }
} g;
queue<int> Q;
int n;
int banx, bany;
int par[maxn], dis[maxn];
int xx, yy;
int bfs(int x) {
    int ret = x;
    dis[x] = 0;
    Q.push(x);
    while (!Q.empty()) {
        int a = Q.front();
        Q.pop();
        for (int p = g.hed[a]; p != -1; p = g.nxt[p]) {
            int b = g.pnt[p];
            if (dis[b] != -1) continue;
            if (a == banx && b == bany || a == bany && b == banx) continue;
            par[b] = a;
            dis[b] = dis[a] + g.val[p];
            Q.push(b);
            if (dis[b] > dis[ret]) ret = b;
        }
    }
    return ret;
}
void FindRoad(int x) {
    memset(par, -1, 4 * n);
    memset(dis, -1, 4 * n);
    yy = bfs(x);
    memset(par, -1, 4 * n);
    memset(dis, -1, 4 * n);
    xx = bfs(yy);
}
int ans;
vector<int> v, d;
void Solve() {
    int t, disx, disy, disedge, dxx, dyy;
    banx = bany = -1;
    FindRoad(0);
    v.clear(); d.clear();
    t = xx;
    while (true) {
        v.push_back(t);
        t = par[t];
        if (t == -1) break;
        d.push_back(dis[v.back()] - dis[t]);
    }
    ans = dis[xx];
    for (int i = 1; i < v.size(); i++) {
        banx = v[i-1]; bany = v[i];
        disedge = d[i-1];
        FindRoad(banx);
        dxx = disx = dis[xx];
        for (t = xx; t != -1; t = par[t])
            disx = min(disx, max(dis[xx] - dis[t], dis[t]));
        FindRoad(bany);
        dyy = disy = dis[xx];
        for (t = xx; t != -1; t = par[t])
            disy = min(disy, max(dis[xx] - dis[t], dis[t]));
        ans = min(ans, max(max(disx + disy + disedge, dxx), dyy));
    }
}
int main() {
    int t, x, y, v, i, cas = 1;
    for (scanf("%d", &t); t--; ) {
        scanf("%d", &n);
        g.init(n);
        for (i = 1; i < n; i++) {
            scanf("%d %d %d", &x, &y, &v);
            g.addedge(x, y, v);
        }
        Solve();
        printf("Case %d: %d\n", cas++, ans);
    }
    return 0;
}
