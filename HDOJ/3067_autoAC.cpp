#include <stdio.h>
int main()
{
    int i,a,n,sum,ans;
    while(~scanf("%d",&n))
    {
        for(i = 0,sum = 0; i<n; i++,sum+=a)
            scanf("%d",&a);
        for(i = 1; i<sum; i++)
        {
            if(sum==(1+i)*i/2)
            {
                ans = 1;
                break;
            }
            if(sum<(1+i)*i/2)
            {
                ans = i;
                break;
            }
        }
        if(sum == 2)
        ans = 2;
        printf("yes\n%d\n",ans);
    }
    return 0;
}
