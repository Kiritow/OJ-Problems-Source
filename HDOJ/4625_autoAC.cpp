#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 5e4 + 10;
const int maxk = 5e2 + 10;
const int mod = 10007;
typedef long long LL;
struct edge {
  int v, to;
};
vector<edge> E;
int L[maxn];
void graph_init()
{
  E.clear();
  memset(L, -1, sizeof(L));
}
void graph_add(int u, int v)
{
  edge t = {v, L[u]};
  L[u] = E.size();
  E.push_back(t);
}
int s[maxk][maxk];  
int f[maxk];       
int c[maxk][maxk]; 
void init()
{
  s[0][0] = f[0] = c[0][0] = 1;
  for (int i = 1; i < maxk; i++) {
    f[i] = f[i-1] * i % mod;
    c[i][0] = 1;
    for (int j = 1; j < maxk; j++) {
      s[i][j] = (j * s[i-1][j] % mod + s[i-1][j-1]) % mod;
      c[i][j] = (c[i-1][j] + c[i-1][j-1]) % mod;
    }
  }
}
int n, k;
int d[maxn][maxk];
void dp_son(int u = 0, int p = -1)
{
  memset(d[u], 0, sizeof(d[u]));
  for (int i = L[u]; i != -1; i = E[i].to)
    if (i != p) {
      int v = E[i].v;
      dp_son(v, i^1);
      for (int j = 0; j <= k; j++)
        d[u][j] = (d[u][j] + d[v][j] + (j? d[v][j-1]: 0) + c[1][j]) % mod;
    }
}
int tmp[maxk];
void dp_father(int u = 0, int p = -1)
{
  if (p != -1) {
    int v = E[p].v;
    memcpy(tmp, d[v], sizeof(d[v]));
    for (int j = 0; j <= k; j++)
      tmp[j] = (tmp[j] - (d[u][j] + (j? d[u][j-1]: 0) + c[1][j]) % mod + mod) % mod;
    for (int j = 0; j <= k; j++)
      d[u][j] = (d[u][j] + tmp[j] + (j? tmp[j-1]: 0) + c[1][j]) % mod;
  }
  for (int i = L[u]; i != -1; i = E[i].to)
    if (i != p) dp_father(E[i].v, i^1);
}
int main()
{
  init();
  int T;
  scanf("%d", &T);
  for ( ; T--; ) {
    graph_init();
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n-1; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
      u--, v--;
      graph_add(u, v);
      graph_add(v, u);
    }
    dp_son();
    dp_father();
    for (int u = 0; u < n; u++) {
      int sum = 0;
      for (int i = 0; i <= k; i++)
        sum = (sum + s[k][i]*f[i]%mod*d[u][i]%mod) % mod;
      printf("%d\n", sum);
    }
  }
  return 0;
}
