#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
const int maxn = 30300;
const int MOD = 1000000007;
int MID;
int a[maxn], p[maxn];
int cnt[maxn];
struct query
{
    int l, r, id;
    bool operator < (const query& rhs) const
    {
        return l / MID < rhs.l / MID || (l / MID == rhs.l / MID && r < rhs.r);
    }
}q[maxn];
long long Inv(long long x, long long mod)
{
    long long r, y;
    for(r = 1, y = mod - 2; y; x = x * x % mod, y >>= 1)
        (y & 1) && (r = r * x % mod);
    return r;
}
int inv[maxn];
void init()
{
    inv[0] = 1;
    for(int i = 1; i < maxn; i ++)
    {
        inv[i] = Inv(i, MOD);
    }
}
int main()
{
    int T, n, m;
    init();
    scanf("%d", &T);
    while(T --)
    {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i ++)
            scanf("%d", &a[i]);
        a[0] = 0;
        for(int i = 0; i < m; i ++)
        {
            scanf("%d%d", &q[i].l, &q[i].r);
            q[i].id = i;
        }
        MID = sqrt(n + 0.0);
        sort(q, q + m);
        int L = 1, R = 1;
        int ans = 1, tot = 1;
        memset(cnt, 0, sizeof(cnt));
        cnt[a[1]] ++;
        for(int i = 0; i < m; i ++)
        {
            while(R < q[i].r)
            {
                R ++; tot ++; cnt[a[R]] ++;
                ans = 1ll * ans * inv[cnt[a[R]]] % MOD;
                ans = 1ll * ans * tot % MOD;
            }
            while(R > q[i].r)
            {
                ans = 1ll * ans * cnt[a[R]] % MOD;
                ans = 1ll * ans * inv[tot] % MOD;
                R --; tot --; cnt[a[R + 1]] --;
            }
            while(L < q[i].l)
            {
                ans = 1ll * ans * cnt[a[L]] % MOD;
                ans = 1ll * ans * inv[tot] % MOD;
                L ++; tot --; cnt[a[L - 1]] --;
            }
            while(L > q[i].l)
            {
                L --; tot ++; cnt[a[L]] ++;
                ans = 1ll * ans * inv[cnt[a[L]]] % MOD;
                ans = 1ll * ans * tot % MOD;
            }
            p[q[i].id] = ans;
        }
        for(int i = 0; i < m; i ++)
        {
            printf("%d\n", p[i]);
        }
    }
}
