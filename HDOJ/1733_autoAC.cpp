#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#define MAXN 20005
#define Lim 75
#define INF (1<<30)
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;
struct Node
{
    int x,y;
    Node(int x1,int y1)
    {x=x1;y=y1;}
    Node(){}
};
struct edge
{
    int u,v,w,next;
}E[2000000];
int head[MAXN],ecnt;
int gap[MAXN],cur[MAXN],dis[MAXN],pre[MAXN];
int N,M,scr,sink,vn,Ti,Sum,now;
int ans;
int dir[5][2]={0,1,0,-1,1,0,-1,0,0,0};
char map[20][20];
Node Q[200000];
int Head,Tail;
bool vis[20][20];
void Insert(int u,int v,int w)
{
    E[ecnt].u=u;
    E[ecnt].v=v;
    E[ecnt].w=w;
    E[ecnt].next=head[u];
    head[u]=ecnt++;
    E[ecnt].u=v;
    E[ecnt].v=u;
    E[ecnt].w=0;
    E[ecnt].next=head[v];
    head[v]=ecnt++;
}
bool BFS(Node s)
{
    int i,j;
    Node u,v;
    memset(vis,false,sizeof(vis));
    Head=Tail=0;
    vis[s.x][s.y]=true;
    Q[Head++]=s;
    while(Head!=Tail)
    {
        u=Q[Tail++];
        if(map[u.x][u.y]=='@') return true;
        for(i=0;i<4;i++)
        {
            int dx=u.x+dir[i][0];
            int dy=u.y+dir[i][1];
            if(dx>=0&&dx<N&&dy>=0&&dy<M&&map[dx][dy]!='#'&&!vis[dx][dy])
            {
                vis[dx][dy]=true;
                Q[Head++]=Node(dx,dy);
            }
        }
    }
    return false;
}
bool OK()
{
    bool ok=true;
    Node s;
    int i,j;
    for(i=0;i<N&&ok;i++)
    {
        for(j=0;j<M;j++)
        {
            if(map[i][j]=='X')
            {
                s.x=i;s.y=j;
                if(!BFS(s))
                {ok=false;break;}
            }
        }
    }
    return ok;
}
void Init()
{
    int i,j,u;
    memset(head,-1,sizeof(head));ecnt=0;
    for(i=0;i<N;i++)
        scanf("%s",map[i]);
    scr=0;sink=1;vn=2;
    Sum=0;
    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
        {
            if(map[i][j]=='X')
            {
                Sum++;
                u=i*M+j+2;
                Insert(scr,u,1);
            }
        }
    }
    now=(M*N);
    vn+=now;
}
int Sap(int s,int t,int n)
{
    int ans=0,aug=INF;
    int i,v,u=pre[s]=s;
    for(i=0;i<=n;i++)
    {
        cur[i]=head[i];
        dis[i]=gap[i]=0;
    }
    gap[s]=n;
    bool flag;
    while(dis[s]<n)
    {
        flag=false;
        for(int &j=cur[u];j!=-1;j=E[j].next)
        {
            v=E[j].v;
            if(E[j].w>0&&dis[u]==dis[v]+1)
            {
                flag=true;
                aug=min(aug,E[j].w);
                pre[v]=u;
                u=v;
                if(u==t)
                {
                    ans+=aug;
                    while(u!=s)
                    {
                        u=pre[u];
                        E[cur[u]].w-=aug;
                        E[cur[u]^1].w+=aug;
                    }
                    aug=INF;
                }
                break;
            }
        }
        if(flag) continue;
        int mindis=n;
        for(i=head[u];i!=-1;i=E[i].next)
        {
            v=E[i].v;
            if(E[i].w>0&&dis[v]<mindis)
            {
                mindis=dis[v];
                cur[u]=i;
            }
        }
        if((--gap[dis[u]])==0) break;
        gap[dis[u]=mindis+1]++;
        u=pre[u];
    }
    return ans;
}
bool Judge(int Ti)
{
    int i,j,k,u,v,a,b,dx,dy;
    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
        {
            if(map[i][j]=='#') continue;
            u=i*M+j+1;
            a=(Ti-1)*N*M;
            b=a+N*M;
            u=a+u+1;
            for(k=0;k<5;k++)
            {
                dx=i+dir[k][0];
                dy=j+dir[k][1];
                if(dx>=0&&dx<N&&dy>=0&&dy<M&&map[dx][dy]!='#')
                {
                    v=dx*M+dy+1;
                    v=b+v+1;
                    Insert(u,v,1);
                }
            }
            if(map[i][j]=='@')
            {
                v=b+i*M+j+2;
                Insert(v,sink,1);
            }
        }
    }
    vn+=(N*M);
    now+=(N*M);
    int t=Sap(scr,sink,vn);
    ans+=t;
    return ans==Sum;
}
void Solve()
{
    if(Sum==0) {printf("0\n");return;}
    if(!OK())  {printf("-1\n");return;}
    ans=Ti=0;
    while(true)
    {
        Ti++;
        if(Judge(Ti)) break;
    }
    printf("%d\n",Ti);
}
int main()
{
    while(scanf("%d%d",&N,&M)!=EOF)
    {
        Init();
        Solve();
    }
return 0;
}
