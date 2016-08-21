#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
const int N = 109;
const int INF =0x3f3f3f3f;
int n,m;
int dp[N][N][30];
bool visit[N][N][30];
char map[N][N];
bool init()
{
    n=0;
    while(1)
    {
        gets(map[n]);
        if(map[n][0]=='-') return false;
        if(strlen(map[n])==0) break;
        n++;
    }
    m = strlen(map[0]);
    return true;
}
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
struct nod{
    int dis;
    int x,y,dep;
    bool operator <(const nod t) const
    {
        return dis>t.dis;
    }
};
priority_queue<nod> que;
bool oor(int x,int y)
{
    if(x<0||x>=n) return false;
    if(y<0||y>=m) return false;
    return true;
}
void deal()
{
    memset(dp,INF,sizeof(dp));
    memset(visit,false,sizeof(visit));
    int enx,eny;
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    if(map[i][j]=='$')
    {
        enx=i,eny=j;
    }
    while(!que.empty()) que.pop();
    nod e,t;
    e.dep=0;e.dis=0;e.x=enx,e.y=eny;
    que.push(e);
    while(!que.empty())
    {
        e = que.top(); que.pop();
        if(visit[e.x][e.y][e.dep]) continue;
        visit[e.x][e.y][e.dep] = true;
        dp[e.x][e.y][e.dep] = e.dis;
        if(e.x==0||e.y==0||e.x==n-1||e.y==m-1) continue;
        for(int i=0;i<4;i++)
        {
            int tx=e.x+dx[i],ty=e.y+dy[i];
            if(!oor(tx,ty)||map[tx][ty]=='*') continue;
            if(map[tx][ty]>='0'&&map[tx][ty]<='9')
            {
                t.dis = e.dis+map[tx][ty]-'0';
                t.dep = e.dep;
                t.x = tx,t.y = ty;
                if(!visit[tx][ty][t.dep]&&dp[tx][ty][t.dep]>t.dis)
                que.push(t);
                t.dis = e.dis;
                t.dep = e.dep+1;
                t.x = tx,t.y = ty;
                if(!visit[tx][ty][t.dep]&&dp[tx][ty][t.dep]>t.dis&&t.dep<=26)
                que.push(t);
            }
            else
            {
                t.dis = e.dis;
                t.dep = e.dep;
                t.x = tx,t.y = ty;
                if(dp[tx][ty][t.dep]>t.dis)
                que.push(t);
            }
        }
    }
}
int fin(int x,int y)
{
    int ans = INF;
    int d = map[x][y]=='#'?0:map[x][y]-'A'+1;
    for(int i=0;i<=d;i++)
    ans=min(dp[x][y][d],ans);
    return ans;
}
void solve()
{
    deal();
    int ans=INF;
    for(int i=1;i<n;i++)
    {
        if(map[i][0]!='*')
        ans=min(fin(i,0),ans);
        if(map[i][m-1]!='*')
        ans=min(fin(i,m-1),ans);
    }
    for(int i=1;i<m;i++)
    {
        if(map[0][i]!='*')
        ans=min(fin(0,i),ans);
        if(map[n-1][i]!='*')
        ans=min(fin(n-1,i),ans);
    }
    if(ans==INF) printf("IMPOSSIBLE\n");
    else printf("%d\n",ans);
}
int main()
{
    while(1)
    {
        if(!init()) break;
        solve();
    }
    return 0;
}
