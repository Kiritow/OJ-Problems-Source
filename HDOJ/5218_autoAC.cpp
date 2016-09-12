#include <iostream>
#include<string.h>
#include<stdio.h>
#include<algorithm>
using namespace std;
int arr[300];
int n,m;
int dp[300][300];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++)scanf("%d",&arr[i]);
        memset(dp,0,sizeof(dp));
        dp[1][0]=1;
        for(int i=2;i<=n;i++)
        {
            for(int j=0;j<i;j++)
            {
                for(int k=0;k<m;k++)
                {
                    if((arr[k]-1)%i==j)continue;
                    if((arr[k]-1)%i<j)dp[i][j]=dp[i-1][j-(arr[k]-1)%i-1];
                    if((arr[k]-1)%i>j)dp[i][j]=dp[i-1][i-1-((arr[k]-1)%i-j)];
                    if(dp[i][j])break;
                }
            }
        }
        int ok=1,ans=0;
        for(int i=0;i<n;i++)if(dp[n][i])ans++;
        printf("%d\n",ans);
        for(int i=0;i<n;i++)
            if(dp[n][i])
            {
                if(ok)ok=0;
                else printf(" ");
                printf("%d",i+1);
            }
        printf("\n");
    }
    return 0;
}
