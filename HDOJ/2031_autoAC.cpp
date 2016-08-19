#include <stdio.h>
#include <string.h>
void ttor(int n, int r)
{
    if (n)
    {
        ttor(n / r, r);
        printf("%c", n % r > 9 ? n % r - 10 + 'A' : n % r + '0');
    }
}
int main(void)
{
    int n;
    int r;
    while (scanf("%d%d", &n, &r) != EOF)
    {
        if (n > 0)
            ttor(n, r);
        else if (!n)
            putchar('0');
        else
        {
            putchar('-');
            ttor(-n, r);
        }
        putchar('\n');
    }
    return 0;
}
