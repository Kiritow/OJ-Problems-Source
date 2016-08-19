#include<stdio.h>
#include<string.h>
int main()
{
    int T,i,j,ii,jj,n,m,mark[105][105],dp[105][105],t,sum;
    scanf("%d",&T);
    while(T--)
    {
        memset(mark,0,sizeof(mark));
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)
         for(j=1;j<=m;j++)
         scanf("%d",&dp[i][j]);
         mark[1][1]=1;
         for(i=1;i<=n;i++)
          for(j=1;j<=m&&!(i==n&&j==m);j++)
          {
              t=dp[i][j];sum=mark[i][j]%10000;
              for(ii=i;ii<=i+t&&ii<=n;ii++)
               for(jj=j;jj<=j+t-ii+i&&jj<=m;jj++)
               mark[ii][jj]+=sum;
          }
          printf("%d\n",mark[n][m]%10000);
    }
}
