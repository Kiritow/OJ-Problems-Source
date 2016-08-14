#include<stdio.h>
#include<string.h>
#define INF 0x3f3f3f
#define MAX 1000+10
int map[MAX][MAX];
int dp[MAX][MAX];
int max(int x,int y)
{
    return x>y?x:y;
}
int main()
{
    int t,n,m,x,y,k,l;
    int i,j,sum,maxsum,s;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d",&n,&m,&x,&y);
        memset(dp,0,sizeof(dp));
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                scanf("%d",&map[i][j]);
                if(i==1)
                dp[i][j]=map[i][j];
                else
                dp[i][j]=map[i][j]+dp[i-1][j];
            }
        }
        maxsum=-INF;
        for(i=1;i<=n;i++)
        {
            for(j=i;j<=n;j++)
            {
                if(j-i+1!=x)
                continue;
                for(k=1;k<=m;k++)
                {
                    sum=dp[j][k]-dp[i-1][k];
                    s=0;
                    for(l=k;l<k+y&&l<=m;l++)
                    {
                        s+=dp[j][l]-dp[i-1][l];
                        if(s>sum)
                        sum=s;
                        if(s<0)
                        s=0;
                    }
                    maxsum=max(sum,maxsum);
                }
            }
        }
        printf("%d\n",maxsum);
    }
    return 0;
}
