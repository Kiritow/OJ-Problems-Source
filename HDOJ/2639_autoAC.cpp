#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAXN 105
#define MAXV 1005
int MyMax(int a,int b)
{
    return (a>b?a:b);
}
int main()
{
    int t,n,v,m;
    while(scanf("%d",&t)!=EOF)
    {
        while(t--)
        {
            int i,j,k,tag;
            int val[MAXN],vol[MAXN],dp[MAXV][35];
            int a[35],b[35];
            scanf("%d%d%d",&n,&v,&m);
            for(i=1;i<=n;i++)
            {
                scanf("%d",&val[i]);
            }
            for(i=1;i<=n;i++)
            {
                scanf("%d",&vol[i]);
            }
            memset(dp,0,sizeof(dp));
            tag=1;
            for(i=1;i<=n;i++)
            {
                for(j=v;j>=vol[i];j--)
                {
                    for(k=1;k<=m;k++)
                    {
                        a[k]=dp[j-vol[i]][k]+val[i];
                        b[k]=dp[j][k];
                    }
                    int x,y,z;
                    x=y=z=1;
                    a[k]=b[k]=-1;
                    while(z<=m&&(y<=m||x<=m))
                    {
                        if(a[x]>b[y])
                        {
                            dp[j][z]=a[x++];
                        }
                        else
                        {
                            dp[j][z]=b[y++];
                        }
                        if(dp[j][z]!=dp[j][z-1])
                        {
                            z++;
                        }
                    }
                }
            }
            printf("%d\n",dp[v][m]);
        }
    }
    return (0);
}
