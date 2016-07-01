#include <stdio.h>
#include <stdlib.h>
char a[256];
char b[256];
char c[256];

int main()
{
    for(int i=0;i<5;i++)
    {
        scanf("%s %s %s",a,b,c);
        printf("%s %s %s\n",a,b,c);
    }
    return 0;
}
