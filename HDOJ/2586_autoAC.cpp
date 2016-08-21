#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N = 40001;
struct Edge {
    int v, w, next;
}edge[2 * N];
int n, m, size, head[N];
int x[N], y[N], z[N], root[N], dis[N];
bool mark[N];
void Insert(int u, int v, int w) {
    edge[size].v = v; edge[size].w = w;
    edge[size].next = head[u]; head[u] = size++ ;
    edge[size].v = u; edge[size].w = w;
    edge[size].next = head[v]; head[v] = size++ ;
}
int Find(int x){
    if(root[x] != x) {
        return root[x] = Find(root[x]);
    }
    return root[x];
}
void LCA_Tarjan(int k) {
    mark[k] = true;
    root[k] = k;
    for(int i = 1; i <= m; i++ ) {
        if(x[i] == k && mark[y[i]])z[i] =Find(y[i]);
        if(y[i] == k && mark[x[i]]) z[i] =Find(x[i]);
    }
    for(int i = head[k]; i != -1; i = edge[i].next) {
        if(!mark[edge[i].v]) {
            dis[edge[i].v] = dis[k] + edge[i].w;
            LCA_Tarjan(edge[i].v);
            root[edge[i].v] = k;
        }
    }
}
int main() {
    int cas, u, v, w, i;
    scanf("%d", &cas);
    while(cas--) {
        scanf("%d %d", &n, &m);
        size = 0;
        memset(head, -1, sizeof(head));
        for(i = 1; i < n; i++ ) {
            scanf("%d %d %d", &u, &v, &w);
            Insert(u, v, w);
        }
        for(i = 1; i <= n; i++ ) {
            x[i] = y[i] = z[i] = 0;
        }
        for(i = 1; i <= m; i++ ) {
            scanf("%d %d", &u, &v);
            x[i] = u; y[i] = v;
        }
        memset(mark, false, sizeof(mark));
        dis[1] = 0;
        LCA_Tarjan(1);
        for(i = 1; i <= m; i++ ) {
            printf("%d\n", dis[x[i]] + dis[y[i]] - 2 * dis[z[i]]);
        }
    }
    return 0;
}
