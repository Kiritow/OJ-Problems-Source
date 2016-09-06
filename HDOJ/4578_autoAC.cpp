#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define lz 2*u,l,mid
#define rz 2*u+1,mid+1,r
typedef long long lld;
const int maxn=100005;
const int mod=10007;
lld add[4*maxn], mul[4*maxn], ch[4*maxn], sum[4*maxn];
void build(int u, int l, int r)
{
    mul[u]=1;
    add[u]=sum[u]=0;
    ch[u]=0;
    if(l==r)
    {
        ch[u]=1;
        return ;
    }
    int mid=(l+r)>>1;
    build(lz);
    build(rz);
}
void push_down(int u, int l, int r)
{
    if(l==r) return ;
    int mid=(l+r)>>1;
    if(ch[u])
    {
        add[2*u]=0, mul[2*u]=1;
        add[2*u+1]=0, mul[2*u+1]=1;
        ch[2*u]=ch[2*u+1]=1;
        sum[2*u]=sum[2*u+1]=sum[u];
        ch[u]=0;
    }
    else
    {
        if(add[u])
        {
            if(ch[2*u]) sum[2*u]=(sum[2*u]+add[u])%mod;
            else
            {
                push_down(lz);
                add[2*u]=(add[2*u]+add[u])%mod;
            }
            if(ch[2*u+1]) sum[2*u+1]=(sum[2*u+1]+add[u])%mod;
            else
            {
                push_down(rz);
                add[2*u+1]=(add[2*u+1]+add[u])%mod;
            }
            add[u]=0;
        }
        if(mul[u]>1)
        {
            if(ch[2*u]) sum[2*u]=(sum[2*u]*mul[u])%mod;
            else
            {
                push_down(lz);
                mul[2*u]=(mul[2*u]*mul[u])%mod;
            }
            if(ch[2*u+1]) sum[2*u+1]=(sum[2*u+1]*mul[u])%mod;
            else
            {
                push_down(rz);
                mul[2*u+1]=(mul[2*u+1]*mul[u])%mod;
            }
            mul[u]=1;
        }
    }
}
void Update(int u, int l, int r, int tl, int tr, int c, int op)
{
    if(tl<=l&&r<=tr)
    {
        if(op==3)
        {
            ch[u]=1;
            mul[u]=1, add[u]=0;
            sum[u]=c;
        }
        else
        {
            if(ch[u])
            {
                if(op==1) sum[u]=(sum[u]+c)%mod;
                else   sum[u]=sum[u]*c%mod;
            }
            else
            {
                push_down(u,l,r);
                if(op==1) add[u]=(add[u]+c)%mod;
                else mul[u]=mul[u]*c%mod;
            }
        }
        return ;
    }
    push_down(u,l,r);
    int mid=(l+r)>>1;
    if(tr<=mid) Update(lz,tl,tr,c,op);
    else if(tl>mid) Update(rz,tl,tr,c,op);
    else
    {
        Update(lz,tl,mid,c,op);
        Update(rz,mid+1,tr,c,op);
    }
}
lld Query(int u, int l, int r, int tl, int tr, int p)
{
    if(tl<=l&&r<=tr)
    {
        if(ch[u])
        {
            lld ans=1, tp=sum[u];
            for(int i=1; i<=p; i++) ans=ans*tp%mod;
            return (r-l+1)*ans%mod;
        }
    }
    push_down(u,l,r);
    int mid=(l+r)>>1;
    if(tr<=mid) return Query(lz,tl,tr,p);
    else if(tl>mid) return Query(rz,tl,tr,p);
    else
    {
        lld t1=Query(lz,tl,mid,p);
        lld t2=Query(rz,mid+1,tr,p);
        return (t1+t2)%mod;
    }
}
int main()
{
    int n, m;
    while(cin >> n >> m, n+m)
    {
        build(1,1,n);
        for(int i=1; i<=m; i++)
        {
            int l, r, c, op;
            scanf("%d%d%d%d",&op,&l,&r,&c);
            if(op<=3) Update(1,1,n,l,r,c,op);
            else printf("%I64d\n",Query(1,1,n,l,r,c)%mod);
        }
    }
    return 0;
}
