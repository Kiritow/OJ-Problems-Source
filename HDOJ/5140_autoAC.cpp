#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const double eps = 1e-8;
const int maxn = 1e5+10;
int tot,tree[maxn],c[maxn*20],lson[maxn*20],rson[maxn*20];
ll sum[maxn*20];
int build (int l, int r)
{
    int root = tot++;
    c[root] = sum[root] = 0;
    if (l != r)
    {
        int mid = (l + r) >> 1;
        lson[root] = build(l,mid);
        rson[root] = build(mid+1,r);
    }
    return root;
}
int MAX;
int update (int root,int pos,int val,ll sa)
{
    int newroot = tot++;
    int tmp = newroot;
    int l = 1, r = MAX;
    c[newroot] = c[root] + val;
    sum[newroot] = sum[root] + sa;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (pos <= mid)
        {
            r = mid;
            rson[newroot] = rson[root];
            root = lson[root];
            lson[newroot] = tot++;
            newroot = lson[newroot];
        }
        else
        {
            l = mid + 1;
            lson[newroot] = lson[root];
            root = rson[root];
            rson[newroot] = tot++;
            newroot = rson[newroot];
        }
        c[newroot] = c[root] + val;
        sum[newroot] = sum[root] + sa;
    }
    return tmp;
}
ll query(int root1,int root2,int l,int r,int ua,int ub)
{
    if (ua > ub)
        return 0;
    if (ua <= l && ub >= r)
    {
        return sum[root2] - sum[root1];
    }
    int mid = (l + r) >> 1;
    ll t1 = 0, t2 = 0;
    if (ua <= mid)
        t1 = query(lson[root1],lson[root2],l,mid,ua,ub);
    if (ub > mid)
        t2 = query(rson[root1],rson[root2],mid+1,r,ua,ub);
    return t1 + t2;
}
int lev[maxn],idx1,idx2,age[maxn];
struct worker
{
    int s,l,a;
    bool operator < (const worker &rhs)const
    {
        return a < rhs.a;
    }
} per[maxn];
int main(void)
{
    int n;
    while (~scanf ("%d",&n))
    {
        tot = 0;
        memset(sum,0,sizeof(sum));
        MAX = n;
        int max_age = 0,min_age = inf;
        for (int i = 1; i <= n; i++)
        {
            scanf ("%d%d%d",&per[i].s, &per[i].l, &per[i].a);
            age[i-1] = per[i].a;
            lev[i-1] = per[i].l;
            max_age = max(max_age,age[i-1]);
            min_age = min(min_age,age[i-1]);
        }
        sort(per+1, per+1+n);
        sort(age, age+n);
        sort(lev, lev+n);
        idx1 = n;
        idx2 = unique(lev,lev+n) - lev;
        tree[0] = build(1,n);
        for (int i = 1; i <= n; i++)
        {
            int tmp = lower_bound(lev,lev+idx2,per[i].l) - lev + 1;
            tree[i] = update(tree[i-1], tmp, 1, (ll)per[i].s);
        }
        int Q;
        ll k = 0;
        scanf ("%d",&Q);
        for (int i = 0; i < Q; i++)
        {
            ll LL,HL,LA,HA;
            scanf ("%I64d%I64d%I64d%I64d",&LL,&HL,&LA,&HA);
            LL += k, HL -= k;
            LA += k, HA -= k;
            if (LL > HL)
                swap(LL, HL);
            if (LA > HA)
                swap(LA, HA);
            LA = max(LA, (ll)0);
            HA = min(HA, (ll)1000000000);
            int idx_la = lower_bound(age,age+idx1,LA) - age + 1;
            int idx_ha = lower_bound(age,age+idx1,HA) - age + 1;
            if (age[idx_ha-1] == HA)
            {
                while (age[idx_ha-1] == HA && idx_ha <= n)
                    idx_ha ++;
                idx_ha--;
            }
            else
                idx_ha--;
            LL = max(LL,(ll)0);
            HL = min(HL,(ll)1000000000);
            int i1 = lower_bound(lev,lev+idx2,LL) - lev + 1;
            int i2 = lower_bound(lev,lev+idx2,HL) - lev + 1;
            if (lev[i2-1] > HL)
                i2--;
            k = query(tree[idx_la-1],tree[idx_ha],1,MAX,i1,i2);
            printf("%I64d\n",k);
        }
    }
    return 0;
}
