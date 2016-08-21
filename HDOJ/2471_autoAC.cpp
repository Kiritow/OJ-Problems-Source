#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair <int, int> pt;
const int MAX_T = 26, MAX_N = 2000, SEED = 99991;
int n[2], t;
bool vis[MAX_N][MAX_N], can_use[MAX_N], cal[MAX_N];
queue <pt> q;
struct node_t {
    int son[MAX_T], end;
    int mask;
    int calc_mask() {
        mask = 0;
        for (int i = 0; i < t; i ++)
            if (son[i] >= 0) mask |= 1 << i;
        mask = mask << 1 | end;
        return mask;
    }
} dfa[2][MAX_N];
bool dfs(int k, int u) {
    if (cal[u]) return can_use[u];
    cal[u] = 1;
    if (dfa[k][u].end) can_use[u] = 1;
    for (int i = 0; i < t; i ++)
        if (dfa[k][u].son[i] >= 0 && dfs(k, dfa[k][u].son[i])) can_use[u] = 1;
    return can_use[u];
}
void dfs_again(int k, int u) {
    if (cal[u]) return;
    cal[u] = 1;
    for (int i = 0; i < t; i ++)
        if (dfa[k][u].son[i] >= 0) {
            if (can_use[dfa[k][u].son[i]]) dfs(k, dfa[k][u].son[i]);
            else dfa[k][u].son[i] = -1;
        }
}
void init(int k) {
    memset(can_use, 0, sizeof(can_use));
    memset(cal, 0, sizeof(cal));
    dfs(k, 0);
    memset(cal, 0, sizeof(cal));
    dfs_again(k, 0);
}
bool solve() {
    memset(vis, 0, sizeof(vis));
    while (q.size()) q.pop();
    q.push(make_pair(0, 0));
    vis[0][0] = 1;
    while (q.size()) {
        pt u = q.front();
        q.pop();
        if (dfa[0][u.first].mask != dfa[1][u.second].mask) return 0;
        for (int i = 0; i < t; i ++)
            if (dfa[0][u.first].son[i] >= 0) {
                pt v = make_pair(dfa[0][u.first].son[i], dfa[1][u.second].son[i]);
                if (!vis[v.first][v.second]) {
                    vis[v.first][v.second] = 1;
                    q.push(v);
                }
            }
    }
    return 1;
}
int main() {
    int cas = 0;
    while (scanf("%d", &t) != EOF && t) {
        for (int k = 0; k < 2; k ++) {
            scanf("%d", &n[k]);
            for (int i = 0; i < n[k]; i ++) {
                scanf("%d", &dfa[k][i].end);
                for (int j = 0; j < t; j ++) scanf("%d", &dfa[k][i].son[j]);
            }
            init(k);
            for (int i = 0; i < n[k]; i ++) dfa[k][i].calc_mask();
        }
        printf("Case #%d: ", ++ cas);
        if (solve()) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
