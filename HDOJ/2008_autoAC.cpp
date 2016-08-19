#include <stdio.h>
int main(void)
{
    int n, i, a, b, c;
    double x;
    while (scanf("%d", &n) , n)
    {
        a = b = c = 0;
        for (i = 0 ; i < n ; i++)
        {
            scanf("%lf", &x);
            if (x > 0) c++;
            else if (x < 0) a++;
            else b++;
        }
        printf("%d %d %d\n", a, b, c);
    }
    return 0;
}
