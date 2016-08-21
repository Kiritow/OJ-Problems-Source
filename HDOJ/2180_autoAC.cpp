#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a,b,s,t;
    int res1, res2, res;
    while(1)
    {
        scanf("%d%d%d%d", &a, &b, &s, &t);
        if(a == 0 && b == 0 && s == 0 && t == 0)
            break;
        a = a%12;
        s = s%12;
        res1 = (a*60+b)*11;
        res2 = (s*60+t)*11;
        if(res2 < res1)
            res2 += 720*11;
        res = res2/720 - res1/720;
        if(res1 == 0)
            res++;
        printf("%d\n", res);
    }
    return 0;
}
