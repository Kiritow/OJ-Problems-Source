#include <stdio.h>
#include <memory.h>
const int maxn = 100005;
struct Graph {
    int hed[maxn], nxt[maxn*2], pnt[maxn*2], val[maxn*2];
    int idx;
    void init(int n) {
        memset(hed + 1, -1, n * 4);
        idx = 0;
    }
    void addedge(int x, int y, int v) {
        pnt[idx] = y; val[idx] = v; nxt[idx] = hed[x]; hed[x] = idx++;
        pnt[idx] = x; val[idx] = v; nxt[idx] = hed[y]; hed[y] = idx++;
    }
} gra;
struct Node {
    int r, x, p;
} sta[maxn];
int teams[maxn], total;
__int64 cunt[maxn], cost[maxn];
void dfs_1() {
    int x, y, r, p, top = 0;
    sta[0].x = 1; sta[0].r = 0; sta[0].p = gra.hed[1];
    cunt[1] = teams[1];
    cost[1] = 0;
    while (true) {
        p = sta[top].p;
        if (p == -1) {
            top--;
            if (top >= 0) {
                p = sta[top].p;
                x = sta[top].x;
                y = gra.pnt[p];
                cunt[x] += cunt[y];
                cost[x] += cunt[y] * gra.val[p] + cost[y];
                sta[top].p = gra.nxt[p];
            } else {
                break;
            }
        } else {
            x = sta[top].x;
            r = sta[top].r;
            y = gra.pnt[p];
            if (y != r) {
                ++top;
                cunt[y] = teams[y];
                cost[y] = 0;
                sta[top].r = x;
                sta[top].x = y;
                sta[top].p = gra.hed[y];
            } else {
                sta[top].p = gra.nxt[p];
            }
        }
    }
}
void dfs_2() {
    int x, y, r, p, top = 0;
    sta[0].x = 1; sta[0].r = 0; sta[0].p = gra.hed[1];
    while (true) {
        p = sta[top].p;
        if (p == -1) {
            top--;
            if (top >= 0) {
                p = sta[top].p;
                sta[top].p = gra.nxt[p];
            } else {
                break;
            }
        } else {
            x = sta[top].x;
            r = sta[top].r;
            y = gra.pnt[p];
            if (y != r) {
                ++top;
                cost[y] = cost[x] + (total - 2 * cunt[y]) * gra.val[p];
                sta[top].r = x;
                sta[top].x = y;
                sta[top].p = gra.hed[y];
            } else {
                sta[top].p = gra.nxt[p];
            }
        }
    }
}
int main() {
    int n, x, y, v;
    while (scanf("%d", &n) != EOF) {     
        total = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", teams + i);
            total += teams[i];
        }
        gra.init(n);
        for (int i = 1; i < n; i++) {
            scanf("%d %d %d", &x, &y, &v);
            gra.addedge(x, y, v);
        }
        dfs_1();
        dfs_2();
        __int64 ans = cost[1];
        for (int i = 2; i <= n; i++) {
            if (cost[i] < ans)
                ans = cost[i];
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
