#include<stdio.h>
#include<string.h>
#define MAXD 100010
int N, M, a[MAXD], mc[4 * MAXD], lc[4 * MAXD], rc[4 * MAXD];
int getmax(int x, int y)
{
    return x > y ? x : y;
}
void update(int cur, int x, int y)
{
    int mid = (x + y) / 2, ls = 2 * cur, rs = 2 * cur + 1;
    mc[cur] = getmax(mc[ls], mc[rs]);
    lc[cur] = lc[ls], rc[cur] = rc[rs];
    if(a[mid] < a[mid + 1])
    {
        mc[cur] = getmax(mc[cur], rc[ls] + lc[rs]);
        if(lc[ls] == mid - x + 1)
            lc[cur] += lc[rs];
        if(rc[rs] == y - mid)
            rc[cur] += rc[ls];
    }
}
void build(int cur, int x, int y)
{
    int mid = (x + y) / 2, ls = 2 * cur, rs = 2 * cur + 1;
    if(x == y)
    {
        mc[cur] = lc[cur] = rc[cur] = 1;
        return ;
    }
    build(ls, x, mid);
    build(rs, mid + 1, y);
    update(cur, x, y);
}
void init()
{
    int i, j, k;
    for(i = 0; i < N; i ++)
        scanf("%d", &a[i]);
    build(1, 0, N - 1);
}
void refresh(int cur, int x, int y, int k, int v)
{
    int mid = (x + y) / 2, ls = 2 * cur, rs = 2 * cur + 1;
    if(x == y)
    {
        a[x] = v;
        return ;
    }
    if(k <= mid)
        refresh(ls, x, mid, k, v);
    else
        refresh(rs, mid + 1, y, k, v);
    update(cur, x, y);
}
int query(int cur, int x, int y, int s, int t, int p, int &ans)
{
    int mid = (x + y) / 2, ls = 2 * cur, rs = 2 * cur + 1;
    if(x == y)
        return 1;
    if(mid >= t)
        return query(ls, x, mid, s, t, 0, ans);
    else if(mid + 1 <= s)
        return query(rs, mid + 1, y, s, t, 1, ans);
    else
    {
        int ln, rn;
        if(x >= s && y <= t)
        {
            ans = getmax(ans, mc[cur]);
            return p ? rc[cur] : lc[cur];
        }
        ln = query(ls, x, mid, s, t, 1, ans), rn = query(rs, mid + 1, y, s, t, 0, ans);
        if(x >= s && mid <= t)
        {
            if(a[mid] < a[mid + 1])
            {
                ans = getmax(ans, rc[ls] + rn);
                if(rc[ls] == mid - x + 1)
                    return rc[ls] + rn;
            }
            return lc[ls];
        }
        else if(mid + 1 >= s && y <= t)
        {
            if(a[mid] < a[mid + 1])
            {
                ans = getmax(ans, ln + lc[rs]);
                if(lc[rs] == y - mid)
                    return ln + lc[rs];
            }
            return rc[rs];
        }
        else
        {
            if(a[mid] < a[mid + 1])
                ans = getmax(ans, ln + rn);
        }
    }
    return 0;
}
void solve()
{
    int i, j, k, x, y, ans;
    char b[5];
    for(i = 0; i < M; i ++)
    {
        scanf("%s%d%d", b, &x, &y);
        if(b[0] == 'Q')
        {
            ans = 1;
            query(1, 0, N - 1, x, y, 0, ans);
            printf("%d\n", ans);
        }
        else
            refresh(1, 0, N - 1, x, y);
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t --)
    {
        scanf("%d%d", &N, &M);
        init();
        solve();
    }
    return 0;
}
