#include <stdio.h>
int main(void)
{
    int i, n, m, b, c;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        b = 2;
        c = 0;
        for (i = 0 ; i < n / m ; i++)
        {
            printf(c++ ? " %d" : "%d", b + m - 1);
            b += m * 2;
        }
        printf(n % m ? " %d\n" : "\n", b + n % m - 1);
    }
    return 0;
}
