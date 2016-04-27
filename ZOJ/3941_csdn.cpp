#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int MAXN = 100 + 10;

PII P[MAXN];
int n, m, k;

void run() {
  cin >> n >> k >> m;
  for (int i = 0; i < n; ++i) {
    cin >> P[i].first >> P[i].second;
  }
  sort(P, P + n);
  int s = 0, ret = 0;
  for (int i = 1; i < n; ++i) {
    if (P[i].first <= P[s].second + 1) {
      P[s].second = max(P[s].second, P[i].second);
    } else P[++s] = P[i];
  }
  n = s + 1; s = 1 << n;
  for (int msk = 0; msk < s; ++msk) {
    int sum = 0, now = 0, rest = m;
    for (int i = 0; i < n && rest; ++i) {
      now = max(now, P[i].first - 1);
      if (now >= P[i].second && (msk >> i & 1)) {
        sum += P[i].second + k - 1 - now;
        now = P[i].second + k - 1;
        rest--;
      } else if (now < P[i].second) {
        int t = min(rest, (P[i].second - now - 1) / k + 1);
        sum += t * k; now += t * k; rest -= t;
        assert(now >= P[i].second || rest == 0);
        if (rest && (msk >> i & 1)) {
          sum += P[i].second + k - 1 - now;
          now = P[i].second + k - 1;
          rest--;
        }
      }
    }
    ret = max(ret, sum);
  }
  cout << ret << endl;
}

int main() {
  int T; scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) run();
  return 0;
}
