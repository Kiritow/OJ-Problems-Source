#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define clr(a, b) memset(a, b, sizeof(a))
#define SZ(a) ((int)a.size())
#define PB push_back
#define MP make_pair
#define inf 0x3f3f3f3f
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
#ifdef ecust
#define RR "%lld"
#else
#define RR "%I64d"
#endif
namespace acm {
int dp[2][220][10][220];
int T, HS, A, R, U, D, FI, P;
int des[300];
void update(int &a, int b) {
    a = max(a, b);
}
void solve() {
    scanf("%d%d%d%d", &T, &HS, &A, &R);
    scanf("%d%d%d%d", &U, &D, &FI, &P);
    forn(i, T)
        scanf("%d", des + i + 1);
    clr(dp, 0x3f);
    forn(i, 2)
        forn(j, 220)
            forn(k, 10)
                forn(l, 220)
                    dp[i][j][k][l] = -inf;
    int now = 0;
    dp[0][HS][0][0] = 0;
    for (int tt = 1; tt <= T; ++tt) {
        int fang = des[tt];
        for (int i = 1; i <= HS; ++i) {
            for (int j = 0; j <= 6; ++j) {
                for (int k = 0; k <= T; ++k) {
                    if (dp[now][i][j][k] == -inf)
                        continue;
                    if (i > D) {
                        int add = A + (HS - i) / R * U;
                        if (add < fang)
                            add = 0;
                        else
                            add -= fang;
                        update(dp[now ^ 1][i - D][6][k + 1], dp[now][i][j][k]
                                + add + FI * k);
                    }
                    int add = A + (HS - i) / R * U;
                    if (add < fang)
                        add = 0;
                    else
                        add -= fang;
                    if (j - 1 == 0)
                        update(dp[now ^ 1][i][j - 1][0], dp[now][i][j][k] + add
                                + FI * k);
                    else if (j)
                        update(dp[now ^ 1][i][j - 1][k], dp[now][i][j][k] + add
                                + FI * k);
                    else if (j == 0)
                        update(dp[now ^ 1][i][j][k], dp[now][i][j][k] + add);
                }
            }
        }
        now = now ^ 1;
    }
    int ans = -inf, ans2 = -inf;
    forn(j, 220)
        forn(k, 10)
            forn(l, 220) {
                if (dp[now ][j][k][l] != inf) {
                    update(ans, dp[now ][j][k][l] - (HS - j) * P);
                }
            }
    printf("%d\n", ans);
}
void icpc() {
    int nc, nn = 1;
    scanf("%d", &nc);
    while (nc--) {
        printf("Case #%d: ", nn++);
        solve();
    }
}
}
int main() {
    acm::icpc();
    return 0;
}
