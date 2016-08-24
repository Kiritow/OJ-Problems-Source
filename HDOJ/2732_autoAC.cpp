#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#define RE(x) ((x)^1)
#define CP(x) ((x)+500)
#define INF 0x3fffffff
using namespace std;
int N, M, MM, dis[1000], head[1000], idx;
const int source = 980, sink = 981;
char G[25][25], S[25][25];
struct Edge
{
    int v, cap, next;
}e[20000];
void init()
{
    idx = -1;
    memset(head, 0xff, sizeof (head));
}
inline int to(int x, int y)
{
    return x*M+y;
}
inline bool out(int x, int y)
{
    int u = x+1, d = N-x, l = y+1, r = M-y;
    int dist = min(u, min(d, min(l, r)));
    return dist <= MM;
}
inline bool judge(int x, int y)
{
    if (x < 0 || x >= N || y < 0 || y >= M) {
        return false;
    }
    else if (!G[x][y]) {
        return false;
    }
    return true;
}
void insert(int a, int b, int c)
{
    ++idx;
    e[idx].v = b, e[idx].cap = c;
    e[idx].next = head[a], head[a] = idx;
}
void build(int x, int y)
{
    int xx, yy;
    if (G[x][y]) {
        insert(to(x, y), CP(to(x,y)), G[x][y]);
        insert(CP(to(x, y)), to(x,y), G[x][y]);
        if (out(x, y)) {
            insert(CP(to(x, y)), sink, INF);
            insert(sink, CP(to(x, y)), 0);
        }
        else {
            for (int i = -MM; i <= MM; ++i) {
                for (int j = -(MM-abs(i)); j <= (MM-abs(i)); ++j) {
                    xx = x + i, yy = y + j;
                    if (judge(xx, yy) && !(x == xx && y == yy)) {
                        insert(CP(to(x, y)), to(xx, yy), G[x][y]);
                        insert(to(xx, yy), CP(to(x, y)), 0);
                    }
                }
            }
        }
    }
}
bool spfa(int u)
{
    queue<int>q;
    memset(dis, 0xff, sizeof (dis));
    dis[u] = 0;
    q.push(u);
    while (!q.empty()) {
        u = q.front();
        q.pop();
        for (int i = head[u]; i != -1; i = e[i].next) {
            if (dis[e[i].v] == -1 && e[i].cap > 0) {
                dis[e[i].v] = dis[u] + 1;
                q.push(e[i].v);
            }
        }
    }
    return dis[sink] != -1;
}
int dfs(int u, int flow)
{
    if (u == sink) {
        return flow;
    }
    int tf = 0, sf;
    for (int i = head[u]; i != -1; i = e[i].next) {
        if (dis[u]+1 == dis[e[i].v] && e[i].cap > 0 && (sf = dfs(e[i].v, min(flow-tf, e[i].cap)))) {
            e[i].cap -= sf, e[RE(i)].cap += sf;
            tf += sf;
            if (tf == flow) {
                return flow;
            }
        }
    }
    if (!tf) {
        dis[u] = -1;
    }
    return tf;
}
int dinic()
{
    int ans = 0;
    while (spfa(source)) {
        ans += dfs(source, INF);
    }
    return ans;
}
int main()
{
    int T, ca = 0, ans;
    scanf("%d", &T);
    while (T--) {
        init();
        ans = 0;
        scanf("%d %d", &N, &MM); 
        for (int i = 0; i < N; ++i) {
            scanf("%s", G[i]);
        }
        M = strlen(G[0]);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                G[i][j] -= '0';
                build(i, j);
            }
        }
        for (int i = 0; i < N; ++i) {
            scanf("%s", S[i]);
            for (int j = 0; j < M; ++j) {
                if (S[i][j] == 'L') {
                    ++ans;
                    insert(source, to(i, j), 1);
                    insert(to(i, j), source, 0);
                }
            }
        }
        ans -= dinic();
        printf("Case #%d: ", ++ca);
        if (!ans) {
            puts("no lizard was left behind.");
        }
        else if (ans == 1){
            printf("%d lizard was left behind.\n", ans);
        }
        else {
            printf("%d lizards were left behind.\n", ans);
        }
    }
    return 0;
}
