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
#define N 300
#define inf 50000000
int T, S, n, m, tot, cas, ans;
int head[N * 2], f[N], g[N], Less[N], Lid[N], More[N], Mid[N], dis[N * 2], qu[N
        * 2];
struct edge {
    int v, w, next;
} ed[N * N * 100];
int cut(int x) {
    int i;
    for (i = 0; x; x -= (x & (-x)), i++)
        ;
    return i;
}
void add(int u, int v, int w) {
    ed[tot].v = v;
    ed[tot].w = w;
    ed[tot].next = head[u];
    head[u] = tot++;
    ed[tot].v = u;
    ed[tot].w = 0;
    ed[tot].next = head[v];
    head[v] = tot++;
}
bool bfs() {
    int l, r, u, v, i;
    memset(dis, -1, sizeof(dis));
    dis[S] = 0;
    qu[0] = S;
    l = 0;
    r = 1;
    while (l < r) {
        u = qu[l++];
        for (i = head[u]; ~i; i = ed[i].next) {
            v = ed[i].v;
            if (dis[v] < 0 && ed[i].w > 0) {
                dis[v] = dis[u] + 1;
                if (v == T)
                    return true;
                qu[r++] = v;
            }
        }
    }
    return false;
}
int dfs(int u, int nowflow) {
    if (u == T)
        return nowflow;
    int i, v, tmp, res = 0;
    for (i = head[u]; ~i; i = ed[i].next) {
        v = ed[i].v;
        if (dis[v] == dis[u] + 1 && ed[i].w > 0) {
            tmp = dfs(v, min(nowflow, ed[i].w));
            nowflow -= tmp;
            ed[i].w -= tmp;
            ed[i ^ 1].w += tmp;
            res += tmp;
            if (!nowflow)
                break;
        }
    }
    if (!nowflow)
        dis[u] = -1;
    return res;
}
int main() {
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d%d", &n, &m);
        n = 1 << n;
        m = 1 << m;
        tot = 0;
        memset(head, -1, sizeof(head));
        ans = 0;
        memset(Less, -1, sizeof(Less));
        memset(More, -1, sizeof(More));
        S = 0;
        T = n * 2 + 1;
        for (int i = 0; i < n; i++)
            scanf("%d", &f[i]);
        for (int i = 0; i < n; i++)
            scanf("%d", &g[i]);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int k;
                scanf("%d", &k);
                k += 1024;
                if (j < f[i]) {
                    if (Less[i] < k) {
                        Less[i] = k;
                        Lid[i] = j;
                    }
                } else {
                    if (More[i] < k) {
                        More[i] = k;
                        Mid[i] = j;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            int aa = cut(i);
            if (aa & 1) {
                add(S, i + 1, Less[i]);
                add(i + 1 + n, T, More[i]);
            } else {
                add(S, i + 1, More[i]);
                add(i + 1 + n, T, Less[i]);
            }
            add(i + 1, i + 1 + n, inf);
            for (int j = i + 1; j < n; j++) {
                if (cut(i ^ j) == 1) {
                    if (aa & 1)
                        add(i + 1, j + 1 + n, g[i] ^ g[j]);
                    else
                        add(j + 1, i + 1 + n, g[i] ^ g[j]);
                }
            }
        }
        while (bfs())
            ans += dfs(S, inf);
        for (int i = 0; i < n; i++) {
            if (i)
                printf(" ");
            int aa = cut(i);
            if (aa & 1) {
                if (dis[i + 1] != -1)
                    printf("%d", Lid[i]);
                else
                    printf("%d", Mid[i]);
            } else {
                if (dis[i + 1] != -1)
                    printf("%d", Mid[i]);
                else
                    printf("%d", Lid[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
