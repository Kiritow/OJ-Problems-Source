#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int maxn = 40;
const int maxpot = maxn*maxn*2;
const int maxm = maxpot*10;
const int INFI = 99999999;
const int dx[4] = {0,1,0,-1};
const int dy[4] = {1,0,-1,0};
int a[maxn][maxn];
int idx[maxn][maxn];
int L[maxpot],R[maxpot];
int head[maxpot],dep[maxpot],lis[maxpot];
int ne[maxm],pot[maxm],flow[maxm];
int S,T,tot,n,m;
void addedge(int a,int b,int c)
{
    pot[++tot] = b; ne[tot] = head[a];
    head[a] = tot; flow[tot] = c;
}
void connect(int a,int b,int c)
{
    addedge(a,b,c);
    addedge(b,a,0);
}
bool bfs()
{
    for (int i=0;i<=T;i++) dep[i] = 0;
    int h=1,t=1;
    lis[1] = S;
    dep[S] = 1;
    while ( h<=t )
    {
        int v = lis[h];
        for (int e=head[v];e!=-1;e=ne[e])
        if ( flow[e]>0 && dep[pot[e]]==0 )
        {
            dep[pot[e]] = dep[v] + 1;
            lis[++t] = pot[e];
        }
        h++;
    }
    return dep[T]>0;
}
int findpath(int v,int tmpflow)
{
    if ( v==T ) return tmpflow;
    int rec = 0,tmp;
    for (int e=head[v];e!=-1;e=ne[e])
    if ( flow[e]>0 && dep[pot[e]]==dep[v]+1 )
    {
        tmp = findpath(pot[e],min(tmpflow,flow[e]));
        tmpflow -= tmp; rec += tmp;
        flow[e] -= tmp; flow[e^1] += tmp;
        if ( tmpflow==0 ) break;
    }
    dep[v] = 0;
    return rec;
}
int dinic()
{
    int ret = 0;
    while ( bfs() )
        ret += findpath(S,INFI);
    return ret;
}
void build_graph()
{
    int sum = 0;
    int tx,ty;
    int v,u;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
        if ( a[i][j]!=-1 )
            idx[i][j] = ++sum;
    S = 0;
    for (int i=1;i<=sum;i++)
    {
        L[i] = i;
        R[i] = i + sum;
    } 
    T = 2 * sum + 1;
    memset(head,-1,sizeof(head));
    tot = -1;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
        if ( a[i][j]!=-1 )
        {
            v = idx[i][j];
            if ( a[i][j]!=0 )
                connect(L[v],R[v],a[i][j]);
            else
                connect(L[v],R[v],INFI);
            for (int t=0;t<4;t++)
            {
                tx = i + dx[t];
                ty = j + dy[t];
                if ( tx<0 || ty<0 || tx>=n || ty>=m ) continue;
                u = idx[tx][ty];
                if ( a[tx][ty]!=-1 )
                    connect(R[v],L[u],INFI);    
            }
            if ( a[i][j]==0 )
                connect(S,L[v],INFI);
            if ( i==0 || j==0 || i==n-1 || j==m-1 )
                connect(R[v],T,INFI);
        }
}
int main()
{
    int test;
    scanf("%d",&test);
    for (int cas=1;cas<=test;cas++)
    {
        scanf("%d%d",&n,&m);
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                scanf("%d",&a[i][j]);
        build_graph();
        int ans = dinic();
        printf("%d\n",ans);
    }
}
