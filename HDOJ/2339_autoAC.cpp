#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 505;
int G[maxn][maxn];
int vis[maxn][maxn];
int n, m, d;
const int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
struct Node {
    int x, y, v;
}node[maxn * maxn], q[maxn * maxn];
int cmp (const Node &a, const Node &b) {
    return a.v > b.v;
}
int BFS (int k) {
    int front , rear;
    int cnt = 1;
    front = 0;
    rear = 1;
    q[front] = node[k];
    vis[node[k].x][node[k].y] = node[k].v;
    bool flag = 1;
    while (front < rear) {
        for (int i = 0; i < 4; i++) {
            int newx = q[front].x + dir[i][0];
            int newy = q[front].y + dir[i][1];
            if (newx < 0 || newx >= n || newy < 0 || newy >= m)    
                continue;
            if (G[newx][newy] > node[k].v) {
                flag = 0;
                continue;
            }
            if (vis[newx][newy] == node[k].v || node[k].v - G[newx][newy] >= d)
                continue;
            vis[newx][newy] = node[k].v;
            if (G[newx][newy] == node[k].v)
                cnt++;
            else 
                G[newx][newy] = node[k].v;
            q[rear].x = newx;
            q[rear++].y = newy;    
        }
        front++;
    }
    if (flag)
        return cnt;
    return 0;
}
int main () {
    int T;
    scanf ("%d", &T);
    while (T--) {
        scanf ("%d%d%d", &n, &m, &d);
        int cnt = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                scanf ("%d", &G[i][j]);
                node[cnt].x = i;
                node[cnt].y = j;
                node[cnt++].v = G[i][j];
            }
        sort (node, node + cnt, cmp);
        memset (vis, -1, sizeof (vis));    
        int ans = 0;
        for (int i = 0; i < cnt; i++) {
            if (vis[node[i].x][node[i].y] == -1) {
                ans += BFS(i);
            }
        }
        printf ("%d\n", ans);
    }
    return 0;
}
