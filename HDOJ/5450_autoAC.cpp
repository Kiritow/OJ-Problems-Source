#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 105;
const int maxm = 15;
const int maxs = 200000;
const int mod = 10007;
int N, P, dp[maxn][maxs];
bool exist[maxn];
int encode (int* c, int n) {
    int ret = 0;
    for (int i = 0; i < n; i++)
        ret = ret * 3 + c[i];
    return ret;
}
void decode(int* c, int n, int s) {
    for (int i = n-1; i >= 0; i--) {
        c[i] = s % 3;
        s /= 3;
    }
}
void move(int* c, int n) {
    for (int i = n; i > 0; i--)
        c[i] = c[i-1];
    c[0] = 0;
}
void init () {
    scanf("%d%d", &N, &P);
    memset(exist, false, sizeof(exist));
    int k, x;
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &x);
        exist[x] = true;
    }
}
void add(int& u, int v) { u = (u + v) % mod; }
int solve () {
    int n = P + 2, cur[maxm], nxt[maxm], idx[3];
    idx[0] = 1, idx[1] = P, idx[2] = P + 2;
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) cur[i] = 2;
    int e = encode(cur, n);
    dp[0][e] = 1;
    for (int i = 0; i < N; i++) {
        for (int s = 0; s <= e; s++) {
            if (dp[i][s] == 0) continue;
            decode(cur, n, s);
            memcpy(nxt, cur, sizeof(cur));
            move(nxt, n);
            if (exist[i+1]) {
                nxt[0] = 2;
                if (nxt[n] == 2) add(dp[i+1][encode(nxt, n)], dp[i][s]);
                continue;
            }
            if (nxt[n] == 2) add(dp[i+1][encode(nxt, n)], dp[i][s]);
            nxt[0] = 1;
            for (int j = 0; j < 3; j++) {
                int& v = nxt[idx[j]];
                if (v < 2) {
                    v++;
                    if (nxt[n] == 2) add(dp[i+1][encode(nxt, n)], dp[i][s]);
                    v--;
                }
            }
            nxt[0] = 2;
            for (int j = 0; j < 3; j++) {
                for (int k = j+1; k < 3; k++) {
                    int& u = nxt[idx[j]];
                    int& v = nxt[idx[k]];
                    if (u < 2 && v < 2) {
                        u++, v++;
                        if (nxt[n] == 2) add(dp[i+1][encode(nxt, n)], dp[i][s]);
                        u--, v--;
                    }
                }
            }
        }
    }
    return dp[N][e];
}
int main () {
    int cas;
    scanf("%d", &cas);
    for (int kcas = 1; kcas <= cas; kcas++) {
        init();
        printf("Case #%d: %d\n", kcas, solve());
    }
    return 0;
}
