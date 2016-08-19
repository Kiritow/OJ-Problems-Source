#include <math.h>
#include <stdio.h>
int main(void)
{
    double r;
    while (scanf("%lf", &r) != EOF)
        printf("%.2lf\n", fabs(r));
    return 0;
}
