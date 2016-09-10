#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
#define LL __int64
const int maxn=5e5+20;
LL mod;
LL val[maxn],dp[maxn];
void fun(int n)
{
    for(LL i=1;i<n;i++)
    {
        for(LL j=i;j<n;j+=i)
        {
            val[j]+=(j/i+1)*(j/i)/2;
        }
    }
}
void init()
{
    mod=1;
    mod=(mod<<32);
    memset(val,0,sizeof(val));
    fun(maxn);
    dp[1]=1;
    for(LL i=2;i<maxn;i++)
    {
        dp[i]=dp[i-1]+val[i]*i;
        dp[i]=dp[i]%mod;
    }
}
int main()
{
    init();
    int n,tt=0,T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        printf("Case #%d: %I64d\n",++tt,dp[n]);
    }
    return 0;
}
