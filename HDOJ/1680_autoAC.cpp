#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define N 100
char map[10][10];
int wx,wy,hx,hy;
int visit[10][10][100];
int dir[8][2]= {0,1,1,1,1,0,1,-1,0,-1,-1,-1,-1,0,-1,1};
struct node
{
    int x;
    int y;
    int step;
} a[N];
bool judge(node a)
{
    if(a.x==hx+a.step&&(a.y==hy+1||a.y==hy-1))return false;
    if(map[a.x][a.y]=='F'||map[a.x][a.y]=='D')return false;
    return a.x>=1&&a.y>=1&&a.x<=8&&a.y<=8&&!visit[a.x][a.y][a.step];
}
int bfs()
{
    memset(visit,0,sizeof(visit));
    int front=0;
    int rear=1;
    node cur;
    a[0].x=wx;
    a[0].y=wy;
    a[0].step=0;
    visit[wx][wy][0]=1;
    int flag=1;
    int mm=0;
    while(front<rear)
    {
        node cur;
        cur.x=a[front].x;
        cur.y=a[front].y;
        cur.step=a[front].step;
        if(map[hx+cur.step][hy]=='F')
        {
            return 1;
        }
        if(hx+cur.step>8)
        {
            return 0;
        }
        for(int i=0; i<8; i++)
        {
            int tx=cur.x+dir[i][0];
            int ty=cur.y+dir[i][1];
            int tstep=cur.step+1;
            node b;
            b.step=tstep;
            b.x=tx;
            b.y=ty;
            if((tx>=1 && tx<=8) && (ty>=1 && ty<=8)  && map[tx][ty]!='F' && map[tx][ty]!='D'  && visit[tx][ty][tstep]==0)
            {
                if(!((tx==hx+tstep && ty==hy-1) || (tx==hx+tstep && ty==hy+1)))
                {
                visit[tx][ty][tstep]=1;
                if(tx==hx+cur.step&&ty==hy||tx==hx+tstep&&ty==hy)
                {
                    return 1;
                }
                node tmp;
                tmp.x=tx;
                tmp.y=ty;
                tmp.step=tstep;
                a[rear++]=tmp;
            }
            }
        }
        front++;
    }
    return 0;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        for(int i=1; i<=8; i++)
        {
            scanf("%s",map[i]+1);
        }
        scanf("%d%d",&wx,&wy);
        int xx=wx;
        wx=9-wy;
        wy=xx;
        scanf("%d%d",&hx,&hy);
        xx=hx;
        hx=9-hy;
        hy=xx;
        int ans=bfs();
        if(ans==1)
        {
            printf("White\n");
        }
        else
            printf("Black\n");
    }
    return 0;
}
