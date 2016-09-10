#include<iostream>
#include<cstdio>
#include<string.h>
#define MAX  10000007
#define LL __int64
using namespace std;
int n;
LL a[MAX];
int main()
{
    LL t,m,i,j,sum,xx=1000000007;
    scanf("%I64d",&t);
    while(t--)
    {
        scanf("%I64d",&n);
        for(j=1; j<=n; j++)
        {
            scanf("%I64d",&a[j]);
        }
        a[0] = 0;
        for(j=1;j<=n;j++)
        {
            a[j] = a[j]*j+a[j-1];
            a[j] = a[j]%xx;
        }
        sum = 0;
        for(j=1;j<=n;j++)
        {
            sum = sum+a[j];
            sum = sum%xx;
        }
        printf("%I64d\n",sum);
    }
    return 0;
}
