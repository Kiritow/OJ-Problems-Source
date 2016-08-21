#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stack>
#include <iostream>
#include<algorithm>
#include<queue>
using namespace std;
#define M 505
__int64 a[M],sum[M];
int main()
{
    __int64 n,i,j,k,t;
    while(~scanf("%I64d",&n))
    {
        if(n==0)
            break;
        for(i=1;i<=n;i++)
        {
            scanf("%I64d",&a[i]);
        }
        memset(sum,0,sizeof(sum));
        for(i=n;i>=1;i--)
        {
            sum[i]=sum[i+1]+a[i];
        }
        j=0;
        for(i=n;i>=1;i--)
        {
            t=0;
            for(k=n;k>i;k--)
            {
                t+=sum[k];
            }
            t+=a[i];
            sum[k]=t;
            j+=t;
        }
        printf("%I64d\n",j);
    }
    return 0;
}
