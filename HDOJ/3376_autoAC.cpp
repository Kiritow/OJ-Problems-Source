#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std ;
const int INF=0xfffffff ;
struct node{
    int s,t,cap,cost,nxt ;
}e[4000005] ;
int sumflow ;
int n,m,cnt,head[1000005],vis[1000005],dis[1000005],pre[1000005] ;
void add(int s,int t,int cap,int cost)
{
    e[cnt].s=s ;e[cnt].t=t ;e[cnt].cap=cap ;e[cnt].cost=cost ;e[cnt].nxt=head[s] ;head[s]=cnt++ ;
    e[cnt].s=t ;e[cnt].t=s ;e[cnt].cap=0 ;e[cnt].cost=-cost ;e[cnt].nxt=head[t] ;head[t]=cnt++ ;
}
int spfa(int s,int t,int N)
{
    for(int i=0 ;i<=N ;i++)
        dis[i]=INF ;
    dis[s]=0 ;
    memset(vis,0,sizeof(vis)) ;
    memset(pre,-1,sizeof(pre)) ;
    vis[s]=1 ;
    queue <int> q ;
    q.push(s) ;
    while(!q.empty())
    {
        int u=q.front() ;
        q.pop() ;
        vis[u]=0 ;
        for(int i=head[u] ;i!=-1 ;i=e[i].nxt)
        {
            int tt=e[i].t ;
            if(e[i].cap && dis[tt]>dis[u]+e[i].cost)
            {
                dis[tt]=dis[u]+e[i].cost ;
                pre[tt]=i ;
                if(!vis[tt])
                {
                    vis[tt]=1 ;
                    q.push(tt) ;
                }
            }
        }
    }
    if(dis[t]==INF)return 0 ;
    return 1 ;
}
int MCMF(int s,int t,int N)
{
    int flow,minflow,mincost ;
    mincost=flow=0 ;
    while(spfa(s,t,N))                                                
    {
        minflow=INF ;
        for(int i=pre[t] ;i!=-1 ;i=pre[e[i].s])
            minflow=min(minflow,e[i].cap) ;
        flow+=minflow ;
        for(int i=pre[t] ;i!=-1 ;i=pre[e[i].s])
        {
            e[i].cap-=minflow ;
            e[i^1].cap+=minflow ;
        }
        mincost+=dis[t]*minflow ;
    }
    sumflow=flow ;
    return mincost ;
}
int num[605][605],M[605][605] ;
int main()
{
    while(~scanf("%d",&n))
    {
        cnt=0 ;
        memset(head,-1,sizeof(head)) ;
        int S=0 ;
        int T=2*n*n+1 ;
        int ct=1 ;
        for(int i=1 ;i<=n ;i++)
            for(int j=1 ;j<=n ;j++)
            {
                scanf("%d",&M[i][j]) ;
                num[i][j]=ct++ ;
            }
           add(S,1,2,0) ;
           add(n*n*2,T,2,0) ;
          for(int i=1 ;i<=n ;i++)
          {
              for(int j=1 ;j<=n ;j++)
              {
                  if(num[i][j]==1)add(num[i][j],num[i][j]+n*n,2,-M[i][j]) ;
                  else if(num[i][j]==n*n)add(num[i][j],num[i][j]+n*n,2,-M[i][j]) ;
                  else add(num[i][j],num[i][j]+n*n,1,-M[i][j]) ;
                  if(i<n)add(num[i][j]+n*n,num[i][j]+n,1,0) ;
                  if(j<n)add(num[i][j]+n*n,num[i][j]+1,1,0) ;
              }
          }
          printf("%d\n",-(MCMF(S,T,T+1)+M[1][1]+M[n][n])) ;
    }
    return 0 ;
}
