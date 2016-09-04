#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=1e2+10;
const int maxm=2e4+10;
const int INF=1e8;
int c[maxn],v[maxn],f[maxm],g[maxm];
int main()
{
    int n,m,tt=0;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0&&m==0)break;
        int i,j,k;
        for(i=0;i<n;i++)
            scanf("%d",&v[i]);
        for(i=0;i<n;i++)
            scanf("%d",&c[i]);
        for(i=1;i<=20000;i++)
        {
            g[i]=f[i]=INF;
        }
        f[0]=g[0]=0;
        //瀹ㄨ
        for(i=0;i<n;i++)
        {
            for(j=v[i];j<=20000;j++)
            g[j]=min(g[j],g[j-v[i]]+1);
        }
        //澶
        for(i=0;i<n;i++)
        {
            if(v[i]*c[i]>=20000)
            {
                for(j=v[i];j<=20000;j++)
                f[j]=min(f[j],f[j-v[i]]+1);
                continue;
            }
            for(k=1;k<c[i];k=k*2)
            {
                for(j=20000;j>=v[i]*k;j--)
                f[j]=min(f[j],f[j-v[i]*k]+k);
                c[i]-=k;
            }
            for(j=20000;j>=c[i]*v[i];j--)
                f[j]=min(f[j],f[j-v[i]*c[i]]+c[i]);
        }
        int ans=INF;
        for(i=m;i<=20000;i++)
            ans=min(ans,f[i]+g[i-m]);
        if(ans==INF)ans=-1;
        printf("Case %d: %d\n",++tt,ans);
    }
    return 0;
}
