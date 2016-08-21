#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int main()
{
    int a[105],b[105],i;
    int n;
    while(scanf("%d",&n)&&n)
    {
        int sum,sum1;
        sum=sum1=0;
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(i=0;i<n;i++)
            scanf("%d",&b[i]);
        sort(a,a+n);
        sort(b,b+n);
        for(i=0;i<n;i++)
        {
            if(a[i]==b[i])
            {
                sum++;
                sum1++;
            }
            if(a[i]>b[i])
                sum+=2;
            if(a[i]<b[i])
                sum1+=2;
        }
        printf("%d vs %d\n",sum,sum1);
    }
    return 0;
}
