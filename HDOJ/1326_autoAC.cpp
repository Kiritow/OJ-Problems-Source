#include<stdio.h>
int main()
{
    int n,t=0,i,sum,a[100];
    int flag;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)break;
        t++;
        for(i=0,sum=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            sum=sum+a[i];
        }
        sum=sum/n;
        for(i=0,flag=0;i<n;i++)
        {
            if(a[i]>sum)
                flag=flag+a[i]-sum;
        }
        printf("Set #%d\nThe minimum number of moves is %d.\n\n",t,flag);
    }
    return 0;
}
