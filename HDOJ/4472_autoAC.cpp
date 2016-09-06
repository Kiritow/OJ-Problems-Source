#include <cstdio>
#include <cstring>
#define N 1010
#define MOD 1000000007
long long dp[N];
int n;
void DP()
{
    memset(dp,0,sizeof(dp));
    dp[1]=1; dp[2]=1;
    for(int i=3; i<=1000; i++)
        for(int j=1; j<=i-1; j++)
            if((i-1)%j == 0)
                dp[i] = (dp[i]+dp[j])%MOD;
}
int main()
{
    DP();
    int ccase=0;
    while(scanf("%d",&n)!=EOF)
    {
        printf("Case %d: %lld\n",++ccase,dp[n]);
    }
    return 0;
}
