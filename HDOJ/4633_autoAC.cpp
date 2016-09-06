#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
typedef long long LL;
const LL MOD=10007;
LL quick_mod(LL a,LL b)
{
    LL ans=1;
    a%=MOD;
    while(b)
    {
        if(b&1)
        {
            ans=ans*a%MOD;
            b--;
        }
        b>>=1;
        a=a*a%MOD;
    }
    return ans;
}
int main()
{
    LL tt=1,t,k,ans;
    cin>>t;
    while(t--)
    {
        cin>>k;
        ans=quick_mod(k,74);
        ans+=3*(2*quick_mod(k,20)+quick_mod(k,38))%MOD;
        ans+=6*quick_mod(k,38);
        ans+=8*quick_mod(k,26);
        ans%=MOD;
        ans*=quick_mod(24,MOD-2);
        ans%=MOD;
        printf("Case %I64d: %I64d\n",tt++,ans);
    }
    return 0;
}
