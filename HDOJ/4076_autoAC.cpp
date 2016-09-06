# include<stdio.h>
# include<string.h>
# include<queue>
using namespace std;
# define N 35
# define INF 0xfffffff
int dir[4][2]={0,1,0,-1,1,0,-1,0};
struct node{
    int x,y;
};
int map[N][N],visit[N][N];
int count1[N][N],mark[N][N];
int xx[N][N],yy[N][N],tt[N][N];
int n,m,flag;
void bfs()
{
    int i,ans;
    queue<node>q;
    node cur,next;
    cur.x=0;
    cur.y=0;
    q.push(cur);
    visit[0][0]=0;
    mark[0][0]=1;
    count1[0][0]++;
    while(!q.empty())
    {
        cur=q.front();
        mark[cur.x][cur.y]=0;
        q.pop();
        if(count1[cur.x][cur.y]>n*m) {flag=1;return;}
        if(cur.x==n-1 && cur.y==m-1) continue;
        if(xx[cur.x][cur.y]!=-1)
        {
            next.x=xx[cur.x][cur.y];
            next.y=yy[cur.x][cur.y];
            ans=visit[cur.x][cur.y]+tt[cur.x][cur.y];
            if(visit[next.x][next.y]>ans)
            {
                visit[next.x][next.y]=ans;
                if(mark[next.x][next.y]==0)
                {
                    mark[next.x][next.y]=1;
                    count1[next.x][next.y]++;
                    q.push(next);
                }
            }
            continue;
        }
        for(i=0;i<4;i++)
        {
            next.x=cur.x+dir[i][0];
            next.y=cur.y+dir[i][1];
            ans=visit[cur.x][cur.y]+1;
            if(next.x<0 || next.y<0 || next.x>=n || next.y>=m || map[next.x][next.y]==1) continue;
            if(visit[next.x][next.y]>ans)
            {
                visit[next.x][next.y]=ans;
                if(mark[next.x][next.y]==0)
                {
                    mark[next.x][next.y]=1;
                    count1[next.x][next.y]++;
                    q.push(next);
                }
            }
        }
    }
}
int main()
{
    int i,j,num,a,b;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0 && m==0) break;
        scanf("%d",&num);
        memset(map,0,sizeof(map));
        while(num--)
        {
            scanf("%d%d",&a,&b);
            map[a][b]=1;
        }
        scanf("%d",&num);
        memset(xx,-1,sizeof(xx));
        while(num--)
        {
            scanf("%d%d",&a,&b);
            scanf("%d%d%d",&xx[a][b],&yy[a][b],&tt[a][b]);
        }
        memset(mark,0,sizeof(mark));
        memset(count1,0,sizeof(count1));
        for(i=0;i<=n;i++)
            for(j=0;j<=m;j++)
                visit[i][j]=INF;
        flag=0;
        bfs();
        if(flag==1) {printf("Never\n");continue;}
        if(visit[n-1][m-1]==INF) printf("Impossible\n");
        else printf("%d\n",visit[n-1][m-1]);
    }
    return 0;
}
