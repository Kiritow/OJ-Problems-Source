#include<stdio.h>
#include<math.h>
int main()
{
 int t;
 int a,b,c;
 double x1,x2,x,temp;
 scanf("%d",&t);
 while(t--)
 {
  scanf("%d%d%d",&a,&b,&c);
  x=b*b-4*a*c;
  if(x<0)
   printf("NO\n");
  else if(x==0)
  {
   x1=-1.0*b/(2*a);
   printf("%.2f\n",x1);
  }
  else if(x>0)
  {
   x1=(-1.0*b-sqrt(x))/(2*a);
   x2=(-1.0*b+sqrt(x))/(2*a);
   if(x1>x2)
   {
    temp=x1;x1=x2;x2=temp;
   }
   printf("%.2f %.2f\n",x1,x2);
  }
 }
 return 0;
}
