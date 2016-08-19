#include <cmath>
#include <cstdio>
int main(void)
{
    double x[2], y[2];
    while (scanf("%lf%lf%lf%lf", x, y, x+1, y+1) != EOF)
        printf("%.2f\n", sqrt((x[1]-x[0])*(x[1]-x[0]) + (y[1]-y[0])*(y[1]-y[0])));
    return 0;
}
