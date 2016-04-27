#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
  static const int MAXN = 100000 + 10;
  static const LL inf = 1ll << 60;
  int a[MAXN], n, q, ret;
  bool mark[MAXN];
  set<int> eq;

  struct BIT {
    LL u[MAXN];
    int n;
    void clr(int _n) {
      n = _n;
      memset(u, 0, sizeof(u[0]) * (n + 1));
    }
    void add(int x, LL v) {
      for (; x <= n; x += ~x & x + 1) u[x] += v;
    }
    void add(int l, int r, LL v) {//[l, r]
      add(l, v); add(r + 1, -v);
    }
    LL get(int x, LL r = 0) {//[0,x]
      for (; x >= 0; x -= ~x & x + 1) r += u[x];
      return r;
    }
  } bit;

  struct SegTree {
    #define lson (rt<<1)
    #define rson (rt<<1|1)
    #define mid ((l+r)>>1)
    struct Node {
      LL val, add;
      int idx;
      void mark(LL v) {
        val += v; add += v;
      }
    } T[MAXN << 2];
    void upd(int rt) {
      T[rt].val = max(T[lson].val, T[rson].val);
      if (T[rt].val == T[lson].val) T[rt].idx = T[lson].idx;
      else T[rt].idx = T[rson].idx;
    }
    void psd(int rt) {
      T[lson].mark(T[rt].add);
      T[rson].mark(T[rt].add);
      T[rt].add = 0;
    }
    void build(int rt, int l, int r) {
      T[rt].add = 0; T[rt].val = -inf; T[rt].idx = l;
      if (l + 1 == r) return;
      build(lson, l, mid);
      build(rson, mid, r);
    }
    void ins(int rt, int l, int r, int x, LL v) {
      if (l + 1 == r) {T[rt].val = v; return;}
      psd(rt);
      if (x < mid) ins(lson, l, mid, x, v);
      else ins(rson, mid, r, x, v);
      upd(rt);
    }
    void add(int rt, int l, int r, int L, int R, LL v) {
      if (L <= l && R >= r) {T[rt].mark(v); return;}
      psd(rt);
      if (L < mid) add(lson, l, mid, L, R, v);
      if (R > mid) add(rson, mid, r, L, R, v);
      upd(rt);
    }
    const Node& Max() const {return T[1];}
  } st;

public:
  void run() {
    scanf("%d%d", &n, &q); ret = 0;
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    st.build(1, 0, n); bit.clr(n);
    eq.clear(); a[n] = 0;
    memset(mark, 0, sizeof(mark));
    for (int i = n - 1; i > 0; --i) {
      a[i] -= a[i - 1];
      if (a[i] == 0) eq.insert(i);
      if (a[i] < 0) st.ins(1, 0, n, i, a[i]);
      if (a[i] > 0 && a[i + 1] < 0) ++ret;
      bit.add(i, i, a[i]);
    }
    cerr << ret << std::endl;
    for (int i = 0; i < q; ++i) {
      int l, r, a, b; scanf("%d%d%d%d", &l, &r, &a, &b);
      LL cl = a, cr = a + 1ll * b * (r - l); --l;
      vector<int> pt;
      st.ins(1, 0, n, l, -inf); eq.erase(l);
      if (l) pt.push_back(l);
      if (l < r - 1) {
        for (auto it = eq.lower_bound(l); it != eq.end(); it = eq.erase(it)) {
          if (*it >= r) break; pt.push_back(*it);
        }
        st.add(1, 0, n, l + 1, r, b);
        while (st.Max().val >= 0) {
          pt.push_back(st.Max().idx);
          st.ins(1, 0, n, pt.back(), -inf);
        }
      }
      if (r < n) {
        st.ins(1, 0, n, r, -inf);
        eq.erase(r);
        pt.push_back(r);
      }
      for (auto &x: pt) mark[x] = true;
      for (auto &x: pt) {
        LL v = bit.get(x);
        if (x > 1 && v < 0 && bit.get(x - 1) > 0) --ret;
        if (x + 1 < n && v > 0 && bit.get(x + 1) < 0 && !mark[x + 1]) --ret;
      }
      if (l) bit.add(l, l, cl);
      if (l < r - 1) bit.add(l + 1, r - 1, b);
      if (r < n) bit.add(r, r, -cr);
      for (auto &x: pt) {
        LL v = bit.get(x);
        if (x > 1 && v < 0 && bit.get(x - 1) > 0) ++ret;
        if (x + 1 < n && v > 0 && bit.get(x + 1) < 0 && !mark[x + 1]) ++ret;
        if (v == 0) eq.insert(x);
        if (v < 0) st.ins(1, 0, n, x, v);
      }
      for (auto &x: pt) mark[x] = false;
      printf("%d\n", ret);
    }
  }
} sol;

int main() {
  int T; scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) sol.run();
  return 0;
}
