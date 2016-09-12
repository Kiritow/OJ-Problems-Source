#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>
#include <queue>
#include <set>
#include <stack>
using namespace std;
const int maxn = 201315;
const int mod = 530600414;
typedef long long LL;
LL dp[maxn];     
LL dist[maxn];   
LL cnt[maxn];    
LL fibo[maxn];   
void init() {
    fibo[1] = 1, fibo[2] = 2;
    cnt[1] = 1, cnt[2] = 0;
    for (int  i = 3; i < maxn; i ++) {
        fibo[i] = (fibo[i-1] % mod + fibo[i-2] % mod) % mod;
        cnt[i] = (cnt[i-1] % mod + cnt[i-2] % mod) % mod;
    }
    dist[1] = dist[2] = 0, dist[3] = 2;
    for (int i = 4; i < maxn; i ++) {
        dist[i] = (dist[i-1] % mod + dist[i-2] % mod + (fibo[i-1] % mod * cnt[i-2] % mod) % mod) % mod;
    }
    dp[4] = dp[1] = dp[2] = dp[3] = 0;
    for (int i = 5; i < maxn; i ++) {
        dp[i] = (dp[i-2] % mod + dp[i-1] % mod
        + (cnt[i-1] % mod * dist[i-2] % mod) % mod
        + (cnt[i-2] % mod * ((fibo[i-1] % mod * cnt[i-1] % mod) % mod - dist[i-1] % mod) % mod) % mod) % mod;
    }
}
int main() {
    init();
    int cas = 1, t, n;
    scanf("%d", &t);
    while (t --) {
        scanf("%d", &n);
        printf("Case #%d: ", cas ++);
        printf("%I64d\n", dp[n]);
    }
    return 0;
}
