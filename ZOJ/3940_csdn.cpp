#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000 + 10, M = 1e9 + 7;
int a[MAXN], n, m;
map<int, int> last;

void run() {
  scanf("%d%d", &n, &m);
  last.clear(); last[m] = 1;
  for (int i = 0; i < n; ++i) {
    int x, s = 0; scanf("%d", &x);
    auto it = last.lower_bound(x);
    for (; it != last.end(); ) {
      last[it->first % x] += it->second;
      s += it->second * (it->first / x);
      it = last.erase(it);
    }
    if (s) last[x - 1] += s;
  }
  int s = 0;
  for (auto it = last.rbegin(); it != last.rend(); ++it) {
    it->second += s; s = it->second;
  }
  int q, ret = 0; scanf("%d", &q);
  for (int i = 1; i <= q; ++i) {
    int x; scanf("%d", &x);
    auto it = last.lower_bound(x);
    if (it != last.end()) ret += 1ll * it->second * i % M;
    if (ret >= M) ret -= M;
  }
  printf("%d\n", ret);
}

int main() {
  int T; scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) run();
  return 0;
}
