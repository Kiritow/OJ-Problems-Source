#include<stdio.h>
int arr[21];
void func( void )
{
    int i;
    arr[1]=0;arr[2]=1;
    for(i=3;i<=20;i++)
        arr[i]=(i-1)*(arr[i-1]+arr[i-2]);
}
int main( void )
{
  int n,t,i,a;
  double sum;
  func();
  scanf("%d",&t);
  while(t--)
  {    sum=0.0;
       a=1;
      scanf("%d",&n);
      if(n>=10)n=10;
      for(i=2;i<=n;i++)
            a*=i;
      printf("%0.2lf%%\n",(arr[n]*100.0)/a);
  }
  return 0;
}
