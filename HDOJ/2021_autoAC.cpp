#include <stdio.h>
int main(void)
{
    int n, i, x, sum;
    while (scanf("%d", &n), n)
    {
        sum = 0;
        for (i = 0 ; i < n ; i++)
        {
            scanf("%d", &x);
            sum += x / 100;
            x %= 100;
            sum += x / 50;
            x %= 50;
            sum += x / 10;
            x %= 10;
            sum += x / 5;
            x %= 5;
            sum += x / 2;
            x %= 2;
            sum += x;
        }
        printf("%d\n", sum);
    }
    return 0;
}
