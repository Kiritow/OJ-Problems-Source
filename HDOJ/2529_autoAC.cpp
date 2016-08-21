#include <stdio.h>
#define g 9.8
int main()
{
    double h, l, v;
    while (scanf("%lf%lf%lf", &h, &l, &v))
    {
        if(h == 0 && l == 0 && v == 0)
            break;
        printf("%.2lf\n", 0.5 * v * v / g - 0.5 * g * l * l / (v*v) + h);
    }
    return 0;
}
