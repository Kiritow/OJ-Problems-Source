#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    double u,v,s;
    while(scanf("%d",&n)!=EOF)
    {
        while(n--)
        {
            scanf("%lf%lf",&s,&u);
            v=tan(atan(1/s)-atan(1/u));
            v=1.0/v;
            printf("%.0lf\n", v*u-s*u-s*v);
        }
    }
    return 0;
}
