#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=400;
const int INF=0x7fffffff;
int N,M,S;
int a[MAXN][MAXN],dis[MAXN];
bool visit[MAXN],d[MAXN];
int StoerWagner(int N)
{
    int p=N,ans=INF,Max,t,s,k,i;
    memset(d,0,sizeof(d));
    while (--p>0)
    {
        memset(visit,0,sizeof(visit));
        memset(dis,0,sizeof(dis));
        i=1;
        while (d[i]) i++;
        visit[i]=1;
        for (int j=1;j<=N;j++)
            if (!d[j] && !visit[j])
                dis[j]=a[i][j];
        t=s=i;
        for (;i<=N;i++)
        {
            Max=0;
            for (int j=1;j<=N;j++)
                if (!d[j] && !visit[j] && Max<dis[j])
                    Max=dis[k=j];
            if (!Max) break;
            visit[k]=1;
            for (int j=1;j<=N;j++)
                if (!d[j] && !visit[j])
                    dis[j]+=a[k][j];
            s=t;
            t=k;
        }
        if (ans>dis[t]) ans=dis[t];
        d[t]=1;
        for (int j=1;j<=N;j++)
            if (!d[j])
            {
                a[s][j]+=a[t][j];
                a[j][s]+=a[j][t];
            }
    }
    return ans;
}
int main()
{
    while (1)
    {
        scanf("%d%d%d",&N,&M,&S);
        if (!N && !M && !S) break;
        memset(a,0,sizeof(a));
        for (int i=1;i<=M;i++)
        {
            int x,y,d;
            scanf("%d%d%d",&x,&y,&d);
            a[x][y]+=d;
            a[y][x]+=d;
        }
        printf("%d\n",StoerWagner(N));
    }
    return 0;
}
