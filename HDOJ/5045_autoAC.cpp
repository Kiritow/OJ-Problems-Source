#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <map>
#include <algorithm>
using namespace std ;
typedef __int64 ll ;
double dp[1005][1050] ;
double p[15][1005] ;
int n,m ;
int main()
{
    int T ;
    scanf("%d",&T) ;
    for(int cas=1 ;cas<=T ;cas++)
    {
        scanf("%d%d",&n,&m) ;
        for(int i=0 ;i<n ;i++)
        {
            for(int j=0 ;j<m ;j++)
                scanf("%lf",&p[i][j]) ;
        }
        for(int i=0 ;i<1005 ;i++)
            for(int j=0 ;j<1050 ;j++)
                dp[i][j]=-1.0 ;
        dp[0][0]=0.0 ;
        int sm=(1<<n)-1 ;
        for(int i=0 ;i<m ;i++)
        {
            for(int s=0 ;s<=sm ;s++)
            {
                if(dp[i][s]<0.0)continue ;
                int st=0 ;
                for(int j=0 ;j<n ;j++)
                {
                    if(!((1<<j)&s))
                    {
                        st=(1<<j)|s ;
                        if(st==sm)st=0 ;
                        dp[i+1][st]=max(dp[i+1][st],dp[i][s]+p[j][i]) ;
                    }
                }
            }
        }
        double ans=0.0 ;
        for(int i=0 ;i<=sm ;i++)
            ans=max(ans,dp[m][i]) ;
        printf("Case #%d: %.5lf\n",cas,ans) ;
    }
    return 0 ;
}
