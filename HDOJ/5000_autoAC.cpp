#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std ;
const int mod=1000000007 ;
int T[2005],dp[2005][2005] ;
int main()
{
    int t ;
    scanf("%d",&t) ;
    while(t--)
    {
        int n ;
        scanf("%d",&n) ;
        int sum=0 ;
        for(int i=0 ;i<n ;i++)
        {
            scanf("%d",&T[i]) ;
            sum+=T[i] ;
        }
        memset(dp,0,sizeof(dp)) ;
        for(int i=0 ;i<=T[0] ;i++)
            dp[0][i]=1 ;
        sum>>=1 ;
        for(int i=1 ;i<n ;i++)
        {
            for(int j=0 ;j<=sum ;j++)
            {
                for(int k=0 ;k<=T[i] ;k++)
                {
                    if(j<k)break ;
                    dp[i][j]=(dp[i][j]+dp[i-1][j-k])%mod ;
                }
            }
        }
        printf("%d\n",dp[n-1][sum]) ;
    }
    return 0 ;
}
