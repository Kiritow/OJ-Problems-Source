#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
const int mod=1000000007;
__int64 n,c;
__int64 fun(__int64 a,__int64 b)
{
    __int64 t=1,y=a;
    for(int i=1;i<=b;i*=2)
    {
        if(b&i)
          t=t*y%mod;
        y=y*y%mod;
    }
    return t;
}
__int64 euler(__int64 a)
{
    __int64 ans=a;
    for(int i=2;i<=a;i++)
    {
        if(a%i==0)
            ans-=ans/i;
        while(a%i==0)
            a/=i;
    }
    if(a>1)
        ans-=ans/a;
    return ans;
}
__int64 Extend_euclid(__int64 a,__int64 b,__int64 &x,__int64 &y)
{
    __int64 d=0,t=0;
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    else
    {
        d=Extend_euclid(b,a%b,x,y);
        t=x;
        x=y;
        y=t-a/b*y;
    }
    return d;
}
__int64 Bignum_Div(__int64 a,__int64 b)
{
    __int64 x=0,y=0;
    Extend_euclid(b,mod,x,y);
    __int64 ans= a*x%mod;
    while(ans<0)
        ans+=mod;
    return ans;
}
int main()
{
    __int64 ans=0,t=1,T=0;
    scanf("%I64d",&T);
    while(T--)
    {
        scanf("%I64d %I64d",&c,&n);
        ans=0;
        for(int i=1;i<=n;i++)
        {
            if(n%i==0)
            {
                ans+=fun(c,i)*euler(n/i);
                ans%=mod;
            }
        }
        if(n&1)
        {
            ans+=n*fun(c,n/2+1);
            ans%=mod;
        }
        else
        {
            ans+=n/2*( fun(c,n/2)+fun(c,n/2+1));
            ans%=mod;
        }
        ans=Bignum_Div(ans,2*n);
        printf("Case #%I64d: %I64d\n",t++,ans);
    }
    return 0;
}
