#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;
int main()
{
   double a,b,c,m,n,l,v;
   while(scanf("%lf%lf%lf%lf%lf%lf", &a, &c, &b, &n, &l, &m)!=EOF)  
   {
      v=(double)sqrt((4.0*a*a*b*b*c*c-a*a*(b*b+c*c-m*m)*(b*b+c*c-m*m)-
      b*b*(c*c+a*a-n*n)*(c*c+a*a-n*n)-c*c*(a*a+b*b-l*l)*
      (a*a+b*b-l*l)+(a*a+b*b-l*l)*(b*b+c*c-m*m)*(c*c+a*a-n*n)))/12.0;
      printf("%.4lf\n", v);
    }
    return 0;
}
