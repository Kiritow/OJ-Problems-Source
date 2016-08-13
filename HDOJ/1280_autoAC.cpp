#include<stdio.h>
#include <algorithm>
using namespace std;
#include <string.h>
    int a[5005];
    int b[5000005];
int main()
{
    int i,j,n,m,l,count;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        l=count=0;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        sort(a+1,a+1+n);
        for(i=n;i>=1;i--)
            for(j=i-1;j>=0;j--)
            {
                count++;
                b[l++]=a[i]+a[j];
                if(count==n*(n-1)/2)
                    break;
            }
            sort(b,b+l);
            for(i=l-1;m>0;m--,i--)
            {
                if(m!=1)
                    printf("%d ",b[i]);
                else
                    printf("%d\n",b[i]);
            }
    }
    return 0;
}
