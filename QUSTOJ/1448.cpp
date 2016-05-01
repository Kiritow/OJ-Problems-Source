#include <stdio.h>
int main()
{
    int all,rep,i,ans;
    scanf("%d",&all);
    for(;all>0;all--)
    {
        scanf("%d",&rep);
        ans=3;
        for(i=0;i<rep;i++)
        {
            ans=(ans-1)*2;
        }
        printf("%d\n",ans);
    }
    return 0;
}
