#include<stdio.h>
#include<string.h>
#define MAXD 40010
int N, isprime[MAXD], prime[MAXD], P, p[MAXD], pn;
long long M;
struct Matrix
{
    long long a[4][4];
    void init()
    {
        memset(a, 0, sizeof(a));
    }
}unit, mat[40];
long long mul(long long x, long long y)
{
    long long ans = 0;
    x %= M;
    while(y)
    {
        if((y & 1) && (ans += x) >= M)
            ans -= M;
        y >>= 1;
        if((x <<= 1) >= M)
            x -= M;
    }
    return ans;
}
Matrix multiply(Matrix &x, Matrix &y)
{
    int i, j, k;
    Matrix z;
    z.init();
    for(i = 0; i < 4; i ++)
        for(k = 0; k < 4; k ++)
            if(x.a[i][k])
            {
                for(j = 0; j < 4; j ++)
                    if(y.a[k][j])
                        z.a[i][j] = (z.a[i][j] + mul(x.a[i][k], y.a[k][j])) % M;
            }
    return z;
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
int euler(int n)
{
    int i, ans = n;
    for(i = 0; i < pn; i ++)
        if(n % p[i] == 0)
            ans = ans / p[i] * (p[i] - 1);
    return ans;
}
void divide(int n)
{
    int i, j;
    pn = 0;
    for(i = 0; i < P && prime[i] * prime[i] <= n; i ++)
        if(n % prime[i] == 0)
        {
            p[pn ++] = prime[i];
            while(n % prime[i] == 0)
                n /= prime[i];
        }
    if(n > 1)
        p[pn ++] = n;
}
void initmat() 
{
    int i;
    mat[0].init();
    mat[0].a[0][0] = 2, mat[0].a[0][2] = 1, mat[0].a[0][3] = M - 1;
    mat[0].a[1][0] = mat[0].a[1][1] = mat[0].a[1][2] = 1;
    mat[0].a[2][0] = 1, mat[0].a[2][2] = 2, mat[0].a[2][3] = M - 1;
    mat[0].a[3][2] = 1;
    for(i = 1; i < 32; i ++)
        mat[i] = multiply(mat[i - 1], mat[i - 1]);
}
void powmod(Matrix &unit, int n)
{
    int i;
    for(i = 0; n; i ++, n >>= 1)
        if(n & 1)
            unit = multiply(mat[i], unit);
}
void dfs(int cur, int R, int x, long long &ans)
{
    int i, cnt = 0, t = 1;
    if(cur == pn)
    {
        int n = euler(N / R);
        if(R == 1)
            ans = (ans + n) % M;
        else
        {
            unit.init();
            unit.a[0][0] = 3, unit.a[1][0] = 2, unit.a[2][0] = 3, unit.a[3][0] = 1;
            powmod(unit, R - 2);
            ans = (ans + mul(n, unit.a[0][0] + unit.a[1][0])) % M;
        }
        return ;
    }
    while(x % p[cur] == 0)
        ++ cnt, x /= p[cur];
    for(i = 0; i <= cnt; i ++)
    {
        dfs(cur + 1, R * t, x, ans);
        t *= p[cur];
    }
}
void solve()
{
    int i;
    long long ans, x, y, n;
    ans = 0;
    divide(N);
    initmat();
    dfs(0, 1, N, ans);
    printf("%I64d\n", ans / N);
}
int main()
{
    prepare();
    while(scanf("%d%I64d", &N, &M) == 2)
    {
        M *= N;
        solve();
    }
    return 0;
}
