#include<stdio.h>
#include<string.h>
#define size 20
#define inf 100000000
int c,m,n1,n2,n3,t,s,temp;
int num[size];
int dp[size][size][size][size];
int main()
{
    scanf("%d",&t);
    int T=0;
    while(t--)
    {
        T++;
        scanf("%d%d",&c,&m);
        memset(num,0,sizeof(num));
        memset(dp,-1,sizeof(dp));
        dp[1][0][0][0]=0;
        for(int i=0;i<m;i++)
        {
           scanf("%d",&s);
           num[s]++;
        }
        for(int i=2;i<=16;i++)
         for(int j=0;j<=c;j++)
           for(int k=0;k<=c;k++)
             for(int l=0;l<=c;l++)
             {
                   if(dp[i-1][j][k][l] == -1) continue;
                   for(int n1=0;n1<=num[i];n1++)
                      for(int n2=0;n2<=num[i];n2++)  
                      {
                         int sum=0;
                         n3=num[i]-(n1+n2);
                         if(n3<0) continue;
                         if(j+n1>c||k+n2>c||l+n3>c) continue;
                         temp = dp[i-1][j][k][l]+(n1!=0)+(n2!=0)+(n3!=0);
                         if(dp[i][j+n1][k+n2][l+n3]==-1||dp[i][j+n1][k+n2][l+n3]>temp)
                            dp[i][j+n1][k+n2][l+n3]=temp;
                      }
             }
    int maxn=inf;
    for(int i=0;i<=c;i++)
      for(int j=0;j<=c;j++)
      {
         if(i+j>m) continue;
         if(dp[16][i][j][m-i-j] == -1) continue;
         if(dp[16][i][j][m-i-j]<maxn)
            maxn=dp[16][i][j][m-i-j];
      }
      printf("Case %d: %d\n",T,maxn);
  }
}
