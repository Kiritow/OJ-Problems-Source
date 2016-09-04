#include<stdio.h>
#include<string.h>
#include<algorithm>
#define MOD 1000000007
#define MAXD 40010
using namespace std;
int isprime[MAXD], prime[MAXD], P, p[MAXD], pn;
long long A, C, K, ANS, T;
void exgcd(long long a, long long b, long long &x, long long &y)
{
    if(b == 0)
        x = 1, y = 0;
    else
        exgcd(b, a % b, y, x), y -= x * (a / b);
}
long long powmod(long long a, long long n)
{
    long long ans = 1;
    while(n)
    {
        if(n & 1)
            ans = ans * a % MOD;
        n >>= 1;
        a = a * a % MOD;
    }
    return ans;
}
void prepare()
{
    int i, j, k = 40000;
    memset(isprime, -1, sizeof(isprime));
    P = 0;
    for(i = 2; i <= k; i ++)
        if(isprime[i])
        {
            prime[P ++] = i;
            for(j = i * i; j <= k; j += i)
                isprime[j] = 0;
        }
}
long long block(long long n, long long c)
{
    long long ans, x, y;
    ans = powmod(c, n * n);
    ans = (ans + 2 * powmod(c, n * n / 4 + (n & 1))) % MOD;
    ans = (ans + powmod(c, n * n / 2 + (n & 1))) % MOD;
    exgcd(4, MOD, x, y);
    x = (x % MOD + MOD) % MOD;
    ans = ans * x % MOD;
    return ans;
}
long long euler(long long n)
{
    int i;
    long long ans = n;
    for(i = 0; i < pn; i ++)
        if(n % p[i] == 0)
            ans = ans / p[i] * (p[i] - 1);
    return ans;
}
long long prepareBK()
{
    int i, j, nx, ny, x, y, cnt;
    long long N = 1;
    nx = x = A - 1, ny = y = A + 1;
    pn = 0;
    for(i = 0; i < P && prime[i] * prime[i] <= ny; i ++)
    {
        cnt = 0;
        if(x % prime[i] == 0 || y % prime[i] == 0)
            p[pn ++] = prime[i];
        while(x % prime[i] == 0)
            ++ cnt, x /= prime[i];
        while(y % prime[i] == 0)
            ++ cnt, y /= prime[i];
        for(j = 0, cnt /= 2; j < cnt; j ++)
            N *= prime[i];
    }
    if(x > y)
        i = x, x = y, y = i;
    if(x > 1)
        p[pn ++] = x;
    if(y > 1)
        p[pn ++] = y;
    if(x == y)
        N *= x;
    return N;
}
void dfs(int cur, long long R, long long x, long long &c)
{
    int i, cnt = 0;
    long long t = 1;
    if(cur == pn)
    {
        long long ans, n, x, y;
        n = euler(K / R) % MOD;
        T = (T + n * powmod(c, R)) % MOD;
        return ;
    }
    while(x % p[cur] == 0)
        x /= p[cur], ++ cnt;
    for(i = 0; i <= cnt; i ++)
    {
        dfs(cur + 1, R * t, x, c);
        t *= p[cur];
    }
}
void findB(int cur, long long B, long long x)
{
    int i, cnt = 0;
    long long t = 1;
    if(cur == pn)
    {
        long long n, x, y, c;
        c = block(B, C);
        K = (A * A - 1) / (B * B);
        T = 0;
        dfs(0, 1, K, c);
        exgcd(K, MOD, x, y);
        x = (x % MOD + MOD) % MOD;
        T = (T * x) % MOD;
        ANS = (ANS + T * C) % MOD;
        return ;
    }
    while(x % p[cur] == 0)
        ++ cnt, x /= p[cur];
    for(i = 0; i <= cnt; i ++)
    {
        findB(cur + 1, B * t, x);
        t *= p[cur];
    }
}
void solve()
{
    ANS = 0;
    findB(0, 1, prepareBK());
    printf("%I64d\n", ANS);
}
int main()
{
    int t, tt;
    prepare();
    scanf("%d", &t);
    for(tt = 0; tt < t; tt ++)
    {
        printf("Case %d: ", tt + 1);
        scanf("%I64d%I64d", &A, &C);
        if(A == 1)
            printf("%I64d\n", C);
        else
            solve();
    }
    return 0;
}
