#include <stdio.h>
#define x 1000000
#define max(a,b) a>b?a:b
int i,n,T,Max;
int a[x];
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        __int64 sum=0;
        scanf("%d",&n);
        Max=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];        
            Max=max(Max,a[i]); 
        }
        sum=sum-Max+1; 
        if(sum>=Max) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
