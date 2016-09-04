#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int inf=1<<28;
int g[1005][1005];
int lx[1005],ly[1005];
bool sx[1005],sy[1005];
int link[1005],n;
vector<int> q[1010];
int min(int a,int b)
{
    if(a<b)  return a;
    return b;
}
bool path(int k)
{
    sx[k]=true;
    for(int i=1; i<=n; i++)
    {
        if(!sy[i]&&(lx[k]+ly[i]==g[k][i]))
        {
            sy[i]=1;
            if(link[i]==-1||path(link[i]))
            {
                link[i]=k;
                return true;
            }
        }
    }
    return false;
}
int BestMatch()
{
    int d,sum;
    memset(ly,0,sizeof(ly));
    memset(link,-1,sizeof(link));
    for(int i=1; i<=n; i++)
    {
        lx[i]=-inf;
        for(int j=1; j<=n; j++)
            if(lx[i]<g[i][j])  lx[i]=g[i][j];
    }
    for(int k=1; k<=n; k++)
    {
        while(1)
        {
            memset(sx,0,sizeof(sx));
            memset(sy,0,sizeof(sy));
            if(path(k))  break;
            d=inf;
            for(int i=1; i<=n; i++)
                if(sx[i])
                    for(int j=1; j<=n; j++)
                        if(!sy[j])
                            d=min(d,lx[i]+ly[j]-g[i][j]);
            for(int i=1; i<=n; i++)
            {
                if(sx[i]) lx[i]-=d;
                if(sy[i]) ly[i]+=d;
            }
        }
    }
    sum=0;
    for(int i=1; i<=n; i++)
    {
        if(link[i]==-1||g[link[i]][i]==-inf) return -1;
        sum+=g[link[i]][i];
    }
    return -sum;
}
int main()
{
    int m,T,cas=1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)  q[i].clear();
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                g[i][j]=inf;
        for(int i=1; i<=m; i++)
        {
            int x,y,c;
            scanf("%d%d%d",&x,&y,&c);
            g[x][y]=g[y][x]=min(g[x][y],c);
        }
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++) g[i][j]=-g[i][j];
        int t=BestMatch();
        if(t==-1)  printf("Case %d: NO\n",cas++);
        else printf("Case %d: %d\n",cas++,t);
    }
    return 0;
}
