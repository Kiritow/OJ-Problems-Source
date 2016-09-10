#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std ;
const int INF=0xfffffff ;
int n ;
int dis[55][55],ti[55],vis[55],ans ;
void floyd()
{
    for(int k=0 ;k<n ;k++)
    {
        for(int i=0 ;i<n ;i++)
        {
            for(int j=0 ;j<n ;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]) ;
        }
    }
}
void dfs(int now,int s,int t,int sum)
{
    if(s==n)
    {
        ans=min(ans,sum) ;
        return ;
    }
    if(sum>ans)return ;
    for(int i=1 ;i<n ;i++)
        if(!vis[i] && dis[now][i]+t>ti[i])return ;
    for(int i=1 ;i<n ;i++)
    {
        if(!vis[i])
        {
            vis[i]=1 ;
            dfs(i,s+1,t+dis[now][i],sum+dis[now][i]*(n-s)) ;
            vis[i]=0 ;
        }
    }
}
int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=0 ;i<n ;i++)
            for(int j=0 ;j<n ;j++)
                scanf("%d",&dis[i][j]) ;
        for(int i=1 ;i<n ;i++)
            scanf("%d",&ti[i]) ;
        floyd() ;
        ans=INF ;
        memset(vis,0,sizeof(vis)) ;
        dfs(0,1,0,0) ;
        if(ans==INF)puts("-1") ;
        else printf("%d\n",ans) ;
    }
    return 0 ;
}
