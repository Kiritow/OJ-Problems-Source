#include<stdio.h>
int main ()
{
    int T, n;
    for(scanf("%d", &T); T; T--)
    {
        scanf("%d", &n);
        printf("%d\n", n * n %10000);
    }
    return 0;
}
