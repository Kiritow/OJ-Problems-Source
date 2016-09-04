#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define N 201
using namespace std;
char Map[N][N];
int f[2][N][N], n, m;
void init(int x, int y) {
    for (int i = 0; i < n; ++i) {
        scanf("%s", Map[i]);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            f[0][i][j] = -1;
        }
    }
    f[0][x - 1][y - 1] = 0;
}
struct Queue {
    int id[N], w[N], left, right;
    void init() {
        left = right = 0;
    }
    bool empty() {
        return left == right;
    }
    void insert(int pos, int v, int len) {
        if (left < right && abs(id[left] - pos) > len) {
            ++left;
        }
        if (v == -1) {
            return;
        }
        while (left < right) {
            int p = right - 1;
            if (w[p] + abs(id[p] - pos) > v) {
                break;
            }
            --right;
        }
        id[right] = pos, w[right] = v;
        ++right;
    }
    int left_id() {
        return id[left];
    }
} que;
void DP(int k, int len, int d) {
    switch (d) {
        case 1:
            for (int j = 0; j < m; ++j) {
                que.init();
                for (int i = n - 1; i >= 0; --i) {
                    que.insert(i, f[1 - k][i][j], len);
                    if (Map[i][j] == 'x') {
                        que.init();
                    }
                    if (que.empty()) {
                        f[k][i][j] = -1;
                    } else {
                        f[k][i][j] = f[1 - k][que.left_id()][j] + que.left_id() - i;
                    }
                }
            }
            break;
        case 3:
            for (int j = 0; j < m; ++j) {
                que.init();
                for (int i = 0; i < n; ++i) {
                    que.insert(i, f[1 - k][i][j], len);
                    if (Map[i][j] == 'x') {
                        que.init();
                    }
                    if (que.empty()) {
                        f[k][i][j] = -1;
                    } else {
                        f[k][i][j] = f[1 - k][que.left_id()][j] + i - que.left_id();
                    }
                }
            }
            break;
        case 2:
            for (int i = 0; i < n; ++i) {
                que.init();
                for (int j = m - 1; j >= 0; --j) {
                    que.insert(j, f[1 - k][i][j], len);
                    if (Map[i][j] == 'x') {
                        que.init();
                    }
                    if (que.empty()) {
                        f[k][i][j] = -1;
                    } else {
                        f[k][i][j] = f[1 - k][i][que.left_id()] + que.left_id() - j;
                    }
                }
            }
            break;
        case 4:
            for (int i = 0; i < n; ++i) {
                que.init();
                for (int j = 0; j < m; ++j) {
                    que.insert(j, f[1 - k][i][j], len);
                    if (Map[i][j] == 'x') {
                        que.init();
                    }
                    if (que.empty()) {
                        f[k][i][j] = -1;
                    } else {
                        f[k][i][j] = f[1 - k][i][que.left_id()] + j - que.left_id();
                    }
                }
            }
            break;
    }
}
int main(int argc, char** argv) {
    int x, y, tot, T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d%d%d", &n, &m, &x, &y, &tot);
        init(x, y);
        for (int i = 1; i <= tot; ++i) {
            int len, d;
            scanf("%d%d", &len, &d);
            DP(i % 2, len, d);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ans = (ans < f[tot % 2][i][j] ? f[tot % 2][i][j] : ans);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
