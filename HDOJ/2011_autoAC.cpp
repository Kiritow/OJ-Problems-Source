#include<stdio.h>
int n;
double rev(int c)
{
    return c <= n ?( ((c & 1) ? 1.0 : -1.0) / c + rev(c + 1) ): 0 ;
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t-- && scanf("%d", &n))
        printf("%.2lf\n", rev(1));
    return 0;
}
