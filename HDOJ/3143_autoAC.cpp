#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int  N = 100+5;
int head[N],cnt,n,e,p,d;
#define pc 160
#define eps 1e-8
#define INF 0x3f3f3f3f
double dist1[N],dist2[N];
bool out[N];
struct edges
{
    int u,cost,next;
    edges(){}
    edges(int a,int b,int c):u(a),cost(b),next(c){}
}edge[N*N];
void init(){
    memset(head,-1,sizeof(head));
    memset(out,0,sizeof(out));
    cnt = 0;
}
void add_edge(int a,int b,int c){
    edge[cnt] = edges(b,c,head[a]);
    head[a] = cnt++;
}
bool inQue[N];
queue<int>que;
void spfa(double dist[],int src)
{
    for(int i = 1; i <= n; ++i) dist[i] = INF,inQue[i] = 0;
    while(!que.empty()) que.pop();
    que.push(src);
    dist[src] = 0;
    inQue[src] = true;
    while(!que.empty())
    {
        int u = que.front();que.pop();
        for(int i = head[u]; i + 1 ; i =edge[i].next)
        {
            int v = edge[i].u;
            int val = edge[i].cost;
            if(src == p && v == d) continue;
            if(dist[u] + val < dist[v])
            {
                dist[v] = dist[u] + val;
                if(!inQue[v]) que.push(v),inQue[v] = true;
            }
        }
        inQue[u] = false;
    }
}
queue<int>qq;
bool has[N];
bool bfs(double vi)
{
    while(!qq.empty()) qq.pop();
    qq.push(p);
    for(int i = 1; i <= n; ++i) has[i] = 0;
    while(!qq.empty())
    {
        int u = qq.front();
        if(out[u]) return true;
        qq.pop();
        for(int i = head[u]; i + 1; i = edge[i].next)
        {
            int  v = edge[i].u;
            if(has[v]||dist1[v]*pc>=dist2[v]*vi) continue;
            qq.push(v);
            has[v] = 1;
        }
    }
    return false;
}
int main()
{
    int m;
    while(scanf("%d%d%d",&n,&m,&e)!=EOF)
    {
        init();
        for(int i = 0,x,y,z; i < m; ++i)
        {
            scanf("%d%d%d",&x,&y,&z);
            add_edge(x,y,z);
            add_edge(y,x,z);
        }
        for(int i = 0; i < e; ++i) scanf("%d",&p),out[p]=1;
        scanf("%d%d",&p,&d);
        spfa(dist1,p);
        spfa(dist2,d);
        double left = 0,right = INF,ans = -1;
        while(left+eps<right)
        {
            double mid = (right+left)/2;
            if(bfs(mid)) right= mid,ans = mid;
            else left = mid;
        }
        if(ans < 0)printf("IMPOSSIBLE\n");
        else printf("%.9f\n",ans);
    }
    return 0;
}
