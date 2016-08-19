#include<stdio.h>
int main()
{
    int n,i;
    while(scanf("%d",&n),n)
    {
        i=n/1000+n/100%10+n/10%10+n%10;
        printf((i==n/4096+n/256%16+n/16%16+n%16)&&(i==n/1728+n/144%12+n/12%12+n%12)?"%d is":"%d is not",n,n);
        printf(" a Sky Number.\n");
    }
}
