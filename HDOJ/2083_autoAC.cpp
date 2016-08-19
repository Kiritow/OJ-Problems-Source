#include<stdio.h>
#include<math.h>
int main()
{
    int t;
    int a[10000];
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int i;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        int min;
        int sum=0;
        int j;
        for(i=0;i<n;i++)
        {
            sum=0;
           for(j=0;j<n;j++)
           {
               sum+=fabs(a[i]-a[j]);
           }    
           if(i==0)
           min=sum;
           if(sum<min)
           min=sum;
        }
        printf("%d\n",min);
    }
    return 0;
}
