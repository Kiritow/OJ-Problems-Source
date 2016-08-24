#include<stdio.h>
int main()
{
    int t;
    double n,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf%lf",&n,&m);
        if(n*52>=m)
            printf("Oh,Samuel's hope will come true,thanks to the DcSLs.\n");
        else
            printf("Unfortunately,Samuel's hope will not come true,more tourists are welcomed!\n");
    }
    return 0;
}
