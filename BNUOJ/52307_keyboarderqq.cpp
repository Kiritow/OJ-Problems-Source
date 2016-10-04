#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=2e2+10;

struct asd{
    int x,y;
};
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
char s[N][N];
int step[N][N];
int n,m;
int sx,sy;
queue<asd>q;

void init()
{
    while(!q.empty())
        q.pop();
    memset(step,-1,sizeof(step));
}

bool Judge(int x,int y)
{
    if(x<0||y<0||x>=n||y>=m)
        return 0;
    if(s[x][y]=='#')
        return 0;
    return 1;
}

void bfs()
{
    init();
    asd now,next;
    now.x=sx;
    now.y=sy;
    step[now.x][now.y]=0;
    q.push(now);
    while(!q.empty())
    {
        now=q.front();
        q.pop();
//        printf("%d %d\n",now.x,now.y);
        for(int i=0;i<4;i++)
        {
            int x=now.x+dx[i];
            int y=now.y+dy[i];
            if(Judge(x,y))
            {
                if(step[x][y]==-1)
                {
                    step[x][y]=step[now.x][now.y]+1;
                    next.x=x;
                    next.y=y;
                    q.push(next);
                }
            }
        }
    }
    int temp1;
    int temp2=0x3f3f3f3f;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(s[i][j]=='@')
            {
                temp1=step[i][j];
            }
            if(s[i][j]=='$'&&step[i][j]!=-1)
            {
                temp2=min(temp2,step[i][j]);
            }
        }
    }
    if(temp1<temp2)
        puts("Yes");
    else
        puts("No");
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%s",s[i]);
    int f=0;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(s[i][j]=='%')
            {
                sx=i;
                sy=j;
                f=1;
                break;
            }
        }
        if(f)
            break;
    }
    bfs();
    return 0;
}
