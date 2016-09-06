#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<bitset>
using namespace std;
#define N 210
#define inf 50000000
int dir[8][2] = { { 0, 1 }, { 1, 1 }, { 1, 0 }, { 1, -1 }, { 0, -1 },
        { -1, -1 }, { -1, 0 }, { -1, 1 } };
int T = 1, n, m, idx, tot;
int maz[N][N], done[N * N], ans[N * N];
char Map[N][N];
struct position {
    int x, y;
} u, v, qu[N * N];
void bfs(int x, int y) {
    maz[x][y] = idx;
    Map[x][y] = '0';
    u.x = x;
    u.y = y;
    int l = 0, r = 1;
    qu[0] = u;
    while (l < r) {
        u = qu[l++];
        for (int i = 0; i < 8; i++) {
            v.x = u.x + dir[i][0];
            v.y = u.y + dir[i][1];
            if (v.x >= 1 && v.x <= n && v.y >= 1 && v.y <= m
                    && Map[v.x][v.y] == '1') {
                maz[v.x][v.y] = idx;
                Map[v.x][v.y] = '0';
                qu[r++] = v;
            }
        }
    }
    if (r < 5)
        done[idx] = 1;
}
void solve(int x, int y) {
    u.x = x;
    u.y = y;
    int i = 1, to = 6;
    qu[0] = u;
    for (;;) {
        int flag = 0;
        for (int j = to; j != to || !flag; j = (j + 1) % 8) {
            if (j == to)
                flag = 1;
            v.x = u.x + dir[j][0];
            v.y = u.y + dir[j][1];
            if (v.x >= 1 && v.x <= n && v.y >= 1 && v.y <= m
                    && maz[v.x][v.y] == maz[x][y]) {
                u.x = u.x + dir[(j + 7) % 8][0];
                u.y = u.y + dir[(j + 7) % 8][1];
                for (j = 0; j < 8; j++) {
                    if (v.x + dir[j][0] == u.x && v.y + dir[j][1] == u.y) {
                        to = j;
                        break;
                    }
                }
                qu[i++] = v;
                u = v;
                if (i >= 4 && qu[0].x == qu[i - 2].x && qu[0].y == qu[i - 2].y
                        && qu[1].x == qu[i - 1].x && qu[1].y == qu[i - 1].y) {
                    ans[tot++] = i - 2;
                    return;
                }
                break;
            }
        }
    }
}
int main() {
    while (~scanf("%d%d", &n, &m)) {
        if (!n && !m)
            break;
        for (int i = 1; i <= n; i++)
            scanf("%s", Map[i] + 1);
        idx = 0;
        memset(maz, 0, sizeof(maz));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (Map[i][j] == '1') {
                    idx++;
                    done[idx] = 0;
                    bfs(i, j);
                }
            }
        }
        tot = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (maz[i][j] && !done[maz[i][j]]) {
                    done[maz[i][j]] = 1;
                    solve(i, j);
                }
            }
        }
        printf("Case %d\n", T++);
        if (tot) {
            sort(ans, ans + tot);
            for (int i = 0; i < tot; i++)
                printf("%d%s", ans[i], (i == tot - 1) ? "\n" : " ");
        } else
            printf("no objects found\n");
    }
    return 0;
}
