#include "stdio.h"
#include "math.h"
 
 int main ()
{
    int n;
    scanf ("%d", &n);
    int x=0;
    x = sqrt(n);
    int i;
    for (i=2; i<=x; i++)
    {
        if (n%i==0)
        {
            printf ("0");
            break;
        }
        if (i=x-1)
        {
            printf ("1");
            break;
        }
 
    }
 
    return 0;
}
