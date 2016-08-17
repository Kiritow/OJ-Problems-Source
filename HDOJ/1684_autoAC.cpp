#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int dp[101][101];
int n,m,sal;
struct pro
{
    int p[101],pun,rew;
}pr[101];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&m,&n,&sal);
        for(int i=1;i<=m;i++)
        {
            pr[i].p[0]=0;
            for(int j=1;j<=n;j++)
                scanf("%d",&pr[i].p[j]);
            scanf("%d %d",&pr[i].rew,&pr[i].pun);
        }
        memset(dp,0,sizeof(dp));
        dp[0][0]=0;
        for(int i=1;i<=m;i++)
            dp[i][0]=dp[i-1][0]-pr[i].pun*100;
        for(int i=1;i<=n;i++)
            dp[1][i]=(pr[1].rew-sal*i)*pr[1].p[i]-(100-pr[1].p[i])*pr[1].pun;
        for(int i=2;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dp[i][j]=-INT_MAX;
                for(int k=0;k<=j;k++)
                {
                    int temp=dp[i-1][j-k]+(pr[i].rew-sal*k)*pr[i].p[k]-(100-pr[i].p[k])*pr[i].pun;
                    if(temp>dp[i][j])
                        dp[i][j]=temp;
                }
            }
        }
        int max1=-INT_MAX;
        for(int i=0;i<=n;i++)
        {
            if(dp[m][i]>max1)
                max1=dp[m][i];
        }        
        printf("%d\n",max1);
        int flag=1;
        for(int i=0;i<=n;i++)
        {
            if(max1==dp[m][i])
            {
                if(flag)
                {
                    printf("%d",i);
                    flag=0;
                }
                else printf(" %d",i);
            }
        }
        printf("\n");
    }
    return 0;
}
