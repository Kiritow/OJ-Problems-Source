#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VP;

class Solution {
  static const int MAXN = 2000 + 10;
  int a[MAXN], n, m;
  LL count00(LL ret = 0) {
    map<VI, VP> mp;
    for (int i = 1; i < n; i += 2) {
      VI pt; int sum = 0;
      for (int j = i; j + 1 < n; ++j) {
        pt.push_back(a[j]);
        if (j & 1) {
          if (a[i - 1] + sum + a[j + 1] >= m) {
            mp[pt].push_back(PII(a[i - 1], a[j + 1]));
          }
        } else sum += a[j];
        if (sum >= m) break;
      }
    }
    for (auto &e: mp) {
      VP &y = e.second, x;
      int sum = m;
      for (size_t i = 1; i < e.first.size(); i += 2) sum -= e.first[i];
      for (auto &v: y) {
        int L = v.first, R = v.second;
        v.first = max(1, sum - R);
        v.second = min(L, sum - 1);
        if (v.first <= v.second) x.push_back(v);
      }
      if (x.empty()) continue;
      sort(x.begin(), x.end());
      int l = x[0].first, r = x[0].second;
      for (size_t i = 0; i < x.size(); ++i) {
        if (x[i].first <= r) r = max(r, x[i].second);
        else {
          ret += r - l + 1;
          l = x[i].first;
          r = x[i].second;
        }
      }
      ret += r - l + 1;
    }
    return ret;
  }
  LL count10(LL ret = 0) {
    map<VI, int> mp;
    for (int i = 1; i < n; i += 2) {
      VI pt; int sum = 0;
      for (int j = i + 1; j < n; ++j) {
        pt.push_back(a[j]);
        if (~j & 1) {
          sum += a[j];
          if (sum >= m) {
            sum -= a[j];
            pt.pop_back();
            pt.push_back(m - sum);
            mp[pt] = max(mp[pt], a[i]);
            break;
          }
        }
      }
    }
    for (auto &e: mp) ret += e.second;
    return ret;
  }
  LL count11(LL ret = 0) {
    map<VI, VP> mp;
    for (int i = 2; i < n; i += 2) {
      VI pt; int sum = 0;
      for (int j = i; j + 1 < n; ++j) {
        pt.push_back(a[j]);
        if (~j & 1) {
          sum += a[j];
          if (sum == m) mp[pt].push_back(PII(a[i - 1], a[j + 1]));
          else if (sum > m) break;
        }
      }
    }
    for (auto &e: mp) {
      VP &y = e.second;
      sort(y.begin(), y.end());
      for (int i = y.size() - 2; i >= 0; --i) {
        y[i].second = max(y[i].second, y[i + 1].second);
      }
      for (size_t i = 0; i < y.size(); ++i) {
        int extra = i ? y[i].first - y[i - 1].first : y[i].first;
        ret += 1ll * extra * y[i].second;
      }
    }
    return ret;
  }
public:
  void run() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    LL ret = count00() + count11();
    ret += count10();
    if (n % 2 == 0) a[n++] = 0;
    reverse(a, a + n);
    ret += count10();
    for (int i = 0; i < n; i += 2) if (a[i] >= m && m) {
      ++ret; break;
    }
    if (m == 0) {
      ret = 0;
      for (int i = 1; i < n; i += 2) ret = max(ret, (LL)a[i]);
    }
    printf("%lld\n", ret);
  }
} sol;

int main() {
  int T; scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) sol.run();
  return 0;
}
