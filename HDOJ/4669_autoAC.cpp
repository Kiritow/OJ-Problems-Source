#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <algorithm>
#define lson step << 1
#define rson step << 1 | 1
#pragma comment(linker,"/STACK:102400000,102400000")
using namespace std;
typedef long long LL;
const int N = 50005;
const int M = 205;
int n , k , a[N] ,l[N];
int dp[2][M] , prefix[N] , fac[N << 2] , suffix[N];
int cnt[M];
int cal (int x) {
    int cnt = 0;
    while (x) x /= 10 , cnt ++;
    return cnt;
}
int main () {
    while (scanf ("%d %d" , &n , &k) != EOF) {
        fac[0] = 1;
        for (int i = 1 ; i <= (n << 2) ; i ++)
            fac[i] = fac[i - 1] * 10 % k;
        for (int i = 1 ; i <= n ; i ++) {
            scanf ("%d" , &a[i]);
            l[i] = cal (a[i]);
        }
        for (int i = 0 ; i < 2 ; i ++) {
            for (int j = 0 ; j < k ; j ++)
                dp[i][j] = 0;
        }
        dp[1][a[1] % k] = 1;
        LL ans = dp[1][0];
        for (int i = 2 ; i <= n ; i ++) {
            for (int j = 0 ; j < k ; j ++)
                dp[i & 1][j] = 0;
            dp[i & 1][a[i] % k] ++;
            for (int j = 0 ; j < k ; j ++) {
                dp[i & 1][(j * fac[l[i]] + a[i]) %k] += dp[(i - 1) & 1][j];
            }
            ans += dp[i & 1][0];
        }
        prefix[0] = 0;suffix[n + 1] = 0;
        for (int i = 1 ; i <= n ; i ++) {
            prefix[i] = (prefix[i - 1] * fac[l[i]] + a[i]) % k;
        }
        int len = 0;
        for (int i = n ; i >= 1 ; i --) {
            suffix[i] = (a[i] * fac[len] + suffix[i + 1]) % k;
            len += l[i];
        }
        len = 0;
        for (int i = 0 ; i < k ; i ++)
            cnt[i] = 0;
        for (int i = 1 ; i <= n ; i ++) {
            cnt[suffix[i]] ++;
            len += l[i];
            int p = prefix[i];
            for (int j = 0 ; j < k ; j ++) {
                if ((j * fac[len] + p) % k) continue;
                ans += dp[n & 1][j] - cnt[j];
            }
        }
        printf ("%I64d\n" , ans);
    }
    return 0;    
}
