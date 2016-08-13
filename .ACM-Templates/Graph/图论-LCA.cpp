//LCA (Least Common Ancestors, 最近公共祖先)
//在线dfs + ST O(nlogn + q)
int dfso[N << 1], cnt; //欧拉序列, 即dfs序, 长度为2n-1, 下标从1开始
int pos[N]; //pos[i]表示点i在欧拉序列中第一次出现的位置
int dep[N << 1]; //欧拉序列对应的深度
int p[N << 1] = { -1}, dp[N << 1][20];
void initRMQ(int n) {
  for (int i = 1; i <= n; i++) { p[i] = p[i - 1] + !(i & (i - 1)); dp[i][0] = i; }
  for (int j = 1; j <= p[n]; j++) {
    for (int i = 1; i + (1 << j) - 1 <= n; i++) {
      dp[i][j] = dep[dp[i][j - 1]] < dep[dp[i + (1 << (j - 1))][j - 1]] ? dp[i][j - 1] : dp[i + (1 << (j - 1))][j - 1];
    }
  }
}
inline int queryRMQ(int l, int r) {
  if (l > r) { swap(l, r); }
  int k = p[r - l + 1];
  return dep[dp[l][k]] <= dep[dp[r - (1 << k) + 1][k]] ? dp[l][k] : dp[r - (1 << k) + 1][k];
}
void dfs(int u, int p, int d) {
  dfso[++cnt] = u; dep[cnt] = d; pos[u] = cnt;
  for (int i = head[u]; ~i; i = nxt[i]) {
    int v = to[i];
    if (v != p) { dfs(v, u, d + 1); dfso[++cnt] = u; dep[cnt] = d; }
  }
}
void initLCA(int rt, int n) {
  cnt = 0; dfs(rt, rt, 0); initRMQ(2 * n - 1);
}
inline int queryLCA(int u, int v) { //查询u和v的LCA编号
  return dfso[queryRMQ(pos[u], pos[v])];
}
//倍增法 O(nlogn + qlogn)
const int DEP = 20;
int fa[N][DEP]; //fa[i][j]表示结点i的第2^j个祖先
int dep[N]; //深度
void bfs(int rt) {
  queue<int> que; que.push(rt);
  dep[rt] = 0; fa[rt][0] = rt;
  while (!que.empty()) {
    int u = que.front(); que.pop();
    for (int i = 1; i < DEP; i++) { fa[u][i] = fa[fa[u][i - 1]][i - 1]; }
    for (int i = head[u]; ~i; i = nxt[i]) {
      int v = to[i];
      if (v != fa[u][0]) { dep[v] = dep[u] + 1; fa[v][0] = u; que.push(v); }
    }
  }
}
int queryLCA(int u, int v) {
  if (dep[u] > dep[v]) { swap(u, v); }
  for (int d = dep[v] - dep[u], i = 0; d; d >>= 1, i++) {
    if (d & 1) { v = fa[v][i]; }
  }
  if (u == v) { return u; }
  for (int i = DEP - 1; i >= 0; i--) {
    if (fa[u][i] != fa[v][i]) { u = fa[u][i]; v = fa[v][i]; }
  }
  return fa[u][0];
}
//离线Tarjan O(n + q)
int n, fa[N], ancestor[N], ans[N];
bool vis[N];
int qhead[N], qto[M], qnxt[M], qtot;
void init() {
  qtot = 0; memset(qhead, -1, sizeof(qhead));
  memset(ancestor, 0, sizeof(ancestor)); memset(vis, 0, sizeof(vis));
  for (int i = 0; i <= n; i++) { fa[i] = i; }
}
void qaddedge(int x, int y) {
  qto[qtot] = y; qnxt[qtot] = qhead[x]; qhead[x] = qtot++;
  qto[qtot] = x; qnxt[qtot] = qhead[y]; qhead[y] = qtot++;
}
int findfa(int n) { return n == fa[n] ? n : fa[n] = findfa(fa[n]); }
inline void unite(int x, int y) {
  x = findfa(x); y = findfa(y);
  if (x != y) { fa[y] = x; }
}
void Tarjan_LCA(int u) {
  ancestor[u] = u; vis[u] = true;
  for (int i = head[u]; ~i; i = nxt[i]) {
    int v = to[i];
    if (!vis[v]) { Tarjan_LCA(v); unite(u, v); ancestor[findfa(u)] = u; }
  }
  for (int i = qhead[u]; ~i; i = qnxt[i]) {
    int v = qto[i];
    if (vis[v]) { ans[i >> 1] = ancestor[findfa(v)]; }
  }
}
