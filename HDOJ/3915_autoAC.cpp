#include<cstdio>
#include<algorithm>
#define MAXN 110
#define MOD 1000007
using namespace std;
int a[MAXN], g[MAXN][MAXN];
int Gauss(int n) {
    int i, j, r, c, cnt;
    for (c = cnt = 0; c < n; c++) {
        for (r = cnt; r < 31; r++) {
            if (g[r][c])
                break;
        }
        if (r < 31) {
            if (r != cnt) {
                for (i = 0; i < n; i++)
                    swap(g[r][i], g[cnt][i]);
            }
            for (i = cnt + 1; i < 31; i++) {
                if (g[i][c]) {
                    for (j = 0; j < n; j++)
                        g[i][j] ^= g[cnt][j];
                }
            }
            cnt++;
        }
    }
    return n - cnt;
}
int main() {
    int c;
    int n, i, j;
    int ans, vary;
    scanf("%d", &c);
    while (c--) {
        scanf("%d", &n);
        for (i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for (i = 0; i < 31; i++) {
            for (j = 0; j < n; j++)
                g[i][j] = (a[j] >> i) & 1;
        }
        vary = Gauss(n);
        for (ans = 1; vary--;) {
            ans <<= 1;
            ans %= MOD;
        }
        printf("%d\n", ans);
    }
    return 0;
}
