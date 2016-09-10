#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef __int64 LL;
const int MAXN = 1005;
int prim[MAXN], nprm;
bool vis[MAXN];
int n, m;
void init_prim()
{
    for (int i = 2; i< MAXN; ++i)
    {
        if (!vis[i]) prim[nprm++] = i;
        for (int j = 0; j< nprm && prim[j]&i < MAXN; ++i)
        {
            vis[prim[j]*i] = 1;
            if (i % prim[j] == 0) break;
        }
    }
}
int Euler(int x)
{
    int res = x;
    for (int i = 0, k; i< nprm ; ++i)
    {
        k = prim[i];
        if (k * k > x) break;
        if (x % k == 0)
        {
            res = res/k*(k-1);
            while (x%k==0) x/=k;
        }
    }
    if (x!=1) res = res/x*(x-1);
    return res;
}
int nfen, fen[100][2];
void m_divide(int x)
{
    nfen = 0;
    for (int i = 0, k; i< nprm ; ++i)
    {
        k = prim[i];
        if (k * k > x) break;
        if (x % k == 0)
        {
            fen[nfen][0] = k;
            fen[nfen][1] = 0;
            while (x%k==0) x/=k, ++fen[nfen][1];
            ++nfen;
        }
    }
    if (x!=1) fen[nfen][0]=x, fen[nfen++][1]=1;
}
LL mpow(LL a, int b, LL mod)
{
    LL res = 1LL;
    while (b)
    {
        if (b&1) res = res*a%mod;
        a = a*a%mod;
        b >>= 1;
    }
    return res;
}
int caonima = 0;
LL ri;
void dfs(int idx, LL all)
{
    if (caonima) return;
    if (idx == nfen)
    {
        if (all == 1LL || all == m) return;
        if (mpow(ri, all, n) == 1LL)
            caonima = 1;
        return;
    }
    for (int i = 0; i<=fen[idx][1]; ++i)
    {
        dfs(idx+1, all);
        all *= fen[idx][0];
    }
}
int check(LL r)
{
    LL res = r;
    if (mpow(r, m, n) != 1LL) return 0;
    caonima = 0;
    ri = res;
    dfs(0, 1);
    if (caonima) return 0;
    return 1;
}
int gcd(int a, int b)
{
    return b==0?a:gcd(b,a%b);
}
int opt[1000000], cnt;
void solve()
{
    m = Euler(n);
    m_divide(m);
    int ff = 0;
    for (int i = 2; i< n; ++i)
    {
        if (check(i))
        {
            ff = i;
            break;
        }
    }
    if (!ff)
    {
        printf("-1\n");
        return;
    }
    cnt = 0;
    opt[cnt++] = ff;
    LL res = ff;
    res = res*ff%n;
    for (int i = 2; i< m; ++i, res = res*ff%n)
    {
        if (gcd(i, m) == 1)
        {
            opt[cnt++] = res;
        }
    }
    sort(opt, opt+cnt);
    printf("%d", opt[0]);
    for (int i = 1; i< cnt; ++i)
    {
        printf(" %d", opt[i]);
    }
    puts("");
}
int main()
{
    init_prim();
    while (scanf("%d", &n) != EOF)
    {
        if (n==2) puts("1");
        else if (n==4) puts("3");
        else
        {
            int p = n, cc = 0;
            if (n%2==0) n>>=1;
            for (int i = 0, k; i<nprm ; ++i)
            {
                k = prim[i];
                if (k*k > n) break;
                if (n % k == 0)
                {
                    if (++cc > 1) break;
                    while (n % k==0) n /= k;
                }
            }
            if (n!=1) ++cc;
            if (cc!=1) puts("-1");
            else
            {
                n = p;
                solve();
            }
        }
    }
    return 0;
}
