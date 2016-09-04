#include<stdio.h>
#include<string.h>
#define MAXD 33
#define MOD 1000000007
typedef __int64 LL;
int N, M, K;
LL C[MAXD][MAXD][MAXD], f[MAXD][MAXD], X[MAXD], S[MAXD];
LL fac(LL a, int n)
{
    int i;
    LL ans = 1;
    for(i = 0; i < n; i ++) ans = ans * a % MOD;
    return ans;
}
void exgcd(LL a, LL b, LL &x, LL &y)
{
    if(b == 0) x = 1, y = 0;
    else exgcd(b, a % b, y, x), y -= x * (a / b);
}
LL getinv(LL a)
{
    LL x, y;
    exgcd(a, MOD, x, y);
    x %= MOD;
    if(x < 0) x += MOD;
    return x;
}
void prepare()
{
    int i, j, t;
    memset(C, 0, sizeof(C));
    C[1][0][0] = 1;
    for(i = 1; i <= 32; i ++)
    {
        C[1][i][0] = 1;
        for(j = 1; j <= i; j ++)
            C[1][i][j] = (C[1][i - 1][j] + C[1][i - 1][j - 1]) % MOD;
    }
    for(t = 2; t <= 32; t ++)
        for(i = 0; i <= 32; i ++)
            for(j = 0; j <= 32; j ++)
                C[t][i][j] = fac(C[1][i][j], t);
}
void solve()
{
    int i, j, k, t;
    LL ans;
    for(t = 1; t <= N; t ++)
    {
        memset(f, 0, sizeof(f)), f[0][0] = 1;
        for(i = 1; i <= K; i ++)
            for(j = 0; j <= M; j ++)
                for(k = 0; k <= j; k ++)
                    f[i][j] = (f[i][j] + f[i - 1][k] * C[t][M - k][j - k]) % MOD;
        X[t] = f[K][M];
    }
    S[0] = 1, S[1] = X[1];
    for(i = 2; i <= N; i ++)
    {
        S[i] = 0;
        for(j = 1; j <= i; j ++)
        {
            if(j & 1) S[i] = (S[i] + S[i - j] * X[j] + MOD) % MOD;
            else S[i] = (S[i] - S[i - j] * X[j] + MOD) % MOD;
        }
        S[i] = S[i] * getinv(i) % MOD;
    }
    ans = S[N];
    for(i = 2; i <= N; i ++) ans = ans * i % MOD;
    if(ans < 0) ans += MOD;
    printf("%I64d\n", ans);
}
int main()
{
    prepare();
    while(scanf("%d%d%d", &N, &M, &K) == 3)
        solve();
    return 0;
}
