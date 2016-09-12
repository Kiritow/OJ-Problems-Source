#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
using namespace std;
typedef long long LL;
const int MOD = 1e9 + 7;
const int INF = 10000000;
const int N = 5000 + 10;
struct State {
    int a[4], b[4]; 
    void read() {
        for(int i = 0; i < 4; i++) {
            scanf("%d%d", &a[i], &b[i]);
        }
    }
} s[N];
int seq[30][4], dp[N][30];
bool check(int b[], int q[]) { 
    for(int i = 1; i < 4; i++) {
        if(b[q[i]] < b[q[i - 1]]) return false;
    }
    return true;
}
int calc(State& A, State& B, int q0[], int q1[]) {
    int dis = 0;
    for(int i = 0; i < 4; i++) {
        dis += abs(A.a[q0[i]] - B.a[q1[i]]);
        dis += abs(A.b[q0[i]] - B.b[q1[i]]);
    }
    return dis;
}
int main() {
    int T, C = 1, n;
    int A[4] = {0, 1, 2, 3};
    int nq = 0;
    do {
        for(int i = 0; i < 4; i++) seq[nq][i] = A[i];
        nq ++;
    } while(next_permutation(A, A + 4));
    scanf("%d", &T);
    while(T--) {
        printf("Case #%d:\n", C++);
        scanf("%d" , &n);
        for(int i = 1; i <= n; i++) {
            s[i].read();
        }
        for(int i = 0; i < 4; i++)
            s[0].b[i] = i + 1, s[0].a[i] = 0;
        for(int i = 0; i < 24; i++) {
            if(check(s[1].b, seq[i])) {
                dp[1][i] = calc(s[0], s[1], seq[0], seq[i]);
            } else {
                dp[1][i] = INF;
            }
        }
        for(int i = 2; i <= n; i++) {
            for(int j = 0; j < 24; j++) {
                dp[i][j] = INF;
                if(!check(s[i].b, seq[j])) continue;
                for(int k = 0; k < 24; k++) {
                    if(dp[i - 1][k] == INF) continue;
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + calc(s[i - 1], s[i], seq[k], seq[j]));
                }
            }
        }
        int ans = INF;
        for(int i = 0; i < 24; i++) {
            ans = min(ans, dp[n][i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
