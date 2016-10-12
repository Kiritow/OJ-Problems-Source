#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int t;
int N1,N2,N3,D1,D2,D3;

#define MAXN 55

///   Left1 Left2 Left3 T.. D.. (T: Fruit of yesterday. D: Day of the last fruit)
LL dp[MAXN][MAXN][MAXN][3][MAXN];

#define TOMOD 1000000007


#define return_if_neq(ValToReturn,ValToCmp) do{if(ValToReturn!=ValToCmp) return ValToReturn;}while(0)

LL dfs(int Left1,int Left2,int Left3,int Type,int Day)
{
    if(Left1<0||Left2<0||Left3<0) return 0;
    switch(Type)
    {
        case 0:if(Day>D1) return 0;else break;
        case 1:if(Day>D2) return 0;else break;
        case 2:if(Day>D3) return 0;else break;
    }
    if(Left1==0&&Left2==0&&Left3==0)
    {
        /// N1,N2,N3: Two of them must be 0, and 1 of them is used directly.
        #ifdef __LOCAL__
        dp[Left1][Left2][Left3][Type][Day]=1;
        #endif // __LOCAL__
        return 1;
    }
    if(dp[Left1][Left2][Left3][Type][Day]!=-1)
    {
        return dp[Left1][Left2][Left3][Type][Day];
    }
    LL tmp=0;
    LL ta,tb,tc;
    switch(Type)
    {
    case 0:
        {
            ta=dfs(Left1-1,Left2,Left3,0,Day+1)%TOMOD;
            tb=dfs(Left1,Left2-1,Left3,1,1)%TOMOD;
            tc=dfs(Left1,Left2,Left3-1,2,1)%TOMOD;
            tmp=(ta+tb+tc)%TOMOD;
            break;
        }
    case 1:
        {
            ta=dfs(Left1-1,Left2,Left3,0,1)%TOMOD;
            tb=dfs(Left1,Left2-1,Left3,1,Day+1)%TOMOD;
            tc=dfs(Left1,Left2,Left3-1,2,1)%TOMOD;
            tmp=(ta+tb+tc)%TOMOD;
            break;
        }
    case 2:
        {
            ta=dfs(Left1-1,Left2,Left3,0,1)%TOMOD;
            tb=dfs(Left1,Left2-1,Left3,1,1)%TOMOD;
            tc=dfs(Left1,Left2,Left3-1,2,Day+1)%TOMOD;
            tmp=(ta+tb+tc)%TOMOD;
            break;
        }
    }
    return dp[Left1][Left2][Left3][Type][Day]=tmp;
}
//#define __LOCAL__
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d %d %d %d",&N1,&N2,&N3,&D1,&D2,&D3);
        memset(dp,-1,sizeof(dp));
        LL ta=dfs(N1-1,N2,N3,0,1)%TOMOD;
        LL tb=dfs(N1,N2-1,N3,1,1)%TOMOD;
        LL tc=dfs(N1,N2,N3-1,2,1)%TOMOD;
        LL ans=(ta+tb+tc)%TOMOD;
        #ifdef __LOCAL__
        printf("%I64d\n",ans);
        for(int i=0;i<N1;i++)
        {
            for(int j=0;j<N2;j++)
            {
                for(int k=0;k<N3;k++)
                {
                    for(int x=0;x<3;x++)
                    {
                        for(int y=0;y<MAXN;y++)
                        {
                            if(dp[i][j][k][x][y]!=-1)printf("dp[%d][%d][%d][%d][%d]=%I64d\n",i,j,k,x,y,dp[i][j][k][x][y]);
                        }
                    }
                }
            }
        }
        #else
        printf("%lld\n",ans);
        #endif // __LOCAL__
    }
    return 0;
}
