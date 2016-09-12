#include<cstdio>
#include<cstring>
#include<queue>
#include<set>
#include<algorithm>
using namespace std;
const int MAXN = 5e5+5;
const int INF  = 0x3f3f3f3f;
typedef long long LL;
int head[MAXN],e;
LL dis[MAXN];
bool vis[MAXN];
struct Edge{
    int v,nxt,w;
}E[MAXN<<1];
void init()
{
    e=0;
    memset(head,-1,sizeof head);
    memset(vis,false,sizeof vis);
}
void add(int u,int v,int w)
{
    E[e].v = v;
    E[e].w = w;
    E[e].nxt = head[u];
    head[u]  = e++;
}
struct QNode{
    int v,c;
    QNode(int _v,int _c){
        v = _v;c=_c;
    }
    bool operator < (const QNode &a) const{
        return c>a.c;
    }
};
LL dijkstra(int n)
{
    memset(dis,INF,sizeof dis);
    priority_queue<QNode>Q;
    dis[1] = 0;
    Q.push(QNode(1,0));
    while(!Q.empty())
    {
        QNode tmp = Q.top();Q.pop();
        int u = tmp.v;
        if(vis[u]) continue;
        vis[u] = true;
        for(int i=head[u];~i;i=E[i].nxt){
            int v = E[i].v;
            int w = E[i].w;
            if(vis[v]) continue;
            if(dis[u]+w<dis[v]){
                dis[v] = dis[u]+w;
                Q.push(QNode(v,dis[v]));
            }
        }
    }
    return dis[n];
}
LL BFS(int n,LL val)
{
    set<int>ta,tb;
    queue<int>Q;Q.push(1);
    dis[1] = 0,dis[n] = INF;
    for(int i=2;i<=n;i++) ta.insert(i);
    while(!Q.empty())
    {
        int u = Q.front();Q.pop();
        for(int i=head[u];~i;i=E[i].nxt){
            int v = E[i].v;
            if(!ta.count(v)) continue;
            ta.erase(v);tb.insert(v);
        }
        for(set<int>::iterator it=ta.begin();it!=ta.end();it++){
            Q.push(*it);
            dis[*it] = dis[u] + val;
        }
        ta.swap(tb);tb.clear();
    }
    return dis[n];
}
int main()
{
    int N,M;
    LL A,B;
    int u,v;
    while(~scanf("%d%d%lld%lld",&N,&M,&A,&B))
    {
        init();
        bool flag = false;
        for(int i=0;i<M;i++){
            scanf("%d%d",&u,&v);
            add(u,v,A);add(v,u,A);
            if(min(u,v)==1&&max(u,v)==N)flag  =true;
        }
        if(!flag) printf("%lld\n",min(dijkstra(N),(LL)B));
        else printf("%lld\n",min(BFS(N,B),(LL)A));
    }
    return 0;
}
