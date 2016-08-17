#include<iostream>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;
struct node
{
    int x,y,x1,y1,x2,y2,x3,y3;
    int step;
};
bool vist[8][8][8][8][8][8][8][8];
int n,m,t[4][2]= {1,0,-1,0,0,1,0,-1};
int f[10][10],cnt;
char s[10][10];
queue<node>q;
void bfs()
{
    while(!q.empty())
    {
        node p=q.front();
        q.pop();
        if(f[p.x1][p.y1]&&f[p.x2][p.y2]&&f[p.x3][p.y3])
        {
            printf("%d\n",p.step);
            return;
        }
        for(int i=0; i<4; i++)
        {
            int mx=p.x+t[i][0];
            int my=p.y+t[i][1];
            int xx=p.x+2*t[i][0];
            int yy=p.y+2*t[i][1];
            if(mx>=0&&mx<n&&my>=0&&my<m&&s[mx][my]!='#')
            {
                if(!((mx==p.x1&&my==p.y1)||(mx==p.x2&&my==p.y2)||(mx==p.x3&&my==p.y3)))
                {
                    node p1=p;
                    p1.x=mx;
                    p1.y=my;
                    p1.step=p.step+1;
                    if(!vist[p1.x][p1.y][p1.x1][p1.y1][p1.x2][p1.y2][p1.x3][p1.y3])
                    {
                        vist[p1.x][p1.y][p1.x1][p1.y1][p1.x2][p1.y2][p1.x3][p1.y3]=true;
                        q.push(p1);
                    }
                }
                else
                {
                    if(xx>=0&&xx<n&&yy>=0&&yy<m&&s[xx][yy]!='#')
                    {
                        if(!((xx==p.x1&&yy==p.y1)||(xx==p.x2&&yy==p.y2)||(xx==p.x3&&yy==p.y3)))
                        {
                            node p1=p;
                            p1.x=mx;
                            p1.y=my;
                            if(p1.x1==mx&&p1.y1==my)
                            {
                                p1.x1=xx;
                                p1.y1=yy;
                            }
                            if(p1.x2==mx&&p1.y2==my)
                            {
                                p1.x2=xx;
                                p1.y2=yy;
                            }
                            if(p1.x3==mx&&p1.y3==my)
                            {
                                p1.x3=xx;
                                p1.y3=yy;
                            }
                            p1.step=p.step+1;
                            if(!vist[p1.x][p1.y][p1.x1][p1.y1][p1.x2][p1.y2][p1.x3][p1.y3])
                            {
                                vist[p1.x][p1.y][p1.x1][p1.y1][p1.x2][p1.y2][p1.x3][p1.y3]=true;
                                q.push(p1);
                            }
                        }
                    }
                }
            }
        }
    }
    printf("-1\n");
}
int main()
{
    while(scanf("%d%d",&n,&m)>0)
    {
        memset(vist,false,sizeof(vist));
        memset(f,0,sizeof(f));
        while(!q.empty())
            q.pop();
        cnt=0;
        int w=0;
        node p;
        for(int i=0; i<n; i++)
        {
            scanf("%s",s[i]);
            for(int j=0; j<m; j++)
            {
                if(s[i][j]=='*'&&w==0)
                {
                    w++;
                    p.x1=i;
                    p.y1=j;
                    s[i][j]='.';
                }
                else  if(s[i][j]=='*'&&w==1)
                {
                    w++;
                    p.x2=i;
                    p.y2=j;
                    s[i][j]='.';
                }
                else if(s[i][j]=='*'&&w==2)
                {
                    w++;
                    p.x3=i;
                    p.y3=j;
                    s[i][j]='.';
                }
                if(s[i][j]=='X')
                {
                    p.x=i;
                    p.y=j;
                    s[i][j]='.';
                }
                if(s[i][j]=='@')
                {
                    f[i][j]=1;
                    s[i][j]='.';
                }
            }
        }
        p.step=0;
        vist[p.x][p.y][p.x1][p.y1][p.x2][p.y2][p.x3][p.y3]=true;
        q.push(p);
        bfs();
    }
    return 0;
}
