#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[1000010];
int main()
{
    int t,ii,n,i,Min,ans;
    scanf("%d",&t);
    for (ii=1;ii<=t;ii++)
    {
        scanf("%d",&n);
        for (i=1;i<=n;i++)
            scanf("%d",&a[i]);
        Min=a[n];
        ans=0;
        for (i=n-1;i>=1;i--)
        {
            if (a[i]>Min) ans++;
                else Min=a[i];
        }
        printf("Case #%d: %d\n",ii,ans);
    }
}
