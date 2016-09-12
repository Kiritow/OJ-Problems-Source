#include <cstdio>  
#include <cstring>  
#include <cmath>  
#include <cstdlib>  
#include <queue>  
#include <algorithm>  
using namespace std;  
const int maxn = 55;  
const double eps = 1e-6;  
const double inf = 1e20;  
const int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};  
int N, M, K, Sx, Sy, Ex, Ey;  
bool done[maxn][maxn][maxn];  
char G[maxn][maxn];  
double dp[maxn][maxn][maxn];  
struct State {  
    int x, y, k;  
    double d;  
    State(int x = 0, int y = 0, int k = 0, double d = 0): x(x), y(y), k(k), d(d) {}  
    bool operator < (const State& u) const { return d > u.d; }  
};  
void init () {  
    scanf("%d%d%d", &N, &M, &K);  
    for (int i = 1; i <= N; i++)  
        scanf("%s", G[i]+1);  
    scanf("%d%d%d%d", &Sx, &Sy, &Ex, &Ey);  
}  
bool Dijkstra () {  
    for (int i = 1; i <= N; i++)  
        for (int j = 1; j <= M; j++)  
            for (int k = 0; k <= K; k++) dp[i][j][k] = inf;  
    memset(done, false, sizeof(done));  
    dp[Sx][Sy][K] = 0;  
    priority_queue<State> Q;  
    Q.push(State(Sx, Sy, K, 0));  
    while (!Q.empty()) {  
        State u = Q.top();  
        Q.pop();  
        int x = u.x, y = u.y, k = u.k;  
        if (done[x][y][k]) continue;  
        done[x][y][k] = true;  
        for (int i = 0; i < 4; i++) {  
            int p = x + dir[i][0];  
            int q = y + dir[i][1];  
            int t = k - 1;  
            if (p <= 0 || p > N || q <= 0 || q > M || t <= 0 || G[p][q] == '#') continue;  
            double d = 1.0 * abs(G[x][y] - G[p][q]) / k;  
            if (dp[p][q][t] > dp[x][y][k] + d) {  
                dp[p][q][t] = dp[x][y][k] + d;  
                Q.push(State(p, q, t, dp[p][q][t]));  
            }  
        }  
    }  
    double ans = inf;  
    for (int i = 1; i <= K; i++)  
        ans = min(ans, dp[Ex][Ey][i]);  
    if (fabs(ans-inf) < eps) return false;  
    printf("%.2lf\n", ans);  
    return true;  
}  
int main () {  
    int cas;  
    scanf("%d", &cas);  
    while (cas--) {  
        init();  
        if (!Dijkstra()) printf("No Answer\n");  
    }  
    return 0;  
}
