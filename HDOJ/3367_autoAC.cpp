#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
const int N=10010;
using namespace std;
int n,m;
int parent[N];
int visited[N];
struct Edge {
    int u,v,w;
    bool operator < (const Edge &p) const {
        return p.w<w;
    }
}edge[N*10];
void UFset(){
    for(int i=0;i<n;i++)
        parent[i]=-1;
}
int Find(int x){
    int s;
    for(s=x;parent[s]>=0;s=parent[s]);
    while(s!=x){
        int temp=parent[x];
        parent[x]=s;
        x=temp;
    }
    return s;
}
void Union(int R1,int R2){
    int r1=Find(R1);
    int r2=Find(R2);
    int temp=parent[r1]+parent[r2];
    if(parent[r1]>parent[r2]){
        parent[r1]=r2;
        parent[r2]=temp;
    }else {
        parent[r2]=r1;
        parent[r1]=temp;
    }
}
int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        if(n==0&&m==0)break;
        memset(visited,0,sizeof(visited));
        int u,v,ans=0;
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
        }
        sort(edge,edge+m);
        UFset();
        for(int i=0;i<m;i++){
            u=Find(edge[i].u);
            v=Find(edge[i].v);
            if(u!=v){
                if(visited[u]&&visited[v])continue; 
                if(visited[u]||visited[v])
                    visited[u]=visited[v]=1;
                ans+=edge[i].w;
                Union(u,v);
            }else if(!visited[u]||!visited[v]){
                Union(u,v);
                visited[u]=visited[v]=1;
                ans+=edge[i].w;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
