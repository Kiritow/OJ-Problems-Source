#include <stdio.h>
int main(void)
{
    int n, i;
    double min, max;
    double x, y;
    while (scanf("%d", &n) != EOF)
    {
        scanf("%lf", &x);
        min = max = x;
        for (i = 1 ; i < n ; i++)
        {
            scanf("%lf", &y);
            x += y;
            if (y > max) max = y;
            if (y < min) min = y;
        }
        printf("%.2lf\n", (x - min - max) / (n - 2));
    }
    return 0;
}
