#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[210],b[210];
int f[210][210];
int main()
{
    int t,ii,n,i,j,k,l,Min,m;
    scanf("%d",&t);
    for (ii=1;ii<=t;ii++)
    {
        memset(f,0,sizeof(0));
        scanf("%d",&n);
        for (i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for (i=1;i<=n;i++)
            scanf("%d",&b[i]);
        for (i=1;i<=n;i++)
        {
            for (j=i;j<=n;j++)
                f[i][j]=99999999;
        }
        for (l=0;l<=n;l++)
            for (i=1;i<n+1-l;i++)
            {
                j=i+l;
                for (k=i;k<=j;k++)
                    if (f[i][k-1]+f[k+1][j]+a[k]+b[i-1]+b[j+1]<f[i][j])
                        f[i][j]=f[i][k-1]+f[k+1][j]+a[k]+b[i-1]+b[j+1];
            }
        printf("Case #%d: %lld\n",ii,f[1][n]);
    }
}
