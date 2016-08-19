#include <math.h>
#include <stdio.h>
#define lev(n) (n % 4 == 0 && (n % 100 != 0 || n % 400 == 0))
int main(void)
{
    int y, m, d, i, s;
    int month[2][13] = {
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
    };
    while (scanf("%d/%d/%d", &y, &m, &d) != EOF)
    {
        for (s = 0, i = 1 ; i < m ; i++)
            s += month[lev(y)][i];
        s += d;
        printf("%d\n", s);
    }
    return 0;
}
