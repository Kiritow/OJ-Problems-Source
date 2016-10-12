#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
#define INF (1LL<<60)
#define MAXN 333
#define MAXM 3333*666
struct Edge{
    int u,v,next;
    long long cap,cost;
}edge[MAXM];
int head[MAXN];
int NV,NE,vs,vt;
  
void addEdge(int u,int v,long long cap,long long cost){
    edge[NE].u=u; edge[NE].v=v; edge[NE].cap=cap; edge[NE].cost=cost;
    edge[NE].next=head[u]; head[u]=NE++;
    edge[NE].u=v; edge[NE].v=u; edge[NE].cap=0; edge[NE].cost=-cost;
    edge[NE].next=head[v]; head[v]=NE++;
}
bool vis[MAXN];
long long dis[MAXN];
int pre[MAXN];
bool SPFA(){
    for(int i=0; i<NV; ++i){
        vis[i]=0;
        dis[i]=INF;
    }
    vis[vs]=1;
    dis[vs]=0;
    queue<int> que;
    que.push(vs);
    while(!que.empty()){
        int u=que.front(); que.pop();
        for(int i=head[u]; i!=-1; i=edge[i].next){
            int v=edge[i].v;
            if(edge[i].cap && dis[v]>dis[u]+edge[i].cost){
                dis[v]=dis[u]+edge[i].cost;
                pre[v]=i;
                if(!vis[v]){
                    vis[v]=1;
                    que.push(v);
                }
            }
        }
        vis[u]=0;
    }
    return dis[vt]!=INF;
}
long long MCMF(){
    long long res=0;
    while(SPFA()){
        long long flow=INF,cost=0;
        for(int u=vt; u!=vs; u=edge[pre[u]].u){
            flow=min(flow,edge[pre[u]].cap);
        }
        for(int u=vt; u!=vs; u=edge[pre[u]].u){
            edge[pre[u]].cap-=flow;
            edge[pre[u]^1].cap+=flow;
            cost+=flow*edge[pre[u]].cost;
        }
        res+=cost;
    }
    return res;
}
  
long long d[MAXN][MAXN];
  
long long gcd(long long a,long long b){
    if(b==0) return a;
    return gcd(b,a%b);
}
  
bool ok[MAXN][MAXN];
  
long long key[MAXN],val[MAXN];
  
  
int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1; i<=n; ++i){
            scanf("%lld",key+i);
        }
        for(int i=1; i<=n; ++i){
            scanf("%lld",val+i);
        }
        memset(ok,0,sizeof(ok));
        for(int i=1; i<=n; ++i){
            for(int j=i+1; j<=n; ++j){
                if(gcd(key[i],key[j])==1) continue;
                ok[i][j]=1;
                ok[j][i]=1;
            }
        }
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=n; ++j){
                d[i][j]=-INF;
            }
        }
        for(int len=2; len<=n; ++len){
            for(int i=1; i+len-1<=n; ++i){
                if(ok[i][i+len-1] && len==2){
                    d[i][i+len-1]=val[i]+val[i+len-1];
                    continue;
                }
                if(ok[i][i+len-1]) d[i][i+len-1]=max(d[i][i+len-1],val[i]+val[i+len-1]+d[i+1][i+len-1-1]);
                for(int j=0; j<len-1; ++j){
                    d[i][i+len-1]=max(d[i][i+len-1],d[i][i+j]+d[i+j+1][i+len-1]);
                }
            }
        }
        long long ans=0;
         
        vs=0; vt=n+2; NV=vt+1; NE=0;
        memset(head,-1,sizeof(head));
        addEdge(vs,1,1,0);
        addEdge(n+1,vt,1,0);
        for(int i=1; i<=n; ++i){
            addEdge(i,i+1,INF,0);
        }
        for(int i=1; i<=n; ++i){
            for(int j=i+1; j<=n; ++j){
                if(d[i][j]!=-INF){
                    addEdge(i,j+1,1,-d[i][j]);
                }
            }
        }
        printf("%lld\n",-MCMF());
    }
}
