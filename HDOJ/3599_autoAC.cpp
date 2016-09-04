#include<iostream>
#include<cstdio>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
#define MAXN 4444
#define inf 1<<30
struct Node{
    int v,w;
    Node(int vv,int ww):v(vv),w(ww){};
};
int n;
bool mark[MAXN];
int dist[MAXN];
vector<vector<Node> >G;
void spfa()
{
    memset(mark,false,sizeof(mark));
    fill(dist,dist+n+2,inf);
    dist[1]=0;
    queue<int>que;
    que.push(1);
    while(!que.empty()){
        int u=que.front();
        que.pop();
        mark[u]=false;
        for(int i=0;i<G[u].size();i++){
            int v=G[u][i].v;
            int w=G[u][i].w;
            if(dist[u]+w<dist[v]){
                dist[v]=dist[u]+w;
                if(!mark[v]){
                    mark[v]=true;
                    que.push(v);
                }
            }
        }
    }
}
struct Edge{
    int v,cap,next;
}edge[MAXN*MAXN];
int NE,NV;
int head[MAXN];
void Insert(int u,int v,int cap)
{
    edge[NE].v=v;
    edge[NE].cap=cap;
    edge[NE].next=head[u];
    head[u]=NE++;
    edge[NE].v=u;
    edge[NE].cap=0;
    edge[NE].next=head[v];
    head[v]=NE++;
}
void Build()
{
    NE=0;
    NV=n;
    memset(head,-1,sizeof(head));
    for(int u=1;u<=n;u++){
        for(int i=0;i<G[u].size();i++){
            int v=G[u][i].v,w=G[u][i].w;
            if(dist[u]+w==dist[v]){
                Insert(u,v,1);
            }
        }
    }
}
int level[MAXN],gap[MAXN];
void bfs(int vt)
{
    memset(level,-1,sizeof(level));
    memset(gap,0,sizeof(gap));
    queue<int>que;
    que.push(vt);
    level[vt]=0;
    gap[level[vt]]++;
    while(!que.empty()){
        int u=que.front();
        que.pop();
        for(int i=head[u];i!=-1;i=edge[i].next){
            int v=edge[i].v;
            if(level[v]!=-1)continue;
            level[v]=level[u]+1;
            gap[level[v]]++;
            que.push(v);
        }
    }
}
int pre[MAXN],cur[MAXN];
int SAP(int vs,int vt)
{
    bfs(vt);
    memset(pre,-1,sizeof(pre));
    memcpy(cur,head,sizeof(head));
    int u=pre[vs]=vs,aug=inf,maxflow=0;
    gap[0]=NV;
    while(level[vs]<NV){
        bool flag=false;
        for(int &i=cur[u];i!=-1;i=edge[i].next){
            int v=edge[i].v;
            if(edge[i].cap>0&&level[u]==level[v]+1){
                flag=true;
                aug=min(aug,edge[i].cap);
                pre[v]=u;
                u=v;
                if(v==vt){
                    maxflow+=aug;
                    for(u=pre[v];v!=vs;v=u,u=pre[u]){
                        edge[cur[u]].cap-=aug;
                        edge[cur[u]^1].cap+=aug;
                    }
                    aug=inf;
                }
                break;
            }
        }
        if(flag)continue;
        int minlevel=NV;
        for(int i=head[u];i!=-1;i=edge[i].next){
            int v=edge[i].v;
            if(edge[i].cap>0&&level[v]<minlevel){
                minlevel=level[v];
                cur[u]=i;
            }
        }
        if(--gap[level[u]]==0)break;
        level[u]=minlevel+1;
        gap[level[u]]++;
        u=pre[u];
    }
    return maxflow;
}
int main()
{
    int _case,u,v,w;
    scanf("%d",&_case);
    while(_case--){
        scanf("%d",&n);
        G.clear();
        G.resize(n+2);
        while(true){
            scanf("%d%d%d",&u,&v,&w);
            if(u==0&&v==0&&w==0)break;
            G[u].push_back(Node(v,w));
            G[v].push_back(Node(u,w));
        }
        spfa();
        if(dist[n]==inf||n==1){
            puts("0");
            continue;
        }
        Build();
        printf("%d\n",SAP(1,n));
    }
    return 0;
}
