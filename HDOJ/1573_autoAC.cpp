#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef __int64 ll;
ll n,k;
ll m[15],c[15],N;
bool check;
ll exgcd(ll a,ll b,ll &x,ll &y)
{
    if(!b)
    {
        x=1;
        y=0;
        return a;
    }
    else
    {
        ll res=exgcd(b,a%b,x,y);
        ll t=x;
        x=y;
        y=t-(a/b)*y;
        return res;
    }
}
ll mod(ll x,ll y)
{
    ll res=x%y;
    if(res<=0)
        res=res+y;
    return res;
}
void solve()
{
    ll i;
    check=true;
    ll ans=c[1],lcm=m[1],x,y,g;
    if(ans==0)
        ans=m[1];
    for(i=2;i<=n;i++)
    {
        g=exgcd(lcm,m[i],x,y);
        if((c[i]-ans)%g)
        {
            check=false;
            break;
        }
        ans=mod(ans+lcm*mod((c[i]-ans)/g*x,m[i]/g),lcm/g*m[i]);
        lcm=lcm/g*m[i];
    }
    if(check)
    {
        if(N>=ans)
        {
            printf("%I64d\n",(N-ans)/lcm+1);
        }
        else
        {
            printf("0\n");
        }
    }
    else
    {
        printf("0\n");
    }
}
int main()
{
    ll i,t;
    scanf("%I64d",&t);
    while(t--)
    {
        scanf("%I64d%I64d",&N,&n);
        for(i=1;i<=n;i++)
            scanf("%I64d",&m[i]);
        for(i=1;i<=n;i++)
            scanf("%I64d",&c[i]);
        solve();
    }
    return 0;
}
