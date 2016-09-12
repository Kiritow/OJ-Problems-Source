#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int maxn=1008;
const int INF=0x7f7f7f7f;
char mp[maxn][maxn];
int dir[2][2]={1,0,0,1};
int di[4][2]={1,0,0,1,-1,0,0,-1};
int n,m;
struct poi{
    int x,y,t;
}f[maxn*maxn];
struct fuck{
    int x,y;
};
fuck pa[maxn][maxn],papa[maxn<<4];
bool flag[maxn<<4],done[maxn][maxn];
int idx=0;
int cmp(poi a,poi b)
{
    return a.t>b.t;
}
void rigou()
{
    int i,nx,ny,x,y,t;
    sort(f+1,f+1+idx,cmp);
    queue<poi> q;
    q.push((poi){f[1].x,f[1].y,1});
    done[f[1].x][f[1].y]=true;
    for(i=2;i<=idx;i++)
    {
        if(f[i].t==f[i-1].t)
        {
                q.push((poi){f[i].x,f[i].y,1});
                done[f[i].x][f[i].y]=true;
            }
        else
            break;
        }
    memset(done,false,sizeof(done));
    memset(flag,false,sizeof(flag));
    memset(pa,-1,sizeof(pa));
    poi pp;
    while(!q.empty())
    {
        pp=q.front();q.pop();
        x=pp.x;y=pp.y;t=pp.t;
        if(flag[t]==true&&mp[x][y]=='1')    continue;
        for(i=0;i<2;i++)
        {
            nx=x+dir[i][0];
            ny=y+dir[i][1];
            if(mp[nx][ny]!='\0'&&!done[nx][ny])
            {
                q.push((poi){nx,ny,t+1});
                if(mp[nx][ny]=='0')
                    flag[t+1]=true;
                pa[nx][ny].x=x;pa[nx][ny].y=y;
                done[nx][ny]=true;
            }
        }
    }
}
bool bfs(int x,int y)
{
    int nx,ny,i;
    queue<fuck> q;
    if(mp[x][y]=='0')
    {
        q.push((fuck){x,y});
        fuck pp;
        memset(done,false,sizeof(done));
        while(!q.empty())
        {
            pp=q.front();q.pop();
            x=pp.x;y=pp.y;
            for(i=0;i<4;i++)
            {
                nx=x+di[i][0];
                ny=y+di[i][1];
                if(mp[nx][ny]=='1'){
                    f[++idx].x=nx;
                    f[idx].y=ny;
                    f[idx].t=nx+ny;
                }
                if(mp[nx][ny]=='0'&&!done[nx][ny])
                {
                    done[nx][ny]=true;
                    if(nx==n&&ny==m)
                        return false;
                    q.push((fuck){nx,ny});
                }
            }
        }
    }
    else
    {
        f[++idx].x=1;f[idx].y=1;f[idx].t=2;
    }
    return true;
}
int main()
{
    int i,j,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        idx=0;
        memset(mp,'\0',sizeof(mp));
        for(i=1;i<=n;i++)
            scanf("%s",mp[i]+1);
        if(bfs(1,1))
        {
           rigou();
           int x=n,y=m,id=0,nx,ny;
           papa[id].x=n;papa[id].y=m;
        while(pa[x][y].x!=-1)
        {
            papa[++id].x=pa[x][y].x;
            papa[id].y=pa[x][y].y;
            nx=pa[x][y].x;
            ny=pa[x][y].y;
            x=nx;y=ny;
        }
        for(i=id;i>=0;i--)
        {
            x=papa[i].x;
            y=papa[i].y;
            printf("%c",mp[x][y]);
        }
        }
        else    
          printf("0");
        printf("\n");
    }
    return 0;
}
