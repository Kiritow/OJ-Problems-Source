#include<iostream>
#include<string.h>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
int a[2001][2001];
int main()
{
    int i,t,j,n,sum;
    memset(a,0,sizeof(a));
    a[1][1]=1;
    for(i=2;i<2001;i++)
    {
        for(j=1;j<=i;j++)
        {
            a[i][j]=a[i-1][j]*j+a[i-1][j-1];
            a[i][j]%=1000;
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
                sum%=1000;
            }
            printf("%d\n",sum);
        }
    }
    return 0;
}
