#include <stdio.h>
int main()
{
int n,x1,x2,x3,x4,i,j,k,m,s,v;
double time,min;
min=2000;
scanf("%d%d%d%d%d",&n,&x1,&x2,&x3,&x4);
for(i=0;i<=10;i++)
for(j=0;j<=10;j++)
for(k=0;k<=10;k++)
if((i+j+k)<=n)
{
m=n-i-j-k;
time=((20.0-i*2)*x1+((100.0-j*7)*x2*2+(100.0-k*9)*x3)/((10.0+m)*x4));
if(time<min) min=time;
time=0;
}
printf("%.3lf",min);
return 0;
}
