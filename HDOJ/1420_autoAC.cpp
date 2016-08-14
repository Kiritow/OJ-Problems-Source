#include<stdio.h>
int main()
{
    __int64 a,b,c,i,n,f,d,e;
    scanf("%I64d",&n);
    while(n--)
    {
        scanf("%I64d%I64d%I64d",&a,&b,&c);
        f=0;
        e=a;
        for(i=1;i<=b;i++)
        {
            d=a%c;
            a=e*d;
            if(a==0)
            {
                f=1;
                printf("0\n");
                break;
            }
        }
        if(!f)
          printf("%I64d\n",d);
    }
    return 0;
}
