#include <stdio.h>
#include <iostream>
using namespace std;
#define maxn 101000
#define ll long long
ll A[maxn],inv[maxn];
ll mod;
ll Pow(ll a,ll b)
{
    ll ret=1;
    a%=mod;
    while(b)
    {
        if(b&1) ret=ret*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ret%mod;
}
void init()
{
    A[0]=1,A[1]=1;
    inv[1]=1;inv[0]=1;
    for(int i=2;i<maxn;i++)
    {A[i]=A[i-1]*(ll)i%mod;inv[i]=Pow(A[i],mod-2);}
}
ll C(ll a,ll b)
{
    if(a<b) return 0;
    if(a<mod&&b<mod) return (A[a]*inv[b]%mod)*inv[a-b]%mod;
    return C(a/mod,b/mod)*C(a%mod,b%mod)%mod;
}
int main()
{
    ll x,xx,y,yy;
    while(scanf("%lld%lld%lld%lld%lld",&x,&y,&xx,&yy,&mod)!=EOF)
    {
        init();
        ll ans=0;
        if(y>x&&yy>xx&&y>xx) {printf("0\n");continue;}
        if(y>x) x=y;
        if(yy>xx) yy=xx;
        ll st=x,en=xx,h=y;
        while(h<=yy&&st<=en)
        {
            if(st<h) st=h;
            ans=(ans+C(en+1,h+1)-C(st,h+1)+mod)%mod;
            h++;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
