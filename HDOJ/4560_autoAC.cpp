#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <math.h>
using namespace std;
const int MAXN=1100;
int maze[MAXN][MAXN];
int gap[MAXN],dis[MAXN],pre[MAXN],cur[MAXN];
int flow[MAXN][MAXN];
int sap(int start,int end,int nodenum)
{
    memset(cur,0,sizeof(cur));
    memset(dis,0,sizeof(dis));
    memset(gap,0,sizeof(gap));
    memset(flow,0,sizeof(flow));
    int u=pre[start]=start,maxflow=0,aug=-1;
    gap[0]=nodenum;
    while(dis[start]<nodenum)
    {
        loop:
          for(int v=cur[u];v<nodenum;v++)
            if(maze[u][v]-flow[u][v] && dis[u]==dis[v]+1)
            {
                if(aug==-1 || aug>maze[u][v]-flow[u][v])aug=maze[u][v]-flow[u][v];
                pre[v]=u;
                u=cur[u]=v;
                if(v==end)
                {
                    maxflow+=aug;
                    for(u=pre[u];v!=start;v=u,u=pre[u])
                    {
                        flow[u][v]+=aug;
                        flow[v][u]-=aug;
                    }
                    aug=-1;
                }
                goto loop;
            }
            int mindis=nodenum-1;
            for(int v=0;v<nodenum;v++)
               if(maze[u][v]-flow[u][v]&&mindis>dis[v])
               {
                   cur[u]=v;
                   mindis=dis[v];
               }
            if((--gap[dis[u]])==0)break;
            gap[dis[u]=mindis+1]++;
            u=pre[u];
    }
    return maxflow;
}
bool used[MAXN][MAXN];
int main()
{
    int T;
    int N,M,L,K;
    scanf("%d",&T);
    int iCase=0;
    while(T--)
    {
        iCase++;
        scanf("%d%d%d%d",&N,&M,&L,&K);
        memset(maze,0,sizeof(maze));
        int u,v;
        memset(used,false,sizeof(used));
        while(L--)
        {
            scanf("%d%d",&u,&v);
            used[u][v]=true;
        }
        for(int i=N+1;i<=N+M;i++)maze[i][i+M]=K;
        for(int i=1;i<=N;i++)
            for(int j=1;j<=M;j++)
            {
                if(used[i][j])
                {
                    maze[i][j+N+M]=1;
                }
                else maze[i][j+N]=1;
            }
        int ans=0;
        int l=0,r=M;
        while(l<=r)
        {
            int mid=(l+r)/2;
            for(int i=1;i<=N;i++)maze[0][i]=mid;
            for(int i=N+M+1;i<=N+2*M;i++)maze[i][N+2*M+1]=mid;
            if(sap(0,N+2*M+1,N+2*M+2)==mid*N)
            {
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        printf("Case %d: %d\n",iCase,ans);
    }
    return 0;
}
