#include<stdio.h>
#include<string.h>
int dp[1005][1005];
int main ()
{
  int fw[1005][2],l[1005],num[1005];
  int i,j,k,s,n,m;
  while(~scanf("%d",&n)&&n)
  {
     scanf("%d",&m);
     for(s=0,i=1;i<=m;i++)
     {
       scanf("%d",&l[i]); 
       fw[i][0]=s+1;
       s+=l[i];
     }
     for(s=0,i=m;i>=1;i--)
     {
        fw[i][1]=n-s;
        s+=l[i];
      }
      for(i=1;i<=n;i++)
      scanf("%d",&num[i]);
      memset(dp,0,sizeof(dp));
      for(i=1;i<=m;i++)
      {
         s=0;
         for(j=fw[i][0];j<=fw[i][1];j++)
         {
           if(j-fw[i][0]+1<=l[i])
           {
        s+=num[j];
        if(j-fw[i][0]+1==l[i])
        {
           if(dp[i][j]<s+dp[i-1][j-l[i]]) 
           for(k=j;k<=n;k++)
           dp[i][k]=dp[i-1][j-l[i]]+s;
               }  
           }
         else
         {
             s+=num[j];
             s-=num[j-l[i]];
             if(dp[i][j]<s+dp[i-1][j-l[i]]) 
            for(k=j;k<=n;k++)
            dp[i][k]=dp[i-1][j-l[i]]+s;
               }
           }  
      }
      printf("%d\n",dp[m][n]);
  }
  return 0;
}
