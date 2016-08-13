//莫队算法 O(n^1.5)
//莫队算法是离线处理一类区间不修改查询类问题的算法
//如果你知道了[L,R]的答案, 你可以在O(1)的时间下得到[L,R-1]和[L,R+1]和[L-1,R]和[L+1,R]的答案的话, 就可以使用莫队算法
//lydsy 2038: [2009国家集训队]小Z的袜子(hose)
int n, m;
int c[N], pos[N];
int ansup[N], ansdn[N], cnt[N];
struct Node {
  int l, r, id;
  bool operator<(const Node &b)const { return pos[l] < pos[b.l] || (pos[l] == pos[b.l] && r < b.r); }
} q[N];
int main() {
  while (~scanf("%d%d", &n, &m)) {
    memset(cnt, 0, sizeof(cnt)); ll ans = 0;
    for (int i = 1, nn = ceil(sqrt(n)); i <= n; i++) { scanf("%d", &c[i]); pos[i] = (i - 1) / nn; }
    for (int i = 0; i < m; i++) { scanf("%d%d", &q[i].l, &q[i].r); q[i].id = i; }
    sort(q, q + m);
    for (int i = 0, l = 1, r = 0; i < m; i++) {
      for (; l > q[i].l;) { ans += cnt[c[--l]]++; }
      for (; l < q[i].l;) { ans -= --cnt[c[l++]]; }
      for (; r < q[i].r;) { ans += cnt[c[++r]]++; }
      for (; r > q[i].r;) { ans -= --cnt[c[r--]]; }
      ll dn = (r - l + 1LL) * (r - l) >> 1, gcd = __gcd(ans, dn);
      ansup[q[i].id] = ans / gcd; ansdn[q[i].id] = dn / gcd;
    }
    for (int i = 0; i < m; i++) { printf("%d/%d\n", ansup[i], ansdn[i]); }
  }
}
