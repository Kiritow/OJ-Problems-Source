#include <stdio.h>
#define EPS 1e-20
__int64 exgcd(__int64 a,__int64 b,__int64 &x,__int64 &y)
{
    if(b == 0LL)
    {
        x = 1LL;
        y = 0LL;
        return a;
    }
    __int64 d = exgcd(b,a%b,x,y);
    __int64 t = x;
    x = y;
    y = t - a / b * y;
    return d;
}
int main()
{
    __int64 t,a,b,x,y,c1,d1,c2,d2,d;
    scanf("%I64d",&t);
    while(t--)
    {
        scanf("%I64d/%I64d",&a,&b);
        x = y = 0;
        d = exgcd(a,b,x,y);
        if(d != 1)
        {
            printf("%I64d/%I64d\n",a/d,b/d);
            continue;
        }
        if(a == 1)
        {
            printf("1/%I64d\n",b-1);
            continue;
        }
        while(x < 0)
            x += b;
        d1 = x;
        c1 = (a * d1 - 1LL) / b;
        while(y < 0)
            y += a;
        c2 = y;
        d2 = (b * c2 - 1LL) / a;
        if(d1 > d2)
            printf("%I64d/%I64d\n",c1,d1);
        else
            printf("%I64d/%I64d\n",c2,d2);
    }
    return 0;
}
