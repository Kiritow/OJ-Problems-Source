#include<stdio.h>
typedef __int64 ll;
ll mod=100000000;
ll m[205];
ll eular(ll n)
{
    ll i,ret=1;
    for(i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            n=n/i;
            ret=ret*(i-1);
            while(n%i==0)
            {
                n=n/i;
                ret=ret*i;
            }
        }
        if(n==1)
            break;
    }
    if(n>1)
        ret=ret*(n-1);
    return ret;
}
void init()
{
    ll i;
    m[1]=mod;
    for(i=2;i<=204;i++)
        m[i]=eular(m[i-1]);
}
ll power(ll a,ll b,ll c)
{
    ll res=1;
    while(b)
    {
        if(b%2==1)  
            res=res*a%c;
        a=(a%c)*(a%c)%c;
        b=b/2;
    }
    return res;
}
int main()
{
    ll a,k,i,ans;
    init();
    while(scanf("%I64d%I64d",&a,&k)!=EOF)
    {
        ans=a;
        if(a==0&&k%2==0)
        {
            printf("1\n");
            continue;
        }
        for(i=k;i>=2;i--)
        {
            ans=ans%m[i];
            if(ans==0)
                ans=m[i];
            ans=power(a,ans,m[i-1]);
        }
        printf("%I64d\n",ans%mod);
    }
    return 0;
}
