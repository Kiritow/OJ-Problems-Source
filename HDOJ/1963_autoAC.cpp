#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
struct node
{
    int v,w;
}a[20];
int dp[100000];
int main()
{
    int t,n,i,j,k,val,y;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&val,&y);
        scanf("%d",&n);
        for(i = 1;i<=n;i++)
        {
            scanf("%d%d",&a[i].v,&a[i].w);
            a[i].v/=1000;
        }
        for(i = 1;i<=y;i++)
        {
            int s = val/1000;
            memset(dp,0,sizeof(dp));
            for(j = 1;j<=n;j++)
            {
                for(k = a[j].v;k<=s;k++)
                {
                    dp[k]=max(dp[k],dp[k-a[j].v]+a[j].w);
                }
            }
            val+=dp[s];
        }
        printf("%d\n",val);
    }
    return 0;
}
