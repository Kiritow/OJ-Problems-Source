#include <stdio.h>
int main ()
{
    int n,s,d;
    scanf ("%d",&n);
    while (n--)
    {
        scanf ("%d%d",&s,&d);
        if ((s+d)%2==0&&(s-d)%2==0&&(s+d)/2>=0&&(s-d)/2>=0)
            printf ("%d %d",(s+d)/2,(s-d)/2);
        else printf ("impossible");
        printf ("\n");
    }
    return 0;
}
