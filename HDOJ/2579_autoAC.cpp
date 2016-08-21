#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<stack>
#include<iostream>
#include<list>
#include<set>
#include<bitset>
#include<vector>
#include<cmath>
#define INF 0x7fffffff
#define eps 1e-8
#define LL long long
#define PI 3.141592654
#define CLR(a,b) memset(a,b,sizeof(a))
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FOR_(i,a,b) for(int i=a;i>=b;i--)
#define sf scanf
#define pf printf
#define all(v) (v).begin(),(v).end()
#define acfun std::ios::sync_with_stdio(false)
#define SIZE (100 +2)
#define MOD 1000000007
using namespace std;
char g[SIZE][SIZE];
int t,n,m;
int xx[]={0,0,-1,1};
int yy[]={-1,1,0,0};
struct node
{
    int x,y,s;
    void init(int _x,int _y,int _s=0)
    {
        x=_x,y=_y,s=_s;
    }
};
node Y,G;
void bfs()
{
    bool vis[SIZE][SIZE][11];
    CLR(vis,0);
    queue<node>q;
    q.push(Y);
    vis[Y.x][Y.y][0]=1;
    while(!q.empty())
    {
        node tmp=q.front();
        q.pop();
        //pf("%d %d=%d\n",tmp.x+1,tmp.y+1,tmp.s);
        if(tmp.x==G.x&&tmp.y==G.y)
        {
            pf("%d\n",tmp.s);
            return;
        }
        FOR(k,0,4)
        {
            int x=tmp.x+xx[k];
            int y=tmp.y+yy[k];
            int s=tmp.s+1;
            if(x<0||x>=n||y<0||y>=m||vis[x][y][s%t])
                continue;
            if(g[x][y]=='#'&&s%t!=0)continue;
            node now;
            vis[x][y][s%t]=1;
            now.init(x,y,s);
            q.push(now);
        }
    }
    puts("Please give me another chance!");
}
int main()
{
    int T;
    sf("%d",&T);
    while(T--)
    {
        sf("%d%d%d",&n,&m,&t);
        FOR(i,0,n)
        {
            sf("%s",g[i]);
            FOR(j,0,m)
            {
                if(g[i][j]=='Y')
                    Y.init(i,j);
                else if(g[i][j]=='G')
                    G.init(i,j);
            }
        }
        bfs();
    }
    return 0;
}
