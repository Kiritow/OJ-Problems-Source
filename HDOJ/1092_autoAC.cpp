#include <stdio.h>
int main(void)
{
    int a, n, i, sum;
    while(scanf("%d", &n) && n != 0)    
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
