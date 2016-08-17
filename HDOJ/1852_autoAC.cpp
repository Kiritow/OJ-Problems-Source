#include <stdio.h>
#include <stdlib.h>
#include "math.h"
__int64 powmod(int d, int n, int k)
{
    __int64 a,b;
    if((n==0) || (d == 1))
        return 1;
    for(a = d,b = 1; n>0; n=n/2)
    {
        if(n%2 == 1)
        {
            b = (b*a)%k;
        }
        a = (a*a)%k;
    }
    return b%k;
}
__int64 cacul_sum(int d, int n, int k)
{
    int l;
    __int64 t1,t2,r;
    l = (d-1)*k;
    t1 = powmod(d, n+1, l);
    t2 = (t1+l-1)%l;
    r = t2/(d-1);
    return r;
}
int cacul_res(int n, int k)
{
    __int64 m1,m2,m,r;
    m1 = cacul_sum(251, n, k);
    m2 = cacul_sum(2, 3*n, k);
    m = (m1*m2)%k;
    r = powmod(2008, m, k);
    return r;
}
int main()
{
    int n,k;
    __int64 r;
    while(1)
    {
        scanf("%d%d", &n, &k);
        if((n==0)&&(k==0))
            break;
        r = cacul_res(n,k);
        printf("%I64d\n", r);
    }
    return 0;
}
