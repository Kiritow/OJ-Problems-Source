#include <stdio.h>
int main(void)
{
    int n, i;
    int t[6];
    scanf("%d", &n);
    while (n--)
    {
        for (i = 0 ; i < 6 ; i++)
            scanf("%d", t + i);
        t[1] += (t[2] + t[5]) / 60;
        t[2] = (t[2] + t[5]) % 60;
        t[0] += (t[1] + t[4]) / 60;
        t[1] = (t[1] + t[4]) % 60;
        t[0] += t[3];
        printf("%d %d %d\n", t[0], t[1], t[2]);
    }
    return 0;
}
