#include <cstring>
#include <cstdio>
using namespace std;
int map[700][700];
int vis[700][700];
int ansx,ansy;
int ansd,anssum;
int n,m;
int res=0;
int xx[4]={0,-1,1,0};
int yy[4]={1,0,0,-1};
void dfs(int x,int y,int ans,int pre)
{
    if(pre==-1)
    {
        int i;
        for(i=0;i<4;i++)
        {
            int nx=x+xx[i];
            int ny=y+yy[i];
            if(nx<0||nx>=n||ny<0||ny>=m)
                continue;
            if(vis[nx][ny])
                continue;
            vis[nx][ny]=1;
            dfs(nx,ny,ans+1,i);
            vis[nx][ny]=0;
            if(res>anssum)
            {
                ansx=x;
                ansy=y;
                ansd=i;
                anssum=res;
            }
        }
        return ;
    }
    int i;
    int flag=1;
    int nx=x+xx[pre];
    int ny=y+yy[pre];
    if(nx>=0&&nx<n&&ny>=0&&ny<m&&!vis[nx][ny])
    {
        vis[nx][ny]=1;
        dfs(nx,ny,ans+1,pre);
        vis[nx][ny]=0;
        flag=0;
    }
    else
    {
        for(i=0;i<4;i++)
        {
            if(i==pre)
                continue;
            nx=x+xx[i];
            ny=y+yy[i];
            if(nx<0||nx>=n||ny<0||ny>=m)
                continue;
            if(vis[nx][ny])
                continue;
            vis[nx][ny]=1;
            dfs(nx,ny,ans+1,i);
            vis[nx][ny]=0;
            flag=0;
        }
    }
    if(flag)
    {
        if(res<ans)
            res=ans;
    }
}
int main()
{
    int cas=0;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        cas++;
        if(n==0&&m==0)
            break;
        int r;
        scanf("%d",&r);
        int i;
        memset(vis,0,sizeof(vis));
        for(i=0;i<r;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            vis[x][y]=1;
        }
        int j;
        anssum=-1;
        res=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(!vis[i][j])
                {
                    vis[i][j]=1;
                    dfs(i,j,1,-1);
                    vis[i][j]=0;
                }
            }
        }
        printf("Case %d: %d %d %d ",cas,anssum,ansx,ansy);
        if(ansd==0)
            printf("E\n");
        else if(ansd==1)
            printf("N\n");
        else if(ansd==2)
            printf("S\n");
        else if(ansd==3)
            printf("W\n");
    }
}
