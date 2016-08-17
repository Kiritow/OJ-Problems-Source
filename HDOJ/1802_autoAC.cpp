#include<cstdio>
#include<stdlib.h>
int main()
{
    int n,m,c;
    while(scanf("%d%d%d",&n,&m,&c),(m+n+c))
    {
    int p,q;
    p=n-7;
    q=m-7;
    if((p*q)&1)
      printf("%d\n",(p*q)/2+c);
    else
    printf("%d\n",(p*q)/2); 
    }
    return 0;
}
