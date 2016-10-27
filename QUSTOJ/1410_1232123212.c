#include "stdio.h"
 
 int main ()
{
    int n;
    scanf ("%d", &n);
    int i, a=0;
    for (i=1; ; i++)
    {
        int x=0;
        x = i*i*i;
        a += x;
        if (a>n)
        {
            break;
        }
    }
    printf ("%d", i-1);
 
    return 0;
}
