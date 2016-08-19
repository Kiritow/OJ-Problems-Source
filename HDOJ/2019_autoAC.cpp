#include <stdio.h>
int main(void)
{
    int n, i, m, x[101];
    while (scanf("%d%d", &n, &m), n || m)
    {
        for (i = 0 ; i < n ; i++)
            scanf("%d", x + i);
        for (i = n ; i && x[i - 1] > m ; i--)
            x[i] = x[i - 1];
        x[i] = m;
        for (i = 0 ; i < n + 1 ; i++)
            printf("%d%c", x[i], (i - n ? ' ' : '\n'));
    }
    return 0;
}
