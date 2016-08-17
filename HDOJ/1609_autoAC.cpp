#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 15;
const int M = 105;
int t, p, c, m, vis[M], have[M], hn, b[M], s[M], ans[N], num;
struct Mi {
    int num[N];
    int vis[M];
    int b, w;
} mi[M];
void init() {
    int i, j;
    memset(vis, 0, sizeof(vis));
    memset(b, 0, sizeof(b));
    memset(s, 0, sizeof(s));
    hn = 0;
    scanf("%d%d%d", &p, &c, &m);
    for (i = 0; i < m; i++) {
        memset(mi[i].vis, 0, sizeof(mi[i].vis));
        for (j = 0; j < p; j++) {
            scanf("%d", &mi[i].num[j]);
            mi[i].vis[mi[i].num[j]]++;
            if (!vis[mi[i].num[j]]) {
                vis[mi[i].num[j]] = 1;
                have[hn++] = mi[i].num[j];
            }
        }
        scanf("%d%d", &mi[i].b, &mi[i].w);
    }
    for (i = 1; i <= c; i++)
        if (!vis[i]) {
            have[hn++] = i;
            break;
        }
    sort(have, have + hn);
}
bool dfs(int d) {
    if (d == p) {
        for (int i = 0; i < m; i++) {
            if (b[i] != mi[i].b || s[i] - b[i] != mi[i].w)
                return false;
        }
        for (int j = 0; j < p - 1; j++)
            printf("%d ", ans[j]);
        printf("%d\n", ans[p - 1]);
        return true;
    }
    for (int i = 0; i < hn; i++) {
        int num = have[i], flag = 0, j, flag2[M];
        memset(flag2, 0, sizeof(flag2));
        for (j = 0; j < m; j++) {
            if (num == mi[j].num[d])
                b[j]++;
            if (mi[j].vis[num]) {
                s[j]++;
                mi[j].vis[num]--;
                flag2[j] = 1;
            }
            if (b[j] > mi[j].b || s[j] > mi[j].b + mi[j].w)
                flag = 1;
        }
        if (!flag) {
            ans[d] = num;
            if (dfs(d + 1)) return true;
        }
        for (j = 0; j < m; j++) {
            if (num == mi[j].num[d])
                b[j]--;
            if (flag2[j]) {
                s[j]--;
                mi[j].vis[num]++;
            }
        }
    }
    return false;
}
int main() {
    scanf("%d", &t);
    while (t--) {
        init();
        if (!dfs(0)) printf("You are cheating!\n");
    }
    return 0;
}
