#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int s[1005];
int dp[1005][1005];
int max(int a,int b)
{
    return a>b?a:b;
}
int main()
{
    int n;
    while (cin>>n&&n)
    {
        memset(dp,0,sizeof(dp));
        for (int i=1;i<=n;i++)
            cin>>s[i];
        for (int l=1;l<=n;l++)
        {
            for (int i=1;i+l-1<=n;i++)
            {
                int j=i+l-1;
                int p=2;
                if (i==j)
                    p=1;
                if (s[j]==s[i])
                    dp[i][j]=p+dp[i+1][j-1];
                else
                    dp[i][j]=max(dp[i][j-1],dp[i+1][j]);
            }
        }
        int ans=0;
        for (int i=0;i<=n;i++)
            ans=max(ans,dp[1][i]+dp[i+1][n]);
        cout<<ans<<endl;
    }
}
