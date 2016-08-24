#include <stdio.h>
int main ()
{
int n,a,b,i,j,k,t=1;
int c[100];
while (scanf("%d %d %d",&n,&a,&b)!=EOF)
{
   printf ("Case %d:",t++);
   i=0;
   while (n)
   {
    c[i]=n%b;
    n/=b;
    i++;
   }
   c[i]=0;
   for (k=0;k<i-1;k++)
   {
    while (c[k]<a)
    {
     c[k]+=b;
     c[k+1]--;
    }
   }
   while (c[k]==0 && k)
    k--;
   while (k)
    printf (" %d",c[k--]);
   printf (" %d\n",c[0]);
}
return 0;
}
