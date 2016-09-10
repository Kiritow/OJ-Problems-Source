#include "cstdio"
#include "iostream"
#include "cstring"
#include "vector"
#include "queue"
using namespace std;
#define inf 0x3f3f3f3f
int area[55][55],dp[1<<15][15],vis[55][55],dis[55][55],dir[4][2]={-1,0,1,0,0,-1,0,1},n,m,g;
struct status
{
    int x,y,dep;
    status(int x,int y,int dep):x(x),y(y),dep(dep) {}
};
int bfs(status s,status e)
{
    memset(vis,0,sizeof(vis));
    vis[s.x][s.y]=true;
    queue<status> Q;
    Q.push(status(s.x,s.y,0));
    while(!Q.empty())
    {
        status t=Q.front();Q.pop();
        for(int s=0;s<4;s++)
        {
            int X=t.x+dir[s][0],Y=t.y+dir[s][1];
            if(X<1||X>n||Y<1||Y>m||vis[X][Y]) continue;
            vis[X][Y]=true;
            if(X==e.x&&Y==e.y) return t.dep+1;
            Q.push(status(X,Y,t.dep+1));
        }
    }
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        vector<status> stone;
        stone.push_back(status(1,1,0));
        for(int i=1;i<=n;i++)
          for(int j=1;j<=m;j++)
            {
               scanf("%d",&g);
               if(i==1&&j==1) continue;
               if(g) stone.push_back(status(i,j,0));
            }
        for(int i=0;i<stone.size();i++)
        {
            for(int j=0;j<stone.size();j++)
            {
                if(i==j) dis[i][j]=0;
                else {if(!dis[i][j]) dis[i][j]=dis[j][i]=bfs(stone[i],stone[j]);}
            }
        }
        int s=stone.size();
        int cnt=1<<s;
        for(int i=0;i<cnt;i++)
        {
            for(int j=0;j<s;j++)
            {
                if(!i&(1<<j)) continue;
                if(i==(1<<j)) dp[i][j]=dis[0][j];
                else
                {
                    dp[i][j]=inf;
                    for(int k=0;k<s;k++) if(i&(1<<k)&&k!=j) dp[i][j]=min(dp[i][j],dp[i^(1<<j)][k]+dis[k][j]);
                }
            }
        }
        int ans=inf;
        for(int i=0;i<s;i++)
            ans=min(ans,dp[cnt-1][i]+dis[i][0]);
        printf("%d\n",ans);
        memset(dp,0,sizeof(dp));
        memset(dis,0,sizeof(dis));
    }
}
