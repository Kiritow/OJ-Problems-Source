#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define mod 1000000009
#define LL __int64
#define maxn 100000+5
LL f[maxn];
void set()
{
    int i;
    f[0] = 1;
    for(i = 1; i<maxn; i++)
        f[i] = (f[i-1]*i)%mod;
}
LL quickmod(LL a,LL b)
{
    LL ans = 1;
    while(b)
    {
        if(b&1)
        {
            ans = (ans*a)%mod;
            b--;
        }
        b/=2;
        a = ((a%mod)*(a%mod))%mod;
    }
    return ans;
}
int main()
{
    int n,m,i,j,k,l,r,x,ll,rr;
    set();
    while(~scanf("%d%d",&n,&m))
    {
        l = r = 0;
        for(i = 0; i<n; i++)
        {
            scanf("%d",&x);
            if(l>=x) ll = l-x;
            else if(r>=x) ll = ((l%2)==(x%2))?0:1;
            else ll = x-r;
            if(r+x<=m) rr = r+x;
            else if(l+x<=m) rr = (((l+x)%2) == (m%2)?m:m-1);
            else rr = 2*m-(l+x);
            l = ll,r = rr;
        }
        LL sum = 0;
        for(i = l; i<=r; i+=2)
            sum+=((f[m]%mod)*(quickmod((f[i]*f[m-i])%mod,mod-2)%mod))%mod;
        printf("%I64d\n",sum%mod);
    }
    return 0;
}
