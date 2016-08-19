#include<stdio.h>
int main(void)
{
    int ans,n,i,j,k,a[5]={50,25,10,5,1};
    int dp[251][101]={0};
    dp[0][0]=1;
    for (i=0;i<5;i++)
        for (j=0;j<=250;j++)
            for (k=0;k<100;k++)
                if (a[i]+j<=250)
                    dp[a[i]+j][k+1]+=dp[j][k];
                else
                    break;
    while (scanf("%d",&n)==1)
    {
        ans=0;
        for (i=0;i<=100;i++)
            ans+=dp[n][i];
        printf("%d\n",ans);
    }
    return 0;
}
