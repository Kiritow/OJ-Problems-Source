#include<stdio.h>
#include<string.h>
#define inf 1000000
#define N 205
int n,y[N],g[N][N],lx[N],ly[N],slack[N];
char vx[N],vy[N];
int search(int u)
{
    vx[u]=1;
    for(int v=1;v<=n;v++)
        if(lx[u]+ly[v]==g[u][v])
        {
            if(vy[v]==1) continue;
            vy[v]=1;
            if(y[v]==-1||search(y[v]))
            {
                y[v]=u;
                return 1;
            }
        }
        else if(lx[u]+ly[v]-g[u][v]<slack[v])
            slack[v]=lx[u]+ly[v]-g[u][v];
    return 0;
}
int KM()
{
    int i,j,min;
    memset(y,-1,sizeof(y));
    memset(ly,0,sizeof(ly));
    memset(lx,0,sizeof(lx));
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            slack[j]=inf;
        while(1)
        {
            memset(vx,0,sizeof(vx));
            memset(vy,0,sizeof(vy));
            if(search(i)) break;
            for(min=inf,j=1;j<=n;j++)
                if(!vy[j]&&slack[j]<min)
                    min=slack[j];
            for(j=1;j<=n;j++)
                if(vx[j]) lx[j]-=min;
            for(j=1;j<=n;j++)
                if(vy[j]) ly[j]+=min;
                else slack[j]-=min;
        }
    }
    int ans=0;
    for(i=1;i<=n;i++)
        ans+=g[y[i]][i];
    return ans;
}
int main()
{
    int t,m,i,j,u,v,w;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                g[i][j]=-inf;
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            if(g[u][v]<-w)
                g[u][v]=-w;
        }
        int ans=-1*KM();
        printf("%d\n",ans);
    }
    return 0;
}
