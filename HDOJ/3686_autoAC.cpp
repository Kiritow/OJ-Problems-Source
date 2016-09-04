#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define pb push_back
const int maxn = 10000 + 10;    
const int maxm = 100000 + 10;   
struct Edge {
    int u, to, next, vis, id;
}edge[maxm<<1];
int head[maxn<<1], dfn[maxn<<1], low[maxn], st[maxm], iscut[maxn], subnet[maxn], bian[maxm];
int E, time, top, btot;
vector<int> belo[maxn]; 
void newedge(int u, int to) {
    edge[E].u = u;
    edge[E].to = to;
    edge[E].next = head[u];
    edge[E].vis = 0;
    head[u] = E++;
}
void init(int n) {
    for(int i = 0;i <= n; i++) {
        head[i] = -1;
        dfn[i] = iscut[i] = subnet[i] = 0;
        belo[i].clear();
    }
    E = time = top = btot = 0;
}
void dfs(int u) {
    dfn[u] = low[u] = ++time;
    for(int i = head[u];i != -1;i = edge[i].next) {
        if(edge[i].vis) continue;
        edge[i].vis = edge[i^1].vis = 1;
        int to = edge[i].to;
        st[++top] = i;
        if(!dfn[to]) {
            dfs(to);
            low[u] = min(low[u], low[to]);
            if(low[to] >= dfn[u]) {
                subnet[u]++;
                iscut[u] = 1;
                btot++;
                do {
                    int now = st[top--];
                    belo[edge[now].u].pb(btot);
                    belo[edge[now].to].pb(btot);
                    bian[edge[now].id] = btot;  
                    to = edge[now].u;
                }while(to != u);
            }
        }
        else
            low[u] = min(low[u], low[to]);
    }
}
int B[maxn<<2], F[maxn<<2], d[maxn<<2][20], pos[maxn<<2], tot, dep[maxn<<1];
bool treecut[maxn<<1];  
void RMQ_init(int n) {
    for(int i = 1;i <= n; i++)  d[i][0] = B[i];
    for(int j = 1;(1<<j) <= n; j++)
        for(int i = 1;i + j - 1 <= n; i++)
            d[i][j] = min(d[i][j-1], d[i + (1<<(j-1))][j-1]);
}
int RMQ(int L, int R) {
    int k = 0;
    while((1<<(k+1)) <= R-L+1)  k++;
    return min(d[L][k], d[R-(1<<k)+1][k] );
}
int lca(int a, int b) {
    if(pos[a] > pos[b])   swap(a, b);
    int ans = RMQ(pos[a], pos[b]);
    return F[ans];
}
void DFS(int u) {
    dfn[u] = ++time;
    B[++tot] = dfn[u];
    F[time] = u;
    pos[u] = tot;
    for(int i = head[u];i != -1;i = edge[i].next){
        int to = edge[i].to;
        if(!dfn[to]) {
            if(treecut[u])
                dep[to] = dep[u] + 1;
            else
                dep[to] = dep[u];
            DFS(to);
            B[++tot] = dfn[u];
        }
    }
}
void solve(int n) {
    for(int i = 0;i <= n; i++)  {
        dfn[i] = 0;
    }
    time = tot = 0;
    for(int i = 1;i <= n; i++) if(!dfn[i]) {
        dep[i] = 0;
        DFS(i);
    }
    RMQ_init(tot);
    int m, u, to;
    scanf("%d", &m);
    while(m--) {
        scanf("%d%d", &u, &to);
        u = bian[u]; to = bian[to];
        if(u < 0 || to < 0) {
            printf("0\n"); continue;
        }
        int LCA = lca(u, to);
        if(u == LCA)
            printf("%d\n", dep[to] - dep[u] - treecut[u]);
        else if(to == LCA)
            printf("%d\n", dep[u] - dep[to] - treecut[to]);
        else
            printf("%d\n", dep[u] + dep[to] - 2*dep[LCA] - treecut[LCA]);
    }
}
int main() {
    int n, m, u, to;
    while(scanf("%d%d", &n, &m) != -1 && n){
        init(n);
        for(int i = 1;i <= m; i++) {
            scanf("%d%d", &u, &to);
            edge[E].id = i;
            newedge(u, to);
            edge[E].id = i;
            newedge(to, u);
        }
        for(int i = 1;i <= n;i ++) if(!dfn[i]) {
            dfs(i);
            subnet[i]--;
            if(subnet[i] <= 0)  iscut[i] = 0;
        }
        int ditot = btot; 
        for(int i = 1;i <= btot; i++) treecut[i] = 0;
        for(int i = 1;i <= btot+n; i++)  head[i] = -1;
        E = 0;
        for(int i = 1;i <= n; i++) if(iscut[i]) {
            sort(belo[i].begin(), belo[i].end());
            ditot++;
            treecut[ditot] = 1;
            newedge(belo[i][0], ditot);
            newedge(ditot, belo[i][0]);
            for(int j = 1;j < belo[i].size(); j++) if(belo[i][j] != belo[i][j-1]) {
                newedge(belo[i][j], ditot);
                newedge(ditot, belo[i][j]);
            }
        }
        solve(ditot);
    }
    return 0;
}
