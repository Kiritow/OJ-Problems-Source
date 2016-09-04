#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int a[1005],sum[1005];
int main()
{
    int n,i;
    while(scanf("%d",&n)!=EOF)
    {
        memset(sum,0,sizeof(sum));
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        sort(a+1,a+1+n);
        for(i=1;i<=n;i++)
            sum[i]=sum[i-1]+a[i];
        for(i=1;i<=n;i++)
        {
            if(a[i]>sum[i-1]+1)
                break;
        }
        printf("%d\n",sum[i-1]+1);
    }
    return 0;
}
