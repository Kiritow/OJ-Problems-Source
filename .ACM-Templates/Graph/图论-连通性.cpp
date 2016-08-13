//图的割点、桥与双连通分量
//[点连通度与边连通度]
//在一个无向连通图中, 如果有一个顶点集合, 删除这个顶点集合,
//以及这个集合中所有顶点相关联的边以后, 原图变成多个连通块, 就称这个点集为割点集合
//一个图的点连通度的定义为, 最小割点集合中的顶点数
//类似的, 如果有一个边集合, 删除这个边集合以后, 原图变成多个连通块, 就称这个点集为割边集合
//一个图的边连通度的定义为, 最小割边集合中的边数
//[双连通图、割点与桥]
//如果一个无向连通图的点连通度大于1, 则称该图是点双连通的(point biconnected), 简称双连通或重连通
//一个图有割点, 当且仅当这个图的点连通度为1, 则割点集合的唯一元素被称为割点(cut point), 又叫关节点(articulation point)
//如果一个无向连通图的边连通度大于1, 则称该图是边双连通的(edge biconnected), 简称双连通或重连通
//一个图有桥, 当且仅当这个图的边连通度为1, 则割边集合的唯一元素被称为桥(bridge), 又叫关节边(articulation edge)
//可以看出, 点双连通与边双连通都可以简称为双连通, 它们之间是有着某种联系的, 下文中提到的双连通, 均既可指点双连通, 又可指边双连通
//[双连通分量]
//在图G的所有子图G'中, 如果G'是双连通的, 则称G'为双连通子图
//如果一个双连通子图G'它不是任何一个双连通子图的真子集, 则G'为极大双连通子图
//双连通分量(biconnected component), 或重连通分量, 就是图的极大双连通子图。特殊的, 点双连通分量又叫做块
//[求割点与桥]
//对图深度优先搜索, 定义DFS(u)为u在搜索树(以下简称为树)中被遍历到的次序号
//定义Low(u)为u或u的子树中能通过非父子边追溯到的最早的节点, 即DFS序号最小的节点
//根据定义, 则有: Low(u) = Min {DFS(u) DFS(v) (u,v)为后向边(返祖边) 等价于DFS(v) < DFS(u)且v不为u的父亲节点Low(v) (u,v)为树枝边(父子边)}
//一个顶点u是割点, 当且仅当满足(1)或(2)
//(1)u为树根, 且u有多于一个子树
//(2)u不为树根, 且满足存在(u,v)为树枝边(或称父子边, 即u为v在搜索树中的父亲), 使得DFS(u)<=Low(v)
//一条无向边(u,v)是桥, 当且仅当(u,v)为树枝边, 且满足DFS(u)<Low(v)
//[求双连通分量]
//对于点双连通分量, 实际上在求割点的过程中就能顺便把每个点双连通分量求出
//建立一个栈, 存储当前双连通分量, 在搜索图时, 每找到一条树枝边或后向边(非横叉边), 就把这条边加入栈中
//如果遇到某时满足DFS(u)<=Low(v), 说明u是一个割点, 同时把边从栈顶一个个取出,
//直到遇到了边(u,v), 取出的这些边与其关联的点, 组成一个点双连通分量
//割点可以属于多个点双连通分量, 其余点和每条边只属于且属于一个点双连通分量
//对于边双连通分量, 只需在求出所有的桥以后, 把桥边删除, 原图变成了多个连通块, 则每个连通块就是一个边双连通分量
//桥不属于任何一个边双连通分量, 其余的边和每个顶点都属于且只属于一个边双连通分量
//[构造双连通图]
//方法为首先求出所有的桥, 然后删除这些桥边, 剩下的每个连通块都是一个双连通子图
//把每个双连通子图收缩为一个顶点, 再把桥边加回来, 最后的这个图一定是一棵树, 边连通度为1
//统计出树中度为1的节点的个数, 即为叶节点的个数, 记为leaf
//则至少在树上添加(leaf + 1) / 2条边, 就能使树达到边二连通, 所以至少添加的边数就是(leaf + 1) / 2
//具体方法为, 首先把两个最近公共祖先最远的两个叶节点之间连接一条边, 这样可以把这两个点到祖先的路径上所有点收缩到一起,
//因为一个形成的环一定是双连通的。然后再找两个最近公共祖先最远的两个叶节点, 这样一对一对找完, 恰好是(leaf + 1) / 2次, 把所有点收缩到了一起

//有向图的强连通分量
//Kosaraju算法 O(V + E)
vector<int> e[N], re[N], pos;
bool vis[N];
int belong[N], num[N], scc, cnt; //所属分量, 分量点数, 分量个数
void dfs(int u) {
  vis[u] = true;
  for (int i = 0; i < (int)e[u].size(); i++) {
    if (!vis[e[u][i]]) { dfs(e[u][i]); }
  }
  pos.push_back(u);
}
void rdfs(int u, int k) {
  vis[u] = true; belong[u] = k; cnt++;
  for (int i = 0; i < (int)re[u].size(); i++) {
    if (!vis[re[u][i]]) { rdfs(re[u][i], k); }
  }
}
void SCC(int n) {
  memset(vis, 0, sizeof(vis)); pos.clear();
  for (int i = 0; i < n; i++) { if (!vis[i]) { dfs(i); } }
  memset(vis, 0, sizeof(vis)); memset(num, 0, sizeof(num)); scc = 0;
  for (int i = (int)pos.size() - 1; i >= 0; i--) {
    if (!vis[pos[i]]) { cnt = 0; rdfs(pos[i], ++scc); num[scc] = cnt; }
  }
}
//Tarjan算法 O(V + E)
vector<int> e[N];
int low[N], dfn[N], index, belong[N], num[N], scc; //所属分量, 分量点数, 分量个数
stack<int> stk;
bool instack[N];
void Tarjan(int u) {
  int v; low[u] = dfn[u] = ++index; stk.push(u); instack[u] = true;
  for (int i = 0; i < (int)e[u].size(); i++) {
    int v = e[u][i];
    if (!dfn[v]) { Tarjan(v); low[u] = min(low[u], low[v]); }
    else if (instack[v] && low[u] > dfn[v]) { low[u] = dfn[v]; }
  }
  if (low[u] == dfn[u]) {
    scc++;
    do {
      v = stk.top(); stk.pop();
      instack[v] = false; belong[v] = scc; num[scc]++;
    } while (v != u);
  }
}
void SCC(int n) {
  memset(dfn, 0, sizeof(dfn)); memset(num, 0, sizeof(num));
  memset(instack, 0, sizeof(instack)); index = scc = 0;
  while (!stk.empty()) { stk.pop(); }
  for (int i = 0; i < n; i++) { if (!dfn[i]) { Tarjan(i); } }
}
//无向图的割点和桥
//Tarjan算法 O(V + E)
int low[N], dfn[N], index, addblock[N], bridge;
bool instack[N], cut[N], ecut[M];
stack<int> stk;
void Tarjan(int u, int p) {
  int son = 0; low[u] = dfn[u] = ++index;
  stk.push(u); instack[u] = true;
  for (int i = head[u]; ~i; i = nxt[i]) {
    int v = to[i];
    if (v == p) { continue; }
    if (!dfn[v]) {
      Tarjan(v, u); son++;
      low[u] = min(low[u], low[v]);
      if (u != p && low[v] >= dfn[u]) { //割点
        cut[u] = true; addblock[u]++;
      }
      if (low[v] > dfn[u]) { //割边
        bridge++; ecut[i] = ecut[i ^ 1] = true;
      }
    } else if (low[u] > dfn[v]) { low[u] = dfn[v]; }
  }
  if (u == p && son > 1) { cut[u] = true; }
  if (u == p) { addblock[u] = son - 1; }
  instack[u] = false; stk.pop();
}
void CUT(int n) {
  memset(dfn, 0, sizeof(dfn)); memset(addblock, 0, sizeof(addblock));
  memset(instack, 0, sizeof(instack)); memset(cut, 0, sizeof(cut)); memset(ecut, 0, sizeof(ecut));
  while (!stk.empty()) { stk.pop(); } index = bridge = 0;
  for (int i = 0; i < n; i++) { if (!dfn[i]) { Tarjan(i, i); } }
}
//无向图的边双连通分量
//求出所有的桥以后, 把桥边删除, 原图变成了多个连通块, 则每个连通块就是一个边双连通分量
//桥不属于任何一个边双连通分量, 其余的边和每个顶点都属于且只属于一个边双连通分量
//Tarjan算法 O(V + E)
int low[N], dfn[N], index, belong[N], bridge, block;
bool instack[N], ecut[M];
stack<int> stk;
void Tarjan(int u, int p) {
  low[u] = dfn[u] = ++index; stk.push(u); instack[u] = true;
  for (int i = head[u]; ~i; i = nxt[i]) {
    int v = to[i];
    if (v == p) { continue; }
    if (!dfn[v]) {
      Tarjan(v, u);
      low[u] = min(low[u], low[v]);
      if (low[v] > dfn[u]) { //割边
        bridge++; ecut[i] = ecut[i ^ 1] = true;
      }
    } else if (low[u] > dfn[v]) { low[u] = dfn[v]; }
  }
  if (low[u] == dfn[u]) {
    int v; block++;
    do {
      v = stk.top(); stk.pop(); instack[v] = false; belong[v] = block;
    } while (u != v);
  }
}
void EBCC(int n) {
  memset(dfn, 0, sizeof(dfn)); memset(instack, 0, sizeof(instack)); memset(cut, 0, sizeof(cut));
  while (!stk.empty()) { stk.pop(); } index = bridge = block = 0;
  for (int i = 0; i < n; i++) { if (!dfn[i]) { Tarjan(i, -1); } }
}
//无向图的点双连通分量
//对于点双连通分量, 实际上在求割点的过程中就能顺便把每个点双连通分量求出
//建立一个栈, 存储当前双连通分量, 在搜索图时, 每找到一条树枝边或后向边(非横叉边), 就把这条边加入栈中
//如果遇到某时满足DFS(u)<=Low(v), 说明u是一个割点, 同时把边从栈顶一个个取出,
//直到遇到了边(u,v), 取出的这些边与其关联的点, 组成一个点双连通分量
//割点可以属于多个点双连通分量, 其余点和每条边只属于且属于一个点双连通分量
//Tarjan算法 O(V + E)
int low[N], dfn[N], index, belong[N], block; //所属分量, 分量点数, 分量个数
stack<int> stk;
bool instack[N];
void Tarjan(int u, int p) {
  low[u] = dfn[u] = ++index;
  stk.push(u); instack[u] = true;
  for (int i = head[u]; ~i; i = nxt[i]) {
    int v = to[i];
    if (v == p) { continue; }
    if (!dfn[v]) {
      Tarjan(v, u);
      low[u] = min(low[u], low[v]);
      if (low[v] >= dfn[u]) { //u为割点
        int vv; block++;
        do {
          vv = stk.top(); stk.pop(); instack[vv] = false;
          belong[vv] = block;
        } while (vv != v);
      }
    } else if (instack[v] && low[u] > dfn[v]) { low[u] = dfn[v]; }
  }
}
void BCC(int n) {
  memset(dfn, 0, sizeof(dfn)); memset(instack, 0, sizeof(instack));
  while (!stk.empty()) { stk.pop(); } index = block = 0;
  for (int i = 0; i < n; i++) { if (!dfn[i]) { Tarjan(i, -1); } }
}
//构造双连通图
//方法为首先求出所有的桥, 然后删除这些桥边, 剩下的每个连通块都是一个双连通子图
//把每个双连通子图收缩为一个顶点, 再把桥边加回来, 最后的这个图一定是一棵树, 边连通度为1
//统计出树中度为1的节点的个数, 即为叶节点的个数, 记为leaf
//则至少在树上添加(leaf + 1) / 2条边, 就能使树达到边二连通, 所以至少添加的边数就是(leaf + 1) / 2
//具体方法为, 首先把两个最近公共祖先最远的两个叶节点之间连接一条边, 这样可以把这两个点到祖先的路径上所有点收缩到一起,
//因为一个形成的环一定是双连通的。然后再找两个最近公共祖先最远的两个叶节点, 这样一对一对找完, 恰好是(leaf + 1) / 2次, 把所有点收缩到了一起
