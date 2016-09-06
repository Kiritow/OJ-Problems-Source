#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#define maxn 5000500
#define M 1000000007
#define ll long long
using namespace std;
ll f[maxn];
ll count(ll x)
{
    ll tot=0;
    for (int i=1; i<=x/3; i++)
    {
        int tep=x-i;
        if (tep/2>=max(i,(tep-i)/2+1))
        {
            tot=(tot+tep/2-max(i,(tep-i)/2+1)+1);
            if (tot>=M) tot-=M;
        }
    }
    return tot;
}
ll get(ll x) 
{
    if (f[x]!=0) return f[x];
    ll tot=0;
    for (int i=3; i<=x/2; i++)
        if (x%i==0)
        {
            tot=(tot+get(i));
            if (tot>=M) tot-=M;
        }
    f[x]=count(x)-tot;
    if (f[x]<0) f[x]+=M;
    return f[x];
}
ll power(ll x,ll y)
{
    ll tot=1;
    while (y)
    {
        if (y&1) tot=(tot*x)%M;
        x=(x*x)%M;
        y>>=1;
    }
    return tot;
}
int main()
{
    ll n,ans,tep,cas=0;
    while (scanf("%I64d",&n)!=EOF)
    {
        ans=0;
        for (int i=1; i*i<=n; i++)
        {
            if (n%i==0)
            {
                tep=get(i); 
                tep=(tep*power(2,n/i-1))%M;
                ans+=tep;
                if (ans>=M) ans-=M;
                if (i*i!=n)
                {
                    tep=get(n/i);
                    tep=(tep*power(2,i-1))%M;
                    ans+=tep;
                    if (ans>=M) ans-=M;
                }
            }
        }
        printf("Case %I64d: %I64d\n",++cas,ans);
    }
    return 0;
}
