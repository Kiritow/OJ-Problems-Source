#include <stdio.h>
int main(void)
{
    int n, i, s, t;
    while (scanf("%d", &n) != EOF)
    {
        for (s = 1, i = 0 ; i < n ; i++)
        {
            scanf("%d", &t);
            if (t & 1) s *= t;
        }
        printf("%d\n", s);
    }
    return 0;
}
