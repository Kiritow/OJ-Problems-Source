#include <stdio.h>
int main()
{
    int a[6],i,t;
    scanf("%d",&t);
    while(t--)
    {
        for(i=0;i<6;i++)
            scanf("%d",&a[i]);
        for(i=0;i<3;i++)
        {
            if(a[i]>a[i+3])
            {
                printf("First\n");
                break;
            }else if(a[i]<a[i+3])
            {
                printf("Second\n");
                break;
            }else if(i==2)printf("Same\n");
        }
    }
    return 0;
}
