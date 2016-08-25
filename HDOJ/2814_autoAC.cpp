#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
typedef unsigned __int64 LL;
struct Matrix
{
    LL m[3][3];
}E, D;
LL Pow(LL a, LL b, LL mod)
{
    LL ans = 1;
    while (b)
    {
        if (b & 1)
        {
            b--;
            ans = (ans*a)%mod;
        }
        else
        {
            b /= 2;
            a = (a*a)%mod;
        }
    }
    return ans;
}
void init()
{
    for (int i = 1; i <= 2; i++)
        for (int j = 1; j <= 2; j++)
        {
            D.m[i][j] = 1;
            E.m[i][j] = (i == j);
        }
        D.m[2][2] = 0;
}
Matrix Multi(Matrix A, Matrix B, LL mod)
{
    Matrix ans;
    for (int i = 1; i <= 2; i++)
        for (int j = 1; j <= 2; j++)
        {
            ans.m[i][j] = 0;
            for (int k = 1; k <= 2; k++)
                ans.m[i][j] = (ans.m[i][j] + A.m[i][k] * B.m[k][j])%mod;
        }
        return ans;
}
Matrix Pow(Matrix A, LL k, LL mod)
{
    Matrix ans = E;
    while (k)
    {
        if (k & 1)
        {
            k--;
            ans = Multi(ans, A, mod);
        }
        else
        {
            k /= 2;
            A = Multi(A, A, mod);
        }
    }
    return ans;
}
LL Fib(LL n, LL mod)
{
    return Pow(D, n, mod).m[2][1];
}
long long euler(long long x)
{
    long long i, res = x;
    for (i = 2; i*i <= x; i++)
        if (x%i == 0)
        {
            res = res / i*(i - 1);
            while (x%i == 0)
                x /= i;
        }
        if (x > 1)
            res = res / x*(x - 1);
        return res;
}
LL s_mod(LL n)
{
    LL a1 = 0, a2 = 1, a3 = 1, tmp, ans = 1;
    while (a2 != 0 || a3 != 1)
    {
        ans++;
        tmp = (a2 + a3)%n;
        a2 = a3;
        a3 = tmp;
    }
    return ans;
}
LL smod[305];
int main()
{
    init();
    smod[1] = 1;
    for (int i = 2; i <= 300; i++)
        smod[i] = s_mod(i);
    LL a, b, n;
    int c;
    int t;
    scanf("%d", &t);
    LL mod1, mod2, tmp, cnt, ans, eul;
    for (int cas = 1; cas <= t; cas++)
    {
        scanf("%I64u%I64u%I64u%d", &a, &b, &n, &c);
        if (c == 1)
        {
            printf("Case %d: 0\n", cas);
            continue;
        }
        mod1 = smod[c];
        eul = euler(c);
        mod2 = smod[eul];
        tmp = Pow(a%mod1, b, mod1);
        tmp = Fib(tmp, c);
        cnt = Pow(a%mod2, b, mod2);
        cnt = Fib(cnt, eul);
        cnt = Pow(cnt, n - 1, eul);
        cnt += eul;
        ans = Pow(tmp, cnt, c);
        printf("Case %d: %I64u\n", cas, ans);
    }
    return 0;
}
