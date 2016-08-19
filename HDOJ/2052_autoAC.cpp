#include <cstdio>
#include <iostream>
using namespace std;
int main ()
{
    int c,k,i,j;
    while (scanf("%d%d",&c,&k)!=EOF)
    {
        printf ("+");
        for (i=1;i<=c;i++)
            printf ("-");
        printf ("+");
        printf ("\n");
        for (i=1;i<=k;i++)
        {
            printf("|");
            for (j=1;j<=c;j++)
                printf (" ");
            printf("|");
            printf ("\n");
        }
        printf ("+");
        for (i=1;i<=c;i++)
            printf ("-");
        printf ("+");
        printf ("\n\n");
    }
    return 0;
}
