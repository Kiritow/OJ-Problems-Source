#include <stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        __int64 a,t = 0;
        int flag = 1;
        while(n--)
        {
            scanf("%I64d",&a);
           if(flag)
           {
               t = a - t;
               if(t<0)
               {
                   flag = 0;
               }
           }
        }
        if(flag && !t)
        printf("yeah~ I escaped ^_^\n");
        else
        printf("I will never go out T_T\n");
    }
    return 0;
}
