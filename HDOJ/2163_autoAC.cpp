#include <stdio.h>
#include <string.h>
int main()
{
    char a[100],b[100];
    int cases=0;
    while(gets(a)&&strcmp(a,"STOP")!=0)
    {
        cases++;
        strcpy(b,a);
        strrev(a);
        if (strcmp(a,b)==0)
        {
             printf("#%d: YES\n",cases);
        }
        else
        {
             printf("#%d: NO\n",cases);
        }
    }
}
