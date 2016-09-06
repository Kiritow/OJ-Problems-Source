#include<cstdio>
#include<cstring>
#define MAXN 1010
int sg[MAXN];
bool vis[MAXN];
int SG(int n) {
    if (n == 0) {
        sg[n] = 0;
    } else if (n == 1) {
        sg[n] = 0;
    } else if (n == 2) {
        sg[n] = 1;
    } else if (n == 3) {
        sg[n] = 1;
    } else if (sg[n] == -1) {
        int i;
        memset(vis, false, sizeof(vis));
        for (i = 0; i <= n - 2; i++) {
            vis[SG(i) ^ SG(n - i - 2)] = true;
        }
        for (i = 0;; i++) {
            if (!vis[i]) {
                break;
            }
        }
        sg[n] = i;
    }
    return sg[n];
}
void init() {
    int i;
    memset(sg, -1, sizeof(sg));
    for (i = 0; i < MAXN; i++) {
        sg[i] = SG(i);
    }
}
int getSG(int n) {
    if (n < MAXN) {
        return sg[n];
    } else {
        return sg[n % 34 + 2 * 34];
    }
}
int main() {
    int T;
    int n;
    int tmp;
    int res;
    init();
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        res = 0;
        while (n--) {
            scanf("%d", &tmp);
            res ^= getSG(tmp);
        }
        if (res) {
            puts("Carol");
        } else {
            puts("Dave");
        }
    }
    return 0;
}
