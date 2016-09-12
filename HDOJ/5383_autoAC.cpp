#include<iostream>
#include<queue>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAXN 805
typedef long long LL;
const LL INF = 1000000007;
struct edge{
    int to,next,cost,cap;
}E[2000000];
struct node{
    int lev,tun,atk;
}A[MAXN];
int head[MAXN],si,prevv[MAXN],preve[MAXN],que[200000],n,m,used[MAXN],C[400][400];
LL dist[MAXN];
void add_edge(int u,int v,int c,int cap)
{
    //printf("%d->%d(cap:%d,cost:%d)\n",u,v,cap,c);
    E[si].to=v;
    E[si].cost=c;
    E[si].cap=cap;
    E[si].next=head[u];
    head[u]=si++;
    E[si].to=u;
    E[si].cost=-c;
    E[si].cap=0;
    E[si].next=head[v];
    head[v]=si++;
}
bool SPFA(int s,int t)
{
    for(int i=0;i<=2*n+1;i++)dist[i]=INF,used[i]=false;
    dist[s]=0;
    int h=0,tail=0;
    for(que[tail++]=s,used[s]=true;h<tail;h++){
        int v=que[h];used[v]=false;
        for(int i=head[v];~i;i=E[i].next){
            if(E[i].cap>0){
                int u=E[i].to;
                if(dist[u]>dist[v]+E[i].cost){
                   // printf("dist[%d]=%I64d___dist[%d]=%I64d___cost:%d\n",u,dist[u],v,dist[v],E[i].cost);
                    dist[u]=dist[v]+E[i].cost;
                    prevv[u]=v;
                    preve[u]=i;
                    if(!used[u]){
                        que[tail++]=u;
                        used[u]=true;
                    }
                }
            }
        }
    }
  //  printf("dist:%I64d\n",dist[t]);
    if(dist[t]<0)return true;
    return false;
}
int min_cost_flow(int s,int t)
{
    LL ans=0;
    while(SPFA(s,t)){
        int d=INF;
        for(int v=t;s!=v;v=prevv[v]){
            d=std::min(d,E[preve[v]].cap);
        }
        ans+=d*dist[t];
        for(int v=t;v!=s;v=prevv[v]){
            E[preve[v]].cap-=d;
            E[preve[v]^1].cap+=d;
        }
    }
    return ans;
}
int main()
{
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        memset(head,-1,sizeof head);si=0;
        memset(C,0,sizeof C);
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&A[i].tun,&A[i].lev,&A[i].atk);
            add_edge(0,i,0,1);
            add_edge(i,i+n,-A[i].atk,1);
            add_edge(i+n,n*2+1,0,1);
        }
        for(int i=1,lev,atk,r,u,v;i<=m;i++){
            scanf("%d%d%d",&lev,&atk,&r);
            if(r==0){
                for(int j=1;j<=n;j++){
                    if(!A[j].tun)
                    for(int k=1;k<=n;k++)if(A[k].tun&&A[j].lev+A[k].lev==lev){
                        C[j][k]=std::min(C[j][k],-atk);
                    }
                }
            }
            else if(r==1){
                scanf("%d",&v);
                if(A[v].tun){
                    for(int j=1;j<=n;j++)if(!A[j].tun&&A[j].lev+A[v].lev==lev){
                      //  add_edge(j,v+n,-atk,1);
                        C[j][v]=std::min(C[j][v],-atk);
                    }
                }
                else{
                    for(int j=1;j<=n;j++)if(A[j].tun&&A[j].lev+A[v].lev==lev){
                        add_edge(v,j+n,-atk,1);
                        C[v][j]=std::min(C[v][j],-atk);
                    }
                }
            }
            else{
                scanf("%d%d",&u,&v);
                if(A[u].tun)std::swap(u,v);
                C[u][v]=std::min(C[u][v],-atk);
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)if(C[i][j]<0&&C[i][j]<-A[i].atk-A[j].atk){
                add_edge(i,j+n,C[i][j],1);
            }
        }
        LL ans=-min_cost_flow(0,n*2+1);
        printf("%I64d\n",ans);
    }
    return 0;
}
