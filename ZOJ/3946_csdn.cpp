#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int MAXN = 100000 + 10;
vector<PII> G[MAXN];
int X[MAXN], Y[MAXN], D[MAXN], C[MAXN];
LL ds[MAXN], ms[MAXN];
int n, m;

void run() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    G[i].clear();
    ms[i] = ds[i] = 1ll << 60;
  }
  for (int i = 0; i < m; ++i) {
    cin >> X[i] >> Y[i] >> D[i] >> C[i];
    G[X[i]].push_back(PII(Y[i], i));
    G[Y[i]].push_back(PII(X[i], i));
  }
  ds[0] = ms[0] = 0;
  queue<int> Q; Q.push(0);
  vector<bool> vs(n);
  while (!Q.empty()) {
    int u = Q.front(); Q.pop(); vs[u] = 0;
    for (auto &x: G[u]) {
      int v = x.first, w = D[x.second];
      if (ds[v] > ds[u] + w) {
        ds[v] = ds[u] + w;
        if (!vs[v]) vs[v] = 1, Q.push(v);
      }
    }
  }
  for (int i = 0; i < m; ++i) {
    if (ds[X[i]] + D[i] == ds[Y[i]]) {
      ms[Y[i]] = min(ms[Y[i]], (LL)C[i]);
    }
    if (ds[Y[i]] + D[i] == ds[X[i]]) {
      ms[X[i]] = min(ms[X[i]], (LL)C[i]);
    }
  }
  LL SD = 0, SC = 0;
  for (int i = 0; i < n; ++i) SD += ds[i], SC += ms[i];
  cout << SD << " " << SC << endl;
}

int main() {
  int T; cin >> T;
  for (int cas = 1; cas <= T; ++cas) run();
  return 0;
}
