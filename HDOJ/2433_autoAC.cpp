#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#define INF 99999999
using namespace std;
const int MAX=100+10;
int dist[MAX],edgenum[MAX][MAX];
bool mark[MAX],flag[MAX][MAX][MAX];
int size,head[MAX],n,m,pos[3002],sum[MAX];
struct Edge{
    int v,w,next;
    Edge(){}
    Edge(int V,int W,int Next):v(V),w(W),next(Next){}
}edge[3002*2];
inline void Init(int num){
    memset(head,-1,sizeof(int)*(num+2));
    memset(edgenum,0,sizeof edgenum);
    memset(flag,false,sizeof flag);
    size=0;
} 
inline void InsertEdge(int u,int v,int w){
    edge[size]=Edge(v,w,head[u]);
    head[u]=size++;
}
int spfa(int s,bool p){
    int ans=0;
    queue<int>enqueue;
    for(int i=1;i<=n;++i)dist[i]=INF,mark[i]=false;
    dist[s]=0;
    mark[s]=true;
    enqueue.push(s);
    while(!enqueue.empty()){
        int u=enqueue.front();
        enqueue.pop();
        mark[u]=false;
        for(int i=head[u];i != -1;i=edge[i].next){
            int v=edge[i].v;
            if(dist[v]>dist[u]+edge[i].w){
                dist[v]=dist[u]+edge[i].w;
                if(!mark[v]){
                    if(p)flag[s][u][v]=flag[s][v][u]=true;
                    enqueue.push(v);
                    mark[v]=true;
                }
            }
        }
    }
    for(int i=1;i<=n;++i){
        if(dist[i] == INF)return INF;
        else ans+=dist[i];
    }
    return ans;
}
int main(){
    int ans,u,v,temp;
    while(cin>>n>>m){
        Init(n);
        for(int i=0;i<m;++i){
            cin>>u>>v;
            pos[i]=size;
            InsertEdge(u,v,1);
            InsertEdge(v,u,1);
            ++edgenum[u][v];
            ++edgenum[v][u];
        }
        ans=temp=0;
        for(int i=1;i<=n;++i){
            sum[i]=spfa(i,1);
            if(sum[i] == INF){ans=INF;break;}
            else ans+=sum[i];
        }
        for(int i=0;i<m;++i){
            u=edge[pos[i]+1].v;
            v=edge[pos[i]].v;
            int s=ans;
            if(ans == INF)cout<<"INF"<<endl;
            else if(edgenum[u][v]-1>0)cout<<ans<<endl;
            else{
                edge[pos[i]+1].w=INF;
                edge[pos[i]].w=INF;
                for(int j=1;j<=n;++j){
                    if(flag[j][u][v]){
                        temp=spfa(j,0);
                        if(temp == INF){cout<<"INF"<<endl;break;}
                        else s+=temp-sum[j]; 
                    }
                }
                if(temp != INF)cout<<s<<endl;
                edge[pos[i]+1].w=1;
                edge[pos[i]].w=1;
            }
        }
    }
    return 0;
}
