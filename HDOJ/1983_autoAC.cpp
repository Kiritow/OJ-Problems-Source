#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;
typedef struct S {
    int order, time, J;
} STEP;
char map[100], s[10];
int m, n, start;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int vis[2][100];
int t;
int bfs() {
    int k, i, j, xx, yy, temp;
    STEP now, next;
    now.order = start;
    now.time = 0;
    now.J = 0;
    queue<STEP> q;
    memset(vis, 0, sizeof (vis));
    vis[0][start] = 1;
    q.push(now);
    while (!q.empty()) {
        now = q.front();
        q.pop();
        if (now.time >= t)
            continue;
        i = now.order / n;
        j = now.order % n;
        for (k = 0; k < 4; ++k) {
            xx = i + dx[k];
            yy = j + dy[k];
            temp = xx * n + yy;
            next.time = now.time + 1;
            if (xx >= 0 && xx < m && yy >= 0 && yy < n) {
                if (map[temp] == 'E') {
                    if (now.J)
                        return 0;
                }
                if (map[temp] != '#') {
                    if (map[temp] == 'J')
                        next.J = 1;
                    else
                        next.J = now.J;
                    if (!vis[now.J][temp]) {
                        vis[now.J][temp] = 1;
                        next.order = temp;
                        q.push(next);
                    }
                }
            }
        }
    }
    return 1;
}
int main() {
    int i, j, jd, T, ans;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &m, &n, &t);
        scanf("%*c");
        jd = 0;
        for (i = 0; i < m; ++i) {
            scanf("%s", s);
            for (j = 0; j < n; ++j) {
                map[jd + j] = s[j];
                if (s[j] == 'S')
                    start = jd + j;
            }
            jd += n;
        }
        int k;
        if (bfs()) {
            ans = 0;
            goto L;
        }
        char ch[3];
        for (i = 0; i < m * n; ++i) {
            if (map[i] == '#' || map[i] == 'S' || map[i] == 'E') {
                continue;
            }
            ch[0] = map[i];
            map[i] = '#';
            if (bfs()) {
                ans = 1;
                goto L;
            }
            map[i] = ch[0];
        }
        for (i = 0; i < m * n; ++i) {
            if (map[i] == '#' || map[i] == 'S' || map[i] == 'E') {
                continue;
            }
            ch[0] = map[i];
            map[i] = '#';
            for (j = i + 1; j < m * n; ++j) {
                if (map[j] == '#' || map[j] == 'S' || map[j] == 'E') {
                    continue;
                }
                ch[1] = map[j];
                map[j] = '#';
                if (bfs()) {
                    ans = 2;
                    goto L;
                }
                map[j] = ch[1];
            }
            map[i] = ch[0];
        }
        for (i = 0; i < m * n; ++i) {
            if (map[i] == '#' || map[i] == 'S' || map[i] == 'E') {
                continue;
            }
            ch[0] = map[i];
            map[i] = '#';
            for (j = i + 1; j < m * n; ++j) {
                if (map[j] == '#' || map[j] == 'S' || map[j] == 'E') {
                    continue;
                }
                ch[1] = map[j];
                map[j] = '#';
                for (k = j + 1; k < m * n; ++k) {
                    if (map[k] == '#' || map[k] == 'S' || map[k] == 'E') {
                        continue;
                    }
                    ch[2] = map[k];
                    map[k] = '#';
                    if (bfs()) {
                        ans = 3;
                        goto L;
                    }
                    map[k] = ch[2];
                }
                map[j] = ch[1];
            }
            map[i] = ch[0];
        }
        ans = 4;
L:
        printf("%d\n", ans);
    }
    return 0;
}
