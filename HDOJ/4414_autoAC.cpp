#include<stdio.h>
#include<string.h>
char grid[70][70];
int vis[70][70],midx[70],midy[70],top;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int N,acquire;
typedef struct node
{
    int x,y;
}Node;
Node queue[30000];    
int BFS(int x,int y)
{
    int rear,front;
    int nx,ny,ox,oy;
    int i,j,k,cnt,step=4;
    cnt=rear=front=0;
    queue[rear].x=x;
    queue[rear++].y=y;
    vis[x][y]=1;
    while(front<rear)
    {
        cnt=0;
        ox=queue[front].x;oy=queue[front++].y;
        for(i=0;i<4;i++)
        {
            nx=ox+dx[i];ny=oy+dy[i];
            if(nx>=0&&nx<N&&ny>=0&&ny<N&&grid[nx][ny]=='#'&&!vis[nx][ny])
            {
                cnt++;
                queue[rear].x=nx;queue[rear++].y=ny;
                vis[nx][ny]=1;
            }
        } 
        if(cnt==1)step++;
    }
    step/=4;
    if(rear==step*4+1)acquire++;
    return 0;     
}   
int DFS(int x,int y)
{
    int nx,ny;
    int i,j,k,cnt=0;
    for(i=0;i<4;i++)
    {
        nx=x+dx[i];ny=y+dy[i];
        if(nx>=0&&nx<N&&ny>=0&&ny<N&&!vis[nx][ny]&&grid[nx][ny]=='#')
        {
            cnt++;
            vis[nx][ny]=1;
            DFS(nx,ny);
        }    
    }
    if(cnt==3)
    {
        midx[top]=x;
        midy[top++]=y;
    }
    return 0;      
}     
int main()
{
    int i,j,k;
    while(scanf("%d",&N)!=EOF&&N)
    {
        memset(vis,0,sizeof(vis));
        acquire=top=0;
        for(i=0;i<N;i++)scanf("%s",grid[i]);
        for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++)
            {
                if(!vis[i][j]&&grid[i][j]=='#')
                {
                    vis[i][j]=1;
                    DFS(i,j);
                }    
            }
        }  
        memset(vis,0,sizeof(vis));
        for(i=0;i<top;i++)
        {
            if(!vis[midx[i]][midy[i]])BFS(midx[i],midy[i]);
        }        
        printf("%d\n",acquire);
    }
    return 0;
}
