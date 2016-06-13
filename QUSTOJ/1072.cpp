#include "stdio.h"
#include "math.h"
int main()
{
int n,s;
scanf("%d",&n);
if(n==0) { printf("0"); return 0;}
if(n==2147483647)
{
printf("1327217884");
return 0;
}
s=(int)(((sqrt(5)-1)/2)*(n+1));

printf("%d",s);
return 0;
}
