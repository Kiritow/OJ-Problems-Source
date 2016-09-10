#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define LL 100005
#define ll __int64
#define lson 2*i
#define rson 2*i+1
#define ls l,mid,2*i
#define rs mid+1,r,2*i+1
struct node
{
    int l,r;
    ll num,maxn;
} a[LL<<2];
int n,m;
ll gcd(ll a,ll b)
{
    if(!b) return a;
    else return gcd(b,a%b);
}
void PushUp(int i)
{
    a[i].num=(a[lson].num==a[rson].num)?a[lson].num:-1;
    a[i].maxn=max(a[lson].maxn,a[rson].maxn);
}
void PushDown(int i)
{
    if(a[i].num>-1)
    {
        a[lson].num = a[rson].num = a[i].num;
        a[lson].maxn = a[rson].maxn = a[i].maxn;
    }
}
void init(int l,int r,int i)
{
    a[i].l = l;
    a[i].r = r;
    if(l == r)
        scanf("%I64d",&a[i].num);
    else
    {
        int mid = (l+r)>>1;
        init(ls);
        init(rs);
        PushUp(i);
    }
}
void change1(int L,int R,ll x,int i)
{
    int l = a[i].l,r = a[i].r;
    if(L<=l && r<=R)
    {
        a[i].num = x;
        a[i].maxn = x;
    }
    else
    {
        int mid = (l+r)>>1;
        PushDown(i);
        if(mid>=R)
            change1(L,R,x,lson);
        else if(mid<L)
            change1(L,R,x,rson);
        else
        {
            change1(L,R,x,lson);
            change1(L,R,x,rson);
        }
        PushUp(i);
    }
}
void change2(int L,int R,ll x,int i)
{
    int l = a[i].l,r = a[i].r;
    if(a[i].maxn<=x) return ;
    if(L<=l && r<=R)
    {
        if(a[i].num>-1)
        {
            a[i].num = gcd(a[i].num,x);
            a[i].maxn = a[i].num;
        }
        else
        {
            PushDown(i);
            change2(L,R,x,lson);
            change2(L,R,x,rson);
            PushUp(i);
        }
    }
    else
    {
        int mid = (l+r)>>1;
        PushDown(i);
        if(mid>=R)
            change2(L,R,x,lson);
        else if(mid<L)
            change2(L,R,x,rson);
        else
        {
            change2(L,R,x,lson);
            change2(L,R,x,rson);
        }
          PushUp(i);
    }
}
void print(int l,int r,int i)
{
    if(a[i].num>-1)
        for(int j = l; j<=r; j++)
            printf("%I64d ",a[i].num);
    else
    {
        int mid = (l+r)>>1;
        print(ls);
        print(rs);
    }
}
int main()
{
    int t,l,r,cas;
    __int64 x;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        init(1,n,1);
        scanf("%d",&m);
        while(m--)
        {
            scanf("%d%d%d%I64d",&cas,&l,&r,&x);
            if(cas == 1) change1(l,r,x,1);
            else change2(l,r,x,1);
        }
        print(1,n,1);
        printf("\n");
    }
}
