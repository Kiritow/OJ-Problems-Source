#include <iostream>
#include <cstdio>
#include <cstring> 
using namespace std ; 
const int INF=0xfffffff ;
struct node
{
    int s,t,cap,nxt ;
}e[400005] ;
int m,n,cnt,head[100005],level[100005],q[100005] ;
void add(int s,int t,int cap)
{
    e[cnt].s=s ;e[cnt].t=t ;e[cnt].cap=cap ;e[cnt].nxt=head[s] ;head[s]=cnt++ ;
    e[cnt].s=t ;e[cnt].t=s ;e[cnt].cap=0 ;e[cnt].nxt=head[t] ;head[t]=cnt++ ;
}
bool build(int s,int t)
{
    int front=0,rear=0 ;
    memset(level,-1,sizeof(level)) ;
    q[rear++]=s ;
    level[s]=1 ;
    while(front<rear)
    {
        int u=q[front++] ;
        for(int i=head[u] ;i!=-1 ;i=e[i].nxt)
        {
            int tt=e[i].t ;
            if(level[tt]==-1 && e[i].cap>0)
            {
                level[tt]=level[u]+1 ;
                if(tt==t)return true ;
                q[rear++]=tt ;
            }
        }
    }
    return false ;
}
int find(int s,int t,int flow)
{
    if(s==t)return flow ;
    int ret=0,a ;
    for(int i=head[s] ;i!=-1 ;i=e[i].nxt)
    {
        int tt=e[i].t ;
        if(level[tt]==level[s]+1 && e[i].cap>0)
        {
            a=find(tt,t,min(e[i].cap,flow-ret)) ;
            e[i].cap-=a ;
            e[i^1].cap+=a ;
            ret+=a ;
            if(ret==flow)
                return ret ;
        }
    }
    if(!ret)level[s]=-1 ;
    return ret ;
}
int dinic(int s,int t)
{
    int flow,ret=0 ;
    while(build(s,t))
        while(flow=find(s,t,INF))
            ret+=flow ;
    return ret ;
}
int a[1005],dp[1005] ;
int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=1 ;i<=n ;i++)
            scanf("%d",&a[i]) ;
        int ans=0 ;
        for(int i=1 ;i<=n ;i++)
        {
            dp[i]=1 ;
            for(int j=1 ;j<i ;j++)
                if(a[j]<a[i] && dp[j]+1>dp[i])
                    dp[i]=dp[j]+1 ;
            ans=max(ans,dp[i]) ;
        }
        int S,T ;
        S=0 ;T=2*n+1 ;
        cnt=0 ;
        memset(head,-1,sizeof(head)) ;
        for(int i=1 ;i<=n ;i++)
        {
            add(i,i+n,1) ;
            if(dp[i]==1)add(S,i,1) ;
            if(dp[i]==ans)add(i+n,T,1) ;
            for(int j=i+1 ;j<=n ;j++)
            {
                if(dp[j]==dp[i]+1)
                    add(i+n,j,1) ;
            }
        }
        printf("%d\n%d\n",ans,dinic(S,T)) ;
    }
    return 0 ;
}
