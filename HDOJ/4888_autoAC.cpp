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
int S,T ;
int vis[100005] ;
int JG(int u,int fa)
{
    if(vis[u])return 1 ;
    vis[u]=1 ;
    for(int i=head[u] ;i!=-1 ;i=e[i].nxt)
    {
        int v=e[i].t ;
        if(v!=fa && v!=S && v!=T && e[i].cap)
            if(JG(v,u))return 1 ;
    }
    vis[u]=0 ;
    return 0 ;
}
int A[505],B[505] ;
int res[505][505] ;
int main()
{
    int k ;
    while(~scanf("%d%d%d",&n,&m,&k))
    {
        cnt=0 ;
        memset(head,-1,sizeof(head)) ;
        int sum1=0,sum2=0 ;
        S=0 ;T=n+m+1 ;
        for(int i=1 ;i<=n ;i++)
        {
            scanf("%d",&A[i]) ;
            sum1+=A[i] ;
            add(S,i,A[i]) ;
            for(int j=1 ;j<=m ;j++)
                add(i,j+n,k) ;
        }
        for(int i=1 ;i<=m ;i++)
        {
            scanf("%d",&B[i]) ;
            sum2+=B[i] ;
            add(i+n,T,B[i]) ;
        }
        int ans=dinic(S,T) ;
        if(ans==sum1 && ans==sum2)
        {
            int flag=0 ;
            memset(vis,0,sizeof(vis)) ;
            for(int i=1 ;i<=n ;i++)
            {
                if(JG(i,-1))
                {
                    flag=1 ;
                    break ;
                }
            }
            if(flag)
            {
                puts("Not Unique") ;
            }
            else
            {
                puts("Unique") ;
                memset(res,0,sizeof(res)) ;
                for(int i=1 ;i<=n ;i++)
                {
                    for(int j=head[i] ;j!=-1 ;j=e[j].nxt)
                    {
                        if(e[j].t<=n+m && e[j].t>n)
                            res[i][e[j].t-n]=k-e[j].cap ;
                    }
                }
                for(int i=1 ;i<=n ;i++)
                {
                    for(int j=1 ;j<=m ;j++)
                     {
                         if(j>1)printf(" ") ;
                         printf("%d",res[i][j]) ;
                    }
                    putchar('\n') ;
                }
            }
        }
        else
        {
            puts("Impossible") ;
        }
    }
    return 0 ;
}
