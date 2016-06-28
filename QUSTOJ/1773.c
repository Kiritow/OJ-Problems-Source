#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char a[1024];
int main()
{
    gets(a);
    int L=strlen(a);
    for(int i=L-1;i>=0;i--)
    {
        printf("%c",a[i]);
    }
    printf("\n");
    return 0;
}
