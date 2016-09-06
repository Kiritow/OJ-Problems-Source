#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
#define MAXN 222
#define inf 1<<30
struct Point{
    int x,y;
}point[MAXN];
int value[MAXN][MAXN];
int map[MAXN][MAXN];
int dist[MAXN][MAXN];
int dd[MAXN];
bool mark[MAXN][MAXN];
int dp[1<<14][14];
int n,m,k;
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
void spfa(int num)
{
    memset(mark,false,sizeof(mark));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)dist[i][j]=inf;
    queue<pair<int,int> >que;
    que.push(make_pair(point[num].x,point[num].y));
    if(dist[point[num].x][point[num].y]==-1)return;
    dist[point[num].x][point[num].y]=0;
    while(!que.empty()){
        int x=que.front().first,y=que.front().second;
        que.pop();
        mark[x][y]=false;
        if(x==0||x==(n-1)||y==0||y==(m-1)){
            dd[num]=min(dd[num],dist[x][y]);
        }
        for(int i=0;i<4;i++){
            int xx=x+dir[i][0],yy=y+dir[i][1];
            if(xx>=0&&xx<n&&yy>=0&&yy<m&&value[xx][yy]!=-1){
                if(dist[x][y]+value[xx][yy]<dist[xx][yy]){
                    dist[xx][yy]=dist[x][y]+value[xx][yy];
                    if(!mark[xx][yy]){
                        mark[xx][yy]=true;
                        que.push(make_pair(xx,yy));
                    }
                }
            }
        }
    }
}
int main()
{
    int _case;
    scanf("%d",&_case);
    while(_case--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                scanf("%d",&value[i][j]);
        scanf("%d",&k);
        for(int i=0;i<k;i++)scanf("%d%d",&point[i].x,&point[i].y);
        for(int i=0;i<k;i++)
            for(int j=0;j<k;j++)
                map[i][j]=(i==j)?0:inf;
        for(int i=0;i<(1<<k);i++)
            for(int j=0;j<k;j++)dp[i][j]=inf;
        fill(dd,dd+MAXN,inf);
        for(int i=0;i<k;i++){
            spfa(i);
            for(int j=0;j<k;j++){
                if(i==j)continue;
                map[i][j]=min(map[i][j],dist[point[j].x][point[j].y]);
            }
            dp[1<<i][i]=dd[i]+value[point[i].x][point[i].y];
        }
        for(int s=0;s<(1<<k);s++){
            for(int i=0;i<k;i++){
                if(s&(1<<i)==0)continue;
                if(dp[s][i]==inf)continue;
                for(int j=0;j<k;j++){
                    if(s&(1<<j)==1)continue;
                    dp[s|(1<<j)][j]=min(dp[s|(1<<j)][j],dp[s][i]+map[i][j]);
                }
            }
        }
        int ans=inf;
        for(int i=0;i<k;i++){
            ans=min(ans,dp[(1<<k)-1][i]+dd[i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
