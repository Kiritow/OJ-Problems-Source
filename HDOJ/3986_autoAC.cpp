#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
const int MAXN=1000+10;
const int inf=1<<30;
struct Node{
    int v,w,id;
};
vector<Node>vet[MAXN];
int path[MAXN];
int dist[MAXN];
bool visited[MAXN];
bool mark[MAXN*50];
int id[MAXN];
int n,m;
bool tag;
void SPFA(int u){
    for(int i=1;i<=n;i++)dist[i]=inf;
    dist[u]=0;
    memset(visited,false,sizeof(visited));
    queue<int>Q;
    Q.push(u);
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();
        visited[u]=false;
        for(int i=0;i<vet[u].size();i++){
            int v=vet[u][i].v;
            int w=vet[u][i].w;
            int ID=vet[u][i].id;
            if(mark[vet[u][i].id])continue;
            if(dist[u]+w<dist[v]){
                dist[v]=dist[u]+w;
                if(tag)path[v]=u,id[v]=ID;
                if(!visited[v]){
                    Q.push(v);
                    visited[v]=true;
                }
            }
        }
    }
}
int main(){
    int _case;
    scanf("%d",&_case);
    while(_case--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)vet[i].clear();
        memset(path,-1,sizeof(path));
        memset(mark,false,sizeof(mark));
        for(int i=1;i<=m;i++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            Node p1,p2;
            p1.v=u,p2.v=v;
            p1.w=p2.w=w;
            p1.id=p2.id=i; 
            vet[u].push_back(p2);
            vet[v].push_back(p1);
        }
        tag=true;
        SPFA(1);
        tag=false;
        if(dist[n]==inf){
            printf("-1\n");
            continue;
        }
        int ans=0;
        bool flag=true;
        for(int u=n;u!=-1;u=path[u]){
            mark[id[u]]=true;
            SPFA(1);
            mark[id[u]]=false;
            if(dist[n]==inf){
                printf("-1\n");
                flag=false;
                break;
            }
            ans=max(ans,dist[n]);
        }
        if(flag){
            printf("%d\n",ans);
        }
    }
    return 0;
}
