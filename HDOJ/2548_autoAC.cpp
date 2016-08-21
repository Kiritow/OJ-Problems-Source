#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        double u,v,w,l;
        scanf("%lf %lf %lf %lf",&u,&v,&w,&l);
        printf("%.3f\n",(l/(u+v))*w);
    }
    return 0;
}
