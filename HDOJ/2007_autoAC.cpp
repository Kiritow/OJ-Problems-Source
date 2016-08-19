#include <stdio.h>
int main(void)
{
    unsigned int m, n, i, x, y;
    while (scanf("%u%u", &m, &n) != EOF)
    {
        if (m > n)
        {
            i = n;
            n = m;
            m = i;
        }
        x = y = 0;
        for (i = m ; i <= n ; i++)
            (i & 1) ? (y += i*i*i) : (x += i*i);
        printf("%u %u\n", x, y);
    }
    return 0;
}
