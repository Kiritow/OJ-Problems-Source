#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iostream>
#define maxn 1000
#define maxm 200000
#define inf 10000000
using namespace std;
int head[maxn],tail;
int queue[maxn],pre[maxn],flag[maxn];
int dist[maxn],maxFlow[maxn];
struct Edge{
    int v,u,next,cost,w;
    Edge(){}
    Edge(int u,int v,int next,int cost,int w):u(u),v(v),next(next),cost(cost),w(w){}
} edge[maxm];
void add_edge(int u,int v,int cost,int w){
    edge[tail] = Edge(u,v,head[u],cost,w);
    head[u] = tail++;
    edge[tail] = Edge(v,u,head[v],-cost,0);
    head[v] = tail++;
}
void init(){
    memset(head,-1,sizeof(head));
    tail=0;
}
int SPFA(int start,int end){
    int i,u,v,front,rear;
    front = rear = 0;
    memset(flag,0,sizeof(flag));
    memset(dist,0x1f,sizeof(dist));
    memset(pre,-1,sizeof(pre));
    dist[start] = 0, dist[end] = inf ,flag[start]=1;
    maxFlow[start] = inf, queue[rear++] = start;
    while(front != rear){
        u = queue[front++];
        if(front >= maxn) front = 0;
        flag[u] = 0;
        for(i = head[u]; i!=-1;i=edge[i].next){
            v=edge[i].v;
      if(edge[i].w&&dist[v]>dist[u]+edge[i].cost){
                dist[v]=dist[u]+edge[i].cost;
        maxFlow[v]=min(edge[i].w,maxFlow[u]);
                pre[v]=i;
                if(!flag[v]){
                    queue[rear++]=v;
                    if(rear>=maxn)rear=0;
                    flag[v] =1;
                }
            }
        }
    }
    return dist[end] != inf;
}
int MFMC(int start,int end){
    int min_cost = 0,v;
    while(SPFA(start,end)){
        v = end;
        while(pre[v]>=0){
            edge[pre[v]].w-=maxFlow[end];
            edge[pre[v]^1].w+=maxFlow[end];
            v=edge[pre[v]].u;
        }
        min_cost+=dist[end]*maxFlow[end];
    }
    return min_cost;
}
int map[207][207];
vector<int> stack;
int check[207];
int n;
void dfs(int u){
    if(check[u]) return;
    check[u] = 1;
    stack.push_back(u);
    for(int i = 1;i <= n; i++){
        if(map[u][i] == 1 && check[i] == 0){
            dfs(i);
        }
    }
}
int main(){
    int m,t,k;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&m,&k);
        init();
        memset(map,0,sizeof(map));
        for(int i = 1;i <= n; i++)
            add_edge(i,n+1,1,1);
        int q,u,v,t,cost = n+2;
        for(int i = 0;i < m; i++){
            scanf("%d",&t);
            if(t == 1){
                scanf("%d",&u);
                memset(check,0,sizeof(check));
                stack.clear();
                dfs(u);
                add_edge(0,cost,500000-cost*500,k);
                for(int j = 0;j < stack.size() ;j++){
                   add_edge(cost,stack[j],0,1);
                }
                cost++;
            }
            else if(t == 2){
                scanf("%d%d",&u,&v);
                map[v][u] = map[u][v] = 1;
            }
            else {
                scanf("%d",&q);
                while(q--){
                    scanf("%d%d",&u,&v);
                    map[u][v] = map[v][u] = 0;
                }
            }
        }
        int ans = MFMC(0,n+1);
        stack.clear();
        for(int i = head[0];i != -1; i=edge[i].next){
            stack.push_back(k-edge[i].w);
        }
        printf("%d\n",ans%500);
        int flag = 0;
        for(int i = stack.size() - 1;i >= 0; i--){
            if(i != stack.size()-1) printf(" ");
            printf("%d",stack[i]);
        }
        printf("\n");
    }
    return 0;
}
