#include <stdio.h>
#include <string.h>
int main(void)
{
    int n;
    char s[1024];
    char t[1024];
    scanf("%d%*c", &n);
    while (n--)
    {
        gets(s);
        strcpy(t, s);
        strrev(s);
        puts(strcmp(t, s) ? "no" : "yes");
    }
    return 0;
}
