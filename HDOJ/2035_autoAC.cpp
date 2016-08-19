#include <stdio.h>
int mi(int n, int m)
{
    return m?(m%2?(mi(n, m/2)*mi(n, m/2)*(n%1000))%1000:(mi(n,m/2)*mi(n,m/2))%1000):1;
}
int main(void)
{
    int n, m;
    while(scanf("%d%d", &n, &m), n+m)
        printf("%d\n", mi(n, m));
    return 0;
}
