#include <iostream>
#include <cstring>
#include <cstdio>
#include <math.h>
#include <cstdlib>
#include <queue>
#include <algorithm>
using namespace std;
#define N 1050
#define mod 100000007
int dp[N][N*2][2];
int main ()
{
        memset(dp,0,sizeof(dp));
        dp[1][1][0]=1;
        dp[1][2][1]=1;
        for(int i=1;i<=1000;++i)
        {
            for(int j=1;j<=2*i;++j)
            {
                dp[i+1][j][0]=(dp[i+1][j][0]+dp[i][j][0]+2*dp[i][j][1])%mod;
                dp[i+1][j+1][0]=(dp[i+1][j+1][0]+dp[i][j][1]+dp[i][j][0])%mod;
                dp[i+1][j][1]=(dp[i+1][j][1]+dp[i][j][1])%mod;
                dp[i+1][j+1][1]=(dp[i+1][j+1][1]+2*dp[i][j][0]+2*dp[i][j][1])%mod;
                dp[i+1][j+2][1]=(dp[i+1][j+2][1]+dp[i][j][0]+dp[i][j][1])%mod;
            }
        }
            int n,k;
    int t;scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        printf("%d\n",(dp[n][k][0]+dp[n][k][1])%mod);
    }
    return 0;
}
