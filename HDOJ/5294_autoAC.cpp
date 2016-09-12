#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int MAXN=2010;
int N,M;
struct Edge{
    int from,to,cap,flow;
};
struct Dinic{
    int n,m,s,t;            
    vector<Edge> edges;   
    vector<int> G[MAXN];    
    bool vis[MAXN];         
    int d[MAXN];            
    int cur[MAXN];          
    void clear_all(int n){
        for(int i=0;i<n;i++) G[i].clear();
        edges.clear();
    }
    void clear_flow(){
        int len=edges.size();
        for(int i=0;i<len;i++) edges[i].flow=0;
    }
    void add_edge(int from,int to,int cap){
        edges.push_back((Edge){from,to,cap,0});
        edges.push_back((Edge){to,from,0,0});
        m=edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }
    bool BFS(){
        memset(vis,0,sizeof(vis));
        queue<int> q;
        q.push(s);
        d[s]=0;
        vis[s]=1;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            int len=G[x].size();
            for(int i=0;i<len;i++){
                Edge& e=edges[G[x][i]];
                if(!vis[e.to]&&e.cap>e.flow){
                    vis[e.to]=1;
                    d[e.to]=d[x]+1;
                    q.push(e.to);
                }
            }
        }
        return vis[t];
    }
    int DFS(int x,int a){
        if(x==t||a==0) return a;
        int flow=0,f,len=G[x].size();
        for(int& i=cur[x];i<len;i++){
            Edge& e=edges[G[x][i]];
            if(d[x]+1==d[e.to]&&(f=DFS(e.to,min(a,e.cap-e.flow)))>0){
                e.flow+=f;
                edges[G[x][i]^1].flow-=f;
                flow+=f;
                a-=f;
                if(a==0) break;
            }
        }
        return flow;
    }
    int maxflow(int s,int t){
        this->s=s;
        this->t=t;
        int flow=0;
        while(BFS()){
            memset(cur,0,sizeof(cur));
            flow+=DFS(s,INF);
        }
        return flow;
    }
    int mincut(){   
        int ans=0;
        int len=edges.size();
        for(int i=0;i<len;i++){
            Edge& e=edges[i];
            if(vis[e.from]&&!vis[e.to]&&e.cap>0) ans++;
        }
        return ans;
    }
    void reduce(){
        int len=edges.size();
        for(int i=0;i<len;i++) edges[i].cap-=edges[i].flow;
    }
}solver;
int d[MAXN];
vector<int> p[MAXN];
struct HeapNode{
    int u,d;
    bool operator < (const HeapNode& rhs) const{
        return d>rhs.d;
    }
};
struct Edge2{
    int u,v,dist;
};
struct Dijkstra{
    int n,m;
    vector<Edge2> edges;
    vector<int> G[MAXN];
    bool done[MAXN];
    void init(int n){
        this->n=n;
        for(int i=0;i<n;i++) G[i].clear();
        edges.clear();
    }
    void add_edge(int u,int v,int dist){
        edges.push_back((Edge2){u,v,dist});
        m=edges.size();
        G[u].push_back(m-1);
    }
    void dijkstra(int s){
        priority_queue<HeapNode> q;
        for(int i=0;i<n;i++) p[i].clear();
        for(int i=0;i<n;i++) d[i]=INF;
        d[s]=0;
        memset(done,0,sizeof(done));
        q.push((HeapNode){s,0});
        while(!q.empty()){
            HeapNode x=q.top();
            q.pop();
            int u=x.u;
            if(done[u]) continue;
            done[u]=true;
            int L=G[u].size();
            for(int i=0;i<L;i++){
                Edge2& e=edges[G[u][i]];
                if(d[e.v]>d[u]+e.dist){
                    d[e.v]=d[u]+e.dist;
                    p[e.v].clear();
                    p[e.v].push_back(u);
                    q.push((HeapNode){e.v,d[e.v]});
                }
                else if(d[e.v]==d[u]+e.dist){
                    p[e.v].push_back(u);
                    q.push((HeapNode){e.v,d[e.v]});
                }
            }
        }
    }
}solver2;
int num[MAXN];
int dfs(int u){
    if(u==0) return 0;
    if(num[u]!=INF) return num[u];
    int len=p[u].size();
    for(int i=0;i<len;i++){
        int fa=p[u][i];
        solver.add_edge(fa,u,1);
        solver.add_edge(u,fa,1);
        num[u]=min(num[u],dfs(fa)+1);
    }
    return num[u];
}
int main(){
    while(scanf("%d%d",&N,&M)!=EOF){
        solver2.init(N+1);
        int u,v,t;
        for(int i=0;i<M;i++){
            scanf("%d%d%d",&u,&v,&t);
            u--;
            v--;
            solver2.add_edge(u,v,t);
            solver2.add_edge(v,u,t);
        }
        solver2.dijkstra(0);
        memset(num,INF,sizeof(num));
        solver.clear_all(N+1);
        int n=dfs(N-1);
        solver.maxflow(0,N-1);
        int ans1=solver.mincut(),ans2=M-num[N-1];
        printf("%d %d\n",ans1,ans2);
    }
    return 0;
}
