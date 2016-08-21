#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define N 1000002
#define INF 10000000
#define L(i) (i) << 1
#define R(i) (i) << 1 | 1
struct _st
{
    int l,r,Min;
    int mid()
    {
        return (l + r) >> 1;
    }
}st[N<<2];
void build(int id,int l,int r)
{
    st[id].l = l;
    st[id].r = r;
    st[id].Min = INF;
    if(l == r)
        return;
    int mid = st[id].mid();
    build(L(id),l,mid);
    build(R(id),mid+1,r);
}
int query(int id,int l,int r)
{
    if(st[id].l >= l && st[id].r <= r)
        return st[id].Min;
    int mid = st[id].mid();
    if(mid >= r)
        return query(L(id),l,r);
    else if(mid < l)
        return query(R(id),l,r);
    else
        return min(query(L(id),l,mid),query(R(id),mid+1,r));
}
void update(int id,int p,int val)
{
    if(st[id].l == st[id].r)
    {
        if(val < st[id].Min)
            st[id].Min = val;
        return ;
    }
    int mid = st[id].mid();
    if(mid >= p)
        update(L(id),p,val);
    else
        update(R(id),p,val);
    st[id].Min = min(st[L(id)].Min, st[R(id)].Min);
}
__int64 s[N];
int main()
{
    int cas = 0;
    int t,n,p,k,i,w;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&p,&k);
        build(1,0,p);
        for(i = 1; i <= n; ++i)
        {
            scanf("%d",&w);
            s[i] = s[i-1] + w;
        }
        __int64 res = -1;
        int id;
        for(i = 1; i <= n; ++i)
        {
            if(s[i] % p <= k)
                id = 0;
            else
                id = query(1,s[i] % p - k ,s[i] % p);
            if(id != INF)
                res = max(res,(s[i] - s[id])/p);
            update(1,s[i] % p,i);
        }
        printf("Case %d: %I64d\n",++cas,res);
    }
    return 0;
}
