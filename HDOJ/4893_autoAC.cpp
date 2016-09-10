#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define ll __int64
#define maxn 100005
#define ls l,mid,2*i
#define rs mid+1,r,2*i+1
#define lson 2*i
#define rson 2*i+1
struct node
{
    int l,r;
    ll e,f;
    int flag,len;
} a[maxn<<2];
int n,m;
ll f[90] = {1,1};
ll pabs(ll a)
{
    return a<0?-a:a;
}
void PushDown(int i,int m)
{
    if(a[i].flag)
    {
        a[lson].flag = a[rson].flag = a[i].flag;
        a[lson].len = a[i].flag*(m-m>>1);
        a[rson].len = a[i].flag*(m>>1);
        a[lson].e = a[lson].f;
        a[rson].e = a[rson].f;
        a[i].flag = 0;
    }
}
void PushUp(int i)
{
    a[i].e = a[lson].e+a[rson].e;
    a[i].f = a[lson].f+a[rson].f;
}
void init(int l,int r,int i)
{
    a[i].flag = a[i].len = 0;
    a[i].l = l;
    a[i].r = r;
    a[i].e = 0;
    if(l == r)
    {
        a[i].f = 1;
        return;
    }
    int mid = (l+r)>>1;
    init(ls);
    init(rs);
    PushUp(i);
}
void add(int pos,int m,int l,int r,int i)
{
    if(pos<l || pos>r) return ;
    if(l == r)
    {
        if(a[i].flag)
        {
            a[i].e = m+a[i].f;
            a[i].flag = 0;
            a[i].len = 0;
        }
        else a[i].e+=m;
        int p = lower_bound(f,f+80,a[i].e)-f;
        if(!p)
            a[i].f = 1;
        else if(pabs(a[i].e-f[p])<pabs(a[i].e-f[p-1]))
            a[i].f = f[p];
        else
            a[i].f = f[p-1];
        return ;
    }
    PushDown(i,r-l+1);
    int mid = (l+r)>>1;
    if(pos<=mid) add(pos,m,ls);
    else add(pos,m,rs);
    PushUp(i);
}
ll query(int L,int R,int l,int r,int i)
{
    if(R<l || L>r) return 0;
    else if(L<=l && R>=r) return a[i].e;
    PushDown(i,r-l+1);
    ll ans = 0;
    int mid = (l+r)>>1;
    if(L<=mid)
        ans += query(L,R,ls);
    if(R>mid)
        ans += query(L,R,rs);
    return ans;
}
void change(int L,int R,int l,int r,int i)
{
    if(R<l || L>r) return ;
    if(L<=l && R>=r)
    {
        a[i].e = a[i].f;
        a[i].flag = 1;
        a[i].len = r-l+1;
        return ;
    }
    PushDown(i,r-l+1);
    int mid = (l+r)>>1;
    if(L<=mid)
        change(L,R,ls);
    if(R>mid)
        change(L,R,rs);
    PushUp(i);
}
int main()
{
    int i,j,x,k,d,l,r;
    for(i = 2; i<80; i++)
        f[i] = f[i-1]+f[i-2];
    while(~scanf("%d%d",&n,&m))
    {
        init(1,n,1);
        while(m--)
        {
            scanf("%d",&x);
            if(x == 1)
            {
                scanf("%d%d",&k,&d);
                add(k,d,1,n,1);
            }
            else
            {
                scanf("%d%d",&l,&r);
                if(x == 2)
                    printf("%I64d\n",query(l,r,1,n,1));
                else
                    change(l,r,1,n,1);
            }
        }
    }
    return 0;
}
