#include<stdio.h>
#include<stdlib.h>
int main()
{
    int t, n, re, i;
    scanf("%d", &t);
    for(i=1; i<=t; i++)
    {
        scanf("%d", &n);
        if(n==1)
            re=1;
        else if(n==2)
            re=2;
        else
            re=2*n-4;
        printf("Case %d: %d\n", i, re);
    }
    return 0;
}
