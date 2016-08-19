#include <ctype.h>
#include <stdio.h>
int main(void)
{
    char t[128] = {' '};
    int i;
    while (gets(t + 1))
    {
        for (i = 1 ; t[i] ; i++)
            putchar((isalpha(t[i]) && t[i-1] == ' ') ? toupper(t[i]) : t[i]);
        putchar('\n');
    }
    return 0;
}
