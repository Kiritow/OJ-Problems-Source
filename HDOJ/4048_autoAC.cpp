#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MAXN 20010
int MOD;
using namespace std;
typedef long long LL;
int cas, n, m, tx;
int pri[MAXN], notp[MAXN], flag[MAXN], prs;
int tot[MAXN], maxm;
int fac[MAXN][305], facs[MAXN], phi[MAXN * 10];
void init(){
    for (int i = 2; i < MAXN; i++) if (!notp[i]) {
        flag[i] = 1;
        for (int j = i*2; j < MAXN; j += i) {
            if (!notp[j]) notp[j] = flag[j] = 1;
            else if (flag[j]) flag[j]++;
            if (j%(i*i) == 0) flag[j] = 0;
        }
    }
    for (int i = 2; i < MAXN; i++)
        if (!notp[i]) pri[prs++] = i;
    for (int i = 1; i < MAXN; i++)
        for (int j = 1; j * j <= i; j++) if (i % j == 0) {
            fac[i][facs[i]++] = j;
            if (j * j != i)fac[i][facs[i]++] = i/j;
        }
    const int maxn = 100000;
    for (int i = 1; i <= maxn; i ++) phi[i] = i;
    for (int i = 2; i <= maxn; i ++) if(phi[i] == i) {
        for(int j = i; j <= maxn; j += i)
            phi[j] = phi[j] / i * (i - 1);
    }
}
int powmod(int x, int d){
    int ans = 1, tmp = x;
    for (; d; d >>= 1, tmp = (LL)tmp * tmp % MOD)
        if (d&1) ans = (LL)ans * tmp % MOD;
    return ans;
}
int cal(int l){
    int ans = powmod(tot[1], l);
    for (int i = 2; i <= maxm; i++) {
        if (flag[i] == 0) continue;
        if (flag[i] & 1) ans = (ans - powmod(tot[i], l)) % MOD;
        else ans = (ans + powmod(tot[i], l)) % MOD;
    }
    return (ans % MOD + MOD) % MOD;
}
void solve(){
    int ans = 0;
    for(int i = 1; i * i <= n; i ++) if(n % i == 0) {
        ans = (ans + (LL)cal(i) * phi[n / i]) % MOD;
        if(i * i != n)
            ans = (ans + (LL)cal(n / i) * phi[i]) % MOD;
    }
    printf("%d\n", (ans + MOD) % MOD / n);
}
int main(){
    init();
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d%d", &m, &n);
        MOD = 10007 * n;
        memset(tot, 0, sizeof tot);
        maxm = 0;
        for (int i = 1; i <= m; i++) {
            scanf("%d", &tx);
            maxm = max(tx, maxm);
            for (int j = 0; j < facs[tx]; j++)
                tot[fac[tx][j]]++;
        }
        solve();
    }
    return 0;
}
