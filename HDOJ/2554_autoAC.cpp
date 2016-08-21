#include <stdio.h>
int main()
{
    int n;
    while(scanf("%d",&n)&&n)
        n*(n+1)/2&1?puts("N"):puts("Y");
}
