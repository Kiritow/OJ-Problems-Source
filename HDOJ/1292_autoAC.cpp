#include<iostream>
#include<string.h>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
__int64 a[30][30];
int main()
{
    int i,j;
    int t,n;
    __int64 sum;
    memset(a,0,sizeof(a));
    a[1][1]=1;
    for(i=2;i<26;i++)
    {
        for(j=1;j<=i;j++)
        {
            a[i][j]=a[i-1][j-1]+a[i-1][j]*j;
        }
    }
    while(~scanf("%d",&t))
    {
        while(t--)
        {
            scanf("%d",&n);
            sum=0;
            for(i=1;i<=n;i++)
            {
                sum+=a[n][i];
            }
            printf("%I64d\n",sum);
        }
    }
    return 0;
}
