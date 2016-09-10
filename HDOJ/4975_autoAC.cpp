#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;
const int inf=1<<29;
const int maxn=1100;
const int maxm=6e5;
struct Edge
{
    int u;
    int v;
    int f;
    int nxt;
    Edge(){}
    Edge(int su,int sv,int sf,int snxt):u(su),v(sv),f(sf),nxt(snxt){}
}E[maxm];
int n,m,row[510],col[510],sumr,sumc;
int e,st,des,head[maxn],level[maxn];
bool vis[maxn];
int q[maxn];
void AddEdge(int u,int v,int f)
{
    E[e]=Edge(u,v,f,head[u]);
    head[u]=e++;
    E[e]=Edge(v,u,0,head[v]);
    head[v]=e++;
}
void Build()
{
    e=st=0,des=n+m+1;
    memset(head,-1,sizeof(head));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            AddEdge(i,n+j,9);
    for(int i=1;i<=n;i++)
        AddEdge(st,i,row[i]);
    for(int i=1;i<=m;i++)
        AddEdge(n+i,des,col[i]);
}
bool BFS()
{
    memset(level,0,sizeof(level));
    level[st]=1;
    int pre=0,last=1;
    q[pre]=st;
    while(pre<last)
    {
        int u=q[pre++];
        for(int i=head[u];i!=-1;i=E[i].nxt)
            if(E[i].f&&!level[E[i].v])
            {
                level[E[i].v]=level[u]+1;
                q[last++]=E[i].v;
                if(E[i].v==des)
                    return level[E[i].v];
            }
    }
    return level[des];
}
int DFS(int u,int maxf)
{
    if(u==des||!maxf)
        return maxf;
    int f=0;
    for(int i=head[u];i!=-1;i=E[i].nxt)
        if(E[i].f&&level[E[i].v]==level[u]+1)
        {
            int t=DFS(E[i].v,min(E[i].f,maxf-f));
            if(t>0)
            {
                E[i].f-=t;
                E[i^1].f+=t;
                f+=t;
                if(f==maxf)
                    break;
            }
            else
                level[E[i].v]=0;
        }
    return f;
}
int maxflow()
{
    int ans=0;
    while(BFS())
        ans+=DFS(st,inf);
    return ans;
}
bool dfs(int u,int f)
{
    vis[u]=1;
    for(int &i=head[u];i!=-1;i=E[i].nxt)
        if(E[i].f)
        {
            if(!vis[E[i].v])
            {
                if(dfs(E[i].v,u))
                    return true;
            }
            else if(E[i].v!=f)
                return true;
        }
    vis[u]=0;
    return false;
}
void solve(int sumr,int sumc)
{
    if(sumr!=sumc)
    {
        printf("So naive!\n");
        return;
    }
    Build();
    int ans=maxflow();
    if(ans!=sumc)
    {
        printf("So naive!\n");
        return;
    }
    memset(vis,0,sizeof(vis));
    bool is=false;
    for(int i=1;i<=n;i++)
        if(dfs(i,-1))
            is=true;
    if(!is)
        printf("So simple!\n");
    else
        printf("So young!\n");
}
inline bool read(int &n)
{      
    int x = 0, tmp = 1;      
    char c = getchar();      
    while((c < '0' || c > '9') && c != '-' && c != EOF) c = getchar();      
    if(c == EOF) return false;      
    if(c == '-') c = getchar(), tmp = -1;      
    while(c >= '0' && c <= '9') x *= 10, x += (c - '0'),c = getchar();      
    n = x*tmp;      
    return true;    
}      
int main()
{
    int T,cas=1;
    scanf("%d",&T);
    while(T--)
    {
        sumr=sumc=0;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            read(row[i]);
            sumr+=row[i];
        }
        for(int i=1;i<=m;i++)
        {
            read(col[i]);
            sumc+=col[i];
        }
        printf("Case #%d: ",cas++);
        solve(sumr,sumc);
    }
    return 0;
}
