#include<stdio.h>
int main()
{
    int a,b,n;
    while(scanf("%d%d",&a,&b)!=EOF)
    {n=a+b;
    if((n%86)==0)
    printf("yes\n");
    else
    printf("no\n");}
    return 0;
}
