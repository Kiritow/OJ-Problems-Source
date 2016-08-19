#include <math.h>
#include <stdio.h>
#define PI 3.1415927
int main(void)
{
    double r;
    while (scanf("%lf", &r) != EOF)
        printf("%.3lf\n", 4.0*PI*r*r*r/3.0);
    return 0;
}
