#include <cstdio>
#include <cstring>
#include <cmath>
#define MAXN 210
#define EPS 1e-3
using namespace std;
int n;
struct Edge{
    int v,next;
    Edge(){}
    Edge(int _v,int _next):v(_v),next(_next){}
}edge[MAXN*MAXN];
int head[MAXN], size;
inline void initial(){
    memset(head,-1,sizeof(int)*(n+2));
    size = 0;
}
inline void add_edge(int u,int v){
    edge[size] = Edge(v,head[u]);
    head[u] = size ++;
}
int belong[MAXN]; 
bool vis[MAXN];
int depth;                 
int bcnt;                  
int dfn[MAXN], low[MAXN];  
int stack[MAXN], tail ;
inline void Tarjan(int u){
    dfn[u] = low[u] = depth ++;
    vis[u] = 1;
    stack[++tail] = u;
    for(int i = head[u];i != -1;i = edge[i].next){
        int v = edge[i].v;
        if(dfn[v] == -1){
            Tarjan(v);
            if(low[u] > low[v])
                low[u] = low[v];
        }else if(vis[v] && low[u] > dfn[v]){
                low[u] = dfn[v];
        }
    }
    if(low[u] == dfn[u]){  
        bcnt ++;
        int j;
        do{
            j = stack[tail--];
            vis[j] = 0;
            belong[j] = bcnt;
        }while(j != u);
    }
}
double x[MAXN], y[MAXN];
inline double Cal(int i,int j){
    return (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
}
inline bool can(){
    int N = n/2;
    for(int i = 1;i <= N; ++i)
        if(belong[i] == belong[i+N]) return false;
    return true;
}
int main()
{
    int N;
    while(scanf("%d",&N) != EOF){
        n = 2*N;
        for(int i = 1;i <= N; ++i)
            scanf("%lf%lf%lf%lf",&x[i],&y[i],&x[i+N],&y[i+N]);
        double right = 10000.0*10000.0, left = 0.0, mid;
        while(right - left >= EPS){
            mid = (right + left)/2.0;
            initial();
            for(int i = 1;i < n; ++i)
                for(int j = i + 1;j <= n; ++j){
                    if(Cal(i,j) < mid){
                        int u, v;
                        if(i <= N) u = i + N;
                        else       u = i - N;
                        if(j <= N) v = j + N;
                        else       v = j - N;
                        add_edge(i,v);
                        add_edge(j,u);
                    }
                }
            tail = depth = bcnt = 0;
            memset(vis,0,sizeof(bool)*(n+2));
            memset(dfn,-1,sizeof(int)*(n+2));
            memset(low,0,sizeof(int)*(n+2));
            for(int i = 1;i <= n; ++i)
                if(dfn[i] == -1) Tarjan(i);
            if(can()) left = mid;
            else right = mid;
        }
        printf("%.2lf\n",sqrt(left)/2.0);
    }
}
