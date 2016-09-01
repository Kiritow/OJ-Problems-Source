#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<set>
#include<map>
#include<vector>
#include<cstring>
#include<stack>
#include<cmath>
#include<queue>
using namespace std;
#define CL(x,v); memset(x,v,sizeof(x));
#define INF 0x3f3f3f3f
#define LL long long
#define REP(i,r,n) for(int i=r;i<=n;i++)
#define RREP(i,n,r) for(int i=n;i>=r;i--)
const int MAXN=200*200+100;
struct Edge{
    int from,to,cap,flow;
};
bool cmp(const Edge& a,const Edge& b){
    return a.from < b.from || (a.from == b.from && a.to < b.to);
}
struct Dinic{
    int n,m,s,t;
    vector<Edge> edges;
    vector<int> G[MAXN];
    bool vis[MAXN];
    int d[MAXN];
    int cur[MAXN];
    void init(int n){
        this->n=n;
        for(int i=0;i<=n;i++)G[i].clear();
        edges.clear();
    }
    void AddEdge(int from,int to,int cap){
        edges.push_back((Edge){from,to,cap,0});
        edges.push_back((Edge){to,from,cap,0});
        m=edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }
    bool BFS(){
        CL(vis,0);
        queue<int> Q;
        Q.push(s);
        d[s]=0;
        vis[s]=1;
        while(!Q.empty()){
            int x=Q.front();
            Q.pop();
            for(int i=0;i<G[x].size();i++){
                Edge& e=edges[G[x][i]];
                if(!vis[e.to]&&e.cap>e.flow){
                    vis[e.to]=1;
                    d[e.to]=d[x]+1;
                    Q.push(e.to);
                }
            }
        }
        return vis[t];
    }
    int DFS(int x,int a){
        if(x==t||a==0)return a;
        int flow=0,f;
        for(int& i=cur[x];i<G[x].size();i++){
            Edge& e=edges[G[x][i]];
            if(d[x]+1==d[e.to]&&(f=DFS(e.to,min(a,e.cap-e.flow)))>0){
                e.flow+=f;
                edges[G[x][i]^1].flow-=f;
                flow+=f;
                a-=f;
                if(a==0)break;
            }
        }
        return flow;
    }
    int Maxflow(int s,int t,int need){
        this->s=s;this->t=t;
        int flow=0;
        while(BFS()){
            CL(cur,0);
            flow+=DFS(s,INF);
            if(flow>need)return flow;
        }
        return flow;
    }
    vector<int> Mincut(){
        BFS();
        vector<int> ans;
        for(int i=0;i<edges.size();i++){
            Edge& e=edges[i];
            if(vis[e.from]&&!vis[e.to]&&e.cap>0)ans.push_back(i);
        }
        return ans;
    }
    void Reduce(){
        for(int i = 0; i < edges.size(); i++) edges[i].cap -= edges[i].flow;
    }
    void ClearFlow(){
        for(int i = 0; i < edges.size(); i++) edges[i].flow = 0;
    }
};
Dinic solver;
int main()
{
    int n,m;
    int cas=0;
    while(~scanf("%d%d",&n,&m))
    {
        int s=n*m;
        int t=n*m+1;
        int N=n*m+1;
        solver.init(N);
        int a;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                scanf("%d",&a);
                if(i!=0)
                    solver.AddEdge((i-1)*m+j,i*m+j,1);
                if(j!=0)
                    solver.AddEdge(i*m+j-1,i*m+j,1);
                if(a==1)
                    solver.AddEdge(s,i*m+j,INF);
                if(a==2)
                    solver.AddEdge(i*m+j,t,INF);
            }
        }
        int ans=solver.Maxflow(s,t,INF);
        printf("Case %d:\n",++cas);
        printf("%d\n",ans);
    }
    return 0;
}
