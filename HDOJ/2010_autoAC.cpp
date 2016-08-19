#include<stdio.h>
int main()
{
    int b, l, c, i;
    int a[] = {1, 153, 370, 371, 407};
    while (scanf("%d%d", &b, &l) != EOF)
    {
        c = 0;
        for (i = 0 ; i < 5 ; i++)
        {
            if (a[i] >= b && a[i] <= l)
                printf(c++ ? " %d" : "%d", a[i]);
        }
        printf(c ? "\n" : "no\n");
    }
    return 0;
}
