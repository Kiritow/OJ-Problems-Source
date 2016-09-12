#include <cstdio>
typedef long long LL;
const int maxn = 100010, mod = 1000000007, inv2 = 500000004;
int t, n, pw1[maxn], pw2[maxn], x, y, pre1x, pre1y, pre2x, pre2y, ans;
int mod_add(int x, int y)
{
    x += y;
    if(x >= mod)
        x -= mod;
    return x;
}
int mod_sub(int x, int y)
{
    x -= y;
    if(x < 0)
        x += mod;
    return x;
}
int det(int x1, int y1, int x2, int y2)
{
    return mod_sub((LL)x1 * y2 % mod, (LL)x2 * y1 % mod);
}
int main()
{
    scanf("%d", &t);
    pw1[0] = 1;
    for(int i = 1; i < maxn; ++i)
        pw1[i] = (LL)pw1[i - 1] * 2 % mod; 
    pw2[0] = 1;
    for(int i = 1; i < maxn; ++i)
        pw2[i] = (LL)pw2[i - 1] * inv2 % mod; 
    while(t--)
    {
        scanf("%d", &n);
        pre1x = pre1y = pre2x = pre2y = ans = 0;
        for(int i = 1; i <= n; ++i)
        {
            scanf("%d%d", &x, &y);
            ans = mod_add(ans, (LL)pw1[i - 1] * det(x, y, pre2x, pre2y) % mod);
            ans = mod_add(ans, (LL)(i == n ? inv2 : pw1[n - i - 1]) * det(pre1x, pre1y, x, y) % mod);
            pre1x = mod_add(pre1x, (LL)x * pw1[i] % mod); 
            pre1y = mod_add(pre1y, (LL)y * pw1[i] % mod); 
            pre2x = mod_add(pre2x, (LL)x * pw2[i] % mod); 
            pre2y = mod_add(pre2y, (LL)y * pw2[i] % mod); 
        }
        printf("%d\n", ans);
    }
    return 0;
}
