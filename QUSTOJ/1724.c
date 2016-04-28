#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DUR 0.001
double func(double x)
{
    return (2*x*x*x)-(4*x*x)+3*x-6;
}

double dfs(double L, double Mid, double R)
{
    int t;
    if(R-L < DUR) return R;

    if(func(L)*func(Mid) <=0)
    {
        t= dfs(L,(L+Mid)/2,Mid);
    }
    else if(func(Mid)*func(R) <=0)
    {
        t= dfs(Mid,(Mid+R)/2,R);
    }
    return t;
}

int main()
{
    double a, b, c;
    scanf("%lf,%lf",&a,&c);
    b = (a+c)/2;
    printf("x=%6.2f\n",dfs(a,b,c));
    return 0;
}
