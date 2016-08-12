#include <stdio.h>
int main(void)
{
    int a, b, i = 0;
    while(i < 5)
    {
            scanf("%d%d", &a, &b);
            printf("%d\n\n", a + b);
        i ++;
    }
    return 0;
}
