#include<stdio.h>
#include<math.h>
int main()
{
    __int64 t, a, b, c, n, m, k;
    scanf("%I64d",&t);
    while(t--)
    {
        scanf("%I64d%I64d%I64d%I64d%I64d%I64d",&a,&b,&c,&n,&m,&k);
        __int64 s = 4 * a * a * b * b - (a * a + b * b - c * c) * (a * a + b * b - c * c);
        __int64 tmp = sqrt(s);
        if(tmp * tmp == s)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
