#include <ctype.h>
#include <stdio.h>
int main(void)
{
    int n, d;
    char c;
    scanf("%d%*c", &n);
    while (n--)
    {
        for (d = 0 ; (c = getchar()) != '\n' ;)
        {
            if (isdigit(c)) d++;
        }
        printf("%d\n", d);
    }
    return 0;
}
