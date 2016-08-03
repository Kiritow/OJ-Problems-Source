#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

#define MOD 100000000

#define _BITMOVE(x) (1<<x)
#define _BITMAX(x) _BITMOVE(x)
#define _BITMAXVALUE(x) (_BITMAX(x)-1)u

#define MAXLINE 13
#define MAXSTATUS _BITMAX(MAXLINE)

typedef unsigned long STATE;
STATE map[MAXLINE];
int dp[MAXLINE][MAXSTATUS];
STATE availableStatus[MAXSTATUS];


inline STATE HasNeighbor(STATE x)
{
    return x&(x<<1);
}

inline STATE PlaceOnMap(int line,int stateid)
{
    return map[line]&availableStatus[stateid];
}

inline STATE CheckBetweenLines(int line1,int line2)
{
    return availableStatus[line1]&availableStatus[line2];
}
void init()
{

}
void solve(int n,int m)
{
    for(int i=0;i<n;i++)
    {
        STATE thisline=0;
        for(int j=0;j<m;j++)
        {
            int tmp;
            scanf("%d",&tmp);
            thisline=(thisline<<1)|tmp;
        }
        map[i]=~thisline;
    }
    ///求所有保证两头牛不相邻的状态
    int statusCount=-1;
    for(int ci=0;ci<_BITMAX(m);ci++)
    {
        if(!HasNeighbor(ci))
        {
            availableStatus[++statusCount]=ci;
        }
    }
    ///重要！
    ++statusCount;
    /// Initialize the Line 0 . Check all available status.
    for(int ci=0;ci<statusCount;ci++)
    {
        if(!PlaceOnMap(0,ci))
        {
            dp[0][ci]=1;
        }
    }
    /// Main DP
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<statusCount;j++)
        {
            ///不能使用序号为j的放置方法
            if(PlaceOnMap(i,j)) continue;
            ///纵向检查
            for(int k=0;k<statusCount;k++)
            {
                ///上一行使用序号为j的放置方法是没用的
                if(PlaceOnMap(i-1,k)) continue;
                ///检查两行之间是否有相邻
                if(!CheckBetweenLines(k,j))
                {
                    ///没有的话可以加上
                    dp[i][j]+=dp[i-1][k];
                }
            }
        }
    }
    ///将最后一行加起来
    int ans=0;
    for(int ci=0;ci<statusCount;ci++)
    {
        ans=(ans+dp[n-1][ci])%MOD;
    }
    printf("%d\n",ans);
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    solve(n,m);
    return 0;
}
