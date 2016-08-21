#include<iostream>
#include<string.h>
using namespace std;
int dp[1001][3];
int main()
{
    int i,j,k,n;
    memset(dp,0,sizeof(dp));
    dp[1][0]=0;dp[1][1]=1;dp[1][2]=1;
    for(i=2;i<=1000;i++)
    {
        dp[i][0]+=dp[i-1][1]+dp[i-1][2];
        dp[i][0]=dp[i][0]%10000;
        dp[i][1]+=dp[i-1][0]+dp[i-1][2];
        dp[i][1]=dp[i][1]%10000;
        dp[i][2]+=dp[i-1][0]+dp[i-1][1];
        dp[i][2]=dp[i][2]%10000;
    }
    while(scanf("%d",&n))
    {
        if(n==0) break;
        cout<<dp[n][0]<<endl;
    }
    return 0;
}
