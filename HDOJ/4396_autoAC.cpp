#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <queue>
using namespace std;
typedef long long ll;
const int N = 5005;
const int M = 200005;
const int NN = 505;
const int Lum = 10;
const int INF = 0x3f3f3f3f;
int vis[N][NN], d[N][NN], en;
int head[M];
int n, m, s, t, k;
struct node {  
    int to, dis, next;  
}edge[M];  
void addEdge(int u,int v,int x) {  
    edge[en].to = v;  
    edge[en].next = head[u];  
    edge[en].dis = x;  
    head[u] = en++;  
    edge[en].to = u;  
    edge[en].next = head[v];  
    edge[en].dis = x;  
    head[v] = en++;  
}  
struct Node{
    int u, m;
};
void SPFA() {  
    queue<Node> Q;  
    for(int i = 1; i <= n; i++) {  
        for (int j = 0; j <= NN; j++) {
            d[i][j] = INF;  
            vis[i][j] = 0;  
        }
    }  
    d[s][0] = 0;  
    vis[s][0] = 1;  
    Q.push((Node){s, 0});  
    while(!Q.empty()) {  
        int u = Q.front().u;  
        int m = Q.front().m;
        vis[u][m] = 0;  
        Q.pop();  
        int temp = m + Lum;
        if (temp >= NN) continue;
        if (temp > k) temp = k;
        for(int i = head[u]; i != -1; i = edge[i].next) {  
            int v = edge[i].to;  
            if(d[u][m] + edge[i].dis < d[v][temp]) {  
                d[v][temp] = d[u][m] + edge[i].dis;  
                if(!vis[v][temp]) {  
                    Q.push((Node){v, temp});  
                    vis[v][temp] = 1;  
                }  
            }  
        }  
    }  
} 
void input() {
    int u, v, c;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &c);  
        addEdge(u, v, c);
    }   
    scanf("%d %d %d", &s, &t, &k);
}
int main() {
    while (scanf("%d %d", &n, &m) == 2) {
        en = 0;
        memset(head, -1, sizeof(head));
        input();    
        if (k % 10) {
            k = 10 * ((k / 10) + 1);
        }
        SPFA();
        if (d[t][k] == INF) {
            printf("-1\n"); 
        } else printf("%d\n", d[t][k]);
    }
    return 0;
}
