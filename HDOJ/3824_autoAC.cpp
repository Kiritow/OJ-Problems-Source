#include <cstdio>
#include <cstring>
using namespace std;
#define maxn 1000
#define max (1<<29)
typedef __int64 ll;
const ll inf = (1ll)<<50;
int t, n, m, s, a, i, j, u, v, w, now, tmp1, tmp2;
int dis[maxn][maxn];
ll best[maxn];
ll cost, k21, k22;
bool vis[maxn];
int head, tail;
int q[maxn*maxn];
bool flag;
int main() {
 scanf("%d", &t);
 for (int cases = 1; cases <= t; cases++) {
 scanf("%d %d %d %d", &n, &m, &s, &a);
 for (i = 0; i < n; i++)
 for (j = 0; j < n; j++)
 dis[i][j] = -1;
 for (i = 0; i < m; i++) {
 scanf("%d %d %d", &u, &v, &w);
 dis[u][v] = dis[v][u] = w;
 }
 head = 1; tail = 1; q[1] = a;
 for (i = 0; i < n; i++) best[i] = inf;
 for (i = 0; i < n; i++) vis[i] = false;
 best[a] = 0;vis[a] = true;
 while (head <= tail) {
 now = q[head];
 for (i = 0; i < n; i++)
 if ((dis[now][i] != -1) && (dis[now][i]*3 <= s)) {
 if ( best[now]+3*dis[now][i] <= s) {
 cost = best[now]+2*dis[now][i]; 
 flag = true;
 } else {
 tmp1 = s-3*dis[now][i]; 
 tmp2 = s-5*dis[now][i]; 
 if(tmp2 > 0){ 
 k21 = (best[now]-tmp1)/tmp2; 
 k22 = (best[now]-tmp1)%tmp2;
 cost = 1ll*(s-dis[now][i])*(1+k21)+1ll*(k22!=0)*(k22+4*dis[now][i]);
 flag = true;
 } else flag = false; 
 }
 if (flag && cost < best[i]){
 best[i] = cost;
 if (!vis[i]) {
 vis[i] = true;
 q[++tail] = i;
 }
 }
 }
 head++; vis[now] = false;
 }
 if (best[0] == inf) { printf("Case %d: Poor princess, we will miss you!\n", cases); } else {
 printf("Case %d: %I64d\n", cases, best[0]);
 }
 }
}
