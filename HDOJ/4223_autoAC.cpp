#include <stdio.h>
int abs(int s)
{
    if(s<0)
        return -s;
    return s;
}
int main()
{
    int t,n,i,j,a[1010],sum,min,k=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        min=abs(a[1]);
        for(i=2;i<=n;i++)
        {
            sum=0;
            for(j=i;j>=1;j--)
            {
                sum+=a[j];
                if(min>abs(sum))
                    min=abs(sum);
            }
        }
        printf("Case %d: %d\n",k++,min);
    }
    return 0;
}
