#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
#define max(a,b) (a>b?a:b)
int b[2000];
int a[2000];
int main()
{
    int i,n,j,m,tm;
    while(~scanf("%d",&n))
    {
        if(n==0)break;
        for(i=0;i<n;i++)
        {
            scanf("%d",&b[i]);
        }
        scanf("%d",&m);
        tm=m-5;
        if(tm<0){printf("%d\n",m);continue;}
        sort(b,b+n);
        memset(a,0,sizeof(a));
        for(i=0;i<=tm;i++)
        {
            if(b[0]<=i)
            {
                a[i]=b[0];
            }
        }
        for(i=1;i<n-1;i++)
        {
            for(j=tm;j>=0;j--)
            {
                if(j>=b[i])
                {
                    a[j]=max(a[j],a[j-b[i]]+b[i]);
                }
            }
        }
        m=m-a[tm]-b[n-1];
        printf("%d\n",m);
    }
    return 0;
}
