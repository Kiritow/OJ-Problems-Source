#include <iostream>
#include <string.h>
using namespace std;
int dp[1005][16][16];
int main()
{
    int w[1005];
    int b[1005];
    int sum=1;
    while (cin>>w[sum]>>b[sum])
        sum++;
    memset(dp,0,sizeof(dp));
    for (int i=1;i<sum;i++)
    {
        for (int t=0;t<=i&&t<=15;t++)
        {
            for (int k=0;k<=15&&k<=i-t;k++)
            {
                dp[i][t][k]=dp[i-1][t][k];
                if (t>0&&dp[i][t][k]<dp[i-1][t-1][k]+w[i])
                    dp[i][t][k]=dp[i-1][t-1][k]+w[i];
                if (k>0&&dp[i][t][k]<dp[i-1][t][k-1]+b[i])
                    dp[i][t][k]=dp[i-1][t][k-1]+b[i];
            }
        }
    }   
    cout<<dp[sum-1][15][15]<<endl;
}
