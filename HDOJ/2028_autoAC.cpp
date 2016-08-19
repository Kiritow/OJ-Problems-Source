#include<stdio.h>
typedef unsigned long UL;
UL gcd(UL u, UL v)
{
    int remainder;
    remainder = u % v;
    while(remainder)
    {
        u = v;
        v = remainder;
        remainder = u % v;
    }
    return v;
}
UL lcm(UL u, UL v)
{
    return u * v / gcd(u, v);
}
int main(void)
{
    int n;
    UL u;
    UL res;
    while (scanf("%d", &n) != EOF)
    {
        res = 1;
        while (n--)
        {
            scanf("%lu", &u);
            res = lcm(res, u);
        }
        printf("%lu\n", res);
    }
    return 0;
}
