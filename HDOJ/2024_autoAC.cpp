#include <ctype.h>
#include <stdio.h>
int main(void)
{
    int n, d, i;
    char sym[64];
    scanf("%d%*c", &n);
    while (n--)
    {
        gets(sym);
        if (sym[0] != '_' && !isalpha(sym[0]))
        {
            puts("no");
            continue;
        }
        for (d = i = 1 ; sym[i] ; i++)
        {
            if (!isalnum(sym[i]) && sym[i] != '_')
            {
                d = 0;
                break;
            }
        }
        puts(d ? "yes" : "no");
    }
    return 0;
}
