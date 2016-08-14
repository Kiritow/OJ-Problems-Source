#include<iostream>
#include<string.h>
#include<stdio.h>
#define maxn 509
using namespace std;
int a[maxn],b[maxn],dp[maxn][maxn];
int main()
{
    int t,i,j,k,l,n,m;
    scanf("%d",&t);
    while(t--)
    {
        int ans=-1;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        scanf("%d",a+i);
        scanf("%d",&m);
        for(i=1;i<=m;i++)
        scanf("%d",b+i);
        for(i=1;i<=n;i++)
        {
            int max=0;
            for(j=1;j<=m;j++)
            {
                if(max<dp[i-1][j]&&a[i]>b[j])max=dp[i-1][j];
                if(a[i]!=b[j])dp[i][j]=dp[i-1][j];
                else dp[i][j]=max+1;
                if(dp[i][j]>ans)
                ans=dp[i][j];
            }
        }
        printf("%d\n",ans);
        if(t)
        puts("");
    }
}
