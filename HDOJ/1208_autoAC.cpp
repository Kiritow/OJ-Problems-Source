#include<stdio.h>
#include<string.h>
int main ()
{
    __int64 dp[50][50];
    int map[50][50];
    int i,j,n;
    char c;
    while(~scanf("%d",&n)&&n!=-1)
    {
      getchar();
      for(i=1;i<=n;i++)
      {
         for(j=1;j<=n;j++)
         {
           scanf("%c",&c);
           map[i][j]=c-48;
          }
          getchar();
      }
      memset(dp,0,sizeof(dp));
      dp[1][1]=1;
      for(i=1;i<=n;i++)
      for(j=1;j<=n;j++)
      {
          if(!map[i][j])
          continue;
          dp[i+map[i][j]][j]+=dp[i][j];
          dp[i][j+map[i][j]]+=dp[i][j];
      }
      printf("%I64d\n",dp[n][n]);
   }
   return 0;
}
