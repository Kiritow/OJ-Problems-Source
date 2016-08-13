//邻接表
typedef int wtype;
const wtype INF = 0x3f3f3f3f;
int head[N], to[M], nxt[M], tot; wtype len[M];
void init() { tot = 0; memset(head, -1, sizeof(head)); }
void addedge(int x, int y, wtype z) { to[tot] = y; len[tot] = z; nxt[tot] = head[x]; head[x] = tot++; }
//Dijkstra + priority_queue + 邻接矩阵 O(V^2)
typedef int wtype;
struct Node {
  int v; wtype w;
  bool operator<(const Node &r)const { return w > r.w; }
};
int n, pre[N]; wtype mp[N][N], dist[N]; bool vis[N]; //邻接矩阵初始化为INF
void Dijkstra(int src) {
  memset(dist, 0x3f, sizeof(dist));
  memset(vis, 0, sizeof(vis)); memset(pre, -1, sizeof(pre));
  priority_queue<Node> que; que.push((Node) {src, dist[src] = 0});
  while (!que.empty()) {
    int u = que.top().v; que.pop();
    if (vis[u]) { continue; }
    vis[u] = true;
    for (int v = 0; v < n; v++) {
      if (!vis[v] && dist[v] > dist[u] + mp[u][v]) {
        dist[v] = dist[u] + mp[u][v]; pre[v] = u; que.push((Node) {v, dist[v]});
      }
    }
  }
}
//Dijkstra + priority_queue + vector存边 O((V+E)logV)
typedef int wtype;
struct Node {
  int v; wtype w;
  bool operator<(const Node &r)const { return w > r.w; }
};
vector<Node> e[N]; wtype dist[N]; bool vis[N];
void Dijkstra(int src) {
  memset(dist, 0x3f, sizeof(dist));
  memset(vis, 0, sizeof(vis));
  priority_queue<Node> que; que.push((Node) {src, dist[src] = 0});
  while (!que.empty()) {
    int u = que.top().v; que.pop();
    if (vis[u]) { continue; }
    vis[u] = true;
    for (int i = 0; i < (int)e[u].size(); i++) {
      int v = e[u][i].v; wtype w = e[u][i].w;
      if (!vis[v] && dist[v] > dist[u] + w) {
        dist[v] = dist[u] + w; que.push((Node) {v, dist[v]});
      }
    }
  }
}
//Dijkstra + priority_queue + 邻接表 O((V+E)logV)
typedef int wtype;
struct Node {
  int v; wtype w;
  bool operator<(const Node &r)const { return w > r.w; }
};
wtype dist[N];
void Dijkstra(int src) {
  memset(dist, 0x3f, sizeof(dist));
  priority_queue<Node> que; que.push((Node) {src, dist[src] = 0});
  while (!que.empty()) {
    int u = que.top().v; wtype w = que.top().w; que.pop();
    if (w > dist[u]) { continue; }
    for (int i = head[u]; ~i; i = nxt[i]) {
      int v = to[i];
      if (dist[v] > len[i] + w) {
        dist[v] = w + len[i]; que.push((Node) {v, dist[v]});
      }
    }
  }
}
//SPFA + queue/stack + vector存边 O(kE)
typedef int wtype;
struct Edge { int v; wtype w; };
vector<Edge> e[N]; int cnt[N], pre[N]; wtype dist[N]; bool vis[N];
bool SPFA(int src) {
  memset(dist, 0x3f, sizeof(dist)); dist[src] = 0;
  memset(cnt, 0, sizeof(cnt)); cnt[src] = 1;
  memset(vis, 0, sizeof(vis)); vis[src] = true;
  memset(pre, -1, sizeof(pre));
  queue<int> que; que.push(src); //stack
  while (!que.empty()) {
    int u = que.front(); que.pop();
    vis[u] = false;
    for (int i = 0; i < (int)e[u].size(); i++) {
      int v = e[u][i].v; wtype w = e[u][i].w;
      if (dist[v] > dist[u] + w) {
        dist[v] = dist[u] + w; pre[v] = u;
        if (!vis[v]) {
          vis[v] = true; que.push(v);
          if (++cnt[v] > n) { return false; } //有负环回路
        }
      }
    }
  }
  return true; //没有负环回路
}
//SPFA + SLF + LLL + 邻接表 O(kE)
typedef int wtype;
wtype dist[N];
bool vis[M];
void SPFA(int src) {
  memset(dist, 0x3f, sizeof(dist)); dist[src] = 0;
  memset(vis, 0, sizeof(vis)); vis[src] = true;
  deque<int> que; que.push_back(src);
  ll sum = 0;
  while (!que.empty()) {
    int u = que.front(); que.pop_front();
    if (!que.empty() && (ll)dist[u] * que.size() > sum) { que.push_back(u); continue; }
    sum -= dist[u]; vis[u] = false;
    for (int i = head[u]; ~i; i = nxt[i]) {
      int v = to[i]; wtype d = dist[u] + len[i];
      if (d < dist[v]) {
        if (vis[v]) { sum += d - dist[v]; }
        dist[v] = d;
        if (!vis[v]) {
          if (!que.empty() && dist[que.front()] > dist[v]) { que.push_front(v); }
          else { que.push_back(v); }
          sum += dist[v]; vis[v] = true;
        }
      }
    }
  }
}
//差分约束系统
//a向b连一条权值为c的有向边表示b − a <= c, 用SPFA判断是否存在负环, 存在即无解
//Bellman-Ford + vector O(VE)
//可以处理负边权图, 可以判断是否存在负环回路, 当且仅当图中不包含从源点可达的负权回路时返回true
typedef int wtype;
struct Edge { int u, v; wtype w; };
vector<Edge> e;
wtype dist[N];
bool BellmanFord(int src) {
  memset(dist, 0x3f, sizeof(dist)); dist[src] = 0;
  for (int i = 1; i < n; i++) {
    bool flag = false;
    for (int j = 0; j < (int)e.size(); j++) {
      int u = e[j].u, v = e[j].v; wtype w = e[j].w;
      if (dist[v] > dist[u] + w) { dist[v] = dist[u] + w; flag = true; }
    }
    if (!flag) { return true; } //没有负环回路
  }
  for (int j = 0; j < (int)e.size(); j++) {
    int u = e[j].u, v = e[j].v; wtype w = e[j].w;
    if (dist[v] > dist[u] + w) { return false; } //有负环回路
  }
  return true; //没有负环回路
}
//Floyd 带路径记录 O(V^3)
typedef int wtype;
int n, pre[N][N]; wtype mp[N][N]; //初始化为INF
void Floyd() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) { pre[i][j] = (i == j) ? -1 : i; }
  }
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (mp[i][k] + mp[k][j] < mp[i][j]) {
          mp[i][j] = mp[i][k] + mp[k][j]; pre[i][j] = pre[k][j];
        }
      }
    }
  }
}
//无负权图的最小环
//有向图: mp[i][i] = INF, 然后跑floyd, ans = min(d[i][i])
//求无向图中经过至少3个点的最小环:
typedef int wtype;
const wtype INF = 0x3f3f3f3f;
int n; wtype mp[N][N], d[N][N]; //初始化为INF
wtype cycFloyd() {
  memcpy(d, mp, sizeof(mp)); wtype ret = INF;
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i < k; i++) {
      for (int j = i + 1; j < k; j++) {
        ans = min(ans, d[i][j] + mp[i][k] + mp[k][j]);
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
}
//Astar求k短路
typedef int wtype;
const wtype INF = 0x3f3f3f3f;
int head[N], to[M], nxt[M], tot; wtype len[M];
int rhead[N], rto[M], rnxt[M], rtot; wtype rlen[M];
void init() { tot = rtot = 0; memset(head, -1, sizeof(head)); memset(rhead, -1, sizeof(rhead)); }
void addedge(int x, int y, wtype z) {
  to[tot] = y; len[tot] = z; nxt[tot] = head[x]; head[x] = tot++;
  rto[rtot] = x; rlen[rtot] = z; rnxt[rtot] = rhead[y]; rhead[y] = rtot++;
}
struct Node {
  int v; wtype w;
  bool operator<(const Node &r)const { return w > r.w; }
};
int vis[N]; wtype dist[N], ans[N]; //前k短路
void Astar(int src, int des, int k) {
  memset(dist, 0x3f, sizeof(dist)); memset(ans, 0x3f, sizeof(ans)); memset(vis, 0, sizeof(vis));
  priority_queue<Node> que; que.push((Node) {des, dist[des] = 0});
  while (!que.empty()) {
    int u = que.top().v; wtype w = que.top().w; que.pop();
    if (w > dist[u]) { continue; }
    for (int i = rhead[u]; ~i; i = rnxt[i]) {
      int v = rto[i];
      if (dist[v] > rlen[i] + w) {
        dist[v] = w + rlen[i]; que.push((Node) {v, dist[v]});
      }
    }
  }
  if (dist[src] < INF) { que.push((Node) {src, dis[src]}); }
  while (!que.empty()) {
    int u = que.top().v; wtype w = que.top().w; que.pop();
    if (u == des && vis[des] <= k) { ans[vis[des]] = w; }
    if (vis[u] > k) { continue; }
    for (int i = head[u]; ~i; i = nxt[i]) {
      int v = to[i]; que.push((Node) {v, w - dist[u] + dist[v] + len[i]});
    }
  }
}
