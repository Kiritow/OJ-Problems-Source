#include"iostream"
#include "queue"
#define inf 0x7FFFFFFF
#define M 500010
using namespace std;
int head[M],minm,maxm,dis[M],edge_sum;
bool inq[M];
struct a{
    int end,jie,next;
}edge[M];
void Init(){
    edge_sum=0;
    memset(head,-1,sizeof(head));
    minm=inf;
    maxm=-inf;
    memset(inq,0,sizeof(inq));
    memset(dis,-inf,sizeof(dis));
}
void add_edge(int u,int v, int jie){
    edge[edge_sum].end=v;
    edge[edge_sum].jie=jie;
    edge[edge_sum].next=head[u];
    head[u]=edge_sum++;
}
int max(int a,int b){ if(a>b)return a;return b;}
int min(int a,int b){ if(a<b)return a;return b;}
int spfa(){
    memset(dis,inf,sizeof(dis));
    queue<int> q;
    while(!q.empty())q.pop();
    q.push(minm), inq[minm]=1,  dis[minm]=0;
    while( !q.empty()){
        int u=q.front();    q.pop(),  inq[u]=0;
        for(int i=head[u] ; i!=-1; i=edge[i].next )
        {
            int v=edge[i].end, jie=edge[i].jie;
            if(dis[v]<dis[u]+jie)
            {
                dis[v]=dis[u]+jie;
                if( !inq[v] )    inq[v]=!inq[v],  q.push(v);
            }
        }
    }
    return dis[maxm];
}
int main(){
    int n;
    while(~scanf("%d",&n)){
        Init();
        while(n--){
            int u,v,jie;
            scanf("%d %d %d",&u,&v,&jie);
            add_edge(u,v+1,jie);
            minm=min(u,minm);
            maxm=max(v+1,maxm);
        }
        for( int i=minm;i<=maxm;i++)
            add_edge(i,i+1,0),  add_edge(i+1,i,-1);
        printf("%d\n",spfa());
    }
    return 0;
}
