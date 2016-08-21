#include<cstdio>
#define Max 456
#include<cstring>
using namespace std;
int g[Max][Max];
int lx[Max],ly[Max];
int visx[Max],visy[Max];
int match[Max];
int n;
int findpath(int u);
int KM();
int main()
{
    //int T;
    //scanf("%d",&T);
    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        scanf("%d",&g[i][j]);
        printf("%d\n",KM());
    }
    return 0;
}
int findpath(int u)
{
    visx[u]=1;
    for(int v=1;v<=n;v++)
    {
        if(!visy[v]&&lx[u]+ly[v]==g[u][v])
        {
            int t=match[v];visy[v]=1;
            if(!t||findpath(t))
            {
                match[v]=u;return 1;
            }
        }
    }
    return 0;
}
int KM()
{
    for(int i=1;i<=n;i++)
    {
        lx[i]=0x80000000;
        ly[i]=0;
        for(int j=1;j<=n;j++)
        if(lx[i]<g[i][j])
        lx[i]=g[i][j];
    }
    memset(match,0,sizeof(match));
    for(int u=1;u<=n;u++)
    {
        while(1)
        {
            memset(visx,0,sizeof(visx));
            memset(visy,0,sizeof(visy));
            if(findpath(u))
            break;
            int d=0x7fffffff;
            for(int i=1;i<=n;i++)
            {
                if(visx[i])
                {
                    for(int j=1;j<=n;j++)
                    if(!visy[j]&&d>lx[i]+ly[j]-g[i][j])
                    d=lx[i]+ly[j]-g[i][j];
                }
            }
            for(int k=1;k<=n;k++)
            {
                if(visx[k])
                lx[k]-=d;
                if(visy[k])
                ly[k]+=d;
            }
        }
    }
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        int t=match[i];
        if(t)
        sum+=g[t][i];
    }
    return sum;
}
