#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
const int N(103),MAXN(0x6ffffff);
struct point
{
    int x,y;
    point *next;
};
struct path_node
{
    int pre_x,pre_y,time;
};
int maze[N][N];
path_node path[N][N];
point *ans;
bool inq[N][N];
queue<point> q;
int dx[4]={0,0,-1,1},dy[4]={-1,1,0,0};
int n,m;
void init()
{
    char x;
    getchar();
    memset(maze,0,sizeof(maze));
    memset(path,0,sizeof(path));
    memset(inq,0,sizeof(inq));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%c",&x);
            if(x=='X') maze[i][j]=-1;
            else if(x!='.') maze[i][j]=x-'0';
            else maze[i][j]=0;
            path[i][j].time=MAXN;
        }
        getchar();
    }
    path[0][0].time=0;
    path[0][0].pre_x=-1;
}
inline bool passable(int x,int y)
{
    if(x<0||x>n-1||y<0||y>m-1||maze[x][y]==-1)
        return false;
    return true;
}
void search()
{
    point s;
    s.x=s.y=0;
    q.push(s);
    inq[s.x][s.y]=true;
    while(!q.empty())
    {
        point u=q.front();
        q.pop();
        inq[u.x][u.y]=false;
        int nx,ny;
        for(int i=0;i<4;i++)
        {
            nx=u.x+dx[i];
            ny=u.y+dy[i];
            if(path[nx][ny].time>path[u.x][u.y].time+maze[nx][ny]+1&&passable(nx,ny))
            {
                path[nx][ny].time=path[u.x][u.y].time+maze[nx][ny]+1;
                path[nx][ny].pre_x=u.x;
                path[nx][ny].pre_y=u.y;
                if(!inq[nx][ny])
                {
                    point np;
                    np.x=nx,np.y=ny;
                    q.push(np);
                    inq[nx][ny]=true;
                }
            }
        }
    }
}
void print()
{
    if(path[n-1][m-1].time!=MAXN)
    {
        point *node;
        int x=n,y=m,t=0;
        while(x!=-1)
        {
            node=new(point);
            if(ans)
                node->x=x,node->y=y;
            else node->x=n-1,node->y=m-1;
            node->next=ans;
            ans=node;
            x=path[node->x][node->y].pre_x;
            y=path[node->x][node->y].pre_y;
        }
        printf("It takes %d seconds to reach the target position, let me show you the way.\n",
               path[n-1][m-1].time);
        point *p,*next;
        for(p=ans;p;p=next)
        {
            while(maze[p->x][p->y])
            {
                printf("%ds:FIGHT AT (%d,%d)\n",++t,p->x,p->y);
                maze[p->x][p->y]--;
            }
            if(p->next)
                printf("%ds:(%d,%d)->(%d,%d)\n",++t,p->x,p->y,p->next->x,p->next->y);
            next=p->next;
            delete p;
        }
        ans=NULL;
    }
    else
        printf("God please help our poor hero.\n");
    printf("FINISH\n");
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        init();
        search();
        print();
    }
}
