#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

#define _BITMOVE(x) (1<<x)
#define _BITMAX(x) _BITMOVE(x)
#define _BITMAXVALUE(x) (_BITMAX(x)-1)

#define MAXLINE 105
#define MAXSTATUS _BITMAX(12)

#define ESTIMATED_MAXSTATUS 129+1

typedef unsigned long STATE;
STATE map[MAXLINE];
int dp[MAXLINE][ESTIMATED_MAXSTATUS][ESTIMATED_MAXSTATUS];
STATE availableStatus[ESTIMATED_MAXSTATUS];
int countOfOne[ESTIMATED_MAXSTATUS];

char _tmpbuff[8];

inline bool isGoodState(STATE x)
{
    if(x&(x<<1)) return false;
    if(x&(x<<2)) return false;
    return true;
}

inline STATE PlaceOnMap(int line,int stateid)
{
    return map[line]&availableStatus[stateid];
}

inline STATE CheckBetweenLines(int line1,int line2)
{
    return availableStatus[line1]&availableStatus[line2];
}

inline int getCountOfOneByState(STATE x)
{
    int c=0;
    while(x>0)
    {
        if(x&1) ++c;
        x=x>>1;
    }
    return c;
}

int solve(int n,int m)
{
    memset(dp,-1,sizeof(int)*MAXLINE*ESTIMATED_MAXSTATUS*ESTIMATED_MAXSTATUS);
    memset(map,0,sizeof(STATE)*MAXLINE);

    for(int i=0;i<n;i++)
    {
        gets(_tmpbuff);
        for(int j=0;j<m;j++)
        {
            int tmp=(_tmpbuff[j]=='P')?0:1;
            map[i]=(map[i]<<1)|tmp;
        }
    }
    if(n==1&&m==1)
    {
        if(map[0]>0) printf("0\n");
        else printf("1\n");
        return 0;
    }
    int statusCount=-1;
    for(STATE ci=0;ci<(STATE)_BITMAX(m);ci++)
    {
        if(isGoodState(ci))
        {
            availableStatus[++statusCount]=ci;
            countOfOne[statusCount]=getCountOfOneByState(ci);
        }
    }
    ++statusCount;
    /// Initialize the Line 0 with all available status.
    for(int ci=0;ci<statusCount;ci++)
    {
        if(!PlaceOnMap(0,ci))
        {
            dp[0][ci][0]=countOfOne[ci];
        }
    }
    /// Main DP
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<statusCount;j++)
        {
            if(PlaceOnMap(i,j)) continue;

            /// Last Line
            for(int k=0;k<statusCount;k++)
            {
                if(CheckBetweenLines(j,k)) continue;

                /// Last Last Line
                for(int x=0;x<statusCount;x++)
                {
                    if(CheckBetweenLines(k,x)) continue;
                    if(CheckBetweenLines(j,x)) continue;

                    if(dp[i-1][k][x]==-1) continue;

                    dp[i][j][k]=max(dp[i][j][k],dp[i-1][k][x]+countOfOne[j]);
                }
            }
        }
    }
    /// Calculate the answer
    int ans=-1;
    for(int ci=0;ci<statusCount;ci++)
    {
        for(int cj=0;cj<statusCount;cj++)
        {
            ///此处是max运算,因为结果要求最大值
            ans=max(ans,dp[n-1][ci][cj]);
        }
    }
    printf("%d\n",ans);
    return 0;
}

int main()
{
    /**
    /// A Program To Estimate the max value of statusCount
    /// The answer is 129

    int statusCount=-1;
    for(STATE ci=0;ci<MAXSTATUS;ci++)
    {
        if(isGoodState(ci))
        {
            availableStatus[++statusCount]=ci;
            countOfOne[statusCount]=getCountOfOneByState(ci);
        }
    }
    ++statusCount;
    printf("%d\n",statusCount);
    */
    int n,m;
    /// %*c重要！
    while(scanf("%d %d%*c",&n,&m)==2)
    {
        solve(n,m);
    }
    return 0;
}
