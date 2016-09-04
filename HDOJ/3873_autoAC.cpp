#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef pair<LL,int>Pair;
#define inf (1ll)<<55
#define MAXN 3333
struct Node {
    int v,w;
};
int In[MAXN];
LL dist[MAXN],pro[MAXN];
bool mark[MAXN];
vector<Node>Map[MAXN];
vector<int>vet[MAXN];
int n,m;
void Dijkstra(){
   for(int i=1;i<=n;i++){ dist[i]=inf;pro[i]=0; }
   dist[1]=0;
   memset(mark,false,sizeof(mark));
   priority_queue<Pair,vector<Pair>,greater<Pair> >Q;
   Q.push(make_pair(dist[1],1));
   while(!Q.empty()){
      Pair pp=Q.top();
      Q.pop();
      int u=pp.second;
      if(mark[u])continue;
      mark[u]=true;
      for(int i=0;i<vet[u].size();i++){
         int v=vet[u][i];
         In[v]--;
         pro[v]=max(pro[v],dist[u]);
         if(dist[v]!=inf&&In[v]==0){
            dist[v]=max(dist[v],pro[v]);
            Q.push(make_pair(dist[v],v));
         }
      }
      for(int i=0;i<Map[u].size();i++){
         int v=Map[u][i].v;
         int w=Map[u][i].w;
         if(dist[v]>dist[u]+w){
            dist[v]=max(dist[u]+w,pro[v]);
            if(In[v]==0){ Q.push(make_pair(dist[v],v)); }
         }
      }
   }
}
int main() {
    int _case,u,v,w,x;
    scanf("%d",&_case);
    while(_case--) {
        scanf("%d%d",&n,&m);
        for(int i=1; i<=n; i++) {
            Map[i].clear();
            vet[i].clear();
        }
        while(m--) {
            scanf("%d%d%d",&u,&v,&w);
            Node p;
            p.v=v,p.w=w;
            Map[u].push_back(p);
        }
        for(int i=1; i<=n; i++) {
            scanf("%d",&In[i]);
            for(int j=1; j<=In[i]; j++) {
                scanf("%d",&x);
                vet[x].push_back(i);
            }
        }
        Dijkstra();
        printf("%I64d\n",dist[n]);
    }
    return 0;
}
