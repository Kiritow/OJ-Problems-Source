#include <cstdio>
int main ()
{
    int i;
    int n, m;
    int a[101] = {0};
    for ( i=1 ; i<101 ; i++ )
        a[i] = a[i - 1] + i;
    scanf ("%d", &i);
    while ( i-- )
    {
        scanf ("%d %d", &n, &m);
        printf ("%d\n", a[n] * a[m]);
    }
}
