#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char a[1024];
char b[1024];
char c[1024];
int main()
{
    gets(a);
    gets(b);
    int L=strlen(b);
    int i;
    for(i=0;i<L;i++)
    {
        c[L-1-i]=b[i];
    }
    printf("%s%s\n",a,c);
    return 0;
}
