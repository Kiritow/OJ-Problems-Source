#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
  static const int MAXN = 100000 + 10;
  static const LL inf = 1ll << 60;
  vector<int> G[MAXN];
  int w[MAXN], n;

  struct Line {// m * x + b
    LL m, b;
    double inter(const Line &r) const {
      return (r.b - b) / (m - r.m);
    }
    inline LL eval(LL x) {return m * x + b;}
  } Q[MAXN];a

  int rt, mins, total, top;
  int vs[MAXN], sz[MAXN], dep[MAXN];
  LL val[MAXN], ps[MAXN], ret;

  void getCenter(int u, int f = -1) {
    int mx = 0; sz[u] = 1;
    for (auto &v: G[u]) if (v != f && !vs[v]) {
      getCenter(v, u); sz[u] += sz[v];
      mx = max(mx, sz[v]);
    }
    mx = max(mx, total - sz[u]);
    if (mx < mins) mins = mx, rt = u;
  }
  int dfs1(int u, int d = 1) {
    ret = max(ret, val[d]);
    for (auto &v: G[u]) if (!vs[v] && u > v) {
      ps[v] = ps[u] + w[v];
      val[d + 1] = val[d] + ps[v];
      return dfs1(v, d + 1) + 1;
    }
    return 1;
  }
  void dfs2(int u, int d = 0, LL sum = 0) {
    sum += 1ll * d * w[u];
    // max(ps[u] * m + b + sum)
    int left = 0, right = top - 2;
    while (left < right) {
      int mid = (left + right) >> 1;
      if (Q[mid].eval(ps[u]) >= Q[mid + 1].eval(ps[u])) right = mid;
      else left = mid + 1;
    }
    ret = max(ret, Q[left].eval(ps[u]) + sum);
    if (left + 1 < top) ret = max(ret, Q[left + 1].eval(ps[u]) + sum);
    for (auto &v: G[u]) if (!vs[v] && u < v) {
      ps[v] = ps[u] + w[v];
      dfs2(v, d + 1, sum);
    }
  }
  void solve(int u, int _tot) {
    total = _tot; mins = _tot * 2;
    getCenter(u); u = rt; vs[u] = 1; getCenter(u);
    val[1] = ps[u] = w[u];
    int md = dfs1(u);
    top = 0;
    for (int i = 1; i <= md; ++i) {
      Line now = (Line){i, val[i]};
      while (top >= 2 && Q[top - 2].inter(Q[top - 1]) >= Q[top - 1].inter(now)) --top;
      Q[top++] = now;
    }
    ps[u] = 0; dfs2(u);
    for (int i = 0; i <= md; ++i) val[i] = -inf;
    for (auto &v: G[u]) if (!vs[v]) {
      solve(v, sz[v]);
    }
  }

public:
  void run() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", w + i); G[i].clear();
    }
    for (int i = 1; i < n; ++i) {
      int x; scanf("%d", &x); --x;
      G[x].push_back(i);
      G[i].push_back(x);
    }
    ret = 0;
    for (int i = 0; i < n; ++i) val[i] = -inf;
    memset(vs, 0, sizeof(vs[0]) * n);
    solve(0, n);
    printf("%lld\n", ret);
  }
} sol;

int main() {
  int T; scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) sol.run();
  return 0;
}
