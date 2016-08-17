#include<stdio.h>
#include<string.h>
int n,m;
int map[111][111];
struct A
{
    int ts;
    int ms;
}dp[111][111];
int Judge(int x,int y)
{
    if(x<0 || x>=n || y<0 || y>=m)    return 1;
    return 0;
}
int main()
{
    int T;
    int i,l;
    int t,x_n,y_n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
        for(l=0;l<m;l++)
            scanf("%d",&map[i][l]);
        memset(dp,0,sizeof(dp));
        dp[0][0].ms=1;
        for(i=0;i<n;i++)
        {
            for(l=0;l<m;l++)
            {
                if(i==n-1 && l==m-1)continue;
                if(map[i][l]==0)    continue;
                if(dp[i][l].ms==0)    continue;
                t=map[i][l]+1;
                x_n=i+map[i][l];
                y_n=l;
                while(t--)
                {
                    if(x_n==n-1 && y_n==m-1)    {x_n--;y_n++;continue;}
                    if(Judge(x_n,y_n))            {x_n--;y_n++;continue;}
                    if(dp[i][l].ts+1>dp[x_n][y_n].ts)
                    {
                        dp[x_n][y_n].ts=dp[i][l].ts+1;
                        dp[x_n][y_n].ms=dp[i][l].ms;
                    }
                    else if(dp[i][l].ts+1==dp[x_n][y_n].ts)    dp[x_n][y_n].ms+=dp[i][l].ms;
                    x_n--;
                    y_n++;
                }
                if(i+l+map[i][l]>n+m-2)
                {
                    if(dp[i][l].ts>dp[n-1][m-1].ts)
                    {
                        dp[n-1][m-1].ts=dp[i][l].ts;
                        dp[n-1][m-1].ms=dp[i][l].ms;
                    }
                    else if(dp[i][l].ts==dp[n-1][m-1].ts)    dp[n-1][m-1].ms+=dp[i][l].ms;
                }
                else if(i+l+map[i][l]==n+m-2)
                {
                    if(dp[i][l].ts+1>dp[n-1][m-1].ts)
                    {
                        dp[n-1][m-1].ts=dp[i][l].ts+1;
                        dp[n-1][m-1].ms=dp[i][l].ms;
                    }
                    else if(dp[i][l].ts+1==dp[n-1][m-1].ts)    dp[n-1][m-1].ms+=dp[i][l].ms;
                }
            }
        }
        printf("%d %d\n",dp[n-1][m-1].ts,dp[n-1][m-1].ms);
    }
    return 0;
}
