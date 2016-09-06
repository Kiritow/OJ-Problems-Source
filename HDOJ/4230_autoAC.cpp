#include"iostream"
#include"cstdio"
#include"queue"
#include"cstring"
using namespace std;
const int N=106;
const int mod=1000000;
const int inf=123456789;
int n,m,s_x,s_y,s_face,e_x,e_y;
int step[N][N][4],cnt[N][N][4],flag[N][N][4];
char map[N][N];
int dir[4][2]={-1,0, 0,-1, 1,0, 0,1};
struct node{
    int x,y,step,face;
};
void bfs()
{
    int i;
    node now,next;
    queue<node>q;
    now.x=s_x;
    now.y=s_y;
    now.step=0;
    now.face=s_face;
    step[now.x][now.y][now.face]=0;
    cnt[now.x][now.y][now.face]=1;
    memset(flag,0,sizeof(flag));
    q.push(now);
    while(!q.empty())
    {
        now=q.front();
        q.pop();
        if(flag[now.x][now.y][now.face])    continue;
        flag[now.x][now.y][now.face]=1;
        for(i=0;i<4;i++)    if(step[now.x][now.y][now.step]<=step[e_x][e_y][i])    break;
        if(i>=4)    return ;
        next.x=now.x+dir[now.face][0];
        next.y=now.y+dir[now.face][1];
        next.step=now.step+1;
        next.face=now.face;
        while(0<=next.x && next.x<n && 0<=next.y && next.y<m && map[next.x][next.y]!='*')
        {
            if(next.step<step[next.x][next.y][next.face])
            {
                step[next.x][next.y][next.face]=next.step;
                cnt[next.x][next.y][next.face]=cnt[now.x][now.y][now.face]%mod;
                q.push(next);
            }
            else if(next.step==step[next.x][next.y][next.face])
            {
                cnt[next.x][next.y][next.face]=(cnt[next.x][next.y][next.face]+cnt[now.x][now.y][now.face])%mod;
                q.push(next);
            }
            next.x+=dir[now.face][0];
            next.y+=dir[now.face][1];
        }
        next.x=now.x;
        next.y=now.y;
        next.step=now.step+1;
        next.face=(now.face+1)%4;
        if(next.step<step[next.x][next.y][next.face])
        {
            step[next.x][next.y][next.face]=next.step;
            cnt[next.x][next.y][next.face]=cnt[now.x][now.y][now.face];
            q.push(next);
        }
        else if(next.step==step[next.x][next.y][next.face])
        {
            cnt[next.x][next.y][next.face]=(cnt[next.x][next.y][next.face]+cnt[now.x][now.y][now.face])%mod;
            q.push(next);
        }
        next.step=now.step+1;
        next.face=(now.face+3)%4;
        if(next.step<step[next.x][next.y][next.face])
        {
            step[next.x][next.y][next.face]=next.step;
            cnt[next.x][next.y][next.face]=cnt[now.x][now.y][now.face];
            q.push(next);
        }
        else if(next.step==step[next.x][next.y][next.face])
        {
            cnt[next.x][next.y][next.face]=(cnt[next.x][next.y][next.face]+cnt[now.x][now.y][now.face])%mod;
            q.push(next);
        }
    }
}
int main()
{
    int i,l,j;
    while(scanf("%d%d",&n,&m),n||m)
    {
        for(i=0;i<n;i++)
        {
            scanf("%s",map[i]);
            for(l=0;l<m;l++)
            {
                if(map[i][l]=='X')    {e_x=i;e_y=l;}
                if(map[i][l]=='N')    {s_x=i;s_y=l;s_face=0;}
                else if(map[i][l]=='W')    {s_x=i;s_y=l;s_face=1;}
                else if(map[i][l]=='S')    {s_x=i;s_y=l;s_face=2;}
                else if(map[i][l]=='E')    {s_x=i;s_y=l;s_face=3;}
                for(j=0;j<4;j++)    step[i][l][j]=inf;
            }
        }
        map[s_x][s_y]='.';
        memset(cnt,0,sizeof(cnt));
        bfs();
        int ans=0,minstep=inf;
        for(i=0;i<4;i++)    if(step[e_x][e_y][i]<minstep)    minstep=step[e_x][e_y][i];
        for(i=0;i<4;i++)    if(step[e_x][e_y][i]==minstep)    ans=(ans+cnt[e_x][e_y][i])%mod;
        if(minstep==inf)    printf("0 0\n");
        else    printf("%d %d\n",minstep,ans);
    }
    return 0;
}
