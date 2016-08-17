#include <cstdio>
#include <cstring>
int tree[13][13];
long long int dp[13][13][1<<13];
int main()
{
    int t;
    scanf("%d",&t);
    for(int p=1;p<=t;p++)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                scanf("%d",&tree[i][j]);
            }
        }
        memset(dp,0,sizeof(dp));
        dp[0][m][0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int k=0;k<(1<<(m+1));k++)
            {
                dp[i][0][k<<1]=dp[i-1][m][k];
            }
            for(int j=1;j<=m;j++)
            {
                int x=1<<j;
                int y=1<<(j-1);
                for(int k=0;k<(1<<(m+1));k++)
                {
                    if(tree[i][j]!=0)
                    {
                        if((k&x)!=0 && (k&y)!=0)
                        {
                            dp[i][j][k]=dp[i][j-1][k^x^y];
                        }
                        else if((k&x)==0 && (k&y)==0)
                        {
                            dp[i][j][k]=dp[i][j-1][k^x^y];
                        }
                        else
                        {
                            dp[i][j][k]=dp[i][j-1][k]+dp[i][j-1][k^x^y];
                        }
                    }
                    else
                    {
                        if((k&x)==0 && (k&y)==0)
                        {
                            dp[i][j][k]=dp[i][j-1][k];
                        }
                        else
                        {
                            dp[i][j][k]=0;
                        }
                    }
                }
            }
        }
        printf("Case %d: There are %I64d ways to eat the trees.\n",p,dp[n][m][0]);
    }
    return 0;
}
