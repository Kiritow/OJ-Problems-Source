#include <stdio.h>
#include <string.h>
double p[7],f[11][61];
void dp(){
 int i,j,k;
 double ans;
 memset(f,0,sizeof(f));
 f[0][0]=1.0;
 for (k=1;k<=10;k++)
  for (j=60;j>=k;j--)
   for (i=1;i<=6;i++)
    if (j>=i)
     f[k][j]+=f[k-1][j-i]*p[i];
 ans=0;
 for (i=1;i<=10;i++)
  ans+=f[i][5];
 printf("5: %.1lf%%\n",ans*100);
 ans=0;
 for (i=1;i<=10;i++)
  ans+=f[i][12];
 printf("12: %.1lf%%\n",ans*100);
 ans=0;
 for (i=1;i<=10;i++)
  ans+=f[i][22];
 printf("22: %.1lf%%\n",ans*100);
 ans=0;
 for (i=1;i<=10;i++)
  ans+=f[i][29];
 printf("29: %.1lf%%\n",ans*100);
 ans=0;
 for (i=1;i<=10;i++)
  ans+=f[i][33];
 printf("33: %.1lf%%\n",ans*100);
 ans=0;
 for (i=1;i<=10;i++)
  ans+=f[i][38];
 printf("38: %.1lf%%\n",ans*100);
 ans=0;
 for (i=1;i<=10;i++)
  ans+=f[i][42];
 printf("42: %.1lf%%\n",ans*100);
 ans=0;
 for (i=1;i<=10;i++)
  ans+=f[i][46];
 printf("46: %.1lf%%\n",ans*100);
 ans=0;
 for (i=1;i<=10;i++)
  ans+=f[i][50];
 printf("50: %.1lf%%\n",ans*100);
 ans=0;
 for (i=1;i<=10;i++)
  ans+=f[i][55];
 printf("55: %.1lf%%\n",ans*100);
}
int main(){
 int t;
 scanf("%d",&t);
 while (t--){
  for (int i=1;i<=6;i++)
   scanf("%lf",&p[i]);
  dp();
  if (t)
   putchar('\n');
 }
 return 0;
}
