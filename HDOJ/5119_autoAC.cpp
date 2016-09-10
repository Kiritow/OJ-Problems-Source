#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
__int64 f[2][1048600];
int a[45];
int main()
{
    int t,ii,n,i,j,Min,m;
    __int64 ans;
    scanf("%d",&t);
    for (ii=1;ii<=t;ii++)
    {
        scanf("%d%d",&n,&m);
        for (i=1;i<=n;i++)
            scanf("%d",&a[i]);
        memset(f,0,sizeof(f));
        f[0][0]=1;ans=0;
        for (i=1;i<=n;i++)
            for (j=0;j<1048576;j++)
                f[i%2][j]=f[(i-1)%2][j]+f[(i-1)%2][j^a[i]];
        for (i=m;i<1048576;i++)
            ans+=f[n%2][i];
        printf("Case #%d: %I64d\n",ii,ans);
    }
}
