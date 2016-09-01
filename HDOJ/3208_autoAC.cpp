#include<stdio.h>
#include<string.h>
#include<math.h>
#include<iostream>
#define ll __int64
#define inf (ll) 1e18+300
#define eps 1e-9
using namespace std;
ll why=(ll)1<<31;
ll num[100];
ll quickpow(ll m,int n)
{
    ll b=1;int k=n;
    while (n>0)
    {
        if (n&1)
        {
            double judge=1.0*(inf)/b;
            if (judge<m) return -1;
            b*=m;
        }
        n=n>>1;
        if (m>why&&n>0) return -1;
        m=m*m;
    }
    return b;
}
ll find(ll x,int k)
{
    ll l=1,r=(ll)pow(x,1.0/k);
    ll tt,pp,qq;
    pp=quickpow(r,k);
    if (pp==x) return r;
    if (pp>x||pp==-1) --r;
    else
    {
        tt=quickpow(r+1,k);
        if (tt!=-1&&tt<=x) ++r;
    }
    return r;
}
ll f(ll x)
{
    int i,j,k;
    ll ans=0;
    if (x<=3) return x;
    memset(num,0,sizeof(num));
    num[1]=x;
    for (i=2;i<63;++i)
    {
        num[i]=find(x,i)-1;
        if (!num[i]) break;
    }
    k=i;
    for (i=k-1;i>0;--i)
    {
        for (j=1;j<i;++j)
            if (i%j==0) num[j]-=num[i];
    }
    ans=num[1];
    for (i=2;i<k;++i)
    {
        ans+=(i*num[i]);
    }
    return ans;
}
int main ()
{
    ll a,b;
    while (scanf("%I64d%I64d",&a,&b)&&(a+b))
    {
        printf("%I64d\n",f(b)-f(a-1));
    }
    return 0;
}
