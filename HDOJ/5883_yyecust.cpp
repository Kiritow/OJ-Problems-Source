#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 100000;
int g[MAXN]; //g[i]表示与i相连的边数
int a[MAXN];
void solve()
{
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    g[i] = 0;
  }
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--;
    v--;
    g[u]++;
    g[v]++;
  }
  int ods = 0; //奇点数
  int xors = 0;
  for (int i = 0; i < n; i++) {
    if (g[i] % 2) {
      ods++;
      if (g[i] % 3) {
        xors ^= a[i];
      }
    } else {
      if (g[i] % 4) {
        xors ^= a[i];
      }
    }
  }
  if (ods > 2) {
    puts("Impossible");
    return;
  }
  if (ods == 2) {
    printf("%d\n", xors);
    return;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, xors ^ a[i]);
  }
  printf("%d\n", ans);
}
int main()
{
  //freopen("in.txt", "r", stdin);
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
}
