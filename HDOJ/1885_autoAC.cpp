#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cctype>
#include <stack>
#include <queue>
#include <stack>
#include <map>
#define inf 0x3f3f3f3f
using namespace std;
struct point
{
    int x,y,z;
};
point b;
map<char,int>gg;
int n,m;
char mp[105][105];
int vis[105][105][16];
int dir[4][2]={ {1,0},{-1,0},{0,-1},{0,1} };
void init()
{
    gg['b']=gg['B']=0;
    gg['y']=gg['Y']=1;
    gg['r']=gg['R']=2;
    gg['g']=gg['G']=3;
}
int bfs()
{
    queue<point>ss;
    ss.push(b);
    vis[b.x][b.y][b.z]=0;
    while(ss.size())
    {
        point f=ss.front();
        ss.pop();
        for(int i=0;i<4;i++)
        {
            b.x=f.x+dir[i][0];
            b.y=f.y+dir[i][1];
            b.z=f.z;
            if(mp[b.x][b.y]!='#'&&vis[b.x][b.y][b.z]==-1)
            {
                if(mp[b.x][b.y]=='X') return vis[f.x][f.y][f.z]+1;
                if(mp[b.x][b.y]=='.')
                {
                    vis[b.x][b.y][b.z]=vis[f.x][f.y][f.z]+1;
                    ss.push(b);
                    continue;
                }
                int t=gg[mp[b.x][b.y]];
                if(isupper(mp[b.x][b.y]))
                {
                    if(b.z>>t&1)
                    {
                        vis[b.x][b.y][b.z]=vis[f.x][f.y][f.z]+1;
                        ss.push(b);
                    }
                }
                else
                {
                    b.z=b.z|1<<t;
                    vis[b.x][b.y][b.z]=vis[f.x][f.y][f.z]+1;
                    ss.push(b);
                }
            }
        }
    }
    return 0;
}
int main()
{
    init();
    while(scanf("%d%d",&n,&m),n+m)
    {
        memset(mp,'#',sizeof(mp));
        memset(vis,-1,sizeof(vis));
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
            {
                scanf(" %c",&mp[i][j]);
                if(mp[i][j]=='*')
                {
                    b.x=i,b.y=j,b.z=0;
                    mp[i][j]='.';
                }
            }
        int t=bfs();
        if(t) printf("Escape possible in %d steps.\n",t);
        else printf("The poor student is trapped!\n");
    }
    return 0;
}
