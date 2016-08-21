#include <stdio.h>
int main()
{
    double a=0.57735026918963,b=0.81649658092773;
    int r;
    while(scanf("%d",&r),r)
        printf("%.3f %.3f\n",a*r,b*r);
    return 0;
}
