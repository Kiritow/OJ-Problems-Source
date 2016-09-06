#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <map>
#include <iostream>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N=109;
bool visit[N<<1][N<<1];
map<int,int> mpx;
map<int,int> mpy;
int n;
struct cpoint{
    int x,y;
    void get()
    {
         scanf("%d%d",&x,&y);x<<=1;y<<=1;
    }
} st,en,re[59][2];
int hashx[N<<1],hashy[N<<1],cnx,cny;
bool  can[N][N][4][4];
void init()
{
    mpx.clear();mpy.clear();
    memset(can,false,sizeof(can));
    cnx=0;cny=0;
    for(int i=0;i<n;i++)
    {
        hashx[cnx++] = re[i][0].x;
        hashx[cnx++] = re[i][0].x+1;
        hashx[cnx++] = re[i][1].x;
        hashx[cnx++] = re[i][1].x+1;
        hashy[cny++] = re[i][0].y;
        hashy[cny++] = re[i][0].y+1;
        hashy[cny++] = re[i][1].y;
        hashy[cny++] = re[i][1].y+1;
    }
    sort(hashx,hashx+cnx);sort(hashy,hashy+cny);
    int tx=0,ty=0;
    mpx[hashx[0]] = 0;
    mpy[hashy[0]] = 0;
    for(int i=1;i<cnx;i++)
    if(hashx[tx]!=hashx[i])
    {
        hashx[++tx] = hashx[i];
        mpx[hashx[i]] = tx;
    }
    for(int i=1;i<cny;i++)
    if(hashy[ty]!=hashy[i])
    {
        hashy[++ty] = hashy[i];
        mpy[hashy[i]] = ty;
    }
    cnx = tx+1,cny = ty+1;
    memset(visit,true,sizeof(visit));
    for(int i=1;i<n;i++)
    {
        int X = mpx[re[i][1].x],Y = mpy[re[i][1].y];
        for(int j=mpx[re[i][0].x]+1;j<=X;j++)
        for(int k=mpy[re[i][0].y]+1;k<=Y;k++)
        visit[j][k] = 0;
    }
    cnx>>=1;cny>>=1;
    for(int i=0;i<cnx;i++)
    for(int j=0;j<cny;j++)
    {
        if((visit[i<<1][j<<1]&&visit[i<<1][j<<1|1])||(visit[i<<1|1][j<<1]&&visit[i<<1|1][j<<1|1]))
            can[i][j][3][3] = can[i][j][1][1] = 1;
        if((visit[i<<1][j<<1]&&visit[i<<1|1][j<<1])||(visit[i<<1][j<<1|1]&&visit[i<<1|1][j<<1|1]))
            can[i][j][2][2] = can[i][j][0][0] = 1;
        if(visit[i<<1][j<<1])
            can[i][j][2][3] = can[i][j][1][0] = 1;
        if(visit[i<<1][j<<1|1])
            can[i][j][2][1] = can[i][j][3][0] = 1;
        if(visit[i<<1|1][j<<1])
            can[i][j][0][3] = can[i][j][1][2] = 1;
        if(visit[i<<1|1][j<<1|1])
            can[i][j][0][1] = can[i][j][3][2] = 1;
        if(visit[i<<1][j<<1]&&visit[i<<1][j<<1|1]&&visit[i<<1|1][j<<1])
            can[i][j][0][1] = can[i][j][3][2] = 1;
        if(visit[i<<1][j<<1]&&visit[i<<1][j<<1|1]&&visit[i<<1|1][j<<1|1])
            can[i][j][1][2] = can[i][j][0][3] = 1;
        if(visit[i<<1][j<<1]&&visit[i<<1|1][j<<1]&&visit[i<<1|1][j<<1|1])
            can[i][j][2][1] = can[i][j][3][0] = 1;
        if(visit[i<<1][j<<1|1]&&visit[i<<1|1][j<<1]&&visit[i<<1|1][j<<1|1])
            can[i][j][1][0] = can[i][j][2][3] = 1;
    }
}
queue<int> que;
bool oor(int x,int y)
{
    if(x<0||x>=cnx) return false;
    if(y<0||y>=cny) return false;
    return true;
}
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int dis[N][N][4];
bool in[N][N][4];
void solve()
{
    memset(in,0,sizeof(in));
    memset(dis,INF,sizeof(dis));
    while(!que.empty()) que.pop();
    int stx=mpx[st.x]/2,sty=mpy[st.y]/2,enx=mpx[en.x]/2,eny=mpy[en.y]/2;
    for(int i=0;i<4;i++)
    {
        que.push((stx<<12)|(sty<<2)|i);
        dis[stx][sty][i]= 0;
    }
    while(!que.empty())
    {
        int e = que.front(); que.pop();
        int ed,ex,ey;
        ed = e&3;e>>=2;
        ey = e&1023;e>>=10;
        ex = e;
        in[ex][ey][ed] = false;
        for(int i=0;i<4;i++)
        {
            int tx=ex+dx[i],ty=ey+dy[i];
            if(i==ed&&oor(tx,ty)&&can[ex][ey][ed][i]&&dis[tx][ty][i]>dis[ex][ey][ed])
            {
                dis[tx][ty][i]=dis[ex][ey][ed];
                if(!in[tx][ty][i]) que.push((tx<<12)|(ty<<2)|i);
            }
            else if(i!=ed&&oor(tx,ty)&&can[ex][ey][ed][i]&&dis[tx][ty][i]>dis[ex][ey][ed]+1)
            {
                dis[tx][ty][i]=dis[ex][ey][ed]+1;
                if(!in[tx][ty][i]) que.push((tx<<12)|(ty<<2)|i);
            }
        }
    }
    int ans=INF;
    for(int i=0;i<4;i++)
    ans = min(dis[enx][eny][i],ans);
    printf("%d\n",ans==INF?-1:ans);
}
int main()
{
    while(~scanf("%d%d%d%d",&st.x,&st.y,&en.x,&en.y))
    {
        if(st.x==0&&st.y==0&&en.x==0&&en.y==0) break;
        st.x<<=1;st.y<<=1;en.x<<=1;en.y<<=1;
        re[0][0] = st;
        re[0][1] = en;
        scanf("%d",&n);n+=1;
        for(int i=1;i<n;i++)
        {
            re[i][0].get(),re[i][1].get();
            if(re[i][0].x>re[i][1].x) swap(re[i][0].x,re[i][1].x);
            if(re[i][0].y>re[i][1].y) swap(re[i][0].y,re[i][1].y);
        }
        init();
        solve();
    }
    return 0;
}
