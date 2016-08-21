#include<stdio.h>
#include<string.h>
int main()
{
    int n,m;
    int dp[50][50];
    int i,l;
    int x,y,flag;
    int x1,y1,x2,y2;
    while(scanf("%d%d",&n,&m)!=-1)
    {
        scanf("%d%d%d%d",&y1,&x1,&y2,&x2);
        if(x1+y1>x2+y2)    {x=x1;y=y1;}
        else            {x=x2;y=y2;}
        if(x1!=x2)    flag=-1;
        else        flag=1;
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(l=1;l<m;l++)
        {
            if(x==0 && l==y)dp[0][l]=0;
            else    dp[0][l]=dp[0][l-1];
        }
        for(i=1;i<n;i++)
        {
            for(l=0;l<m;l++)
            {
                if(i==x && l==y)
                {
                    if(l!=0)
                    {
                        if(flag==-1)    dp[i][l]=dp[i][l-1];
                        else            dp[i][l]=dp[i-1][l];
                    }
                    else
                    {
                        if(flag==-1)    dp[i][l]=0;
                        else            dp[i][l]=dp[i-1][l];
                    }
                }
                else
                {
                    if(l==0)    dp[i][l]=dp[i-1][l];
                    else        dp[i][l]=dp[i-1][l]+dp[i][l-1];
                }
            }
        }
        printf("%d\n",dp[n-1][m-1]);
    }
    return 0;
}
