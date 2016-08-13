#include <iostream>
#include <math.h>
using namespace std;
double a,b,r;
double xj(double xy,double x,double y,double aa,double bb)
{
    double m,n=y+1;
    m=r*r-(xy-aa)*(xy-aa);
    if(m>0) n=sqrt(m)+bb;
    if(m<0||n>y||n<x) return 0;
    else return 1;
}
int main(){
int n;
scanf("%d",&n);
while(n--)
{
    double x1,y1,x2,y2,a1,b1,c1,d1;
    scanf("%lf%lf%lf%lf%lf%lf%lf",&a,&b,&r,&x1,&y1,&x2,&y2);
    a1=x1>x2?x2:x1;b1=x1+x2-a1;
    c1=y1>y2?y2:y1;d1=y1+y2-c1;
    if(xj(a1,c1,d1,a,b)||xj(b1,c1,d1,a,b)||xj(c1,a1,b1,b,a)||xj(d1,a1,b1,b,a))
        printf("YES\n");
    else
        printf("NO\n");
}
return 0;
}
