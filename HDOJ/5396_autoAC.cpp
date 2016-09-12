#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 110;
const LL mod = 1000000007;
LL dp[maxn][maxn],c[maxn][maxn] = {1},f[maxn] = {1};
void init() {
    for(int i = 1; i < maxn; ++i) {
        c[i][0] = c[i][i] = 1;
        f[i] = f[i-1]*i%mod;
        for(int j = 1; j < i; ++j)
            c[i][j] = (c[i-1][j-1] + c[i-1][j])%mod;
    }
}
char op[maxn];
int main() {
    init();
    int n;
    while(~scanf("%d",&n)) {
        memset(dp,0,sizeof dp);
        for(int i = 0; i < n; ++i)
            scanf("%I64d",&dp[i][i]);
        scanf("%s",op);
        for(int i = 2; i <= n; ++i) {
            for(int j = 0; j + i <= n; ++j) {
                for(int k = j,t = j + i -1; k < t; ++k) {
                    LL tmp;
                    if(op[k] == '+')
                        tmp = (f[t-k-1]*dp[j][k] + f[k-j]*dp[k+1][t])%mod;
                    else if(op[k] == '-') {
                        tmp = (f[t-k-1]*dp[j][k] - f[k-j]*dp[k+1][t])%mod;
                        tmp = (tmp + mod)%mod;
                    } else if(op[k] == '*') tmp = dp[j][k]*dp[k+1][t]%mod;
                    tmp = tmp*c[t-j-1][k-j]%mod;
                    dp[j][t] = (dp[j][t] + tmp + mod)%mod;
                }
            }
        }
        printf("%I64d\n",dp[0][n-1]);
    }
    return 0;
}
