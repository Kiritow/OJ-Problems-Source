#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <algorithm>
using namespace std;

#define MAXN 205

/** == ACM Templates == BEGIN */
#define INF 0x3f3f3f3f
#define NINF 0xc0c0c0c0
/** == ACM Templates == END */

int dpa[MAXN][MAXN];
int dpb[MAXN][MAXN];
int G[MAXN][MAXN];
int ans;
int m,n;

void newinstance()
{
    memset(G,0,sizeof(int)*MAXN*MAXN);
    scanf("%d %d",&m,&n);
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&G[i][j]);
        }
    }
}
void solve()
{
    memset(dpa,0xc0,sizeof(int)*MAXN*MAXN);
    memset(dpb,0xc0,sizeof(int)*MAXN*MAXN);
    /// Initial Money
    dpa[0][1]=0;
    /// Must move from up to down in 1st col.
    for(int i=1;i<=m;i++)
    {
        dpa[i][1]=dpa[i-1][1]+G[i][1];
    }
    /// From Col 2, Mr.Dudu can move from up to down or from down to up.
    /// But the move from right to left is not allowed.
    for(int j=2;j<=n;j++)
    {
        /// From Up to Down, Accepted Move: From left, from up
        for(int i=1;i<=m;i++)
        {
            dpa[i][j]=max(max(dpa[i][j-1],dpb[i][j-1]),dpa[i-1][j])+G[i][j];
        }
        /// From down to up, Accepted Move: From Left, from down.
        for(int i=m;i>=1;i--)
        {
            dpb[i][j]=max(max(dpa[i][j-1],dpb[i][j-1]),dpb[i+1][j])+G[i][j];
        }
    }
    ans=max(dpa[1][n],dpb[1][n]);
}
/*
void printDP()
{
    printf("DP:A\n");
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            printf("%3d ",dpa[i][j]);
        }
        printf("\n");
    }
    printf("DP:B\n");
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            printf("%3d ",dpb[i][j]);
        }
        printf("\n");
    }
}
//*/
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        newinstance();
        solve();
        //printDP();
        printf("Case #%d:\n%d\n",i,ans);
    }
    return 0;
    //*/
}
