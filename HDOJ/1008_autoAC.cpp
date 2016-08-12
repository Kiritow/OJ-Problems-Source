#include <stdio.h>
int main()
{
 int i,n,a[101],sum;
 while(scanf("%d",&n),n)
 {
  sum=0; a[0]=0;
  for(i=1;i<=n;i++)
    scanf("%d",a+i);
  for(i=0;i<n;i++)
  {
   if(a[i]<=a[i+1])  
{
    sum+=(a[i+1]-a[i])*6+5;
   }
   else if(a[i]>a[i+1])
   {
    sum+=(a[i]-a[i+1])*4+5;
   }
  }
  printf("%d\n",sum);
 }
 return 0;
}
