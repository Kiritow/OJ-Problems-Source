#include <math.h>
#include <stdio.h>
int main(void)
{
    int i, j;
    int n, m;
    int x, y;
    double a, t;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        a = x = y = 0;
        for (i = 0 ; i < n ; i++)
        {
            for (j = 0 ; j < m ; j++)
            {
                scanf("%lf", &t);
                if (fabs(t) > fabs(a))
                {
                    a = t;
                    x = i;
                    y = j;
                }
            }
        }
        printf("%d %d %.0f\n", x + 1, y + 1, a);
    }
    return 0;
}
