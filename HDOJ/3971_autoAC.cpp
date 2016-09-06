#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
namespace ST
{
    typedef long long LL;
    const int maxn = 300010;
    LL a[maxn];
    LL Min[maxn<<2], Max[maxn<<2], add[maxn<<2];
    inline void pushUp(int rt)
    {
        Max[rt] = max(Max[rt<<1], Max[rt<<1|1]);
        Min[rt] = min(Min[rt<<1], Min[rt<<1|1]); 
    }
    inline void modify(int rt, LL c)
    {
        add[rt] += c;
        Max[rt] += c;
        Min[rt] += c;
    }
    inline void pushDown(int rt)
    {
        modify(rt << 1, add[rt]);
        modify((rt << 1) | 1, add[rt]);
        add[rt] = 0;
    }
    void build(int l, int r, int rt)
    {
        add[rt] = 0;
        if (l == r) {
            Max[rt] = Min[rt] = a[l];
            return ;
        }
        int m = (l + r) >> 1;
        build(l, m, rt << 1);
        build(m + 1, r, (rt << 1) | 1);
        pushUp(rt);
    }
    void update(int l, int r, int rt, LL L, LL R, LL D)
    {
        if (L > Max[rt] || R < Min[rt]) return ;
        if (L <= Min[rt] && R >= Max[rt]) {
            modify(rt, D);
            return ;
        }
        if (l == r) return ;
        int m = (l + r) >> 1;
        pushDown(rt);
        update(l, m, rt << 1, L, R, D); 
        update(m + 1, r, (rt << 1) | 1, L, R, D); 
        pushUp(rt);
    }
    int query(int l, int r, int rt, LL L, LL R)
    {
        if (L > Max[rt] || R < Min[rt]) {
            return 0;
        }
        if (L <= Min[rt] && R >= Max[rt]) {
            return r - l + 1;
        }
        if (l == r) return 0;
        int m = (l + r) >> 1;
        pushDown(rt);
        return query(l, m, rt << 1, L, R) + query(m + 1, r, (rt << 1) | 1, L, R);
    }
    void getNewArr(int l, int r, int rt)
    {
        if (l == r) {
            a[l] = Max[rt];
            return ;
        }
        int m = (l + r) >> 1;
        pushDown(rt);
        getNewArr(l, m, rt << 1);
        getNewArr(m + 1, r, (rt << 1) | 1);
    }
} 
int main()
{
    using namespace ST;
    int n, m;
    char op[2];
    long long L, R, D;
    while (scanf("%d%d", &n, &m) != EOF) {
        for (int i = 1; i <= n; ++i) {
            scanf("%lld", &a[i]);
        }
        sort(a + 1, a + n + 1);
        build(1, n, 1);
        while (m--) {
            scanf("%s", op);
            if (op[0] == 'C') {
                scanf("%lld%lld%lld", &L, &R, &D);
                update(1, n, 1, L, R, D);
            } else {
                scanf("%lld%lld", &L, &R);
                printf("%d\n", query(1, n, 1, L, R));
            }
            if (m % 4500 == 0) {
                getNewArr(1, n, 1);
                sort(a + 1, a + n + 1);
                build(1, n, 1);
            }
        }
    }
    return 0;
}
