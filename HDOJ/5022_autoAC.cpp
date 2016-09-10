#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long int64;
int64 v[210000],tx[210000],ty[210000],rk[210000],a,b,c,d,s,t,P,pp,x,y,sp,gg,tot,rs,ans,cnt;
int64 gcd(int64 a,int64 b)
{
    x=1,y=0;
    if(!b) return a;
    int64 d=gcd(b,a%b);
    int64 xx=x; x=y; y=xx-a/b*y;
    return d;
}
int64 qpow(int64 a,int64 b,int64 c)
{
    int64 res=1;
    for(;b;b>>=1,a=a*a%c)
      if(b&1) res=res*a%c;
    return res;
}
int64 dt2(int64 a)
{
    int l=1,r=cnt,mid;
    while(l+1<r)
    {
        mid=(l+r)>>1;
        if(tx[rk[mid]]<a) l=mid;
        else r=mid;
    }
    if(tx[rk[l]]==a) return ty[rk[l]];
    if(tx[rk[r]]==a) return ty[rk[r]];
    return 0;
}
int64 dlog(int64 a)
{
    for(int i=0;i<=sp;++i)
    {
        int64 k=dt2(a*qpow(gg,i,P)%P);
        if(!k) continue;
        return (k-i+pp)%pp;
    }
    return -1;
}
bool ok(int64 a)
{
    for(int i=1;i<=tot;++i)
      if(qpow(a,pp/v[i],P)==1) return 0;
    return 1;
}
int64 getpg(int64 a)
{
    for(int i=2;i<=a-1;++i)
      if(ok(i)) return i;
    return -1;
}
int64 t2(int64 a)
{
    int l=1,r=tot,mid;
    while(l+1<r)
    {
        mid=(l+r)>>1;
        if(v[mid]<a) l=mid;
        else r=mid;
    }
    if(v[l]>=a) return v[l];
    return v[r];
}
int64 solve(int64 a,int64 b,int64 P,int64 t)
{
    a=(a+P)%P; b=(b+P)%P; tot=0; int64 sp=0,ans=b;
    for(;(sp+1)*(sp+1)<=t;++sp);
    for(int i=0;sp*sp+i<=t;++i)
      ans=min(ans,(a*(sp*sp+i)+b)%P);
    if(!sp) return ans;
    for(int i=1;i<=sp;++i) v[++tot]=(a*sp*i+b)%P;
    sort(v+1,v+tot+1);
    for(int i=0;i<=sp;++i)
    {
        int64 x=a*i%P;
        ans=min(ans,(v[1]+P-x)%P);
        ans=min(ans,(t2(x)-x+P)%P);
    }
    return ans;
}
bool cmp(int a,int b)
{
    return tx[a]<tx[b];
}
int main()
{
    while(scanf("%I64d%I64d%I64d%I64d%I64d%I64d",&c,&a,&b,&s,&t,&P),P)
    {
        tot=0; pp=P-1;
        for(sp=1;sp*sp<=pp;++sp);
        for(int i=2;i*i<=pp;++i)
        {
            if(pp%i) continue;
            v[++tot]=i; while(pp%i==0) pp/=i;
        }
        if(pp>1) v[++tot]=pp; pp=P-1;
        gg=getpg(P); cnt=0;
        for(int i=1;i<=sp;++i) tx[++cnt]=qpow(gg,sp*i,P),ty[cnt]=sp*i,rk[cnt]=cnt;
        sort(rk+1,rk+cnt+1,cmp);
        a=dlog(a); b=dlog(b); c=dlog(c);
        a=(pp-a)%pp; c=(c-b*s%pp+pp)%pp; t-=s;
        d=gcd(pp,gcd(a,b));
        if(c%d)
        {
            printf("impossible\n"); continue;
        }
        a/=d; b/=d; c/=d; pp/=d; d=gcd(pp,a);
        gcd(b,d); x=(x%d+d)%d; rs=c*x%d;
        if(t<rs)
        {
            printf("impossible\n"); continue;
        }
        t=(t-rs)/d; c=(c-rs*b)/d; a/=d; pp/=d;
        gcd(a,pp); b=(pp-b*x%pp)%pp; c=(pp+c*x%pp)%pp;
        ans=solve(b,c,pp,t);
        printf("%I64d\n",ans);
    }
    return 0;
}
