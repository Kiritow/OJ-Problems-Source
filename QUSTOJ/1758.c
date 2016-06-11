#include <stdio.h>
#include <stdlib.h>

char pool[1024];
int main()
{
    int n;
    scanf("%d%*c",&n);
    gets(pool);
    for(int i=n-1;i>=0;--i)
    {
        printf("%c",pool[i]);
    }
    return printf("\n"),0;
}

