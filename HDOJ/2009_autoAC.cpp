#include <math.h>
#include <stdio.h>
int main(void)
{
    int n;
    double x, s;
    while (scanf("%lf%d", &x, &n) != EOF)
    {
        for(s = 0.0; n--; x = sqrt(x))
            s += x;
        printf("%.2lf\n", s);
    }
    return 0;
}
