#include <iostream>
#include <cstdio>
#include <cstdlib>
#define LL long long
#define MOD 1000000007
using namespace std;
LL b1, q, a1, d, n, m;
LL ans, dis[10005];
void input()
{
    ans = 0;
    scanf("%I64d%I64d%I64d%I64d%I64d%I64d", &b1, &q, &a1, &d, &n, &m);
}
void exgcd(LL a, LL b, LL &x, LL &y, LL &d)
{
    if (b == 0)
    {
        x = 1;
    y = 0;
    d = a;
    }
    else
    {
        exgcd(b, a%b, y, x, d);
        y -= a/b*x;
    }
}
LL modDiv(LL a, LL b)
{
    LL x, y, d;
    exgcd(b, MOD, x, y, d);
    x = (x+MOD) % MOD;
    x = (x*a/d) % MOD;
    return x;
}
LL quickPow(LL x, LL n)
{
    LL a = 1;
    while (n)
    {
        a *= n&1 ? x : 1;
        a %= MOD;
        n >>= 1 ;
        x *= x;
        x %= MOD;
    }
    return a;
}
void work()
{
    LL now = b1, tmp;
    now %= MOD;
    for (int i = 1; i <= n; ++i)
    {
        tmp = modDiv(now, q-1);
        now = now+tmp;
        now %= MOD;
        dis[i] = (a1+(i-1)*d%MOD-tmp)%MOD;
        dis[i] = (dis[i]+MOD)%MOD;
    }
    LL qt = 1;
    ans += qt*dis[n];
    for (int i = n-1; i > 0; --i)
    {
        qt = modDiv((qt*((n+m-1)-i)%MOD+MOD)%MOD, n-i);
        ans += (qt*dis[i])%MOD;
        ans %= MOD;
    }
    tmp = quickPow(q, (m-1)%(MOD-1))%MOD;
    ans += now*tmp%MOD;
    ans %= MOD;
    printf("%I64d\n", ans);
}
int main()
{
    int T;
    scanf("%d", &T);
    for (int times = 1; times <= T; ++times)
    {
        printf("Case #%d: ", times);
        input();
        work();
    }
    return 0;
}
