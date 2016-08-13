#include<stdio.h>
#include<string.h>
int minn(int x,int y)
{
   return x<y?x:y;
}
int main ()
{
   int dp[2005];
   int a1[2005];
   int a2[2005];
   int i,n,t,j;
   int a,b,c;
   char c1,c2;
   scanf("%d",&t);
   while(t--)
   {
      scanf("%d",&n);
      for(i=1;i<=n;i++)
      scanf("%d",&a1[i]);
      for(i=1;i<n;i++)
      scanf("%d",&a2[i]);
      memset(dp,0,sizeof(dp));
      dp[1]=a1[1];
      for(i=2;i<=n;i++)
      dp[i]=minn(dp[i-1]+a1[i],dp[i-2]+a2[i-1]);
      a=8,b=c=0;
      c=dp[n]%60;
      b=dp[n]/60%60;
      a+=(dp[n]/3600);
      if(a<12||a==12&&b==c&&c==0)
      {
         c1='a';
         c2='m';
      }
      else
      {
        if(a!=12)
           a%=12;   
        c1='p';
        c2='m';
     }
     printf("%02d:%02d:%02d %c%c\n",a,b,c,c1,c2);
   }
   return 0;
}
