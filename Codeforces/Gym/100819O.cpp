/// Problem O - Grid
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <queue>
using namespace std;
#define MAXM 505
#define MAXN 505
#define INF 0x3f3f3f3f
#define NINF 0xc0c0c0c0
int m,n;
char map[MAXM][MAXN];
int val[MAXM][MAXN];
struct _pos
{
    int line,col;
    _pos(int _line,int _col):line(_line),col(_col){}
};
void solve()
{
    queue<_pos> bus;
    bus.push(_pos(1,1));
    val[1][1]=0;
    /// Main Loop
    while(!bus.empty())
    {
        _pos pos=bus.front();
        bus.pop();
        int power=map[pos.line][pos.col]-'0';
        /// 4 Directions
        /// up
        if(pos.line-power>0&&val[pos.line][pos.col]+1<val[pos.line-power][pos.col])
        {
            bus.push(_pos(pos.line-power,pos.col));
            val[pos.line-power][pos.col]=val[pos.line][pos.col]+1;
        }
        /// Down
        if(pos.line+power<=m&&val[pos.line][pos.col]+1<val[pos.line+power][pos.col])
        {
            bus.push(_pos(pos.line+power,pos.col));
            val[pos.line+power][pos.col]=val[pos.line][pos.col]+1;
        }
        /// Left
        if(pos.col-power>0&&val[pos.line][pos.col]+1<val[pos.line][pos.col-power])
        {
            bus.push(_pos(pos.line,pos.col-power));
            val[pos.line][pos.col-power]=val[pos.line][pos.col]+1;
        }
        /// Right
        if(pos.col+power<=n&&val[pos.line][pos.col]+1<val[pos.line][pos.col+power])
        {
            bus.push(_pos(pos.line,pos.col+power));
            val[pos.line][pos.col+power]=val[pos.line][pos.col]+1;
        }
    }
    if(val[m][n]!=INF)
    {
        printf("%d\n",val[m][n]);
    }
    else
    {
        printf("IMPOSSIBLE\n");
    }
}


int main()
{
    scanf("%d %d%*c",&m,&n);
    for(int i=1;i<=m;i++)
    {
        gets(&map[i][1]);
    }
    memset(val,0x3f,sizeof(val));
    solve();

    /*
    /// Output Val
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            printf("%d ",val[i][j]);
        }
        printf("\n");
    }
    */
    return 0;
}
/*
5 4
2120
1203
3113
1120
1110
*/
