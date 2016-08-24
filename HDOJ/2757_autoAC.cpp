#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int sx,sy,ex,ey;
char a[1002][1002];
int b[1002][1002];
int dir[8][2]={0,-1,1,-1,1,0,1,1,0,1,-1,1,-1,0,-1,-1};
struct fuck{
     int x, y,t;
    friend bool operator< (const fuck &a, const fuck &b)
    {
        return a.t>b.t;
    }
}f;
priority_queue<fuck> q;
int bfs()
{
    int nx,ny,nt,x,y,t,i;
    if(sx==ex&&sy==ey)
        return 0;
    f.x=sx;f.y=sy;f.t=0;
    q.push(f);
    b[sx][sy]=0;
    while(!q.empty())
    {
        x=q.top().x;
        y=q.top().y;
        t=q.top().t;
        q.pop();
        for(i=0;i<8;i++)
        {
            nx=x+dir[i][1];
            ny=y+dir[i][0];
            nt=t+(i!=(a[x][y]-48));
            if(a[nx][ny]!='x'&&nt<b[ex][ey]&&nt<b[nx][ny])
            {
                f.x=nx;f.y=ny;f.t=nt;
                if(nx!=ex||ny!=ey) 
                    q.push(f);
                b[nx][ny]=nt;
            }
        }
    }
    return b[ex][ey];
}
int main()
{
    int n,t,m,i,j;
    memset(a,'x',sizeof(a));
    while(scanf("%d%d",&n,&m)==2)
    {
        getchar();
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
                scanf("%c",&a[i][j]);
                getchar();
            }
        scanf("%d",&t);
        while(t--)
            {
                scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
                for(i=1;i<=n;i++)
                    for(j=1;j<=m;j++)
                        b[i][j]=2002;
                printf("%d\n",bfs());
            }
    }
    return 0;
}
