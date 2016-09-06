#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
int N, T, sx, sy;
char mp[105][105];
char vis[105][105][2];
struct Sta {
    int x, y, t;    
};
queue<Sta>q;
int dir[8][2]={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
inline bool judge(int x, int y) {
    if (x >= 0 && x < N && y >= 0 && y < N) return true;
    return false;
}
void cover(const Sta &cur) {
    Sta nxt;
    bool flag = false;
    for (int k = 0; k < 8; ++k) {
        nxt.x = cur.x + dir[k][0];
        nxt.y = cur.y + dir[k][1];
        nxt.t = cur.t + 1;
        if (judge(nxt.x, nxt.y) && mp[nxt.x][nxt.y] == '.') {
            flag = true;
            if (!vis[nxt.x][nxt.y][nxt.t&1]) {
                vis[nxt.x][nxt.y][nxt.t&1] = 1;
                if (nxt.t < T) {
                    q.push(nxt);
                }
            }
        }
    }
    if (!flag) {
        nxt = cur;
        ++nxt.t;
        if (!vis[nxt.x][nxt.y][nxt.t&1]) {
            vis[nxt.x][nxt.y][nxt.t&1] = 1;
            if (nxt.t < T) {
                q.push(nxt);
            }
        }
    }
}
void solve() {
    while (!q.empty()) q.pop();
    memset(vis, 0, sizeof (vis));
    Sta cur, nxt;
    nxt.x = sx, nxt.y = sy, nxt.t = 0;
    vis[sx][sy][0] = 1;
    q.push(nxt);
    while (!q.empty()) {
        cur = q.front(), q.pop();
        cover(cur);
    }
    int odd = 0, even = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (vis[i][j][0]) ++even;
            if (vis[i][j][1]) ++odd;
        }
    }
    if (T & 1) printf("%d\n", odd);
    else printf("%d\n", even);
}
int main() {
    int C;
    scanf("%d", &C);
    while (C--) {
        scanf("%d %d %d %d", &N, &T, &sx, &sy);
        sx--, sy--;
        for (int i = 0; i < N; ++i) {
            scanf("%s", mp[i]);
        }
        solve();
    }
    return 0;    
}
