#include <cstdio>
#include <queue>
#define INF 999999999
#define max(A,B)(A>B?A:B)
using namespace std;
struct S{
int x,y;
}fruit[20],t;
int n,m,cnt,ans,mp[256][256],dis[20][20],cost[256][256],nxt[4][2]={{1,0},{0,1},{-1,0},{0,-1}},mx[1<<18][20],val[20];
void bfs(S t)
{
    int i,j,nx,ny;
    for(i=0;i<n;i++) for(j=0;j<m;j++) cost[i][j]=INF;
    queue<S>que;
    cost[t.x][t.y]=0;
    que.push(t);
    while(!que.empty())
    {
        t=que.front();
        for(i=0;i<4;i++)
        {
            nx=t.x+nxt[i][0];
            ny=t.y+nxt[i][1];
            if(nx>=0 && nx<n && ny>=0 && ny<m && mp[nx][ny]!=-1 && cost[nx][ny]==INF)
            {
                cost[nx][ny]=cost[t.x][t.y]+1;
                t.x=nx;
                t.y=ny;
                que.push(t);
            }
            t=que.front();
        }
        que.pop();
    }
}
int main()
{
    int i,j;
    while(~scanf("%d%d",&n,&m))
    {
        cnt=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                scanf("%d",&mp[i][j]);
                if(mp[i][j]>0)
                {
                    fruit[cnt].x=i;
                    fruit[cnt].y=j;
                    val[cnt++]=mp[i][j];
                }
            }
        }
        if(n==1 && m==1)
        {
            if(mp[0][0]>=0) printf("%d\n",mp[0][0]);
            else printf("you loss!\n");
            continue;
        }
        if(mp[0][0]<=0)
        {
            printf("you loss!\n");
            continue;
        }
        if(mp[n-1][m-1]==-1)
        {
            printf("you loss!\n");
            continue;
        }
        fruit[cnt].x=n-1;
        fruit[cnt].y=m-1;
        for(i=0;i<=cnt;i++)
        {
            bfs(fruit[i]);
            for(j=0;j<=cnt;j++) dis[i][j]=cost[fruit[j].x][fruit[j].y];
        }
        queue<S>que;
        for(i=1;i<(1<<cnt);i++) for(j=0;j<cnt;j++) mx[i][j]=-1;
        int v;
        t.x=1;
        t.y=0;
        mx[t.x][t.y]=val[0];
        que.push(t);
        while(!que.empty())
        {
            t=que.front();
            for(i=1;i<cnt;i++)
            {
                if(!(t.x & (1<<i)))
                {
                    v=mx[t.x][t.y]-dis[t.y][i];
                    if(v>=0)
                    {
                        t.x=(t.x | (1<<i));
                        t.y=i;
                        if(v+val[i]>mx[t.x][i])
                        {
                            mx[t.x][i]=v+val[i];
                            que.push(t);
                        }
                        t=que.front();
                    }
                }
            }
            que.pop();
        }
        ans=-1;
        for(i=1;i<(1<<cnt);i++) for(j=0;j<cnt;j++) ans=max(ans,mx[i][j]-dis[j][cnt]);
        if(ans>=0) printf("%d\n",ans);
        else puts("you loss!");
    }
}
