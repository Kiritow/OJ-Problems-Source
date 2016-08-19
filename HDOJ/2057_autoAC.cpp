#include<stdio.h>
int main()
{
    __int64 m,n;
    while(~scanf("%I64X%I64X",&m,&n))
    {
        m=m+n;
        if(m<0){m=-m;printf("-%I64X\n",m);}
                  else printf("%I64X\n",m);
    }
}
