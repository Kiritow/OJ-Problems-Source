#include <stdio.h>
#define N 1000
int sum[N][N];
int main()
{
 int c,n,i,j;
 while (scanf("%d",&c)!=EOF)
 {
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
   for(j=i;j<n;j++)
    scanf("%d",&sum[i][j]);
  }
  for(i=0;i<n;i++)
  {
   for(j=i;j<n;j++)
   {
    if(i==0)
     sum[i][j]=c+sum[i][j];
    else
     sum[i][j]=(sum[i-1][i-1]+c+sum[i][j])<(sum[i-1][j])?(sum[i-1][i-1]+c+sum[i][j]):(sum[i-1][j]);
   }
  }
  printf("%d\n",sum[n-1][n-1]);
 }
 return 0;
}
