#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int cmp(const int *a, const int *b)
{
    return abs(*b) - abs(*a);
}
int main(void)
{
    int n, i, x[101];
    while (scanf("%d", &n), n)
    {
        for (i = 0 ; i < n ; i++)
            scanf("%d", x + i);
        qsort(x, n, sizeof(int), cmp);
        for (i = 0 ; i < n ; i++)
            printf("%d%c", x[i], (i != n - 1 ? ' ' : '\n'));
    }
    return 0;
}
