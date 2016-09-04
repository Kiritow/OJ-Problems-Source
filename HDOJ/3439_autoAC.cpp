#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
const int maxn=100005;
ll n,k,m;
ll f1[2*maxn],f2[maxn],c[maxn],mul[maxn],num[maxn],tot;
ll cp()
{
    f1[0]=1%m;f1[1]=0;
    ll i;
    for(i=2;i<=2*m;++i)
        f1[i]=(((f1[i-1]+f1[i-2])%m)*(i-1))%m;
    return f1[(n-k)%(2*m)];
}
void prem()
{
    ll i,mm;
    mm=m;
    tot=0;
    for(i=2;i*i<=mm;++i)
    {
        if(mm%i==0)
        {
            c[tot]=i;mul[tot]=1;num[tot]=0;
            while(mm%i==0)
            {
                mul[tot]*=i;
                num[tot]++;
                mm/=i;
            }
            tot++;
        }
    }
    if(mm!=1)
    {
        c[tot]=mm;mul[tot]=mm;num[tot]=1;
        tot++;
    }
}
ll quickpow(ll a,ll b,ll c)
{
    ll ret=1;
    while(b)
    {
        if(b&1)
        {
            (ret*=a)%=c;
        }
        (a*=a)%=c;
        b>>=1;
    }
    return ret%c;
}
void ex_gcd(ll a,ll b,ll &x,ll &y)
{
    if(b==0)
    {
        x=1;y=0;
        return ;
    }
    ex_gcd(b,a%b,x,y);
    ll t=x;
    x=y;
    y=t-(a/b)*y;
}
ll count(ll a,ll p)
{
    if(a<p)
        return 0;
    else
        return a/p+count(a/p,p);
}
ll count2(ll a,ll p,ll mp)
{
    if(a<p)
        return f2[a];
    return ((f2[a%mp]*quickpow(f2[mp-1],a/mp,mp))%mp*count2(a/p,p,mp))%mp;
}
ll work1(ll id)
{
    ll p=c[id];ll mp=mul[id];ll nm=num[id];
    ll t1;
    t1=count(n,p)-count(k,p)-count(n-k,p);
    if(t1>=nm)
        return 0;
    ll ret=quickpow(p,t1,mp);
    ll i,x,y;
    f2[0]=1;
    for(i=1;i<=mp;++i)
    {
        f2[i]=f2[i-1];
        if(i%p!=0)
            f2[i]*=i;
        f2[i]%=mp;
    }
    ex_gcd(count2(k,p,mp)*count2(n-k,p,mp),mp,x,y);
    (ret*=x)%=mp;
    (ret*=count2(n,p,mp))%=mp;
    return ret;
}
ll work()
{
    ll i,ret=0,tmp,x,y;
    prem();
    for(i=0;i<tot;++i)
    {
        tmp=work1(i);
        ex_gcd(m/mul[i],mul[i],x,y);
        ret+=(((m/mul[i])%m*x)%m*tmp)%m;
    }
    ret=(ret%m+m)%m;
    return (ret*cp())%m;
}
int main()
{
    int t,cas=0;
    scanf("%d",&t);
    while(t--)
    {
        cas++;
        scanf("%I64d%I64d%I64d",&n,&k,&m);
        printf("Case %d: %I64d\n",cas,work());
    }
    return 0;
}
