#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int dp[110][110];
int main()
{
    memset(dp, 0, sizeof(dp));
    for(int i=1; i<=100; i++)
    {
        dp[i][0] = dp[i][i-1] = 1;
    }
    for(int i=1; i<=100; i++)
    {
        for(int j=1; j<=100; j++)
        {
            dp[i][j] = (dp[i-1][j]*(j+1) + dp[i-1][j-1]*(i-j)) % 2009;
        }
    }
    int n,k;
    while(scanf("%d %d",&n,&k) != EOF)
    {
        cout<<dp[n][k]<<endl;
    }
    return 0;
}
