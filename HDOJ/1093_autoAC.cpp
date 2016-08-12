#include <stdio.h>
int main()
{
    int n, m, a, sum, i, j;
    while(scanf("%d", &n) != EOF)
    {
        for(i = 0; i < n; i ++)
        {
            scanf("%d", &m);
            sum = 0;
            for(j = 0; j < m; j ++)
            {
                scanf("%d", &a);
                sum = sum + a;
            }
            printf("%d\n", sum);
        }
     }
     return 0;
}
