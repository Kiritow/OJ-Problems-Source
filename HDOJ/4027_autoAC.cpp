#include <queue>
#include <stack>
#include <cmath>
#include <cstdio>
#include <stdlib.h>
#include <iostream>
#include <limits.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#define LL __int64
using namespace std;
const int N=100010;
struct Node
{
    int L,R;
    LL len;
    LL sum;
} t[N*4];
LL data[N];
int n,q;
void up(int fa){
    t[fa].sum=t[fa<<1].sum+t[fa<<1|1].sum;
}
void down(int l,int r,int fa)
{
    if(t[fa].L==t[fa].R)
    {
        t[fa].sum=(LL)(sqrt(t[fa].sum));
        return;
    }
    int ls=fa<<1;
    int rs=fa<<1|1;
    int mid=(t[fa].L+t[fa].R)/2;
    down(l,mid,ls);
    down(mid+1,r,rs);
    up(fa);
}
void built(int l,int r,int fa)
{
    t[fa].L=l;
    t[fa].R=r;
    t[fa].len=r-l+1;
    t[fa].sum=0LL;
    if(l==r)
    {
        t[fa].sum=data[l];
        return;
    }
    int mid=(l+r)/2;
    built(l,mid,fa<<1);
    built(mid+1,r,fa<<1|1);
    up(fa);
}
void update(int l,int r,int fa)
{
    int ls=fa<<1;
    int rs=fa<<1|1;
    int mid=(t[fa].L+t[fa].R)/2;
    if(t[fa].L==l&&t[fa].R==r)
    {
        if(t[fa].sum==t[fa].len)
            return ;
        down(l,r,fa);
            return ;
    }
    if(r<=mid)
        update(l,r,ls);
    else if(l>mid)
        update(l,r,rs);
    else
    {
        update(l,mid,ls);
        update(mid+1,r,rs);
    }
    up(fa);
}
LL query(int l,int r,int fa)
{
    int ls=fa<<1;
    int rs=fa<<1|1;
    int mid=(t[fa].L+t[fa].R)/2;
    if(t[fa].L>=l&&t[fa].R<=r)
        return t[fa].sum;
    if(r<=mid)
        return query(l,r,ls);
    else if(l>mid)
        return query(l,r,rs);
    else
        return query(l,mid,ls)+query(mid+1,r,rs);
}
int main()
{
    int t=1;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1; i<=n; i++)
        scanf("%I64d",&data[i]);
        built(1,n,1);
        int a,b,c;
        printf("Case #%d:\n",t++);
        cin>>q;
        while(q--)
        {
            scanf("%d%d%d",&a,&b,&c);
            if(b>c)swap(b,c);
            if(a)
                cout<<query(b,c,1)<<endl;
            else
                update(b,c,1);
        }
        cout<<endl;
    }
    return 0;
}
