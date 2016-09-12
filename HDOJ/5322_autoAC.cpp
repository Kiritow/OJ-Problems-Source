#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll Mod=998244353;
const ll g=3;
ll fp(ll a,ll k)
{
    ll res=1LL;
    while(k>0)
    {
        if(k&1)res=res*a%Mod;
        a=a*a%Mod;
        k>>=1;
    }
    return res;
}
ll f[100005],inv[100005];
void change(ll y[],int len)
{
    for(int i=1,j=len/2;i<len-1;i++)
    {
        if(i<j)swap(y[i],y[j]);
        int k=len/2;
        while(j>=k)
        {
            j-=k;
            k/=2;
        }
        if(j<k)j+=k;
    }
}
void ntt(ll y[],int len,int on)
{
    change(y,len);
    for(int h=2;h<=len;h<<=1)
    {
        ll wn=fp(g,(Mod-1)/h);
        if(on==-1)wn=fp(wn,Mod-2);
        for(int j=0;j<len;j+=h)
        {
            ll w=1LL;
            for(int k=j;k<j+h/2;k++)
            {
                ll u=y[k];
                ll t=w*y[k+h/2]%Mod;
                y[k]=(u+t)%Mod;
                y[k+h/2]=(u-t+Mod)%Mod;
                w=w*wn%Mod;
            }
        }
    }
    if(on==-1)
    {
        ll t=fp(len,Mod-2);
        for(int i=0;i<len;i++)
            y[i]=y[i]*t%Mod;
    }
}
ll dp[100005];
ll x1[200005],x2[200005];
void cdq(int l,int r)
{
    if(l==r)return;
    int m=(l+r)>>1;
    cdq(l,m);
    int len=1;
    while(len<=r-l+1)len<<=1;
    for(int i=0;i<len;i++)
    {
        x1[i]=(l+i<=m ? dp[l+i]*inv[l+i]%Mod : 0);
        x2[i]=(l+i<r ? 1LL*(i+1)*(i+1)%Mod : 0);
    }
    ntt(x1,len,1);
    ntt(x2,len,1);
    for(int i=0;i<len;i++)
        x1[i]=x1[i]*x2[i]%Mod;
    ntt(x1,len,-1);
    for(int i=m+1;i<=r;i++)
        dp[i]=(dp[i]+f[i-1]*x1[i-l-1]%Mod)%Mod;
    cdq(m+1,r);
}
void prepare()
{
    f[0]=1LL;
    for(int i=1;i<=100000;i++)
        f[i]=i*f[i-1]%Mod;
    for(int i=0;i<=100000;i++)
        inv[i]=fp(f[i],Mod-2)%Mod;
    dp[0]=1LL;
    cdq(0,100000);
}
int main()
{
    prepare();
    int n;
    while(scanf("%d",&n)!=EOF)printf("%I64d\n",dp[n]);
    return 0;
}
