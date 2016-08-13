#include<stdio.h>
#include<queue>
using namespace std;
char map[10][10][10];
int startx,starty,startz,endx,endy,endz;
int n;
struct node
{
    int x,y,z,step;
    friend bool operator <(node a,node b)
    {
        return a.step>b.step;
    }
};
void bfs(int x1,int y1,int z1,int x2,int y2,int z2)
{
    int k;
    int move[6][3]={0,0,1,0,0,-1,0,1,0,0,-1,0,1,0,0,-1,0,0};
    node now,next;
    priority_queue<node>q;
    now.x=x1;
    now.y=y1;
    now.z=z1;
    now.step=0;
    map[now.x][now.y][now.z]='X';
    q.push(now);
    while(!q.empty())
    {
        next=q.top();
        q.pop();
        if(next.x==x2&&next.y==y2&&next.z==z2)
        {
            printf("%d %d\n",n,next.step);
            return ;
        }
        for(k=0;k<6;k++)
        {
            now.x=next.x+move[k][0];
            now.y=next.y+move[k][1];
            now.z=next.z+move[k][2];
            if(now.x>=0&&now.x<n&&now.y>=0&&now.y<n&&now.z>=0&&now.z<n&&map[now.x][now.y][now.z]=='O')
            {
                now.step=next.step+1;
                map[now.x][now.y][now.z]='X';
                q.push(now);
            }
        }
    }
    printf("NO ROUTE\n");
}
int main()
{
    int i,j,k;
    char s[10];
    char c;
    while(scanf("%s %d",s,&n)!=EOF)
    {
        c=getchar();
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                for(k=0;k<n;k++)
                {
                    scanf("%c",&map[i][j][k]);
                }
                c=getchar();
            }
            c=getchar();
        }
        scanf("%d%d%d%d%d%d",&startx,&starty,&startz,&endx,&endy,&endz);
        scanf("%s",s);
        bfs(startx,starty,startz,endx,endy,endz);
    }
    return 0;
}
