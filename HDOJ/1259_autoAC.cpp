#include <stdio.h>
int main()
{
    int n,i,t1,t2;
    scanf("%d",&n);
    while(n--)
    {
        int sum=2;
        int m;
        scanf("%d",&m);
        for(i=1;i<=m;i++)
        {
            scanf("%d%d",&t1,&t2);
            if(t2==sum)
                sum=t1;
            else    if(t1==sum)
                sum=t2;
        }
        printf("%d\n",sum);
    }
}
