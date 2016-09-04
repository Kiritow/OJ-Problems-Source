#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int dp[1005][1005],sum[1005],a[1005],s[1005][1005];
int main()
{
    int n,m,r;
    while(scanf("%d%d%d",&n,&m,&r)!=EOF)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            sum[i]=sum[i-1]+a[i];
        }
        memset(dp,-1,sizeof(dp));
        memset(s,-0x1f1f1f1f,sizeof(s));
        dp[0][0]=0;s[0][0]=-sum[1];
        for(int i=1;i<=n;i++)
        {
            if(i>=r)
            {
                dp[0][i]=sum[i];         
            }
            dp[i][i]=0;
            s[0][i]=max(s[0][i-1],dp[0][i]-sum[i+1]);
        }
        for(int i=1;i<=m;i++)
        {
            for(int j=i;j<=n;j++)
            {
                if(dp[i-1][j-1]!=-1)
                    dp[i][j]=max(dp[i-1][j-1],dp[i][j]);
                if(j-r>=i&&s[i-1][j-r-1]!=-0x1f1f1f1f)
                    dp[i][j]=max(dp[i][j],sum[j]+s[i-1][j-r-1]);
                if(dp[i][j]!=-1)
                    s[i][j]=max(s[i][j-1],dp[i][j]-sum[j+1]);
                else
                    s[i][j]=s[i][j-1];
            }
        }
        printf("%d\n",dp[m][n]);
    }
    return 0;
}
