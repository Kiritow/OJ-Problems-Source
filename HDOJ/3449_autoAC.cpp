#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int Ni = 55;
const int Mi = 100005;
int dp[Ni][Mi];
int main()
{
    int n,m,tv,i,j,k,pi,c,w;
    memset(dp[0],0,sizeof(dp[0]));
    while(~scanf("%d%d",&n,&tv))
    {
        for(i=1;i<=n;i++)
        {
            scanf("%d%d",&pi,&m);
            for(j=0;j<pi;j++) dp[i][j]=-1;
            for(j=tv;j>=pi;j--) dp[i][j]=dp[i-1][j-pi];
            for(k=0;k<m;k++)
            {
                scanf("%d%d",&c,&w);
                for(j=tv;j>=c;j--) if(dp[i][j-c]!=-1)
                 dp[i][j]=max(dp[i][j],dp[i][j-c]+w);
            }
            for(j=tv;j>=0;j--) dp[i][j]=max(dp[i][j],dp[i-1][j]);
        }
        printf("%d\n",dp[n][tv]);
    }
    return 0;
}
