#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int dp[(1<<16)+2][10][4];
int map[17][17];
int bit[(1<<16)+2];
int main()
{
    int i,j,n,cnt,k,l,m,p,a,ans;
    for (i=0;i<(1<<16);i++)
    {
        cnt=0;
        for (j=0;j<16;j++)
        {
            if ((i & (1<<j))!=0) cnt++;
        }
        bit[i]=cnt;
    }
    while(1)
    {
        scanf("%d",&n);
        if (n==0) break;
        for (i=0;i<n;i++)
        {
            for (j=0;j<n;j++)
            {
                scanf("%d",&map[i][j]);
            }
        }
        memset(dp,-1,sizeof(dp));
        ans=0;
        dp[0][0][0]=0;
        for (i=0;i<(1<<n);i++)
        {
            for (j=0;j<(1<<3);j++)
            {
                for (k=0;k<3;k++)
                {
                    if (dp[i][j][k]==-1) continue;
                    ans=max(ans,dp[i][j][k]);
                    if (k==3) continue;
                    for (l=0;l<n;l++)
                    {
                        if ((i & (1<<l))!=0) continue;
                        p=(i | (1<<l));
                        cnt=bit[p]-1;
                        if (map[l][cnt]==0)
                        {
                            dp[p][j][k+1]=max(dp[p][j][k+1],dp[i][j][k]);
                        }
                        if (map[l][cnt]==1)
                        {
                            if (k==2) continue;
                            if ((j & 4)!=0) dp[p][(j<<1) & 7][k+1]=max(dp[p][(j<<1) & 7][k+1],dp[i][j][k]+1);
                            else dp[p][(j<<1) & 7][k+1]=max(dp[p][(j<<1) & 7][k+1],dp[i][j][k]);
                        }
                        if (map[l][cnt]==2)
                        {
                            if ((j & 4)!=0) dp[p][((j<<1) & 7)+1][k]=max(dp[p][((j<<1) & 7)+1][k],dp[i][j][k]+1);
                            else dp[p][((j<<1) & 7)+1][k]=max(dp[p][((j<<1) & 7)+1][k],dp[i][j][k]);
                        }
                        if (map[l][cnt]==3)
                        {
                            dp[p][0][k]=max(dp[p][0][k],dp[i][j][k]+((j & 1)!=0)+((j & 2)!=0)+((j & 4)!=0)+1);
                        }
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
