#include <stdio.h>
int main(void)
{
    int n, a, sum, i;
    while(scanf("%d", &n) != EOF)
    {
        sum = 0;
        for(i = 0; i < n; i ++)
        {
            scanf("%d", &a);
            sum = sum + a;
        }
        printf("%d\n", sum);
    }
    return 0;
}
