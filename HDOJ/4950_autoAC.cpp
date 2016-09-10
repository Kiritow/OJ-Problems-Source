#include <stdio.h>
int main()
{
    __int64 h,a,b,k,cas=1;
    while(~scanf("%I64d%I64d%I64d%I64d",&h,&a,&b,&k),h+a+b+k)
    {
        if(a>=h||(a-b)*k-b>0||(a-b)*(k-1)+a>=h)
            printf("Case #%I64d: YES\n",cas++);
        else
            printf("Case #%I64d: NO\n",cas++);
    }
    return 0;
}
