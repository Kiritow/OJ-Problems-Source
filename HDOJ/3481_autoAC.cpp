#include<cstdio>
#include<algorithm>
const int MOD = 987654321;
long long dp[110][10];
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m),n>0)
    {
        if(m==1){puts("0");continue;}
        if(m==2){printf("%d\n",n==1?2:0);continue;}
        memset(dp,0,sizeof(dp));
        dp[1][1]=m;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<m;j++)
            {
                dp[i][j]%=MOD;
                dp[i+1][j+1]+=dp[i][j]*(m-j);
                for(int k=2;k<=j;k++)
                    dp[i+1][k]+=dp[i][j];
                if(j>1||i==1)
                {
                    for(int k=1;1+k<=m-1;k++)
                    {
                        dp[i+k][1]+=dp[i][j];
                    }
                }
            }
        }
        long long ans=0;
        for(int j=1;j<m;j++)
        {
            ans+=dp[n][j];
        }
        printf("%I64d\n",ans%MOD);
    }
    return 0;
}
