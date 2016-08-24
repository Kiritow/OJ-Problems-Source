#include<stdio.h>
#define max 1001
#define INF 100000000
int N;
int v[max];
int dis[max];
int g[max][max];
void dijk()
{
    int i,j,mark,mindis;
    for(i=0;i<=N;i++)
    {
        v[i] = 0;
        dis[i] = INF;
    }
    dis[0] = 0;
    v[0]  = 1;
    for(i=0;i<=N;i++)
    {
        mindis = INF;
        mark = 0;
        for(j=0;j<=N;j++)
        if(!v[j] && dis[j] < mindis)
        {
            mindis = dis[j];
            mark = j;
        }
        v[mark] = j;
        for(j=0;j<=N;j++)
        if(!v[j] && dis[j] > dis[mark] + g[mark][j])
            dis[j] = dis[mark] + g[mark][j];
    }
}
int main()
{
    int W,M,Q,i,j,d,a,b;
    while(~scanf("%d%d%d",&N,&M,&Q))
    {
        for(i=0;i<max;i++)
        for(j=0;j<max;j++)
        {
            if(i==j)g[i][j] = 0;
            else
            g[i][j] = INF;
        }
        while(M--)
        {
            scanf("%d%d%d",&a,&b,&d);
            if(d < g[a][b])
            g[a][b] = d;
        }
        scanf("%d",&W);
        while(W--)
        {
            scanf("%d",&a);
            g[0][a] = 0;
        }
        dijk();
        if(dis[Q] == INF)
        printf("-1\n");
        else
        printf("%d\n",dis[Q]);
    }
}
