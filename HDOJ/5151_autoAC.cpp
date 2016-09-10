#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
using namespace std; 
#define INF 1000000000
#define N 111
typedef __int64 LL; 
const LL mod = 1000000007; 
LL dp[N][N], C[N][N]; 
int n, num[N]; 
void init() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j <= i; j++) {
            if(j == 0 || j == i) C[i][j] = 1; 
            else C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod; 
        }
    }
}
LL dfs(int L, int R) {
    if(dp[L][R] != -1) return dp[L][R]; 
    if(L == R) return dp[L][R] = 1; 
    dp[L][R] = (dfs(L+1, R) + dfs(L, R - 1)) % mod; 
    for(int i = L+1; i <= R-1; i ++) {
        if(num[i-1] != num[i+1]) continue; 
        dp[L][R] = (dp[L][R] + (dfs(L, i - 1) * dfs(i+1, R) % mod) * C[R- L][i - L]%mod) % mod; 
    }
    return dp[L][R]; 
}
int main() {
    init();
    while(scanf("%d", &n) != EOF) {
        memset(dp, -1, sizeof(dp)); 
        for(int i = 1;i <= n; i++) scanf("%d", &num[i]); 
        printf("%I64d\n", dfs(1, n)); 
    }
    return 0; 
}
