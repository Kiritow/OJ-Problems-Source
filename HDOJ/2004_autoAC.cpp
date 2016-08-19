#include <math.h>
#include <stdio.h>
int main(void)
{
    int r;
    while (scanf("%d", &r) != EOF)
    {
        if (r < 0)
            puts("Score is error!");
        else if (r < 60)
            puts("E");
        else if (r < 70)
            puts("D");
        else if (r < 80)
            puts("C");
        else if (r < 90)
            puts("B");
        else if (r < 101)
            puts("A");
        else
            puts("Score is error!");
    }
    return 0;
}
