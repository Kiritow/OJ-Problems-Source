#include <iostream>
#include <string.h>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
const int maxn = 50000;
struct node
{
    int s;
    int e;
    int v;
}seg[maxn+5];
struct hashnode
{
    int rv;
    int id;
}index[maxn*2+5];
bool cmp(const hashnode &a, const hashnode &b)
{
    return a.rv<b.rv;
}
int f[maxn*2+5];
inline int lowbit(int x)
{
    return x & (-x);
}
inline void _update(int x, int d)
{
    int i;
    for (i=x; i>0; i-=lowbit(i))
    {
        f[i] += d;
    }
}
inline void update(int l, int r, int d)
{
    _update(l-1, -d);
    _update(r, d);
}
inline int getpt(int x, int n)
{
    int i, s = 0;
    for (i=x; i<=n; i+=lowbit(i))
    {
        s += f[i];
    }
    return s;
}
int bs(int v, int s, int t)
{
    int l=s-1, r=t+1, m, ans;
    while(l<=r)
    {
        m = (l+r)>>1;
        if (v<=index[m].rv)
        {
            ans = m;
            r = m-1;
        }
        else l = m+1;
    }
    return index[ans].id;
}
int main()
{
    int t;
    int len;
    double amt;
    int n;
    int i, j;
    int a, b;
    int end;
    double ans;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %lf", &len, &amt);
        scanf("%d", &n);
        index[1].rv = 0;
        index[2].rv = len;
        for (i=0,j=3; i<n; i++,j+=2)
        {
            scanf("%d %d %d", &seg[i].s, &seg[i].e, &seg[i].v);
            index[j].rv = seg[i].s;
            index[j+1].rv = seg[i].e;
        }
        end = j-1;
        sort(index+1, index+end+1, cmp);
        index[1].id = 1;
        for (i=2,j=2; i<=end; i++)
        {
            if (index[i].rv!=index[j-1].rv)
            {
                index[j].rv = index[i].rv;
                index[j].id = j;
                j++;
            }
        }
        end = j-1;
        memset(f, 0, sizeof(f));
        update(1, end-1, 1);
        for (i=0; i<n; i++)
        {
            a = bs(seg[i].s, 1, end);
            b = bs(seg[i].e, 1, end);
            update(a, b-1, seg[i].v);
        }
        ans = 0;
        for (i=1; i<end && fabs(amt)>1e-6; i++)
        {
            a = index[i+1].rv-index[i].rv;
            b = getpt(i, end);
            if (a*1.0>amt/b)
            {
                ans += amt/b;
                amt = 0;
            }
            else
            {
                ans += a;
                amt -= a*b;
            }
        }
        printf("%.2lf\n", ans);
    }
    return 0;
}
