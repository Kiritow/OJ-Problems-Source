#include<stdio.h>
int main()
{
    int a[105];
    int n,i,flag,sum,k;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
            break;
        for(i=0,sum=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            sum=sum^a[i];
        }
        if(sum==0)
        {
            printf("0\n");
            continue;
        }
        for(i=0,flag=0;i<n;i++)
        {
            k=sum^a[i];
            if(k<a[i])
                flag++;
        }
        printf("%d\n",flag);
    }
    return 0;
}
