#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
using namespace std;
typedef unsigned __int64 u64;
const int MAX=100;
u64 f0[100],f1[100],ff,n,tmp,ret,ret1,p,pp;
u64 myrandom()
{
    u64 a;
    a=rand();
    a*=rand();
    a*=rand();
    a*=rand();
    return a;
}
u64 mulmod(u64 a,u64 b,u64 c)
{
    u64 ret=0;
    while(b)
    {
        if(b&1)
        {
            ret+=a;
            if(ret>c)
                ret-=c;
        }
        a<<=1;
        if(a>c)
            a-=c;
        b>>=1;
    }
    return ret;
}
u64 powmod(u64 a,u64 b,u64 c)
{
    u64 ret=1;
    while(b)
    {
        if(b&1)
            ret=mulmod(ret,a,c);
        a=mulmod(a,a,c);
        b>>=1;
    }
    return ret;
}
int miller(u64 base,u64 n)
{
    u64 m=n-1,k=0;
    while(m%2==0)
    {
        m>>=1;
        k++;
    }
    if(powmod(base,m,n)==1)
        return 1;
    for(int i=0;i<k;i++)
    {
        if(powmod(base,m<<i,n)==n-1)
            return 1;
    }
    return 0;
}
int Miller_Rabin(u64 n)
{
    for(int i=2;i<100;++i)
        if(n%i==0)
            if(n==i)
                return 1;
            else return 0;
    for( int i=0;i<MAX;++i)
    {
        u64 base=myrandom()%(n-1)+1;
        if(!miller(base,n))
            return 0;
    }
    return 1;
}
u64 gcd(u64 a, u64 b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
u64 f(u64 a,u64 b)
{
    return (mulmod(a,a,b)+1)%b;
}
u64 Pollard_Rho(u64 n)
{
    if(n<=2) return 0;
    for(u64 i=2;i<100;++i)
        if(n%i==0)
            return i;
    u64 p,x,xx;
    for( int i=1;i<MAX;i ++)
    {
        x=myrandom()%n;
        xx=f(x,n);
        p=gcd((xx+n-x)%n,n);
        while(p==1)
        {
            x=f(x,n);
            xx=f(f(xx,n),n);
            p=gcd((xx+n-x)%n,n)%n;
        }
        if(p) return p;
    }
    return 0;
}
u64 Prime(u64 a)
{
    if(Miller_Rabin(a)) return 0;
    u64 t=Pollard_Rho(a);
    u64 p=Prime(t);
    if(p) return p;
    return t;
}
int main()
{
    int tt;
    scanf("%d",&tt);
    while(tt--)
    {
        scanf("%I64d %I64d",&n,&p);
        pp=p*2;
        u64 old=n%pp;
        ret=1,ret1=1,ff=0;
        while(n>1)
        {
            if(Miller_Rabin(n)) 
                break;
            tmp=Prime(n);
            f0[ff]=tmp;
            f1[ff]=1;
            n/=tmp;
            while(n%tmp==0)
            {
                n/=tmp;
                f1[ff]++;
            }
            ff++;
        }
        if(n>0)
        {
            f0[ff]=n;
            f1[ff++]=1;
        }
        for(int i=0;i<ff;++i)
        {
            u64 tmp=1;
            for(int j=0;j<f1[i];++j)
                tmp=tmp*f0[i];
            ret1=ret1*(f1[i]*(tmp-tmp/f0[i])+tmp);
            ret1=ret1%p;
            tmp=1;
            for(int j=0;j<2*f1[i]+1;++j)
                tmp=tmp*f0[i];
            ret=ret*((tmp+1)/(1+f0[i]));
            ret=ret%pp;
        }
        ret=((old*(ret+1))%pp)/2;
        if(ret==ret1)
            printf("yes\n");
        else 
            printf("no\n");
    }
    return 0;
}
