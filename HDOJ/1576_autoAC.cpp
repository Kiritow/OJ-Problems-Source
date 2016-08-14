#include<stdio.h>
int main()
{
    int T,n,i;
    long long int B;
    scanf("%d",&T);
    while(T--)
    {
    scanf("%d%lld",&n,&B);
     for(i=0;i<=10000;i++)
     if((B*i-n)%9973==0) break;
     printf("%d\n",i);    
    }
    return 0;
 }
