#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;
long long gcd(long long a,long long b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
long long Pow(long long a,long long b,long long mod)
{
    long long ans=1;
    while(b)
    {
        if(b&1)
        {
            b--;
            ans=(ans*a)%mod;
        }
        else
        {
            b/=2;
            a=(a*a)%mod;
        }
    }
    return ans;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long a,m,n,k;
        scanf("%I64d%I64d%I64d%I64d",&a,&m,&n,&k);
        printf("%I64d\n",(Pow(a,gcd(m,n),k)+k-1)%k);
    }
    return 0;
}
