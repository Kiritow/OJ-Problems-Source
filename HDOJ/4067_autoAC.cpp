#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
#define MAXN 222
#define MAXM 2222222
#define inf 1<<30
struct Edge{
    int v,cap,cost,next;
}edge[MAXM];
int n,m,vs,vt,NE;
int head[MAXN];
void Insert(int u,int v,int cap,int cost)
{
    edge[NE].v=v;
    edge[NE].cap=cap;
    edge[NE].cost=cost;
    edge[NE].next=head[u];
    head[u]=NE++;
    edge[NE].v=u;
    edge[NE].cap=0;
    edge[NE].cost=-cost;
    edge[NE].next=head[v];
    head[v]=NE++;
}
int dist[MAXN],pre[MAXN],cur[MAXN];
bool mark[MAXN];
bool spfa(int vs,int vt)
{
    memset(mark,false,sizeof(mark));
    fill(dist,dist+MAXN-1,inf);
    dist[vs]=0;
    queue<int>que;
    que.push(vs);
    while(!que.empty()){
        int u=que.front();
        que.pop();
        mark[u]=false;
        for(int i=head[u];i!=-1;i=edge[i].next){
            int v=edge[i].v,cost=edge[i].cost;
            if(edge[i].cap>0&&dist[u]+cost<dist[v]){
                dist[v]=cost+dist[u];
                pre[v]=u;
                cur[v]=i;
                if(!mark[v]){
                    mark[v]=true;
                    que.push(v);
                }
            }
        }
    }
    return dist[vt]<inf;
}
int MinCostFlow(int vs,int vt)
{
    int flow=0,cost=0;
    while(spfa(vs,vt)){
        int aug=inf;
        for(int u=vt;u!=vs;u=pre[u]){
            aug=min(aug,edge[cur[u]].cap);
        }
        flow+=aug;cost+=dist[vt]*aug;
        for(int u=vt;u!=vs;u=pre[u]){
            edge[cur[u]].cap-=aug;
            edge[cur[u]^1].cap+=aug;
        }
    }
    return cost;
}
int In[MAXN],Out[MAXN];
bool Judge()
{
    for(int i=head[vs];i!=-1;i=edge[i].next){
        int cap=edge[i].cap;
        if(cap>0)return false;
    }
    return true;
}
int main()
{
    int s,t,u,v,a,b,sum,cost,T=1,_case;
    scanf("%d",&_case);
    while(_case--){
        scanf("%d%d%d%d",&n,&m,&s,&t);
        NE=0;
        memset(head,-1,sizeof(head));
        memset(In,0,sizeof(In));
        memset(Out,0,sizeof(Out));
        sum=0;
        while(m--){
            scanf("%d%d%d%d",&u,&v,&a,&b);
            if(a<=b){
                Insert(v,u,1,b-a);
                In[v]++,Out[u]++;
                sum+=a;
            }else {
                Insert(u,v,1,a-b);
                sum+=b;
            }
        }
        In[s]++;
        Out[t]++;
        vs=0,vt=n+1;
        for(int i=1;i<=n;i++){
            if(In[i]>Out[i])Insert(vs,i,(In[i]-Out[i]),0);
            else if(In[i]<Out[i])Insert(i,vt,(Out[i]-In[i]),0);
        }
        cost=MinCostFlow(vs,vt);
        printf("Case %d: ",T++);
        if(Judge()){
            printf("%d\n",sum+cost);
        }else 
            puts("impossible");
    }
    return 0;
}
