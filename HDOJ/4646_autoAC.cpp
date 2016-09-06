#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#define ll long long
using namespace std;
ll t,n;
map<ll,ll> g;
ll f(ll x)
{
    if (x%2==0) return 2*(x/6+1)-1;
        else return 2*((x-3)/6+1);
}
ll get(ll x)
{
    if (g[x]!=0) return g[x];
    g[x]=f(x);
    for (ll i=2; i*i<=x; i++)
    {
        if (x%i>0) continue;
        g[x]-=get(i);
        if (i*i!=x)
        {
            g[x]-=get(x/i);
        }
    }
    return g[x];
}
int main()
{
    scanf("%I64d",&t);
    while (t--)
    {
        scanf("%I64d",&n);
        if (n%3==0)
        {
            printf("0\n");
            continue;
        }
        if ((n&1)==0)
        {
            printf("0\n");
            continue;
        }
        if (n==1)
        {
            printf("1\n");
            continue;
        }
        if (n==3)
        {
            printf("0\n");
            continue;
        }
        n=(n+3)>>1;
        printf("%I64d\n",get(n));
    }
    return 0;
}
