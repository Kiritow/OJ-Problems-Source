#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;
const int N = 1005;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
int n, p, a[N], f[N][N];
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &p);
        memset(f, 0, sizeof(f));
        f[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            a[i] %= p;
            a[i] = (a[i] + p) % p;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < p; j++) {
                f[i][j] = (f[i][j] + f[i - 1][j]) % MOD;
                f[i][(j + a[i]) % p] = (f[i][(j + a[i]) % p] + f[i - 1][j]) % MOD;
            }
        }
        printf("%d\n", f[n][0]);
    }
    return 0;
}
