#include <iostream>
#include <algorithm>
#include <string.h>
#define MAXN 1010
#define MAXM 20010
#define INF 0x7fffffff
using namespace std;
struct edge
{
    int to,w,next; 
}E[MAXM];
int head[MAXN],ecnt;
int Stack[MAXN],dis[MAXN],cnt[MAXN];
bool used[MAXN];
int N,X,Y,top;
void Insert(int from,int to,int w)
{
    E[ecnt].to=to;
    E[ecnt].w=w;
    E[ecnt].next=head[from];
    head[from]=ecnt++; 
}
bool Relax(int from,int to,int w)
{
    if(dis[to]>dis[from]+w)
    {
        dis[to]=dis[from]+w;
        return true; 
    } 
return false;
}
void Init()
{
    int i,u,v,w;
    memset(head,-1,sizeof(head));ecnt=0;
    for(i=1;i<=X;i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        Insert(u,v,w);  
    }
    for(i=1;i<=Y;i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        Insert(v,u,-w);
    }
    for(i=1;i<N;i++)
        Insert(i+1,i,0);
}
int SPFA(int s)
{
    int i,u,v;
    for(i=0;i<=N;i++)
    {
        cnt[i]=0;
        used[i]=false;
        dis[i]=INF; 
    }
    top=0;
    Stack[top++]=s;
    dis[s]=0;
    used[s]=true;
    while(top)
    {
        u=Stack[--top];
        used[u]=false;
        cnt[u]++;
        if(cnt[u]>N)
            return -1;
        for(i=head[u];i!=-1;i=E[i].next)
        {
            v=E[i].to;
            if(Relax(u,v,E[i].w)&&!used[v])
            {
                Stack[top++]=v;
                used[v]=true;
            }
        }
    }
    if(dis[N]==INF) 
        return -2;
    return dis[N]; 
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&N,&X,&Y);
        Init();
        int ans=SPFA(1);
        printf("%d\n",ans); 
    }
return 0;
}
