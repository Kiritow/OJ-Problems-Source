#include<cstdio>
int main()
{
int N,i;
scanf("%d",&N);
printf("%d=",N);
for(i=2;i<=N;i++)
{
while(N%i==0)
{
printf("%d",i);
N=N/i;
if(N<i)
break;
else
printf("*");
}
}
if(N==i)
printf("%d",N);
return 0;
}
