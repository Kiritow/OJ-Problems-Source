#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
long long dp[1000001];
int main()
{
    int n,i,j;
    while(scanf("%d",&n)!=EOF)
    {
        memset(dp,0,sizeof(dp)); dp[0]=1;
        for(i=1;i<=n;i*=2)
        {
            for(j=i;j<=n;j++)
            {
                dp[j]+=dp[j-i];
                dp[j]%=1000000000;
            }
        }
        printf("%lld\n",dp[n]);
    }
    return 0;
}
